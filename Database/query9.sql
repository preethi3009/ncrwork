select ename,sal*12 "annual sal",comm from emp
where sal>isnull(comm,0)
order by sal desc,ename;