use sample;
select dname,ename from emp, dept
where emp.deptno=dept.deptno
order by dname;