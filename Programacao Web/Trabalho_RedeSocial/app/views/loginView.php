<script type="text/javascript" src="scripts/jquery.superbgimage.min.js"></script>
<script type="text/javascript">
$(function() {
	$("html,body").superbgimage();
});
</script>



<div id="global-login" align="center">

	<div id="content" align="center">
		<div class="sub_content">
			

			<span class="title">Entrar na Perspective</span>
			<br>
			<div class="text bold">
				Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod
				tempor incididunt ut labore et dolore magna aliqua. 
			</div>

			<br>
			<br>
			<br>

			
			<div class="window">
			<?php
			if($view_error)
				echo "<span class='error'>Erro: Dados Inválidos!</span><br><br>"
			?>
				<form name="form_login" id="form_login" action="<?php echo System::getBase(); ?>login/entrar/" method="post">
					<input type="text" name="email" id="email" class="input_text_b" placeholder="E-mail" size="45" />
					<div class="mh"></div>
					<input type="password" name="senha" id="senha" class="input_text_b" placeholder="Senha" size="45" />
					<div class="mh"></div>
					<input type="checkbox" name="lembrar" id="lembrar" class="pl mhl" value="ativado" />
					<label for="lembrar" class="mute"> Lembrar Senha</label>
					<a name="entrar" id="entrar" class="input_button mini pr" onclick="login();">Entrar</a>
					<div class="cleaner"></div>
				</form>
			</div>
			<div class="cleaner"></div>
			<br>
			<br>
			<span class="text ">Ou cadastre-se:</span>
			<a class="input_button mhl" href="<?php echo System::getBase(); ?>login/cadastro/"><img src="images/icons/person.png" width="20" />Me cadastrar!</a>

		</div>
	</div><!-- CONTENT -->

	<?php include_once("gui/footer.php"); ?>

</div><!-- GLOBAL -->

<div id="superbgimage">
	<img src="images/backgrounds/bg<?php echo rand(1, 14); ?>.png" alt="" />
</div>


<script type="text/javascript">
function login(){

	var email = document.getElementById("email");
	var senha = document.getElementById("senha");

	var eremail = new RegExp(/^[A-Za-z0-9_\-\.]+@[A-Za-z0-9_\-\.]{2,}\.[A-Za-z0-9]{2,}(\.[A-Za-z0-9])?/);

	if(email.value == "" || email.value =="E-mail"){
		email.style.borderColor = "#C94A4A";
		email.focus();
	}
	else if (!(eremail.test(email.value))){
		email.style.borderColor = "#C94A4A";
		email.focus();
	}
	else if(senha.value == "" || senha.value == "Senha"){
		senha.style.borderColor = "#C94A4A";
		senha.focus();
	}
	else{
		document.getElementById("entrar").innerHTML = 'Entrando...';
		document.form_login.submit();
	}
}
$(document).ready(function(){
	$("#form_login").on("keypress", function(e){
		var keycode;

		if(window.event) 
			keycode = window.event.keyCode;
		else if(e) 
			keycode = e.which;
		
		if(keycode == 13)
			$("#entrar").click();
	});
});
</script>