SELECT  empno 
       ,ename
       ,sal
       ,dept.deptno
       ,dname
FROM emp
CROSS JOIN dept
WHERE emp.deptno = 10 
AND dname = 'ACCOUNTING'; 