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

	return Stack;

}());


// A container with a first-in-first-out (FIFO) queuing policy.
var Queue = (function(){
	"use strict";

	function Queue(){
		this._array = [];
	};
	
	Stack.prototype.push = function(item){
		this._array.unshift(item);
	};

	Stack.prototype.pop = function(){
		return this._array.pop();
	};

	Stack.prototype.isEmpty = function(){
		return (this._array.length == 0);
	};

	return Queue;

}());



var MemManager = (function(){
	"use strict";

	var colors = [];

	function MemManager(){
		this.colors = ["white", "blue", "red", "green", "yellow", "cyan", "gray", "black", "pink", "purple", "orange"]; 
	};

	MemManager.prototype.createTable = function(qtd, table){
		
		var lines = Math.ceil(qtd/8);
		var columns = 8;

		var cleaner = "<div class='clearfix'></div>";
		var text = "";
		var pos = 0;
		var count = 0;

		for(var i=1; i<=lines; i++){
			for(var j=1; j<=8; j++){
				var val = i+String.fromCharCode(j+64);
				var index = (i+j)%this.colors.length;
				var label = "label-"+this.colors[index];
				text += "<span class='memblock "+label+"' pos='"+pos+"'>"+val+"</span>";
				count++;
				if(count >= qtd)
					break;
			}
			text += cleaner;
		}

		table.innerHTML = text;
	}

	return MemManager;

}());


var ProcManager = (function(){
	"use strict";

	var readyQueue = {};
	var qtdProcess = 0;
	var idProcess = 0;

	function ProcManager(){}


}());





var MemManager = new MemManager();

document.getElementById("createTable").onclick = function(e){

	var qtd = document.getElementById("qtdFrames").value;
	var table = document.getElementById("memTable");

	MemManager.createTable(qtd, table);
	e.preventDefault();
}

document.getElementById("qtdFrames").onkeypress = function(e){

	var e = window.event || e
	var keyunicode = e.charCode || e.keyCode

	if(e.keyCode == 13){
		document.getElementById("createTable").click();
		return false;
	}

	return true;
}


document.getElementById("createProcess").onclick = function(e){

	var qtd = document.getElementById("qtdProcess").value;
	var table = document.getElementById("processTable");

	MemManager.createTable(qtd, table);
	e.preventDefault();
}

document.getElementById("qtdProcess").onkeypress = function(e){

	var e = window.event || e
	var keyunicode = e.charCode || e.keyCode

	if(e.keyCode == 13){
		document.getElementById("createProcess").click();
		return false;
	}

	return true;
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

$('*[data-toggle="tooltip"]').tooltip();