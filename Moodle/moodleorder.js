// Anonymous "self-invoking" function
(function() {
    // Load the script
    var script = document.createElement("SCRIPT");
    script.src = 'https://ajax.googleapis.com/ajax/libs/jquery/1.7.1/jquery.min.js';
    script.type = 'text/javascript';
    document.getElementsByTagName("head")[0].appendChild(script);

    // Poll for jQuery to come into existance
    var checkReady = function(callback) {
        if (window.jQuery)
            callback(jQuery);
        else
            window.setTimeout(function() { checkReady(callback); }, 100);
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

            var cursos = new Array();
            cursos[0] = "Arquitetura e Organizacao de Computadores I";
            cursos[1] = "Arquitetura e Organização de Computadores II";
            cursos[2] = "Banco de Dados I";
            cursos[3] = "Computação Gráfica";
            cursos[4] = "Comunicação de Dados";
            cursos[5] = "Inteligência Inteligência Artificial";
            cursos[6] = "Introdução ao Processamento de Imagens Digitais";
            cursos[7] = "Introdução ao Processamento Paralelo";
            cursos[8] = "Laboratório de Desenvolvimento de Jogos Digitais";
            cursos[9] = "Língua Inglesa Instrumental I";
            cursos[10] = "Linguagens Formais";
            cursos[11] = "Organização de Arquivos e Dados";
            cursos[12] = "Projeto de Linguagens de Programação";
            cursos[13] = "Projeto e Análise de Algoritmos";
            cursos[14] = "Segurança da Informação";
            cursos[16] = "Sistemas Sistemas Operacionais";


            var semestres = new Array();
            semestres[0] = cursos[0]+"!@!"+cursos[3]+"!@!"+cursos[4]+"!@!"+cursos[6]+"!@!"+cursos[7]+"!@!"+cursos[11];
            semestres[1] = cursos[1]+"!@!"+cursos[2]+"!@!"+cursos[8]+"!@!"+cursos[13]+"!@!"+cursos[14];
            semestres[2] = cursos[5]+"!@!"+cursos[8]+"!@!"+cursos[9]+"!@!"+cursos[10]+"!@!"+cursos[12];

            var ntext, text = "";
            for(i=0; i<semestres.length; i++){
                text += "Semestre "+(i+3)+":<hr>";  
                ncursos = semestres[i].split("!@!");
                ntext = "";
                for(j=0; j<ncursos.length; j++)
                    ntext += ncursos[j]+"<br>";
                text += ntext+"<br>";
            }


            $("#yui_3_13_0_2_1400003315461_27").html(text);

        });
        
    });
})();