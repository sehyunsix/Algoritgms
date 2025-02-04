-- 코드를 입력하세요
# select * from user_info
SELECT count(*) as USERS 
from user_info
where age >= 20 and
age <=29
and joined like '__21-__-__'