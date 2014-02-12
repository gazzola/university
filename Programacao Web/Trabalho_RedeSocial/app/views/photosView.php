<div id="global" align="center">

	<?php include_once("gui/header.php"); ?>

	<div id="content" align="center">
		<div class="sub_content">
			<?php 
				include_once("gui/profile.php");
			?>

			<div id="mural">
			<?php
				if($view_idres == $IDGLOBAL){
			?>
				<div id="post_message">
					<div id="post_message_top">
						<img src="images/icons/image_w.png" width="24" class="icons" /> Fotos
						<a class="input_button mini tooltip pr mhr edit" title="Editar"><img src="images/icons/pen.png" width="12" class="nmh" /></a>
					</div>

					<div id="post_message_middle">
						<br>
						<br>
						<div class="text">	
							<form name="form_fotos" id="form_fotos" action="<?php echo System::getBase(); ?>photos/enviar/" method="post" enctype="multipart/form-data">

								<span class="input_text_left"></span>
								<input type="file" class="input_text" id="foto" name="foto" size="45" placeholder="Adicionar Foto" />
								<span class="input_text_right"></span>
								<div class="cleaner"></div>

								<br>

	
								<span class="input_text_left"></span>
								<input type="text" class="input_text" id="descricao" name="descricao" size="45" placeholder="Descricao" />
								<span class="input_text_right"></span>
								<div class="cleaner"></div>

								

								<br>
								<a class="input_button pl" id="enviar_foto_bt" onclick="adicionar_foto();"><img src="images/icons/up.png" width="18" />Enviar</a>
								<div id="errorfoto" class="error pl mhl"></div>
								<br>
							</form>
						</div>
					</div>

					<div id="post_message_bottom">	
					</div>

				</div><!-- POST_MESSAGE -->

				<div id="message_divisor"></div>
				<?php
				}
				else{
				?>
				<img src="images/icons/image_w.png" width="36" class="icons" /> <span class="title_pag">FOTOS</span>
				<div class="lineo"></div>
				<br>
				<br>
				<?php
				}
				?>

				<div id="fotoscontent">
					
					<?php 
						$urlped = "system/helpers/phpThumb/phpThumb.php?src=../../../_assets/uploads/fotos/";
						$urlped2 = "&amp;q=80&amp;w=120&amp;h=130&amp;zc=1";

						foreach ($view_fotos as $key => $value) {
							$url = System::getBase().$urlped.$value['foto'].$urlped2;
							$url2 = "uploads/fotos/".$value['foto'];
					?>

					
					<div class="products">
						<a class="fancyapps" data-fancybox-href="<?php echo $url2; ?>" data-fancybox-title="<?php echo $value['descricao']; ?>" rel="fancybox-thumb">
							<img class="pictures" src="<?php echo $url; ?>" />
						</a>

						<?php
							if($view_idres == $IDGLOBAL){
						?>
						<a class="delete" href="<?php echo System::getBase(); ?>photos/excluir/<?php echo $value['foto']; ?>/">Excluir</a>
						<?php
							}
						?>
						
					</div>
					

					<?php
						}
						if(count($view_fotos) <= 0)
							echo "<center><span class='sub basic'>Nenhuma foto cadastrada.</span></center>";
					?>
					
					<div class="cleaner"></div>

				</div>

			</div>	

			<?php
				include_once("gui/chat.php");
			?>

		</div>
	</div><!-- CONTENT -->

	<?php include_once("gui/footer.php"); ?>

</div><!-- GLOBAL -->



<script type="text/javascript">

function adicionar_foto(){

	var foto = document.getElementById("foto").value;
	var desc = document.getElementById("descricao").value;

	if(foto == "")
		document.getElementById("errorfoto").innerHTML = "Escolha uma foto";
	else if(desc == "")
		document.getElementById("errorfoto").innerHTML = "Digite uma descricao";
	else{
		document.getElementById("enviar_foto_bt").innerHTML = "Enviando...";
		document.form_fotos.submit();
	}

}

$(document).ready(function(e) {

	$(".products .pictures").hover(function(){
		$(this).stop().animate({"opacity":"0.4"}, "fast");
	}, function(){
		$(this).stop().animate({"opacity":"1"}, "fast");
	});
	
});
</script>


<?php include_once("gui/scripts.php"); ?>