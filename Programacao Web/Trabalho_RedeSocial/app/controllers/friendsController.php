<?php

class Friends extends Controller{

	public function index_index(){

		$ses = new sessionHelper();
		$idAtual = $ses->getSession('loginId');
		$var = (System::getUrl(1) != null) ? System::getUrl(1) : $idAtual;
		$col = ($var == $idAtual) ? "id" : "nome_url";


		$friends = new friendsModel();

		if($var != $idAtual){
			$friends->_tabela = "usuarios";
			$res0 = $friends->listaDados("id", "nome_url=?", array("nome_url"=>$var));
			if(count($res0) > 0)
				$idres = $res0[0]['id'];
			else
				$idres = $idAtual;
			$exibeadd = true;
		}
		else{
			$exibeadd = false;
			$idres = $idAtual; 
		}	

		$exibeacc = 0;

		if($exibeadd){
			$friends->_tabela = "amizades";
			$res00 = $friends->listaDados("id_usuario, id_amigo, status", "((id_amigo=? AND id_usuario=?) OR (id_amigo=? AND id_usuario=?)) AND status<=?", array("id_amigo"=>$idres, "id_usuario"=>$idAtual, "id_amigo2"=>$idAtual, "id_usuario2"=>$idres, "status"=>1));
			if(count($res00) > 0){
				$exibeadd = false;
				$res000 = $friends->listaDados("status, id_usuario", "((id_usuario=? AND id_amigo=?) OR (id_usuario=? AND id_amigo=?)) AND status=?", array("id_usuario"=>$idAtual, "id_amigo"=>$idres, "id_usuario2"=>$idres, "id_amigo2"=>$idAtual, "status"=>0));
				if(count($res000) > 0)
					$exibeacc = ($res000[0]['status'] == 0 && $res000[0]['id_usuario']==$idAtual) ? 2 : 1;
			}
			else
				$exibeadd = true;

		}


		$friends->_tabela = "publicacoes";
		$res2 = $friends->listaDados("id_usuario, id_amigo", "id_usuario=? AND status=?", array("id_usuario"=>$idAtual, "status"=>0));
		$friends->_tabela = "usuarios";
		$res2 = $friends->organizaDados($res2, array("nome_usuario", "nome_usuario_url", "foto_usuario"), $idAtual);

		$friends->_tabela = "amizades";
		$res3 = $friends->listaDados("id_usuario, id_amigo", "id_usuario=? AND status=?", array("id_usuario"=>$idAtual, "status"=>0));
		$friends->_tabela = "usuarios";
		$res3 = $friends->organizaDados($res3, array("nome_usuario", "nome_usuario_url", "foto_usuario"), $idAtual);


		if(System::getUrl(2) == "common"){
			$friends->_tabela = "amizades";
			$res4 = $friends->listaDados("id_usuario, id_amigo", "(id_amigo=? OR id_usuario=?) AND status=?", array("id_amigo"=>$idres, "id_usuario"=>$idres, "status"=>1), null, null, null, null);
			$res4x = $friends->listaDados("id_usuario, id_amigo", "(id_amigo=? OR id_usuario=?) AND status=?", array("id_amigo"=>$idAtual, "id_usuario"=>$idAtual, "status"=>1), null, null, null, null);
			$friends->_tabela = "usuarios";
			$res4 = $friends->comparaDados($res4, $res4x, array("nome_amigo", "nome_amigo_url", "foto_usuario"), $idres);
		}
		else{
			$friends->_tabela = "amizades";
			$res4 = $friends->listaDados("id_usuario, id_amigo", "(id_amigo=? OR id_usuario=?) AND status=?", array("id_amigo"=>$idres, "id_usuario"=>$idres, "status"=>1), null, null, null, array("nome_amigo", "nome_amigo_url", "foto_usuario"));
			$friends->_tabela = "usuarios";
			$res4 = $friends->organizaDados($res4, array("nome_amigo", "nome_amigo_url", "foto_usuario"), $idres);
		}
		

		$friends->_tabela = "mensagens";
		$res5 = $friends->listaDados("id_usuario, id_amigo, conteudo, status", "id_amigo=?", array("id_amigo"=>$idres), "id DESC", null, array("nome_usuario", "foto_usuario"));
		$friends->_tabela = "usuarios";
		$res5 = $friends->organizaDados($res5, array("nome_usuario", "nome_usuario_url", "foto_usuario"), $idres);

		$res6 = $friends->listaDados("nome, nome_url, foto, cidade_uf", "id>?", array("id"=>0), "nome");
		
		$res = $friends->listaDados("id, nome_url, nome, email, data_nascimento, telefone, cidade_uf, foto, fundo", "$col=?", array($col=>$var));
		if(count($res) > 0){

			$data['sobre'] = $res[0];
			$data['publicacoes'] = $res2;
			$data['requisicoes'] = $res3;
			$data['friends'] = $res4;
			$data['mensagens'] = $res5;
			$data['add'] = $exibeadd;
			$data['acc'] = $exibeacc;
			$data['pesquisar'] = $res6;

			$this->view('friends', $data);
		}
		else{

			$friends->_tabela = "usuarios";
			$res = $friends->listaDados("id, nome, foto, nome_url", "id=?", array("id"=>$idres));

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

}