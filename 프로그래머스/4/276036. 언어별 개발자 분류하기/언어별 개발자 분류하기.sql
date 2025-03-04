
WITH GRADES AS (
    SELECT 
        CASE 
            WHEN (SELECT SUM(CODE) FROM SKILLCODES s WHERE s.CATEGORY = 'Front End'
                 GROUP By s.CATEGORY
                 ) & SKILL_CODE > 0 AND 
                 (SELECT s.CODE FROM SKILLCODES s WHERE s.NAME ='python') & SKILL_CODE >0 
            THEN 'A'
            WHEN (SELECT s.CODE FROM SKILLCODES s WHERE s.NAME = 'C#') & SKILL_CODE  > 0 
            THEN 'B'
            WHEN (SELECT SUM(CODE) FROM SKILLCODES s WHERE s.CATEGORY = 'Front End'
                 GROUP By s.CATEGORY
                 ) & SKILL_CODE > 0
            Then 'C'
        END AS GRADE,
        ID, 
        EMAIL 
    FROM DEVELOPERS
    order by grade ,id

)

SELECT * FROM GRADES
WHERE GRADE IS NOT NULL;
