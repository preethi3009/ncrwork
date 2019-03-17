select ename,loc,dname from emp,dept
where dept.deptno=emp.deptno
and emp.sal>1500;