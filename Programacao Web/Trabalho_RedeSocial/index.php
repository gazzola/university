<?php

session_start();
date_default_timezone_set('America/Sao_Paulo');

define('CONTROLLERS', 'app/controllers/');
define('VIEWS', 'app/views/');
define('MODELS', 'app/models/');
define('HELPERS', 'system/helpers/');


function __autoload($file){
	if(file_exists(MODELS . lcfirst($file) . '.php'))
		require_once(MODELS . lcfirst($file) . '.php');
	else if(file_exists(MODELS . ucfirst($file) . '.php'))
		require_once(MODELS . ucfirst($file) . '.php');
	else if(file_exists(HELPERS . lcfirst($file) . '.php'))
		require_once(HELPERS . lcfirst($file) . '.php');
	else if(file_exists(HELPERS . ucfirst($file) . '.php'))
		require_once(HELPERS . ucfirst($file) . '.php');
	else if(file_exists(CONTROLLERS . lcfirst($file) . '.php'))
		require_once(CONTROLLERS . lcfirst($file) . '.php');
	else if(file_exists(CONTROLLERS . ucfirst($file) . '.php'))
		require_once(CONTROLLERS . ucfirst($file) . '.php');
	else if(file_exists(VIEWS . lcfirst($file) . '.php'))
		require_once(VIEWS . lcfirst($file) . '.php');
	else if(file_exists(VIEWS . ucfirst($file) . '.php'))
		require_once(VIEWS . ucfirst($file) . '.php');
	else
		die("Model, Helper, Controller ou View nao encontrado!". $file);
}

require_once('system/system.php');
System::start();