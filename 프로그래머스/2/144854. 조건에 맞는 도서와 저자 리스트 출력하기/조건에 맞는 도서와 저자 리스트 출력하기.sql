-- 코드를 입력하세요
SELECT book_id,  author_name ,date_format(book.published_date ,'%Y-%m-%d') as published_date
from book join author 
on book.author_id = author.author_id
where category ='경제'
order by published_date