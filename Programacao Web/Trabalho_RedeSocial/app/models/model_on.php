<?php

abstract class Model{

	private $mysqli, $host, $user, $pass, $dba, $types;
	public $_tabela;

	public function __construct(){

		$this->host = "localhost";
		$this->user = "c1desenv";
		$this->pass = "MCDJEYR3j7x";
		$this->dba = "c1perspective";

		$this->mysqli = new MySQLi($this->host, $this->user, $this->pass, $this->dba);

		if (mysqli_connect_errno()){
		    printf("Erro na conexao: %s\n", mysqli_connect_error());
		    exit();
		}

		$this->mysqli->set_charset("utf8");
	}


	private function setTypes(Array $datas){
		$types = "";
	    foreach($datas as $value) {
	        if (is_string($value)) 
	            $types .= 's';
	        else if (is_int($value)) 
	            $types .= 'i';
	        else if (is_float($value))
	            $types .= 'd';
	        else
	            $types .= 'b';
	    }
	    $this->types = $types;
	}

	private function assocArray(Array $datas){
		$arr = array();
		$count=0;
		foreach ($datas as $value) {
			$arr[$count] = $value;
			$count++;
		}
		return $arr;
	}

	private function qtMarks(Array $datas){
		$size = count($datas);
        $inter = "";
        for($i=0; $i<$size; $i++){
        	$inter .= '?';
        	if($i < $size-1)
        		$inter .=',';
        }
        return $inter;
	}


	//CRUD - Create, Read, Update, Delete
	protected function insert(Array $datas){

		$campos = implode(", ", array_keys($datas));
		$qt_marks = $this->qtMarks($datas);		

		$sql = "INSERT INTO $this->_tabela ($campos) VALUES ($qt_marks)";
		if($stmt = $this->mysqli->prepare($sql)){

			$this->setTypes($datas);
			$arr = $this->assocArray($datas);

		    $bind_names[] = $this->types;
	        for($i=0; $i<count($arr); $i++) {
	            $bind_name = 'bind' . $i;       
	            $$bind_name = $arr[$i];      
	            $bind_names[] = &$$bind_name;   
      	  	}

            call_user_func_array(array($stmt,'bind_param'), $bind_names);

			$stmt->execute();
			$stmt->close();

		}

		return null;
	}


	protected function read($campos, $where=null, Array $wheredatas=null, $orderby=null, $limit=null, $offset=null, Array $more=null){
		$where = ($where != null) ? "WHERE ".$where : "";
		$limit = ($limit != null) ? "LIMIT ".$limit : "";
		$offset = ($offset != null) ? "OFFSET ".$offset : "";
		$orderby = ($orderby != null) ? "ORDER BY ".$orderby : "";

		$sql = "SELECT $campos FROM $this->_tabela $where $orderby $limit $offset";// SELECT nome, foto FROM usuarios WHERE id=? AND cor=?
		if($stmt = $this->mysqli->prepare($sql)){

			if($wheredatas != null){

				$this->setTypes($wheredatas);
				$arr = $this->assocArray($wheredatas);

			    $bind_names[] = $this->types;
		        for($i=0; $i<count($arr); $i++) {
		            $bind_name = 'bind' . $i;       
		            $$bind_name = $arr[$i];      
		            $bind_names[] = &$$bind_name;   
	      	  	}

	            call_user_func_array(array($stmt,'bind_param'), $bind_names);

            }

			$stmt->execute();

	        $meta = $stmt->result_metadata();
	        while($field = $meta->fetch_field()) { 
	            $var = $field->name; 
	            $$var = null; 
	            $fields[$var] = &$$var;
	        }

	        call_user_func_array(array($stmt,'bind_result'),$fields);

	        $i = 0;
	        $results = array();
	        while ($stmt->fetch()) {
	            $results[$i] = array();
	            foreach($fields as $k => $v){
	                $results[$i][$k] = $v;
	                if($more != null){
	        			for($j=0; $j<count($more); $j++)
	        				$results[$more[$j]] = "";
	       			}
	            }
	            $i++;
	        }


			$stmt->close();
			return $results;
		}

		return null;
	}


	protected function update(Array $datas, $where, Array $wheredatas){
		foreach ($datas as $key => $value)
			$campos[] = "$value=? ";

		$campos = implode(", ", $campos);

		$sql = "UPDATE $this->_tabela SET $campos WHERE $where";
		if($stmt = $this->mysqli->prepare($sql)){

			$this->setTypes($wheredatas);
			$arr = $this->assocArray($wheredatas);

		    $bind_names[] = $this->types;
	        for($i=0; $i<count($arr); $i++) {
	            $bind_name = 'bind' . $i;       
	            $$bind_name = $arr[$i];      
	            $bind_names[] = &$$bind_name;   
      	  	}

            call_user_func_array(array($stmt,'bind_param'), $bind_names);

            $stmt->execute();
			$stmt->close();

		}

		return null;
	}


	protected function delete($where, Array $wheredatas){

		$sql = "DELETE FROM $this->_tabela WHERE $where";
		if($stmt = $this->mysqli->prepare($sql)){

			if($wheredatas != null){

				$this->setTypes($wheredatas);
				$arr = $this->assocArray($wheredatas);

			    $bind_names[] = $this->types;
		        for($i=0; $i<count($arr); $i++) {
		            $bind_name = 'bind' . $i;       
		            $$bind_name = $arr[$i];      
		            $bind_names[] = &$$bind_name;   
	      	  	}

	            call_user_func_array(array($stmt,'bind_param'), $bind_names);

            }

            $stmt->execute();
			$stmt->close();

		}
		return null;
	}

}