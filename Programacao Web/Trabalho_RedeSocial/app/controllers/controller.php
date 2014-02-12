<?php

abstract class Controller extends System{

	protected function view($nome, $vars = null){

		$file = VIEWS . $nome . 'View.php';
		if(!file_exists($file))
			die("Erro! View nao existe.");

		$view = new View($file, $vars);
		$view->show();
		exit(); //exit, pois incluir a view eh a ultima acao a ser feita
	}

	public function init(){
		$auth = new authHelper();
		$auth->checkUser();
		$auth->checkLogin();

	} //init, pois sempre estou chamando o init no start da aplicacao
}
