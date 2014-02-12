<?php

class commentModel extends basicModel{

	public $_tabela = "mensagens";

	public function transformLink($text, $attributes=array()){

		$attrs = '';
		foreach ($attributes as $attribute => $value)
			$attrs .= " {$attribute}=\"{$value}\"";

		$text = ' ' . $text;
		$text = preg_replace(
			'`([^"=\'>])((http|https|ftp)://[^\s<]+[^\s<\.)])`i',
			'$1<a href="$2"'.$attrs.'>$2</a>',
			$text
		);

		$text = substr($text, 1);
		$text = str_replace('<a', '<a target="_blank" class="linksx"', $text);
		
		return $text;
	}

}
