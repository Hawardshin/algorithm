-- 코드를 입력하세요
# SELECT * FROM PRODUCT;

SELECT  FLOOR(PRICE/10000)*10000 PRICE_GROUP, COUNT(PRODUCT_ID) PRODUCTS FROM PRODUCT
GROUP BY FLOOR(PRICE/10000)
ORDER BY PRICE_GROUP
;