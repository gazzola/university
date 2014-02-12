<div id="chat">
	<div id="chat_top">
		Bate-Papo
		<input type="text" id="search_chat" placeholder="Procurar...">
	</div>

	<div id="chat_middle">
		<div class="chat_content">
		<div class="error mht bold" align="center">Bate-Papo em manutenção.</div>
		<?php 

		$tam = count($view_pesquisar)+1;
		foreach ($view_pesquisar as $key => $value) {
			$urlped = System::getBase()."system/helpers/phpThumb/phpThumb.php?src=../../../_assets/uploads/fotos_perfil/";
			$urlped2 = "&amp;q=80&amp;w=40&amp;h=40&amp;zc=1";
			$url = $urlped.$value['foto'].$urlped2;
			if(rand(0, $tam) % ($key+2) == 0)
				$varn = 'n';
			else
				$varn = '';
		?>
			<div class="chat_user" data-id="<?php echo $key+1; ?>">
				<img src="<?php echo $url; ?>" />
				<span class="nome"><?php echo $value['nome']; ?></span>
				<span class="<?php echo $varn; ?>status">•</span>
				<div class="cleaner"></div>
			</div>

		<?php
		}
		?>
			
			<div id="cont_fanboxes"></div>
		</div>
	</div>

	<div id="chat_bottom"></div>
	
</div><!-- CHAT -->

<div class="cleaner"></div>

<?php 
foreach ($view_pesquisar as $key => $value) {
?>
	<div id="selectormsg_<?php echo $key+1; ?>" class="dnone dialog" title="<?php echo $value['nome']; ?>">

		<br>
		<textarea class="input_text_area" placeholder="Enviar mensagem..." style="width:90%;"></textarea>
		<div class="mh"></div>
		<a class="input_button mini">Enviar</a> 
		<a class="mhl linksx" href="<?php echo System::getBase(); ?>user/<?php echo $value['nome_url']; ?>/">Ver perfil de <?php echo $value['nome']; ?></a>
		<div class="mh"></div>
	</div>
<?php } 
?>



<link href="scripts/scrollbar/perfect-scrollbar.css" rel="stylesheet">
<script type="text/javascript" src="scripts/scrollbar/jquery.mousewheel.js"></script>
<script type="text/javascript" src="scripts/scrollbar/perfect-scrollbar.js"></script>
<script type="text/javascript" src="scripts/jquery.sticky.js"></script>


<link rel="stylesheet" href="http://code.jquery.com/ui/1.10.3/themes/smoothness/jquery-ui.css" />
<script src="http://code.jquery.com/ui/1.10.3/jquery-ui.js"></script>

<script type="text/javascript">

$(document).ready(function(){
	
	var hp = $(window).height()-200;
	$("#chat_middle").css("height", hp);
	
	$('#chat_middle').perfectScrollbar({
		wheelSpeed: 50
	});
	$("#chat").sticky({ 
		topSpacing: 20
	});

	var total = $("#chat_middle .chat_user").length;

	$("#search_chat").bind('keyup', function(){

		var psq = $(this).val().toLowerCase();
		
		if(psq == "pesquisar"){
			jAlert("errado", "Digite uma pesquisa que contenha pelo menos 2 caracteres");
			return false;
		}
		else{
			$('.chat_user').each(function(){
				if($(this).find('.nome').html().toLowerCase().indexOf(psq) != -1){
					$(this).show();
					$(this).attr("data-rel", "ok");
				}
				else{
					$(this).hide();
					$(this).attr("data-rel", "notok");
				}
			});
			
			if($("#search_chat .chat_user[data-rev=notok]").length == total){
				$("#cont_fanboxes").html("<br><center><span class='text'>Nenhum amigo encontrado.</span></center>");
			}
			else{
				$("#cont_fanboxes").html("");
			}	
		
		}
			
	});


	$('.dialog').dialog({
        autoOpen: false,
        width: 350,
        maxWidth: 500,
        maxHeight: 350,
        buttons: false,
        position: { my: "left top", at: "left bottom", of: window }
    });
 
    $('#chat_middle .chat_user').click(function(){
	    var id_link = $(this).attr('data-id');
	    $('#selectormsg_'+id_link).dialog('open');
	    return false;
    });

});

</script>