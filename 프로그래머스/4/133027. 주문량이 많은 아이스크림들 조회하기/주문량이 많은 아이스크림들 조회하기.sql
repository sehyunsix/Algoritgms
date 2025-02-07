-- 코드를 입력하세요
SELECT first_half.flavor 
from first_half left join (
    select july.flavor ,sum(total_order) as july_order from july
    group by july.flavor
) as j
on first_half.flavor = j.flavor
order by first_half.total_order + july_order  desc
limit 0,3

