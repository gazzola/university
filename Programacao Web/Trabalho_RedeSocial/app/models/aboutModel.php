<?php

class aboutModel extends basicModel{

	public $_tabela = "usuarios";
	
	public function patternUrl($str){
		$str = strtolower(utf8_decode($str)); 
		
		$str = strtr($str, utf8_decode('àáâãäåæçèéêëìíîïñòóôõöøùúûýýÿ'), 'aaaaaaaceeeeiiiinoooooouuuyyy');
		$str = preg_replace("/([^a-z0-9])/",'-',utf8_encode($str));

		$i=1;
		while($i>0) 
			$str = str_replace('--','-',$str,$i);

		if (substr($str, -1) == '-') 
			$str = substr($str, 0, -1);

		return $str;
	}
	
}
