
// Anonymous "self-invoking" function
(function() {
	
	// Load the script
	var script = document.createElement("SCRIPT");
	script.src = 'https://ajax.googleapis.com/ajax/libs/jquery/1.7.1/jquery.min.js';
	script.type = 'text/javascript';
	document.getElementsByTagName("head")[0].appendChild(script);

	// Poll for jQuery to come into existance
	var checkReady = function(callback) {
		if (window.jQuery) {
			callback(jQuery);
		}
		else {
			window.setTimeout(function() { checkReady(callback); }, 100);
		}
	};

	// Start polling...
	checkReady(function($) {
		

		$(document).ready(function(){

			
			var palestras = []
			palestras.push("Desenvolvimento de Software com Baixo Consumo Energético para Dispositivos Móveis.");
			palestras.push("Técnicas de economia de energia e seus trade-offs");
			palestras.push("Coding Dojo");



			// NAO MEXER DAQUI PRA BAIXO!!!!!!!!!!!!!

			$("body").append("<button id='buttonokxd' style='font-size:22px; position:fixed; top:0'>Fechar</button>");
			$("body").append("<table id='tableokxd' style='position:fixed; width:100%; min-height:100px; z-index:99999; background:#000; color:#FFF; border:2px solid #666; top:0; left:0px;'></table>");

			var valores = []
			$(".tabela tr").each(function(){
				for(var i=0, len=palestras.length; i<len; i++){
					if($(this).html().indexOf(palestras[i]) != -1){
						valores.push("<tr>"+$(this).html()+"</tr>");
						break;
					}
				}
			});

			var text = "";
			for(var i=0, len=valores.length; i<len; i++)
				text += valores[i];

			$("#tableokxd").html(text);

			var h = $("#tableokxd").height()+10;
			$("#buttonokxd").css("margin-top",h+"px");
			var ok = true;

			$("#buttonokxd").click(function(){
				if(ok){
					$("#tableokxd").fadeOut("fast");
					$(this).html("Abrir");
				}
				else{
					$("#tableokxd").fadeIn("fast");
					$(this).html("Fechar");
				}

				ok = !ok;
			});


		});
		
	});
})();