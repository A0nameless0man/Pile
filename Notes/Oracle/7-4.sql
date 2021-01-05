SELECT  empno 
       ,ename 
       ,sal 
       ,emp.deptno 
       ,dept.deptno 
       ,dname
FROM emp
INNER JOIN dept
ON emp.deptno = dept.deptno;