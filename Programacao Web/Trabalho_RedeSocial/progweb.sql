# Host: localhost  (Version: 5.5.24-log)
# Date: 2013-10-05 14:31:50
# Generator: MySQL-Front 5.3  (Build 3.22)

/*!40101 SET NAMES utf8 */;

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
# Data for table "amizades"
#

INSERT INTO `amizades` VALUES (2,15,16,1);

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
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Data for table "comentarios"
#


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
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;

#
# Data for table "fotos"
#

INSERT INTO `fotos` VALUES (1,15,'13790180635232254f1ae8b449232735.jpg','COD 4');

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
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;

#
# Data for table "mensagens"
#

INSERT INTO `mensagens` VALUES (1,15,16,'dae',0);

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
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

#
# Data for table "publicacoes"
#

INSERT INTO `publicacoes` VALUES (1,15,15,'No dia 12/09/2013 às 20:52',0,'Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod\r\ntempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,\r\nquis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo\r\nconsequat. \r\n\r\nDuis aute irure dolor in reprehenderit in voluptate velit esse\r\ncillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non\r\nproident, sunt in culpa qui officia deserunt mollit anim id est laborum.',1),(2,16,15,'No dia 12/09/2013 às 21:21',0,'<a target=\"_blank\" class=\"linksx\" href=\"http://127.0.0.1/_ProgWeb/friends/angus-young/\">http://127.0.0.1/_ProgWeb/friends/angus-young/</a>\r\n\r\nuaehuaehu',1);

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
) ENGINE=InnoDB AUTO_INCREMENT=17 DEFAULT CHARSET=utf8;

#
# Data for table "usuarios"
#

INSERT INTO `usuarios` VALUES (15,'Mark Knopfler','mark-knopfler','mark@gmail.com','20/09/1992','(55) 84215943','default','default.jpg','bg1.png','60712964729730b22ebb8528aca77db34b9f6d981a7b25df6435db92aed2009a','ffa286a45694cf2fe48ccdff33175d85828bb89ded41c78d9042e4512eb3f965','t%¬´ýqeL¯}Õa','127.0.0.1'),(16,'Angus Young','angus-young','angus@gmail.com','16/06/1975','(54) 3443-2358','default','13790189075232289bc5ed7449107209.jpg','bg3.png','e8f93a38c7d13937cd04d96c5a1ef30e4342356e5a0773712c4fe3fefc25887a','a9778aaae81fa41f900be00d77946c8d07d4474925e21f7ec72a1e67ccb06cf5','OSèõ;òX*Ë|ä','127.0.0.1');
