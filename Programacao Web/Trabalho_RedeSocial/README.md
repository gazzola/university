#TRABALHO REDE SOCIAL - PROGRAMA��O PARA WEB

-MARCOS TREVISO - 121150107 
-PAULO ALMEIDA - 121151639

-APLICA��O ONLINE EM: http://desenvolvimento.madlap.com.br/progweb/
-MAPA DO SITE: mapa.php
-ARQUIVOS NA PASTA '_datas'

INICIAR APLICA��O:
>> TRABALHO FUNCIONA COM REESCRITA DE URL VIA HTACCESS:
deve-se ent�o habilitar o mod_rewrite do apache, para isso basta
abrir o httpd.conf e descomentar a linha de inclus�o do mod_rewrite (CTRL+F em mod_rewrite, tirar o '#')

>> NECESSITA DE BANCO DE DADOS MYSQL:
deve-se importar o arquivo progweb.sql
ou deve-se criar o banco com o nome 'progweb' e importar o arquivo progweb_bd.sql

>> ORGANIZA��O:
- pasta '_assets' para ser colocados assets para as p�ginas
- pasta 'system' guarda as fun��es do sistema e helpers para controle da aplica��o
- pasta 'app' guarda a estrutura mvc

>> OBSERVA��ES:
- chat sem implementa��o, pois requer configura��o de long polling do servidor
- foi utilizada a biblioteca javascript jquery para algumas intera��es
- para ajax foi utlizado tambem o jquery
