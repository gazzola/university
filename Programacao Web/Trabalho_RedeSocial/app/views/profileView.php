<div id="global" align="center">

	<?php include_once("gui/header.php"); ?>

	<div id="content" align="center">
		<div class="sub_content">
			<?php 
				include_once("gui/profile.php");
			?>


			<div id="mural">
			<?php  if($IDGLOBAL == $view_sobre['id']){  ?>
				<div id="post_message">
					<div id="post_message_top">
						<img src="images/icons/people_w.png" width="24" class="icons" /> Configurar Perfil
						
						<a class="input_button mini tooltip pr mhr edit" title="Editar"><img src="images/icons/pen.png" width="12" class="nmh" /></a>
						
					</div>

					<div id="post_message_middle">
						<br>
						<br>
						<div class="text">	
							<form name="form_profile" id="form_profile" action="<?php echo System::getBase(); ?>profile/editar/" method="post" enctype="multipart/form-data">
								
								<span class="mhl bold">Foto de Perfil:</span>
								<br>
								<span class="input_text_left"></span>
								<input type="file" class="input_text" id="foto" name="foto" size="45" />
								<span class="input_text_right"></span>
								<div class="cleaner"></div>

								<br><br>

								<span class="mhl bold">Foto de Fundo:</span>
								<br>
								<?php
								$valor = explode(".", $view_sobre['fundo']);
								$valor = substr($valor[0], 2);
								$x = 1;
								while($x<=14){
									if($x!=12 && $x!=7){
										if($x == $valor)
											$var = "id='activebg'";
										else
											$var = '';

								?>
								<img src="images/backgrounds/thumbs/bg<?php echo $x; ?>.jpg" <?php echo $var; ?> class="pl mhl mht products" height="46" onclick="mudar_fundo('<?php echo $x; ?>', this);" />
								<?php

									}
									$x++;
								}
								?>
								<input type="hidden" name="fundo" id="fundo" value="bg<?php echo $valor; ?>">
								<div class="cleaner"></div>
								<br>
								<a class="input_button pl" id="enviar_foto_bt" onclick="editar_profile();"><img src="images/icons/up.png" width="18" />Enviar</a>
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
				?>


			</div>

			<?php
				include_once("gui/chat.php");
			?>

		</div>
	</div><!-- CONTENT -->

	<?php include_once("gui/footer.php"); ?>

</div><!-- GLOBAL -->

<script type="text/javascript">

function editar_profile(){

	document.getElementById("enviar_foto_bt").innerHTML = "Enviando...";
	document.form_profile.submit();
}

var ant = document.getElementById("activebg");
function mudar_fundo(ele, th){
	document.getElementById("background").src = "images/backgrounds/bg"+ele+".png";
	document.getElementById("fundo").value = "bg"+ele;
	ant.style.borderColor = "rgba(255,255,255,0.3)";
	th.style.borderColor = "#4C707F";
	ant = th;
}

</script>

<?php include_once("gui/scripts.php"); ?>