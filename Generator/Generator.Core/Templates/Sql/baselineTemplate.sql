-- @{USE-DATABASE-HERE}@
SET GLOBAL sql_mode='STRICT_ALL_TABLES';

-- @{TABLE-DROP-HERE}@
DROP TABLE IF EXISTS `rawBinaryMessages`;
DROP TABLE IF EXISTS `epoch`;
DROP TABLE IF EXISTS `customTypeVariableSizeForDimension`;
DROP TABLE IF EXISTS `messageVariableSizeForDimension`;
DROP TABLE IF EXISTS `customTypeVariableMeta`;
DROP TABLE IF EXISTS `messageVariableMeta`;
DROP TABLE IF EXISTS `messageCode`;
DROP TABLE IF EXISTS `messageMeta`;
DROP TABLE IF EXISTS `customTypeMeta`;
DROP TABLE IF EXISTS `sizeSpecialValueClassifier`;
DROP TABLE IF EXISTS `messageValidationClassifier`;
DROP TABLE IF EXISTS `messageKindClassifier`;
DROP TABLE IF EXISTS `messageTypeClassifier`;

-- группировка сообщений по эпохам
CREATE TABLE `epoch` (
         id SERIAL,
         -- dt DATETIME NOT NULL,
         unixTime BIGINT UNSIGNED NOT NULL,
         PRIMARY KEY (`id`),
         INDEX `idx_unixTime` (`unixTime`)
       );

-- классификатор специальных значений поля `size` у сообщений и custom-типов
CREATE TABLE `sizeSpecialValueClassifier` (
         id INT NOT NULL,
         name VARCHAR(100) NOT NULL,
         PRIMARY KEY (`id`)
       );

-- классификатор способов валидации сообщений
CREATE TABLE `messageValidationClassifier` (
         id INT NOT NULL,
         name VARCHAR(100) NOT NULL,
         PRIMARY KEY (`id`)
       );

-- классификатор сообщений по происхождению (StandardMessage, StandardTextMessage, ...)
CREATE TABLE `messageKindClassifier` (
         id SERIAL,
         name VARCHAR(100) NOT NULL,
         PRIMARY KEY (`id`)
       );

-- классификатор сообщений по типу (General Purpose Messages, Almanacs and Ephemeris, ...)
CREATE TABLE `messageTypeClassifier` (
         id SERIAL,
         name VARCHAR(100) NOT NULL,
         PRIMARY KEY (`id`)
       );

-- мета-информация для custom-типов
CREATE TABLE `customTypeMeta` (
         id SERIAL,
         name VARCHAR(100) NOT NULL,
         size INT NOT NULL,
         tableName VARCHAR(100) NOT NULL,
         PRIMARY KEY (`id`),
         UNIQUE (`name`),
         UNIQUE (`tableName`)
       );

-- мета-информация для сообщений
CREATE TABLE `messageMeta` (
         id SERIAL,
         name VARCHAR(100) NOT NULL,
         title VARCHAR(100) NOT NULL,
         size INT NOT NULL,
         idValidation INT NOT NULL,
         idKind BIGINT UNSIGNED NOT NULL,
         idType BIGINT UNSIGNED NOT NULL,
         tableName VARCHAR(100) NOT NULL,
         PRIMARY KEY (`id`),
         UNIQUE (`tableName`),
         INDEX `idx_fk_messageMeta_idValidation` (`idValidation`),
         CONSTRAINT `fk_messageMeta_idValidation` FOREIGN KEY (`idValidation`) 
            REFERENCES `messageValidationClassifier` (`id`),
         INDEX `idx_fk_messageMeta_idKind` (`idKind`),
         CONSTRAINT `fk_messageMeta_idKind` FOREIGN KEY (`idKind`) 
            REFERENCES `messageKindClassifier` (`id`),
         INDEX `idx_fk_messageMeta_idType` (`idType`),
         CONSTRAINT `fk_messageMeta_idType` FOREIGN KEY (`idType`) 
            REFERENCES `messageTypeClassifier` (`id`)
       );

-- мета-информация о полях custom-типов
CREATE TABLE `customTypeVariableMeta` (
         id SERIAL,
         `name` VARCHAR(100) NOT NULL,
         `greisType` VARCHAR(100) NOT NULL,
         `requiredValue` VARCHAR(100) NOT NULL,
         `idCustomTypeMeta` BIGINT UNSIGNED NOT NULL,
         PRIMARY KEY (`id`),
         INDEX `idx_fk_customTypeVariableMeta_idCustomTypeMeta` (`idCustomTypeMeta`),
         CONSTRAINT `fk_customTypeVariableMeta_idCustomTypeMeta` FOREIGN KEY (`idCustomTypeMeta`) 
            REFERENCES `customTypeMeta` (`id`)
       );

-- мета-информация о полях сообщений
CREATE TABLE `messageVariableMeta` (
         id SERIAL,
         `name` VARCHAR(100) NOT NULL,
         `greisType` VARCHAR(100) NOT NULL,
         `requiredValue` VARCHAR(100) NOT NULL,
         `idMessageMeta` BIGINT UNSIGNED NOT NULL,
         PRIMARY KEY (`id`),
         INDEX `idx_fk_messageVariableMeta_idMessageMeta` (`idMessageMeta`),
         CONSTRAINT `fk_messageVariableMeta_idMessageMeta` FOREIGN KEY (`idMessageMeta`) 
            REFERENCES `messageMeta` (`id`)
       );

-- коды сообщений в соответствии с идентификаторами
CREATE TABLE `messageCode` (
         id SERIAL,
         code CHAR(2) NOT NULL,
         `idMessageMeta` BIGINT UNSIGNED NOT NULL,
         PRIMARY KEY (`id`),
         INDEX `idx_fk_messageCode_idMessageMeta` (`idMessageMeta`),
         CONSTRAINT `fk_messageCode_idMessageMeta` FOREIGN KEY (`idMessageMeta`) 
            REFERENCES `messageMeta` (`id`)
       );

-- размеры для размерностей переменных пользовательских типов
CREATE TABLE `customTypeVariableSizeForDimension` (
         id SERIAL,
         `idVariable` BIGINT UNSIGNED NOT NULL,
         `dimensionNumber` INT NOT NULL,
         `size` INT NOT NULL,
         PRIMARY KEY (`id`),
         INDEX `idx_fk_customTypeVariableSizeForDimension_idVariable` (`idVariable`),
         CONSTRAINT `fk_customTypeVariableSizeForDimension_idVariable` FOREIGN KEY (`idVariable`) 
            REFERENCES `customTypeVariableMeta` (`id`)
       );

-- размеры для размерностей переменных сообщений
CREATE TABLE `messageVariableSizeForDimension` (
         id SERIAL,
         `idVariable` BIGINT UNSIGNED NOT NULL,
         `dimensionNumber` INT NOT NULL,
         `size` INT NOT NULL,
         PRIMARY KEY (`id`),
         INDEX `idx_fk_messageVariableSizeForDimension_idVariable` (`idVariable`),
         CONSTRAINT `fk_messageVariableSizeForDimension_idVariable` FOREIGN KEY (`idVariable`) 
            REFERENCES `messageVariableMeta` (`id`)
       );

-- message 'FileId': [JP] File Identifier
CREATE TABLE `rawBinaryMessages` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    code CHAR(2) NOT NULL, 
    bodySize INT NOT NULL, 
    `data` BLOB, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_rawBinaryMessages_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_rawBinaryMessages_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_rawBinaryMessages_code` (`code`), 
    CONSTRAINT `fk_rawBinaryMessages_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`)
    );

-- @{TABLE-CREATION-HERE}@

-- нулевая эпоха-заглушка
-- INSERT INTO `epoch` (`unixtime`) VALUES (NULL);

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
