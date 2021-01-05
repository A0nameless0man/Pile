DECLARE
    CURSOR
        crs_updateSal
    IS
        SELECT * FROM emp for update of sal;
        r_updateSal crs_updateSal%ROWTYPE;
        salAdd emp.sal%type;
        salinfo emp.sal%type;
BEGIN
    FOR r_updateSal in crs_updateSal LOOP
        salAdd := r_updateSal.sal*0.2;
        IF salAdd>300 THEN
            salinfo := r_updateSal.sal;
            dbms_output.PUT_LINE(r_updateSal.ename||' : Fail');
        ELSE
            salinfo := r_updateSal.sal + salAdd;
            dbms_output.PUT_LINE(r_updateSal.ename||' : Success');
        END IF;
        update emp set sal = salinfo where current of crs_updateSal;
    END LOOP;
END;
/