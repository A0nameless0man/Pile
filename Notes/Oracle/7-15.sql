SELECT  empno 
       ,ename 
       ,sal 
       ,deptno
FROM emp
WHERE deptno IN ( SELECT deptno FROM emp WHERE empno > 7782)
ORDER BY empno desc;  