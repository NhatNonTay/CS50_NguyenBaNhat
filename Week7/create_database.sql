-- Tạo cơ sở dữ liệu
CREATE DATABASE EntertainmentDB;
GO

-- Sử dụng cơ sở dữ liệu vừa tạo
USE EntertainmentDB;
GO

-- Tạo bảng Songs
CREATE TABLE Songs
(
    SongID INT IDENTITY(1,1) NOT NULL PRIMARY KEY,
    Title NVARCHAR(100) NOT NULL,
    Artist NVARCHAR(100) NOT NULL,
    Album NVARCHAR(100),
    ReleaseYear INT
);
GO

-- Tạo bảng Movies
CREATE TABLE Movies
(
    MovieID INT IDENTITY(1,1) NOT NULL PRIMARY KEY,
    Title NVARCHAR(100) NOT NULL,
    Director NVARCHAR(100) NOT NULL,
    Genre NVARCHAR(50),
    ReleaseYear INT
);
GO
