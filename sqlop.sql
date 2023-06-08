--Below this line is the sql code for creating tables
--Here will be 5 tables


create table super_user(
sname varchar(30) not null primary key,
	realname varchar(30) not null,
	w_id varchar(30) not null,  --work id
	gender varchar(20) not null,
	pass_word varchar(40) not null,
    age int not null
); --create superuser

create table common_user(
sname varchar(30) not null primary key,
	realname varchar(30) not null,
	w_id varchar(30) not null, --work id
	gender varchar(20) not null,
	pass_word varchar(40) not null,
    age int not null
); --create commonuser

create table book(
    isbn varchar(60) not null primary key,
    bookno serial not null, --the number of this book
    title varchar(60) not null,
    author varchar(60) not null,
    publisher varchar(50) not null,
    price numeric(7,2) not null,
    stock int not null
); --create book


create table bookpurchase
(
    purchaseno serial not null primary key,
    isbn varchar(60) not null,
    title varchar(60) not null,
    author varchar(60) not null,
    publisher varchar(50) not null,
    quantity int not null,
    price numeric(7,2) not null,
    paidstatus int not null default 0   --0 is unpaid,1 is paid,2 is cancelled
); --create bookpurchase

create table bill
(
    billno serial not null primary key,
    isbn varchar(30) not null,
    catagory varchar(20) not null,
    amount numeric(7,2) not null,
    time_ timestamp with timezone(0) default current_timestamp(0)
) --create bill

