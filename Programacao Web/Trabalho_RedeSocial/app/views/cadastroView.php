<script type="text/javascript" src="scripts/jquery.superbgimage.min.js"></script>
<script type="text/javascript">
$(function() {
	$("html,body").superbgimage();
});
</script>


<div id="global-login" align="center">

	<div id="content" align="center">
		<div class="sub_content">


			<span class="title">Me cadastrar na Perspective</span>
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
				<form name="form_cadastro" id="form_cadastro" action="<?php echo System::getBase(); ?>login/cadastrar/" method="post">
					<input type="text" name="nome" id="nome" class="input_text_b" placeholder="Nome Completo" size="45" />
					<div class="mh"></div>
					<input type="text" name="telefone" id="telefone" class="input_text_b" placeholder="Telefone" size="45" />
					<div class="mh"></div>
					<input type="text" name="datanasc" id="datanasc" class="input_text_b" placeholder="Data de Nascimento" size="45" />
					<div class="mh"></div>
					<input type="text" name="email" id="email" class="input_text_b" placeholder="E-mail" size="45" autocomplete="off" />
					<div class="mh"></div>
					<input type="password" name="senha" id="senha" class="input_text_b" placeholder="Senha" size="45" autocomplete="off" />
					<div class="mh"></div>
					<input type="checkbox" name="lembrar" id="lembrar" class="pl mhl" />
					<label for="lembrar" id="lembrarlabel" class="mute"> Aceito os Termos</label>
					<a name="cadastrar" id="cadastrar" class="input_button mini pr" onclick="cadastro();">Cadastrar</a>
					<div class="cleaner"></div>
				</form>
			</div>

			<div class="cleaner"></div>
			<br>
			<br>
			<span class="text">Ou voltar para <a class="underline" href="<?php echo System::getBase(); ?>login/">login</a></span>

		</div>
	</div><!-- CONTENT -->

	<?php include_once("gui/footer.php"); ?>

</div><!-- GLOBAL -->

<div id="superbgimage">
	<img src="images/backgrounds/bg<?php echo rand(1, 14); ?>.png" alt="" />
</div>



<script type="text/javascript">
function cadastro(){

	var nome = document.getElementById("nome");
	var email = document.getElementById("email");
	var telefone = document.getElementById("telefone");
	var datanasc = document.getElementById("datanasc");
	var senha = document.getElementById("senha");

	var eremail = new RegExp(/^[A-Za-z0-9_\-\.]+@[A-Za-z0-9_\-\.]{2,}\.[A-Za-z0-9]{2,}(\.[A-Za-z0-9])?/);

	if(nome.value == "" || nome.value == "Senha"){
		nome.style.borderColor = "#C94A4A";
		nome.focus();
	}
	else if(telefone.value == "" || telefone.value == "Senha"){
		telefone.style.borderColor = "#C94A4A";
		telefone.focus();
	}
	else if(datanasc.value == "" || datanasc.value == "Data de Nascimento"){
		datanasc.style.borderColor = "#C94A4A";
		datanasc.focus();
	}
	else if(email.value == "" || email.value =="E-mail"){
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
	else if(document.getElementById("lembrar").checked != true){
		document.getElementById("lembrarlabel").style.color = "#C94A4A";
		document.getElementById("lembrarlabel").style.textDecoration = "underline";
	}
	else{
		document.getElementById("cadastrar").innerHTML = 'Entrando...';
		document.form_cadastro.submit();
	}
}
</script>