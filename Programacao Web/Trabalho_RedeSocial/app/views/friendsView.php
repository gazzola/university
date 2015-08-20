<div id="global" align="center">

	<?php include_once("gui/header.php"); ?>

	<div id="content" align="center">
		<div class="sub_content">
			<?php 
				include_once("gui/profile.php");
			?>


			<div id="mural">

			<?php 
			if($IDGLOBAL != $view_sobre['id']){
			?>
				<img src="images/icons/people_w.png" width="36" class="icons" /> <span class="title_pag">AMIGOS</span>
				<a class="input_button mini pr mht" href="<?php echo System::getBase(); ?>friends/<?php echo $view_sobre['nome_url']; ?>/common/" ><img src="images/icons/com.png" width="12" class="nmh"/> Amigos em Comum</a>
				<div class="lineo"></div>
				<br>
				<br>

				<?php 
			}

			$totaldeamigos = count($view_friends);
			if(System::getUrl(2) == "common")
				$totaldeamigos -= 1;
			echo "<span class='text white'>Total: $totaldeamigos amigos</span><br><br>";


				$urlped = "system/helpers/phpThumb/phpThumb.php?src=../../../_assets/uploads/fotos_perfil/";
				$urlped2 = "&amp;q=80&amp;w=120&amp;h=130&amp;zc=1";
				$it = 0;
				foreach ($view_friends as $key => $value) {

					$url = System::getBase().$urlped.$value['foto_usuario'].$urlped2;

					if(System::getUrl(2) == "common"){



						if($value['id_usuario'] != $IDGLOBAL && $value['id_amigo'] != $IDGLOBAL && $value['nome_amigo'] != null){
				?>

						<a class="tooltip pl mhr" title="<?php echo $value['nome_amigo']; ?>" href="<?php echo System::getBase(); ?>user/<?php echo $value['nome_amigo_url']; ?>/">
							<div class="products frnd">
								<img class="pictures" src="<?php echo $url; ?>" />
								<div class="text "><?php echo $value['nome_amigo']; ?></div>
							</div>
						</a>

				<?php
							$it++;
						}

						if($it == 0){
							echo "<div class='text white'><center>Nenhum amigo em comum encontrado.</center></div>";
							$it = 1;
						}
	

					}
					else{
				?>

						<a class="tooltip pl mhr" title="<?php echo $value['nome_amigo']; ?>" href="<?php echo System::getBase(); ?>user/<?php echo $value['nome_amigo_url']; ?>/">
							<div class="products frnd">
								<img class="pictures" src="<?php echo $url; ?>" />
								<div class="text "><?php echo $value['nome_amigo']; ?></div>
							</div>
						</a>

				<?php
					$it++;
					}

					

				}

				if(count($view_friends) <= 0)
					echo "<div class='text white'><center>Nenhum amigo encontrado.</center></div>";
				?>


								


			</div>

			<?php
				include_once("gui/chat.php");
			?>

		</div>
	</div><!-- CONTENT -->

	<?php include_once("gui/footer.php"); ?>

</div><!-- GLOBAL -->

<?php include_once("gui/scripts.php"); ?>