<?php

class Publish extends Controller{

	public function index_index(){
		$red = new redirectorHelper();
		$red->go('');
	}

	public function send(){

		$red = new redirectorHelper();

		if($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['postmessagearea']) && !empty($_POST['postmessagearea'])){
			$ses = new sessionHelper();
			$idAtual = $ses->getSession('loginId'); //friend
			$idUser = System::getUrl(2);

			$publish = new publishModel();
			$publish->_tabela = "usuarios";
			$res = $publish->listaDados("nome_url", "id=?", array("id"=>$idUser));

			if(count($res) > 0){
				$urlnome =$res[0]['nome_url'];
				$postmessagearea = strip_tags(trim($_POST['postmessagearea']));
				$postmessagearea = $publish->transformLink($postmessagearea);
				$publish->_tabela = "publicacoes";
				$data = "No dia ".date("d/m/Y")." às ".date("H:i");
				$publish->insereDados(array("id_usuario"=>$idUser, "id_amigo"=>$idAtual, "conteudo"=>$postmessagearea, "status"=>1, "data"=>$data, "num_curtir"=>0));
				
			}

			if($idAtual == $idUser || count($res) <= 0){
				$red->go('');
			}
			else{
				$red->go('user/'.$urlnome.'/');
			}
				
		}
		else{
			$red->go('');
		}
	}

	public function delete(){
		$red = new redirectorHelper();
		$ses = new sessionHelper();
		$idAtual = $ses->getSession('loginId');
		$idPost = System::getUrl(2);

		$comment = new commentModel();
		$comment->_tabela = "usuarios";
		$res = $comment->listaDados("nome_url", "id=?", array("id"=>$idAtual));

		if(count($res) > 0){

			$comment->_tabela = "publicacoes";
			$comment->deletaDados("id=? AND id_usuario=?", array("id"=>$idPost, "id_usuario"=>$idAtual));

			$comment->_tabela = "comentarios";
			$comment->deletaDados("id_publicacao=?", array("id_publicacao"=>$idPost));

		}
		
		$red->go('');
	}

}
