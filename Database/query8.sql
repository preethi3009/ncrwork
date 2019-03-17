select ename,sal+isnull(comm,0) "remuneration"
from emp; 