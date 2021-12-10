# SQL (Structured Query Language)

Database: Systematic collection of data

> *Client sends request, query is executed, and results are displayed.*

## Data Types (in Oracle)
### Basic
1. Number: Numeric Data
2. Char: Alphanumeric Data (enclosed in single quotes 'Char')
3. Date: Date data type field (Default: DD-MON-YYYY)

## SQL Statements:
DDL is used to manipulate table structures, DML manipulates the data contained within table structures.

### DDL: Data Definition Language
1. Create
Creates the schema of tables

```
create table emp(eno number(3));
```
creates a table named emp with one column called eno with data type number and size 3

2. Alter
Changes the structure of table

3. Drop
Drops the structure of the table

> DESC table\_name
> Describes (returns names and data type of columns) a created table

### DML: Data Manipulation Language
1. Insert
Inserts data/record into the database

```
INSERT INTO table_name VALUES(value_of_column_1, value_of_column_2, ...);
```

e.g.
```
insert into emp values(1);
```
inserts the value 1 into emp table

2. Update
Makes modifications in the database

3. Delete
Deletes rows or data from table

4. Select
Retrieves or selects data from the database

```
select * from emp
```
returns everything in emp table

> "\_p%": any entry with p as 2nd letter

### DCL: Data Control Language
1. Commit
Makes changes in the database permanent

2. Rollback
Undo changes in the database

3. Grant
Assigns priviledge or right to user

4. Revoke
Removes priviledges or rights from user

## Basic Data Table Creation
1. Choose column names **(blank spaces not allowed)**
e.g. 1      ID\_Number    Name    Country    Debt    Date    (...)

2. Choose Data Type (Number, Character, Date in Oracle) for above columns
e.g. 1      Number        Char    Char       Number  Date    (...)

3. Decide on the (maximum) size of columns
e.g. 1        8            20      10          3      -      (...)

4. Create table:

```
CREATE TABLE table_name
(
Column_name1 data_type(size),
Column_name2 data_type(size),
...
);
```

e.g. 1:
```
CREATE TABLE debtors:
	(
	ID_Number Number(8),
	Name Char(20),
	Country Char(10),
	Debt Number(4),
	Date Date
	);
```

5. Insert values into the table:

```
INSERT INTO table_name VALUES(value_of_column_1, value_of_column_2, ...);
```

> *order of columns should be respected*
> *values for all columns need to be supplied*

e.g. 1:
```
insert into debtors values(1, 'Shiva', 'France', 100, '21-DEC-1856');
```

- To retrieve the data from a certain table:
```
SELECT column_names FROM table_name
[where <condition>]
[order by <expression>]
```

```
select * from debtors
```
brings up all the entries in debtors

e.g. 1:
```
SELECT ID_Number,Name,Debt FROM debtors
```

or to select only those that have Country as France:
```
select * from debtors where Country='France';
```

> *Entries are case sensitive, i.e. France is not the same as FRANCE or france* 

or to rearrange according to a specific column, use order:
```
select * from debtors order by Debt;
```

or as desc keyword for arranging in descending order:
```
select * from debtors order by Debt desc;
```

- Existing data can be changed using UPDATE
```
UPDATE table_name SET column_1 = new_value [, column_2 = new_value, ...]
[where <condition>]
```

Here, the where keyword can be used to change one data depending on another's value:
```
update debtors set Debt = 50 where ID_Number = 1;
```
changes the Debt for the row with ID\_Number 1.

- Deletion of data
```
DELETE [FROM] table_name [where <condition>]
```

For example, to delete all debtors from Spain
```
delete from debtors where Country='Spain'
```

> "delete debtors" only deletes data/entries contained within debtors and not the table structure itself

## PL/SQL

```
begin
dbms_output.put_line('Welcome to PL/SQL');
end;
```

# Program-specific notes
## Oracle LiveSQL
> *In an Oracle LiveSQL Worksheet, highlight the line/block you want to run and then click RUN*


