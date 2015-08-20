<div id="footer_divisor"></div>

<div id="footer">
	<div class="sub_content">
		<div class="line"></div>
		<br>

		Perspective © 2000-2013. Todos os direitos reservados.

		<a class="linksx pr mhl" id="iraotopo">Ir ao topo</a><span class="pr mhl">|</span>
		<a class="linksx pr mhl" data-fancybox-href="#termosmodal" data-fancybox-title="Termos">Termos</a><span class="pr mhl">|</span>
		<a class="linksx pr mhl" data-fancybox-href="#desenvmodal" data-fancybox-title="Desenvolvedores">Desenvolvedores</a><span class="pr mhl">|</span>
		<a class="linksx pr mhl" data-fancybox-href="#sobremodal" data-fancybox-title="Sobre">Sobre</a>
	</div>
</div><!-- FOOTER -->

<div class="dnone text" id="termosmodal">
Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod
tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,
quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo
consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse
cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non
proident, sunt in culpa qui officia deserunt mollit anim id est laborum.

<br>
<br>

Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod
tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,
quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo
consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse
cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non
proident, sunt in culpa qui officia deserunt mollit anim id est laborum.
</div>

<div class="dnone" id="desenvmodal">
• Marcos Treviso
<br>
• Paulo Almeida
</div>

<div class="dnone" id="sobremodal">

<center>Trabalho de Programação Web.</center>
<div class="lineo"></div>
<div class="mh"></div>
Universidade Federal do Pampa.
<div class="mh"></div>
3º Semestre - 2013.
<div class="mh"></div>
PHP + MYSQL + JAVASCRIPT
<div class="mh"></div>

</div>



<!-- Add mousewheel plugin (this is optional) -->
<script type="text/javascript" src="scripts/fancyapps/lib/jquery.mousewheel-3.0.6.pack.js"></script>

<!-- Add fancyBox -->
<link rel="stylesheet" href="scripts/fancyapps/source/jquery.fancybox.css?v=2.1.4" type="text/css" media="screen" />
<script type="text/javascript" src="scripts/fancyapps/source/jquery.fancybox.js?v=2.1.4"></script>

<!-- Optionally add helpers - button, thumbnail and/or media
<link rel="stylesheet" href="scripts/fancyapps/source/helpers/jquery.fancybox-buttons.css?v=1.0.5" type="text/css" media="screen" />
<script type="text/javascript" src="scripts/fancyapps/source/helpers/jquery.fancybox-buttons.js?v=1.0.5"></script>
<script type="text/javascript" src="scripts/fancyapps/source/helpers/jquery.fancybox-media.js?v=1.0.5"></script>
 -->
 
<link rel="stylesheet" href="scripts/fancyapps/source/helpers/jquery.fancybox-thumbs.css?v=1.0.7" type="text/css" media="screen" />
<script type="text/javascript" src="scripts/fancyapps/source/helpers/jquery.fancybox-thumbs.js?v=1.0.7"></script>





<script type="text/javascript">

$(document).ready(function(e) {
	
	$(".fancyapps").fancybox({
		openEffect	: 'elastic',
		closeEffect	: 'elastic',
		helpers	: {
			thumbs	: {
				width	: 50,
				height	: 50
			}
		}
	});

	$("#footer .linksx").fancybox({
		openEffect	: 'elastic',
		closeEffect	: 'elastic',
		maxWidth: 640,
		maxHeight: 480
	});
	
	$("#iraotopo").click(function(){
		$("html, body").animate({ scrollTop: 0 }, "fast");
 		 return false;
	});

});
</script>
