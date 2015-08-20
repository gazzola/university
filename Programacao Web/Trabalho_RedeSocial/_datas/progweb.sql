
DROP DATABASE IF EXISTS `progweb`;
CREATE DATABASE `progweb` /*!40100 DEFAULT CHARACTER SET utf8 */;
USE `progweb`;

#
# Source for table "amizades"
#

DROP TABLE IF EXISTS `amizades`;
CREATE TABLE `amizades` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `id_usuario` int(11) DEFAULT NULL,
  `id_amigo` int(11) DEFAULT NULL,
  `status` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;


#
# Source for table "comentarios"
#

DROP TABLE IF EXISTS `comentarios`;
CREATE TABLE `comentarios` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `id_publicacao` int(11) DEFAULT NULL,
  `id_usuario` int(11) DEFAULT NULL,
  `conteudo` text,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=13 DEFAULT CHARSET=utf8;


#
# Source for table "fotos"
#

DROP TABLE IF EXISTS `fotos`;
CREATE TABLE `fotos` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `id_usuario` int(11) DEFAULT NULL,
  `foto` text,
  `descricao` text,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8;


#
# Source for table "mensagens"
#

DROP TABLE IF EXISTS `mensagens`;
CREATE TABLE `mensagens` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `id_usuario` int(11) DEFAULT NULL,
  `id_amigo` int(11) DEFAULT NULL,
  `conteudo` text,
  `status` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=20 DEFAULT CHARSET=utf8;


#
# Source for table "publicacoes"
#

DROP TABLE IF EXISTS `publicacoes`;
CREATE TABLE `publicacoes` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `id_usuario` int(11) DEFAULT NULL,
  `id_amigo` int(11) DEFAULT NULL,
  `data` varchar(50) DEFAULT NULL,
  `num_curtir` int(11) DEFAULT NULL,
  `conteudo` text,
  `status` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8;


#
# Source for table "usuarios"
#

DROP TABLE IF EXISTS `usuarios`;
CREATE TABLE `usuarios` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `nome` varchar(100) DEFAULT NULL,
  `nome_url` varchar(150) DEFAULT NULL,
  `email` varchar(75) DEFAULT NULL,
  `data_nascimento` varchar(15) DEFAULT NULL,
  `telefone` varchar(25) DEFAULT NULL,
  `cidade_uf` varchar(75) DEFAULT NULL,
  `foto` text,
  `fundo` varchar(10) DEFAULT NULL,
  `hash` varchar(64) DEFAULT NULL,
  `hash_cookie` varchar(64) DEFAULT NULL,
  `salt` varchar(64) DEFAULT NULL,
  `ip` varchar(25) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=13 DEFAULT CHARSET=utf8;
