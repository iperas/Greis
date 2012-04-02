USE `world`;
SET GLOBAL sql_mode='STRICT_ALL_TABLES';

DROP TABLE IF EXISTS `msg_FileId`;
DROP TABLE IF EXISTS `msg_MsgFmt`;
DROP TABLE IF EXISTS `msg_RcvTime`;
DROP TABLE IF EXISTS `msg_EpochTime`;
DROP TABLE IF EXISTS `msg_RcvDate`;
DROP TABLE IF EXISTS `msg_RcvTimeOffset`;
DROP TABLE IF EXISTS `msg_RcvTimeOffsetDot`;
DROP TABLE IF EXISTS `msg_RcvTimeAccuracy`;
DROP TABLE IF EXISTS `msg_GPSTime`;
DROP TABLE IF EXISTS `msg_RcvGPSTimeOffset`;
DROP TABLE IF EXISTS `msg_GLOTime`;
DROP TABLE IF EXISTS `msg_RcvGLOTimeOffset`;
DROP TABLE IF EXISTS `msg_RcvGALTimeOffset`;
DROP TABLE IF EXISTS `msg_RcvWAASTimeOffset`;
DROP TABLE IF EXISTS `msg_GpsUtcParam`;
DROP TABLE IF EXISTS `msg_WaasUtcParam`;
DROP TABLE IF EXISTS `msg_GalUtcGpsParam`;
DROP TABLE IF EXISTS `msg_GloUtcGpsParam`;
DROP TABLE IF EXISTS `msg_SolutionTime`;
DROP TABLE IF EXISTS `msg_Pos`;
DROP TABLE IF EXISTS `msg_Vel`;
DROP TABLE IF EXISTS `msg_PosVel`;
DROP TABLE IF EXISTS `msg_GeoPos`;
DROP TABLE IF EXISTS `msg_GeoVel`;
DROP TABLE IF EXISTS `msg_Rms`;
DROP TABLE IF EXISTS `msg_Dops`;
DROP TABLE IF EXISTS `msg_PosCov`;
DROP TABLE IF EXISTS `msg_VelCov`;
DROP TABLE IF EXISTS `msg_BaseLine`;
DROP TABLE IF EXISTS `msg_PosStat`;
DROP TABLE IF EXISTS `msg_PosCompTime`;
DROP TABLE IF EXISTS `msg_SatIndex`;
DROP TABLE IF EXISTS `msg_AntName`;
DROP TABLE IF EXISTS `msg_SatNumbers`;
DROP TABLE IF EXISTS `msg_SatElevation`;
DROP TABLE IF EXISTS `msg_SatAzimuth`;
DROP TABLE IF EXISTS `msg_PR`;
DROP TABLE IF EXISTS `msg_SPR`;
DROP TABLE IF EXISTS `msg_RPR`;
DROP TABLE IF EXISTS `msg_SRPR`;
DROP TABLE IF EXISTS `msg_SC`;
DROP TABLE IF EXISTS `msg_SS`;
DROP TABLE IF EXISTS `msg_CP`;
DROP TABLE IF EXISTS `msg_SCP`;
DROP TABLE IF EXISTS `msg_RCP_RC0`;
DROP TABLE IF EXISTS `msg_RCP_rc1`;
DROP TABLE IF EXISTS `msg_DP`;
DROP TABLE IF EXISTS `msg_SRDP`;
DROP TABLE IF EXISTS `msg_CNR`;
DROP TABLE IF EXISTS `msg_CNR_4`;
DROP TABLE IF EXISTS `msg_Flags`;
DROP TABLE IF EXISTS `msg_TrackingTimeCA`;
DROP TABLE IF EXISTS `msg_NavStatus`;
DROP TABLE IF EXISTS `msg_IonoDelay`;
DROP TABLE IF EXISTS `msg_GPSAlm0`;
DROP TABLE IF EXISTS `msg_GALAlm`;
DROP TABLE IF EXISTS `msg_GLOAlmanac`;
DROP TABLE IF EXISTS `msg_WAASAlmanac`;
DROP TABLE IF EXISTS `msg_GPSEphemeris0`;
DROP TABLE IF EXISTS `msg_GLOEphemeris`;
DROP TABLE IF EXISTS `msg_WAASEhemeris`;
DROP TABLE IF EXISTS `msg_GALEphemeris`;
DROP TABLE IF EXISTS `msg_GpsNavData`;
DROP TABLE IF EXISTS `msg_GloNavData`;
DROP TABLE IF EXISTS `msg_WAASRawMessage`;
DROP TABLE IF EXISTS `msg_GALRawMessage`;
DROP TABLE IF EXISTS `msg_GloPhaseDelay`;
DROP TABLE IF EXISTS `msg_RotationMatrix`;
DROP TABLE IF EXISTS `msg_RotationMatrixAndVectors`;
DROP TABLE IF EXISTS `msg_RotationAngles`;
DROP TABLE IF EXISTS `msg_AngularVelocity`;
DROP TABLE IF EXISTS `msg_InertialMeasurements`;
DROP TABLE IF EXISTS `msg_ExtEvent`;
DROP TABLE IF EXISTS `msg_PPSOffset`;
DROP TABLE IF EXISTS `msg_RcvTimeOffsAtPPS`;
DROP TABLE IF EXISTS `msg_RefEpoch`;
DROP TABLE IF EXISTS `msg_RawMeas`;
DROP TABLE IF EXISTS `msg_PosVelVector`;
DROP TABLE IF EXISTS `msg_ClockOffsets`;
DROP TABLE IF EXISTS `msg_RE`;
DROP TABLE IF EXISTS `msg_ER`;
DROP TABLE IF EXISTS `msg_IonoParams`;
DROP TABLE IF EXISTS `msg_Event`;
DROP TABLE IF EXISTS `msg_Latency`;
DROP TABLE IF EXISTS `msg_Wrapper`;
DROP TABLE IF EXISTS `msg_Params`;
DROP TABLE IF EXISTS `msg_LoggingHistory`;
DROP TABLE IF EXISTS `msg_BaseInfo`;
DROP TABLE IF EXISTS `msg_Security0`;
DROP TABLE IF EXISTS `msg_Security1`;
DROP TABLE IF EXISTS `msg_TrackingTime`;
DROP TABLE IF EXISTS `msg_RcvOscOffs`;
DROP TABLE IF EXISTS `msg_EpochEnd`;
DROP TABLE IF EXISTS `ct_UtcOffs`;
DROP TABLE IF EXISTS `ct_Smooth`;
DROP TABLE IF EXISTS `ct_SvData0`;
DROP TABLE IF EXISTS `ct_SvData1`;
DROP TABLE IF EXISTS `ct_SvData2`;
DROP TABLE IF EXISTS `ct_Header`;
DROP TABLE IF EXISTS `ct_SlotRec`;
DROP TABLE IF EXISTS `ct_ClkOffs`;
DROP TABLE IF EXISTS `ct_GPSAlm1`;
DROP TABLE IF EXISTS `ct_GPSEphemeris1`;

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

-- custom type 'UtcOffs'
CREATE TABLE `ct_UtcOffs` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `a0` DOUBLE, 
    `a1` FLOAT, 
    `tot` INT UNSIGNED, 
    `wnt` SMALLINT UNSIGNED, 
    `dtls` TINYINT, 
    `dn` TINYINT UNSIGNED, 
    `wnlsf` SMALLINT UNSIGNED, 
    `dtlsf` TINYINT, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_ct_UtcOffs_unixTimeEpoch` (`unixTimeEpoch`));

-- custom type 'Smooth'
CREATE TABLE `ct_Smooth` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `value` FLOAT, 
    `interval` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_ct_Smooth_unixTimeEpoch` (`unixTimeEpoch`));

-- custom type 'SvData0'
CREATE TABLE `ct_SvData0` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `prn` TINYINT, 
    `cnt` TINYINT UNSIGNED, 
    `data` BLOB, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_ct_SvData0_unixTimeEpoch` (`unixTimeEpoch`));

-- custom type 'SvData1'
CREATE TABLE `ct_SvData1` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `fcn1` TINYINT, 
    `cnt` TINYINT UNSIGNED, 
    `data` BLOB, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_ct_SvData1_unixTimeEpoch` (`unixTimeEpoch`));

-- custom type 'SvData2'
CREATE TABLE `ct_SvData2` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `header` BIGINT UNSIGNED, 
    `slot` BLOB, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_ct_SvData2_unixTimeEpoch` (`unixTimeEpoch`));

-- custom type 'Header'
CREATE TABLE `ct_Header` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `refrange` INT UNSIGNED, 
    `usi` TINYINT UNSIGNED, 
    `num` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_ct_Header_unixTimeEpoch` (`unixTimeEpoch`));

-- custom type 'SlotRec'
CREATE TABLE `ct_SlotRec` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `svstOrDelrange` SMALLINT, 
    `word1` INT UNSIGNED, 
    `flags` SMALLINT UNSIGNED, 
    `lock` SMALLINT UNSIGNED, 
    `word2` INT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_ct_SlotRec_unixTimeEpoch` (`unixTimeEpoch`));

-- custom type 'ClkOffs'
CREATE TABLE `ct_ClkOffs` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `word1` INT UNSIGNED, 
    `word2` INT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_ct_ClkOffs_unixTimeEpoch` (`unixTimeEpoch`));

-- custom type 'GPSAlm1'
CREATE TABLE `ct_GPSAlm1` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `sv` TINYINT UNSIGNED, 
    `wna` SMALLINT, 
    `toa` INT, 
    `healthA` TINYINT UNSIGNED, 
    `healthS` TINYINT UNSIGNED, 
    `config` TINYINT UNSIGNED, 
    `af1` FLOAT, 
    `af0` FLOAT, 
    `rootA` FLOAT, 
    `ecc` FLOAT, 
    `m0` FLOAT, 
    `omega0` FLOAT, 
    `argPer` FLOAT, 
    `deli` FLOAT, 
    `omegaDot` FLOAT, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_ct_GPSAlm1_unixTimeEpoch` (`unixTimeEpoch`));

-- custom type 'GPSEphemeris1'
CREATE TABLE `ct_GPSEphemeris1` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `sv` TINYINT UNSIGNED, 
    `tow` INT UNSIGNED, 
    `flags` TINYINT UNSIGNED, 
    `iodc` SMALLINT, 
    `toc` INT, 
    `ura` TINYINT, 
    `healthS` TINYINT UNSIGNED, 
    `wn` SMALLINT, 
    `tgd` FLOAT, 
    `af2` FLOAT, 
    `af1` FLOAT, 
    `af0` FLOAT, 
    `toe` INT, 
    `iode` SMALLINT, 
    `rootA` DOUBLE, 
    `ecc` DOUBLE, 
    `m0` DOUBLE, 
    `omega0` DOUBLE, 
    `inc0` DOUBLE, 
    `argPer` DOUBLE, 
    `deln` FLOAT, 
    `omegaDot` FLOAT, 
    `incDot` FLOAT, 
    `crc` FLOAT, 
    `crs` FLOAT, 
    `cuc` FLOAT, 
    `cus` FLOAT, 
    `cic` FLOAT, 
    `cis` FLOAT, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_ct_GPSEphemeris1_unixTimeEpoch` (`unixTimeEpoch`));

-- message 'FileId': [JP] File Identifier
CREATE TABLE `msg_FileId` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `id_sugar` VARCHAR(1000), 
    `description` VARCHAR(1000), 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_FileId_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_FileId_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_FileId_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_FileId_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_FileId_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'MsgFmt': [MF] Messages Format
CREATE TABLE `msg_MsgFmt` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `id_sugar` VARCHAR(1000), 
    `majorVer` VARCHAR(1000), 
    `minorVer` VARCHAR(1000), 
    `order` CHAR, 
    `cs` VARCHAR(1000), 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_MsgFmt_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_MsgFmt_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_MsgFmt_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_MsgFmt_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_MsgFmt_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'RcvTime': [~~](RT) Receiver Time
CREATE TABLE `msg_RcvTime` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `tod` INT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RcvTime_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_RcvTime_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_RcvTime_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_RcvTime_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_RcvTime_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'EpochTime': [::](ET) Epoch Time
CREATE TABLE `msg_EpochTime` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `tod` INT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_EpochTime_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_EpochTime_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_EpochTime_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_EpochTime_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_EpochTime_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'RcvDate': [RD] Receiver Date
CREATE TABLE `msg_RcvDate` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `year` SMALLINT UNSIGNED, 
    `month` TINYINT UNSIGNED, 
    `day` TINYINT UNSIGNED, 
    `base` TINYINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RcvDate_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_RcvDate_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_RcvDate_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_RcvDate_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_RcvDate_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'RcvTimeOffset': [TO] Reference Time to Receiver Time Offset
CREATE TABLE `msg_RcvTimeOffset` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `val` DOUBLE, 
    `sval` DOUBLE, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RcvTimeOffset_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_RcvTimeOffset_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_RcvTimeOffset_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_RcvTimeOffset_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_RcvTimeOffset_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'RcvTimeOffsetDot': [DO] Derivative of Receiver Time Offset
CREATE TABLE `msg_RcvTimeOffsetDot` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `val` FLOAT, 
    `sval` FLOAT, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RcvTimeOffsetDot_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_RcvTimeOffsetDot_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_RcvTimeOffsetDot_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_RcvTimeOffsetDot_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_RcvTimeOffsetDot_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'RcvTimeAccuracy': [BP] Rough Accuracy of Time Approximation
CREATE TABLE `msg_RcvTimeAccuracy` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `acc` FLOAT, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RcvTimeAccuracy_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_RcvTimeAccuracy_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_RcvTimeAccuracy_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_RcvTimeAccuracy_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_RcvTimeAccuracy_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'GPSTime': [GT] GPS Time
CREATE TABLE `msg_GPSTime` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `tow` INT UNSIGNED, 
    `wn` SMALLINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_GPSTime_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_GPSTime_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_GPSTime_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_GPSTime_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_GPSTime_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'RcvGPSTimeOffset': [GO] GPS to Receiver Time Offset
CREATE TABLE `msg_RcvGPSTimeOffset` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `val` DOUBLE, 
    `sval` DOUBLE, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RcvGPSTimeOffset_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_RcvGPSTimeOffset_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_RcvGPSTimeOffset_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_RcvGPSTimeOffset_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_RcvGPSTimeOffset_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'GLOTime': [NT] GLONASS Time
CREATE TABLE `msg_GLOTime` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `tod` INT UNSIGNED, 
    `dn` SMALLINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_GLOTime_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_GLOTime_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_GLOTime_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_GLOTime_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_GLOTime_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'RcvGLOTimeOffset': [NO] GLONASS to Receiver Time Offset
CREATE TABLE `msg_RcvGLOTimeOffset` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `val` DOUBLE, 
    `sval` DOUBLE, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RcvGLOTimeOffset_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_RcvGLOTimeOffset_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_RcvGLOTimeOffset_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_RcvGLOTimeOffset_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_RcvGLOTimeOffset_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'RcvGALTimeOffset': [EO] GALILEO to Receiver Time Offset
CREATE TABLE `msg_RcvGALTimeOffset` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `val` DOUBLE, 
    `sval` DOUBLE, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RcvGALTimeOffset_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_RcvGALTimeOffset_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_RcvGALTimeOffset_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_RcvGALTimeOffset_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_RcvGALTimeOffset_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'RcvWAASTimeOffset': [WO] WAAS to Receiver Time Offset
CREATE TABLE `msg_RcvWAASTimeOffset` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `val` DOUBLE, 
    `sval` DOUBLE, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RcvWAASTimeOffset_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_RcvWAASTimeOffset_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_RcvWAASTimeOffset_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_RcvWAASTimeOffset_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_RcvWAASTimeOffset_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'GpsUtcParam': [UO] GPS UTC Time Parameters
CREATE TABLE `msg_GpsUtcParam` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `utc` BIGINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_GpsUtcParam_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_GpsUtcParam_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_GpsUtcParam_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_GpsUtcParam_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_GpsUtcParam_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'WaasUtcParam': [WU] WAAS UTC Time Parameters
CREATE TABLE `msg_WaasUtcParam` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `utc` BIGINT UNSIGNED, 
    `utcsi` TINYINT, 
    `tow` INT UNSIGNED, 
    `wn` SMALLINT UNSIGNED, 
    `flags` TINYINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_WaasUtcParam_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_WaasUtcParam_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_WaasUtcParam_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_WaasUtcParam_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_WaasUtcParam_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'GalUtcGpsParam': [EU] GALILEO UTC and GPS Time Parameters
CREATE TABLE `msg_GalUtcGpsParam` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `utc` BIGINT UNSIGNED, 
    `a0g` FLOAT, 
    `a1g` FLOAT, 
    `t0g` INT UNSIGNED, 
    `wn0g` SMALLINT UNSIGNED, 
    `flags` SMALLINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_GalUtcGpsParam_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_GalUtcGpsParam_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_GalUtcGpsParam_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_GalUtcGpsParam_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_GalUtcGpsParam_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'GloUtcGpsParam': [NU] GLONASS UTC and GPS Time Parameters
CREATE TABLE `msg_GloUtcGpsParam` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `tauSys` DOUBLE, 
    `tauGps` FLOAT, 
    `B1` FLOAT, 
    `B2` FLOAT, 
    `KP` TINYINT UNSIGNED, 
    `N4` TINYINT UNSIGNED, 
    `Dn` SMALLINT, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_GloUtcGpsParam_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_GloUtcGpsParam_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_GloUtcGpsParam_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_GloUtcGpsParam_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_GloUtcGpsParam_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'SolutionTime': [ST] Solution Time-Tag
CREATE TABLE `msg_SolutionTime` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `time` INT UNSIGNED, 
    `solType` TINYINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_SolutionTime_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_SolutionTime_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_SolutionTime_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_SolutionTime_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_SolutionTime_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'Pos': [PO] Cartesian Position
CREATE TABLE `msg_Pos` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `x` DOUBLE, 
    `y` DOUBLE, 
    `z` DOUBLE, 
    `sigma` FLOAT, 
    `solType` TINYINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_Pos_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_Pos_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_Pos_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_Pos_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_Pos_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'Vel': [VE] Cartesian Velocity
CREATE TABLE `msg_Vel` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `x` FLOAT, 
    `y` FLOAT, 
    `z` FLOAT, 
    `sigma` FLOAT, 
    `solType` TINYINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_Vel_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_Vel_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_Vel_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_Vel_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_Vel_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'PosVel': [PV] Cartesian Position and Velocity
CREATE TABLE `msg_PosVel` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `x` DOUBLE, 
    `y` DOUBLE, 
    `z` DOUBLE, 
    `pSigma` FLOAT, 
    `vx` FLOAT, 
    `vy` FLOAT, 
    `vz` FLOAT, 
    `vSigma` FLOAT, 
    `solType` TINYINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_PosVel_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_PosVel_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_PosVel_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_PosVel_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_PosVel_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'GeoPos': [PG] Geodetic Position
CREATE TABLE `msg_GeoPos` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `lat` DOUBLE, 
    `lon` DOUBLE, 
    `alt` DOUBLE, 
    `pSigma` FLOAT, 
    `solType` TINYINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_GeoPos_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_GeoPos_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_GeoPos_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_GeoPos_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_GeoPos_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'GeoVel': [VG] Geodetic Velocity
CREATE TABLE `msg_GeoVel` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `lat` FLOAT, 
    `lon` FLOAT, 
    `alt` FLOAT, 
    `pSigma` FLOAT, 
    `solType` TINYINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_GeoVel_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_GeoVel_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_GeoVel_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_GeoVel_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_GeoVel_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'Rms': [SG] Position and Velocity RMS Errors
CREATE TABLE `msg_Rms` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `hpos` FLOAT, 
    `vpos` FLOAT, 
    `hvel` FLOAT, 
    `vvel` FLOAT, 
    `solType` TINYINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_Rms_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_Rms_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_Rms_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_Rms_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_Rms_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'Dops': [DP] Dilution of Precision (DOP)
CREATE TABLE `msg_Dops` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `hdop` FLOAT, 
    `vdop` FLOAT, 
    `tdop` FLOAT, 
    `solType` TINYINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_Dops_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_Dops_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_Dops_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_Dops_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_Dops_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'PosCov': [SP] Position Covariance Matrix
CREATE TABLE `msg_PosCov` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `xx` FLOAT, 
    `yy` FLOAT, 
    `zz` FLOAT, 
    `tt` FLOAT, 
    `xy` FLOAT, 
    `xz` FLOAT, 
    `xt` FLOAT, 
    `yz` FLOAT, 
    `yt` FLOAT, 
    `zt` FLOAT, 
    `solType` TINYINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_PosCov_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_PosCov_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_PosCov_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_PosCov_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_PosCov_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'VelCov': [SV] Velocity Covariance Matrix
CREATE TABLE `msg_VelCov` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `xx` FLOAT, 
    `yy` FLOAT, 
    `zz` FLOAT, 
    `tt` FLOAT, 
    `xy` FLOAT, 
    `xz` FLOAT, 
    `xt` FLOAT, 
    `yz` FLOAT, 
    `yt` FLOAT, 
    `zt` FLOAT, 
    `solType` TINYINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_VelCov_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_VelCov_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_VelCov_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_VelCov_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_VelCov_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'BaseLine': [BL] Base Line
CREATE TABLE `msg_BaseLine` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `x` DOUBLE, 
    `y` DOUBLE, 
    `z` DOUBLE, 
    `sigma` FLOAT, 
    `solType` TINYINT UNSIGNED, 
    `time` INT, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_BaseLine_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_BaseLine_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_BaseLine_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_BaseLine_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_BaseLine_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'PosStat': [PS] Position Statistics
CREATE TABLE `msg_PosStat` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `solType` TINYINT UNSIGNED, 
    `gpsLocked` TINYINT UNSIGNED, 
    `gloLocked` TINYINT UNSIGNED, 
    `gpsAvail` TINYINT UNSIGNED, 
    `gloAvail` TINYINT UNSIGNED, 
    `gpsUsed` TINYINT UNSIGNED, 
    `gloUsed` TINYINT UNSIGNED, 
    `fixProg` TINYINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_PosStat_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_PosStat_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_PosStat_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_PosStat_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_PosStat_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'PosCompTime': [PT] Time of Continuous Position Computation
CREATE TABLE `msg_PosCompTime` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `pt` INT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_PosCompTime_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_PosCompTime_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_PosCompTime_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_PosCompTime_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_PosCompTime_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'SatIndex': [SI] Satellite Indices
CREATE TABLE `msg_SatIndex` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `usi` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_SatIndex_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_SatIndex_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_SatIndex_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_SatIndex_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_SatIndex_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'AntName': [AN] Antenna Names
CREATE TABLE `msg_AntName` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `name` VARCHAR(1000), 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_AntName_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_AntName_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_AntName_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_AntName_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_AntName_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'SatNumbers': [NN] GLONASS Satellite System Numbers
CREATE TABLE `msg_SatNumbers` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `osn` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_SatNumbers_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_SatNumbers_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_SatNumbers_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_SatNumbers_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_SatNumbers_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'SatElevation': [EL] Satellite Elevations
CREATE TABLE `msg_SatElevation` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `elev` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_SatElevation_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_SatElevation_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_SatElevation_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_SatElevation_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_SatElevation_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'SatAzimuth': [AZ] Satellite Azimuths
CREATE TABLE `msg_SatAzimuth` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `azim` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_SatAzimuth_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_SatAzimuth_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_SatAzimuth_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_SatAzimuth_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_SatAzimuth_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'PR': [RC], [R1], [R2], [R3], [R5]: Pseudoranges
CREATE TABLE `msg_PR` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `pr` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_PR_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_PR_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_PR_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_PR_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_PR_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'SPR': [rc], [r1], [r2], [r3], [r5]: Short Pseudoranges
CREATE TABLE `msg_SPR` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `spr` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_SPR_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_SPR_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_SPR_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_SPR_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_SPR_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'RPR': [1R], [2R], [3R], [5R]: Relative Pseudoranges
CREATE TABLE `msg_RPR` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `rpr` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RPR_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_RPR_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_RPR_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_RPR_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_RPR_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'SRPR': [1r], [2r], [3r], [5r]: Short Relative Pseudoranges
CREATE TABLE `msg_SRPR` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `srpr` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_SRPR_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_SRPR_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_SRPR_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_SRPR_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_SRPR_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'SC': [CC], [C1], [C2], [C3], [C5]: Smoothing Corrections
CREATE TABLE `msg_SC` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `smooth` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_SC_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_SC_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_SC_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_SC_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_SC_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'SS': [cc], [c1], [c2], [c3], [c5]: Short Smoothing Corrections
CREATE TABLE `msg_SS` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `smooth` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_SS_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_SS_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_SS_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_SS_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_SS_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'CP': [PC], [P1], [P2], [P3], [P5]: Carrier Phases
CREATE TABLE `msg_CP` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `cp` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_CP_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_CP_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_CP_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_CP_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_CP_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'SCP': [pc], [p1], [p2], [p3], [p5]: Short Carrier Phases
CREATE TABLE `msg_SCP` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `scp` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_SCP_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_SCP_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_SCP_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_SCP_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_SCP_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'RCP_RC': [CP], [1P], [2P], [3P], [5P]: Short Relative Carrier Phases
CREATE TABLE `msg_RCP_RC0` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `rcp` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RCP_RC0_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_RCP_RC0_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_RCP_RC0_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_RCP_RC0_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_RCP_RC0_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'RCP_rc': [cp], [1p], [2p], [3p], [5p]: Short Relative Carrier Phases
CREATE TABLE `msg_RCP_rc1` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `rcp` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RCP_rc1_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_RCP_rc1_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_RCP_rc1_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_RCP_rc1_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_RCP_rc1_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'DP': [DC], [D1], [D2], [D3], [D5]: Doppler
CREATE TABLE `msg_DP` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `dp` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_DP_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_DP_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_DP_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_DP_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_DP_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'SRDP': [1d], [2d], [3d], [5d]: Short Relative Doppler
CREATE TABLE `msg_SRDP` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `srdp` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_SRDP_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_SRDP_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_SRDP_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_SRDP_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_SRDP_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'CNR': [EC], [E1], [E2], [E3], [E5]: Carrier to Noise Ratio
CREATE TABLE `msg_CNR` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `cnr` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_CNR_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_CNR_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_CNR_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_CNR_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_CNR_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'CNR_4': [CE], [1E], [2E], [3E], [5E]: Carrier to Noise Ratio x 
CREATE TABLE `msg_CNR_4` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `cnrX4` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_CNR_4_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_CNR_4_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_CNR_4_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_CNR_4_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_CNR_4_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'Flags': [FC], [F1], [F2], [F3], [F5]: Signal Lock Loop Flags
CREATE TABLE `msg_Flags` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `flags` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_Flags_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_Flags_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_Flags_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_Flags_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_Flags_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'TrackingTimeCA': [TC] CA/L1 Continuous Tracking Time
CREATE TABLE `msg_TrackingTimeCA` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `tt` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_TrackingTimeCA_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_TrackingTimeCA_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_TrackingTimeCA_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_TrackingTimeCA_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_TrackingTimeCA_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'NavStatus': [SS] Satellite Navigation Status
CREATE TABLE `msg_NavStatus` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `ns` BLOB, 
    `solType` TINYINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_NavStatus_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_NavStatus_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_NavStatus_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_NavStatus_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_NavStatus_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'IonoDelay': [ID] Ionospheric Delays
CREATE TABLE `msg_IonoDelay` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `delay` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_IonoDelay_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_IonoDelay_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_IonoDelay_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_IonoDelay_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_IonoDelay_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'GPSAlm0': [GA] GPS Almanac
CREATE TABLE `msg_GPSAlm0` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `sv` TINYINT UNSIGNED, 
    `wna` SMALLINT, 
    `toa` INT, 
    `healthA` TINYINT UNSIGNED, 
    `healthS` TINYINT UNSIGNED, 
    `config` TINYINT UNSIGNED, 
    `af1` FLOAT, 
    `af0` FLOAT, 
    `rootA` FLOAT, 
    `ecc` FLOAT, 
    `m0` FLOAT, 
    `omega0` FLOAT, 
    `argPer` FLOAT, 
    `deli` FLOAT, 
    `omegaDot` FLOAT, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_GPSAlm0_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_GPSAlm0_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_GPSAlm0_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_GPSAlm0_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_GPSAlm0_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'GALAlm': [EA] GALILEO Almanac
CREATE TABLE `msg_GALAlm` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `gps` BIGINT UNSIGNED, 
    `iod` SMALLINT, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_GALAlm_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_GALAlm_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_GALAlm_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_GALAlm_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_GALAlm_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'GLOAlmanac': [NA] GLONASS Almanac
CREATE TABLE `msg_GLOAlmanac` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `sv` TINYINT UNSIGNED, 
    `frqNum` TINYINT, 
    `dna` SMALLINT, 
    `tlam` FLOAT, 
    `flags` TINYINT UNSIGNED, 
    `tauN` FLOAT, 
    `tauSys` DOUBLE, 
    `ecc` FLOAT, 
    `lambda` FLOAT, 
    `argPer` FLOAT, 
    `delT` FLOAT, 
    `delTdt` FLOAT, 
    `deli` FLOAT, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_GLOAlmanac_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_GLOAlmanac_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_GLOAlmanac_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_GLOAlmanac_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_GLOAlmanac_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'WAASAlmanac': [WA] WAAS Almanac
CREATE TABLE `msg_WAASAlmanac` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `waasPrn` TINYINT UNSIGNED, 
    `gpsPrn` TINYINT UNSIGNED, 
    `id_sugar` TINYINT UNSIGNED, 
    `healthS` TINYINT UNSIGNED, 
    `tod` INT UNSIGNED, 
    `xg` DOUBLE, 
    `yg` DOUBLE, 
    `zg` DOUBLE, 
    `vxg` FLOAT, 
    `vyg` FLOAT, 
    `vzg` FLOAT, 
    `tow` INT UNSIGNED, 
    `wn` SMALLINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_WAASAlmanac_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_WAASAlmanac_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_WAASAlmanac_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_WAASAlmanac_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_WAASAlmanac_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'GPSEphemeris0': [GE] GPS Ephemeris
CREATE TABLE `msg_GPSEphemeris0` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `sv` TINYINT UNSIGNED, 
    `tow` INT UNSIGNED, 
    `flags` TINYINT UNSIGNED, 
    `iodc` SMALLINT, 
    `toc` INT, 
    `ura` TINYINT, 
    `healthS` TINYINT UNSIGNED, 
    `wn` SMALLINT, 
    `tgd` FLOAT, 
    `af2` FLOAT, 
    `af1` FLOAT, 
    `af0` FLOAT, 
    `toe` INT, 
    `iode` SMALLINT, 
    `rootA` DOUBLE, 
    `ecc` DOUBLE, 
    `m0` DOUBLE, 
    `omega0` DOUBLE, 
    `inc0` DOUBLE, 
    `argPer` DOUBLE, 
    `deln` FLOAT, 
    `omegaDot` FLOAT, 
    `incDot` FLOAT, 
    `crc` FLOAT, 
    `crs` FLOAT, 
    `cuc` FLOAT, 
    `cus` FLOAT, 
    `cic` FLOAT, 
    `cis` FLOAT, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_GPSEphemeris0_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_GPSEphemeris0_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_GPSEphemeris0_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_GPSEphemeris0_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_GPSEphemeris0_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'GLOEphemeris': [NE] GLONASS Ephemeris
CREATE TABLE `msg_GLOEphemeris` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `sv` TINYINT UNSIGNED, 
    `frqNum` TINYINT, 
    `dne` SMALLINT, 
    `tk` INT, 
    `tb` INT, 
    `health` TINYINT UNSIGNED, 
    `age` TINYINT UNSIGNED, 
    `flags` TINYINT UNSIGNED, 
    `r` BLOB, 
    `v` BLOB, 
    `w` BLOB, 
    `tauSys` DOUBLE, 
    `tau` FLOAT, 
    `gamma` FLOAT, 
    `fDelTauN` FLOAT, 
    `nFt` TINYINT UNSIGNED, 
    `nN4` TINYINT UNSIGNED, 
    `flags2` SMALLINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_GLOEphemeris_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_GLOEphemeris_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_GLOEphemeris_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_GLOEphemeris_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_GLOEphemeris_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'WAASEhemeris': [WE] WAAS Ephemeris
CREATE TABLE `msg_WAASEhemeris` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `waasPrn` TINYINT UNSIGNED, 
    `gpsPrn` TINYINT UNSIGNED, 
    `iod` TINYINT UNSIGNED, 
    `acc` TINYINT UNSIGNED, 
    `tod` INT UNSIGNED, 
    `xg` DOUBLE, 
    `yg` DOUBLE, 
    `zg` DOUBLE, 
    `vxg` FLOAT, 
    `vyg` FLOAT, 
    `vzg` FLOAT, 
    `vvxg` FLOAT, 
    `vvyg` FLOAT, 
    `vvzg` FLOAT, 
    `agf0` FLOAT, 
    `agf1` FLOAT, 
    `tow` INT UNSIGNED, 
    `wn` SMALLINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_WAASEhemeris_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_WAASEhemeris_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_WAASEhemeris_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_WAASEhemeris_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_WAASEhemeris_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'GALEphemeris': [EN] GALILEO Ephemeris
CREATE TABLE `msg_GALEphemeris` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `gps` BIGINT UNSIGNED, 
    `bgdE1E5a` FLOAT, 
    `bgdE1E5b` FLOAT, 
    `ai0` FLOAT, 
    `ai1` FLOAT, 
    `ai2` FLOAT, 
    `sfi` TINYINT UNSIGNED, 
    `navType` TINYINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_GALEphemeris_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_GALEphemeris_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_GALEphemeris_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_GALEphemeris_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_GALEphemeris_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'GpsNavData': [GD] GPS Raw Navigation Data
CREATE TABLE `msg_GpsNavData` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `recSize` TINYINT UNSIGNED, 
    `dat` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_GpsNavData_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_GpsNavData_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_GpsNavData_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_GpsNavData_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_GpsNavData_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'GloNavData': [LD] GLONASS Raw Navigation Data
CREATE TABLE `msg_GloNavData` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `recSize` TINYINT UNSIGNED, 
    `dat` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_GloNavData_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_GloNavData_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_GloNavData_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_GloNavData_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_GloNavData_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'WAASRawMessage': [WD] WAAS Raw Navigation Data
CREATE TABLE `msg_WAASRawMessage` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `prn` TINYINT UNSIGNED, 
    `time` INT UNSIGNED, 
    `reserv` SMALLINT UNSIGNED, 
    `data` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_WAASRawMessage_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_WAASRawMessage_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_WAASRawMessage_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_WAASRawMessage_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_WAASRawMessage_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'GALRawMessage': [ED] GALILEO Raw Navigation Data
CREATE TABLE `msg_GALRawMessage` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `prn` TINYINT UNSIGNED, 
    `time` INT UNSIGNED, 
    `type` TINYINT UNSIGNED, 
    `len` TINYINT UNSIGNED, 
    `data` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_GALRawMessage_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_GALRawMessage_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_GALRawMessage_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_GALRawMessage_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_GALRawMessage_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'GloPhaseDelay': [gC], [g1], [g2], [g3]: GLONASS Phase Delays
CREATE TABLE `msg_GloPhaseDelay` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `fcn` BLOB, 
    `phase` BLOB, 
    `range` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_GloPhaseDelay_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_GloPhaseDelay_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_GloPhaseDelay_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_GloPhaseDelay_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_GloPhaseDelay_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'RotationMatrix': [MR] Rotation Matrix
CREATE TABLE `msg_RotationMatrix` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `time` INT UNSIGNED, 
    `q00` FLOAT, 
    `q01` FLOAT, 
    `q02` FLOAT, 
    `q12` FLOAT, 
    `rms` BLOB, 
    `solType` BLOB, 
    `flag` TINYINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RotationMatrix_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_RotationMatrix_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_RotationMatrix_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_RotationMatrix_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_RotationMatrix_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'RotationMatrixAndVectors': [mr] Rotation Matrix and Vectors
CREATE TABLE `msg_RotationMatrixAndVectors` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `time` INT UNSIGNED, 
    `q00` FLOAT, 
    `q01` FLOAT, 
    `q02` FLOAT, 
    `q12` FLOAT, 
    `rms` BLOB, 
    `solType` BLOB, 
    `flag` TINYINT UNSIGNED, 
    `bl0` BLOB, 
    `bl1` BLOB, 
    `bl2` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RotationMatrixAndVectors_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_RotationMatrixAndVectors_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_RotationMatrixAndVectors_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_RotationMatrixAndVectors_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_RotationMatrixAndVectors_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'RotationAngles': [AR] Rotation Angles
CREATE TABLE `msg_RotationAngles` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `time` INT UNSIGNED, 
    `pitch` FLOAT, 
    `roll` FLOAT, 
    `heading` FLOAT, 
    `pitchRms` FLOAT, 
    `rollRms` FLOAT, 
    `headingRms` FLOAT, 
    `flags` TINYINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RotationAngles_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_RotationAngles_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_RotationAngles_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_RotationAngles_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_RotationAngles_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'AngularVelocity': [AV] Angular Velocities
CREATE TABLE `msg_AngularVelocity` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `time` INT UNSIGNED, 
    `x` FLOAT, 
    `y` FLOAT, 
    `z` FLOAT, 
    `rms` FLOAT, 
    `flags` TINYINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_AngularVelocity_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_AngularVelocity_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_AngularVelocity_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_AngularVelocity_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_AngularVelocity_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'InertialMeasurements': [IM] Inertial Measurements
CREATE TABLE `msg_InertialMeasurements` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `accelerations` BLOB, 
    `angularVelocities` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_InertialMeasurements_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_InertialMeasurements_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_InertialMeasurements_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_InertialMeasurements_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_InertialMeasurements_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'ExtEvent': [XA], [XB] External Event
CREATE TABLE `msg_ExtEvent` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `ms` INT, 
    `ns` INT, 
    `timeScale` TINYINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_ExtEvent_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_ExtEvent_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_ExtEvent_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_ExtEvent_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_ExtEvent_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'PPSOffset': [ZA], [ZB] PPS Offset
CREATE TABLE `msg_PPSOffset` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `offs` FLOAT, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_PPSOffset_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_PPSOffset_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_PPSOffset_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_PPSOffset_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_PPSOffset_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'RcvTimeOffsAtPPS': [YA], [YB] Time Offset at PPS Generation Time
CREATE TABLE `msg_RcvTimeOffsAtPPS` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `offs` DOUBLE, 
    `timeScale` TINYINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RcvTimeOffsAtPPS_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_RcvTimeOffsAtPPS_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_RcvTimeOffsAtPPS_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_RcvTimeOffsAtPPS_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_RcvTimeOffsAtPPS_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'RefEpoch': [rE] Reference Epoch
CREATE TABLE `msg_RefEpoch` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `sample` SMALLINT UNSIGNED, 
    `scale` SMALLINT UNSIGNED, 
    `reftime` INT UNSIGNED, 
    `crc16` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RefEpoch_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_RefEpoch_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_RefEpoch_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_RefEpoch_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_RefEpoch_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'RawMeas': [rM] Raw Measurements
CREATE TABLE `msg_RawMeas` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `sample` SMALLINT UNSIGNED, 
    `scale` SMALLINT UNSIGNED, 
    `reftime` INT UNSIGNED, 
    `clock` SMALLINT, 
    `flags` SMALLINT UNSIGNED, 
    `svd` BLOB, 
    `crc16` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RawMeas_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_RawMeas_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_RawMeas_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_RawMeas_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_RawMeas_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'PosVelVector': [rV] Receiver’s Position and Velocity
CREATE TABLE `msg_PosVelVector` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `sample` SMALLINT UNSIGNED, 
    `delta` SMALLINT UNSIGNED, 
    `word1` INT UNSIGNED, 
    `word2` INT UNSIGNED, 
    `word3` INT UNSIGNED, 
    `word4` INT UNSIGNED, 
    `word5` INT UNSIGNED, 
    `word6` INT UNSIGNED, 
    `word7` INT UNSIGNED, 
    `word8` INT UNSIGNED, 
    `word9` INT UNSIGNED, 
    `crc16` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_PosVelVector_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_PosVelVector_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_PosVelVector_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_PosVelVector_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_PosVelVector_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'ClockOffsets': [rT] Receiver Clock Offsets
CREATE TABLE `msg_ClockOffsets` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `sample` SMALLINT UNSIGNED, 
    `reserved` SMALLINT UNSIGNED, 
    `recSize` TINYINT UNSIGNED, 
    `Offs` BLOB, 
    `crc16` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_ClockOffsets_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_ClockOffsets_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_ClockOffsets_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_ClockOffsets_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_ClockOffsets_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'RE': [RE] Reply
CREATE TABLE `msg_RE` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `reply` VARCHAR(1000), 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RE_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_RE_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_RE_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_RE_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_RE_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'ER': [ER] Error
CREATE TABLE `msg_ER` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `error` VARCHAR(1000), 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_ER_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_ER_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_ER_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_ER_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_ER_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'IonoParams': [IO] Ionospheric Parameters
CREATE TABLE `msg_IonoParams` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `tot` INT UNSIGNED, 
    `wn` SMALLINT UNSIGNED, 
    `alpha0` FLOAT, 
    `alpha1` FLOAT, 
    `alpha2` FLOAT, 
    `alpha3` FLOAT, 
    `beta0` FLOAT, 
    `beta1` FLOAT, 
    `beta2` FLOAT, 
    `beta3` FLOAT, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_IonoParams_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_IonoParams_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_IonoParams_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_IonoParams_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_IonoParams_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'Event': [==](EV) Event
CREATE TABLE `msg_Event` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `time` INT UNSIGNED, 
    `type` TINYINT UNSIGNED, 
    `data` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_Event_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_Event_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_Event_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_Event_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_Event_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'Latency': [LT] Message Output Latency
CREATE TABLE `msg_Latency` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `lt` TINYINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_Latency_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_Latency_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_Latency_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_Latency_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_Latency_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'Wrapper': [>>] Wrapper
CREATE TABLE `msg_Wrapper` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `id_sugar` TINYINT UNSIGNED, 
    `data` BLOB, 
    `cs` VARCHAR(1000), 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_Wrapper_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_Wrapper_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_Wrapper_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_Wrapper_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_Wrapper_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'Params': [PM] Parameters
CREATE TABLE `msg_Params` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `params` VARCHAR(1000), 
    `delim` VARCHAR(1000), 
    `cs` VARCHAR(1000), 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_Params_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_Params_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_Params_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_Params_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_Params_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'LoggingHistory': [LH] Logging History
CREATE TABLE `msg_LoggingHistory` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `svsCount` TINYINT UNSIGNED, 
    `targetStream` TINYINT UNSIGNED, 
    `issue` SMALLINT UNSIGNED, 
    `bitsCount` SMALLINT UNSIGNED, 
    `lastBitTime` INT UNSIGNED, 
    `uids` BLOB, 
    `pad` BLOB, 
    `hist` BLOB, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_LoggingHistory_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_LoggingHistory_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_LoggingHistory_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_LoggingHistory_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_LoggingHistory_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'BaseInfo': [BI] Base Station Information
CREATE TABLE `msg_BaseInfo` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `x` DOUBLE, 
    `y` DOUBLE, 
    `z` DOUBLE, 
    `id_sugar` SMALLINT UNSIGNED, 
    `solType` TINYINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_BaseInfo_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_BaseInfo_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_BaseInfo_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_BaseInfo_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_BaseInfo_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'Security': [SE] Security
CREATE TABLE `msg_Security0` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `data` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_Security0_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_Security0_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_Security0_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_Security0_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_Security0_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'Security': [SM] Security for [rM]
CREATE TABLE `msg_Security1` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `data` BLOB, 
    `crc16` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_Security1_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_Security1_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_Security1_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_Security1_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_Security1_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'TrackingTime': [TT] CA/L1 Overall Continuous Tracking Time
CREATE TABLE `msg_TrackingTime` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `tt` INT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_TrackingTime_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_TrackingTime_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_TrackingTime_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_TrackingTime_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_TrackingTime_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'RcvOscOffs': [OO] Oscillator Offset
CREATE TABLE `msg_RcvOscOffs` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `val` FLOAT, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RcvOscOffs_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_RcvOscOffs_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_RcvOscOffs_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_RcvOscOffs_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_RcvOscOffs_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'EpochEnd': [||](EE) Epoch End
CREATE TABLE `msg_EpochEnd` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_EpochEnd_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_EpochEnd_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_EpochEnd_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_EpochEnd_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_EpochEnd_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));



-- нулевая эпоха-заглушка
-- INSERT INTO `epoch` (`unixtime`) VALUES (NULL);

-- Наполнение классификатора sizeSpecialValueClassifier
INSERT INTO `sizeSpecialValueClassifier` (`id`, `name`) 
    VALUES (-2, 'Fill'), 
           (-1, 'Dynamic');

-- Наполнение классификатора messageValidationClassifier
INSERT INTO `messageValidationClassifier` (`id`, `name`) 
    VALUES (0, 'None'), 
           (1, 'Checksum'), 
           (2, 'ChecksumAsHexAscii'), 
           (3, 'Crc16');

-- Наполнение классификатора messageKindClassifier
INSERT INTO `messageKindClassifier` (`name`) 
    VALUES ('NonStandardTextMessage'), 
           ('StandardTextMessage'), 
           ('GreisStandardMessage'), 
           ('ForeignStandardMessage'), 
           ('UnknownStandardMessage');

-- Наполнение классификатора messageTypeClassifier
INSERT INTO `messageTypeClassifier` (`name`) 
    VALUES ('Unknown'), 
           ('AlmanacsAndEphemeris');

-- Наполнение мета-информации о пользовательских типах
INSERT INTO `customTypeMeta` (`id`, `name`, `size`, `tableName`) 
    VALUES (1, 'UtcOffs', 23, 'ct_UtcOffs'), 
           (2, 'Smooth', 6, 'ct_Smooth'), 
           (3, 'SvData0', 42, 'ct_SvData0'), 
           (4, 'SvData1', 18, 'ct_SvData1'), 
           (5, 'SvData2', -1, 'ct_SvData2'), 
           (6, 'Header', 6, 'ct_Header'), 
           (7, 'SlotRec', 14, 'ct_SlotRec'), 
           (8, 'ClkOffs', 8, 'ct_ClkOffs'), 
           (9, 'GPSAlm1', 46, 'ct_GPSAlm1'), 
           (10, 'GPSEphemeris1', 122, 'ct_GPSEphemeris1');

-- Наполнение мета-информации о сообщениях
INSERT INTO `messageMeta` (`id`, `name`, `title`, `size`, `idValidation`, `idKind`, `idType`, `tableName`) 
    VALUES (1, 'FileId', '[JP] File Identifier', 85, 0, 3, 1, 'msg_FileId'), 
           (2, 'MsgFmt', '[MF] Messages Format', 9, 2, 3, 1, 'msg_MsgFmt'), 
           (3, 'RcvTime', '[~~](RT) Receiver Time', 5, 1, 3, 1, 'msg_RcvTime'), 
           (4, 'EpochTime', '[::](ET) Epoch Time', 5, 1, 3, 1, 'msg_EpochTime'), 
           (5, 'RcvDate', '[RD] Receiver Date', 6, 1, 3, 1, 'msg_RcvDate'), 
           (6, 'RcvTimeOffset', '[TO] Reference Time to Receiver Time Offset', 17, 1, 3, 1, 'msg_RcvTimeOffset'), 
           (7, 'RcvTimeOffsetDot', '[DO] Derivative of Receiver Time Offset', 9, 1, 3, 1, 'msg_RcvTimeOffsetDot'), 
           (8, 'RcvTimeAccuracy', '[BP] Rough Accuracy of Time Approximation', 5, 1, 3, 1, 'msg_RcvTimeAccuracy'), 
           (9, 'GPSTime', '[GT] GPS Time', 7, 1, 3, 1, 'msg_GPSTime'), 
           (10, 'RcvGPSTimeOffset', '[GO] GPS to Receiver Time Offset', 17, 1, 3, 1, 'msg_RcvGPSTimeOffset'), 
           (11, 'GLOTime', '[NT] GLONASS Time', 7, 1, 3, 1, 'msg_GLOTime'), 
           (12, 'RcvGLOTimeOffset', '[NO] GLONASS to Receiver Time Offset', 17, 1, 3, 1, 'msg_RcvGLOTimeOffset'), 
           (13, 'RcvGALTimeOffset', '[EO] GALILEO to Receiver Time Offset', 17, 1, 3, 1, 'msg_RcvGALTimeOffset'), 
           (14, 'RcvWAASTimeOffset', '[WO] WAAS to Receiver Time Offset', 17, 1, 3, 1, 'msg_RcvWAASTimeOffset'), 
           (15, 'GpsUtcParam', '[UO] GPS UTC Time Parameters', 24, 1, 3, 1, 'msg_GpsUtcParam'), 
           (16, 'WaasUtcParam', '[WU] WAAS UTC Time Parameters', 32, 1, 3, 1, 'msg_WaasUtcParam'), 
           (17, 'GalUtcGpsParam', '[EU] GALILEO UTC and GPS Time Parameters', 40, 1, 3, 1, 'msg_GalUtcGpsParam'), 
           (18, 'GloUtcGpsParam', '[NU] GLONASS UTC and GPS Time Parameters', 25, 1, 3, 1, 'msg_GloUtcGpsParam'), 
           (19, 'SolutionTime', '[ST] Solution Time-Tag', 6, 1, 3, 1, 'msg_SolutionTime'), 
           (20, 'Pos', '[PO] Cartesian Position', 30, 1, 3, 1, 'msg_Pos'), 
           (21, 'Vel', '[VE] Cartesian Velocity', 18, 1, 3, 1, 'msg_Vel'), 
           (22, 'PosVel', '[PV] Cartesian Position and Velocity', 46, 1, 3, 1, 'msg_PosVel'), 
           (23, 'GeoPos', '[PG] Geodetic Position', 30, 1, 3, 1, 'msg_GeoPos'), 
           (24, 'GeoVel', '[VG] Geodetic Velocity', 18, 1, 3, 1, 'msg_GeoVel'), 
           (25, 'Rms', '[SG] Position and Velocity RMS Errors', 18, 1, 3, 1, 'msg_Rms'), 
           (26, 'Dops', '[DP] Dilution of Precision (DOP)', 14, 1, 3, 1, 'msg_Dops'), 
           (27, 'PosCov', '[SP] Position Covariance Matrix', 42, 1, 3, 1, 'msg_PosCov'), 
           (28, 'VelCov', '[SV] Velocity Covariance Matrix', 42, 1, 3, 1, 'msg_VelCov'), 
           (29, 'BaseLine', '[BL] Base Line', 34, 1, 3, 1, 'msg_BaseLine'), 
           (30, 'PosStat', '[PS] Position Statistics', 9, 1, 3, 1, 'msg_PosStat'), 
           (31, 'PosCompTime', '[PT] Time of Continuous Position Computation', 5, 1, 3, 1, 'msg_PosCompTime'), 
           (32, 'SatIndex', '[SI] Satellite Indices', -2, 1, 3, 1, 'msg_SatIndex'), 
           (33, 'AntName', '[AN] Antenna Names', -2, 1, 3, 1, 'msg_AntName'), 
           (34, 'SatNumbers', '[NN] GLONASS Satellite System Numbers', -2, 1, 3, 1, 'msg_SatNumbers'), 
           (35, 'SatElevation', '[EL] Satellite Elevations', -2, 1, 3, 1, 'msg_SatElevation'), 
           (36, 'SatAzimuth', '[AZ] Satellite Azimuths', -2, 1, 3, 1, 'msg_SatAzimuth'), 
           (37, 'PR', '[RC], [R1], [R2], [R3], [R5]: Pseudoranges', -2, 1, 3, 1, 'msg_PR'), 
           (38, 'SPR', '[rc], [r1], [r2], [r3], [r5]: Short Pseudoranges', -2, 1, 3, 1, 'msg_SPR'), 
           (39, 'RPR', '[1R], [2R], [3R], [5R]: Relative Pseudoranges', -2, 1, 3, 1, 'msg_RPR'), 
           (40, 'SRPR', '[1r], [2r], [3r], [5r]: Short Relative Pseudoranges', -2, 1, 3, 1, 'msg_SRPR'), 
           (41, 'SC', '[CC], [C1], [C2], [C3], [C5]: Smoothing Corrections', -2, 1, 3, 1, 'msg_SC'), 
           (42, 'SS', '[cc], [c1], [c2], [c3], [c5]: Short Smoothing Corrections', -2, 1, 3, 1, 'msg_SS'), 
           (43, 'CP', '[PC], [P1], [P2], [P3], [P5]: Carrier Phases', -2, 1, 3, 1, 'msg_CP'), 
           (44, 'SCP', '[pc], [p1], [p2], [p3], [p5]: Short Carrier Phases', -2, 1, 3, 1, 'msg_SCP'), 
           (45, 'RCP_RC', '[CP], [1P], [2P], [3P], [5P]: Short Relative Carrier Phases', -2, 1, 3, 1, 'msg_RCP_RC0'), 
           (46, 'RCP_rc', '[cp], [1p], [2p], [3p], [5p]: Short Relative Carrier Phases', -2, 1, 3, 1, 'msg_RCP_rc1'), 
           (47, 'DP', '[DC], [D1], [D2], [D3], [D5]: Doppler', -2, 1, 3, 1, 'msg_DP'), 
           (48, 'SRDP', '[1d], [2d], [3d], [5d]: Short Relative Doppler', -2, 1, 3, 1, 'msg_SRDP'), 
           (49, 'CNR', '[EC], [E1], [E2], [E3], [E5]: Carrier to Noise Ratio', -2, 1, 3, 1, 'msg_CNR'), 
           (50, 'CNR_4', '[CE], [1E], [2E], [3E], [5E]: Carrier to Noise Ratio x ', -2, 1, 3, 1, 'msg_CNR_4'), 
           (51, 'Flags', '[FC], [F1], [F2], [F3], [F5]: Signal Lock Loop Flags', -2, 1, 3, 1, 'msg_Flags'), 
           (52, 'TrackingTimeCA', '[TC] CA/L1 Continuous Tracking Time', -2, 1, 3, 1, 'msg_TrackingTimeCA'), 
           (53, 'NavStatus', '[SS] Satellite Navigation Status', -2, 1, 3, 1, 'msg_NavStatus'), 
           (54, 'IonoDelay', '[ID] Ionospheric Delays', -2, 1, 3, 1, 'msg_IonoDelay'), 
           (55, 'GPSAlm0', '[GA] GPS Almanac', 47, 1, 3, 2, 'msg_GPSAlm0'), 
           (56, 'GALAlm', '[EA] GALILEO Almanac', 49, 1, 3, 2, 'msg_GALAlm'), 
           (57, 'GLOAlmanac', '[NA] GLONASS Almanac', 46, 1, 3, 2, 'msg_GLOAlmanac'), 
           (58, 'WAASAlmanac', '[WA] WAAS Almanac', 51, 1, 3, 2, 'msg_WAASAlmanac'), 
           (59, 'GPSEphemeris0', '[GE] GPS Ephemeris', 123, 1, 3, 2, 'msg_GPSEphemeris0'), 
           (60, 'GLOEphemeris', '[NE] GLONASS Ephemeris', 88, 1, 3, 2, 'msg_GLOEphemeris'), 
           (61, 'WAASEhemeris', '[WE] WAAS Ephemeris', 71, 1, 3, 2, 'msg_WAASEhemeris'), 
           (62, 'GALEphemeris', '[EN] GALILEO Ephemeris', 145, 1, 3, 2, 'msg_GALEphemeris'), 
           (63, 'GpsNavData', '[GD] GPS Raw Navigation Data', -2, 1, 3, 1, 'msg_GpsNavData'), 
           (64, 'GloNavData', '[LD] GLONASS Raw Navigation Data', -2, 1, 3, 1, 'msg_GloNavData'), 
           (65, 'WAASRawMessage', '[WD] WAAS Raw Navigation Data', 40, 1, 3, 1, 'msg_WAASRawMessage'), 
           (66, 'GALRawMessage', '[ED] GALILEO Raw Navigation Data', -2, 1, 3, 1, 'msg_GALRawMessage'), 
           (67, 'GloPhaseDelay', '[gC], [g1], [g2], [g3]: GLONASS Phase Delays', -2, 1, 3, 1, 'msg_GloPhaseDelay'), 
           (68, 'RotationMatrix', '[MR] Rotation Matrix', 37, 1, 3, 1, 'msg_RotationMatrix'), 
           (69, 'RotationMatrixAndVectors', '[mr] Rotation Matrix and Vectors', 73, 1, 3, 1, 'msg_RotationMatrixAndVectors'), 
           (70, 'RotationAngles', '[AR] Rotation Angles', 30, 1, 3, 1, 'msg_RotationAngles'), 
           (71, 'AngularVelocity', '[AV] Angular Velocities', 22, 1, 3, 1, 'msg_AngularVelocity'), 
           (72, 'InertialMeasurements', '[IM] Inertial Measurements', 25, 1, 3, 1, 'msg_InertialMeasurements'), 
           (73, 'ExtEvent', '[XA], [XB] External Event', 10, 1, 3, 1, 'msg_ExtEvent'), 
           (74, 'PPSOffset', '[ZA], [ZB] PPS Offset', 5, 1, 3, 1, 'msg_PPSOffset'), 
           (75, 'RcvTimeOffsAtPPS', '[YA], [YB] Time Offset at PPS Generation Time', 10, 1, 3, 1, 'msg_RcvTimeOffsAtPPS'), 
           (76, 'RefEpoch', '[rE] Reference Epoch', 10, 3, 3, 1, 'msg_RefEpoch'), 
           (77, 'RawMeas', '[rM] Raw Measurements', -1, 3, 3, 1, 'msg_RawMeas'), 
           (78, 'PosVelVector', '[rV] Receiver’s Position and Velocity', 42, 3, 3, 1, 'msg_PosVelVector'), 
           (79, 'ClockOffsets', '[rT] Receiver Clock Offsets', -2, 3, 3, 1, 'msg_ClockOffsets'), 
           (80, 'RE', '[RE] Reply', -2, 0, 3, 1, 'msg_RE'), 
           (81, 'ER', '[ER] Error', -2, 0, 3, 1, 'msg_ER'), 
           (82, 'IonoParams', '[IO] Ionospheric Parameters', 39, 1, 3, 1, 'msg_IonoParams'), 
           (83, 'Event', '[==](EV) Event', -2, 1, 3, 1, 'msg_Event'), 
           (84, 'Latency', '[LT] Message Output Latency', 2, 1, 3, 1, 'msg_Latency'), 
           (85, 'Wrapper', '[>>] Wrapper', -2, 2, 3, 1, 'msg_Wrapper'), 
           (86, 'Params', '[PM] Parameters', -2, 2, 3, 1, 'msg_Params'), 
           (87, 'LoggingHistory', '[LH] Logging History', -1, 0, 3, 1, 'msg_LoggingHistory'), 
           (88, 'BaseInfo', '[BI] Base Station Information', 28, 1, 3, 1, 'msg_BaseInfo'), 
           (89, 'Security', '[SE] Security', 6, 1, 3, 1, 'msg_Security0'), 
           (90, 'Security', '[SM] Security for [rM]', 8, 3, 3, 1, 'msg_Security1'), 
           (91, 'TrackingTime', '[TT] CA/L1 Overall Continuous Tracking Time', 5, 1, 3, 1, 'msg_TrackingTime'), 
           (92, 'RcvOscOffs', '[OO] Oscillator Offset', 5, 1, 3, 1, 'msg_RcvOscOffs'), 
           (93, 'EpochEnd', '[||](EE) Epoch End', 1, 1, 3, 1, 'msg_EpochEnd');

INSERT INTO `messageCode` (`code`, `idMessageMeta`) 
    VALUES ('JP', 1), 
           ('MF', 2), 
           ('~~', 3), 
           ('::', 4), 
           ('RD', 5), 
           ('TO', 6), 
           ('DO', 7), 
           ('BP', 8), 
           ('GT', 9), 
           ('GO', 10), 
           ('NT', 11), 
           ('NO', 12), 
           ('EO', 13), 
           ('WO', 14), 
           ('UO', 15), 
           ('WU', 16), 
           ('EU', 17), 
           ('NU', 18), 
           ('ST', 19), 
           ('PO', 20), 
           ('VE', 21), 
           ('PV', 22), 
           ('PG', 23), 
           ('VG', 24), 
           ('SG', 25), 
           ('DP', 26), 
           ('SP', 27), 
           ('SV', 28), 
           ('BL', 29), 
           ('PS', 30), 
           ('PT', 31), 
           ('SI', 32), 
           ('AN', 33), 
           ('NN', 34), 
           ('EL', 35), 
           ('AZ', 36), 
           ('RC', 37), 
           ('R1', 37), 
           ('R2', 37), 
           ('R3', 37), 
           ('R5', 37), 
           ('rc', 38), 
           ('r1', 38), 
           ('r2', 38), 
           ('r3', 38), 
           ('r5', 38), 
           ('1R', 39), 
           ('2R', 39), 
           ('3R', 39), 
           ('5R', 39), 
           ('1r', 40), 
           ('2r', 40), 
           ('3r', 40), 
           ('5r', 40), 
           ('CC', 41), 
           ('C1', 41), 
           ('C2', 41), 
           ('C3', 41), 
           ('C5', 41), 
           ('cc', 42), 
           ('c1', 42), 
           ('c2', 42), 
           ('c3', 42), 
           ('c5', 42), 
           ('PC', 43), 
           ('P1', 43), 
           ('P2', 43), 
           ('P3', 43), 
           ('P5', 43), 
           ('pc', 44), 
           ('p1', 44), 
           ('p2', 44), 
           ('p3', 44), 
           ('p5', 44), 
           ('CP', 45), 
           ('1P', 45), 
           ('2P', 45), 
           ('3P', 45), 
           ('5P', 45), 
           ('cp', 46), 
           ('1p', 46), 
           ('2p', 46), 
           ('3p', 46), 
           ('5p', 46), 
           ('DC', 47), 
           ('D1', 47), 
           ('D2', 47), 
           ('D3', 47), 
           ('D5', 47), 
           ('1d', 48), 
           ('2d', 48), 
           ('3d', 48), 
           ('5d', 48), 
           ('EC', 49), 
           ('E1', 49), 
           ('E2', 49), 
           ('E3', 49), 
           ('E5', 49), 
           ('CE', 50), 
           ('1E', 50), 
           ('2E', 50), 
           ('3E', 50), 
           ('5E', 50), 
           ('FC', 51), 
           ('F1', 51), 
           ('F2', 51), 
           ('F3', 51), 
           ('F5', 51), 
           ('TC', 52), 
           ('SS', 53), 
           ('ID', 54), 
           ('GA', 55), 
           ('EA', 56), 
           ('NA', 57), 
           ('WA', 58), 
           ('GE', 59), 
           ('NE', 60), 
           ('WE', 61), 
           ('EN', 62), 
           ('GD', 63), 
           ('LD', 64), 
           ('WD', 65), 
           ('ED', 66), 
           ('gC', 67), 
           ('g1', 67), 
           ('g2', 67), 
           ('g3', 67), 
           ('MR', 68), 
           ('mr', 69), 
           ('AR', 70), 
           ('AV', 71), 
           ('IM', 72), 
           ('XA', 73), 
           ('XB', 73), 
           ('ZA', 74), 
           ('ZB', 74), 
           ('YA', 75), 
           ('YB', 75), 
           ('rE', 76), 
           ('rM', 77), 
           ('rV', 78), 
           ('rT', 79), 
           ('RE', 80), 
           ('ER', 81), 
           ('IO', 82), 
           ('==', 83), 
           ('LT', 84), 
           ('>>', 85), 
           ('PM', 86), 
           ('LH', 87), 
           ('BI', 88), 
           ('SE', 89), 
           ('SM', 90), 
           ('TT', 91), 
           ('OO', 92), 
           ('||', 93);

INSERT INTO `messageVariableMeta` (`id`, `name`, `greisType`, `requiredValue`, `idMessageMeta`) 
    VALUES (1, 'id', 'a1', '', 1), 
           (2, 'description', 'a1', '', 1), 
           (3, 'id', 'a1', 'JP', 2), 
           (4, 'majorVer', 'a1', '', 2), 
           (5, 'minorVer', 'a1', '', 2), 
           (6, 'order', 'a1', '', 2), 
           (7, 'cs', 'a1', '', 2), 
           (8, 'tod', 'u4', '', 3), 
           (9, 'cs', 'u1', '', 3), 
           (10, 'tod', 'u4', '', 4), 
           (11, 'cs', 'u1', '', 4), 
           (12, 'year', 'u2', '', 5), 
           (13, 'month', 'u1', '', 5), 
           (14, 'day', 'u1', '', 5), 
           (15, 'base', 'u1', '', 5), 
           (16, 'cs', 'u1', '', 5), 
           (17, 'val', 'f8', '', 6), 
           (18, 'sval', 'f8', '', 6), 
           (19, 'cs', 'u1', '', 6), 
           (20, 'val', 'f4', '', 7), 
           (21, 'sval', 'f4', '', 7), 
           (22, 'cs', 'u1', '', 7), 
           (23, 'acc', 'f4', '', 8), 
           (24, 'cs', 'u1', '', 8), 
           (25, 'tow', 'u4', '', 9), 
           (26, 'wn', 'u2', '', 9), 
           (27, 'cs', 'u1', '', 9), 
           (28, 'val', 'f8', '', 10), 
           (29, 'sval', 'f8', '', 10), 
           (30, 'cs', 'u1', '', 10), 
           (31, 'tod', 'u4', '', 11), 
           (32, 'dn', 'u2', '', 11), 
           (33, 'cs', 'u1', '', 11), 
           (34, 'val', 'f8', '', 12), 
           (35, 'sval', 'f8', '', 12), 
           (36, 'cs', 'u1', '', 12), 
           (37, 'val', 'f8', '', 13), 
           (38, 'sval', 'f8', '', 13), 
           (39, 'cs', 'u1', '', 13), 
           (40, 'val', 'f8', '', 14), 
           (41, 'sval', 'f8', '', 14), 
           (42, 'cs', 'u1', '', 14), 
           (43, 'utc', 'UtcOffs', '', 15), 
           (44, 'cs', 'u1', '', 15), 
           (45, 'utc', 'UtcOffs', '', 16), 
           (46, 'utcsi', 'i1', '', 16), 
           (47, 'tow', 'u4', '', 16), 
           (48, 'wn', 'u2', '', 16), 
           (49, 'flags', 'u1', '', 16), 
           (50, 'cs', 'u1', '', 16), 
           (51, 'utc', 'UtcOffs', '', 17), 
           (52, 'a0g', 'f4', '', 17), 
           (53, 'a1g', 'f4', '', 17), 
           (54, 't0g', 'u4', '', 17), 
           (55, 'wn0g', 'u2', '', 17), 
           (56, 'flags', 'u2', '', 17), 
           (57, 'cs', 'u1', '', 17), 
           (58, 'tauSys', 'f8', '', 18), 
           (59, 'tauGps', 'f4', '', 18), 
           (60, 'B1', 'f4', '', 18), 
           (61, 'B2', 'f4', '', 18), 
           (62, 'KP', 'u1', '', 18), 
           (63, 'N4', 'u1', '', 18), 
           (64, 'Dn', 'i2', '', 18), 
           (65, 'cs', 'u1', '', 18), 
           (66, 'time', 'u4', '', 19), 
           (67, 'solType', 'u1', '', 19), 
           (68, 'cs', 'u1', '', 19), 
           (69, 'x', 'f8', '', 20), 
           (70, 'y', 'f8', '', 20), 
           (71, 'z', 'f8', '', 20), 
           (72, 'sigma', 'f4', '', 20), 
           (73, 'solType', 'u1', '', 20), 
           (74, 'cs', 'u1', '', 20), 
           (75, 'x', 'f4', '', 21), 
           (76, 'y', 'f4', '', 21), 
           (77, 'z', 'f4', '', 21), 
           (78, 'sigma', 'f4', '', 21), 
           (79, 'solType', 'u1', '', 21), 
           (80, 'cs', 'u1', '', 21), 
           (81, 'x', 'f8', '', 22), 
           (82, 'y', 'f8', '', 22), 
           (83, 'z', 'f8', '', 22), 
           (84, 'pSigma', 'f4', '', 22), 
           (85, 'vx', 'f4', '', 22), 
           (86, 'vy', 'f4', '', 22), 
           (87, 'vz', 'f4', '', 22), 
           (88, 'vSigma', 'f4', '', 22), 
           (89, 'solType', 'u1', '', 22), 
           (90, 'cs', 'u1', '', 22), 
           (91, 'lat', 'f8', '', 23), 
           (92, 'lon', 'f8', '', 23), 
           (93, 'alt', 'f8', '', 23), 
           (94, 'pSigma', 'f4', '', 23), 
           (95, 'solType', 'u1', '', 23), 
           (96, 'cs', 'u1', '', 23), 
           (97, 'lat', 'f4', '', 24), 
           (98, 'lon', 'f4', '', 24), 
           (99, 'alt', 'f4', '', 24), 
           (100, 'pSigma', 'f4', '', 24), 
           (101, 'solType', 'u1', '', 24), 
           (102, 'cs', 'u1', '', 24), 
           (103, 'hpos', 'f4', '', 25), 
           (104, 'vpos', 'f4', '', 25), 
           (105, 'hvel', 'f4', '', 25), 
           (106, 'vvel', 'f4', '', 25), 
           (107, 'solType', 'u1', '', 25), 
           (108, 'cs', 'u1', '', 25), 
           (109, 'hdop', 'f4', '', 26), 
           (110, 'vdop', 'f4', '', 26), 
           (111, 'tdop', 'f4', '', 26), 
           (112, 'solType', 'u1', '', 26), 
           (113, 'cs', 'u1', '', 26), 
           (114, 'xx', 'f4', '', 27), 
           (115, 'yy', 'f4', '', 27), 
           (116, 'zz', 'f4', '', 27), 
           (117, 'tt', 'f4', '', 27), 
           (118, 'xy', 'f4', '', 27), 
           (119, 'xz', 'f4', '', 27), 
           (120, 'xt', 'f4', '', 27), 
           (121, 'yz', 'f4', '', 27), 
           (122, 'yt', 'f4', '', 27), 
           (123, 'zt', 'f4', '', 27), 
           (124, 'solType', 'u1', '', 27), 
           (125, 'cs', 'u1', '', 27), 
           (126, 'xx', 'f4', '', 28), 
           (127, 'yy', 'f4', '', 28), 
           (128, 'zz', 'f4', '', 28), 
           (129, 'tt', 'f4', '', 28), 
           (130, 'xy', 'f4', '', 28), 
           (131, 'xz', 'f4', '', 28), 
           (132, 'xt', 'f4', '', 28), 
           (133, 'yz', 'f4', '', 28), 
           (134, 'yt', 'f4', '', 28), 
           (135, 'zt', 'f4', '', 28), 
           (136, 'solType', 'u1', '', 28), 
           (137, 'cs', 'u1', '', 28), 
           (138, 'x', 'f8', '', 29), 
           (139, 'y', 'f8', '', 29), 
           (140, 'z', 'f8', '', 29), 
           (141, 'sigma', 'f4', '', 29), 
           (142, 'solType', 'u1', '', 29), 
           (143, 'time', 'i4', '', 29), 
           (144, 'cs', 'u1', '', 29), 
           (145, 'solType', 'u1', '', 30), 
           (146, 'gpsLocked', 'u1', '', 30), 
           (147, 'gloLocked', 'u1', '', 30), 
           (148, 'gpsAvail', 'u1', '', 30), 
           (149, 'gloAvail', 'u1', '', 30), 
           (150, 'gpsUsed', 'u1', '', 30), 
           (151, 'gloUsed', 'u1', '', 30), 
           (152, 'fixProg', 'u1', '', 30), 
           (153, 'cs', 'u1', '', 30), 
           (154, 'pt', 'u4', '', 31), 
           (155, 'cs', 'u1', '', 31), 
           (156, 'usi', 'u1', '', 32), 
           (157, 'cs', 'u1', '', 32), 
           (158, 'name', 'a1', '', 33), 
           (159, 'cs', 'u1', '', 33), 
           (160, 'osn', 'u1', '', 34), 
           (161, 'cs', 'u1', '', 34), 
           (162, 'elev', 'i1', '', 35), 
           (163, 'cs', 'u1', '', 35), 
           (164, 'azim', 'u1', '', 36), 
           (165, 'cs', 'u1', '', 36), 
           (166, 'pr', 'f8', '', 37), 
           (167, 'cs', 'u1', '', 37), 
           (168, 'spr', 'i4', '', 38), 
           (169, 'cs', 'u1', '', 38), 
           (170, 'rpr', 'f4', '', 39), 
           (171, 'cs', 'u1', '', 39), 
           (172, 'srpr', 'i2', '', 40), 
           (173, 'cs', 'u1', '', 40), 
           (174, 'smooth', 'Smooth', '', 41), 
           (175, 'cs', 'u1', '', 41), 
           (176, 'smooth', 'i2', '', 42), 
           (177, 'cs', 'u1', '', 42), 
           (178, 'cp', 'f8', '', 43), 
           (179, 'cs', 'u1', '', 43), 
           (180, 'scp', 'u4', '', 44), 
           (181, 'cs', 'u1', '', 44), 
           (182, 'rcp', 'f4', '', 45), 
           (183, 'cs', 'u1', '', 45), 
           (184, 'rcp', 'i4', '', 46), 
           (185, 'cs', 'u1', '', 46), 
           (186, 'dp', 'i4', '', 47), 
           (187, 'cs', 'u1', '', 47), 
           (188, 'srdp', 'i2', '', 48), 
           (189, 'cs', 'u1', '', 48), 
           (190, 'cnr', 'u1', '', 49), 
           (191, 'cs', 'u1', '', 49), 
           (192, 'cnrX4', 'u1', '', 50), 
           (193, 'cs', 'u1', '', 50), 
           (194, 'flags', 'u2', '', 51), 
           (195, 'cs', 'u1', '', 51), 
           (196, 'tt', 'u2', '', 52), 
           (197, 'cs', 'u1', '', 52), 
           (198, 'ns', 'u1', '', 53), 
           (199, 'solType', 'u1', '', 53), 
           (200, 'cs', 'u1', '', 53), 
           (201, 'delay', 'f4', '', 54), 
           (202, 'cs', 'u1', '', 54), 
           (203, 'sv', 'u1', '', 55), 
           (204, 'wna', 'i2', '', 55), 
           (205, 'toa', 'i4', '', 55), 
           (206, 'healthA', 'u1', '', 55), 
           (207, 'healthS', 'u1', '', 55), 
           (208, 'config', 'u1', '', 55), 
           (209, 'af1', 'f4', '', 55), 
           (210, 'af0', 'f4', '', 55), 
           (211, 'rootA', 'f4', '', 55), 
           (212, 'ecc', 'f4', '', 55), 
           (213, 'm0', 'f4', '', 55), 
           (214, 'omega0', 'f4', '', 55), 
           (215, 'argPer', 'f4', '', 55), 
           (216, 'deli', 'f4', '', 55), 
           (217, 'omegaDot', 'f4', '', 55), 
           (218, 'cs', 'u1', '', 55), 
           (219, 'gps', 'GPSAlm1', '', 56), 
           (220, 'iod', 'i2', '', 56), 
           (221, 'cs', 'u1', '', 56), 
           (222, 'sv', 'u1', '', 57), 
           (223, 'frqNum', 'i1', '', 57), 
           (224, 'dna', 'i2', '', 57), 
           (225, 'tlam', 'f4', '', 57), 
           (226, 'flags', 'u1', '', 57), 
           (227, 'tauN', 'f4', '', 57), 
           (228, 'tauSys', 'f8', '', 57), 
           (229, 'ecc', 'f4', '', 57), 
           (230, 'lambda', 'f4', '', 57), 
           (231, 'argPer', 'f4', '', 57), 
           (232, 'delT', 'f4', '', 57), 
           (233, 'delTdt', 'f4', '', 57), 
           (234, 'deli', 'f4', '', 57), 
           (235, 'cs', 'u1', '', 57), 
           (236, 'waasPrn', 'u1', '', 58), 
           (237, 'gpsPrn', 'u1', '', 58), 
           (238, 'id', 'u1', '', 58), 
           (239, 'healthS', 'u1', '', 58), 
           (240, 'tod', 'u4', '', 58), 
           (241, 'xg', 'f8', '', 58), 
           (242, 'yg', 'f8', '', 58), 
           (243, 'zg', 'f8', '', 58), 
           (244, 'vxg', 'f4', '', 58), 
           (245, 'vyg', 'f4', '', 58), 
           (246, 'vzg', 'f4', '', 58), 
           (247, 'tow', 'u4', '', 58), 
           (248, 'wn', 'u2', '', 58), 
           (249, 'cs', 'u1', '', 58), 
           (250, 'sv', 'u1', '', 59), 
           (251, 'tow', 'u4', '', 59), 
           (252, 'flags', 'u1', '', 59), 
           (253, 'iodc', 'i2', '', 59), 
           (254, 'toc', 'i4', '', 59), 
           (255, 'ura', 'i1', '', 59), 
           (256, 'healthS', 'u1', '', 59), 
           (257, 'wn', 'i2', '', 59), 
           (258, 'tgd', 'f4', '', 59), 
           (259, 'af2', 'f4', '', 59), 
           (260, 'af1', 'f4', '', 59), 
           (261, 'af0', 'f4', '', 59), 
           (262, 'toe', 'i4', '', 59), 
           (263, 'iode', 'i2', '', 59), 
           (264, 'rootA', 'f8', '', 59), 
           (265, 'ecc', 'f8', '', 59), 
           (266, 'm0', 'f8', '', 59), 
           (267, 'omega0', 'f8', '', 59), 
           (268, 'inc0', 'f8', '', 59), 
           (269, 'argPer', 'f8', '', 59), 
           (270, 'deln', 'f4', '', 59), 
           (271, 'omegaDot', 'f4', '', 59), 
           (272, 'incDot', 'f4', '', 59), 
           (273, 'crc', 'f4', '', 59), 
           (274, 'crs', 'f4', '', 59), 
           (275, 'cuc', 'f4', '', 59), 
           (276, 'cus', 'f4', '', 59), 
           (277, 'cic', 'f4', '', 59), 
           (278, 'cis', 'f4', '', 59), 
           (279, 'cs', 'u1', '', 59), 
           (280, 'sv', 'u1', '', 60), 
           (281, 'frqNum', 'i1', '', 60), 
           (282, 'dne', 'i2', '', 60), 
           (283, 'tk', 'i4', '', 60), 
           (284, 'tb', 'i4', '', 60), 
           (285, 'health', 'u1', '', 60), 
           (286, 'age', 'u1', '', 60), 
           (287, 'flags', 'u1', '', 60), 
           (288, 'r', 'f8', '', 60), 
           (289, 'v', 'f4', '', 60), 
           (290, 'w', 'f4', '', 60), 
           (291, 'tauSys', 'f8', '', 60), 
           (292, 'tau', 'f4', '', 60), 
           (293, 'gamma', 'f4', '', 60), 
           (294, 'fDelTauN', 'f4', '', 60), 
           (295, 'nFt', 'u1', '', 60), 
           (296, 'nN4', 'u1', '', 60), 
           (297, 'flags2', 'u2', '', 60), 
           (298, 'cs', 'u1', '', 60), 
           (299, 'waasPrn', 'u1', '', 61), 
           (300, 'gpsPrn', 'u1', '', 61), 
           (301, 'iod', 'u1', '', 61), 
           (302, 'acc', 'u1', '', 61), 
           (303, 'tod', 'u4', '', 61), 
           (304, 'xg', 'f8', '', 61), 
           (305, 'yg', 'f8', '', 61), 
           (306, 'zg', 'f8', '', 61), 
           (307, 'vxg', 'f4', '', 61), 
           (308, 'vyg', 'f4', '', 61), 
           (309, 'vzg', 'f4', '', 61), 
           (310, 'vvxg', 'f4', '', 61), 
           (311, 'vvyg', 'f4', '', 61), 
           (312, 'vvzg', 'f4', '', 61), 
           (313, 'agf0', 'f4', '', 61), 
           (314, 'agf1', 'f4', '', 61), 
           (315, 'tow', 'u4', '', 61), 
           (316, 'wn', 'u2', '', 61), 
           (317, 'cs', 'u1', '', 61), 
           (318, 'gps', 'GPSEphemeris1', '', 62), 
           (319, 'bgdE1E5a', 'f4', '', 62), 
           (320, 'bgdE1E5b', 'f4', '', 62), 
           (321, 'ai0', 'f4', '', 62), 
           (322, 'ai1', 'f4', '', 62), 
           (323, 'ai2', 'f4', '', 62), 
           (324, 'sfi', 'u1', '', 62), 
           (325, 'navType', 'u1', '', 62), 
           (326, 'cs', 'u1', '', 62), 
           (327, 'recSize', 'u1', '', 63), 
           (328, 'dat', 'SvData0', '', 63), 
           (329, 'cs', 'u1', '', 63), 
           (330, 'recSize', 'u1', '', 64), 
           (331, 'dat', 'SvData1', '', 64), 
           (332, 'cs', 'u1', '', 64), 
           (333, 'prn', 'u1', '', 65), 
           (334, 'time', 'u4', '', 65), 
           (335, 'reserv', 'u2', '', 65), 
           (336, 'data', 'u1', '', 65), 
           (337, 'cs', 'u1', '', 65), 
           (338, 'prn', 'u1', '', 66), 
           (339, 'time', 'u4', '', 66), 
           (340, 'type', 'u1', '', 66), 
           (341, 'len', 'u1', '', 66), 
           (342, 'data', 'u1', '', 66), 
           (343, 'cs', 'u1', '', 66), 
           (344, 'fcn', 'i1', '', 67), 
           (345, 'phase', 'f4', '', 67), 
           (346, 'range', 'f4', '', 67), 
           (347, 'cs', 'u1', '', 67), 
           (348, 'time', 'u4', '', 68), 
           (349, 'q00', 'f4', '', 68), 
           (350, 'q01', 'f4', '', 68), 
           (351, 'q02', 'f4', '', 68), 
           (352, 'q12', 'f4', '', 68), 
           (353, 'rms', 'f4', '', 68), 
           (354, 'solType', 'u1', '', 68), 
           (355, 'flag', 'u1', '', 68), 
           (356, 'cs', 'u1', '', 68), 
           (357, 'time', 'u4', '', 69), 
           (358, 'q00', 'f4', '', 69), 
           (359, 'q01', 'f4', '', 69), 
           (360, 'q02', 'f4', '', 69), 
           (361, 'q12', 'f4', '', 69), 
           (362, 'rms', 'f4', '', 69), 
           (363, 'solType', 'u1', '', 69), 
           (364, 'flag', 'u1', '', 69), 
           (365, 'bl0', 'f4', '', 69), 
           (366, 'bl1', 'f4', '', 69), 
           (367, 'bl2', 'f4', '', 69), 
           (368, 'cs', 'u1', '', 69), 
           (369, 'time', 'u4', '', 70), 
           (370, 'pitch', 'f4', '', 70), 
           (371, 'roll', 'f4', '', 70), 
           (372, 'heading', 'f4', '', 70), 
           (373, 'pitchRms', 'f4', '', 70), 
           (374, 'rollRms', 'f4', '', 70), 
           (375, 'headingRms', 'f4', '', 70), 
           (376, 'flags', 'u1', '', 70), 
           (377, 'cs', 'u1', '', 70), 
           (378, 'time', 'u4', '', 71), 
           (379, 'x', 'f4', '', 71), 
           (380, 'y', 'f4', '', 71), 
           (381, 'z', 'f4', '', 71), 
           (382, 'rms', 'f4', '', 71), 
           (383, 'flags', 'u1', '', 71), 
           (384, 'cs', 'u1', '', 71), 
           (385, 'accelerations', 'f4', '', 72), 
           (386, 'angularVelocities', 'f4', '', 72), 
           (387, 'cs', 'u1', '', 72), 
           (388, 'ms', 'i4', '', 73), 
           (389, 'ns', 'i4', '', 73), 
           (390, 'timeScale', 'u1', '', 73), 
           (391, 'cs', 'u1', '', 73), 
           (392, 'offs', 'f4', '', 74), 
           (393, 'cs', 'u1', '', 74), 
           (394, 'offs', 'f8', '', 75), 
           (395, 'timeScale', 'u1', '', 75), 
           (396, 'cs', 'u1', '', 75), 
           (397, 'sample', 'u2', '', 76), 
           (398, 'scale', 'u2', '', 76), 
           (399, 'reftime', 'u4', '', 76), 
           (400, 'crc16', 'u2', '', 76), 
           (401, 'sample', 'u2', '', 77), 
           (402, 'scale', 'u2', '', 77), 
           (403, 'reftime', 'u4', '', 77), 
           (404, 'clock', 'i2', '', 77), 
           (405, 'flags', 'u2', '', 77), 
           (406, 'svd', 'SvData2', '', 77), 
           (407, 'crc16', 'u2', '', 77), 
           (408, 'sample', 'u2', '', 78), 
           (409, 'delta', 'u2', '', 78), 
           (410, 'word1', 'u4', '', 78), 
           (411, 'word2', 'u4', '', 78), 
           (412, 'word3', 'u4', '', 78), 
           (413, 'word4', 'u4', '', 78), 
           (414, 'word5', 'u4', '', 78), 
           (415, 'word6', 'u4', '', 78), 
           (416, 'word7', 'u4', '', 78), 
           (417, 'word8', 'u4', '', 78), 
           (418, 'word9', 'u4', '', 78), 
           (419, 'crc16', 'u2', '', 78), 
           (420, 'sample', 'u2', '', 79), 
           (421, 'reserved', 'u2', '', 79), 
           (422, 'recSize', 'u1', '', 79), 
           (423, 'Offs', 'ClkOffs', '', 79), 
           (424, 'crc16', 'u2', '', 79), 
           (425, 'reply', 'a1', '', 80), 
           (426, 'error', 'a1', '', 81), 
           (427, 'tot', 'u4', '', 82), 
           (428, 'wn', 'u2', '', 82), 
           (429, 'alpha0', 'f4', '', 82), 
           (430, 'alpha1', 'f4', '', 82), 
           (431, 'alpha2', 'f4', '', 82), 
           (432, 'alpha3', 'f4', '', 82), 
           (433, 'beta0', 'f4', '', 82), 
           (434, 'beta1', 'f4', '', 82), 
           (435, 'beta2', 'f4', '', 82), 
           (436, 'beta3', 'f4', '', 82), 
           (437, 'cs', 'u1', '', 82), 
           (438, 'time', 'u4', '', 83), 
           (439, 'type', 'u1', '', 83), 
           (440, 'data', 'u1', '', 83), 
           (441, 'cs', 'u1', '', 83), 
           (442, 'lt', 'u1', '', 84), 
           (443, 'cs', 'u1', '', 84), 
           (444, 'id', 'u1', '', 85), 
           (445, 'data', 'u1', '', 85), 
           (446, 'cs', 'a1', '', 85), 
           (447, 'params', 'a1', '', 86), 
           (448, 'delim', 'a1', ',@', 86), 
           (449, 'cs', 'a1', '', 86), 
           (450, 'svsCount', 'u1', '', 87), 
           (451, 'targetStream', 'u1', '', 87), 
           (452, 'issue', 'u2', '', 87), 
           (453, 'bitsCount', 'u2', '', 87), 
           (454, 'lastBitTime', 'u4', '', 87), 
           (455, 'uids', 'u1', '', 87), 
           (456, 'pad', 'u1', '', 87), 
           (457, 'hist', 'u4', '', 87), 
           (458, 'x', 'f8', '', 88), 
           (459, 'y', 'f8', '', 88), 
           (460, 'z', 'f8', '', 88), 
           (461, 'id', 'u2', '', 88), 
           (462, 'solType', 'u1', '', 88), 
           (463, 'cs', 'u1', '', 88), 
           (464, 'data', 'u1', '', 89), 
           (465, 'cs', 'u1', '', 89), 
           (466, 'data', 'u1', '', 90), 
           (467, 'crc16', 'u2', '', 90), 
           (468, 'tt', 'u4', '', 91), 
           (469, 'cs', 'u1', '', 91), 
           (470, 'val', 'f4', '', 92), 
           (471, 'cs', 'u1', '', 92), 
           (472, 'cs', 'u1', '', 93);

INSERT INTO `customTypeVariableMeta` (`id`, `name`, `greisType`, `requiredValue`, `idCustomTypeMeta`) 
    VALUES (1, 'a0', 'f8', '', 1), 
           (2, 'a1', 'f4', '', 1), 
           (3, 'tot', 'u4', '', 1), 
           (4, 'wnt', 'u2', '', 1), 
           (5, 'dtls', 'i1', '', 1), 
           (6, 'dn', 'u1', '', 1), 
           (7, 'wnlsf', 'u2', '', 1), 
           (8, 'dtlsf', 'i1', '', 1), 
           (9, 'value', 'f4', '', 2), 
           (10, 'interval', 'u2', '', 2), 
           (11, 'prn', 'i1', '', 3), 
           (12, 'cnt', 'u1', '', 3), 
           (13, 'data', 'u4', '', 3), 
           (14, 'fcn1', 'i1', '', 4), 
           (15, 'cnt', 'u1', '', 4), 
           (16, 'data', 'u4', '', 4), 
           (17, 'header', 'Header', '', 5), 
           (18, 'slot', 'SlotRec', '', 5), 
           (19, 'refrange', 'u4', '', 6), 
           (20, 'usi', 'u1', '', 6), 
           (21, 'num', 'u1', '', 6), 
           (22, 'svstOrDelrange', 'i2', '', 7), 
           (23, 'word1', 'u4', '', 7), 
           (24, 'flags', 'u2', '', 7), 
           (25, 'lock', 'u2', '', 7), 
           (26, 'word2', 'u4', '', 7), 
           (27, 'word1', 'u4', '', 8), 
           (28, 'word2', 'u4', '', 8), 
           (29, 'sv', 'u1', '', 9), 
           (30, 'wna', 'i2', '', 9), 
           (31, 'toa', 'i4', '', 9), 
           (32, 'healthA', 'u1', '', 9), 
           (33, 'healthS', 'u1', '', 9), 
           (34, 'config', 'u1', '', 9), 
           (35, 'af1', 'f4', '', 9), 
           (36, 'af0', 'f4', '', 9), 
           (37, 'rootA', 'f4', '', 9), 
           (38, 'ecc', 'f4', '', 9), 
           (39, 'm0', 'f4', '', 9), 
           (40, 'omega0', 'f4', '', 9), 
           (41, 'argPer', 'f4', '', 9), 
           (42, 'deli', 'f4', '', 9), 
           (43, 'omegaDot', 'f4', '', 9), 
           (44, 'sv', 'u1', '', 10), 
           (45, 'tow', 'u4', '', 10), 
           (46, 'flags', 'u1', '', 10), 
           (47, 'iodc', 'i2', '', 10), 
           (48, 'toc', 'i4', '', 10), 
           (49, 'ura', 'i1', '', 10), 
           (50, 'healthS', 'u1', '', 10), 
           (51, 'wn', 'i2', '', 10), 
           (52, 'tgd', 'f4', '', 10), 
           (53, 'af2', 'f4', '', 10), 
           (54, 'af1', 'f4', '', 10), 
           (55, 'af0', 'f4', '', 10), 
           (56, 'toe', 'i4', '', 10), 
           (57, 'iode', 'i2', '', 10), 
           (58, 'rootA', 'f8', '', 10), 
           (59, 'ecc', 'f8', '', 10), 
           (60, 'm0', 'f8', '', 10), 
           (61, 'omega0', 'f8', '', 10), 
           (62, 'inc0', 'f8', '', 10), 
           (63, 'argPer', 'f8', '', 10), 
           (64, 'deln', 'f4', '', 10), 
           (65, 'omegaDot', 'f4', '', 10), 
           (66, 'incDot', 'f4', '', 10), 
           (67, 'crc', 'f4', '', 10), 
           (68, 'crs', 'f4', '', 10), 
           (69, 'cuc', 'f4', '', 10), 
           (70, 'cus', 'f4', '', 10), 
           (71, 'cic', 'f4', '', 10), 
           (72, 'cis', 'f4', '', 10);

-- Наполнение информации о размерностях для пользовательского типа `SvData0`
INSERT INTO `customTypeVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (13, 1, 10);

-- Наполнение информации о размерностях для пользовательского типа `SvData1`
INSERT INTO `customTypeVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (16, 1, 4);

-- Наполнение информации о размерностях для пользовательского типа `SvData2`
INSERT INTO `customTypeVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (18, 1, -2);

-- Наполнение информации о размерностях для сообщения `FileId`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (1, 1, 5), 
           (2, 1, 80);

-- Наполнение информации о размерностях для сообщения `MsgFmt`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (3, 1, 2), 
           (4, 1, 2), 
           (5, 1, 2), 
           (7, 1, 2);

-- Наполнение информации о размерностях для сообщения `SatIndex`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (156, 1, -2);

-- Наполнение информации о размерностях для сообщения `AntName`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (158, 1, -2);

-- Наполнение информации о размерностях для сообщения `SatNumbers`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (160, 1, -2);

-- Наполнение информации о размерностях для сообщения `SatElevation`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (162, 1, -2);

-- Наполнение информации о размерностях для сообщения `SatAzimuth`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (164, 1, -2);

-- Наполнение информации о размерностях для сообщения `PR`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (166, 1, -2);

-- Наполнение информации о размерностях для сообщения `SPR`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (168, 1, -2);

-- Наполнение информации о размерностях для сообщения `RPR`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (170, 1, -2);

-- Наполнение информации о размерностях для сообщения `SRPR`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (172, 1, -2);

-- Наполнение информации о размерностях для сообщения `SC`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (174, 1, -2);

-- Наполнение информации о размерностях для сообщения `SS`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (176, 1, -2);

-- Наполнение информации о размерностях для сообщения `CP`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (178, 1, -2);

-- Наполнение информации о размерностях для сообщения `SCP`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (180, 1, -2);

-- Наполнение информации о размерностях для сообщения `RCP_RC`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (182, 1, -2);

-- Наполнение информации о размерностях для сообщения `RCP_rc`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (184, 1, -2);

-- Наполнение информации о размерностях для сообщения `DP`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (186, 1, -2);

-- Наполнение информации о размерностях для сообщения `SRDP`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (188, 1, -2);

-- Наполнение информации о размерностях для сообщения `CNR`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (190, 1, -2);

-- Наполнение информации о размерностях для сообщения `CNR_4`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (192, 1, -2);

-- Наполнение информации о размерностях для сообщения `Flags`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (194, 1, -2);

-- Наполнение информации о размерностях для сообщения `TrackingTimeCA`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (196, 1, -2);

-- Наполнение информации о размерностях для сообщения `NavStatus`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (198, 1, -2);

-- Наполнение информации о размерностях для сообщения `IonoDelay`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (201, 1, -2);

-- Наполнение информации о размерностях для сообщения `GLOEphemeris`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (288, 1, 3), 
           (289, 1, 3), 
           (290, 1, 3);

-- Наполнение информации о размерностях для сообщения `GpsNavData`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (328, 1, -2);

-- Наполнение информации о размерностях для сообщения `GloNavData`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (331, 1, -2);

-- Наполнение информации о размерностях для сообщения `WAASRawMessage`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (336, 1, 32);

-- Наполнение информации о размерностях для сообщения `GALRawMessage`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (342, 1, -2);

-- Наполнение информации о размерностях для сообщения `GloPhaseDelay`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (344, 1, -2), 
           (345, 1, -2), 
           (346, 1, -2);

-- Наполнение информации о размерностях для сообщения `RotationMatrix`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (353, 1, 3), 
           (354, 1, 3);

-- Наполнение информации о размерностях для сообщения `RotationMatrixAndVectors`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (362, 1, 3), 
           (363, 1, 3), 
           (365, 1, 3), 
           (366, 1, 3), 
           (367, 1, 3);

-- Наполнение информации о размерностях для сообщения `InertialMeasurements`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (385, 1, 3), 
           (386, 1, 3);

-- Наполнение информации о размерностях для сообщения `RawMeas`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (406, 1, -2);

-- Наполнение информации о размерностях для сообщения `ClockOffsets`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (423, 1, -2);

-- Наполнение информации о размерностях для сообщения `RE`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (425, 1, -2);

-- Наполнение информации о размерностях для сообщения `ER`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (426, 1, -2);

-- Наполнение информации о размерностях для сообщения `Event`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (440, 1, -2);

-- Наполнение информации о размерностях для сообщения `Wrapper`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (445, 1, -2), 
           (446, 1, 2);

-- Наполнение информации о размерностях для сообщения `Params`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (447, 1, -2), 
           (448, 1, 2), 
           (449, 1, 2);

-- Наполнение информации о размерностях для сообщения `LoggingHistory`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (455, 1, -2), 
           (456, 1, -2), 
           (457, 1, -2), 
           (457, 2, -2);

-- Наполнение информации о размерностях для сообщения `Security`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (464, 1, 5);

-- Наполнение информации о размерностях для сообщения `Security`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (466, 1, 6);



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
