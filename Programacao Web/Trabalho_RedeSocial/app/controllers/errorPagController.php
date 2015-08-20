<?php

class ErrorPag extends Controller{

	public function index_index(){

		$ses = new sessionHelper();
		$idAtual = $ses->getSession('loginId');


		$errorm = new errorModel();


		$errorm->_tabela = "publicacoes";
		$res2 = $errorm->listaDados("id_usuario, id_amigo", "id_usuario=? AND status=?", array("id_usuario"=>$idAtual, "status"=>0));
		$errorm->_tabela = "usuarios";
		$res2 = $errorm->organizaDados($res2, array("nome_usuario", "nome_usuario_url", "foto_usuario"), $idAtual);

		$errorm->_tabela = "amizades";
		$res3 = $errorm->listaDados("id_usuario, id_amigo", "id_usuario=? AND status=?", array("id_usuario"=>$idAtual, "status"=>0));
		$errorm->_tabela = "usuarios";
		$res3 = $errorm->organizaDados($res3, array("nome_usuario", "nome_usuario_url", "foto_usuario"), $idAtual);

		$errorm->_tabela = "usuarios";
		$res = $errorm->listaDados("nome, foto, nome_url, id, fundo", "id=?", array("id"=>$idAtual));

		$errorm->_tabela = "mensagens";
		$res5 = $errorm->listaDados("id_usuario, id_amigo, conteudo, status", "id_amigo=?", array("id_amigo"=>$idAtual), "id DESC", null, array("nome_usuario", "foto_usuario"));
		$errorm->_tabela = "usuarios";
		$res5 = $errorm->organizaDados($res5, array("nome_usuario", "nome_usuario_url", "foto_usuario"), $idAtual);

		$res6 = $errorm->listaDados("nome, nome_url, foto, cidade_uf", "id>?", array("id"=>0), "nome");

		$data['sobre'] = $res[0];
		$data['publicacoes'] = $res2;
		$data['requisicoes'] = $res3;
		$data['mensagens'] = $res5;
		$data['add'] = false;
		$data['acc'] = false;
		$data['pesquisar'] = $res6;

		$this->view('error404', $data);

	}

}