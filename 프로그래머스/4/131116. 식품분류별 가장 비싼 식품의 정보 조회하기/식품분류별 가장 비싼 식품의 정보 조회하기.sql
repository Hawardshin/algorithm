SELECT CATEGORY, PRICE MAX_PRICE, PRODUCT_NAME 
FROM FOOD_PRODUCT
WHERE (CATEGORY,PRICE) IN(
    SELECT CATEGORY, MAX(PRICE)
    FROM FOOD_PRODUCT
    GROUP BY CATEGORY
    HAVING CATEGORY IN ('국', '김치','식용유','과자')
)
ORDER BY MAX_PRICE DESC
;

# SELECT *
# FROM FOOD_PRODUCT
# WHERE CATEGORY = '과자'
# OR CATEGORY= '국'
# OR CATEGORY='김치'
# OR CATEGORY='식용유'
# GROUP BY CATEGORY
# ORDER BY PRICE DESC
# ;


# 식용유 : 8950, 국 : 2900, 김치 19000,과자 : 1950