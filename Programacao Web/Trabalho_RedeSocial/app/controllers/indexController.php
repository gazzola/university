<?php

class Index extends Controller{

	public function index_index(){

		$ses = new sessionHelper();
		$idAtual = $ses->getSession('loginId');

		$first = new indexModel();
		$res = $first->listaDados("nome, foto, id, nome_url, fundo", "id=?", array("id"=>$idAtual));
		
		$first->_tabela = "publicacoes";
		$res2 = $first->listaDados("id_usuario, id_amigo", "id_usuario=? AND status=?", array("id_usuario"=>$idAtual, "status"=>0));
		$first->_tabela = "usuarios";
		$res2 = $first->organizaDados($res2, array("nome_usuario", "nome_usuario_url", "foto_usuario"), $idAtual);

		$first->_tabela = "amizades";
		$res3 = $first->listaDados("id_usuario, id_amigo", "id_usuario=? AND status=?", array("id_usuario"=>$idAtual, "status"=>0));
		$first->_tabela = "usuarios";
		$res3 = $first->organizaDados($res3, array("nome_usuario", "nome_usuario_url", "foto_usuario"), $idAtual);

		$first->_tabela = "mensagens";
		$res4 = $first->listaDados("id_usuario, id_amigo, conteudo, status", "id_amigo=?", array("id_amigo"=>$idAtual), "id DESC");
		$first->_tabela = "usuarios";
		$res4 = $first->organizaMensagens($res4, array("nome_usuario", "nome_usuario_url", "foto_usuario"), $idAtual);

		$first->_tabela = "publicacoes";
		$res5 = $first->listaDados("id, id_usuario, id_amigo, conteudo, num_curtir, data", "id_usuario=? AND status<=?", array("id_usuario"=>$idAtual, "status"=>1), "id DESC", 5);
		$first->_tabela = "usuarios";
		$res5 = $first->organizaDados($res5, array("nome_usuario", "nome_usuario_url", "foto_usuario", "comentarios"), $idAtual);

		$res6 = $first->listaDados("nome, nome_url, foto, cidade_uf", "id>?", array("id"=>0), "nome");

		$data['sobre'] = $res[0];
		$data['publicacoes'] = $res2;
		$data['requisicoes'] = $res3;
		$data['mensagens'] = $res4;
		$data['postagens'] = $res5;
		$data['pesquisar'] = $res6;
		$data['add'] = false;
		$data['acc'] = false;
		$data['pub'] = true;

		$this->view('index', $data);
	}

	public function logout(){
		$auth = new authHelper();
		$auth->logout();
	}

}