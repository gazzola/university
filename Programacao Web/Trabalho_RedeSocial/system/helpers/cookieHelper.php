<?php

class cookieHelper{

	public function setCookie($name, $value){
		setcookie($name, $value, time()+3600*24*30, "/"); //1 mes
		return $this;
	}

	public function getCookie($name){
		return $_COOKIE[$name];
	}

	public function deleteCookie($name){
		setcookie($name, "", time()-3600*24*30, "/"); //1 mes
		return $this;
	}

	public function checkCookie($name){
		return isset($_COOKIE[$name]);
	}

}