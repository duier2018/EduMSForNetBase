create table user_info
	(id			varchar(8), 
	 pswd		varchar(8), 
	 role		varchar(20),
	 date		varchar(20),
	 primary key (id)
	);

create table student_info
	(id		varchar(8), 
	 name	varchar(40), 
	 degree	varchar(40),
	 major	varchar(40),
	 primary key (id),
	 foreign key (id) references user_info(id)
	);
	
create table teacher_info
	(id			varchar(8), 
	 name		varchar(40), 
	 dept		varchar(40),
	 post		varchar(40),
	 primary key (id),
	 foreign key (id) references user_info(id)
	);

create table class_info
	(id			varchar(8), 
	 name		varchar(40), 
	 room		varchar(20),
	 count		varchar(4),
	 primary key (id)
	);
	
create table course_info
	(id			varchar(8), 
	 name		varchar(40), 
	 type		varchar(20),
	 lesson		varchar(4),
	 primary key (id)
	);


create table schedule_info
	(tea_id		varchar(8), 
	 class_id	varchar(8),
	 course_id	varchar(8), 
	 date	varchar(10),
	 primary key (tea_id, class_id, course_id),
	 foreign key (tea_id) references teacher_info(id),
	 foreign key (class_id) references class_info(id),
	 foreign key (course_id) references course_info(id)
	);
	
create table elect_info
	(stu_id		varchar(8), 
	 class_id	varchar(8),
	 course_id	varchar(8), 
	 grade	varchar(10),
	 primary key (stu_id, class_id, course_id),
	 foreign key (stu_id) references student_info(id),
	 foreign key (class_id) references class_info(id),
	 foreign key (course_id) references course_info(id)
	);

