<?php

require_once("model.php");
require_once("basicModel.php");
require_once("indexModel.php");

class ajaxModel extends Model{

	public function editarMensagens($id, $tipo){
		$this->_tabela = $tipo;
		return $this->update(array("status"), "id_amigo=?", array("status"=>1, "id_amigo"=>$id));
	}

	public function incluirComentarios($tipo, $id_pub, $id_user, $conteudo){
		$this->_tabela = $tipo;
		return $this->insert(array(
								"id_publicacao"=>$id_pub,
								"id_usuario"=>$id_user,
								"conteudo"=>$conteudo
							));
	}

	public function curtirPublicacao($tipo, $id_pub, $qtd){
		$this->_tabela = $tipo;
		return $this->update(array("num_curtir"), "id=?", array("num_curtir"=>$qtd, "id"=>$id_pub));
	}

	public function verNotificacoes($tipo, $id_user){
		$this->_tabela = $tipo;
		return $this->update(array("status"), "id_usuario=?", array("status"=>1, "id_usuario"=>$id_user));
	}

	public function carregarPost($qtd){


		$inicio = $qtd;
		$final = $qtd + 5;
		$limit = $inicio.",".$final;

		$idAtual = $_SESSION['loginId'];

		$first = new indexModel();
		$first->_tabela = "publicacoes";
		$res5 = $first->read("id, id_usuario, id_amigo, conteudo, num_curtir, data", "id_usuario=? AND status<=?", array("id_usuario"=>$idAtual, "status"=>1), "id DESC", $limit);
		$first->_tabela = "usuarios";
		$res5 = $first->organizaDados($res5, array("nome_usuario", "nome_usuario_url", "foto_usuario", "comentarios"), $idAtual);

		return $res5;

	}

}

$ajax = new ajaxModel();

if($_GET['tipo'] == "mensagens"){
	$ajax->editarMensagens($_GET['id'], $_GET['tipo']);
}
else if($_GET['tipo'] == "comentarios"){
	$ajax->incluirComentarios($_GET['tipo'], $_GET['id_pub'],  $_GET['id_user'],  $_GET['conteudo']);
}
else if($_GET['tipo'] == "curtir"){
	$ajax->curtirPublicacao("publicacoes", $_GET['id_pub'], (int) $_GET['qtd']);
}
else if($_GET['tipo'] == "notificacoes"){
	$ajax->verNotificacoes("publicacoes", $_GET['id']);
}
else if($_GET['tipo'] == "postagens"){

	require_once("../../system/ISystem.php");
	require_once("../../system/system.php");

	session_start();
	$view_postagens = $ajax->carregarPost($_GET['qtd']);
	//$view_postagens = $ajax->carregarPost(5);

	$IDGLOBAL = $_SESSION['loginId'];
	

	$count = $_GET['qtd']+5;
	foreach ($view_postagens as $value) {
		$urlped = $_GET['base']."system/helpers/phpThumb/phpThumb.php?src=../../../_assets/uploads/fotos_perfil/";
		$urlped2 = "&amp;fltr[]=gam|1.2&amp;fltr[]=usm;q=80&amp;w=80&amp;h=80&amp;zc=1";
		$url = $urlped.$value['foto_usuario'].$urlped2;
	?>

	<div class="publications">
	<div class="line"></div>
	<a href="<?php echo $_GET['base']; ?>user/<?php echo $value['nome_usuario_url']; ?>/"><img class="headimg" src="<?php echo $url; ?>" class="pl" /></a>
	<div class="headers">
		<a class="linksx" href="<?php echo $_GET['base']; ?>user/<?php echo $value['nome_usuario_url']; ?>/"><span class="title"><?php echo $value['nome_usuario']; ?></span></a>
		<span class="normal">publicou no <?php if($value['id_usuario'] == $_GET['sobreid']) echo "seu proprio mural."; else echo "no mural de ".$_GET['sobrenome']; ?></span>
		<div class="mh"></div>

		<span class="mute"><img src="images/icons/clock.png" width="16" /> <?php echo $value['data'] ?></span>
		
	</div>

	<?php if($IDGLOBAL == $value['id_usuario']){ ?>	
	<a onclick="deletar_post('<?php echo $count; ?>');">
		<div class="block tooltip" title="Deletar Publicacao">
			<img src="images/icons/block.png" width="24" />
		</div>
	</a>
		
	<a id="slave_delete_<?php echo $count; ?>" href="<?php echo $_GET['base']; ?>publish/delete/<?php echo $value['id']?>/"></a>
	<?php } ?>

	<div class="cleaner"></div>
	<br>

	<div class="text">
	<?php echo nl2br($value['conteudo']); ?>
	</div>
	<br>

	<a class="input_button pl mini mhr comment" rel="<?php echo $count; ?>" rev="0">
		<img src="images/icons/pen.png" width="16" />
		Comentar
	</a>

	<a class="input_button pl mini mhr likebutton" rel="<?php echo $value['id']; ?>" rev="<?php echo $value['num_curtir']; ?>">
		<img src="images/icons/like.png" width="16" />
		Curtir <span id="numlike_<?php echo $value['id']; ?>" class="numb"><?php echo ($value['num_curtir']>0) ? "(".$value['num_curtir'].")" : ""; ?></span>
	</a>

	<div class="cleaner"></div>
	<br>

	<form name="form_comment_<?php echo $count; ?>" id="form_comment_<?php echo $count; ?>" action="<?php echo $_GET['base']; ?>comment/add/<?php echo $value['id']; ?>/<?php echo $_GET['sobreid']; ?>/" method="post" enctype="multipart/form-data">
		<textarea id="pub_textarea_<?php echo $count; ?>" name="conteudo_comentario" class="input_text_area dnone" cols="60" rows="3" placeholder="Escreva um comentario..."></textarea>
		<div class="mh"></div>
		<a id="pub_button_<?php echo $count; ?>" rel="<?php echo $count; ?>" class="input_button mini dnone envbtcomment">Enviar</a>
	</form>

	<div class="mh"></div>

	<?php
	foreach ($value['comentarios'] as $key => $value) {
		
		$urlped = $_GET['base']."system/helpers/phpThumb/phpThumb.php?src=../../../_assets/uploads/fotos_perfil/";
		$urlped2 = "&amp;fltr[]=gam|1.2&amp;fltr[]=usm;q=80&amp;w=50&amp;h=50&amp;zc=1";
		$url = $urlped.$value['comment_foto_usuario'].$urlped2;

	?>
	<div id="comment_num_<?php echo $count; ?>" class="comments">

		<?php if($IDGLOBAL == $value['id_usuario']){ ?>	
		<a onclick="deletar_comment('<?php echo $count+$key; ?>');" class="pr">
			<div class="block tooltip" title="Deletar Comentario">
				<img src="images/icons/block.png" width="14" />
			</div>
		</a>
			
		<a id="slave_delete_comment_<?php echo $count+$key; ?>" href="<?php echo $_GET['base']; ?>comment/delete/<?php echo $value['id']?>/<?php echo $_GET['sobrenomeurl']; ?>/"></a>
		<?php } ?>

		<a class="pl pl mhr tooltip" title="<?php echo $value['comment_nome_usuario']; ?>" href="<?php echo $_GET['base']; ?>user/<?php echo $value['comment_nome_url']; ?>/">
			<img class="pic" src="<?php echo $url; ?>" />
		</a>
		<div class="text">
			<?php echo $value['conteudo']; ?>
		</div>
		<div class="cleaner"></div>
	</div>

	<?php
	}
	?>

	</div><!-- PUBLICATIONS -->
	<?php
	$count++;
	}

	

}



?>