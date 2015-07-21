-- SELECT 'robos1' as 'tabela', COUNT(idrobos) FROM robos1
-- UNION
-- SELECT 'robos2', COUNT(idrobos) FROM robos2
-- UNION
-- SELECT 'robos3', COUNT(idrobos) FROM robos3
-- UNION
-- SELECT 'robos4', COUNT(idrobos) FROM robos4
-- UNION
-- SELECT 'robos5', COUNT(idrobos) FROM robos5;
-- 
 

-- CALL dowhile(100, 'robos1');
-- CALL dowhile(1000, 'robos2');
-- CALL dowhile(10000, 'robos3');
-- CALL dowhile(100000, 'robos4');


-- EXPLAIN SELECT * FROM robos1 WHERE idrobos != 42

-- remove cache effects
-- SET GLOBAL query_cache_size = 0;
-- SET GLOBAL query_cache_type = 0;
-- 
SELECT * FROM robos5 WHERE pais != 42;
