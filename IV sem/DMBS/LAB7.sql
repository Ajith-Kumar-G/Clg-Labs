CREATE DATABASE BOOKDB;
USE BOOKDB;

CREATE TABLE PUBLISHER(
NAME VARCHAR(20) PRIMARY KEY,
PHONE VARCHAR(10),
ADDRESS VARCHAR(20)
);

CREATE TABLE BOOK(
BOOK_ID INT PRIMARY KEY,
TITLE VARCHAR(20),
PUB_YEAR VARCHAR(20),
PUBLISHER_NAME VARCHAR(20) REFERENCES PUBLISHER(NAME) ON DELETE CASCADE
);

CREATE TABLE BOOK_AUTHORS(
AUTHOR_NAME VARCHAR(20),
BOOK_ID INT REFERENCES BOOK(BOOK_ID) ON DELETE CASCADE,
PRIMARY KEY (BOOK_ID, AUTHOR_NAME)
);

CREATE TABLE LIBRARY_BRANCH(
BRANCH_ID INT PRIMARY KEY,
BRANCH_NAME VARCHAR(50),
ADDRESS VARCHAR(50)
);

CREATE TABLE BOOK_COPIES(
NO_OF_COPIES INT,
BOOK_ID INT REFERENCES BOOK (BOOK_ID) ON DELETE CASCADE,
BRANCH_ID INT REFERENCES LIBRARY_BRANCH (BRANCH_ID) ON DELETE CASCADE,
PRIMARY KEY (BOOK_ID, BRANCH_ID)
);

CREATE TABLE CARD(
CARD_NO INT PRIMARY KEY
);

CREATE TABLE BOOK_LENDING(
DATE_OUT DATE,
DUE_DATE DATE,
BOOK_ID INT REFERENCES BOOK (BOOK_ID) ON DELETE CASCADE,
BRANCH_ID INT REFERENCES LIBRARY_BRANCH (BRANCH_ID) ON DELETE CASCADE,
CARD_NO INT REFERENCES CARD (CARD_NO) ON DELETE CASCADE,
PRIMARY KEY (BOOK_ID, BRANCH_ID, CARD_NO)
);

INSERT INTO PUBLISHER VALUES 
('MCGRAW-HILL', 9989076587, 'BANGALORE'),
('PEARSON', 9889076565, 'NEWDELHI'),
('RANDOM HOUSE', 7455679345, 'HYDRABAD'),
('HACHETTE LIVRE', 8970862340, 'CHENAI'),
('GRUPO PLANETA', 7756120238, 'BANGALORE');


INSERT INTO BOOK VALUES
(1,'DBMS','JAN-2017', 'MCGRAW-HILL'),
(2,'ADBMS','JUN-2016', 'MCGRAW-HILL'),
(3,'CN','SEP-2016', 'PEARSON'),
(4,'CG','SEP-2015', 'GRUPO PLANETA'),
(5,'OS','MAY-2016', 'PEARSON');


INSERT INTO BOOK_AUTHORS VALUES
('NAVATHE', 1),
('NAVATHE', 2),
('TANENBAUM', 3),
('EDWARD ANGEL', 4),
('GALVIN', 5);


INSERT INTO LIBRARY_BRANCH VALUES
(10,'RR NAGAR','BANGALORE'),
(11,'RNSIT','BANGALORE'),
(12,'RAJAJI NAGAR', 'BANGALORE'),
(13,'NITTE','MANGALORE'),
(14,'MANIPAL','UDUPI'); 


INSERT INTO BOOK_COPIES VALUES
(10, 1, 10),
(5, 1, 11),
(2, 2, 12),
(5, 2, 13),
(7, 3, 14),
(1, 5, 10),
(3, 4, 11);


INSERT INTO CARD VALUES
(100),
(101),
(102),
(103),
(104);


INSERT INTO BOOK_LENDING VALUES
('2017-01-01','01-06-01', 1, 10, 101),
('2017-01-11','11-03-11', 3, 14, 101),
('2017-02-21','21-04-21', 2, 13, 101),
('2017-03-15','15-06-15', 4, 11, 101),
('2017-04-12','12-05-12', 1, 11, 104);

SELECT * FROM BOOK;
SELECT * FROM  BOOK_AUTHORS;
SELECT * FROM BOOK_LENDING;
SELECT * FROM  CARD;
SELECT * FROM  LIBRARY_BRANCH;
SELECT * FROM  PUBLISHER;

/*QUERY-1*/

SELECT B.BOOK_ID, B.TITLE, B.PUBLISHER_NAME, BA.AUTHOR_NAME, C.NO_OF_COPIES, L.BRANCH_ID
FROM BOOK B, BOOK_AUTHORS BA, BOOK_COPIES C, LIBRARY_BRANCH L
WHERE B.BOOK_ID=BA.BOOK_ID AND B.BOOK_ID=C.BOOK_ID AND L.BRANCH_ID=C.BRANCH_ID;

/*QUERY-2*/

SELECT CARD_NO FROM BOOK_LENDING
WHERE DATE_OUT BETWEEN '2017-01-01' AND '2017-06-01' GROUP BY CARD_NO HAVING COUNT(*)>3;

/*QUERY-3*/

DELETE FROM BOOK WHERE BOOK_ID=3;
SELECT * FROM BOOK;

/*QUERY-4*/

CREATE VIEW V_PUBLICATION AS
SELECT PUB_YEAR FROM BOOK;
SELECT * FROM V_PUBLICATION;

/*QUERY-5*/

CREATE VIEW ALL_BOOKS AS
SELECT B.BOOK_ID, B.TITLE, C.NO_OF_COPIES
FROM BOOK B, BOOK_COPIES C
WHERE B.BOOK_ID=C.BOOK_ID;

