<?php

class Search extends Controller{

	public function index_index(){

		$ses = new sessionHelper();
		$idAtual = $ses->getSession('loginId');
		$pesq = (System::getUrl(1) != null) ? System::getUrl(1) : $idAtual;

		$search = new searchModel();

		$search->_tabela = "publicacoes";
		$res2 = $search->listaDados("id_usuario, id_amigo", "id_usuario=? AND status=?", array("id_usuario"=>$idAtual, "status"=>0));
		$search->_tabela = "usuarios";
		$res2 = $search->organizaDados($res2, array("nome_usuario", "nome_usuario_url", "foto_usuario"), $idAtual);

		$search->_tabela = "amizades";
		$res3 = $search->listaDados("id_usuario, id_amigo", "id_usuario=? AND status=?", array("id_usuario"=>$idAtual, "status"=>0));
		$search->_tabela = "usuarios";
		$res3 = $search->organizaDados($res3, array("nome_usuario", "nome_usuario_url", "foto_usuario"), $idAtual);
		
		$search->_tabela = "mensagens";
		$res4 = $search->listaDados("id_usuario, id_amigo, conteudo, status", "id_amigo=?", array("id_amigo"=>$idAtual), "id DESC", null, array("nome_usuario", "foto_usuario"));
		$search->_tabela = "usuarios";
		$res4 = $search->organizaDados($res4, array("nome_usuario", "nome_usuario_url", "foto_usuario"), $idAtual);

		$res5 = $search->listaDados("nome, nome_url, foto, cidade_uf", "nome LIKE CONCAT('%', ?, '%') OR email LIKE CONCAT('%', ?, '%') OR cidade_uf LIKE CONCAT('%', ?, '%')", array("nome"=>$pesq, "email"=>$pesq, "cidade_uf"=>$pesq), "nome");
		$res6 = $search->listaDados("nome, nome_url, foto, cidade_uf", "id>?", array("id"=>0), "nome");

		$res = $search->listaDados("id, nome_url, nome, email, data_nascimento, telefone, cidade_uf, foto, fundo", "id=?", array("id"=>$idAtual));
		

		if(count($res) > 0){

			$data['sobre'] = $res[0];
			$data['publicacoes'] = $res2;
			$data['requisicoes'] = $res3;
			$data['idres'] = $idAtual;
			$data['mensagens'] = $res4;
			$data['add'] = false;
			$data['acc'] = false;
			$data['pesquisar_users'] = $res5;
			$data['pesquisar'] = $res6;

			$this->view('search', $data);
		}
		else{

			$search->_tabela = "usuarios";
			$res = $search->listaDados("nome, foto, nome_url, id", "id=?", array("id"=>$idAtual));

			$data['sobre'] = $res[0];
			$data['publicacoes'] = $res2;
			$data['requisicoes'] = $res3;
			$data['mensagens'] = $res4;
			$data['add'] = false;
			$data['acc'] = false;
			$data['pesquisar'] = $res5;

			$this->view('error404', $data);
		}

	}

}