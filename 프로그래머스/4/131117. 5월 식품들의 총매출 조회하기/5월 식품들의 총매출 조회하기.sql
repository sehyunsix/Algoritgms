-- 코드를 입력하세요
SELECT p.product_id , p.product_name , SUM(o.amount)*p.price as total_sales
from food_product p join food_order o
on p.product_id = o.product_id
and o.produce_date like '2022-05-%'
group by p.product_id , p.product_name
order by total_sales desc, o.product_id 