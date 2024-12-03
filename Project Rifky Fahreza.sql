create database perpustakaan_50;
use perpustakaan_50;

-- DDL (Data Definition Language)
create table anggota (IDanggota int primary key, 
nama varchar(20), 
email varchar(20), 
telepon varchar(20), 
alamat varchar(20)
);
desc anggota;

create table penulis (IDpenulis int primary key,
nama varchar(20)
);
desc penulis;

create table buku (IDbuku int primary key,
IDpenulis int,foreign key(IDpenulis) references penulis(IDpenulis),
judul varchar(25),
penerbit varchar(25),
tahun_terbit varchar(25)
);
desc buku;

create table kategoriBUKU (IDbuku int,foreign key(IDbuku)references buku(IDbuku),
IDkategori int,foreign key(IDkategori)references kategori(IDkategori)
);
desc kategoriBUKU;

create table kategori (IDkategori int primary key,
NAMAkategori varchar(25)
);
desc kategori;

create table peminjaman (IDpeminjaman int primary key,
IDanggota int, foreign key(IDanggota)references anggota(IDanggota),
IDbuku int, foreign key(IDbuku)references buku(IDbuku),
Tanggal_peminjaman date,
Tanggal_kembali date
);
desc peminjaman;

-- DML (Data Manipulation Language) 
insert into anggota values
(1,"Ryza","Ryza@gmail.com",082393335443,"Makassar"),
(2,"Rifky","Rifky@gmail.com",082393335443,"Makassar"),
(3,"Reza","Reza@gmail.com",082393335443,"Makassar"),
(4,"ichwal","ichwal@gmail.com",082393335443,"luwu"),
(5,"irgi","irgi@gmail.com",082393335443,"Makassar"),
(6,"ikhlas","ikhlas@gmail.com",082393335443,"Makassar"),
(7,"amri","amri@gmail.com",082393335443,"Makassar"),
(8,"malik","malik@gmail.com",082393335443,"Makassar"),
(9,"alif","alif@gmail.com",082393335443,"Makassar"),
(10,"sirat","sirat@gmail.com",082393335443,"Makassar");
select *from anggota;

insert into penulis values
(1,"yujina"),
(2,"soekarno"),
(3,"miyamoto"),
(4,"yamato"),
(5,"yamamoto"),
(6,"indra"),
(7,"george"),
(8,"wang lin"),
(9,"xiangli yao"),
(10,"yun jin");
select *from penulis;

insert into buku values
(1,1,"Data_scientist","Mihoyo","2023-11-10"),
(2,2,"PanduanBUILD","Mihoyo","2023-11-11"),
(3,3,"Projec_tmugen","Mihoyo","2023-11-12"),
(4,4,"Data_chef","Mihoyo","2023-11-13"),
(5,5,"data_analyst","Mihoyo","2023-11-14"),
(6,6,"ZZZ","Mihoyo","2023-11-15"),
(7,7,"HI3","Mihoyo","2023-11-16"),
(8,8,"Honkai star rail","Mihoyo","2023-11-17"),
(9,9,"machine learning","Mihoyo","2023-11-18"),
(10,10,"management","Mihoyo","2023-11-19");
select *from buku;


insert into peminjaman values
(1,1,1,"2024-12-03","2024-12-05"),
(2,2,2,"2024-11-03","2024-11-05"),
(3,3,3,"2024-10-03","2024-10-05"),
(4,4,4,"2024-12-04","2024-12-05"),
(5,5,5,"2024-11-04","2024-11-05"),
(6,6,6,"2024-10-04","2024-10-05"),
(7,7,7,"2024-12-05","2024-12-05"),
(8,8,8,"2024-11-05","2024-11-05"),
(9,9,9,"2024-10-05","2024-10-05"),
(10,10,10,"2024-10-06","2024-10-05");
select *from peminjaman;

insert into kategori values
(1,"programmer"),
(2,"Game"),
(3,"Game"),
(4,"Data"),
(5,"Tools"),
(6,"Game2"),
(7,"AI"),
(8,"IOT"),
(9,"money"),
(10,"project");
select *from kategori;


insert into kategoriBUKU values
(1,1),
(2,2),
(3,3),
(4,4),
(5,5),
(6,6),
(7,7),
(8,8),
(9,9),
(10,10);
select *from kategoriBUKU;

-- JOIN
-- view
-- procedure
-- function
-- trigger