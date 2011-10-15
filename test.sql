SET GLOBAL sql_mode='STRICT_ALL_TABLES';

DROP TABLE IF EXISTS `world`.`SomeMessage`;
DROP TABLE IF EXISTS `world`.`epochs`;
DROP TABLE IF EXISTS `world`.`messageTypes`;
DROP TABLE IF EXISTS `world`.`messagesClassifier`;

CREATE TABLE `world`.`epochs` (
         id SERIAL,
         unixtime DOUBLE NOT NULL,
         PRIMARY KEY (`id`),
         INDEX `idx_unixtime` (`unixtime`)
       );

CREATE TABLE `world`.`messagesClassifier` (
         id SERIAL,
         className VARCHAR(100) NOT NULL,
         PRIMARY KEY (`id`)
       );
       
CREATE TABLE `world`.`messageTypes` (
         id SERIAL,
         messageName VARCHAR(100),
         tableName VARCHAR(100),
         idClassifier BIGINT UNSIGNED NOT NULL,
         PRIMARY KEY (`id`),
         INDEX `idx_fk_messagesClassifier` (`idClassifier`),
         CONSTRAINT `fk_messagesClassifier` FOREIGN KEY (`idClassifier`) 
            REFERENCES `messagesClassifier` (`id`)
       );

CREATE TABLE `world`.`SomeMessage` (
         id SERIAL,
         idEpoch BIGINT UNSIGNED NOT NULL,
         -- message data. 1000 - max length for dynamic-length array
         _a1 CHAR,
         _uint1 TINYINT UNSIGNED,
         _int1 TINYINT,
         _uint2 SMALLINT UNSIGNED,
         _int2 SMALLINT,
         _uint4 INT UNSIGNED,
         _int4 INT,
         _f4 FLOAT,
         _f8 DOUBLE,
         numericArray VARCHAR(1000),
         fixedLengthStrArray VARCHAR(5),
         unknownLengthStrArray VARCHAR(1000),
         
         PRIMARY KEY (`id`),
         INDEX `idx_fk_epochs` (`idEpoch`),
         CONSTRAINT `fk_epochs` FOREIGN KEY (`idEpoch`) 
            REFERENCES `epochs` (`id`)
       );
       
/*SHOW ENGINE INNODB STATUS; */