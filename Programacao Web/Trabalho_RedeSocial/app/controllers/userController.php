<?php

class User extends Controller{

	public function index_index(){

		$ses = new sessionHelper();
		$idAtual = $ses->getSession('loginId');

		$first = new indexModel();
		$exibeacc = 0;

		if(System::getUrl(1) != null){
			$var = System::getUrl(1);
			$res = $first->listaDados("nome, foto, id, nome_url, fundo", "nome_url=?", array("nome_url"=>$var));
			if(count($res) <= 0){
				$red = new redirectorHelper();
				$red->go('errorPag/');
			}
			$idAtual = $res[0]['id'];

			$first->_tabela = "amizades";
			$res00 = $first->listaDados("id_usuario, id_amigo, status", "((id_amigo=? AND id_usuario=?) OR (id_amigo=? AND id_usuario=?)) AND status<=?", array("id_amigo"=>$ses->getSession('loginId'), "id_usuario"=>$idAtual, "id_amigo2"=>$idAtual, "id_usuario2"=>$ses->getSession('loginId'), "status"=>1));
			if(count($res00) > 0){
				$exibeadd = false;
				$res000 = $first->listaDados("status, id_usuario", "((id_usuario=? AND id_amigo=?) OR (id_usuario=? AND id_amigo=?)) AND status=?", array("id_usuario"=>$ses->getSession('loginId'), "id_amigo"=>$idAtual, "id_usuario2"=>$idAtual, "id_amigo2"=>$ses->getSession('loginId'), "status"=>0));
				if(count($res000) > 0)
					$exibeacc = ($res000[0]['status'] == 0 && $res000[0]['id_usuario']==$ses->getSession('loginId')) ? 2 : 1;
			}
			else
				$exibeadd = true;

		}
		else{
			$res = $first->listaDados("nome, foto, id, nome_url, fundo", "id=?", array("id"=>$idAtual));
			$exibeadd = false;
		}

		$exibepub = ($exibeacc == 0 && $exibeadd == false) ? true : false;

		$first->_tabela = "publicacoes";
		$res2 = $first->listaDados("id_usuario, id_amigo", "id_usuario=? AND status=?", array("id_usuario"=>$ses->getSession('loginId'), "status"=>0));
		$first->_tabela = "usuarios";
		$res2 = $first->organizaDados($res2, array("nome_usuario", "nome_usuario_url", "foto_usuario"), $ses->getSession('loginId'));

		$first->_tabela = "amizades";
		$res3 = $first->listaDados("id_usuario, id_amigo", "id_usuario=? AND status=?", array("id_usuario"=>$ses->getSession('loginId'), "status"=>0));
		$first->_tabela = "usuarios";
		$res3 = $first->organizaDados($res3, array("nome_usuario", "nome_usuario_url", "foto_usuario"), $ses->getSession('loginId'));
		
		$first->_tabela = "mensagens";
		$res4 = $first->listaDados("id_usuario, id_amigo, conteudo, status", "id_amigo=?", array("id_amigo"=>$idAtual), "id DESC", null, array("nome_usuario", "foto_usuario"));
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
		$data['add'] = $exibeadd;
		$data['acc'] = $exibeacc;
		$data['pub'] = $exibepub;
		$data['pesquisar'] = $res6;

		$this->view('user', $data);

	}

	public function logout(){
		$auth = new authHelper();
		$auth->logout();
	}

}