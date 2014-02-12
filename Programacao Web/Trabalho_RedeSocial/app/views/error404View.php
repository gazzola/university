<div id="global" align="center">

	<?php include_once("gui/header.php"); ?>

	<div id="content" align="center">
		<div class="sub_content">
			<?php 
				include_once("gui/profile.php");
			?>

			<br>
			<br>

			<div align="center">
				<span class="title_pag">ERRO 404: Desculpe, esta página não está disponível.</span>
				<div class="linex"></div>
				<div class="mh"></div>
				<div class="text">
					<div class="basic" align="center">O link que você seguiu pode estar quebrado ou a página pode ter sido removida.</div>
				</div>
				<br>
				<br>
				<a class="input_button mini mhr" href="javascript:history.go(-1);">Voltar à pagina anterior</a>
				<a class="input_button mini" href="<?php echo System::getBase(); ?>">Voltar à pagina principal</a>

			</div>

		</div>
	</div><!-- CONTENT -->

	<?php include_once("gui/footer.php"); ?>

</div><!-- GLOBAL -->

<?php include_once("gui/scripts.php"); ?>