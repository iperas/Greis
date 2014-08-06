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
DROP TABLE IF EXISTS `msg_RcvSBASTimeOffset`;
DROP TABLE IF EXISTS `msg_RcvQZSSTimeOffset`;
DROP TABLE IF EXISTS `msg_GpsUtcParam`;
DROP TABLE IF EXISTS `msg_SbasUtcParam`;
DROP TABLE IF EXISTS `msg_GalUtcGpsParam`;
DROP TABLE IF EXISTS `msg_QzssUtcParam`;
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
DROP TABLE IF EXISTS `msg_Baseline`;
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
DROP TABLE IF EXISTS `msg_IAmp`;
DROP TABLE IF EXISTS `msg_QAmp`;
DROP TABLE IF EXISTS `msg_TrackingTimeCA`;
DROP TABLE IF EXISTS `msg_NavStatus`;
DROP TABLE IF EXISTS `msg_IonoDelay`;
DROP TABLE IF EXISTS `msg_GPSAlm0`;
DROP TABLE IF EXISTS `msg_GALAlm`;
DROP TABLE IF EXISTS `msg_QZSSAlm`;
DROP TABLE IF EXISTS `msg_GLOAlmanac`;
DROP TABLE IF EXISTS `msg_SBASAlmanac`;
DROP TABLE IF EXISTS `msg_GPSEphemeris0`;
DROP TABLE IF EXISTS `msg_GALEphemeris`;
DROP TABLE IF EXISTS `msg_QZSSEphemeris`;
DROP TABLE IF EXISTS `msg_GLOEphemeris`;
DROP TABLE IF EXISTS `msg_SBASEhemeris`;
DROP TABLE IF EXISTS `msg_GpsNavData0`;
DROP TABLE IF EXISTS `msg_GpsRawNavData0`;
DROP TABLE IF EXISTS `msg_QzssNavData`;
DROP TABLE IF EXISTS `msg_QzssRawNavData`;
DROP TABLE IF EXISTS `msg_GloNavData`;
DROP TABLE IF EXISTS `msg_GloRawNavData`;
DROP TABLE IF EXISTS `msg_SbasRawNavData`;
DROP TABLE IF EXISTS `msg_GalRawNavData`;
DROP TABLE IF EXISTS `msg_CompRawNavData`;
DROP TABLE IF EXISTS `msg_Spectrum0`;
DROP TABLE IF EXISTS `msg_Spectrum1`;
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
DROP TABLE IF EXISTS `msg_IonoParams0`;
DROP TABLE IF EXISTS `msg_QzssIonoParams`;
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
DROP TABLE IF EXISTS `ct_GpsEphReqData`;
DROP TABLE IF EXISTS `ct_SvData0`;
DROP TABLE IF EXISTS `ct_SvData1`;
DROP TABLE IF EXISTS `ct_SpecData`;
DROP TABLE IF EXISTS `ct_ExtSpecData`;
DROP TABLE IF EXISTS `ct_SvData2`;
DROP TABLE IF EXISTS `ct_Header`;
DROP TABLE IF EXISTS `ct_SlotRec`;
DROP TABLE IF EXISTS `ct_ClkOffs`;
DROP TABLE IF EXISTS `ct_GPSAlm1`;
DROP TABLE IF EXISTS `ct_GPSEphemeris1`;
DROP TABLE IF EXISTS `ct_IonoParams1`;
DROP TABLE IF EXISTS `ct_GpsNavData1`;
DROP TABLE IF EXISTS `ct_GpsRawNavData1`;

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

-- custom type 'GpsEphReqData'
CREATE TABLE `ct_GpsEphReqData` (
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
    INDEX `idx_fk_ct_GpsEphReqData_unixTimeEpoch` (`unixTimeEpoch`));

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

-- custom type 'SpecData'
CREATE TABLE `ct_SpecData` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `spec` BLOB, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_ct_SpecData_unixTimeEpoch` (`unixTimeEpoch`));

-- custom type 'ExtSpecData'
CREATE TABLE `ct_ExtSpecData` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `spec` BLOB, 
    `agcmin` BLOB, 
    `agcmax` BLOB, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_ct_ExtSpecData_unixTimeEpoch` (`unixTimeEpoch`));

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
    `req` BIGINT UNSIGNED, 
    `cNavType` TINYINT UNSIGNED, 
    `lTope` INT, 
    `lTopc` INT, 
    `dADot` DOUBLE, 
    `fDelnDot` FLOAT, 
    `cURAoe` TINYINT, 
    `cURAoc` TINYINT, 
    `cURAoc1` TINYINT, 
    `cURAoc2` TINYINT, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_ct_GPSEphemeris1_unixTimeEpoch` (`unixTimeEpoch`));

-- custom type 'IonoParams1'
CREATE TABLE `ct_IonoParams1` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
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
    INDEX `idx_fk_ct_IonoParams1_unixTimeEpoch` (`unixTimeEpoch`));

-- custom type 'GpsNavData1'
CREATE TABLE `ct_GpsNavData1` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `recSize` TINYINT UNSIGNED, 
    `dat` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_ct_GpsNavData1_unixTimeEpoch` (`unixTimeEpoch`));

-- custom type 'GpsRawNavData1'
CREATE TABLE `ct_GpsRawNavData1` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `prn` TINYINT UNSIGNED, 
    `time` INT UNSIGNED, 
    `type` TINYINT UNSIGNED, 
    `len` TINYINT UNSIGNED, 
    `data` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_ct_GpsRawNavData1_unixTimeEpoch` (`unixTimeEpoch`));

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

-- message 'RcvSBASTimeOffset': [WO] WAAS/EGNOS to Receiver Time Offset
CREATE TABLE `msg_RcvSBASTimeOffset` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `val` DOUBLE, 
    `sval` DOUBLE, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RcvSBASTimeOffset_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_RcvSBASTimeOffset_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_RcvSBASTimeOffset_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_RcvSBASTimeOffset_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_RcvSBASTimeOffset_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'RcvQZSSTimeOffset': [QO] QZSS to Receiver Time Offset
CREATE TABLE `msg_RcvQZSSTimeOffset` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `val` DOUBLE, 
    `sval` DOUBLE, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RcvQZSSTimeOffset_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_RcvQZSSTimeOffset_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_RcvQZSSTimeOffset_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_RcvQZSSTimeOffset_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_RcvQZSSTimeOffset_idMessageCode` FOREIGN KEY (`idMessageCode`) 
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

-- message 'SbasUtcParam': [WU] WAAS/EGNOS UTC Time Parameters
CREATE TABLE `msg_SbasUtcParam` (
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
    INDEX `idx_fk_msg_SbasUtcParam_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_SbasUtcParam_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_SbasUtcParam_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_SbasUtcParam_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_SbasUtcParam_idMessageCode` FOREIGN KEY (`idMessageCode`) 
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

-- message 'QzssUtcParam': [QU] QZSS UTC Time Parameters
CREATE TABLE `msg_QzssUtcParam` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `utc` BIGINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_QzssUtcParam_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_QzssUtcParam_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_QzssUtcParam_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_QzssUtcParam_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_QzssUtcParam_idMessageCode` FOREIGN KEY (`idMessageCode`) 
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

-- message 'Baseline': [BL] Baseline
CREATE TABLE `msg_Baseline` (
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
    INDEX `idx_fk_msg_Baseline_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_Baseline_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_Baseline_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_Baseline_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_Baseline_idMessageCode` FOREIGN KEY (`idMessageCode`) 
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

-- message 'PR': [RC], [R1], [R2], [R3], [R5], [Rl]: Pseudoranges
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

-- message 'SPR': [rc], [r1], [r2], [r3], [r5], [rl]: Pseudoranges
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

-- message 'RPR': [1R], [2R], [3R], [5R], [lR]: Relative Pseudoranges
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

-- message 'SRPR': [1r], [2r], [3r], [5r], [lr]: Relative Pseudoranges
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

-- message 'SC': [CC],[C1],[C2],[C3],[C5],[Cl]: Smoothing Corrections
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

-- message 'SS': [cc],[c1],[c2],[c3],[c5],[cl]: Smoothing Corrections
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

-- message 'CP': [PC], [P1], [P2], [P3], [P5], [Pl]: Carrier Phases
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

-- message 'SCP': [pc], [p1], [p2], [p3], [p5], [pl]: Carrier Phases
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

-- message 'RCP_RC': [CP],[1P],[2P],[3P],[5P],[lP]: Relative Carrier Phases
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

-- message 'RCP_rc': [cp],[1p],[2p],[3p],[5p],[lp]: Relative Carrier Phases
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

-- message 'DP': [DC], [D1], [D2], [D3], [D5], [Dl]: Doppler
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

-- message 'SRDP': [1d], [2d], [3d], [5d], [ld]: Relative Doppler
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

-- message 'CNR': [EC], [E1], [E2], [E3], [E5], [El]: SNR
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

-- message 'CNR_4': [CE], [1E], [2E], [3E], [5E], [lE]: SNR x 
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

-- message 'Flags': [FC],[F1],[F2],[F3],[F5],[Fl]: Signal Lock Loop Flags
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

-- message 'IAmp': [ec], [e1], [e2], [e3], [e5]: Raw Inphases (I)
CREATE TABLE `msg_IAmp` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `amp` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_IAmp_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_IAmp_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_IAmp_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_IAmp_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_IAmp_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'QAmp': [qc], [q1], [q2], [q3], [q5]: Raw Quadratures (Q)
CREATE TABLE `msg_QAmp` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `amp` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_QAmp_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_QAmp_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_QAmp_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_QAmp_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_QAmp_idMessageCode` FOREIGN KEY (`idMessageCode`) 
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

-- message 'QZSSAlm': [QA] QZSS Almanac
CREATE TABLE `msg_QZSSAlm` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `gps` BIGINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_QZSSAlm_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_QZSSAlm_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_QZSSAlm_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_QZSSAlm_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_QZSSAlm_idMessageCode` FOREIGN KEY (`idMessageCode`) 
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
    `n4` TINYINT UNSIGNED, 
    `navType` TINYINT UNSIGNED, 
    `gammaN` FLOAT, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_GLOAlmanac_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_GLOAlmanac_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_GLOAlmanac_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_GLOAlmanac_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_GLOAlmanac_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'SBASAlmanac': [WA] WAAS/EGNOS Almanac
CREATE TABLE `msg_SBASAlmanac` (
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
    INDEX `idx_fk_msg_SBASAlmanac_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_SBASAlmanac_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_SBASAlmanac_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_SBASAlmanac_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_SBASAlmanac_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'GPSEphemeris0': [GE] GPS Ephemeris
CREATE TABLE `msg_GPSEphemeris0` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `req` BIGINT UNSIGNED, 
    `cNavType` TINYINT UNSIGNED, 
    `lTope` INT, 
    `lTopc` INT, 
    `dADot` DOUBLE, 
    `fDelnDot` FLOAT, 
    `cURAoe` TINYINT, 
    `cURAoc` TINYINT, 
    `cURAoc1` TINYINT, 
    `cURAoc2` TINYINT, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_GPSEphemeris0_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_GPSEphemeris0_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_GPSEphemeris0_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_GPSEphemeris0_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_GPSEphemeris0_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'GALEphemeris': [EN] GALILEO Ephemeris
CREATE TABLE `msg_GALEphemeris` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `req` BIGINT UNSIGNED, 
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

-- message 'QZSSEphemeris': [QE] QZSS Ephemeris
CREATE TABLE `msg_QZSSEphemeris` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `gps` BIGINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_QZSSEphemeris_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_QZSSEphemeris_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_QZSSEphemeris_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_QZSSEphemeris_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_QZSSEphemeris_idMessageCode` FOREIGN KEY (`idMessageCode`) 
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
    `navType` TINYINT UNSIGNED, 
    `beta` FLOAT, 
    `tauSysDot` FLOAT, 
    `ec` TINYINT UNSIGNED, 
    `ee` TINYINT UNSIGNED, 
    `fc` TINYINT, 
    `fe` TINYINT, 
    `reserv` SMALLINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_GLOEphemeris_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_GLOEphemeris_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_GLOEphemeris_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_GLOEphemeris_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_GLOEphemeris_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'SBASEhemeris': [WE] WAAS/EGNOS Ephemeris
CREATE TABLE `msg_SBASEhemeris` (
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
    `flags` SMALLINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_SBASEhemeris_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_SBASEhemeris_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_SBASEhemeris_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_SBASEhemeris_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_SBASEhemeris_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'GpsNavData0': [GD] GPS Raw Navigation Data (obsolete)
CREATE TABLE `msg_GpsNavData0` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `recSize` TINYINT UNSIGNED, 
    `dat` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_GpsNavData0_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_GpsNavData0_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_GpsNavData0_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_GpsNavData0_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_GpsNavData0_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'GpsRawNavData0': [gd] GPS Raw Navigation Data
CREATE TABLE `msg_GpsRawNavData0` (
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
    INDEX `idx_fk_msg_GpsRawNavData0_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_GpsRawNavData0_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_GpsRawNavData0_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_GpsRawNavData0_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_GpsRawNavData0_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'QzssNavData': [QD] QZSS Raw Navigation Data (obsolete)
CREATE TABLE `msg_QzssNavData` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `data` BIGINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_QzssNavData_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_QzssNavData_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_QzssNavData_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_QzssNavData_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_QzssNavData_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'QzssRawNavData': [qd] QZSS Raw Navigation Data
CREATE TABLE `msg_QzssRawNavData` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `data` BIGINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_QzssRawNavData_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_QzssRawNavData_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_QzssRawNavData_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_QzssRawNavData_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_QzssRawNavData_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'GloNavData': [LD] GLONASS Raw Navigation Data (obsolete)
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

-- message 'GloRawNavData': [lD] GLONASS Raw Navigation Data
CREATE TABLE `msg_GloRawNavData` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `num` TINYINT UNSIGNED, 
    `fcn` TINYINT, 
    `time` INT UNSIGNED, 
    `type` TINYINT UNSIGNED, 
    `len` TINYINT UNSIGNED, 
    `data` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_GloRawNavData_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_GloRawNavData_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_GloRawNavData_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_GloRawNavData_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_GloRawNavData_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'SbasRawNavData': [WD] WAAS/EGNOS Raw Navigation Data
CREATE TABLE `msg_SbasRawNavData` (
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
    INDEX `idx_fk_msg_SbasRawNavData_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_SbasRawNavData_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_SbasRawNavData_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_SbasRawNavData_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_SbasRawNavData_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'GalRawNavData': [ED] GALILEO Raw Navigation Data
CREATE TABLE `msg_GalRawNavData` (
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
    INDEX `idx_fk_msg_GalRawNavData_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_GalRawNavData_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_GalRawNavData_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_GalRawNavData_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_GalRawNavData_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'CompRawNavData': [cd] COMPASS Raw Navigation Data
CREATE TABLE `msg_CompRawNavData` (
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
    INDEX `idx_fk_msg_CompRawNavData_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_CompRawNavData_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_CompRawNavData_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_CompRawNavData_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_CompRawNavData_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'Spectrum0': [sp] Spectrum
CREATE TABLE `msg_Spectrum0` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `currFrq` SMALLINT, 
    `finalFrq` SMALLINT, 
    `n` TINYINT UNSIGNED, 
    `m` TINYINT UNSIGNED, 
    `s` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_Spectrum0_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_Spectrum0_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_Spectrum0_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_Spectrum0_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_Spectrum0_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'Spectrum1': [sP] Extended Spectrum
CREATE TABLE `msg_Spectrum1` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `currFrq` SMALLINT, 
    `finalFrq` SMALLINT, 
    `n` TINYINT UNSIGNED, 
    `m` TINYINT UNSIGNED, 
    `s` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_Spectrum1_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_Spectrum1_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_Spectrum1_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_Spectrum1_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_Spectrum1_idMessageCode` FOREIGN KEY (`idMessageCode`) 
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

-- message 'IonoParams0': [IO] GPS Ionospheric Parameters
CREATE TABLE `msg_IonoParams0` (
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
    INDEX `idx_fk_msg_IonoParams0_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_IonoParams0_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_IonoParams0_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_IonoParams0_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_IonoParams0_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'QzssIonoParams': [QI] QZSS Ionospheric Parameters
CREATE TABLE `msg_QzssIonoParams` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `par` BIGINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_QzssIonoParams_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_QzssIonoParams_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_QzssIonoParams_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_QzssIonoParams_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_QzssIonoParams_idMessageCode` FOREIGN KEY (`idMessageCode`) 
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

-- message 'Security0': [SE] Security
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

-- message 'Security1': [SM] Security for [rM]
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
    VALUES (-3, 'FixedWithOptionalDataBlock'), 
           (-2, 'Fill'), 
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
           (3, 'GpsEphReqData', 122, 'ct_GpsEphReqData'), 
           (4, 'SvData0', 42, 'ct_SvData0'), 
           (5, 'SvData1', 18, 'ct_SvData1'), 
           (6, 'SpecData', -1, 'ct_SpecData'), 
           (7, 'ExtSpecData', -1, 'ct_ExtSpecData'), 
           (8, 'SvData2', -1, 'ct_SvData2'), 
           (9, 'Header', 6, 'ct_Header'), 
           (10, 'SlotRec', 14, 'ct_SlotRec'), 
           (11, 'ClkOffs', 8, 'ct_ClkOffs'), 
           (12, 'GPSAlm1', 46, 'ct_GPSAlm1'), 
           (13, 'GPSEphemeris1', -4, 'ct_GPSEphemeris1'), 
           (14, 'IonoParams1', 39, 'ct_IonoParams1'), 
           (15, 'GpsNavData1', -2, 'ct_GpsNavData1'), 
           (16, 'GpsRawNavData1', -2, 'ct_GpsRawNavData1');

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
           (14, 'RcvSBASTimeOffset', '[WO] WAAS/EGNOS to Receiver Time Offset', 17, 1, 3, 1, 'msg_RcvSBASTimeOffset'), 
           (15, 'RcvQZSSTimeOffset', '[QO] QZSS to Receiver Time Offset', 17, 1, 3, 1, 'msg_RcvQZSSTimeOffset'), 
           (16, 'GpsUtcParam', '[UO] GPS UTC Time Parameters', 24, 1, 3, 1, 'msg_GpsUtcParam'), 
           (17, 'SbasUtcParam', '[WU] WAAS/EGNOS UTC Time Parameters', 32, 1, 3, 1, 'msg_SbasUtcParam'), 
           (18, 'GalUtcGpsParam', '[EU] GALILEO UTC and GPS Time Parameters', 40, 1, 3, 1, 'msg_GalUtcGpsParam'), 
           (19, 'QzssUtcParam', '[QU] QZSS UTC Time Parameters', 24, 1, 3, 1, 'msg_QzssUtcParam'), 
           (20, 'GloUtcGpsParam', '[NU] GLONASS UTC and GPS Time Parameters', 25, 1, 3, 1, 'msg_GloUtcGpsParam'), 
           (21, 'SolutionTime', '[ST] Solution Time-Tag', 6, 1, 3, 1, 'msg_SolutionTime'), 
           (22, 'Pos', '[PO] Cartesian Position', 30, 1, 3, 1, 'msg_Pos'), 
           (23, 'Vel', '[VE] Cartesian Velocity', 18, 1, 3, 1, 'msg_Vel'), 
           (24, 'PosVel', '[PV] Cartesian Position and Velocity', 46, 1, 3, 1, 'msg_PosVel'), 
           (25, 'GeoPos', '[PG] Geodetic Position', 30, 1, 3, 1, 'msg_GeoPos'), 
           (26, 'GeoVel', '[VG] Geodetic Velocity', 18, 1, 3, 1, 'msg_GeoVel'), 
           (27, 'Rms', '[SG] Position and Velocity RMS Errors', 18, 1, 3, 1, 'msg_Rms'), 
           (28, 'Dops', '[DP] Dilution of Precision (DOP)', 14, 1, 3, 1, 'msg_Dops'), 
           (29, 'PosCov', '[SP] Position Covariance Matrix', 42, 1, 3, 1, 'msg_PosCov'), 
           (30, 'VelCov', '[SV] Velocity Covariance Matrix', 42, 1, 3, 1, 'msg_VelCov'), 
           (31, 'Baseline', '[BL] Baseline', 34, 1, 3, 1, 'msg_Baseline'), 
           (32, 'PosStat', '[PS] Position Statistics', 9, 1, 3, 1, 'msg_PosStat'), 
           (33, 'PosCompTime', '[PT] Time of Continuous Position Computation', 5, 1, 3, 1, 'msg_PosCompTime'), 
           (34, 'SatIndex', '[SI] Satellite Indices', -2, 1, 3, 1, 'msg_SatIndex'), 
           (35, 'AntName', '[AN] Antenna Names', -2, 1, 3, 1, 'msg_AntName'), 
           (36, 'SatNumbers', '[NN] GLONASS Satellite System Numbers', -2, 1, 3, 1, 'msg_SatNumbers'), 
           (37, 'SatElevation', '[EL] Satellite Elevations', -2, 1, 3, 1, 'msg_SatElevation'), 
           (38, 'SatAzimuth', '[AZ] Satellite Azimuths', -2, 1, 3, 1, 'msg_SatAzimuth'), 
           (39, 'PR', '[RC], [R1], [R2], [R3], [R5], [Rl]: Pseudoranges', -2, 1, 3, 1, 'msg_PR'), 
           (40, 'SPR', '[rc], [r1], [r2], [r3], [r5], [rl]: Pseudoranges', -2, 1, 3, 1, 'msg_SPR'), 
           (41, 'RPR', '[1R], [2R], [3R], [5R], [lR]: Relative Pseudoranges', -2, 1, 3, 1, 'msg_RPR'), 
           (42, 'SRPR', '[1r], [2r], [3r], [5r], [lr]: Relative Pseudoranges', -2, 1, 3, 1, 'msg_SRPR'), 
           (43, 'SC', '[CC],[C1],[C2],[C3],[C5],[Cl]: Smoothing Corrections', -2, 1, 3, 1, 'msg_SC'), 
           (44, 'SS', '[cc],[c1],[c2],[c3],[c5],[cl]: Smoothing Corrections', -2, 1, 3, 1, 'msg_SS'), 
           (45, 'CP', '[PC], [P1], [P2], [P3], [P5], [Pl]: Carrier Phases', -2, 1, 3, 1, 'msg_CP'), 
           (46, 'SCP', '[pc], [p1], [p2], [p3], [p5], [pl]: Carrier Phases', -2, 1, 3, 1, 'msg_SCP'), 
           (47, 'RCP_RC', '[CP],[1P],[2P],[3P],[5P],[lP]: Relative Carrier Phases', -2, 1, 3, 1, 'msg_RCP_RC0'), 
           (48, 'RCP_rc', '[cp],[1p],[2p],[3p],[5p],[lp]: Relative Carrier Phases', -2, 1, 3, 1, 'msg_RCP_rc1'), 
           (49, 'DP', '[DC], [D1], [D2], [D3], [D5], [Dl]: Doppler', -2, 1, 3, 1, 'msg_DP'), 
           (50, 'SRDP', '[1d], [2d], [3d], [5d], [ld]: Relative Doppler', -2, 1, 3, 1, 'msg_SRDP'), 
           (51, 'CNR', '[EC], [E1], [E2], [E3], [E5], [El]: SNR', -2, 1, 3, 1, 'msg_CNR'), 
           (52, 'CNR_4', '[CE], [1E], [2E], [3E], [5E], [lE]: SNR x ', -2, 1, 3, 1, 'msg_CNR_4'), 
           (53, 'Flags', '[FC],[F1],[F2],[F3],[F5],[Fl]: Signal Lock Loop Flags', -2, 1, 3, 1, 'msg_Flags'), 
           (54, 'IAmp', '[ec], [e1], [e2], [e3], [e5]: Raw Inphases (I)', -1, 1, 3, 1, 'msg_IAmp'), 
           (55, 'QAmp', '[qc], [q1], [q2], [q3], [q5]: Raw Quadratures (Q)', -1, 1, 3, 1, 'msg_QAmp'), 
           (56, 'TrackingTimeCA', '[TC] CA/L1 Continuous Tracking Time', -2, 1, 3, 1, 'msg_TrackingTimeCA'), 
           (57, 'NavStatus', '[SS] Satellite Navigation Status', -2, 1, 3, 1, 'msg_NavStatus'), 
           (58, 'IonoDelay', '[ID] Ionospheric Delays', -2, 1, 3, 1, 'msg_IonoDelay'), 
           (59, 'GPSAlm0', '[GA] GPS Almanac', 47, 1, 3, 2, 'msg_GPSAlm0'), 
           (60, 'GALAlm', '[EA] GALILEO Almanac', 49, 1, 3, 2, 'msg_GALAlm'), 
           (61, 'QZSSAlm', '[QA] QZSS Almanac', 47, 1, 3, 1, 'msg_QZSSAlm'), 
           (62, 'GLOAlmanac', '[NA] GLONASS Almanac', -3, 1, 3, 2, 'msg_GLOAlmanac'), 
           (63, 'SBASAlmanac', '[WA] WAAS/EGNOS Almanac', 51, 1, 3, 2, 'msg_SBASAlmanac'), 
           (64, 'GPSEphemeris0', '[GE] GPS Ephemeris', -3, 1, 3, 2, 'msg_GPSEphemeris0'), 
           (65, 'GALEphemeris', '[EN] GALILEO Ephemeris', 145, 1, 3, 2, 'msg_GALEphemeris'), 
           (66, 'QZSSEphemeris', '[QE] QZSS Ephemeris', -1, 1, 3, 1, 'msg_QZSSEphemeris'), 
           (67, 'GLOEphemeris', '[NE] GLONASS Ephemeris', -3, 1, 3, 2, 'msg_GLOEphemeris'), 
           (68, 'SBASEhemeris', '[WE] WAAS/EGNOS Ephemeris', 73, 1, 3, 2, 'msg_SBASEhemeris'), 
           (69, 'GpsNavData0', '[GD] GPS Raw Navigation Data (obsolete)', -2, 1, 3, 1, 'msg_GpsNavData0'), 
           (70, 'GpsRawNavData0', '[gd] GPS Raw Navigation Data', -2, 1, 3, 1, 'msg_GpsRawNavData0'), 
           (71, 'QzssNavData', '[QD] QZSS Raw Navigation Data (obsolete)', -1, 0, 3, 1, 'msg_QzssNavData'), 
           (72, 'QzssRawNavData', '[qd] QZSS Raw Navigation Data', -1, 0, 3, 1, 'msg_QzssRawNavData'), 
           (73, 'GloNavData', '[LD] GLONASS Raw Navigation Data (obsolete)', -2, 1, 3, 1, 'msg_GloNavData'), 
           (74, 'GloRawNavData', '[lD] GLONASS Raw Navigation Data', -2, 1, 3, 1, 'msg_GloRawNavData'), 
           (75, 'SbasRawNavData', '[WD] WAAS/EGNOS Raw Navigation Data', 40, 1, 3, 1, 'msg_SbasRawNavData'), 
           (76, 'GalRawNavData', '[ED] GALILEO Raw Navigation Data', -2, 1, 3, 1, 'msg_GalRawNavData'), 
           (77, 'CompRawNavData', '[cd] COMPASS Raw Navigation Data', -2, 1, 3, 1, 'msg_CompRawNavData'), 
           (78, 'Spectrum0', '[sp] Spectrum', -1, 1, 3, 1, 'msg_Spectrum0'), 
           (79, 'Spectrum1', '[sP] Extended Spectrum', -1, 1, 3, 1, 'msg_Spectrum1'), 
           (80, 'GloPhaseDelay', '[gC], [g1], [g2], [g3]: GLONASS Phase Delays', -2, 1, 3, 1, 'msg_GloPhaseDelay'), 
           (81, 'RotationMatrix', '[MR] Rotation Matrix', 37, 1, 3, 1, 'msg_RotationMatrix'), 
           (82, 'RotationMatrixAndVectors', '[mr] Rotation Matrix and Vectors', 73, 1, 3, 1, 'msg_RotationMatrixAndVectors'), 
           (83, 'RotationAngles', '[AR] Rotation Angles', 30, 1, 3, 1, 'msg_RotationAngles'), 
           (84, 'AngularVelocity', '[AV] Angular Velocities', 22, 1, 3, 1, 'msg_AngularVelocity'), 
           (85, 'InertialMeasurements', '[IM] Inertial Measurements', 25, 1, 3, 1, 'msg_InertialMeasurements'), 
           (86, 'ExtEvent', '[XA], [XB] External Event', 10, 1, 3, 1, 'msg_ExtEvent'), 
           (87, 'PPSOffset', '[ZA], [ZB] PPS Offset', 5, 1, 3, 1, 'msg_PPSOffset'), 
           (88, 'RcvTimeOffsAtPPS', '[YA], [YB] Time Offset at PPS Generation Time', 10, 1, 3, 1, 'msg_RcvTimeOffsAtPPS'), 
           (89, 'RefEpoch', '[rE] Reference Epoch', 10, 3, 3, 1, 'msg_RefEpoch'), 
           (90, 'RawMeas', '[rM] Raw Measurements', -1, 3, 3, 1, 'msg_RawMeas'), 
           (91, 'PosVelVector', '[rV] Receiver’s Position and Velocity', 42, 3, 3, 1, 'msg_PosVelVector'), 
           (92, 'ClockOffsets', '[rT] Receiver Clock Offsets', -2, 3, 3, 1, 'msg_ClockOffsets'), 
           (93, 'RE', '[RE] Reply', -2, 0, 3, 1, 'msg_RE'), 
           (94, 'ER', '[ER] Error', -2, 0, 3, 1, 'msg_ER'), 
           (95, 'IonoParams0', '[IO] GPS Ionospheric Parameters', 39, 1, 3, 1, 'msg_IonoParams0'), 
           (96, 'QzssIonoParams', '[QI] QZSS Ionospheric Parameters', 39, 0, 3, 1, 'msg_QzssIonoParams'), 
           (97, 'Event', '[==](EV) Event', -2, 1, 3, 1, 'msg_Event'), 
           (98, 'Latency', '[LT] Message Output Latency', 2, 1, 3, 1, 'msg_Latency'), 
           (99, 'Wrapper', '[>>] Wrapper', -2, 2, 3, 1, 'msg_Wrapper'), 
           (100, 'Params', '[PM] Parameters', -2, 2, 3, 1, 'msg_Params'), 
           (101, 'LoggingHistory', '[LH] Logging History', -1, 0, 3, 1, 'msg_LoggingHistory'), 
           (102, 'BaseInfo', '[BI] Base Station Information', 28, 1, 3, 1, 'msg_BaseInfo'), 
           (103, 'Security0', '[SE] Security', 6, 1, 3, 1, 'msg_Security0'), 
           (104, 'Security1', '[SM] Security for [rM]', 8, 3, 3, 1, 'msg_Security1'), 
           (105, 'TrackingTime', '[TT] CA/L1 Overall Continuous Tracking Time', 5, 1, 3, 1, 'msg_TrackingTime'), 
           (106, 'RcvOscOffs', '[OO] Oscillator Offset', 5, 1, 3, 1, 'msg_RcvOscOffs'), 
           (107, 'EpochEnd', '[||](EE) Epoch End', 1, 1, 3, 1, 'msg_EpochEnd');

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
           ('QO', 15), 
           ('UO', 16), 
           ('WU', 17), 
           ('EU', 18), 
           ('QU', 19), 
           ('NU', 20), 
           ('ST', 21), 
           ('PO', 22), 
           ('VE', 23), 
           ('PV', 24), 
           ('PG', 25), 
           ('VG', 26), 
           ('SG', 27), 
           ('DP', 28), 
           ('SP', 29), 
           ('SV', 30), 
           ('BL', 31), 
           ('PS', 32), 
           ('PT', 33), 
           ('SI', 34), 
           ('AN', 35), 
           ('NN', 36), 
           ('EL', 37), 
           ('AZ', 38), 
           ('RC', 39), 
           ('R1', 39), 
           ('R2', 39), 
           ('R3', 39), 
           ('R5', 39), 
           ('Rl', 39), 
           ('rc', 40), 
           ('r1', 40), 
           ('r2', 40), 
           ('r3', 40), 
           ('r5', 40), 
           ('rl', 40), 
           ('1R', 41), 
           ('2R', 41), 
           ('3R', 41), 
           ('5R', 41), 
           ('lR', 41), 
           ('1r', 42), 
           ('2r', 42), 
           ('3r', 42), 
           ('5r', 42), 
           ('lr', 42), 
           ('CC', 43), 
           ('C1', 43), 
           ('C2', 43), 
           ('C3', 43), 
           ('C5', 43), 
           ('Cl', 43), 
           ('cc', 44), 
           ('c1', 44), 
           ('c2', 44), 
           ('c3', 44), 
           ('c5', 44), 
           ('cl', 44), 
           ('PC', 45), 
           ('P1', 45), 
           ('P2', 45), 
           ('P3', 45), 
           ('P5', 45), 
           ('Pl', 45), 
           ('pc', 46), 
           ('p1', 46), 
           ('p2', 46), 
           ('p3', 46), 
           ('p5', 46), 
           ('pl', 46), 
           ('CP', 47), 
           ('1P', 47), 
           ('2P', 47), 
           ('3P', 47), 
           ('5P', 47), 
           ('lP', 47), 
           ('cp', 48), 
           ('1p', 48), 
           ('2p', 48), 
           ('3p', 48), 
           ('5p', 48), 
           ('lp', 48), 
           ('DC', 49), 
           ('D1', 49), 
           ('D2', 49), 
           ('D3', 49), 
           ('D5', 49), 
           ('Dl', 49), 
           ('1d', 50), 
           ('2d', 50), 
           ('3d', 50), 
           ('5d', 50), 
           ('ld', 50), 
           ('EC', 51), 
           ('E1', 51), 
           ('E2', 51), 
           ('E3', 51), 
           ('E5', 51), 
           ('El', 51), 
           ('CE', 52), 
           ('1E', 52), 
           ('2E', 52), 
           ('3E', 52), 
           ('5E', 52), 
           ('lE', 52), 
           ('FC', 53), 
           ('F1', 53), 
           ('F2', 53), 
           ('F3', 53), 
           ('F5', 53), 
           ('Fl', 53), 
           ('ec', 54), 
           ('e1', 54), 
           ('e2', 54), 
           ('e3', 54), 
           ('e5', 54), 
           ('qc', 55), 
           ('q1', 55), 
           ('q2', 55), 
           ('q3', 55), 
           ('q5', 55), 
           ('TC', 56), 
           ('SS', 57), 
           ('ID', 58), 
           ('GA', 59), 
           ('EA', 60), 
           ('QA', 61), 
           ('NA', 62), 
           ('WA', 63), 
           ('GE', 64), 
           ('EN', 65), 
           ('QE', 66), 
           ('NE', 67), 
           ('WE', 68), 
           ('GD', 69), 
           ('gd', 70), 
           ('QD', 71), 
           ('qd', 72), 
           ('LD', 73), 
           ('lD', 74), 
           ('WD', 75), 
           ('ED', 76), 
           ('cd', 77), 
           ('sp', 78), 
           ('sP', 79), 
           ('gC', 80), 
           ('g1', 80), 
           ('g2', 80), 
           ('g3', 80), 
           ('MR', 81), 
           ('mr', 82), 
           ('AR', 83), 
           ('AV', 84), 
           ('IM', 85), 
           ('XA', 86), 
           ('XB', 86), 
           ('ZA', 87), 
           ('ZB', 87), 
           ('YA', 88), 
           ('YB', 88), 
           ('rE', 89), 
           ('rM', 90), 
           ('rV', 91), 
           ('rT', 92), 
           ('RE', 93), 
           ('ER', 94), 
           ('IO', 95), 
           ('QI', 96), 
           ('==', 97), 
           ('LT', 98), 
           ('>>', 99), 
           ('PM', 100), 
           ('LH', 101), 
           ('BI', 102), 
           ('SE', 103), 
           ('SM', 104), 
           ('TT', 105), 
           ('OO', 106), 
           ('||', 107);

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
           (43, 'val', 'f8', '', 15), 
           (44, 'sval', 'f8', '', 15), 
           (45, 'cs', 'u1', '', 15), 
           (46, 'utc', 'UtcOffs', '', 16), 
           (47, 'cs', 'u1', '', 16), 
           (48, 'utc', 'UtcOffs', '', 17), 
           (49, 'utcsi', 'i1', '', 17), 
           (50, 'tow', 'u4', '', 17), 
           (51, 'wn', 'u2', '', 17), 
           (52, 'flags', 'u1', '', 17), 
           (53, 'cs', 'u1', '', 17), 
           (54, 'utc', 'UtcOffs', '', 18), 
           (55, 'a0g', 'f4', '', 18), 
           (56, 'a1g', 'f4', '', 18), 
           (57, 't0g', 'u4', '', 18), 
           (58, 'wn0g', 'u2', '', 18), 
           (59, 'flags', 'u2', '', 18), 
           (60, 'cs', 'u1', '', 18), 
           (61, 'utc', 'UtcOffs', '', 19), 
           (62, 'cs', 'u1', '', 19), 
           (63, 'tauSys', 'f8', '', 20), 
           (64, 'tauGps', 'f4', '', 20), 
           (65, 'B1', 'f4', '', 20), 
           (66, 'B2', 'f4', '', 20), 
           (67, 'KP', 'u1', '', 20), 
           (68, 'N4', 'u1', '', 20), 
           (69, 'Dn', 'i2', '', 20), 
           (70, 'cs', 'u1', '', 20), 
           (71, 'time', 'u4', '', 21), 
           (72, 'solType', 'u1', '', 21), 
           (73, 'cs', 'u1', '', 21), 
           (74, 'x', 'f8', '', 22), 
           (75, 'y', 'f8', '', 22), 
           (76, 'z', 'f8', '', 22), 
           (77, 'sigma', 'f4', '', 22), 
           (78, 'solType', 'u1', '', 22), 
           (79, 'cs', 'u1', '', 22), 
           (80, 'x', 'f4', '', 23), 
           (81, 'y', 'f4', '', 23), 
           (82, 'z', 'f4', '', 23), 
           (83, 'sigma', 'f4', '', 23), 
           (84, 'solType', 'u1', '', 23), 
           (85, 'cs', 'u1', '', 23), 
           (86, 'x', 'f8', '', 24), 
           (87, 'y', 'f8', '', 24), 
           (88, 'z', 'f8', '', 24), 
           (89, 'pSigma', 'f4', '', 24), 
           (90, 'vx', 'f4', '', 24), 
           (91, 'vy', 'f4', '', 24), 
           (92, 'vz', 'f4', '', 24), 
           (93, 'vSigma', 'f4', '', 24), 
           (94, 'solType', 'u1', '', 24), 
           (95, 'cs', 'u1', '', 24), 
           (96, 'lat', 'f8', '', 25), 
           (97, 'lon', 'f8', '', 25), 
           (98, 'alt', 'f8', '', 25), 
           (99, 'pSigma', 'f4', '', 25), 
           (100, 'solType', 'u1', '', 25), 
           (101, 'cs', 'u1', '', 25), 
           (102, 'lat', 'f4', '', 26), 
           (103, 'lon', 'f4', '', 26), 
           (104, 'alt', 'f4', '', 26), 
           (105, 'pSigma', 'f4', '', 26), 
           (106, 'solType', 'u1', '', 26), 
           (107, 'cs', 'u1', '', 26), 
           (108, 'hpos', 'f4', '', 27), 
           (109, 'vpos', 'f4', '', 27), 
           (110, 'hvel', 'f4', '', 27), 
           (111, 'vvel', 'f4', '', 27), 
           (112, 'solType', 'u1', '', 27), 
           (113, 'cs', 'u1', '', 27), 
           (114, 'hdop', 'f4', '', 28), 
           (115, 'vdop', 'f4', '', 28), 
           (116, 'tdop', 'f4', '', 28), 
           (117, 'solType', 'u1', '', 28), 
           (118, 'cs', 'u1', '', 28), 
           (119, 'xx', 'f4', '', 29), 
           (120, 'yy', 'f4', '', 29), 
           (121, 'zz', 'f4', '', 29), 
           (122, 'tt', 'f4', '', 29), 
           (123, 'xy', 'f4', '', 29), 
           (124, 'xz', 'f4', '', 29), 
           (125, 'xt', 'f4', '', 29), 
           (126, 'yz', 'f4', '', 29), 
           (127, 'yt', 'f4', '', 29), 
           (128, 'zt', 'f4', '', 29), 
           (129, 'solType', 'u1', '', 29), 
           (130, 'cs', 'u1', '', 29), 
           (131, 'xx', 'f4', '', 30), 
           (132, 'yy', 'f4', '', 30), 
           (133, 'zz', 'f4', '', 30), 
           (134, 'tt', 'f4', '', 30), 
           (135, 'xy', 'f4', '', 30), 
           (136, 'xz', 'f4', '', 30), 
           (137, 'xt', 'f4', '', 30), 
           (138, 'yz', 'f4', '', 30), 
           (139, 'yt', 'f4', '', 30), 
           (140, 'zt', 'f4', '', 30), 
           (141, 'solType', 'u1', '', 30), 
           (142, 'cs', 'u1', '', 30), 
           (143, 'x', 'f8', '', 31), 
           (144, 'y', 'f8', '', 31), 
           (145, 'z', 'f8', '', 31), 
           (146, 'sigma', 'f4', '', 31), 
           (147, 'solType', 'u1', '', 31), 
           (148, 'time', 'i4', '', 31), 
           (149, 'cs', 'u1', '', 31), 
           (150, 'solType', 'u1', '', 32), 
           (151, 'gpsLocked', 'u1', '', 32), 
           (152, 'gloLocked', 'u1', '', 32), 
           (153, 'gpsAvail', 'u1', '', 32), 
           (154, 'gloAvail', 'u1', '', 32), 
           (155, 'gpsUsed', 'u1', '', 32), 
           (156, 'gloUsed', 'u1', '', 32), 
           (157, 'fixProg', 'u1', '', 32), 
           (158, 'cs', 'u1', '', 32), 
           (159, 'pt', 'u4', '', 33), 
           (160, 'cs', 'u1', '', 33), 
           (161, 'usi', 'u1', '', 34), 
           (162, 'cs', 'u1', '', 34), 
           (163, 'name', 'a1', '', 35), 
           (164, 'cs', 'u1', '', 35), 
           (165, 'osn', 'u1', '', 36), 
           (166, 'cs', 'u1', '', 36), 
           (167, 'elev', 'i1', '', 37), 
           (168, 'cs', 'u1', '', 37), 
           (169, 'azim', 'u1', '', 38), 
           (170, 'cs', 'u1', '', 38), 
           (171, 'pr', 'f8', '', 39), 
           (172, 'cs', 'u1', '', 39), 
           (173, 'spr', 'i4', '', 40), 
           (174, 'cs', 'u1', '', 40), 
           (175, 'rpr', 'f4', '', 41), 
           (176, 'cs', 'u1', '', 41), 
           (177, 'srpr', 'i2', '', 42), 
           (178, 'cs', 'u1', '', 42), 
           (179, 'smooth', 'Smooth', '', 43), 
           (180, 'cs', 'u1', '', 43), 
           (181, 'smooth', 'i2', '', 44), 
           (182, 'cs', 'u1', '', 44), 
           (183, 'cp', 'f8', '', 45), 
           (184, 'cs', 'u1', '', 45), 
           (185, 'scp', 'u4', '', 46), 
           (186, 'cs', 'u1', '', 46), 
           (187, 'rcp', 'f4', '', 47), 
           (188, 'cs', 'u1', '', 47), 
           (189, 'rcp', 'i4', '', 48), 
           (190, 'cs', 'u1', '', 48), 
           (191, 'dp', 'i4', '', 49), 
           (192, 'cs', 'u1', '', 49), 
           (193, 'srdp', 'i2', '', 50), 
           (194, 'cs', 'u1', '', 50), 
           (195, 'cnr', 'u1', '', 51), 
           (196, 'cs', 'u1', '', 51), 
           (197, 'cnrX4', 'u1', '', 52), 
           (198, 'cs', 'u1', '', 52), 
           (199, 'flags', 'u2', '', 53), 
           (200, 'cs', 'u1', '', 53), 
           (201, 'amp', 'i2', '', 54), 
           (202, 'cs', 'u1', '', 54), 
           (203, 'amp', 'i2', '', 55), 
           (204, 'cs', 'u1', '', 55), 
           (205, 'tt', 'u2', '', 56), 
           (206, 'cs', 'u1', '', 56), 
           (207, 'ns', 'u1', '', 57), 
           (208, 'solType', 'u1', '', 57), 
           (209, 'cs', 'u1', '', 57), 
           (210, 'delay', 'f4', '', 58), 
           (211, 'cs', 'u1', '', 58), 
           (212, 'sv', 'u1', '', 59), 
           (213, 'wna', 'i2', '', 59), 
           (214, 'toa', 'i4', '', 59), 
           (215, 'healthA', 'u1', '', 59), 
           (216, 'healthS', 'u1', '', 59), 
           (217, 'config', 'u1', '', 59), 
           (218, 'af1', 'f4', '', 59), 
           (219, 'af0', 'f4', '', 59), 
           (220, 'rootA', 'f4', '', 59), 
           (221, 'ecc', 'f4', '', 59), 
           (222, 'm0', 'f4', '', 59), 
           (223, 'omega0', 'f4', '', 59), 
           (224, 'argPer', 'f4', '', 59), 
           (225, 'deli', 'f4', '', 59), 
           (226, 'omegaDot', 'f4', '', 59), 
           (227, 'cs', 'u1', '', 59), 
           (228, 'gps', 'GPSAlm1', '', 60), 
           (229, 'iod', 'i2', '', 60), 
           (230, 'cs', 'u1', '', 60), 
           (231, 'gps', 'GPSAlm1', '', 61), 
           (232, 'cs', 'u1', '', 61), 
           (233, 'sv', 'u1', '', 62), 
           (234, 'frqNum', 'i1', '', 62), 
           (235, 'dna', 'i2', '', 62), 
           (236, 'tlam', 'f4', '', 62), 
           (237, 'flags', 'u1', '', 62), 
           (238, 'tauN', 'f4', '', 62), 
           (239, 'tauSys', 'f8', '', 62), 
           (240, 'ecc', 'f4', '', 62), 
           (241, 'lambda', 'f4', '', 62), 
           (242, 'argPer', 'f4', '', 62), 
           (243, 'delT', 'f4', '', 62), 
           (244, 'delTdt', 'f4', '', 62), 
           (245, 'deli', 'f4', '', 62), 
           (246, 'n4', 'u1', '', 62), 
           (247, 'navType', 'u1', '', 62), 
           (248, 'gammaN', 'f4', '', 62), 
           (249, 'cs', 'u1', '', 62), 
           (250, 'waasPrn', 'u1', '', 63), 
           (251, 'gpsPrn', 'u1', '', 63), 
           (252, 'id', 'u1', '', 63), 
           (253, 'healthS', 'u1', '', 63), 
           (254, 'tod', 'u4', '', 63), 
           (255, 'xg', 'f8', '', 63), 
           (256, 'yg', 'f8', '', 63), 
           (257, 'zg', 'f8', '', 63), 
           (258, 'vxg', 'f4', '', 63), 
           (259, 'vyg', 'f4', '', 63), 
           (260, 'vzg', 'f4', '', 63), 
           (261, 'tow', 'u4', '', 63), 
           (262, 'wn', 'u2', '', 63), 
           (263, 'cs', 'u1', '', 63), 
           (264, 'req', 'GpsEphReqData', '', 64), 
           (265, 'cNavType', 'u1', '', 64), 
           (266, 'lTope', 'i4', '', 64), 
           (267, 'lTopc', 'i4', '', 64), 
           (268, 'dADot', 'f8', '', 64), 
           (269, 'fDelnDot', 'f4', '', 64), 
           (270, 'cURAoe', 'i1', '', 64), 
           (271, 'cURAoc', 'i1', '', 64), 
           (272, 'cURAoc1', 'i1', '', 64), 
           (273, 'cURAoc2', 'i1', '', 64), 
           (274, 'cs', 'u1', '', 64), 
           (275, 'req', 'GpsEphReqData', '', 65), 
           (276, 'bgdE1E5a', 'f4', '', 65), 
           (277, 'bgdE1E5b', 'f4', '', 65), 
           (278, 'ai0', 'f4', '', 65), 
           (279, 'ai1', 'f4', '', 65), 
           (280, 'ai2', 'f4', '', 65), 
           (281, 'sfi', 'u1', '', 65), 
           (282, 'navType', 'u1', '', 65), 
           (283, 'cs', 'u1', '', 65), 
           (284, 'gps', 'GPSEphemeris1', '', 66), 
           (285, 'cs', 'u1', '', 66), 
           (286, 'sv', 'u1', '', 67), 
           (287, 'frqNum', 'i1', '', 67), 
           (288, 'dne', 'i2', '', 67), 
           (289, 'tk', 'i4', '', 67), 
           (290, 'tb', 'i4', '', 67), 
           (291, 'health', 'u1', '', 67), 
           (292, 'age', 'u1', '', 67), 
           (293, 'flags', 'u1', '', 67), 
           (294, 'r', 'f8', '', 67), 
           (295, 'v', 'f4', '', 67), 
           (296, 'w', 'f4', '', 67), 
           (297, 'tauSys', 'f8', '', 67), 
           (298, 'tau', 'f4', '', 67), 
           (299, 'gamma', 'f4', '', 67), 
           (300, 'fDelTauN', 'f4', '', 67), 
           (301, 'nFt', 'u1', '', 67), 
           (302, 'nN4', 'u1', '', 67), 
           (303, 'flags2', 'u2', '', 67), 
           (304, 'navType', 'u1', '', 67), 
           (305, 'beta', 'f4', '', 67), 
           (306, 'tauSysDot', 'f4', '', 67), 
           (307, 'ec', 'u1', '', 67), 
           (308, 'ee', 'u1', '', 67), 
           (309, 'fc', 'i1', '', 67), 
           (310, 'fe', 'i1', '', 67), 
           (311, 'reserv', 'u2', '', 67), 
           (312, 'cs', 'u1', '', 67), 
           (313, 'waasPrn', 'u1', '', 68), 
           (314, 'gpsPrn', 'u1', '', 68), 
           (315, 'iod', 'u1', '', 68), 
           (316, 'acc', 'u1', '', 68), 
           (317, 'tod', 'u4', '', 68), 
           (318, 'xg', 'f8', '', 68), 
           (319, 'yg', 'f8', '', 68), 
           (320, 'zg', 'f8', '', 68), 
           (321, 'vxg', 'f4', '', 68), 
           (322, 'vyg', 'f4', '', 68), 
           (323, 'vzg', 'f4', '', 68), 
           (324, 'vvxg', 'f4', '', 68), 
           (325, 'vvyg', 'f4', '', 68), 
           (326, 'vvzg', 'f4', '', 68), 
           (327, 'agf0', 'f4', '', 68), 
           (328, 'agf1', 'f4', '', 68), 
           (329, 'tow', 'u4', '', 68), 
           (330, 'wn', 'u2', '', 68), 
           (331, 'flags', 'u2', '', 68), 
           (332, 'cs', 'u1', '', 68), 
           (333, 'recSize', 'u1', '', 69), 
           (334, 'dat', 'SvData0', '', 69), 
           (335, 'cs', 'u1', '', 69), 
           (336, 'prn', 'u1', '', 70), 
           (337, 'time', 'u4', '', 70), 
           (338, 'type', 'u1', '', 70), 
           (339, 'len', 'u1', '', 70), 
           (340, 'data', 'u4', '', 70), 
           (341, 'cs', 'u1', '', 70), 
           (342, 'data', 'GpsNavData1', '', 71), 
           (343, 'data', 'GpsRawNavData1', '', 72), 
           (344, 'recSize', 'u1', '', 73), 
           (345, 'dat', 'SvData1', '', 73), 
           (346, 'cs', 'u1', '', 73), 
           (347, 'num', 'u1', '', 74), 
           (348, 'fcn', 'i1', '', 74), 
           (349, 'time', 'u4', '', 74), 
           (350, 'type', 'u1', '', 74), 
           (351, 'len', 'u1', '', 74), 
           (352, 'data', 'u1', '', 74), 
           (353, 'cs', 'u1', '', 74), 
           (354, 'prn', 'u1', '', 75), 
           (355, 'time', 'u4', '', 75), 
           (356, 'reserv', 'u2', '', 75), 
           (357, 'data', 'u1', '', 75), 
           (358, 'cs', 'u1', '', 75), 
           (359, 'prn', 'u1', '', 76), 
           (360, 'time', 'u4', '', 76), 
           (361, 'type', 'u1', '', 76), 
           (362, 'len', 'u1', '', 76), 
           (363, 'data', 'u1', '', 76), 
           (364, 'cs', 'u1', '', 76), 
           (365, 'prn', 'u1', '', 77), 
           (366, 'time', 'u4', '', 77), 
           (367, 'type', 'u1', '', 77), 
           (368, 'len', 'u1', '', 77), 
           (369, 'data', 'u4', '', 77), 
           (370, 'cs', 'u1', '', 77), 
           (371, 'currFrq', 'i2', '', 78), 
           (372, 'finalFrq', 'i2', '', 78), 
           (373, 'n', 'u1', '', 78), 
           (374, 'm', 'u1', '', 78), 
           (375, 's', 'SpecData', '', 78), 
           (376, 'cs', 'u1', '', 78), 
           (377, 'currFrq', 'i2', '', 79), 
           (378, 'finalFrq', 'i2', '', 79), 
           (379, 'n', 'u1', '', 79), 
           (380, 'm', 'u1', '', 79), 
           (381, 's', 'ExtSpecData', '', 79), 
           (382, 'cs', 'u1', '', 79), 
           (383, 'fcn', 'i1', '', 80), 
           (384, 'phase', 'f4', '', 80), 
           (385, 'range', 'f4', '', 80), 
           (386, 'cs', 'u1', '', 80), 
           (387, 'time', 'u4', '', 81), 
           (388, 'q00', 'f4', '', 81), 
           (389, 'q01', 'f4', '', 81), 
           (390, 'q02', 'f4', '', 81), 
           (391, 'q12', 'f4', '', 81), 
           (392, 'rms', 'f4', '', 81), 
           (393, 'solType', 'u1', '', 81), 
           (394, 'flag', 'u1', '', 81), 
           (395, 'cs', 'u1', '', 81), 
           (396, 'time', 'u4', '', 82), 
           (397, 'q00', 'f4', '', 82), 
           (398, 'q01', 'f4', '', 82), 
           (399, 'q02', 'f4', '', 82), 
           (400, 'q12', 'f4', '', 82), 
           (401, 'rms', 'f4', '', 82), 
           (402, 'solType', 'u1', '', 82), 
           (403, 'flag', 'u1', '', 82), 
           (404, 'bl0', 'f4', '', 82), 
           (405, 'bl1', 'f4', '', 82), 
           (406, 'bl2', 'f4', '', 82), 
           (407, 'cs', 'u1', '', 82), 
           (408, 'time', 'u4', '', 83), 
           (409, 'pitch', 'f4', '', 83), 
           (410, 'roll', 'f4', '', 83), 
           (411, 'heading', 'f4', '', 83), 
           (412, 'pitchRms', 'f4', '', 83), 
           (413, 'rollRms', 'f4', '', 83), 
           (414, 'headingRms', 'f4', '', 83), 
           (415, 'flags', 'u1', '', 83), 
           (416, 'cs', 'u1', '', 83), 
           (417, 'time', 'u4', '', 84), 
           (418, 'x', 'f4', '', 84), 
           (419, 'y', 'f4', '', 84), 
           (420, 'z', 'f4', '', 84), 
           (421, 'rms', 'f4', '', 84), 
           (422, 'flags', 'u1', '', 84), 
           (423, 'cs', 'u1', '', 84), 
           (424, 'accelerations', 'f4', '', 85), 
           (425, 'angularVelocities', 'f4', '', 85), 
           (426, 'cs', 'u1', '', 85), 
           (427, 'ms', 'i4', '', 86), 
           (428, 'ns', 'i4', '', 86), 
           (429, 'timeScale', 'u1', '', 86), 
           (430, 'cs', 'u1', '', 86), 
           (431, 'offs', 'f4', '', 87), 
           (432, 'cs', 'u1', '', 87), 
           (433, 'offs', 'f8', '', 88), 
           (434, 'timeScale', 'u1', '', 88), 
           (435, 'cs', 'u1', '', 88), 
           (436, 'sample', 'u2', '', 89), 
           (437, 'scale', 'u2', '', 89), 
           (438, 'reftime', 'u4', '', 89), 
           (439, 'crc16', 'u2', '', 89), 
           (440, 'sample', 'u2', '', 90), 
           (441, 'scale', 'u2', '', 90), 
           (442, 'reftime', 'u4', '', 90), 
           (443, 'clock', 'i2', '', 90), 
           (444, 'flags', 'u2', '', 90), 
           (445, 'svd', 'SvData2', '', 90), 
           (446, 'crc16', 'u2', '', 90), 
           (447, 'sample', 'u2', '', 91), 
           (448, 'delta', 'u2', '', 91), 
           (449, 'word1', 'u4', '', 91), 
           (450, 'word2', 'u4', '', 91), 
           (451, 'word3', 'u4', '', 91), 
           (452, 'word4', 'u4', '', 91), 
           (453, 'word5', 'u4', '', 91), 
           (454, 'word6', 'u4', '', 91), 
           (455, 'word7', 'u4', '', 91), 
           (456, 'word8', 'u4', '', 91), 
           (457, 'word9', 'u4', '', 91), 
           (458, 'crc16', 'u2', '', 91), 
           (459, 'sample', 'u2', '', 92), 
           (460, 'reserved', 'u2', '', 92), 
           (461, 'recSize', 'u1', '', 92), 
           (462, 'Offs', 'ClkOffs', '', 92), 
           (463, 'crc16', 'u2', '', 92), 
           (464, 'reply', 'a1', '', 93), 
           (465, 'error', 'a1', '', 94), 
           (466, 'tot', 'u4', '', 95), 
           (467, 'wn', 'u2', '', 95), 
           (468, 'alpha0', 'f4', '', 95), 
           (469, 'alpha1', 'f4', '', 95), 
           (470, 'alpha2', 'f4', '', 95), 
           (471, 'alpha3', 'f4', '', 95), 
           (472, 'beta0', 'f4', '', 95), 
           (473, 'beta1', 'f4', '', 95), 
           (474, 'beta2', 'f4', '', 95), 
           (475, 'beta3', 'f4', '', 95), 
           (476, 'cs', 'u1', '', 95), 
           (477, 'par', 'IonoParams1', '', 96), 
           (478, 'time', 'u4', '', 97), 
           (479, 'type', 'u1', '', 97), 
           (480, 'data', 'u1', '', 97), 
           (481, 'cs', 'u1', '', 97), 
           (482, 'lt', 'u1', '', 98), 
           (483, 'cs', 'u1', '', 98), 
           (484, 'id', 'u1', '', 99), 
           (485, 'data', 'u1', '', 99), 
           (486, 'cs', 'a1', '', 99), 
           (487, 'params', 'a1', '', 100), 
           (488, 'delim', 'a1', ',@', 100), 
           (489, 'cs', 'a1', '', 100), 
           (490, 'svsCount', 'u1', '', 101), 
           (491, 'targetStream', 'u1', '', 101), 
           (492, 'issue', 'u2', '', 101), 
           (493, 'bitsCount', 'u2', '', 101), 
           (494, 'lastBitTime', 'u4', '', 101), 
           (495, 'uids', 'u1', '', 101), 
           (496, 'pad', 'u1', '', 101), 
           (497, 'hist', 'u4', '', 101), 
           (498, 'x', 'f8', '', 102), 
           (499, 'y', 'f8', '', 102), 
           (500, 'z', 'f8', '', 102), 
           (501, 'id', 'u2', '', 102), 
           (502, 'solType', 'u1', '', 102), 
           (503, 'cs', 'u1', '', 102), 
           (504, 'data', 'u1', '', 103), 
           (505, 'cs', 'u1', '', 103), 
           (506, 'data', 'u1', '', 104), 
           (507, 'crc16', 'u2', '', 104), 
           (508, 'tt', 'u4', '', 105), 
           (509, 'cs', 'u1', '', 105), 
           (510, 'val', 'f4', '', 106), 
           (511, 'cs', 'u1', '', 106), 
           (512, 'cs', 'u1', '', 107);

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
           (11, 'sv', 'u1', '', 3), 
           (12, 'tow', 'u4', '', 3), 
           (13, 'flags', 'u1', '', 3), 
           (14, 'iodc', 'i2', '', 3), 
           (15, 'toc', 'i4', '', 3), 
           (16, 'ura', 'i1', '', 3), 
           (17, 'healthS', 'u1', '', 3), 
           (18, 'wn', 'i2', '', 3), 
           (19, 'tgd', 'f4', '', 3), 
           (20, 'af2', 'f4', '', 3), 
           (21, 'af1', 'f4', '', 3), 
           (22, 'af0', 'f4', '', 3), 
           (23, 'toe', 'i4', '', 3), 
           (24, 'iode', 'i2', '', 3), 
           (25, 'rootA', 'f8', '', 3), 
           (26, 'ecc', 'f8', '', 3), 
           (27, 'm0', 'f8', '', 3), 
           (28, 'omega0', 'f8', '', 3), 
           (29, 'inc0', 'f8', '', 3), 
           (30, 'argPer', 'f8', '', 3), 
           (31, 'deln', 'f4', '', 3), 
           (32, 'omegaDot', 'f4', '', 3), 
           (33, 'incDot', 'f4', '', 3), 
           (34, 'crc', 'f4', '', 3), 
           (35, 'crs', 'f4', '', 3), 
           (36, 'cuc', 'f4', '', 3), 
           (37, 'cus', 'f4', '', 3), 
           (38, 'cic', 'f4', '', 3), 
           (39, 'cis', 'f4', '', 3), 
           (40, 'prn', 'i1', '', 4), 
           (41, 'cnt', 'u1', '', 4), 
           (42, 'data', 'u4', '', 4), 
           (43, 'fcn1', 'i1', '', 5), 
           (44, 'cnt', 'u1', '', 5), 
           (45, 'data', 'u4', '', 5), 
           (46, 'spec', 'i2', '', 6), 
           (47, 'spec', 'i2', '', 7), 
           (48, 'agcmin', 'u1', '', 7), 
           (49, 'agcmax', 'u1', '', 7), 
           (50, 'header', 'Header', '', 8), 
           (51, 'slot', 'SlotRec', '', 8), 
           (52, 'refrange', 'u4', '', 9), 
           (53, 'usi', 'u1', '', 9), 
           (54, 'num', 'u1', '', 9), 
           (55, 'svstOrDelrange', 'i2', '', 10), 
           (56, 'word1', 'u4', '', 10), 
           (57, 'flags', 'u2', '', 10), 
           (58, 'lock', 'u2', '', 10), 
           (59, 'word2', 'u4', '', 10), 
           (60, 'word1', 'u4', '', 11), 
           (61, 'word2', 'u4', '', 11), 
           (62, 'sv', 'u1', '', 12), 
           (63, 'wna', 'i2', '', 12), 
           (64, 'toa', 'i4', '', 12), 
           (65, 'healthA', 'u1', '', 12), 
           (66, 'healthS', 'u1', '', 12), 
           (67, 'config', 'u1', '', 12), 
           (68, 'af1', 'f4', '', 12), 
           (69, 'af0', 'f4', '', 12), 
           (70, 'rootA', 'f4', '', 12), 
           (71, 'ecc', 'f4', '', 12), 
           (72, 'm0', 'f4', '', 12), 
           (73, 'omega0', 'f4', '', 12), 
           (74, 'argPer', 'f4', '', 12), 
           (75, 'deli', 'f4', '', 12), 
           (76, 'omegaDot', 'f4', '', 12), 
           (77, 'req', 'GpsEphReqData', '', 13), 
           (78, 'cNavType', 'u1', '', 13), 
           (79, 'lTope', 'i4', '', 13), 
           (80, 'lTopc', 'i4', '', 13), 
           (81, 'dADot', 'f8', '', 13), 
           (82, 'fDelnDot', 'f4', '', 13), 
           (83, 'cURAoe', 'i1', '', 13), 
           (84, 'cURAoc', 'i1', '', 13), 
           (85, 'cURAoc1', 'i1', '', 13), 
           (86, 'cURAoc2', 'i1', '', 13), 
           (87, 'tot', 'u4', '', 14), 
           (88, 'wn', 'u2', '', 14), 
           (89, 'alpha0', 'f4', '', 14), 
           (90, 'alpha1', 'f4', '', 14), 
           (91, 'alpha2', 'f4', '', 14), 
           (92, 'alpha3', 'f4', '', 14), 
           (93, 'beta0', 'f4', '', 14), 
           (94, 'beta1', 'f4', '', 14), 
           (95, 'beta2', 'f4', '', 14), 
           (96, 'beta3', 'f4', '', 14), 
           (97, 'cs', 'u1', '', 14), 
           (98, 'recSize', 'u1', '', 15), 
           (99, 'dat', 'SvData0', '', 15), 
           (100, 'cs', 'u1', '', 15), 
           (101, 'prn', 'u1', '', 16), 
           (102, 'time', 'u4', '', 16), 
           (103, 'type', 'u1', '', 16), 
           (104, 'len', 'u1', '', 16), 
           (105, 'data', 'u4', '', 16), 
           (106, 'cs', 'u1', '', 16);

-- Наполнение информации о размерностях для пользовательского типа `SvData0`
INSERT INTO `customTypeVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (42, 1, 10);

-- Наполнение информации о размерностях для пользовательского типа `SvData1`
INSERT INTO `customTypeVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (45, 1, 4);

-- Наполнение информации о размерностях для пользовательского типа `SpecData`
INSERT INTO `customTypeVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (46, 1, -2);

-- Наполнение информации о размерностях для пользовательского типа `ExtSpecData`
INSERT INTO `customTypeVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (47, 1, -2), 
           (48, 1, -2), 
           (49, 1, -2);

-- Наполнение информации о размерностях для пользовательского типа `SvData2`
INSERT INTO `customTypeVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (51, 1, -2);

-- Наполнение информации о размерностях для пользовательского типа `GpsNavData1`
INSERT INTO `customTypeVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (99, 1, -2);

-- Наполнение информации о размерностях для пользовательского типа `GpsRawNavData1`
INSERT INTO `customTypeVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (105, 1, -2);

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
    VALUES (161, 1, -2);

-- Наполнение информации о размерностях для сообщения `AntName`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (163, 1, -2);

-- Наполнение информации о размерностях для сообщения `SatNumbers`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (165, 1, -2);

-- Наполнение информации о размерностях для сообщения `SatElevation`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (167, 1, -2);

-- Наполнение информации о размерностях для сообщения `SatAzimuth`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (169, 1, -2);

-- Наполнение информации о размерностях для сообщения `PR`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (171, 1, -2);

-- Наполнение информации о размерностях для сообщения `SPR`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (173, 1, -2);

-- Наполнение информации о размерностях для сообщения `RPR`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (175, 1, -2);

-- Наполнение информации о размерностях для сообщения `SRPR`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (177, 1, -2);

-- Наполнение информации о размерностях для сообщения `SC`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (179, 1, -2);

-- Наполнение информации о размерностях для сообщения `SS`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (181, 1, -2);

-- Наполнение информации о размерностях для сообщения `CP`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (183, 1, -2);

-- Наполнение информации о размерностях для сообщения `SCP`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (185, 1, -2);

-- Наполнение информации о размерностях для сообщения `RCP_RC`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (187, 1, -2);

-- Наполнение информации о размерностях для сообщения `RCP_rc`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (189, 1, -2);

-- Наполнение информации о размерностях для сообщения `DP`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (191, 1, -2);

-- Наполнение информации о размерностях для сообщения `SRDP`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (193, 1, -2);

-- Наполнение информации о размерностях для сообщения `CNR`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (195, 1, -2);

-- Наполнение информации о размерностях для сообщения `CNR_4`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (197, 1, -2);

-- Наполнение информации о размерностях для сообщения `Flags`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (199, 1, -2);

-- Наполнение информации о размерностях для сообщения `IAmp`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (201, 1, -2);

-- Наполнение информации о размерностях для сообщения `QAmp`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (203, 1, -2);

-- Наполнение информации о размерностях для сообщения `TrackingTimeCA`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (205, 1, -2);

-- Наполнение информации о размерностях для сообщения `NavStatus`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (207, 1, -2);

-- Наполнение информации о размерностях для сообщения `IonoDelay`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (210, 1, -2);

-- Наполнение информации о размерностях для сообщения `GLOEphemeris`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (294, 1, 3), 
           (295, 1, 3), 
           (296, 1, 3);

-- Наполнение информации о размерностях для сообщения `GpsNavData0`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (334, 1, -2);

-- Наполнение информации о размерностях для сообщения `GpsRawNavData0`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (340, 1, -2);

-- Наполнение информации о размерностях для сообщения `GloNavData`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (345, 1, -2);

-- Наполнение информации о размерностях для сообщения `GloRawNavData`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (352, 1, -2);

-- Наполнение информации о размерностях для сообщения `SbasRawNavData`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (357, 1, 32);

-- Наполнение информации о размерностях для сообщения `GalRawNavData`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (363, 1, -2);

-- Наполнение информации о размерностях для сообщения `CompRawNavData`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (369, 1, -2);

-- Наполнение информации о размерностях для сообщения `Spectrum0`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (375, 1, -2);

-- Наполнение информации о размерностях для сообщения `Spectrum1`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (381, 1, -2);

-- Наполнение информации о размерностях для сообщения `GloPhaseDelay`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (383, 1, -2), 
           (384, 1, -2), 
           (385, 1, -2);

-- Наполнение информации о размерностях для сообщения `RotationMatrix`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (392, 1, 3), 
           (393, 1, 3);

-- Наполнение информации о размерностях для сообщения `RotationMatrixAndVectors`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (401, 1, 3), 
           (402, 1, 3), 
           (404, 1, 3), 
           (405, 1, 3), 
           (406, 1, 3);

-- Наполнение информации о размерностях для сообщения `InertialMeasurements`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (424, 1, 3), 
           (425, 1, 3);

-- Наполнение информации о размерностях для сообщения `RawMeas`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (445, 1, -2);

-- Наполнение информации о размерностях для сообщения `ClockOffsets`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (462, 1, -2);

-- Наполнение информации о размерностях для сообщения `RE`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (464, 1, -2);

-- Наполнение информации о размерностях для сообщения `ER`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (465, 1, -2);

-- Наполнение информации о размерностях для сообщения `Event`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (480, 1, -2);

-- Наполнение информации о размерностях для сообщения `Wrapper`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (485, 1, -2), 
           (486, 1, 2);

-- Наполнение информации о размерностях для сообщения `Params`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (487, 1, -2), 
           (488, 1, 2), 
           (489, 1, 2);

-- Наполнение информации о размерностях для сообщения `LoggingHistory`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (495, 1, -2), 
           (496, 1, -2), 
           (497, 1, -2), 
           (497, 2, -2);

-- Наполнение информации о размерностях для сообщения `Security0`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (504, 1, 5);

-- Наполнение информации о размерностях для сообщения `Security1`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (506, 1, 6);



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
