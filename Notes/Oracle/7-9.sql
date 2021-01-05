SELECT  ename
       ,dname
FROM emp
FULL OUTER JOIN dept
ON emp.deptno = dept.deptno;