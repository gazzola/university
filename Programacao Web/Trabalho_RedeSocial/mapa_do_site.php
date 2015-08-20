<?php

	$URL = $_SERVER['REQUEST_URI'];
	$URL = substr($URL, 0, strlen($URL)-8);

?>

<!DOCTYPE html>
<html>
<head>
	<title>Mapa do Site</title>
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
	<meta name="robots" content="noindex, nofollow" />
	<meta name="googlebot" content="noindex, nofollow" />


	<style type="text/css">

	@charset "utf-8";

	html, body{
		color:#666;
		font-size: 14px;
		background: url(_assets/images/bg.png) repeat #CCC;
		font-family: Arial, sans-serif;
	}

	ul{
		list-style: square;
		border-left: 1px dotted #999;
		padding:0px 0px 0px 10px;
		margin-left: 20px;
	}
	ul li{
		margin-bottom: 25px;
	}

	a{
		color: inherit;
		text-decoration: underline;
	}
	a:hover{
		color: #5A8593;
	}

	dl{
		
		border-left: 1px dotted #CCC;
		padding: 0;
		margin-left: 20px;
		font-size: 12px;

	}
	dl dd{
		margin: 10px 0px 0px;
		padding: 0;
	}
	
	h1{
		color:#333;
		font-size: 64px;
		margin: 0;
		padding: 0;
		font-weight: 600;
		font-family: sans-serif;
		text-shadow:0px 1px 0px #FFF;
	}

	hr{
		height: 0px;
		border-top: 1px solid rgb(204, 204, 204);
		border-bottom: 1px solid rgb(255, 255, 255);
	}

	</style>

</head>
<body>

	<h1>Mapa do Site:</h1>
	<hr>
	<br>

	<ul>
		<li><a href="<?php echo $URL; ?>">Pagina Principal</a></li>

		<li>
			Configuracoes Gerais
			<br>
			<dl>
				<dd><a href="<?php echo $URL; ?>account/">Configurar Conta</a></dd>
				<dd><a href="<?php echo $URL; ?>profile/">Configurar Perfil</a></dd>
				<dd><a href="<?php echo $URL; ?>logout/">Sair</a></dd>
			</dl>
		</li>

		<li><a href="<?php echo $URL; ?>search/">Pesquisar</a></li>

		<li>
			Usuario
			<br>
			<dl>
				<dd><a href="<?php echo $URL; ?>about/">Sobre</a></dd>
				<dd><a href="<?php echo $URL; ?>photos/">Fotos</a></dd>
				<dd><a href="<?php echo $URL; ?>#bt_escrever_msg">Mensagens</a></dd>
				<dd><a href="<?php echo $URL; ?>friends/">Amigos</a></dd>
				<dd><a href="<?php echo $URL; ?>user/">Mural</a></dd>
			</dl>
		</li>

		<li><a href="<?php echo $URL; ?>#chat">Bate-Papo</a></li>

		<li>
			Mais Informacoes
			<br>
			<dl>
				<dd><a href="<?php echo $URL; ?>#footer">Sobre</a></dd>
				<dd><a href="<?php echo $URL; ?>#footer">Desenvolvedores</a></dd>
				<dd><a href="<?php echo $URL; ?>#footer">Termos</a></dd>
			</dl>
		</li>

	</ul>

</body>
</html>