#  select c.car_id, car_type , start_date ,end_date , datediff(end_date,start_date)+1 as duration
# from car_rental_company_car c join car_rental_company_rental_history h
# on c.car_id =h.car_id
# and h.end_date <= '2022-11-01'  -- 11월 1일 이후 대여 기록이 있는 경우
# and  c.car_type  in ('세단','SUV') 
with available_car  as (

select c.car_id , car_type, daily_fee 
from CAR_RENTAL_COMPANY_CAR c 
left join  CAR_RENTAL_COMPANY_RENTAL_HISTORY h
on c.car_id = h.car_id
and car_type in ('SUV' ,'세단')
group by c.car_id, car_type, daily_fee 
having max(end_date) < '2022-11-01'  

)

select car_id, a.car_type , round(daily_fee*30 *(1- discount_rate/100))  as fee from available_car a join CAR_RENTAL_COMPANY_DISCOUNT_PLAN p
on a.car_type = p.car_type
and p.duration_type ='30일 이상'
having fee < 2000000 and
fee  >= 500000
order by fee desc, a.car_type , car_id desc;


# select car_id 
# from CAR_RENTAL_COMPANY_RENTAL_HISTORY
# group by car_id
# having max(end_date) < '2022-11-01' or min(start_date) > '2022-11-30'