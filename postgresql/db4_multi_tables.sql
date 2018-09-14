create table users(
  id serial primary key,
  player varchar(255) not null,
  score real,
  team varchar(255)
);

insert into users (player, score, team) values
('Curry', 28.3, 'Warriors'),
('Harden',30.2, 'Rocket'),
('Durant',25.6, 'Warriors'),
('James', 27.8, 'Cavaliers'),
('Turtle',31.3, 'Thunder'),
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

