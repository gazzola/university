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
						<img src="images/icons/people_w.png" width="24" class="icons" /> Configurar Conta
						
						<a class="input_button mini tooltip pr mhr edit" title="Editar"><img src="images/icons/pen.png" width="12" class="nmh" /></a>
						
					</div>

					<div id="post_message_middle">
						<br>
						<br>
						<div class="text">	
							<form name="form_account" id="form_account" action="<?php echo System::getBase(); ?>account/editar/" method="post" enctype="multipart/form-data">
								
								<span class="input_text_left"></span>
								<input type="text" class="input_text" id="email" name="email" size="45" placeholder="E-mail" autocomplete="off" />
								<span class="input_text_right"></span>
								<div class="cleaner"></div>

								<br>

								<span class="input_text_left"></span>
								<input type="password" class="input_text" id="senha" name="senha" size="45" placeholder="Senha" autocomplete="off" />
								<span class="input_text_right"></span>
								<a class="input_button mini pl mhl mht" onclick="gerar_senha();">Gerar Senha</a>
								<div class="cleaner"></div>

								<br>
								<a class="input_button pl" id="enviar_foto_bt" onclick="editar_conta();"><img src="images/icons/up.png" width="18" />Enviar</a>
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

var flag = false;

function editar_conta(){

	var senha = document.getElementById("senha").value;
	var email = document.getElementById("email").value;
	var eremail = new RegExp(/^[A-Za-z0-9_\-\.]+@[A-Za-z0-9_\-\.]{2,}\.[A-Za-z0-9]{2,}(\.[A-Za-z0-9])?/);

	if(email == "" || email =="E-mail"){
		document.getElementById("errorfoto").innerHTML = "Digite um e-mail";
	}
	else if (!(eremail.test(email))){
		document.getElementById("errorfoto").innerHTML = "Digite um e-mail corretamente";
	}
	else if(senha == "" || senha == "Senha"){
		document.getElementById("errorfoto").innerHTML = "Digite uma senha";
	}
	else{

		if(flag) 
			var x = confirm('Anote sua nova senha:'+senha);
		else
			var x = true;

		if(x){
			document.getElementById("enviar_foto_bt").innerHTML = "Enviando...";
			document.form_account.submit();
		}
	}

}

function gerar_senha(){
	document.getElementById("senha").type = "text";
	var ate = 15;
	var ascii = [[0, 122],[0,122],[0,122]];
	var i = Math.floor(Math.random()*(ascii.length));
	var valor = "";
	for(j=0; j<ate; j++){
		valor += String.fromCharCode(Math.floor(Math.random()*(ascii[i][1]-ascii[i][0]))+ascii[i][0]);
	}
	document.getElementById("senha").value = valor.toString();
	flag = true;
}


</script>

<?php include_once("gui/scripts.php"); ?>