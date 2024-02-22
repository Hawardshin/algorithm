-- 코드를 입력하세요
# SELECT * FROM ICECREAM_INFO ;
# SELECT * FROM FIRST_HALF;
# SELECT * FROM ICECREAM_INFO, FIRST_HALF;
SELECT B.FLAVOR
FROM FIRST_HALF A, ICECREAM_INFO B
WHERE A.FLAVOR = B.FLAVOR
AND A.TOTAL_ORDER > 3000
AND B.INGREDIENT_TYPE = 'fruit_based'
ORDER BY A.TOTAL_ORDER DESC;


# FLAVOR	SUM(A.TOTAL_ORDER)
# strawberry	9400
# peach	9400