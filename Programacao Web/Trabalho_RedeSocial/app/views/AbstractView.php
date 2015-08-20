<?php

abstract class AbstractView implements IView{

	private $_file, $_vars;

	protected function setFile($file){
		$this->_file = $file;
		return $this;
	}

	protected function setVars(Array $vars = null){
		$this->_vars = $vars;
		return $this;
	}

	private function getIdGlobal(){
		$ses = new sessionHelper();
		if($ses->checkSession('loginId'))
			return $ses->getSession('loginId');
		return null;
	}

	public function show(){

		if(is_array($this->_vars) && count($this->_vars)>0)
			extract($this->_vars, EXTR_PREFIX_ALL, 'view'); //extrai cada elemento do array, fazendo: varname = view_(prefix)indice = valor

		$this->showHeader();
		$IDGLOBAL = $this->getIdGlobal();
		require_once($this->_file);
		$this->showFooter();

	}

	private function showHeader(){
		echo '
		<!DOCTYPE html>
		<html>
		<head>';
		$this->showMetas();
		echo '
		</head>
		<body>
		';
	}

	private function showMetas(){

		/*
		// HEREDOC
		$mensagem = <<< MSG
			Seja bem-vindo "$nome"
		MSG;

		echo $mensagem;
		*/
	
		echo '
		<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
		<meta http-equiv="content-language" content="pt-br" />
		<meta name="description" content="Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua." />
		<meta name="keywords" content="social network, perspective social, perspective network" />
		<meta name="author" content="Perspective Development" />
		<meta name="reply-to" content="contact@perspective.com.br" />
		<meta name="robots" content="index, follow" />
		<meta name="googlebot" content="index, follow" />
		<title>Perspective</title>
		';

		//BASE PARA URL AMIGAVEL
		echo '
		<base href="'.System::getBase().'_assets/" />
		<!--[if IE]><script type="text/javascript" src="'.System::getBase().'_assets/scripts/iefix.js"></script><![endif]-->
		'; //FIX BASE FOR IE

		echo '
		<link rel="stylesheet" href="estilo.css" media="all" />
		<link rel="shortcut icon" type="image/x-icon" href="favicon.ico" />
		<link rel="icon" href="favicon.ico" />
		<script type="text/javascript" src="scripts/jquery.js"></script>
		';
	}

	private function showFooter(){
		echo '
		</body>
	  	</html>';
	}

}