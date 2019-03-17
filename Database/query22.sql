select ename,sal,grade from emp,salgrade
where sal between losal and hisal
and grade=3;