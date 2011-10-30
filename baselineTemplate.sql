-- @{USE-DATABASE-HERE}@
SET GLOBAL sql_mode='STRICT_ALL_TABLES';

-- @{TABLE-DROP-HERE}@
DROP TABLE IF EXISTS `exampleMessage`;
DROP TABLE IF EXISTS `epochs`;
DROP TABLE IF EXISTS `customTypeVariablesMeta`;
DROP TABLE IF EXISTS `messageVariablesMeta`;
DROP TABLE IF EXISTS `messageCodes`;
DROP TABLE IF EXISTS `messagesMeta`;
DROP TABLE IF EXISTS `customTypesMeta`;
DROP TABLE IF EXISTS `sizeSpecialValuesClassifier`;
DROP TABLE IF EXISTS `messageValidationsClassifier`;
DROP TABLE IF EXISTS `messageKindsClassifier`;
DROP TABLE IF EXISTS `messageTypesClassifier`;

-- группировка сообщений по эпохам
CREATE TABLE `epochs` (
         id SERIAL,
         unixtime DOUBLE NOT NULL,
         PRIMARY KEY (`id`),
         INDEX `idx_unixtime` (`unixtime`)
       );

-- классификатор специальных значений поля `size` у сообщений и custom-типов
CREATE TABLE `sizeSpecialValuesClassifier` (
         id INT NOT NULL,
         name VARCHAR(100) NOT NULL,
         PRIMARY KEY (`id`)
       );

-- классификатор способов валидации сообщений
CREATE TABLE `messageValidationsClassifier` (
         id SERIAL,
         name VARCHAR(100) NOT NULL,
         PRIMARY KEY (`id`)
       );

-- классификатор сообщений по происхождению (StandardMessage, StandardTextMessage, ...)
CREATE TABLE `messageKindsClassifier` (
         id SERIAL,
         name VARCHAR(100) NOT NULL,
         PRIMARY KEY (`id`)
       );

-- классификатор сообщений по типу (General Purpose Messages, Almanacs and Ephemeris, ...)
CREATE TABLE `messageTypesClassifier` (
         id SERIAL,
         name VARCHAR(100) NOT NULL,
         PRIMARY KEY (`id`)
       );

-- мета-информация для custom-типов
CREATE TABLE `customTypesMeta` (
         id SERIAL,
         name VARCHAR(100) NOT NULL,
         size INT NOT NULL,
         tableName VARCHAR(100) NOT NULL,
         PRIMARY KEY (`id`),
         UNIQUE (`name`),
         UNIQUE (`tableName`)
       );

-- мета-информация для сообщений
CREATE TABLE `messagesMeta` (
         id SERIAL,
         name VARCHAR(100) NOT NULL,
         title VARCHAR(100) NOT NULL,
         size INT NOT NULL,
         idValidation BIGINT UNSIGNED NOT NULL,
         idKind BIGINT UNSIGNED NOT NULL,
         idType BIGINT UNSIGNED NOT NULL,
         tableName VARCHAR(100) NOT NULL,
         PRIMARY KEY (`id`),
         UNIQUE (`tableName`),
         INDEX `idx_fk_messagesMeta_idValidation` (`idValidation`),
         CONSTRAINT `fk_messagesMeta_idValidation` FOREIGN KEY (`idValidation`) 
            REFERENCES `messageValidationsClassifier` (`id`),
         INDEX `idx_fk_messagesMeta_idKind` (`idKind`),
         CONSTRAINT `fk_messagesMeta_idKind` FOREIGN KEY (`idKind`) 
            REFERENCES `messageKindsClassifier` (`id`),
         INDEX `idx_fk_messagesMeta_idType` (`idType`),
         CONSTRAINT `fk_messagesMeta_idType` FOREIGN KEY (`idType`) 
            REFERENCES `messageTypesClassifier` (`id`)
       );

-- мета-информация о полях custom-типов
CREATE TABLE `customTypeVariablesMeta` (
         id SERIAL,
         `name` VARCHAR(100) NOT NULL,
         `type` VARCHAR(100) NOT NULL,
         `dimensions` TINYINT NOT NULL,
         `requiredValue` VARCHAR(100) NOT NULL,
         `idMessagesMeta` BIGINT UNSIGNED NOT NULL,
         PRIMARY KEY (`id`),
         INDEX `idx_fk_variablesMeta_idMessagesMeta` (`idMessagesMeta`),
         CONSTRAINT `fk_variablesMeta_idMessagesMeta` FOREIGN KEY (`idMessagesMeta`) 
            REFERENCES `messagesMeta` (`id`)
       );

-- мета-информация о полях сообщений
CREATE TABLE `messageVariablesMeta` (
         id SERIAL,
         `name` VARCHAR(100) NOT NULL,
         `type` VARCHAR(100) NOT NULL,
         `dimensions` TINYINT NOT NULL,
         `requiredValue` VARCHAR(100) NOT NULL,
         `idMessagesMeta` BIGINT UNSIGNED NOT NULL,
         PRIMARY KEY (`id`),
         INDEX `idx_fk_variablesMeta_idMessagesMeta` (`idMessagesMeta`),
         CONSTRAINT `fk_variablesMeta_idMessagesMeta` FOREIGN KEY (`idMessagesMeta`) 
            REFERENCES `messagesMeta` (`id`)
       );

-- коды сообщений в соответствии с идентификаторами
CREATE TABLE `messageCodes` (
         id SERIAL,
         code CHAR(2) NOT NULL,
         `idMessagesMeta` BIGINT UNSIGNED NOT NULL,
         PRIMARY KEY (`id`),
         UNIQUE (`code`), 
         INDEX `idx_fk_messageCodes_idMessagesMeta` (`idMessagesMeta`),
         CONSTRAINT `fk_messageCodes_idMessagesMeta` FOREIGN KEY (`idMessagesMeta`) 
            REFERENCES `messagesMeta` (`id`)
       );

-- @{TABLE-CREATION-HERE}@

-- @{INITIAL-FILLUP-HERE}@

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
       );

SHOW ENGINE INNODB STATUS; */
