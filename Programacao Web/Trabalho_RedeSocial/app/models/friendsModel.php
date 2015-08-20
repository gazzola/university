<?php

class friendsModel extends basicModel{

	public $_tabela = "usuarios";

	public function comparaDados(Array $arr1, Array $arr2, Array $more, $id){
		for($i=0; $i<count($arr1); $i++) {
			for($j=0; $j<count($more); $j++){
				
				$param = (($arr1[$i]['id_usuario']) == $id) ? 'id_amigo' : 'id_usuario';

				if($j == 0){//nome amigo
					$arr1[$i][$more[$j]] = $this->getNomeUsuario($arr1[$i][$param], $arr2);
				}
				else if($j == 1){//nome_amigo_url
					$arr1[$i][$more[$j]] = $this->getNomeUrlUsuario($arr1[$i][$param], $arr2);
				}
				else{//foto_usuario
					$arr1[$i][$more[$j]] = $this->getFotoUsuario($arr1[$i][$param], $arr2);
				}

			}
		}
		return $arr1;
	}

	public function inArrayMult($id, Array $arr2){
		foreach ($arr2 as $value) {
			if($value['id_amigo'] == $id || $value['id_usuario'] == $id)
				return true;
		}

		return false;
	}

	protected function getNomeUsuario($id, Array $arr2 = null){
		$res = $this->read("nome", "id=?", array("id"=>$id));

		if(count($res > 0)){
			if($arr2 != null){
				if($this->inArrayMult($id, $arr2))
					return $res[0]['nome'];
				else
					return null;
			}
			else
				return $res[0]['nome'];
		}

		return null;
	}

	protected function getNomeUrlUsuario($id, Array $arr2 = null){
		$res = $this->read("nome_url", "id=?", array("id"=>$id));

		if(count($res > 0)){
			if($arr2 != null){
				if($this->inArrayMult($id, $arr2))
					return $res[0]['nome_url'];
				else
					return null;
			}
			else
				return $res[0]['nome_url'];
		}

		return null;
	}

	protected function getFotoUsuario($id, Array $arr2 = null){ 
		$res = $this->read("foto", "id=?", array("id"=>$id));

		if(count($res > 0)){
			if($arr2 != null){
				if($this->inArrayMult($id, $arr2))
					return $res[0]['foto'];
				else
					return null;
			}
			else
				return $res[0]['foto'];
		}

		return null;
	}

}
