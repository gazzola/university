<?php

class Messages extends Controller{

	public function index_index(){
		$red = new redirectorHelper();
		$red->go('');
	}

	public function reply(){

		$red = new redirectorHelper();

		if($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['postmessagemodal']) && !empty($_POST['postmessagemodal'])){
			$ses = new sessionHelper();
			$idAtual = $ses->getSession('loginId');
			$idPost = System::getUrl(2);
			$ret = System::getUrl(3);

			$messages = new messagesModel();
			$messages->_tabela = "usuarios";
			$res = $messages->listaDados("nome_url", "id=?", array("id"=>$idPost));

			if(count($res) > 0){
				$urlnome =$res[0]['nome_url'];
				$postmessagemodal = strip_tags(trim($_POST['postmessagemodal']));
				$postmessagemodal = $messages->transformLink($postmessagemodal);
				$messages->_tabela = "mensagens";
				$messages->insereDados(array("id_usuario"=>$idAtual, "id_amigo"=>$idPost, "conteudo"=>$postmessagemodal, "status"=>0));
			}
			
			if($ret == "i")
				$red->go('');
			else
				$red->go('user/'.$urlnome.'/');
		}
		else{
			$red->go('');
		}
	}

}