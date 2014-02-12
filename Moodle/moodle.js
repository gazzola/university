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
        
        function inArray(arr, obj){
            return (arr.indexOf(obj) != -1);
        }
        
        function removeSeparator(arr, obj){
            while(arr.indexOf(obj) != -1)
                arr = arr.replace(obj, "");
            return arr;
        }


        $(document).ready(function(){

            var cursosn = new Array();
            var arrids = new Array();
            $("#inst311 .list li").each(function(index){
                arrids[index] = $(this).html();
                cursosn[index] = $(this).find("a").html();
            });
            
            
            cursosok = new Array();
            cursosok[0] = "Arquitetura e Organização de Computadores II 02/2013";
            cursosok[1] = "Banco de Dados I 02/2013";
            cursosok[2] = "CC - Programação Orientada a Objetos 02/2013";
            
            count=0;
            for(i=0; i<cursosn.length; i++){
                if(inArray(cursosok, cursosn[i])){
                    cursosok[count] = (arrids[i].indexOf("CC - ") != -1) ? arrids[i].replace("CC - ", "") : arrids[i];
            	    arrids[i] = "";
            	    count++;
            	}
            }
            
            cursosok.sort();
            
            for(i=0; i<cursosok.length; i++)
        		cursosok[i] = "<li>"+cursosok[i]+"</li>";
            
            for(i=0; i<arrids.length; i++)
            	arrids[i] = "<li>"+arrids[i]+"</li>";
  
            
            var conteudo = "<b>Novos:</b><br>"+cursosok+"<br><hr><br><b>Antigos:</b><br>"+arrids;
            conteudo = removeSeparator(conteudo, ",");
            
                
            $("#inst311 .list").html(conteudo);

        });
        
    });
})();