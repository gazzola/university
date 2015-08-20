<?php

class Photos extends Controller{

	public function index_index(){

		$ses = new sessionHelper();
		$idAtual = $ses->getSession('loginId');

		$var = (System::getUrl(1) != null) ? System::getUrl(1) : $idAtual;
		$col = ($var == $idAtual) ? "id" : "nome_url";


		$photos = new photosModel();

		if($var != $idAtual){
			$photos->_tabela = "usuarios";
			$res0 = $photos->listaDados("id", "nome_url=?", array("nome_url"=>$var));
			if(count($res0) > 0){
				$idres = $res0[0]['id'];
			}
			else
				$idres = $idAtual;
			$exibeadd = true;
		}
		else{
			$idres = $idAtual;
			$exibeadd = false;
		}

		$exibeacc = 0;

		if($exibeadd){
			$photos->_tabela = "amizades";
			$res00 = $photos->listaDados("id_usuario, id_amigo, status", "((id_amigo=? AND id_usuario=?) OR (id_amigo=? AND id_usuario=?)) AND status<=?", array("id_amigo"=>$idres, "id_usuario"=>$idAtual, "id_amigo2"=>$idAtual, "id_usuario2"=>$idres, "status"=>1));
			if(count($res00) > 0){
				$exibeadd = false;
				$res000 = $photos->listaDados("status, id_usuario", "((id_usuario=? AND id_amigo=?) OR (id_usuario=? AND id_amigo=?)) AND status=?", array("id_usuario"=>$idAtual, "id_amigo"=>$idres, "id_usuario2"=>$idres, "id_amigo2"=>$idAtual, "status"=>0));
				if(count($res000) > 0)
					$exibeacc = ($res000[0]['status'] == 0 && $res000[0]['id_usuario']==$idAtual) ? 2 : 1;
			}
			else
				$exibeadd = true;
		}

		$photos->_tabela = "fotos";
		$res0 = $photos->listaDados("foto, descricao", "id_usuario=?", array("id_usuario"=>$idres), "id DESC");

		$photos->_tabela = "publicacoes";
		$res2 = $photos->listaDados("id_usuario, id_amigo", "id_usuario=? AND status=?", array("id_usuario"=>$idAtual, "status"=>0));
		$photos->_tabela = "usuarios";
		$res2 = $photos->organizaDados($res2, array("nome_usuario", "nome_usuario_url", "foto_usuario"), $idAtual);

		$photos->_tabela = "amizades";
		$res3 = $photos->listaDados("id_usuario, id_amigo", "id_usuario=? AND status=?", array("id_usuario"=>$idAtual, "status"=>0));
		$photos->_tabela = "usuarios";
		$res3 = $photos->organizaDados($res3, array("nome_usuario", "nome_usuario_url", "foto_usuario"), $idAtual);

		$photos->_tabela = "usuarios";
		$res = $photos->listaDados("nome, foto, id, nome_url, fundo", "$col=?", array($col=>$var));
		
		$photos->_tabela = "mensagens";
		$res4 = $photos->listaDados("id_usuario, id_amigo, conteudo, status", "id_amigo=?", array("id_amigo"=>$idres), "id DESC", null);
		$photos->_tabela = "usuarios";
		$res4 = $photos->organizaDados($res4, array("nome_usuario", "nome_usuario_url", "foto_usuario"), $idres);

		$res6 = $photos->listaDados("nome, nome_url, foto, cidade_uf", "id>?", array("id"=>0), "nome");

		if(count($res) > 0){

			$data['sobre'] = $res[0];
			$data['publicacoes'] = $res2;
			$data['requisicoes'] = $res3;
			$data['idres'] = $idres;
			$data['fotos'] = $res0;
			$data['mensagens'] = $res4;
			$data['add'] = $exibeadd;
			$data['acc'] = $exibeacc;
			$data['pesquisar'] = $res6;

			$this->view('photos', $data);
		}
		else{

			$photos->_tabela = "usuarios";
			$res = $photos->listaDados("nome, foto, nome_url, id", "id=?", array("id"=>$idres));

			$data['sobre'] = $res[0];
			$data['publicacoes'] = $res2;
			$data['requisicoes'] = $res3;
			$data['mensagens'] = $res4;
			$data['add'] = false;
			$data['acc'] = false;
			$data['pesquisar'] = $res6;

			$this->view('error404', $data);
		}

	}

	public function enviar(){

		if($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['descricao']) && !empty($_POST['descricao'])){

			$ses = new sessionHelper();
			$idAtual = $ses->getSession('loginId');

			$descricao = strip_tags(trim($_POST['descricao']));
			$foto = $_FILES['foto'];
			
			$foto_tmp = $foto["tmp_name"];
			$name = $foto["name"];
			$type = $foto["type"];
			$permitido = array('image/jpg', 'image/jpeg', 'image/pjpeg', 'image/png', 'image/gif');	

			if(!empty($foto) && in_array($type, $permitido)){
					

				$var = substr(System::getBase(), 1);
				$root = $_SERVER['DOCUMENT_ROOT'];
				$bar = ($root[strlen($root)-1] != '/') ? '/' : '';
				$path = $root.$bar.$var."_assets/uploads/fotos/";

				$IH = new ImgHandlerHelper();
				$IH->setPath($path);
				$IH->setMaxImgSize(1400, 900);
				$novaFoto = $IH->saveImg($foto_tmp);
				$novaFoto = str_replace($path, "", $novaFoto);

				$upm = new photosModel();
				$upm->insereDados(array("id_usuario"=>$idAtual, "foto"=>$novaFoto, "descricao"=>$descricao));

			}

			$red = new redirectorHelper();
			$red->go('photos/');

		}
		else{
			$red->go('');
		}
	
	}

	public function excluir(){

		$ses = new sessionHelper();
		$idAtual = $ses->getSession('loginId');

		$foto = strip_tags(trim(System::getUrl(2)));

		if(!empty($foto)){
			$upm = new photosModel();
			$upm->deletaDados("id_usuario=? AND foto=?", array("id_usuario"=>$idAtual, "foto"=>$foto));
		}

		$red = new redirectorHelper();
		$red->go('photos/');

	}

}