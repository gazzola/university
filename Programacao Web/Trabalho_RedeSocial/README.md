#TRABALHO REDE SOCIAL - PROGRAMAÇÃO PARA WEB
#MARCOS TREVISO - 121150107 
#PAULO ALMEIDA - 121151639

#APLICAÇÃO ONLINE EM: http://desenvolvimento.madlap.com.br/progweb/
#MAPA DO SITE: mapa.php
#ARQUIVOS NA PASTA '_datas'

INICIAR APLICAÇÃO:
>> TRABALHO FUNCIONA COM REESCRITA DE URL VIA HTACCESS:
deve-se então habilitar o mod_rewrite do apache, para isso basta
abrir o httpd.conf e descomentar a linha de inclusão do mod_rewrite (CTRL+F em mod_rewrite, tirar o '#')

>> NECESSITA DE BANCO DE DADOS MYSQL:
deve-se importar o arquivo progweb.sql
ou deve-se criar o banco com o nome 'progweb' e importar o arquivo progweb_bd.sql

>> ORGANIZAÇÃO:
- pasta '_assets' para ser colocados assets para as páginas
- pasta 'system' guarda as funções do sistema e helpers para controle da aplicação
- pasta 'app' guarda a estrutura mvc

>> OBSERVAÇÕES:
- chat sem implementação, pois requer configuração de long polling do servidor
- foi utilizada a biblioteca javascript jquery para algumas interações
- para ajax foi utlizado tambem o jquery
