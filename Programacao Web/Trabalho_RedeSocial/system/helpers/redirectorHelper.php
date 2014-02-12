<?php

class redirectorHelper{

	protected $parameters = array();

	public function go($data){
		$base = System::getBase();
		header("Location:".$base.$data);
	}

	public function setUrlParameter($name, $value){
		$this->parameters[$name] = $value;
		return $this;
	}

	protected function getUrlParameters(){
		$params = '';
		foreach ($this->parameters as $name => $value)
			$params .= $name.'/'.$value.'/';
		return $params;
	}

	public function getCurrentController(){
		$c = System::getUrl(0);
		if($c != null)
			return $c;
		return 'index';
	}

	public function goToController($controller){
		$this->go($controller.'/'.$this->getUrlParameters());
	}

	public function goToCurrentUrl(){
		$url = System::getUrl();
		$purl = "";
		foreach ($url as $value)
			$purl .= $value."/";

		$this->go($purl);
	}

	public function goToIndex(){
		if($this->getCurrentController() != 'index')
			$this->goToController('index');
	}

	public function goToUrl($url){
		header("Location: ".$url);
	}

}
