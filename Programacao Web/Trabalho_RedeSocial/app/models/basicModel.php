<?php

abstract class basicModel extends Model{

	public function listaDados($campos, $where, $wheredatas, $oderby=null, $limit=null){
		return $this->read($campos, $where, $wheredatas, $oderby, $limit, null);
	}

	public function insereDados($dados){
		return $this->insert($dados);
	}
	
	public function editaDados($datas, $where, $wheredatas){
		return $this->update($datas, $where, $wheredatas);
	}

	public function deletaDados($where, $wheredatas=null){
		return $this->delete($where, $wheredatas);
	}

	public function organizaDados(Array $array, Array $more, $id, $invert=false){
		for($i=0; $i<count($array); $i++) {
			for($j=0; $j<count($more); $j++){

				$param = (($array[$i]['id_usuario']) == $id) ? 'id_amigo' : 'id_usuario';
					

				if($j == 0){//nome amigo
					$array[$i][$more[$j]] = $this->getNomeUsuario($array[$i][$param]);
				}
				else if($j == 1){//nome_amigo_url
					$array[$i][$more[$j]] = $this->getNomeUrlUsuario($array[$i][$param]);
				}
				else{//foto_usuario
					if($invert)
						$param = 'id_amigo';
					$array[$i][$more[$j]] = $this->getFotoUsuario($array[$i][$param]);
				}

			}
		}
		return $array;
	}

	protected function getNomeUsuario($id){
		$res = $this->read("nome", "id=?", array("id"=>$id));
		return $res[0]['nome'];
	}

	protected function getFotoUsuario($id){ 
		$res = $this->read("foto", "id=?", array("id"=>$id));
		return $res[0]['foto'];
	}

	protected function getNomeUrlUsuario($id){
		$res = $this->read("nome_url", "id=?", array("id"=>$id));
		return (count($res > 0)) ? $res[0]['nome_url'] : null;
	}

}