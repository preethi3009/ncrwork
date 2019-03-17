select job,min(sal) "min sal",max(sal) "max sal"
from emp
group by job;