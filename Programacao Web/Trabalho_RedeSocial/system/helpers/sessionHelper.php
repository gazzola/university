<?php

class sessionHelper{

	public function setSession($name, $value){
		$_SESSION[$name] = $value;
		return $this;
	}

	public function getSession($name){
		return $_SESSION[$name];
	}

	public function deleteSession($name){
		unset($_SESSION[$name]);
		return $this;
	}

	public function checkSession($name){
		return isset($_SESSION[$name]);
	}

}