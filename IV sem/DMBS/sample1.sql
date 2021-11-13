create DATABASE EMPLOYEE;
USE EMPLOYEE;

CREATE TABLE EMP(
EMPNO INT PRIMARY KEY,
ENAME VARCHAR(20),
JOB VARCHAR(20),
MGR INT,
SAL INT,DEPTNO INT
);

SELECT * FROM EMP;

SELECT E.ENAME, E.SAL
FROM EMP E
WHERE SAL=(SELECT MAX(P.SAL) FROM EMP P
WHERE P.SAL NOT IN (SELECT
MAX(Q.SAL)
FROM EMP Q));