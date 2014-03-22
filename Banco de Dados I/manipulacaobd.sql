--------------------------------------
------------- SIMLPES -----------------
--------------------------------------


--SELECT nome, ling_cidada FROM acao WHERE ling_cidada LIKE '%A%';
--SELECT DISTINCT nome FROM funcao;
--SELECT CONCAT(nome, '-', uf) as cidadeuf FROM municipio WHERE id > 2;
--SELECT * FROM favorecido, municipio


--------------------------------------
------- AGREGACAO/ORDENACAO ----------
--------------------------------------

--SELECT DISTINCT nome, id FROM funcao ORDER BY id DESC LIMIT 5;
--SELECT sum(val_repasse) FROM pagamento;
--SELECT count(mod_aplicacao) FROM pagamento GROUP BY mod_aplicacao;
--SELECT nome, count(nome) FROM programa WHERE id_acao > 1 GROUP BY nome ORDER BY nome ASC



--------------------------------------
------------- JOINS ------------------
--------------------------------------

-- Seleciona pagamentos do programa bolsa familia,
-- exibindo o nome da funcao e o favorecido, fonte de finalidade e o valor de repasse.
/*
SELECT 
pagamento.id, funcao.nome AS funcao, favorecido.nome AS favorecido, programa.nome AS programa,
fonte_finalidade, val_repasse
FROM pagamento
INNER JOIN funcao
ON pagamento.id_funcao = funcao.id
INNER JOIN programa
ON funcao.id_programa = programa.id AND programa.nome = 'Bolsa Família'
INNER JOIN favorecido
ON pagamento.id_favorecido = favorecido.id;
*/

--------------------------------------


-- Alterar valores de repasse para programas com bolsa familia para 450
/*
UPDATE pagamento 
SET val_repasse = 450.00 
WHERE id in (
	SELECT 
	pagamento.id
	FROM pagamento
	INNER JOIN funcao
	ON pagamento.id_funcao = funcao.id
	INNER JOIN programa
	ON funcao.id_programa = programa.id AND programa.nome = 'Bolsa Família'
	INNER JOIN favorecido
	ON pagamento.id_favorecido = favorecido.id
	);
*/


--------------------------------------


-- Selecionar todos registros de pagamentos que foram destinados para Boa Vista
-- e que o valor de repasse seja maior que 150.00, exibindos o nome do municipio junto com a sigla uf,
-- e o fonte de finalidade, valor de repasse, modalidade de aplicacao e numero do convenio.
/*
SELECT pagamento.id, concat(municipio.nome, ' - ', municipio.uf) AS mun_uf, 
pagamento.fonte_finalidade, pagamento.val_repasse, pagamento.mod_aplicacao, pagamento.num_convenio
FROM pagamento
INNER JOIN municipio 
ON pagamento.id_municipio = municipio.id AND municipio.nome = 'Boa Vista'
WHERE pagamento.val_repasse > 150;
*/


--------------------------------------


-- O sistema nao aceita valores de repasse maiores que 500, ao nao aceitar, deve-se entao,
-- deletar os registros com valores de repasse maiores que 500.

/*
DELETE FROM pagamentos
WHERE val_repasse > 500;
*/


--------------------------------------


-- Selecionar todos os registros destinados ao Fundo Municipal de Educação, em qualquer municipio,
-- onde a funcao seja educacao. 
-- Deve-se exibir o nome do programa utilizado e o nome do municipio e o valor de repasse.
-- Deve-se exibir apenas os resultados cujo val_repasse seja menor que a media de todos pagamentos.
/*
SELECT pagamento.id, municipio.nome as municipio, programa.nome as programa, pagamento.val_repasse
FROM pagamento
INNER JOIN municipio ON pagamento.id_municipio = municipio.id
INNER JOIN funcao ON pagamento.id_funcao = funcao.id AND funcao.nome = 'Educação'
INNER JOIN programa ON funcao.id_programa = programa.id
INNER JOIN favorecido ON pagamento.id_favorecido = favorecido.id AND favorecido.nome = 'Fundo Municipal de Educação'
WHERE pagamento.val_repasse < (SELECT avg(val_repasse) FROM pagamento);
*/


--------------------------------------


-- Saber a quantidade de registros cujo favorecido do pagamento nao tenha sido a Prefeitura
-- agrupar para a funcao que comece com a letra E no nome.

/*
SELECT count(funcao.nome)--, funcao.nome
FROM pagamento
INNER JOIN funcao ON pagamento.id_funcao = funcao.id
INNER JOIN favorecido ON pagamento.id_favorecido = favorecido.id and favorecido.nome != 'Prefeitura'
GROUP BY funcao.nome LIKE 'E%'--, funcao.nome
HAVING funcao.nome LIKE 'E%';
*/


--------------------------------------


-- Selecionar a quantidade de favorecidos que estao na tabela de pagamento,
-- e os que nao estao. Juntamente com todos os municipios, inclusive os que nao estao
-- relacionados com a tabela de pagamento. Agrupar o resultado por valores de repasse menores/maiores que 300

/*
SELECT count(val_repasse)
FROM pagamento
RIGHT JOIN favorecido ON pagamento.id_favorecido = favorecido.id
RIGHT JOIN municipio ON pagamento.id_municipio = municipio.id
GROUP BY val_repasse < 300;
*/


--------------------------------------


-- O usuario gostaria de saber qual a data que foi realizada o pagamento
-- deve-se alterar a tabela de pagamento e incluir o campo data

-- ALTER TABLE pagamento DROP IF EXISTS data;
-- ALTER TABLE pagamento ADD data char(10) DEFAULT to_char(CURRENT_DATE,'DD/MM/YYYY');


--------------------------------------


-- Atualizar as datas dos pagamentos 1 e 5 para 30/05/2014 e do pagamento 2 e 3 para 10/03/2014
/*UPDATE pagamento SET data = '30/02/2014' WHERE id in (1, 5);
UPDATE pagamento SET data = '20/04/2014' WHERE id in (2, 3);*/


--------------------------------------

-- Selecionar subfuncao que tenha educacao no nome e que o pagamento seja de hoje, deve-se mostrar o nome da funcao
-- nome da subfuncao, nome do programa, nome da acao, valor de repasse e a data,
-- ordenar por valor de repasse e limitar a apenas os 3 primeiros registros.
/*
SELECT funcao.nome, subfuncao.nome, programa.nome, acao.nome, val_repasse, data 
FROM pagamento
INNER JOIN funcao ON pagamento.id_funcao = funcao.id
INNER JOIN subfuncao ON funcao.id_subfuncao = subfuncao.id
INNER JOIN programa ON funcao.id_programa = programa.id
INNER JOIN acao ON programa.id_acao = acao.id
WHERE data = to_char(CURRENT_DATE,'DD/MM/YYYY')
ORDER BY val_repasse
LIMIT 3;
*/


--------------------------------------

-- Selecionar os programas com todas acoes, inclusives as nao relacionadas com algum programa.
-- Juntamente com o nome do municipio e o favorecido, mostrando a fonte de finalidade, o valor
-- de repasse e a data, para todos os pagamentos que nao foram cadastrados hoje.
-- Ordenar por data
/*
SELECT programa.nome, acao.nome, municipio.nome, favorecido.nome, fonte_finalidade, val_repasse, data
FROM pagamento
INNER JOIN funcao ON pagamento.id_funcao = funcao.id
INNER JOIN programa ON funcao.id_programa = programa.id
RIGHT JOIN acao ON programa.id_acao = acao.id
INNER JOIN favorecido ON pagamento.id_favorecido = favorecido.id
INNER JOIN municipio ON pagamento.id_municipio = municipio.id
WHERE data <> to_char(CURRENT_DATE,'DD/MM/YYYY')
ORDER BY data;
*/


--------------------------------------

-- Selecionar todos pagamentos, com todas informacoes referentes a ele
-- que o data seja antes que a de hoje.
-- Ordenar por valor data, e valor de repasse
/*
SELECT pagamento.id, municipio.nome as municipio, favorecido.nome as favorecido, programa.nome as programa,
acao.nome as acao, funcao.nome as funcao, subfuncao.nome as subfuncao, pagamento.fonte_finalidade,
pagamento.val_repasse, pagamento.num_convenio, pagamento.data
FROM pagamento
INNER JOIN municipio ON pagamento.id_municipio = municipio.id
INNER JOIN favorecido ON pagamento.id_favorecido = favorecido.id
INNER JOIN funcao ON pagamento.id_funcao = funcao.id
INNER JOIN subfuncao ON funcao.id_subfuncao = subfuncao.id
INNER JOIN programa ON funcao.id_programa = programa.id
INNER JOIN acao ON programa.id_acao = acao.id
WHERE 
CONCAT(SUBSTRING(data, 7, 4), SUBSTRING(data, 4, 2), SUBSTRING(data, 1, 2))--::int
< 
CONCAT(SUBSTRING(to_char(CURRENT_DATE,'DD/MM/YYYY'), 7, 4), SUBSTRING(to_char(CURRENT_DATE,'DD/MM/YYYY'), 4, 2), SUBSTRING(to_char(CURRENT_DATE,'DD/MM/YYYY'), 1, 2))--::int
ORDER BY pagamento.data, pagamento.val_repasse;
*/







