var MAX_FRAMES = 32;
var MAX_PROCESS = 90;

var PRONTO = 0;
var EXECUTANDO = 1;
var ENCERRADO = 2;

var CPUBOUND = 0;
var IOBOUND = 1;



// A container with a last-in-first-out (LIFO) queuing policy.
var Stack = (function(){
	"use strict";

	function Stack(){
		this._array = [];
	};
	
	Stack.prototype.push = function(item){
		this._array.push(item);
	};

	Stack.prototype.pop = function(){
		return this._array.pop();
	};

	Stack.prototype.isEmpty = function(){
		return (this._array.length == 0);
	};

	Stack.prototype.getArray = function(){
		return this._array;
	};

	return Stack;

}());


// A container with a first-in-first-out (FIFO) queuing policy.
var Queue = (function(){
	"use strict";

	function Queue(){
		this._array = [];
	};
	
	Queue.prototype.push = function(item){
		this._array.unshift(item);
	};

	Queue.prototype.pop = function(){
		return this._array.pop();
	};

	Queue.prototype.isEmpty = function(){
		return (this._array.length == 0);
	};

	Queue.prototype.getArray = function(){
		return this._array;
	};

	return Queue;

}());


var ManagersHistory = (function(){
	"use strict";

	var hist = {};

	function ManagersHistory(){
		this.hist = new Stack();
	};

	ManagersHistory.prototype.add = function(msg){
		//this.hist.push(msg);
		document.getElementById("console").innerHTML += msg+'\n';
	};

	ManagersHistory.prototype.getHistory = function(){
		var text = "";
		while(!this.hist.isEmpty())
			text += this.hist.pop()+'\n';

		return text;
	}

	return ManagersHistory;
}());

ManHistory = new ManagersHistory();



var MemManager = (function(){
	"use strict";

	var table = [[]];
	var _numAllocated;
	var div = {}

	function MemManager(){
		this.table = [[]]
		this._createTable();
		this._numAllocated = 0;
		this.div = {};
	};


	MemManager.prototype._createTable = function(){
		for(var i=0; i<MAX_FRAMES; i++)
			this.table.push([null, null, null, 0, 0]);
	};

	MemManager.prototype.setMemTableDiv = function(div){
		this.div = div;
	};

	MemManager.prototype.drawTable = function(){
		
		var columns = 8;
		var total = MAX_FRAMES;
		
		var cleaner = "<div class='clearfix'></div>";
		var text = "";

		for(var i=0; i<total; i++){
			
			if(this.table[i][0] == null){
				var label = "label-white";
				text += "<span class='memblock "+label+"'>&Oslash;</span>";
			}
			else{
				
				var val = this.table[i][0]+""+this.table[i][1];
				var label = "label-"+this.table[i][2];
				text += "<span class='memblock "+label+"'>"+val+"</span>";
			}

			if((i+1)%columns == 0)
				text += cleaner;
		}

		this.div.innerHTML = text;
	};


	MemManager.prototype.operate = function(pid, page, color){
		
		this._increaseTime();

		var tablePageIndex = this._isAllocatedPage(pid, page);
		if(tablePageIndex != -1){
			this._hitPage(tablePageIndex);
			ManHistory.add("Pagina "+pid+""+page+" encontrada.");
			return tablePageIndex;
		}

		// poderia buscar o dado no disco

		if(this._numAllocated < MAX_FRAMES){
			var index = this._getSpacePointer();
			ManHistory.add("Pagina "+pid+""+page+" alocada.");
			this._allocate(index, pid, page, color);
		}
		else{
			var index = this._isAllocatedProcess(pid);
			if(index != -1){
				//sobrepor pags do processo (escolher quais atraves dos hits)
				var lessHitsIndex = this._getLessHitsOfProcess(index, pid);
				var lessPid = this.table[lessHitsIndex][0];
				var lessPage = this.table[lessHitsIndex][1];
				ManHistory.add("Pagina "+pid+""+page+" realocada no lugar da pagina "+lessPid+""+lessPage+".");
				this._reallocate(lessHitsIndex, pid, page, color);
			}
			else{
				//tirar paginas do processo maior
				var greaterTimeIndex = this._getGreaterTimeOfAll();
				var gtPid = this.table[greaterTimeIndex][0];
				var gtPage = this.table[greaterTimeIndex][1];
				ManHistory.add("Paginas do processo "+gtPid+" desalocadas para o processo "+pid+".");
				ManHistory.add("Pagina "+pid+""+page+" realocada no lugar da pagina "+gtPid+""+gtPage+".");
				this._reallocate(greaterTimeIndex, pid, page, color);
				this._unallocate(gtPid);
			}
		}

		this.drawTable();
		return -1;

	};


	// modificadores
	MemManager.prototype._hitPage = function(index){
		this.table[index][3] += 1;
	};

	MemManager.prototype._increaseTime = function(){
		for(var i=0; i<MAX_FRAMES; i++)
			if(this.table[i][0] != null)
				this.table[i][4] += 1;
	};


	// verficadores
	MemManager.prototype._isAllocatedProcess = function(pid){
		for(var i=0; i<MAX_FRAMES; i++)
			if(this.table[i][0] == pid)
				return i;
		return -1;
	};

	MemManager.prototype._isAllocatedPage = function(pid, page){
		for(var i=0; i<MAX_FRAMES; i++)
			if(this.table[i][0] == pid && this.table[i][1] == page)
				return i;
		return -1;
	};

	MemManager.prototype._getSpacePointer = function(){
		for(var i=0; i<MAX_FRAMES; i++)
			if(this.table[i][0] == null)
				return i;
		return -1;
	};


	// algoritmos de substituicao
	MemManager.prototype._getLessHitsOfProcess = function(start, pid){
		var menor = start;
		for(var i=start+1; i<MAX_FRAMES; i++)
			if(this.table[i][0] == pid)
				if(this.table[i][3] < this.table[menor][3])
					menor = i;
		return menor;
	};

	MemManager.prototype._getLessHitsOfAll = function(){
		var menor = 0;
		for(var i=1; i<MAX_FRAMES; i++)
			if(this.table[i][3] < this.table[menor][3] && this.table[i][0] != null)
				menor = i;
		return menor;
	};

	MemManager.prototype._getGreaterHitsOfAll = function(){
		var maior = 0;
		for(var i=1; i<MAX_FRAMES; i++)
			if(this.table[i][3] > this.table[maior][3] && this.table[i][0] != null)
				maior = i;
		return maior;
	};

	MemManager.prototype._getGreaterTimeOfAll = function(){
		var maior = 0;
		for(var i=1; i<MAX_FRAMES; i++)
			if(this.table[i][4] > this.table[maior][4] && this.table[i][0] != null)
				maior = i;
		return maior;
	};



	// alocadores
	MemManager.prototype._allocate = function(index, pid, page, color){
		this.table[index][0] = pid;
		this.table[index][1] = page;
		this.table[index][2] = color;
		this.table[index][3] = 1;
		this.table[index][4] = 1;
		this._numAllocated += 1;
	};

	MemManager.prototype._reallocate = function(index, pid, page, color){
		this.table[index][0] = pid;
		this.table[index][1] = page;
		this.table[index][2] = color;
		this.table[index][3] = 1;
		this.table[index][4] = 1;
	};

	MemManager.prototype._unallocate = function(pid){
		for(var i=0; i<MAX_FRAMES; i++){
			if(this.table[i][0] == pid){
				this.table[i][0] = null;
				this.table[i][1] = null;
				this.table[i][2] = null;
				this.table[i][3] = 0;
				this.table[i][4] = 0;
				this._numAllocated -= 1;
			}
		}
	};

	return MemManager;

}());




var Process = (function(){
	"use strict";

	var pid;
	var priority; 
	var state;
	var bound;
	var memory;
	var pointer;
	var color;
	var quantum;

	function Process(pid, priority, state, bound, color){
		this.pid = pid;
		this.priority = priority;
		this.state = state;
		this.bound = bound;
		this.memory = Math.ceil(4+(Math.random()*28))*1000;    //no max 32KB de memoria = 8 pags de 4K
		this.pointer = 0;								  	   //de acordo com a formula (X/4KB)
		this.color = color;
		this.page = '';
		this.hits = 0;
		if(bound == CPUBOUND)
			this.quantum = Math.ceil(Math.random()*10)+this.getNumPages();
		else
			this.quantum = Math.ceil(Math.random()*15)+this.getNumPages();
	};

	Process.prototype.setPointer = function(pointer){
		this.pointer = pointer;
	};

	Process.prototype.getPointer = function(){
		return this.pointer;
	}

	Process.prototype.getNumPages = function(){
		return Math.floor(this.memory/4000);
	}

	return Process;

}());


function sleep(milliseconds) {
	var start = new Date().getTime();
	for(var i=0; i<1e7; i++){
		if((new Date().getTime() - start) > milliseconds)
		  break;
	}
}

var timer = null;


var ProcManager = (function(){
	"use strict";

	var readyQueue = {};
	var closedQueue = {};
	var runningProcess = {};
	var qtdProcess = 0;
	var idProcess = 0;
	var colors = []
	

	function ProcManager(){
		this.init();
	}

	ProcManager.prototype.init = function(){
		this.readyQueue = new Queue();
		this.closedQueue = new Queue();
		this.runningProcess = null;
		this.qtdProcess = 0;
		this.idProcess = 0;
		this.colors = ["blue", "red", "green", "yellow", "cyan", "pink", "purple", "orange", "gray", "black", "white"]; 
	}

	ProcManager.prototype._getBoundTxt = function(bound){
		return (bound==IOBOUND) ? 'IO' : 'CPU';
	}

	ProcManager.prototype.createProcess = function(qtd){
		if(this.qtdProcess+parseInt(qtd) <= MAX_PROCESS){
			for(var i=0; i<qtd; i++){
				
				var index = this.idProcess%(this.colors.length-1);
				var priority = Math.ceil(Math.random()*10);
				var bound = (Math.floor(Math.random()*2) == 0) ? IOBOUND : CPUBOUND;
				
				this.idProcess += 1;
				this.qtdProcess += 1;
				ManHistory.add("Processo "+this.idProcess+" - ("+priority+", "+this._getBoundTxt(bound)+") movido para PRONTO.");
				
				this.readyQueue.push(new Process(this.idProcess, priority, PRONTO, bound, this.colors[index]));
			}
		}
		else{
			alert("Quantidade máxima de processos é "+MAX_PROCESS);
			return false;
		}
	}

	ProcManager.prototype.executeProcess = function(){

		if(this.qtdProcess > 0){

			var process = this.readyQueue.pop();
			process.state = EXECUTANDO;
			ManHistory.add("Processo "+process.pid+" - ("+process.priority+", "+this._getBoundTxt(process.bound)+") movido para EXECUTANDO.");

			for(var i=0; i<process.quantum; i++){
				var memPage = Math.ceil(Math.random()*process.getNumPages());
				var memPageTable = String.fromCharCode(memPage+64);
				MemManager.operate(process.pid, memPageTable, process.color);
			}

			document.getElementById("processor").innerHTML = process.pid;
			this.drawProcess(document.getElementById("processQueues"));
			this.closeProcess(process);
		}
		else
			alert("Nenhum processo na lista.");
	}

	

	ProcManager.prototype.closeProcess = function(process){
		
		this.qtdProcess -= 1;
		this.closedQueue.push(process)
		process.state = ENCERRADO;

		ManHistory.add("Processo "+process.pid+" - ("+process.priority+", "+this._getBoundTxt(process.bound)+") movido para ENCERRADO.");
		
		if(this.qtdProcess == 0){
			//clearTimeout(timer);
			setTimeout(function(){
				document.getElementById("processor").innerHTML = '&Oslash;';
			}, 1000);
		}
	}



	ProcManager.prototype.executeAllProcesses = function(sec){
		sec *= 1000; //in ms

		if(this.qtdProcess > 0){
			while(!this.readyQueue.isEmpty()){
				this.executeProcess();
				//sleep(sec);
			}
		}
		else
			alert("Nenhum processo na lista.");
	}

	ProcManager.prototype.closeAllProcesses = function(){
		while(!this.closedQueue.isEmpty())
			this.closeProcess(null);
	}


	ProcManager.prototype.drawProcess = function(table){
		var array = this.readyQueue.getArray();
		
		var text = '';
		var startgroup = '<div class="btn-group">';
		var endgroup = '</div>';

		var startbutton = '<button type="button" class="btn btn-default dropdown-toggle" data-toggle="dropdown">';
		var endbutton = '<span class="caret"></span></button>';

		var startdrop = '<ul class="dropdown-menu" role="menu">';
		var enddrop = '</ul>';

		var startdropbutton = '<li><a>';
		var enddropbutton = '</a></li>';

		text += startgroup;
		for(var i=array.length-1; i>=0; i--){
			text += startgroup;

			var label = "label-bt-"+array[i].color;
			text += '<button type="button" class="btn btn-default dropdown-toggle '+label+'" data-toggle="dropdown">';
			
			if(array[i].pid < 10)
				text += '0';
			text += array[i].pid;
			

			text += endbutton;
			
			text += startdrop;
			var limit = array[i].getNumPages();
			for(var j=1; j<=limit; j++){
				text += startdropbutton;
				text += array[i].pid+String.fromCharCode(j+64);
				text += enddropbutton;
			}
			text += enddrop;

			text += endgroup;
		}
		text += endgroup;

		table.innerHTML = text;
	}

	return ProcManager;

}());





// MAIN

var MemManager = new MemManager();
MemManager.setMemTableDiv(document.getElementById("memTable"));
MemManager.drawTable();
var ProcManager = new ProcManager();





// EVENTS

/* document.getElementById("createTable").onclick = function(e){

	var qtd = document.getElementById("qtdFrames").value;
	var table = document.getElementById("memTable");

	if(qtd < 793)
		MemManager.createTable(qtd, table);
	else
		alert("Quantidade máxima de quadros é 793.")

	e.preventDefault();
}

document.getElementById("qtdFrames").onkeypress = function(e){

	var e = window.event || e
	var keyunicode = e.charCode || e.keyCode

	if(keyunicode == 13){
		document.getElementById("createTable").click();
		return false;
	}

	return true;
} */



document.getElementById("qtdProcess").onkeypress = function(e){

	var e = window.event || e
	var keyunicode = e.charCode || e.keyCode

	if(keyunicode == 13){
		document.getElementById("createProcess").click();
		return false;
	}

	return true;
}

document.getElementById("createProcess").onclick = function(e){

	var qtd = document.getElementById("qtdProcess").value;
	var table = document.getElementById("processQueues");

	ProcManager.createProcess(qtd);
	ProcManager.drawProcess(table);

	//MemManager.createTable(qtd, table);
	//ProcManager.executeAllProcesses();
	e.preventDefault();

}

document.getElementById("executeProcess").onclick = function(e){
	ProcManager.executeProcess();
	e.preventDefault();
}

document.getElementById("secProcess").onkeypress = function(e){

	var e = window.event || e
	var keyunicode = e.charCode || e.keyCode

	if(keyunicode == 13){
		document.getElementById("executeAllProcesses").click();
		return false;
	}

	return true;
}

document.getElementById("executeAllProcesses").onclick = function(e){

	var sec = parseInt(document.getElementById("secProcess").value);
	ProcManager.executeAllProcesses(sec);
	e.preventDefault();
}


//document.querySelectorAll('*[data-toggle="modal"]').onclick = function(e){}

$('*[data-toggle="modal"]').on("click", function(){
	var id = this.getAttribute("id");
	var title = this.getAttribute("data-title");
	var text = document.getElementById(id+"Content").innerHTML;
	
	var modal = document.getElementById("myModal");
	modal.getElementsByClassName("modal-title")[0].innerHTML = title;
	modal.getElementsByClassName("modal-body")[0].innerHTML = text;

});

$("#seeHistory").on('click', function(){
	var console = $("#console");
	if(console.attr("visible") == "false"){
		console.slideDown("slow");
		console.attr("visible", "true");
		$(this).html("Fechar Histórico &raquo;");
	}
	else{
		console.slideUp("slow");
		console.attr("visible", "false");
		$(this).html("Ver Histórico &raquo;");
	}

});

$('*[data-toggle="tooltip"]').tooltip();

$('.popovers').popover({
  trigger: 'focus'
})