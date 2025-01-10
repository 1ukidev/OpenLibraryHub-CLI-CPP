-- Script para criar o banco de dados e as tabelas necessárias.

CREATE DATABASE IF NOT EXISTS `openlibraryhub`;

USE `openlibraryhub`;

DROP TABLE IF EXISTS `livros`;

CREATE TABLE IF NOT EXISTS `livros` (
    `id` BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY NOT NULL,
    `titulo` VARCHAR(255) NOT NULL,
    `autor` VARCHAR(255) NOT NULL,
    `secao` VARCHAR(255) NOT NULL,
    `paginas` INT UNSIGNED NOT NULL,
    `ano` INT UNSIGNED NOT NULL,
    `estoque` INT UNSIGNED NOT NULL
);

DROP TABLE IF EXISTS `emprestimos`;
DROP TABLE IF EXISTS `alunos`;
DROP TABLE IF EXISTS `turmas`;

CREATE TABLE IF NOT EXISTS `turmas` (
    `id` BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY NOT NULL,
    `nome` VARCHAR(255) NOT NULL
);

CREATE TABLE IF NOT EXISTS `alunos` (
    `id` BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY NOT NULL,
    `nome` VARCHAR(255) NOT NULL,
    `turma` INT UNSIGNED NOT NULL,
    FOREIGN KEY (`turma`) REFERENCES `turmas`(`id`)
);

CREATE TABLE IF NOT EXISTS `emprestimos` (
    `id` BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY NOT NULL,
    `aluno` INT UNSIGNED NOT NULL,
    `livro` INT UNSIGNED NOT NULL,
    `data_emprestimo` DATE NOT NULL,
    `data_devolucao` DATE NOT NULL,
    FOREIGN KEY (`aluno`) REFERENCES `alunos`(`id`),
    FOREIGN KEY (`livro`) REFERENCES `livros`(`id`)
);
