-- 코드를 입력하세요
SELECT animal_outs.animal_id ,animal_outs.name 
from animal_outs left join animal_ins
on animal_outs.animal_id = animal_ins.animal_id
where intake_condition is null
