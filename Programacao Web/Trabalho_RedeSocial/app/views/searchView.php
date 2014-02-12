<div id="global" align="center">

	<?php include_once("gui/header.php"); ?>

	<div id="content" align="center">
		<div class="sub_content">
			<?php 
				include_once("gui/profile.php");
			?>


			<div id="mural">
			
				<img src="images/icons/info_w.png" width="36" class="icons" /> <span class="title_pag">PESQUISAR</span>
				<div class="lineo"></div>
				<br>
				<br>
				<span class=" sub basic">Foram encontrados <?php echo count($view_pesquisar_users); ?> resultados</span>

				<br>
				<span class=" sub basic">Foi pesquisado por: '<?php echo strip_tags(System::getUrl(1)); ?>'</span>
				<br>
				<br>


				<div class="publications">

					<?php
					foreach ($view_pesquisar_users as $value) {
						$urlped = System::getBase()."system/helpers/phpThumb/phpThumb.php?src=../../../_assets/uploads/fotos_perfil/";
						$urlped2 = "&amp;fltr[]=gam|1.2&amp;fltr[]=usm;q=100&amp;w=50&amp;h=50&amp;zc=1";
						$url = $urlped.$value['foto'].$urlped2;
					?>
					<a href="<?php echo System::getBase() ?>user/<?php echo $value['nome_url']; ?>/">
					<div class="subitensh">
						<img src="<?php echo $url; ?>" class="pl mhr" />
						<div class="reqinfos">
							<span class="title sub basic" data-nome="<?php echo $value['nome']; ?>">
								<?php echo $value['nome']; ?>
							</span>
							<div class="mh"></div>
							<span class="text mht">
								<?php echo ($value['cidade_uf']!='default') ? $value['cidade_uf'] : ''; ?>
							</span>
						</div>
						<div class="cleaner"></div>
					</div>
					</a>
					<br>
					<?php
					}
					?>

				</div>

			</div>

			<?php
				include_once("gui/chat.php");
			?>

		</div>
	</div><!-- CONTENT -->

	<?php include_once("gui/footer.php"); ?>

</div><!-- GLOBAL -->

<?php include_once("gui/scripts.php"); ?>