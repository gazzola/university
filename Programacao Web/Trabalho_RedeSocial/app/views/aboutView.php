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
						<img src="images/icons/info_w.png" width="24" class="icons" /> Sobre
						
						<a class="input_button mini tooltip pr mhr edit" title="Editar"><img src="images/icons/pen.png" width="12" class="nmh" /></a>
						
					</div>

					<div id="post_message_middle">
						<br>
						<br>
						<div class="text">	
							<form name="form_sobre" id="form_sobre" action="<?php echo System::getBase(); ?>about/editar/" method="post" enctype="multipart/form-data">
	
								<span class="input_text_left"></span>
								<input type="text" class="input_text" id="nome" name="nome" size="45" placeholder="Nome" />
								<span class="input_text_right"></span>
								<div class="cleaner"></div>

								<br>

								<span class="input_text_left"></span>
								<input type="text" class="input_text" id="datanasc" name="datanasc" size="45" placeholder="Data de Nascimento" />
								<span class="input_text_right"></span>
								<div class="cleaner"></div>

								<br>

								<span class="input_text_left"></span>
								<input type="text" class="input_text" id="telefone" name="telefone" size="45" placeholder="Telefone" />
								<span class="input_text_right"></span>
								<div class="cleaner"></div>

								<br>

								<span class="input_text_left"></span>
								<input type="text" class="input_text" id="cidadeuf" name="cidadeuf" size="45" placeholder="Cidade - UF" />
								<span class="input_text_right"></span>
								<div class="cleaner"></div>


								<br>
								<a class="input_button pl" id="enviar_foto_bt" onclick="editar_sobre();"><img src="images/icons/up.png" width="18" />Enviar</a>
								<div id="errorfoto" class="error pl mhl mht"></div>
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
				<img src="images/icons/info_w.png" width="36" class="icons" /> <span class="title_pag">SOBRE</span>
				<div class="lineo"></div>
				<br>
				<br>
				<?php
				}
				?>


				<div class="publications">

					<span class="title sub">Informacoes Pessoais</span>
					<div class="line"></div>

					<div class="mh"></div>

					<div class="text basic">

						<b>Nome:</b> <a href="mailto:<?php echo $view_sobre['email']; ?>" class="linksx"><?php echo $view_sobre['nome']; ?></a>
						<div class="mh"></div>
						<b>Data de Nascimento:</b> <?php echo $view_sobre['data_nascimento']; ?>
						<div class="mh"></div>
						<b>Telefone:</b> <?php echo $view_sobre['telefone']; ?>
						<div class="mh"></div>
						<b>Cidade - UF:</b> <?php echo ($view_sobre['cidade_uf'] == "default") ? "Nao cadastrado" : $view_sobre['cidade_uf']; ?>

					</div>

				</div>

				<br>
				<br>
				<br>
				<br>

				

				<span class="title sub">Publicacoes Recentes</span>
				<div class="line"></div>


				<?php 

				$urlped = "system/helpers/phpThumb/phpThumb.php?src=../../../_assets/uploads/fotos_perfil/";
				$urlped2 = "&amp;q=80&amp;w=120&amp;h=130&amp;zc=1";
				foreach ($view_publicacoes_ult as $key => $value) {
					$url = System::getBase().$urlped.$value['foto_usuario'].$urlped2;
				?>
				<div class="publications">
				<?php if($key > 0){ ?><div class="line"></div><?php } ?>
					
					<img class="headimg" src="<?php echo $url; ?>" width="80" height="80" class="pl" />
					<div class="headers">
						<span class="title"><?php echo $view_sobre['nome']; ?></span> 
						<span class="normal">publicou no <?php echo ($value['id_usuario'] == $view_sobre['id']) ? "seu proprio mural" : "mural de <a class='linksx' href='".System::getBase()."user/".$value['nome_usuario_url']."/'>".$value['nome_amigo']."</a>"; ?></span>
						<div class="mh"></div>
						<span class="mute"><img src="images/icons/clock.png" width="16" /> <?php echo $value['data'] ?></span>
					</div>

					<div class="cleaner"></div>
					<br>

					<div class="text">
					<?php echo nl2br($value['conteudo']); ?>
					</div>

					<div class="cleaner"></div>
					<br><br>

				</div><!-- PUBLICATIONS -->
				<?php
				}
				if(count($view_publicacoes_ult) <= 0)
							echo "<center><span class='sub basic'>Nenhuma publicacao cadastrada.</span></center>";
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

function editar_sobre(){

	var nome = document.getElementById("nome").value;
	var datanasc = document.getElementById("datanasc").value;
	var telefone = document.getElementById("telefone").value;

	if(nome == "" || nome == "Nome")
		document.getElementById("errorfoto").innerHTML = "Digite um nome";
	else if(datanasc == "" || datanasc == "Data de Nascimento")
		document.getElementById("errorfoto").innerHTML = "Digite uma data de nascimento";
	else if(telefone == "" || telefone == "Telefone")
		document.getElementById("errorfoto").innerHTML = "Digite um telefone";
	else{
		document.getElementById("enviar_foto_bt").innerHTML = "Enviando...";
		document.form_sobre.submit();
	}

}

</script>

<?php include_once("gui/scripts.php"); ?>