SELECT  empno 
       ,ename 
       ,sal 
       ,emp.deptno 
       ,dept.deptno 
       ,dname
FROM emp , dept
WHERE emp.deptno = dept.deptno;  