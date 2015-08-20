<?php

class Add extends Controller{

	public function index_index(){

		$ses = new sessionHelper();
		$idAtual = $ses->getSession('loginId');
		$nomePost = System::getUrl(1);

		$add = new addModel();
		$ver = $add->listaDados("id", "nome_url=?", array("nome_url"=>$nomePost));

		$red = new redirectorHelper();

		if(count($ver) > 0){
			$id = $ver[0]['id'];
			$add->_tabela = "amizades";
			$add->insereDados(array("id_usuario"=>$id, "id_amigo"=>$idAtual, "status"=>0));	
			$red->go('user/'.$nomePost.'/');	
		}
		else{
			$red->go('');
		}

	}

	public function accept(){

		$ses = new sessionHelper();
		$idAtual = $ses->getSession('loginId');
		$nomePost = System::getUrl(2);
		$return = System::getUrl(3);

		$add = new addModel();
		$ver = $add->listaDados("id", "nome_url=?", array("nome_url"=>$nomePost));

		$red = new redirectorHelper();

		if(count($ver) > 0){
			$idAmigo = $ver[0]['id'];
			$add->_tabela = "amizades";
			$add->editaDados(array("status"), "id_usuario=? AND id_amigo=?", array("status"=>1, "id_usuario"=>$idAtual, "id_amigo"=>$idAmigo));
		}

		if($return != null && $return == 'true')
			$red->go('user/'.$nomePost.'/');
		else
			$red->go('');

	}

	public function reject(){
		$ses = new sessionHelper();
		$idAtual = $ses->getSession('loginId');
		$nomePost = System::getUrl(2);
		$return = System::getUrl(3);

		$add = new addModel();
		$ver = $add->listaDados("id", "nome_url=?", array("nome_url"=>$nomePost));

		$red = new redirectorHelper();

		if(count($ver) > 0){
			$idAmigo = $ver[0]['id'];
			$add->_tabela = "amizades";
			$add->deletaDados("status=? AND id_usuario=? AND id_amigo=?", array("status"=>0, "id_usuario"=>$idAtual, "id_amigo"=>$idAmigo));
			
		}

		if($return != null && $return == 'true')
			$red->go('user/'.$nomePost.'/');
		else
			$red->go('');
	}


	public function cancel(){
		$ses = new sessionHelper();
		$idAtual = $ses->getSession('loginId');
		$nomePost = System::getUrl(2);
		$return = System::getUrl(3);

		$add = new addModel();
		$ver = $add->listaDados("id", "nome_url=?", array("nome_url"=>$nomePost));

		$red = new redirectorHelper();

		if(count($ver) > 0){
			$idAmigo = $ver[0]['id'];
			$add->_tabela = "amizades";
			$add->deletaDados("status=? AND id_usuario=? AND id_amigo=?", array("status"=>0, "id_usuario"=>$idAmigo, "id_amigo"=>$idAtual));
		}

		if($return != null && $return == 'true')
			$red->go('user/'.$nomePost.'/');
		else
			$red->go('');
	}

}