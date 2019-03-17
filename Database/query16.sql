select dname,count(*) "no of employees" from dept,emp 
where dept.deptno=emp.deptno
group by dname
having count(*)>3 ;
