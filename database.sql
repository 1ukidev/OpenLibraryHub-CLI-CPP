-- Script para criar o banco de dados e as tabelas necessárias.

CREATE DATABASE IF NOT EXISTS `openlibraryhub`;

USE `openlibraryhub`;

DROP TABLE IF EXISTS `livros`;

CREATE TABLE IF NOT EXISTS `livros` (
    `id` INT UNSIGNED AUTO_INCREMENT PRIMARY KEY NOT NULL,
    `titulo` VARCHAR(255) NOT NULL,
    `autor` VARCHAR(255) NOT NULL,
    `secao` VARCHAR(255) NOT NULL,
    `paginas` INT UNSIGNED NOT NULL,
    `ano` INT UNSIGNED NOT NULL,
    `estoque` INT UNSIGNED NOT NULL
);

DROP TABLE IF EXISTS `emprestimos`;
DROP TABLE IF EXISTS `estudantes`;
DROP TABLE IF EXISTS `turmas`;

CREATE TABLE IF NOT EXISTS `turmas` (
    `id` INT UNSIGNED AUTO_INCREMENT PRIMARY KEY NOT NULL,
    `nome` VARCHAR(255) NOT NULL
);

CREATE TABLE IF NOT EXISTS `estudantes` (
    `id` INT UNSIGNED AUTO_INCREMENT PRIMARY KEY NOT NULL,
    `nome` VARCHAR(255) NOT NULL,
    `turma_id` INT UNSIGNED NOT NULL,
    FOREIGN KEY (`turma_id`) REFERENCES `turmas`(`id`)
);

CREATE TABLE IF NOT EXISTS `emprestimos` (
    `id` INT UNSIGNED AUTO_INCREMENT PRIMARY KEY NOT NULL,
    `estudante_id` INT UNSIGNED NOT NULL,
    `livro_id` INT UNSIGNED NOT NULL,
    `data_emprestimo` DATE NOT NULL,
    `data_devolucao` DATE NOT NULL,
    FOREIGN KEY (`estudante_id`) REFERENCES `estudantes`(`id`),
    FOREIGN KEY (`livro_id`) REFERENCES `livros`(`id`)
);
