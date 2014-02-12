<?php

class Account extends Controller{

	public function index_index(){

		$ses = new sessionHelper();
		$idAtual = $ses->getSession('loginId');
		$var = (System::getUrl(1) != null) ? System::getUrl(1) : $idAtual;
		$col = ($var == $idAtual) ? "id" : "nome_url";

		$about = new profileModel();

		if($var != $idAtual){
			$about->_tabela = "usuarios";
			$res0 = $about->listaDados("id", "nome_url=?", array("nome_url"=>$var));
			if(count($res0) > 0)
				$idres = $res0[0]['id'];
			else
				$idres = $idAtual;
			$exibeadd = true;
		}
		else{
			$idres = $idAtual; 
			$exibeadd = false;
		}

		if($exibeadd){
			$about->_tabela = "amizades";
			$res00 = $about->listaDados("id_usuario, id_amigo", "((id_amigo=? AND id_usuario=?) OR (id_amigo=? AND id_usuario=?)) AND status=?", array("id_amigo"=>$idres, "id_usuario"=>$idAtual, "id_amigo2"=>$idAtual, "id_usuario2"=>$idres, "status"=>1));
			if(count($res00) > 0)
				$exibeadd = false;
			else
				$exibeadd = true;
		}

		$about->_tabela = "publicacoes";
		$res2 = $about->listaDados("id_usuario, id_amigo", "id_usuario=? AND status=?", array("id_usuario"=>$idAtual, "status"=>0));
		$about->_tabela = "usuarios";
		$res2 = $about->organizaDados($res2, array("nome_usuario", "nome_usuario_url", "foto_usuario"), $idAtual);

		$about->_tabela = "amizades";
		$res3 = $about->listaDados("id_usuario, id_amigo", "id_usuario=? AND status=?", array("id_usuario"=>$idAtual, "status"=>0));
		$about->_tabela = "usuarios";
		$res3 = $about->organizaDados($res3, array("nome_usuario", "nome_usuario_url", "foto_usuario"), $idAtual);
		
		$about->_tabela = "publicacoes";
		$res4 = $about->listaDados("id_usuario, data, conteudo, id_amigo", "id_amigo=? AND status<=?", array("id_amigo"=>$idres, "status"=>1), "id DESC", 2);
		$about->_tabela = "usuarios";
		$res4 = $about->organizaDados($res4, array("nome_amigo", "foto_usuario"), $idres, true); 

		$about->_tabela = "mensagens";
		$res5 = $about->listaDados("id_usuario, id_amigo, conteudo, status", "id_amigo=?", array("id_amigo"=>$idres), "id DESC", null, array("nome_usuario", "foto_usuario"));
		$about->_tabela = "usuarios";
		$res5 = $about->organizaDados($res5, array("nome_usuario", "nome_usuario_url", "foto_usuario"), $idres);

		$res6 = $about->listaDados("nome, nome_url, foto, cidade_uf", "id>?", array("id"=>0), "nome");
		
		$res = $about->listaDados("id, nome_url, nome, email, data_nascimento, telefone, cidade_uf, foto, fundo", "$col=?", array($col=>$var));
		if(count($res) > 0){

			$data['sobre'] = $res[0];
			$data['publicacoes'] = $res2;
			$data['requisicoes'] = $res3;
			$data['idres'] = $idres;
			$data['publicacoes_ult'] = $res4;
			$data['mensagens'] = $res5;
			$data['add'] = false;
			$data['acc'] = false;
			$data['pesquisar'] = $res6;

			$this->view('account', $data);
		}
		else{

			$about->_tabela = "usuarios";
			$res = $about->listaDados("nome, foto, nome_url, id", "id=?", array("id"=>$idres));

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


	public function editar(){

		if($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['senha']) && !empty($_POST['senha'])){

			$ses = new sessionHelper();
			$idAtual = $ses->getSession('loginId');

			$email = strip_tags(trim($_POST['email']));
			$senha = strip_tags(trim($_POST['senha']));
			
			$coo = new cookieHelper();
			$check = $coo->checkCookie('XH2CuociRS');

			$sign = new signHelper();
			$sign->setNewAccount($email, $senha, $check, $idAtual);

			$auth = new authHelper();
			$auth->setUser($email)
				   ->setPass($senha)
				   ->setCheck($check)
				   ->login();
			
			$red = new redirectorHelper();
			$red->go('account/');

		}
		else{
			$red->go('');
		}

	}

}