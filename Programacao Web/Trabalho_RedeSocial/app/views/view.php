<?php

class View extends AbstractView{
	public function __construct($file, Array $vars = null){
		$this->setFile($file);
		$this->setVars($vars);
	}
}