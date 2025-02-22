-- 코드를 작성해주세요
select id , email ,first_name, last_name  from developers

where (skill_code & (select  SUM(s.code ) from  skillcodes s
where s.category='Front End'
group by s.category ) ) > 0
order by id