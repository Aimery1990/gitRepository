/*this is the init readme info*/

sudo apt-get install postgresql
psql --version


sudo su postgres
psql -l
createdb aimery
psql -l
psql aimery

help
       \h for help with SQL commands
       \? for help with psql commands
       \q to quit

select now();
select version();


dropdb aimery
psql -l

///////////////////////////////////////////////
sudo su postgres
psql -l
createdb aimery
psql aimery

create table posts (titile varchar(255), content text);
\dt
\d post
alter table posts rename to aimposts;
\dt
drop table aimposts;
\q

vim db.sql

...
create table posts (title varchar(255), content text);
...

psql aimery

\i db.sql
\dt
drop table posts;

\q
dropdb aimery
psql -l


/////////////////////////////////////////////////data type
//numeric
integer(int)
real
serial

//character
char //very short char such gender. more bytes will be zerolized if only part of bytes updated
varchar
text

//date time
date
time
timestamp

//others
array
ip_address(inet)
JSON
XML

/////////////////////////////////////////////////
//table constraint condition

create table posts(
  id serial primary key,
  title varchar(255) not null,
  content test check(length(content)>8),
  is_draft boolean default FALSE,
  create_date timestamp default 'now'
);

/*
not null, unique, check default primary key(not null, unique)
*/


////////////////////////////////////////////////
//insert data

insert into posts (title, content) values ('', '');         /* '' is not null, it's values not value*/
insert into posts (title, content) values (NULL, '');
insert into posts (title, content) values ('title1', 'content11');
select * from posts;
insert into posts (title, content) values ('title2', 'content22');
insert into posts (title, content) values ('title3', 'content33');
select * from posts;

////////////////////////////////////////////////
//select data

create table users (
  id serial primary key,
  player varchar(255) not null,
  score real,
  team varchar(255)
);

insert into users (player, score, team) values
('Curry', 28.3, 'Warriors'),
('Harden' 30.2, 'Rocket'),
('Durant',25.6, 'Warriors'),
('James', 27.8, 'Cavaliers'),
('Turtle',31,3, 'Thunder'),
('White Side', 19.8, 'Heat');

\dt
\d users
select * from users;
\x
select * from users;
\x

select player, score from users;

//////////////////////////////////////////////////
//where

select * from users;
select * from users where score > 20;
select * from users where score > 20 and score < 30;
select * from users where team = 'Warriors';
select * from users where team != 'Warriors';
select * from users where player like '%r%';
select * from users where player like 'Curr_';


//////////////////////////////////////////////////
//order by
//limit
//offset

select * from users order by score asc;
select * from users order by score desc;
select * from users order by team;
select * from users order by team, score;
select * from users order by team, score desc;
select * from users order by team desc, score desc;
select * from users order by score desc limit 3;
select * from users order by score desc limit 3 offset 1;
select * from users order by score desc limit 3 offset 2;
select * from users order by score desc limit 3 offset 3;

//////////////////////////////////////////////////
//distinct
//sum
//max/min
//group by/having

select distinct team from users;
select sum(score) from users;
select max(score) from users;
select min(score) from users;
select * from users where score = (select max(score) from users);
select * from users where score = (select min(score) from users);
select team, max(score) from users group by team;
select team, max(score) from users group by team having max(score) >= 25;  //having is for group by!!!!!
select team, max(score) from users group by team having max(score) >= 25 order by max(score);


/////////////////////////////////////////////////
//length
//concat
//alias
//substring
//random

select players, length(player) from users;
select players, concat(players, '/', team) from users;
select players, concat(players, '/', team) as "player info" from users;
select substring(team, 1, 1) as "teams' cap" from users;
select concat('we' substring(team, 1, 1)) as "teams' cap" from users;
select random();
select * from users order by random();
select * from users order by random() limit 1;


//////////////////////////////////////////////////
//update [table] set [field=newvalue, ...] where ...;
//delete from [table] where ...;

update users set score = 29.1 where player = 'James';
update users set score = score+1 where team = 'Warriors';
update users set score = score+100 where team IN ('Warriors', 'Cavaliers'); //2 teams member add 100 scores
delete from users where score > 30;


//////////////////////////////////////////////////
//alter table [tablename] ...
//create index ...
//drop index ...

\d users
alter table users add fullname varchar(255);
\d users
alter table users drop fullname;
\d users
alter table users rename player to nba_player;
\d users
alter table users alter nba_player type varchar(100);
\d users
create index nba_player_index on users(nba_player);
\d users
drop index nba_player_index;
\d users

//////////////////////////////////////////////////


//drop old tables

create table users(
  id serial primary key,
  player varchar(255) not null,
  score real,
  team varchar(255)
);

insert into users (players, score, team) values
('Curry', 28.3, 'Warriors'),
('Harden' 30.2, 'Rocket'),
('Durant',25.6, 'Warriors'),
('James', 27.8, 'Cavaliers'),
('Turtle',31,3, 'Thunder'),
('White Side', 19.8, 'Heat');

create table twitters(
  id serial primary key,
  user_id integer,
  content varchar(255) not null
);


insert into twitters (user_id, content) values
(1, 'Today is another big win, Claire did a great job!'),
(2, 'I got 60 scores tonight, lol'),
(3, 'We are not afraid of winning. Who lacks who feels awkward'),
(4, 'I may go to the west next year.'),
(5, 'I have won double 20+, why it failed again?'),
(6, 'Heard of a big fish will come next year, who?');


select users.player, twitters.content from users, twitters where users.id = twitters.id;
select u.player, t.content from users as u, twitters as t where u.id = t.id;
select u.player, t.content from users as u, twitters as t where u.id = t.id and u.id = 1;

//////////////////////////////////////////////////
//view
//create view ...
//drop view ...

select u.player, t.content from users as u, twitters as t where u.id = t.id and u.id = 1;
create view curry_twitters as select u.player, t.content from users as u, twitters as t where u.id = t.id and u.id = 1;
drop view curry_twitters;

//////////////////////////////////////////////////
//database transaction
//begin
//commit
//rollback

select * from users;
begin;
update users set score = 50 where player = 'Curry';
update users set score = 60 where player = 'Harden';
commit;
select * from users;


begin;
update users set score = 0 where player = 'Curry';
update users set score = 0 where player = 'Harden';
rollback;
select * from users;
