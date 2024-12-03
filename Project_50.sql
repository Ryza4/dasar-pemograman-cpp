create database perpustakaan_50;
use perpustakaan_50;

create table anggota (IDanggota int primary key, 
nama varchar(20), 
email varchar(20), 
telepon varchar(20), 
alamat varchar(20)
);

create table penulis (IDpenulis int primary key,
nama varchar(20)
);

create table buku (IDbuku int primary key,
IDpenulis int,foreign key(IDpenulis) references penulis(IDpenulis),
judul varchar(25),
penerbit varchar(25),
tahun_terbit varchar(25)
);

create table kategoriBUKU (IDbuku int,foreign key(IDbuku)references buku(IDbuku),
IDkategori int,foreign key(IDkategori)references kategori(IDkategori)
);

create table kategori (IDkategori int primary key,
NAMAkategori varchar(25)
);

create table peminjaman (IDpeminjaman int primary key,
IDanggota int, foreign key(IDanggota)references anggota(IDanggota),
IDbuku int, foreign key(IDbuku)references buku(IDbuku),
Tanggal_peminjaman date,
Tanggal_kembali date
);

insert into anggota values
(1,"Ryza","Ryza@gmail.com",082393335443,"Makassar"),
(2,"Rifky","Rifky@gmail.com",082393335443,"Makassar"),
(3,"Reza","Reza@gmail.com",082393335443,"Makassar");

insert into penulis values
(1,"yujina"),
(2,"soekarno"),
(3,"miyamoto");

insert into buku values
(1,1,"Data_scientist","Mihoyo","2023-11-10"),
(2,2,"PanduanBUILD","Mihoyo","2023-11-11"),
(3,3,"Projec_tmugen","Mihoyo","2023-11-12");

insert into peminjaman values
(1,1,1,"2024-12-03","2024-12-05"),
(2,2,2,"2024-11-03","2024-11-05"),
(3,3,3,"2024-10-03","2024-10-05");

insert into kategori values
(1,"programmer"),
(2,"Game"),
(3,"Game");

insert into kategoriBUKU values
(1,1),
(2,2),
(3,3);

