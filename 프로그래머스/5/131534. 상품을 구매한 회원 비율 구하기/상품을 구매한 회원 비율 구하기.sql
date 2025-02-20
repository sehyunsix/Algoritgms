-- 코드를 입력하세요

with g as (
    select i.user_id, sales_date ,date_format(sales_date ,'%Y-%m') as months, COUNT(DISTINCT o.user_id) as purchased_users from 
    online_sale o right join user_info i
    on i.user_id = o.user_id
    where i.joined like'%2021%'
    group by months
    
)

, n as(
  select COUNT(DISTINCT user_id) as joined_total_users from user_info 
    where joined like'%2021%'
)

select  date_format(sales_date,'%Y') as YEAR ,date_format(sales_date ,'%c') as MONTH,
 PURCHASED_USERS, PUCHASED_RATIO
from (
select sales_date, purchased_users, ROUND((purchased_users/ (select * from n) ) ,1) as puchased_ratio from g  ) sub
where sales_date is not null
# order by year, month;




# SELECT YEAR(SALES_DATE) AS YEAR, 
#         MONTH(SALES_DATE) AS MONTH,
#         COUNT(DISTINCT U.USER_ID) AS PURCHASED_USERS,
#         ROUND(COUNT(DISTINCT U.USER_ID)/(SELECT COUNT(DISTINCT USER_ID) FROM USER_INFO WHERE YEAR(JOINED) = 2021), 1) AS PUCHASED_RATIO
#     FROM USER_INFO U JOIN ONLINE_SALE S 
#       ON U.USER_ID = S.USER_ID
#     WHERE YEAR(JOINED) = 2021
#     GROUP BY 1, 2
#     ORDER BY 1, 2