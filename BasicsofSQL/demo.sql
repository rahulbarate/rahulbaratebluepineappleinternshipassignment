.header on
.width 0 20 25 15
.mode column

PRAGMA foreign_keys = ON;

-- creating dep table and adding values
.print
.print Creating Department table
.print

create table Department
(depId int primary key,depName varchar(30) not null,totalSubject int not null);

.print
.print Inserting Values in Department
.print

insert into Department values
(1,"Computer Science",10),
(2,"Biology",20),
(3,"chemistry",15),
(4,"physics",20),
(5,"mathematics",10)
;


.print
.print Creating Teachers table
.print

-- creating teachers table and adding values
create table Teachers
(tId int primary key,tName varchar(50) not null,subject varchar(30)not null,
address varchar(30) not null,salary int not null,depId int, FOREIGN KEY(depId) REFERENCES Department(depId));

.print
.print Inserting Values in Teachers
.print


insert into Teachers values(101,"aparana mam","data mining","pune",40,1);
insert into Teachers values(102,"anjali mam","python","pune",50,1);
insert into Teachers values(103,"ashok sir","microbiology","nashik",60,2);
insert into Teachers values(104,"aarti mam","biotech","nashik",50,2);
insert into Teachers values(105,"nandan sir","organic chemistry","nagar",30,3);
insert into Teachers values(106,"pandit madam","inorganic chemistry","mumbai",40,3);
insert into Teachers values(107,"narendra sir","quantum mechanics","satara",20,4);
insert into Teachers values(108,"uma madam","classical mechanics","aurangabad",20,4);
insert into Teachers values(109,"imran sir","statistical mechanics","dhule",20,4);
insert into Teachers values(110,"bhupesh sir","statistical mechanics","nagar",35,4);
insert into Teachers values(111,"nilima mam","microbiology","dhule",20,2);
-- Example of select
.print
.print Example of SELECT clause :
.print
select depId,depName from Department;
.print
.print
select * from Teachers;

-- Example of where 
.print
.print Example of WHERE clause:
.print

select * from Teachers where depId==4;

-- Example of AND,OR and NOT
.print
.print Example of AND,OR and NOT clause:
.print

select * from Teachers where (depId==4 OR depId==3) AND NOT(address=="aurangabad" OR address=="mumbai");

-- Example of UPDATE clause
.print
.print Example of UPDATE clause:
.print
.print Before update :
select tName,address from Teachers;

update Teachers SET address="ahamadnagar" where address=="nagar";

.print
.print After update :
select tName,address from Teachers;

-- Example on delete clause
.print
.print Example of DELETE clause:
.print
.print Before delete :
select tId, tName from Teachers;

delete from teachers where tId == 111;
.print
.print After delete :
select tId, tName from Teachers;

.print
.print Example of COUNT function:
.print

select count(tName) AS Teachers_From_Nashik from Teachers where address=="nashik";

.print
.print Example of AVG function:
.print

select AVG(salary) as Average_Salary_In_Pune from Teachers where address=="pune";

.print
.print Example of SUM function:
.print

select SUM(salary) as Total_Salary from Teachers where address =="nashik";

.print
.print Example of INNER Join:
.print

select Teachers.tId, Teachers.tName,  Teachers.subject, Department.depId, Department.depName
from Department
inner join Teachers on Department.depId == Teachers.depId;

.print
.print Example of left Join:
.print

select Department.depId,Department.depName, Teachers.tName
from Department
left join Teachers on Department.depId == Teachers.depId;

.print
.print Example of Group by clause:
.print

select depId,count(tid) as count_of_teachers from Teachers Group by depId

