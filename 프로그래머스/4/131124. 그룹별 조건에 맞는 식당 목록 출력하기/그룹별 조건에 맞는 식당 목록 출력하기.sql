-- 코드를 입력하세요
SELECT member_name ,review_text ,date_format(review_date,'%Y-%m-%d' ) as review_date from
member_profile left join rest_review
on member_profile.member_id = rest_review.member_id
where member_profile.member_id =  (
    select member_id from rest_review
    group by member_id
    order by count(*) desc
    limit 1 
)
order by review_date, review_text;
