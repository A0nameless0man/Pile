DECLARE
    CURSOR
        crs_WorkDay
    IS
        select
            ename,
            hiredate,
            trunc(months_between(SYSDATE(),hiredate)) as years,
            trunc(mod(months_between(SYSDATE(),hiredate),12)) as months,
            trunc(mod(mod(SYSDATE()-hiredate,365),12)) as days
        from emp;
    r_WorkDay crs_WorkDay%ROWTYPE;
BEGIN
    for r_WorkDay in crs_WorkDay LOOP
        dbms_output.put_line(r_WorkDay.ename||r_WorkDay.years||r_WorkDay.months||r_WorkDay.days);
    END LOOP;
END;
/