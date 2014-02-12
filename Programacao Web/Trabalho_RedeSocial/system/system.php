<?php

require_once("ISystem.php");

class System implements ISystem{

	private static $_url, $_controller, $_action, $_base;

	public static function start(){
		self::setBase();
		self::setUrl();
		self::setController();
		self::setAction();
		self::run();
	}

	private static function setBase(){
		global $_SERVER;
		$start = strlen($_SERVER["DOCUMENT_ROOT"]);
        $currentUrl = substr($_SERVER["SCRIPT_FILENAME"], $start, -9); //-9 => index.php
        self::$_base = ($currentUrl[0] == '/') ? $currentUrl : '/'.$currentUrl;
	}
 
    public static function getBase(){
        return self::$_base;
    }
    
    private static function setUrl(){

    	global $_SERVER;

    	$start = strlen($_SERVER["DOCUMENT_ROOT"]);
        $currentUrl = substr($_SERVER["SCRIPT_FILENAME"], $start, -9); //-9 => index.php
         
        $request = $_SERVER['REQUEST_URI'];   
        $request = substr($request, strlen($currentUrl));
         
        $urlTmp = explode("?", $request);
        $request = $urlTmp[0];

        $explode = explode("/", $request);
        $arr = array();
 
        for($a=0; $a <= count($explode); $a ++)
            if(isset($explode[$a]) && !empty($explode[$a]))
                array_push($arr, $explode[$a]);

        self::$_url = $arr;
    }

    public static function getUrl($index = -1){
    	if($index >= 0){
    		if(array_key_exists($index, self::$_url))
    			return self::$_url[$index];
    		else
    			return null;
    	}
    	return self::$_url;
    }   

    public static function getCurrentUrl(){
        $tmp = '';
        foreach (self::$_url as $value){
            $tmp .= $value.'/';
        }
        return $tmp;
    }

    private static function setController(){
    	self::$_controller = (self::getUrl(0) != null) ? self::getUrl(0) : 'index';
    }

    public static function getController(){
    	return self::$_controller;
    }

    private static function setAction(){
    	self::$_action = (self::getUrl(1) != null && self::getUrl(1) != 'index') ? self::getUrl(1) : 'index_index';
    }

    public static function getAction(){
    	return self::$_action;
    }

    private static function run(){
    	$controller_path = CONTROLLERS . self::$_controller . 'Controller.php';
		if(!file_exists($controller_path)){

            $tmpcontroller = "index";
            require_once(CONTROLLERS.$tmpcontroller.'Controller.php');
            if(method_exists(new $tmpcontroller, self::$_controller)){
                self::$_action = self::$_controller;
                self::$_controller = $tmpcontroller;
                $controller_path = CONTROLLERS.$tmpcontroller.'Controller.php';
            }
            else{
                $controller_path = CONTROLLERS.'errorPagController.php';
                self::$_controller = "errorPag";
            }
        }

		require_once($controller_path);
		$app = new self::$_controller();
			
		if(!method_exists($app, self::$_action))
			self::$_action = "index_index";

		$app->init();
		$action = self::$_action;
		$app->$action();
    }

}