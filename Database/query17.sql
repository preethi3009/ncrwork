SELECT case when count(distinct empno)= count(empno)
THEN 'column values are unique' ELSE 'column values are NOT unique' END
FROM emp;