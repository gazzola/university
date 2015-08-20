<?php

class Comment extends Controller{

	public function index_index(){
		$red = new redirectorHelper();
		$red->go('');
	}

	public function add(){

		$red = new redirectorHelper();

		if($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['conteudo_comentario']) && !empty($_POST['conteudo_comentario'])){


			$idPost = System::getUrl(2);
			$idUser = System::getUrl(3);
			$ses = new sessionHelper();
			$idAmigo = $ses->getSession('loginId');

			$comment = new commentModel();
			$comment->_tabela = "usuarios";
			$res = $comment->listaDados("nome_url", "id=?", array("id"=>$idUser));

			if(count($res) > 0){

				$urlnome =$res[0]['nome_url'];
				$conteudo_comentario = strip_tags(trim($_POST['conteudo_comentario']));
				$conteudo_comentario = $comment->transformLink($conteudo_comentario);

				$comment->_tabela = "comentarios";
				$comment->insereDados(array("id_publicacao"=>$idPost, "id_usuario"=>$idAmigo, "conteudo"=>$conteudo_comentario));
	
				$red->go('user/'.$urlnome.'/');
			
			}
			else{
				$red->go('');
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

			$urlnome = System::getUrl(3);;
			$comment->_tabela = "comentarios";
			$comment->deletaDados("id=? AND id_usuario=?", array("id"=>$idPost, "id_usuario"=>$idAtual));

			$red->go('user/'.$urlnome.'/');

		}
		else{
			$red->go('');
		}

	}

}