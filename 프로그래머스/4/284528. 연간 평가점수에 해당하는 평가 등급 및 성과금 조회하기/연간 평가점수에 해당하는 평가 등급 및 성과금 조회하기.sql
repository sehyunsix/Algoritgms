select  E.EMP_NO ,
E.EMP_NAME,
CASE WHEN AVG(G.SCORE) >= 96 THEN 'S'
WHEN AVG(G.SCORE) >= 90 THEN 'A'
WHEN AVG(G.SCORE) >= 80 THEN 'B'
ELSE 'C'
END as GRADE,
CASE WHEN AVG(G.SCORE) >= 96 THEN 0.2*E.SAL
WHEN AVG(G.SCORE) >= 90 THEN 0.15*E.SAL
WHEN AVG(G.SCORE) >= 80 THEN  0.10*E.SAL
ELSE 0
END as BONUS

from
HR_EMPLOYEES E join HR_GRADE G
on  E.EMP_NO = G.EMP_NO
group by E.EMP_NO
order by E.EMP_NO;
