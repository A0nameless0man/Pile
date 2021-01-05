SELECT  distinct emp.deptno 
       ,dept.deptno
FROM emp
RIGHT OUTER JOIN dept
ON dept.deptno = emp.deptno;