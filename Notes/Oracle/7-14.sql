SELECT  ename
FROM emp
WHERE deptno = ( 
SELECT  deptno
FROM dept
WHERE dname = 'SALES') ; 