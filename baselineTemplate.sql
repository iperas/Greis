-- USE `world`;
-- @{USE-DATABASE-HERE}@
SET GLOBAL sql_mode='STRICT_ALL_TABLES';

DROP TABLE IF EXISTS `exampleMessage`;
DROP TABLE IF EXISTS `epochs`;
DROP TABLE IF EXISTS `messagesMeta`;
DROP TABLE IF EXISTS `messageKindsClassifier`;
DROP TABLE IF EXISTS `messageTypesClassifier`;
-- @{TABLE-DROP-HERE}@

-- группировка сообщений по эпохам
CREATE TABLE `epochs` (
         id SERIAL,
         unixtime DOUBLE NOT NULL,
         PRIMARY KEY (`id`),
         INDEX `idx_unixtime` (`unixtime`)
       );

-- классификатор сообщений по происхождению (StandardMessage, StandardTextMessage, ...)
CREATE TABLE `messageKindsClassifier` (
         id SERIAL,
         messageKind VARCHAR(100) NOT NULL,
         PRIMARY KEY (`id`)
       );

-- классификатор сообщений по типу (General Purpose Messages, Almanacs and Ephemeris, ...)
CREATE TABLE `messageTypesClassifier` (
         id SERIAL,
         messageType VARCHAR(100) NOT NULL,
         PRIMARY KEY (`id`)
       );

-- мета-информация для сообщений
CREATE TABLE `messagesMeta` (
         id SERIAL,
         name VARCHAR(100),
         title VARCHAR(100),
         idKind BIGINT UNSIGNED NOT NULL,
         idType BIGINT UNSIGNED NOT NULL,
         tableName VARCHAR(100),
         PRIMARY KEY (`id`),
         INDEX `idx_fk_messageKindsClassifier` (`idKind`),
         CONSTRAINT `fk_messageKindsClassifier` FOREIGN KEY (`idKind`) 
            REFERENCES `messageKindsClassifier` (`id`),
         INDEX `idx_fk_messageTypesClassifier` (`idType`),
         CONSTRAINT `fk_messageTypesClassifier` FOREIGN KEY (`idType`) 
            REFERENCES `messageTypesClassifier` (`id`)
       );

-- @{TABLE-CREATION-HERE}@

/*CREATE TABLE `exampleMessage` (
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
       );*/

-- SHOW ENGINE INNODB STATUS; 

-- @{INITIAL-FILLUP-HERE}@
