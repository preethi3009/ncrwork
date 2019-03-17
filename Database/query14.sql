select job,avg(sal) "avg sal",sum(sal+isnull(comm,0)) "remuneration"
from emp
group by job;