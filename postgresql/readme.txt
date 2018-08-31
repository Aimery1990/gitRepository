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
