/*
DROP TABLE IF EXISTS pagamento;
DROP TABLE IF EXISTS funcao;
DROP TABLE IF EXISTS subfuncao;
DROP TABLE IF EXISTS programa;
DROP TABLE IF EXISTS acao;
DROP TABLE IF EXISTS municipio;
DROP TABLE IF EXISTS favorecido;
*/


-------------------------------------------------------


CREATE TABLE IF NOT EXISTS acao(
	id int primary key,
	nome varchar(100) not null,
	ling_cidada varchar(75)
);

INSERT INTO acao VALUES (1, 'Serviço de Apoio à Gestão Descentralizada do Programa Bolsa Família', 'Indice de Gestão Descentralizada - IGD');
INSERT INTO acao VALUES (2, 'Apoio à Reestruturação da Rede Física Pública da Educação Básica', 'Promed');
INSERT INTO acao VALUES (3, 'Transferência da Cota-Parte do Salário-Educação (Lei nº 9.424)', 'Cota-parte dos Estados e DF do Salário-Educação');
INSERT INTO acao VALUES (4, 'Implantação de Escolas para Educação Infantil', '');
INSERT INTO acao VALUES (5, 'Promoção da Assistência Farmacêutica e Insumos Estratégicos na Atenção Básica em Saúde', 'Farmácia Básica');
INSERT INTO acao VALUES (6, 'Atenção à Saúde da População para Procedimentos em Média e Alta Complexidade', 'TETO MAC');
INSERT INTO acao VALUES (7, 'Subvenção Econômica a Projetos de Desenvolvimento Tecnológico (Lei nº 10.973)', '');
INSERT INTO acao VALUES (8, 'Elevação da Escolaridade e Qualificação Profissional - ProJovem', '');
INSERT INTO acao VALUES (9, 'Serviços de Proteção Social Básica', 'PAIF/CRAS');
INSERT INTO acao VALUES (10, 'Infraestrutura para a Educação Básica', '');


-------------------------------------------------------


CREATE TABLE IF NOT EXISTS programa(
	id int primary key,
	id_acao int references acao(id),
	nome varchar(100) not null
);

INSERT INTO programa VALUES (1, 1, 'Bolsa Família');
INSERT INTO programa VALUES (2, 2, 'Qualidade na Escola');
INSERT INTO programa VALUES (3, 3, 'Operações Especiais: Transferências Constitucionais e as Decorrentes de Legislação Específica');
INSERT INTO programa VALUES (4, 4, 'Educação Básica');
INSERT INTO programa VALUES (5, 5, 'Aperfeiçoamento do Sistema Único de Saúde (SUS)');
INSERT INTO programa VALUES (6, 6, 'Aperfeiçoamento do Sistema Único de Saúde (SUS)');
INSERT INTO programa VALUES (7, 9, 'Aperfeiçoamento do Sistema Único de Saúde (SUS)');
INSERT INTO programa VALUES (8, 7, 'Ciência Tecnologia e Inovação');
INSERT INTO programa VALUES (9, 8, 'Nacional de Inclusão de Jovens - ProJovem');
INSERT INTO programa VALUES (10, 4, 'Educação Básica');


-------------------------------------------------------


CREATE TABLE IF NOT EXISTS subfuncao(
	id int primary key,
	nome varchar(75) not null
);

INSERT INTO subfuncao VALUES (1, 'Assistência Comunitária');
INSERT INTO subfuncao VALUES (2, 'Transferências para Educação Básica');
INSERT INTO subfuncao VALUES (3, 'Educação Infantil');
INSERT INTO subfuncao VALUES (4, 'Suporte Profilático e Terapêutico');
INSERT INTO subfuncao VALUES (5, 'Assistência Hospitalar e Ambulatorial');
INSERT INTO subfuncao VALUES (6, 'Atenção Básica');
INSERT INTO subfuncao VALUES (7, 'Desenvolvimento Tecnológico e Engenharia');


-------------------------------------------------------


CREATE TABLE IF NOT EXISTS funcao(
	id int primary key,
	id_subfuncao int references subfuncao(id),
	id_programa int references programa(id),
	nome varchar(75) not null
);

INSERT INTO funcao VALUES (1, 1, 1, 'Assistência Social');
INSERT INTO funcao VALUES (2, 2, 2, 'Educação');
INSERT INTO funcao VALUES (3, 3, 4, 'Educação');
INSERT INTO funcao VALUES (4, 2, 3, 'Encargos Especiais');
INSERT INTO funcao VALUES (5, 4, 5, 'Saúde');
INSERT INTO funcao VALUES (6, 5, 6, 'Saúde');
INSERT INTO funcao VALUES (7, 6, 7, 'Saúde');
INSERT INTO funcao VALUES (8, 7, 8, 'Ciência e Tecnologia');


-------------------------------------------------------


CREATE TABLE IF NOT EXISTS municipio(
	id int primary key,
	nome varchar(75) not null,
	uf varchar(10) not null
);

INSERT INTO municipio VALUES (1, 'Alegrete', 'RS');
INSERT INTO municipio VALUES (2, 'Joinville', 'SC');
INSERT INTO municipio VALUES (3, 'Boa Vista', 'RR');
INSERT INTO municipio VALUES (4, 'Vitória', 'ES');
INSERT INTO municipio VALUES (5, 'Curitiba', 'PR');
INSERT INTO municipio VALUES (6, 'São Paulo', 'SP');
INSERT INTO municipio VALUES (7, 'Rio de Janeiro', 'RJ');
INSERT INTO municipio VALUES (8, 'Belo Horizonte', 'MG');
INSERT INTO municipio VALUES (9, 'Belém', 'PA');
INSERT INTO municipio VALUES (10, 'Brasília', 'DF');


-------------------------------------------------------


CREATE TABLE IF NOT EXISTS favorecido(
	id int primary key,
	nome varchar(75) not null
);

INSERT INTO favorecido VALUES (1, 'Fundo Municipal de Assistência Social');
INSERT INTO favorecido VALUES (2, 'Fundo Municipal de Educação');
INSERT INTO favorecido VALUES (3, 'Fundo Municipal de Saúde');
INSERT INTO favorecido VALUES (4, 'Prefeitura');
INSERT INTO favorecido VALUES (5, 'Câmara de Vereadores');


-------------------------------------------------------


CREATE TABLE IF NOT EXISTS pagamento(
	id int primary key,
	id_municipio int references municipio(id),
	id_funcao int references funcao(id),
	id_favorecido int references favorecido(id),
	fonte_finalidade varchar(75) not null,
	mod_aplicacao varchar(75) not null,
	val_repasse decimal CONSTRAINT positive_val CHECK (val_repasse > 0),
	num_convenio int not null
);


INSERT INTO pagamento VALUES (1, 1, 1, 1, 'STN - Convênios/Contratos de Repasses/Fundo a Fundo/Outros', 'Transferências a Municípios - Fundo a Fundo', 412.10, 6102);
INSERT INTO pagamento VALUES (2, 2, 2, 2, 'STN - Convênios/Contratos de Repasses/Fundo a Fundo', 'Transferências a Municípios - Fundo a Fundo', 250.00, 6205);
INSERT INTO pagamento VALUES (3, 3, 5, 3, 'STN - Convênios/Contratos de Repasses/Fundo a Fundo', 'Transferências a Municípios - Fundo a Fundo', 100.40, 6805);
INSERT INTO pagamento VALUES (4, 3, 6, 3, 'STN - Convênios/Contratos de Repasses/Fundo a Fundo/Outros', 'Transferências a Municípios - Fundo a Fundo', 500.75, 6303);
INSERT INTO pagamento VALUES (5, 4, 5, 3, 'STN - Convênios/Fundo a Fundo/Outros', 'Transferências a Municípios - Fundo a Fundo', 220.20, 6621);
INSERT INTO pagamento VALUES (6, 5, 4, 4, 'STN - Convênios/Fundo a Fundo/Outros', 'Transferências a Municípios - Fundo a Fundo', 360.00, 6111);
INSERT INTO pagamento VALUES (7, 8, 8, 4, 'STN - Contratos de Repasses/Fundo a Fundo/Outros', 'Transferências a Municípios - Fundo a Fundo', 273.30, 6445);
