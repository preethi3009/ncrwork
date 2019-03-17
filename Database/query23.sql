select ename,dname,loc from emp,dept
where emp.deptno=dept.deptno
and loc='dallas';