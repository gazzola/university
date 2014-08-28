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