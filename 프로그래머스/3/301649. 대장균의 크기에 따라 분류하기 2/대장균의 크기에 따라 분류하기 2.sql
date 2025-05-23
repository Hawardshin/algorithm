-- 코드를 작성해주세요
SELECT D.ID
    , CASE
        WHEN D.R >= 0.75 THEN 'CRITICAL'
        WHEN D.R >= 0.5 THEN 'HIGH'
        WHEN D.R >= 0.25 THEN 'MEDIUM'
        ELSE 'LOW'
      END AS COLONY_NAME
FROM (
    SELECT ID
        , PERCENT_RANK() OVER (ORDER BY SIZE_OF_COLONY) AS R
    FROM ECOLI_DATA
) D
ORDER BY D.ID;

# SELECT D.ID
#     , CASE
#         WHEN D.R > D.MAX_ID*0.75 THEN 'CRITICAL'
#         WHEN D.R > D.MAX_ID*0.5 THEN 'HIGH'
#         WHEN D.R > D.MAX_ID*0.25 THEN 'MEDIUM'
#         ELSE 'LOW'
#       END AS COLONY_NAME
# FROM (
#     SELECT ID
#     	# 순위
#         , ROW_NUMBER() OVER (ORDER BY SIZE_OF_COLONY) AS R
#         # 총 데이터의 수
#         , MAX(ID) OVER() AS MAX_ID
#     FROM ECOLI_DATA
# ) D
# ORDER BY D.ID;