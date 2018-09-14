create table posts(
  id serial primary key,
  title varchar(255) not null,
  content text check(length(content)>8),
  is_draft boolean default FALSE,
  create_date timestamp default 'now'
);
