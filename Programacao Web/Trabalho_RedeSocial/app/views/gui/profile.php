<div id="profile">

	<div id="avatar">
		<?php
			$urlped = System::getBase()."system/helpers/phpThumb/phpThumb.php?src=../../../_assets/uploads/fotos_perfil/";
			$urlped2 = "&amp;fltr[]=gam|1.2&amp;fltr[]=usm;q=100&amp;w=158&amp;h=170&amp;zc=1";
			$url = $urlped.$view_sobre['foto'].$urlped2;
			$url2 = "uploads/fotos_perfil/".$view_sobre['foto'];
		?>
		<a class="fancyapps" data-fancybox-href="<?php echo $url2; ?>" data-fancybox-title="<?php echo $view_sobre['nome']; ?>">
		
		<div class="shadow">
			<img src="<?php echo $url; ?>" />
		</div>

		</a>
	</div><!-- AVATAR -->

	<div id="infos">
		<div id="info_title">
			<a href="<?php echo System::getBase(); ?>user/<?php echo $view_sobre['nome_url']; ?>/">
			<?php echo $view_sobre['nome']; ?>
			</a>
		</div>
		<div id="info_buttons">
		
		<a class="input_button pl mhr" href="<?php echo System::getBase(); ?>about/<?php echo ($IDGLOBAL != $view_sobre['id']) ? $view_sobre['nome_url'].'/' : ''; ?>">
			<img src="images/icons/info.png" width="20" />
			Sobre
		</a>

		<a class="input_button pl mhr" href="<?php echo System::getBase(); ?>photos/<?php echo ($IDGLOBAL != $view_sobre['id']) ? $view_sobre['nome_url'].'/' : ''; ?>">
			<img src="images/icons/image.png" width="20" />
			Fotos
		</a>

		<?php
		$qtdmsg = 0;
			foreach ($view_mensagens as $value) {
				if($value['status'] == "0")
					$qtdmsg++;
			}

			if($qtdmsg == 0)
				$qtdmsg = "";
			else
				$qtdmsg = "($qtdmsg)";
		?>

		<a id="bt_escrever_msg" class="input_button pl mhr" rel="<?php echo $view_sobre['id']; ?>">
			<img src="images/icons/<?php echo ($IDGLOBAL != $view_sobre['id']) ? "write" : "messages"; ?>.png" width="20" />
			<span id="bt_escrever_msg_txt"><?php echo ($IDGLOBAL != $view_sobre['id']) ? "Escrever" : "Mensagens $qtdmsg"; ?></span>
		</a>

		<?php if($view_add && $IDGLOBAL != $view_sobre['id']){ ?>
		<a class="input_button pr tooltip" title="Adicionar" href="<?php echo System::getBase(); ?>add/<?php echo $view_sobre['nome_url']; ?>/true/">
			<img src="images/icons/plus.png" width="20" class="nmh" />
		</a>
		<?php 
		}
		else{
			if($view_acc == 2){
		?>
			<a class="input_button pr tooltip" title="Aceitar" href="<?php echo System::getBase(); ?>add/accept/<?php echo $view_sobre['nome_url']; ?>/true/">
				<img src="images/icons/key.png" width="20" class="nmh" />
			</a>
			<?php
			}
			else{
				if($IDGLOBAL != $view_sobre['id'] && $view_acc == 1){
			?>
				<a class="input_button pr tooltip" title="Remover Solicitacao" href="<?php echo System::getBase(); ?>add/cancel/<?php echo $view_sobre['nome_url']; ?>/true/">
					<img src="images/icons/block.png" width="20" class="nmh" />
				</a>
		<?php
				}
				else if($IDGLOBAL != $view_sobre['id'] && $view_acc == 0){
				?>

				<a class="input_button pr tooltip" title="Remover Amizade" href="<?php echo System::getBase(); ?>add/reject/<?php echo $view_sobre['nome_url']; ?>/true/">
					<img src="images/icons/block.png" width="20" class="nmh" />
				</a>

				<?php
				}
			}
		} 
		?>

		<a class="input_button pr mhr" href="<?php echo System::getBase(); ?>friends/<?php echo ($IDGLOBAL != $view_sobre['id']) ? $view_sobre['nome_url'].'/' : ''; ?>">
			<img src="images/icons/people.png" width="20" />
			Amigos
		</a>

		</div>
	</div><!-- INFOS -->

</div><!-- PROFILE -->

<div class="cleaner"></div>


<div id="modalwind" class="dnone">
<?php

if($IDGLOBAL == $view_sobre['id']){

	$k = 0;
	foreach ($view_mensagens as $value) {

	$urlped = System::getBase()."system/helpers/phpThumb/phpThumb.php?src=../../../_assets/uploads/fotos_perfil/";
	$urlped2 = "&amp;fltr[]=gam|1.2&amp;fltr[]=usm;q=80&amp;w=70&amp;h=80&amp;zc=1";
	$url = $urlped.$value['foto_usuario'].$urlped2;

?>
	
	<div>
		<img class="pl mhr" src="<?php echo $url; ?>" />
		<a class="linksx" href="<?php echo System::getBase(); ?>user/<?php echo $value['nome_usuario_url']; ?>/"><div class="title sub"><?php echo $value['nome_usuario']; ?></div></a>
		<div class="lineo"></div>

		<div class="text mht">
			<?php echo $value['conteudo']; ?>
		</div>

		<div class="mh"></div>
		<a class="input_button mini pl mhr btnresp" rel="<?php echo $k; ?>">Responder</a>

		<form name="form_messages_<?php echo $k; ?>" id="form_messages_<?php echo $k; ?>" method="post" action="<?php echo System::getBase(); ?>messages/reply/<?php echo $value['id_usuario']; ?>/i/">
			<textarea class="input_text_area mht dnone pl mini" id="postmessagemodal_<?php echo $k; ?>" name="postmessagemodal" placeholder="Escreva sua mensagem..."></textarea>
			<a class="input_button btnenv pl mhl dnone mini" rel="<?php echo $k; ?>" id="postmessagemodalenv_<?php echo $k ?>">Enviar</a>
		</form>

		<div class="cleaner"></div>
		<br>
	</div>

	<br>
	<br>

<?php
	$k++;
	}
	if($k == 0)
		echo "<center>Nenhuma mensagem recebida.</center>";
}
else{
?>
	<div>
		<form name="form_messages_0" id="form_messages_0" method="post" action="<?php echo System::getBase(); ?>messages/reply/<?php echo $view_sobre['id']; ?>/">
			<textarea class="input_text_area mht full" id="postmessagemodal_0" name="postmessagemodal" placeholder="Escreva sua mensagem..."></textarea>
			<br><br>
			<a class="input_button btnenv mht mini" rel="0" id="postmessagemodalenv_0">Enviar</a>
		<br>
		<br>
		<br>
		</form>
	</div>
<?php
}
?>

</div>




<script type="text/javascript">

$(document).ready(function(){

	$("#bt_escrever_msg").click(function(){
		$.fancybox.open({
			href : "#modalwind", 
			openEffect:'elastic', 
			closeEffect:'elastic',
			minWidth: 790,
			maxWidth: 800,
			maxHeight: 600,
			afterLoad: function(){

				if($("#bt_escrever_msg_txt").html() != "Escrever"){
					$.ajax({
						method:"get",
						url:"<?php echo System::getBase(); ?>app/models/ajaxModel.php",
						data:"tipo=mensagens&id="+<?php echo $IDGLOBAL; ?>,
						success: function(filtrar){
							$("#bt_escrever_msg_txt").html("Mensagens");
						}
								
					});	
					
					
				}
			}
		});
	})

	$("#modalwind div .btnresp").live("click", function(){
		var rel = $(this).attr("rel");
		$(this).hide();
		$("#postmessagemodal_"+rel+"").slideDown("fast");
		$("#postmessagemodalenv_"+rel+"").slideDown("fast");
	});

	$("#modalwind div .btnenv").live("click", function(){
		var rel = $(this).attr("rel");
		if($("#postmessagemodal_"+rel+"").val() == "")
			$("#postmessagemodal_"+rel+"").css("border", "1px solid #C94A4A");
		else
			$("#form_messages_"+rel+"").submit();
	});

});

</script>