SELECT  dname 
       ,ename
FROM dept
LEFT JOIN emp
ON dept.deptno = emp.deptno;