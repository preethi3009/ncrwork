select ename,job,sal,grade,dname from emp,salgrade,dept
where emp.deptno=dept.deptno
and sal between losal and hisal
and job!='clerk'
order by sal desc;