var interval; // global var to timeout counting in start and pause methods

var TuringMachine = (function(){
	"use strict";

	function TuringMachine(machine_element){

		this.head_pointer = 0;								// head_pointer to the init of array
		this.pointer = 0;									// pointer to current state
		this.element = machine_element;						// dom element <div>
		this.len = Math.ceil(this.element.offsetWidth/52);	// 52 = state width in html
		
		this.machine = new Array(this.len);					// array to represent the machine
		this.string = "";
		this.states = [];
		this.alphabet_input = [];
		this.alphabet_tape = [];
		this.blank_symbol = '□';
		this.final_states = [];
		this.initial_state = "";

		this.actual_state = "";
		this.accepted = null; 	// var to view if machine is accepeted


		this.initializeMachine();
		this.drawMachine();
	};


	TuringMachine.prototype.initializeMachine = function(){
		for(var i=0; i<this.len; i++)
			this.machine[i] = this.blank_symbol;
	};

	TuringMachine.prototype.setStringEquals = function(string){
		this.initializeMachine();
		
		this.string = string;
		var start = Math.ceil((this.len-string.length)/2);
		this.pointer = start;

		for(var i=start, len=string.length+start; i<len; i++)
			this.machine[i] = string[i-start];
	};

	TuringMachine.prototype.setString = function(string){
		if(this.string == ""){	
			this.initializeMachine();

			this.string = string;
			for(var i=0, len=string.length; i<len; i++)
				this.machine[i] = string[i];
		}
	};

	TuringMachine.prototype.setActualState = function(state){
		this.actual_state = state;
	};

	TuringMachine.prototype._shiftLeft = function(){
		this.pointer += 1;
		this.head_pointer += 1;
		this.drawMachine();
	};

	TuringMachine.prototype._shiftRight = function(){
		this.pointer -= (this.head_pointer > 0) ? 1 : 0;
		this.head_pointer -= (this.head_pointer > 0) ? 1 : 0;
		this.drawMachine();
	};

	TuringMachine.prototype.drawMachine = function(){
		
		var content = ""
		var s_state = "<div class='state'>";	// start_state
		var s_state_a = "<div class='state active'>";	// active state
		var e_state = "</div>";					// end_state

		for(var i=this.head_pointer; i<this.len+this.head_pointer; i++){
			content += (i == this.pointer) ? s_state_a : s_state;
			content += (i < this.len) ? this.machine[i] : this.blank_symbol;
			content += e_state;
		}

		this.element.innerHTML = content;
	};

	

	// (estado, de, novo_estado, para, E|D|S)
	TuringMachine.prototype._getTransition = function(character, state){
		var len = this.transitions.length;
		for(var i=0; i<len; i++){
			var estado = this.transitions[i][0];
			var de = this.transitions[i][1];
			if(estado == state && de == character)
				return [this.transitions[i][2], this.transitions[i][3], this.transitions[i][4]]
		}

		return null;
	};



	TuringMachine.prototype._run = function(){
		
		if(this.actual_state == ""){
			tm.setActualState(this.initial_state);
			return true;
		}

		var character = this.machine[this.pointer];
		var transicao = this._getTransition(character, this.actual_state);

		if(transicao == null)
			return false;

		if(transicao[2] == "E"){
			this.actual_state = transicao[0];
			this.machine[this.pointer] = transicao[1];
			this.pointer -= (this.pointer > 0) ? 1 : 0;
		}
		else if(transicao[2] == "D"){
			this.actual_state = transicao[0];
			this.machine[this.pointer] = transicao[1];
			this.pointer += 1;
		}
		else if(transicao[2] == "S"){
			this.actual_state = transicao[0];
			this.machine[this.pointer] = transicao[1];
		}

		return true;
	};



	TuringMachine.prototype.startMachine = function(seconds){

		if(this.accepted == null){
			if(this._verifyDependencies()){
				this.drawMachine();

				var $this = this;
				interval = setInterval(function(){ 
					if($this._run()){
						$this.drawMachine(); 
					}
					else{
						clearInterval(interval); 

						if($this.final_states.indexOf($this.actual_state) != -1){
							alert("String accepted by machine!");
							this.accepted = true;
							limpar(true);	// !
						}
						else{
							alert("String not accepted by machine!");
							this.accepted = false;
							limpar(false);	// !
						}

					}
				}, seconds);


			}
			else{
				alert("Verify the input data.");
				this.accepted = null;
			}
		}
		
		return this.accepted;
	};



	TuringMachine.prototype.pauseMachine = function(){
		if(this.accepted == null)
			clearInterval(interval);
		
		return this.accepted;
	};


	TuringMachine.prototype.stepMachine = function(){

		if(this.accepted == null){
			if(this._verifyDependencies()){
				if(this._run()){
					this.drawMachine();
				}
				else{
					if(this.final_states.indexOf(this.actual_state) != -1){
						alert("String accepted by machine!");
						this.accepted = true;
					}
					else{
						alert("String not accepted by machine!");
						this.accepted = false;
					}
				}
			}
			else{
				alert("Verify the input data.");
				this.accepted = null;
			}
		}

		return this.accepted;
	};

	TuringMachine.prototype.testMachine = function(){
		if(this.accepted == null){
			if(this._verifyDependencies()){
				while(this._run())
					this.drawMachine();

				if(this.final_states.indexOf(this.actual_state) != -1){
					alert("String accepted by machine!");
					this.accepted = true;
				}
				else{
					alert("String not accepted by machine!");
					this.accepted = false;
				}
			}
			else{
				alert("Verify the input data.");
				this.accepted = null;
			}
		}
		
		return this.accepted;
	};






	TuringMachine.prototype._verifyDependencies = function(){
		
		// verify is a string is in the alphabet
		var len = this.string.length;

		for(var i=0; i<len; i++)
			if(this.alphabet_input.indexOf(this.string[i]) == -1)
				return false;
		
		
		// blank symbol in tape alphabet
		if(this.alphabet_tape.indexOf(this.blank_symbol) == -1)
			return false;


		// transitions in tape alphabet
		len = this.transitions.length;
		for(var i=0; i<len; i++){
			var de = this.transitions[i][1];
			var para = this.transitions[i][3];
			
			if(this.alphabet_tape.indexOf(de) == -1){
				alert(de);
				return false; 
			}
			else if(this.alphabet_tape.indexOf(para) == -1){
				return false;
			}
		}

		return true;
	};

	return TuringMachine;

}());




tm = new TuringMachine(document.getElementById("turing-machine"));
//tm.setString("010110101011"); //010110+101011
//tm.drawMachine();




// functions to capture events

function setPropriedades(){
	var string = document.getElementById("string").value;
	var estados =  document.getElementById("estados").value;
	var alfabeto = document.getElementById("alfabeto").value;
	var alfabeto_fita = document.getElementById("alfabeto-fita").value;
	var simbolo_vazio = document.getElementById("simbolo-vazio").value;
	var estados_finais = document.getElementById("estados-finais").value;
	var estado_inicial = document.getElementById("estado-inicial").value;
	var transicoes = document.getElementById("transicoes").value;
	
	if(string == ""){
		alert("Please, enter the input string.");
		return false;
	}
	else if(estados == ""){
		alert("Please, enter the set of states.");
		return false;
	}
	else if(alfabeto == ""){
		alert("Please, enter the input alphabet.");
		return false;
	}
	else if(alfabeto_fita == ""){
		alert("Please, enter the tape alphabet.");
		return false;
	}
	else if(simbolo_vazio == ""){
		alert("Please, enter the blank symbol.");
		return false;
	}
	else if(estados_finais == ""){
		alert("Please, enter the final states.");
		return false;
	}
	else if(estado_inicial == "" || estado_inicial == "Initial State"){
		alert("Please, enter the initial state.");
		return false;
	}
	else if(transicoes == ""){
		alert("Please, enter the transitions.");
		return false;
	}

	estados = estados.replace(" ", "").split(",");
	alfabeto = alfabeto.replace(" ", "").split(",");
	alfabeto_fita = alfabeto_fita.replace(" ", "").split(",");
	estados_finais = estados_finais.replace(" ", "").split(",");
	transicoes = transicoes.split('\n');
	for(var i=0, len=transicoes.length; i<len; i++)
		transicoes[i] = transicoes[i].replace(" ", "").split(",");

	tm.blank_symbol = simbolo_vazio;
	tm.setString(string);
	tm.states = estados;
	tm.alphabet_input = alfabeto;
	tm.alphabet_tape = alfabeto_fita;
	tm.final_states = estados_finais;
	tm.initial_state = estado_inicial;
	tm.transitions = transicoes;

	return true;
}


document.getElementById("iniciar").onclick = function(e){
	
	if(setPropriedades()){

		var bt_start = document.getElementById("iniciar");
		var bt_pause = document.getElementById("pausar");

		bt_start.setAttribute("class", "btn btn-lg btn-primary");
		bt_pause.setAttribute("class", "btn btn-lg btn-default"); 

		var segundos = document.getElementById("segundos").value;
		if(segundos == "")
			segundos = 0.5;

		tm.startMachine(segundos*1000); //in ms

	}
		
}

document.getElementById("pausar").onclick = function(e){

	if(setPropriedades()){

		var bt_start = document.getElementById("iniciar");
		var bt_pause = document.getElementById("pausar");

		bt_start.setAttribute("class", "btn btn-lg btn-default");
		bt_pause.setAttribute("class", "btn btn-lg btn-primary"); 

		tm.pauseMachine();
	}
}

document.getElementById("passar").onclick = function(e){
	if(setPropriedades()){
		var aux = tm.stepMachine();
		limpar(aux);
	}
}

document.getElementById("testar").onclick = function(e){
	if(setPropriedades()){
		var aux = tm.testMachine();
		limpar(aux);
	}
}


estados_visitados = [];
document.getElementById("estados").onblur = function(e){
	
	estados = document.getElementById("estados").value;
	if(estados.trim() != ""){
		
		var arr = estados.split(",");
		var content = "";

		for(var i=0, len=arr.length; i<len; i++){
			if(estados_visitados.indexOf(arr[i]) == -1){
				content += "<option value='"+arr[i]+"'>"+arr[i]+"</option>";
				estados_visitados.push(arr[i]);
			}
		}
		
		document.getElementById("estado-inicial").innerHTML += content;
	}

}


document.getElementById("exemplo").onclick = function(e){
	preencher();
	e.preventDefault();
}

function preencher(){
	document.getElementById("string").value = "110";
	document.getElementById("estados").value = "q0,q1";
	document.getElementById("alfabeto").value = "0,1";
	document.getElementById("alfabeto-fita").value = "0,1,□";
	document.getElementById("simbolo-vazio").value = "□";
	document.getElementById("estados-finais").value = "q1";
	document.getElementById("estado-inicial").innerHTML = "<option selected='selected' value='q0'>q0</option>";
	document.getElementById("transicoes").value = "q0,□, q1,1,D\nq0,0, q1,1,D\nq0,1, q0,0,D";
}

function limpar(accepted){

	var result = document.getElementById("resultado");

	if(accepted === null){
		result.setAttribute("class", "label label-default");
		result.innerHTML = "waiting";
	}
	else if(accepted === true){
		result.setAttribute("class", "label label-success");
		result.innerHTML = "accepted";
	}
	else if(accepted === false){
		result.setAttribute("class", "label label-warning");
		result.innerHTML = "not accepted";
	}

	document.getElementById("iniciar").setAttribute("class", "btn btn-lg btn-default");
	document.getElementById("pausar").setAttribute("class", "btn btn-lg btn-default");
}


// jquery functions (modal, tooltip and popover)

$('*[data-toggle="modal"]').on("click", function(){
	var id = this.getAttribute("id");
	var title = this.getAttribute("data-title");
	var text = document.getElementById(id+"Content").innerHTML;
	
	var modal = document.getElementById("myModal");
	modal.getElementsByClassName("modal-title")[0].innerHTML = title;
	modal.getElementsByClassName("modal-body")[0].innerHTML = text;

});

$('*[data-toggle="tooltip"]').tooltip();

$('.popovers').popover({
  trigger: 'focus'
})