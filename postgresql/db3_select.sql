
create table users (
 id serial primary key,
 player varchar(255) not null,
 score real,
 team varchar(255)
);

\dt

insert into users (player, score, team) values
('Curry', 28.3, 'Warriors'),
('Harden', 30.2, 'Rocket'),
('Durant', 25.6, 'Warriors'),
('James', 27.8, 'Cavaliers'),
('Turtle', 31.3, 'Thunder'),
('White Side', 19.8, 'Heat');

\d users

