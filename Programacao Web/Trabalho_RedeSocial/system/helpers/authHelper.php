<?php

require_once("hashHelper.php"); //pbkdf2 function

class authHelper{

	protected $sessionHelper, $redirectorHelper, $cookieHelper, $user, $pass, $check=false, $tempcookie=null,
			  $loginController='login', $logoutController='login';

	private $_error=true;

	public function __construct(){
		$this->sessionHelper = new sessionHelper();
		$this->cookieHelper = new cookieHelper();
		$this->redirectorHelper = new redirectorHelper();
		return $this;
	}

	public function setUser($val){
		$this->user = $val;
		return $this;
	}

	public function setPass($val){
		$this->pass = $val;
		return $this;
	}

	public function setCheck($check){
		$this->check = $check;
		return $this;
	}

	public function setLoginController($controller){
		$this->loginController = $controller;
		return $this;
	}

	public function setLogoutController($controller){
		$this->logoutController = $controller;
		return $this;
	}

	public function getTempCookie(){
		return $this->tempcookie;
	}

	public function login(){
		$db = new loginModel();
		$sql = $db->listaDados("id, hash, hash_cookie, salt", "email=?", array("email"=>$this->user));

		if(count($sql) > 0){

			$hash_old = $sql[0]['hash'];
			$salt = $sql[0]['salt'];
			$hash_cookie = $sql[0]['hash_cookie'];
			$id = $sql[0]['id'];

			$hash_user = pbkdf2('SHA256', $this->pass, $salt, 100, 32, false);
			if($hash_user == $hash_old) //verify if newhash of user is compatible with hash liked in databse
				$this->_error = false; //pass to the next step
		}


		if($this->_error === false && $this->check === true){ //login with session and cookie

			if($this->cookieHelper->checkCookie("XH2CuociRS") && $_COOKIE['XH2CuociRS'] == $hash_cookie){ //if isset cookie, just create session and add time expires for old cookie
				$this->cookieHelper->setCookie("XH2CuociRS", $hash_cookie);
				$this->tempcookie = $hash_cookie; //set the cookie for a temp variable (cookie has been estabilished after reload page)
			}
			else{

				$size = mcrypt_get_iv_size(MCRYPT_CAST_256, MCRYPT_MODE_CFB); //generate salt and new hash for cookie
				$salt_cookie = mcrypt_create_iv($size, MCRYPT_DEV_RANDOM);
				$salt_cookie = utf8_encode($salt_cookie);
				$hash_cookie_new = pbkdf2('SHA256', $hash_user, $salt_cookie, 100, 32, false);

				$this->cookieHelper->setCookie("XH2CuociRS", $hash_cookie_new);
				$this->tempcookie = $hash_cookie_new; //set the cookie for a temp variable (cookie has been estabilished after reload page)
			}

			$this->sessionHelper->setSession('loginAuth', true)
								->setSession('loginId', $id);

			$ip = $_SERVER['REMOTE_ADDR'];
			$db->editaDados(array("ip", "hash_cookie"), "id=?", array("ip"=>$ip, "hash_cookie"=>$this->tempcookie, "id"=>$id));

		}
		else if($this->_error === false && $this->check === false){//login with session only

			$this->sessionHelper->setSession('loginAuth', true)
								->setSession('loginId', $id);


			$ip = $_SERVER['REMOTE_ADDR'];
			$db->editaDados(array("ip"), "id=?", array("ip"=>$ip, "id"=>$id));
		}

		if($this->_error === true)
			$this->redirectorHelper->go('login/error/');
		else
			$this->redirectorHelper->go('');
		
		return $this;
	}


	public function logout(){
		if($this->cookieHelper->checkCookie('XH2CuociRS'))
			$this->cookieHelper->deleteCookie('XH2CuociRS');

		$this->sessionHelper->deleteSession('loginAuth')
							->deleteSession('loginId');
		$this->redirectorHelper->go('');	
		return $this;
	}

	public function checkLogin(){

		if(!$this->sessionHelper->checkSession('loginAuth') && !$this->cookieHelper->checkCookie('XH2CuociRS')){
			if($this->redirectorHelper->getCurrentController() != $this->loginController)
				$this->redirectorHelper->go('login/');
		}
		else if(!$this->sessionHelper->checkSession('loginAuth') && $this->cookieHelper->checkCookie('XH2CuociRS')){

			$hcookie = $this->cookieHelper->getCookie('XH2CuociRS');
			$ip = $_SERVER['REMOTE_ADDR'];

			$db = new loginModel();
			$sql = $db->listaDados("id", "hash_cookie=? AND ip=?", array("hash_cookie"=>$hcookie, "ip"=>$ip));
			if(count($sql) > 0){
				$id = $sql[0]['id'];
				$this->sessionHelper->setSession('loginAuth', true)
								    ->setSession('loginId', $id);
				$this->redirectorHelper->goToCurrentUrl();
			}
			else{
				$this->cookieHelper->deleteCookie('XH2CuociRS');
				$this->redirectorHelper->go('login/');
			}
		}
		else if($this->sessionHelper->checkSession('loginAuth') && $this->redirectorHelper->getCurrentController() == "login"){
			$this->redirectorHelper->go('');
		}

	}

	public function checkUser(){
		if($this->sessionHelper->checkSession('loginId')){
			$id = $this->sessionHelper->getSession('loginId');
			$db = new loginModel();
			$sql = $db->listaDados("id", "id=?", array("id"=>$id));
			if(count($sql) <= 0){
				if($this->cookieHelper->checkCookie('XH2CuociRS'))
					$this->cookieHelper->deleteCookie('XH2CuociRS');

				$this->sessionHelper->deleteSession('loginAuth')
									->deleteSession('loginId');
			}
		}
	}

}