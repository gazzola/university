<?php

class indexModel extends basicModel{

	public $_tabela = "usuarios";

	public function organizaDados(Array $array, Array $more, $id, $invert=false){
		for($i=0; $i<count($array); $i++) {
			for($j=0; $j<count($more); $j++){
				if($j == 0){
					$array[$i][$more[$j]] =  $this->getNomeUsuario($array[$i]['id_amigo']);
				}
				else if($j==1){
					$array[$i][$more[$j]] =  $this->getNomeUrlUsuario($array[$i]['id_amigo']);
				}
				else if($j==2){
					$array[$i][$more[$j]] =  $this->getFotoUsuario($array[$i]['id_amigo']);
				}
				else{
					$array[$i][$more[$j]] =  $this->getComentarios($array[$i]['id']);
				}
			}
		}
		return $array;
	}

	public function organizaMensagens(Array $array, Array $more, $id){
		for($i=0; $i<count($array); $i++) {
			for($j=0; $j<count($more); $j++){
				if($j == 0){
					$array[$i][$more[$j]] =  $this->getNomeUsuario($array[$i]['id_usuario']);
				}
				else if($j==1){
					$array[$i][$more[$j]] =  $this->getNomeUrlUsuario($array[$i]['id_usuario']);
				}
				else{
					$array[$i][$more[$j]] =  $this->getFotoUsuario($array[$i]['id_usuario']);
				}
			}
		}
		return $array;
	}

	public function organizaDadosComentarios(Array $array, Array $more){
		for($i=0; $i<count($array); $i++) {
			for($j=0; $j<count($more); $j++){
				if($j == 0){
					$array[$i][$more[$j]] =  $this->getNomeUsuario($array[$i]['id_usuario']);
				}
				else if($j==1){
					$array[$i][$more[$j]] =  $this->getNomeUrlUsuario($array[$i]['id_usuario']);
				}
				else{
					$array[$i][$more[$j]] =  $this->getFotoUsuario($array[$i]['id_usuario']);
				}
			}
		}
		return $array;
	}

	private function getComentarios($id){
		$this->_tabela = "comentarios";
		$res = $this->read("id, id_usuario, conteudo", "id_publicacao=?", array("id_publicacao"=>$id));
		$this->_tabela = "usuarios";
		if(count($res)>0){
			$resx = $this->organizaDadosComentarios($res, array("comment_nome_usuario", "comment_nome_url", "comment_foto_usuario"));
			return $resx;
		}
		return $res;
	}

}
