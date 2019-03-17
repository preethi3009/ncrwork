select ename,round(sal+(15/100)*sal,0) "sal increased to 15%",
concat(ename,(concat(' works as ',job))) "description"
from emp;
