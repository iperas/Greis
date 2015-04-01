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
DROP TABLE IF EXISTS `msg_RcvBeiDouTimeOffset`;
DROP TABLE IF EXISTS `msg_GpsUtcParam`;
DROP TABLE IF EXISTS `msg_SbasUtcParam`;
DROP TABLE IF EXISTS `msg_GalUtcGpsParam`;
DROP TABLE IF EXISTS `msg_QzssUtcParam`;
DROP TABLE IF EXISTS `msg_BeiDouUtcParam`;
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
DROP TABLE IF EXISTS `msg_Baselines`;
DROP TABLE IF EXISTS `msg_FullRotationMatrix`;
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
DROP TABLE IF EXISTS `msg_RangeResidual`;
DROP TABLE IF EXISTS `msg_VelocityResidual`;
DROP TABLE IF EXISTS `msg_GPSAlm0`;
DROP TABLE IF EXISTS `msg_GALAlm`;
DROP TABLE IF EXISTS `msg_QZSSAlm`;
DROP TABLE IF EXISTS `msg_BeiDouAlm`;
DROP TABLE IF EXISTS `msg_GLOAlmanac`;
DROP TABLE IF EXISTS `msg_SBASAlmanac`;
DROP TABLE IF EXISTS `msg_GPSEphemeris0`;
DROP TABLE IF EXISTS `msg_GALEphemeris`;
DROP TABLE IF EXISTS `msg_QZSSEphemeris`;
DROP TABLE IF EXISTS `msg_BeiDouEphemeris`;
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
DROP TABLE IF EXISTS `msg_GloDelays`;
DROP TABLE IF EXISTS `msg_CalBandsDelay`;
DROP TABLE IF EXISTS `msg_RotationMatrix`;
DROP TABLE IF EXISTS `msg_RotationMatrixAndVectors`;
DROP TABLE IF EXISTS `msg_RotationAngles`;
DROP TABLE IF EXISTS `msg_AngularVelocity`;
DROP TABLE IF EXISTS `msg_InertialMeasurements`;
DROP TABLE IF EXISTS `msg_ExtEvent`;
DROP TABLE IF EXISTS `msg_PPSOffset`;
DROP TABLE IF EXISTS `msg_RcvTimeOffsAtPPS`;
DROP TABLE IF EXISTS `msg_HeadAndPitch`;
DROP TABLE IF EXISTS `msg_RefEpoch`;
DROP TABLE IF EXISTS `msg_RawMeas`;
DROP TABLE IF EXISTS `msg_PosVelVector`;
DROP TABLE IF EXISTS `msg_ClockOffsets`;
DROP TABLE IF EXISTS `msg_RE`;
DROP TABLE IF EXISTS `msg_ER`;
DROP TABLE IF EXISTS `msg_IonoParams0`;
DROP TABLE IF EXISTS `msg_QzssIonoParams`;
DROP TABLE IF EXISTS `msg_BeiDouIonoParams`;
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
DROP TABLE IF EXISTS `ct_SvDelay`;
DROP TABLE IF EXISTS `ct_BandDelay`;
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
    epochIndex INT UNSIGNED NOT NULL,
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

-- custom type 'SvDelay'
CREATE TABLE `ct_SvDelay` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `fcn` TINYINT, 
    `phase` FLOAT, 
    `range` FLOAT, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_ct_SvDelay_unixTimeEpoch` (`unixTimeEpoch`));

-- custom type 'BandDelay'
CREATE TABLE `ct_BandDelay` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `band` TINYINT, 
    `signal` TINYINT, 
    `delay` FLOAT, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_ct_BandDelay_unixTimeEpoch` (`unixTimeEpoch`));

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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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

-- message 'RcvSBASTimeOffset': [WO] SBAS to Receiver Time Offset
CREATE TABLE `msg_RcvSBASTimeOffset` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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

-- message 'RcvBeiDouTimeOffset': [CO] BeiDou to Receiver Time Offset
CREATE TABLE `msg_RcvBeiDouTimeOffset` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `val` DOUBLE, 
    `sval` DOUBLE, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RcvBeiDouTimeOffset_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_RcvBeiDouTimeOffset_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_RcvBeiDouTimeOffset_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_RcvBeiDouTimeOffset_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_RcvBeiDouTimeOffset_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'GpsUtcParam': [UO] GPS UTC Time Parameters
CREATE TABLE `msg_GpsUtcParam` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
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

-- message 'SbasUtcParam': [WU] SBAS UTC Time Parameters
CREATE TABLE `msg_SbasUtcParam` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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

-- message 'BeiDouUtcParam': [CU] BeiDou UTC Time Parameters
CREATE TABLE `msg_BeiDouUtcParam` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `utc` BIGINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_BeiDouUtcParam_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_BeiDouUtcParam_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_BeiDouUtcParam_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_BeiDouUtcParam_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_BeiDouUtcParam_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'GloUtcGpsParam': [NU] GLONASS UTC and GPS Time Parameters
CREATE TABLE `msg_GloUtcGpsParam` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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

-- message 'Baselines': [bL] Attitude Baselines
CREATE TABLE `msg_Baselines` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `bl0` BLOB, 
    `bl1` BLOB, 
    `bl2` BLOB, 
    `rms` BLOB, 
    `solType` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_Baselines_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_Baselines_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_Baselines_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_Baselines_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_Baselines_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'FullRotationMatrix': [mR] Attitude Full Rotation Matrix
CREATE TABLE `msg_FullRotationMatrix` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `q00` FLOAT, 
    `q01` FLOAT, 
    `q02` FLOAT, 
    `q10` FLOAT, 
    `q11` FLOAT, 
    `q12` FLOAT, 
    `q20` FLOAT, 
    `q21` FLOAT, 
    `q22` FLOAT, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_FullRotationMatrix_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_FullRotationMatrix_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_FullRotationMatrix_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_FullRotationMatrix_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_FullRotationMatrix_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'PosStat': [PS] Position Statistics
CREATE TABLE `msg_PosStat` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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

-- message 'RangeResidual': [rr] Satellite Range Residuals
CREATE TABLE `msg_RangeResidual` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `res` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RangeResidual_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_RangeResidual_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_RangeResidual_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_RangeResidual_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_RangeResidual_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'VelocityResidual': [vr] Satellite Velocity Residuals
CREATE TABLE `msg_VelocityResidual` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `res` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_VelocityResidual_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_VelocityResidual_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_VelocityResidual_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_VelocityResidual_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_VelocityResidual_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'GPSAlm0': [GA] GPS Almanac
CREATE TABLE `msg_GPSAlm0` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `gps` BIGINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_QZSSAlm_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_QZSSAlm_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_QZSSAlm_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_QZSSAlm_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_QZSSAlm_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'BeiDouAlm': [CA] BeiDou Almanac
CREATE TABLE `msg_BeiDouAlm` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `gps` BIGINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_BeiDouAlm_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_BeiDouAlm_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_BeiDouAlm_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_BeiDouAlm_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_BeiDouAlm_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'GLOAlmanac': [NA] GLONASS Almanac
CREATE TABLE `msg_GLOAlmanac` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
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

-- message 'SBASAlmanac': [WA] SBAS Almanac
CREATE TABLE `msg_SBASAlmanac` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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

-- message 'BeiDouEphemeris': [CN] BeiDou Ephemeris
CREATE TABLE `msg_BeiDouEphemeris` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `req` BIGINT UNSIGNED, 
    `tgd2` FLOAT, 
    `navType` TINYINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_BeiDouEphemeris_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_BeiDouEphemeris_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_BeiDouEphemeris_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_BeiDouEphemeris_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_BeiDouEphemeris_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'GLOEphemeris': [NE] GLONASS Ephemeris
CREATE TABLE `msg_GLOEphemeris` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
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

-- message 'SBASEhemeris': [WE] SBAS Ephemeris
CREATE TABLE `msg_SBASEhemeris` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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

-- message 'SbasRawNavData': [WD] SBAS Raw Navigation Data
CREATE TABLE `msg_SbasRawNavData` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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

-- message 'CompRawNavData': [cd] BeiDou Raw Navigation Data
CREATE TABLE `msg_CompRawNavData` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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

-- message 'GloDelays': [gC], [g1], [g2], [g3]: GLONASS Delays
CREATE TABLE `msg_GloDelays` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `del` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_GloDelays_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_GloDelays_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_GloDelays_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_GloDelays_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_GloDelays_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'CalBandsDelay': [gR] Code Delays of Receiver RF Bands
CREATE TABLE `msg_CalBandsDelay` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `d` BLOB, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_CalBandsDelay_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_CalBandsDelay_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_CalBandsDelay_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_CalBandsDelay_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_CalBandsDelay_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'RotationMatrix': [MR] Rotation Matrix
CREATE TABLE `msg_RotationMatrix` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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

-- message 'HeadAndPitch': [ha] Heading and Pitch
CREATE TABLE `msg_HeadAndPitch` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `heading` FLOAT, 
    `pitch` FLOAT, 
    `solType` TINYINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_HeadAndPitch_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_HeadAndPitch_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_HeadAndPitch_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_HeadAndPitch_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_HeadAndPitch_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'RefEpoch': [rE] Reference Epoch
CREATE TABLE `msg_RefEpoch` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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

-- message 'BeiDouIonoParams': [CI] BeiDou Ionospheric Parameters
CREATE TABLE `msg_BeiDouIonoParams` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `par` BIGINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_BeiDouIonoParams_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_BeiDouIonoParams_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_BeiDouIonoParams_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_BeiDouIonoParams_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_BeiDouIonoParams_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'Event': [==](EV) Event
CREATE TABLE `msg_Event` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
    epochIndex INT UNSIGNED NOT NULL, 
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
           (8, 'SvDelay', 9, 'ct_SvDelay'), 
           (9, 'BandDelay', 6, 'ct_BandDelay'), 
           (10, 'SvData2', -1, 'ct_SvData2'), 
           (11, 'Header', 6, 'ct_Header'), 
           (12, 'SlotRec', 14, 'ct_SlotRec'), 
           (13, 'ClkOffs', 8, 'ct_ClkOffs'), 
           (14, 'GPSAlm1', 46, 'ct_GPSAlm1'), 
           (15, 'GPSEphemeris1', -4, 'ct_GPSEphemeris1'), 
           (16, 'IonoParams1', 39, 'ct_IonoParams1'), 
           (17, 'GpsNavData1', -2, 'ct_GpsNavData1'), 
           (18, 'GpsRawNavData1', -2, 'ct_GpsRawNavData1');

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
           (14, 'RcvSBASTimeOffset', '[WO] SBAS to Receiver Time Offset', 17, 1, 3, 1, 'msg_RcvSBASTimeOffset'), 
           (15, 'RcvQZSSTimeOffset', '[QO] QZSS to Receiver Time Offset', 17, 1, 3, 1, 'msg_RcvQZSSTimeOffset'), 
           (16, 'RcvBeiDouTimeOffset', '[CO] BeiDou to Receiver Time Offset', 17, 1, 3, 1, 'msg_RcvBeiDouTimeOffset'), 
           (17, 'GpsUtcParam', '[UO] GPS UTC Time Parameters', 24, 1, 3, 1, 'msg_GpsUtcParam'), 
           (18, 'SbasUtcParam', '[WU] SBAS UTC Time Parameters', 32, 1, 3, 1, 'msg_SbasUtcParam'), 
           (19, 'GalUtcGpsParam', '[EU] GALILEO UTC and GPS Time Parameters', 40, 1, 3, 1, 'msg_GalUtcGpsParam'), 
           (20, 'QzssUtcParam', '[QU] QZSS UTC Time Parameters', 24, 1, 3, 1, 'msg_QzssUtcParam'), 
           (21, 'BeiDouUtcParam', '[CU] BeiDou UTC Time Parameters', 24, 1, 3, 1, 'msg_BeiDouUtcParam'), 
           (22, 'GloUtcGpsParam', '[NU] GLONASS UTC and GPS Time Parameters', 25, 1, 3, 1, 'msg_GloUtcGpsParam'), 
           (23, 'SolutionTime', '[ST] Solution Time-Tag', 6, 1, 3, 1, 'msg_SolutionTime'), 
           (24, 'Pos', '[PO] Cartesian Position', 30, 1, 3, 1, 'msg_Pos'), 
           (25, 'Vel', '[VE] Cartesian Velocity', 18, 1, 3, 1, 'msg_Vel'), 
           (26, 'PosVel', '[PV] Cartesian Position and Velocity', 46, 1, 3, 1, 'msg_PosVel'), 
           (27, 'GeoPos', '[PG] Geodetic Position', 30, 1, 3, 1, 'msg_GeoPos'), 
           (28, 'GeoVel', '[VG] Geodetic Velocity', 18, 1, 3, 1, 'msg_GeoVel'), 
           (29, 'Rms', '[SG] Position and Velocity RMS Errors', 18, 1, 3, 1, 'msg_Rms'), 
           (30, 'Dops', '[DP] Dilution of Precision (DOP)', 14, 1, 3, 1, 'msg_Dops'), 
           (31, 'PosCov', '[SP] Position Covariance Matrix', 42, 1, 3, 1, 'msg_PosCov'), 
           (32, 'VelCov', '[SV] Velocity Covariance Matrix', 42, 1, 3, 1, 'msg_VelCov'), 
           (33, 'Baseline', '[BL] Baseline', 34, 1, 3, 1, 'msg_Baseline'), 
           (34, 'Baselines', '[bL] Attitude Baselines', 52, 1, 3, 1, 'msg_Baselines'), 
           (35, 'FullRotationMatrix', '[mR] Attitude Full Rotation Matrix', 37, 1, 3, 1, 'msg_FullRotationMatrix'), 
           (36, 'PosStat', '[PS] Position Statistics', 9, 1, 3, 1, 'msg_PosStat'), 
           (37, 'PosCompTime', '[PT] Time of Continuous Position Computation', 5, 1, 3, 1, 'msg_PosCompTime'), 
           (38, 'SatIndex', '[SI] Satellite Indices', -2, 1, 3, 1, 'msg_SatIndex'), 
           (39, 'AntName', '[AN] Antenna Names', -2, 1, 3, 1, 'msg_AntName'), 
           (40, 'SatNumbers', '[NN] GLONASS Satellite System Numbers', -2, 1, 3, 1, 'msg_SatNumbers'), 
           (41, 'SatElevation', '[EL] Satellite Elevations', -2, 1, 3, 1, 'msg_SatElevation'), 
           (42, 'SatAzimuth', '[AZ] Satellite Azimuths', -2, 1, 3, 1, 'msg_SatAzimuth'), 
           (43, 'PR', '[RC], [R1], [R2], [R3], [R5], [Rl]: Pseudoranges', -2, 1, 3, 1, 'msg_PR'), 
           (44, 'SPR', '[rc], [r1], [r2], [r3], [r5], [rl]: Pseudoranges', -2, 1, 3, 1, 'msg_SPR'), 
           (45, 'RPR', '[1R], [2R], [3R], [5R], [lR]: Relative Pseudoranges', -2, 1, 3, 1, 'msg_RPR'), 
           (46, 'SRPR', '[1r], [2r], [3r], [5r], [lr]: Relative Pseudoranges', -2, 1, 3, 1, 'msg_SRPR'), 
           (47, 'SC', '[CC],[C1],[C2],[C3],[C5],[Cl]: Smoothing Corrections', -2, 1, 3, 1, 'msg_SC'), 
           (48, 'SS', '[cc],[c1],[c2],[c3],[c5],[cl]: Smoothing Corrections', -2, 1, 3, 1, 'msg_SS'), 
           (49, 'CP', '[PC], [P1], [P2], [P3], [P5], [Pl]: Carrier Phases', -2, 1, 3, 1, 'msg_CP'), 
           (50, 'SCP', '[pc], [p1], [p2], [p3], [p5], [pl]: Carrier Phases', -2, 1, 3, 1, 'msg_SCP'), 
           (51, 'RCP_RC', '[CP],[1P],[2P],[3P],[5P],[lP]: Relative Carrier Phases', -2, 1, 3, 1, 'msg_RCP_RC0'), 
           (52, 'RCP_rc', '[cp],[1p],[2p],[3p],[5p],[lp]: Relative Carrier Phases', -2, 1, 3, 1, 'msg_RCP_rc1'), 
           (53, 'DP', '[DC], [D1], [D2], [D3], [D5], [Dl]: Doppler', -2, 1, 3, 1, 'msg_DP'), 
           (54, 'SRDP', '[1d], [2d], [3d], [5d], [ld]: Relative Doppler', -2, 1, 3, 1, 'msg_SRDP'), 
           (55, 'CNR', '[EC], [E1], [E2], [E3], [E5], [El]: SNR', -2, 1, 3, 1, 'msg_CNR'), 
           (56, 'CNR_4', '[CE], [1E], [2E], [3E], [5E], [lE]: SNR x ', -2, 1, 3, 1, 'msg_CNR_4'), 
           (57, 'Flags', '[FC],[F1],[F2],[F3],[F5],[Fl]: Signal Lock Loop Flags', -2, 1, 3, 1, 'msg_Flags'), 
           (58, 'IAmp', '[ec], [e1], [e2], [e3], [e5]: Raw Inphases (I)', -1, 1, 3, 1, 'msg_IAmp'), 
           (59, 'QAmp', '[qc], [q1], [q2], [q3], [q5]: Raw Quadratures (Q)', -1, 1, 3, 1, 'msg_QAmp'), 
           (60, 'TrackingTimeCA', '[TC] CA/L1 Continuous Tracking Time', -2, 1, 3, 1, 'msg_TrackingTimeCA'), 
           (61, 'NavStatus', '[SS] Satellite Navigation Status', -2, 1, 3, 1, 'msg_NavStatus'), 
           (62, 'IonoDelay', '[ID] Ionospheric Delays', -2, 1, 3, 1, 'msg_IonoDelay'), 
           (63, 'RangeResidual', '[rr] Satellite Range Residuals', -1, 1, 3, 1, 'msg_RangeResidual'), 
           (64, 'VelocityResidual', '[vr] Satellite Velocity Residuals', -1, 1, 3, 1, 'msg_VelocityResidual'), 
           (65, 'GPSAlm0', '[GA] GPS Almanac', 47, 1, 3, 2, 'msg_GPSAlm0'), 
           (66, 'GALAlm', '[EA] GALILEO Almanac', 49, 1, 3, 2, 'msg_GALAlm'), 
           (67, 'QZSSAlm', '[QA] QZSS Almanac', 47, 0, 3, 1, 'msg_QZSSAlm'), 
           (68, 'BeiDouAlm', '[CA] BeiDou Almanac', 47, 0, 3, 1, 'msg_BeiDouAlm'), 
           (69, 'GLOAlmanac', '[NA] GLONASS Almanac', -3, 1, 3, 2, 'msg_GLOAlmanac'), 
           (70, 'SBASAlmanac', '[WA] SBAS Almanac', 51, 1, 3, 2, 'msg_SBASAlmanac'), 
           (71, 'GPSEphemeris0', '[GE] GPS Ephemeris', -3, 1, 3, 2, 'msg_GPSEphemeris0'), 
           (72, 'GALEphemeris', '[EN] GALILEO Ephemeris', 145, 1, 3, 2, 'msg_GALEphemeris'), 
           (73, 'QZSSEphemeris', '[QE] QZSS Ephemeris', -1, 1, 3, 1, 'msg_QZSSEphemeris'), 
           (74, 'BeiDouEphemeris', '[CN] BeiDou Ephemeris', 128, 1, 3, 1, 'msg_BeiDouEphemeris'), 
           (75, 'GLOEphemeris', '[NE] GLONASS Ephemeris', -3, 1, 3, 2, 'msg_GLOEphemeris'), 
           (76, 'SBASEhemeris', '[WE] SBAS Ephemeris', 73, 1, 3, 2, 'msg_SBASEhemeris'), 
           (77, 'GpsNavData0', '[GD] GPS Raw Navigation Data (obsolete)', -2, 1, 3, 1, 'msg_GpsNavData0'), 
           (78, 'GpsRawNavData0', '[gd] GPS Raw Navigation Data', -2, 1, 3, 1, 'msg_GpsRawNavData0'), 
           (79, 'QzssNavData', '[QD] QZSS Raw Navigation Data (obsolete)', -1, 0, 3, 1, 'msg_QzssNavData'), 
           (80, 'QzssRawNavData', '[qd] QZSS Raw Navigation Data', -1, 0, 3, 1, 'msg_QzssRawNavData'), 
           (81, 'GloNavData', '[LD] GLONASS Raw Navigation Data (obsolete)', -2, 1, 3, 1, 'msg_GloNavData'), 
           (82, 'GloRawNavData', '[lD] GLONASS Raw Navigation Data', -2, 1, 3, 1, 'msg_GloRawNavData'), 
           (83, 'SbasRawNavData', '[WD] SBAS Raw Navigation Data', 40, 1, 3, 1, 'msg_SbasRawNavData'), 
           (84, 'GalRawNavData', '[ED] GALILEO Raw Navigation Data', -2, 1, 3, 1, 'msg_GalRawNavData'), 
           (85, 'CompRawNavData', '[cd] BeiDou Raw Navigation Data', -2, 1, 3, 1, 'msg_CompRawNavData'), 
           (86, 'Spectrum0', '[sp] Spectrum', -1, 1, 3, 1, 'msg_Spectrum0'), 
           (87, 'Spectrum1', '[sP] Extended Spectrum', -1, 1, 3, 1, 'msg_Spectrum1'), 
           (88, 'GloDelays', '[gC], [g1], [g2], [g3]: GLONASS Delays', -2, 1, 3, 1, 'msg_GloDelays'), 
           (89, 'CalBandsDelay', '[gR] Code Delays of Receiver RF Bands', -1, 1, 3, 1, 'msg_CalBandsDelay'), 
           (90, 'RotationMatrix', '[MR] Rotation Matrix', 37, 1, 3, 1, 'msg_RotationMatrix'), 
           (91, 'RotationMatrixAndVectors', '[mr] Rotation Matrix and Vectors', 73, 1, 3, 1, 'msg_RotationMatrixAndVectors'), 
           (92, 'RotationAngles', '[AR] Rotation Angles', 30, 1, 3, 1, 'msg_RotationAngles'), 
           (93, 'AngularVelocity', '[AV] Angular Velocities', 22, 1, 3, 1, 'msg_AngularVelocity'), 
           (94, 'InertialMeasurements', '[IM] Inertial Measurements', 25, 1, 3, 1, 'msg_InertialMeasurements'), 
           (95, 'ExtEvent', '[XA], [XB] External Event', 10, 1, 3, 1, 'msg_ExtEvent'), 
           (96, 'PPSOffset', '[ZA], [ZB] PPS Offset', 5, 1, 3, 1, 'msg_PPSOffset'), 
           (97, 'RcvTimeOffsAtPPS', '[YA], [YB] Time Offset at PPS Generation Time', 10, 1, 3, 1, 'msg_RcvTimeOffsAtPPS'), 
           (98, 'HeadAndPitch', '[ha] Heading and Pitch', 10, 1, 3, 1, 'msg_HeadAndPitch'), 
           (99, 'RefEpoch', '[rE] Reference Epoch', 10, 3, 3, 1, 'msg_RefEpoch'), 
           (100, 'RawMeas', '[rM] Raw Measurements', -1, 3, 3, 1, 'msg_RawMeas'), 
           (101, 'PosVelVector', '[rV] Receiver’s Position and Velocity', 42, 3, 3, 1, 'msg_PosVelVector'), 
           (102, 'ClockOffsets', '[rT] Receiver Clock Offsets', -2, 3, 3, 1, 'msg_ClockOffsets'), 
           (103, 'RE', '[RE] Reply', -2, 0, 3, 1, 'msg_RE'), 
           (104, 'ER', '[ER] Error', -2, 0, 3, 1, 'msg_ER'), 
           (105, 'IonoParams0', '[IO] GPS Ionospheric Parameters', 39, 1, 3, 1, 'msg_IonoParams0'), 
           (106, 'QzssIonoParams', '[QI] QZSS Ionospheric Parameters', 39, 0, 3, 1, 'msg_QzssIonoParams'), 
           (107, 'BeiDouIonoParams', '[CI] BeiDou Ionospheric Parameters', 39, 0, 3, 1, 'msg_BeiDouIonoParams'), 
           (108, 'Event', '[==](EV) Event', -2, 1, 3, 1, 'msg_Event'), 
           (109, 'Latency', '[LT] Message Output Latency', 2, 1, 3, 1, 'msg_Latency'), 
           (110, 'Wrapper', '[>>] Wrapper', -2, 2, 3, 1, 'msg_Wrapper'), 
           (111, 'Params', '[PM] Parameters', -2, 2, 3, 1, 'msg_Params'), 
           (112, 'LoggingHistory', '[LH] Logging History', -1, 0, 3, 1, 'msg_LoggingHistory'), 
           (113, 'BaseInfo', '[BI] Base Station Information', 28, 1, 3, 1, 'msg_BaseInfo'), 
           (114, 'Security0', '[SE] Security', 6, 1, 3, 1, 'msg_Security0'), 
           (115, 'Security1', '[SM] Security for [rM]', 8, 3, 3, 1, 'msg_Security1'), 
           (116, 'TrackingTime', '[TT] CA/L1 Overall Continuous Tracking Time', 5, 1, 3, 1, 'msg_TrackingTime'), 
           (117, 'RcvOscOffs', '[OO] Oscillator Offset', 5, 1, 3, 1, 'msg_RcvOscOffs'), 
           (118, 'EpochEnd', '[||](EE) Epoch End', 1, 1, 3, 1, 'msg_EpochEnd');

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
           ('CO', 16), 
           ('UO', 17), 
           ('WU', 18), 
           ('EU', 19), 
           ('QU', 20), 
           ('CU', 21), 
           ('NU', 22), 
           ('ST', 23), 
           ('PO', 24), 
           ('VE', 25), 
           ('PV', 26), 
           ('PG', 27), 
           ('VG', 28), 
           ('SG', 29), 
           ('DP', 30), 
           ('SP', 31), 
           ('SV', 32), 
           ('BL', 33), 
           ('bL', 34), 
           ('mR', 35), 
           ('PS', 36), 
           ('PT', 37), 
           ('SI', 38), 
           ('AN', 39), 
           ('NN', 40), 
           ('EL', 41), 
           ('AZ', 42), 
           ('RC', 43), 
           ('R1', 43), 
           ('R2', 43), 
           ('R3', 43), 
           ('R5', 43), 
           ('Rl', 43), 
           ('rc', 44), 
           ('r1', 44), 
           ('r2', 44), 
           ('r3', 44), 
           ('r5', 44), 
           ('rl', 44), 
           ('1R', 45), 
           ('2R', 45), 
           ('3R', 45), 
           ('5R', 45), 
           ('lR', 45), 
           ('1r', 46), 
           ('2r', 46), 
           ('3r', 46), 
           ('5r', 46), 
           ('lr', 46), 
           ('CC', 47), 
           ('C1', 47), 
           ('C2', 47), 
           ('C3', 47), 
           ('C5', 47), 
           ('Cl', 47), 
           ('cc', 48), 
           ('c1', 48), 
           ('c2', 48), 
           ('c3', 48), 
           ('c5', 48), 
           ('cl', 48), 
           ('PC', 49), 
           ('P1', 49), 
           ('P2', 49), 
           ('P3', 49), 
           ('P5', 49), 
           ('Pl', 49), 
           ('pc', 50), 
           ('p1', 50), 
           ('p2', 50), 
           ('p3', 50), 
           ('p5', 50), 
           ('pl', 50), 
           ('CP', 51), 
           ('1P', 51), 
           ('2P', 51), 
           ('3P', 51), 
           ('5P', 51), 
           ('lP', 51), 
           ('cp', 52), 
           ('1p', 52), 
           ('2p', 52), 
           ('3p', 52), 
           ('5p', 52), 
           ('lp', 52), 
           ('DC', 53), 
           ('D1', 53), 
           ('D2', 53), 
           ('D3', 53), 
           ('D5', 53), 
           ('Dl', 53), 
           ('1d', 54), 
           ('2d', 54), 
           ('3d', 54), 
           ('5d', 54), 
           ('ld', 54), 
           ('EC', 55), 
           ('E1', 55), 
           ('E2', 55), 
           ('E3', 55), 
           ('E5', 55), 
           ('El', 55), 
           ('CE', 56), 
           ('1E', 56), 
           ('2E', 56), 
           ('3E', 56), 
           ('5E', 56), 
           ('lE', 56), 
           ('FC', 57), 
           ('F1', 57), 
           ('F2', 57), 
           ('F3', 57), 
           ('F5', 57), 
           ('Fl', 57), 
           ('ec', 58), 
           ('e1', 58), 
           ('e2', 58), 
           ('e3', 58), 
           ('e5', 58), 
           ('qc', 59), 
           ('q1', 59), 
           ('q2', 59), 
           ('q3', 59), 
           ('q5', 59), 
           ('TC', 60), 
           ('SS', 61), 
           ('ID', 62), 
           ('rr', 63), 
           ('vr', 64), 
           ('GA', 65), 
           ('EA', 66), 
           ('QA', 67), 
           ('CA', 68), 
           ('NA', 69), 
           ('WA', 70), 
           ('GE', 71), 
           ('EN', 72), 
           ('QE', 73), 
           ('CN', 74), 
           ('NE', 75), 
           ('WE', 76), 
           ('GD', 77), 
           ('gd', 78), 
           ('QD', 79), 
           ('qd', 80), 
           ('LD', 81), 
           ('lD', 82), 
           ('WD', 83), 
           ('ED', 84), 
           ('cd', 85), 
           ('sp', 86), 
           ('sP', 87), 
           ('gC', 88), 
           ('g1', 88), 
           ('g2', 88), 
           ('g3', 88), 
           ('gR', 89), 
           ('MR', 90), 
           ('mr', 91), 
           ('AR', 92), 
           ('AV', 93), 
           ('IM', 94), 
           ('XA', 95), 
           ('XB', 95), 
           ('ZA', 96), 
           ('ZB', 96), 
           ('YA', 97), 
           ('YB', 97), 
           ('ha', 98), 
           ('rE', 99), 
           ('rM', 100), 
           ('rV', 101), 
           ('rT', 102), 
           ('RE', 103), 
           ('ER', 104), 
           ('IO', 105), 
           ('QI', 106), 
           ('CI', 107), 
           ('==', 108), 
           ('LT', 109), 
           ('>>', 110), 
           ('PM', 111), 
           ('LH', 112), 
           ('BI', 113), 
           ('SE', 114), 
           ('SM', 115), 
           ('TT', 116), 
           ('OO', 117), 
           ('||', 118);

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
           (46, 'val', 'f8', '', 16), 
           (47, 'sval', 'f8', '', 16), 
           (48, 'cs', 'u1', '', 16), 
           (49, 'utc', 'UtcOffs', '', 17), 
           (50, 'cs', 'u1', '', 17), 
           (51, 'utc', 'UtcOffs', '', 18), 
           (52, 'utcsi', 'i1', '', 18), 
           (53, 'tow', 'u4', '', 18), 
           (54, 'wn', 'u2', '', 18), 
           (55, 'flags', 'u1', '', 18), 
           (56, 'cs', 'u1', '', 18), 
           (57, 'utc', 'UtcOffs', '', 19), 
           (58, 'a0g', 'f4', '', 19), 
           (59, 'a1g', 'f4', '', 19), 
           (60, 't0g', 'u4', '', 19), 
           (61, 'wn0g', 'u2', '', 19), 
           (62, 'flags', 'u2', '', 19), 
           (63, 'cs', 'u1', '', 19), 
           (64, 'utc', 'UtcOffs', '', 20), 
           (65, 'cs', 'u1', '', 20), 
           (66, 'utc', 'UtcOffs', '', 21), 
           (67, 'cs', 'u1', '', 21), 
           (68, 'tauSys', 'f8', '', 22), 
           (69, 'tauGps', 'f4', '', 22), 
           (70, 'B1', 'f4', '', 22), 
           (71, 'B2', 'f4', '', 22), 
           (72, 'KP', 'u1', '', 22), 
           (73, 'N4', 'u1', '', 22), 
           (74, 'Dn', 'i2', '', 22), 
           (75, 'cs', 'u1', '', 22), 
           (76, 'time', 'u4', '', 23), 
           (77, 'solType', 'u1', '', 23), 
           (78, 'cs', 'u1', '', 23), 
           (79, 'x', 'f8', '', 24), 
           (80, 'y', 'f8', '', 24), 
           (81, 'z', 'f8', '', 24), 
           (82, 'sigma', 'f4', '', 24), 
           (83, 'solType', 'u1', '', 24), 
           (84, 'cs', 'u1', '', 24), 
           (85, 'x', 'f4', '', 25), 
           (86, 'y', 'f4', '', 25), 
           (87, 'z', 'f4', '', 25), 
           (88, 'sigma', 'f4', '', 25), 
           (89, 'solType', 'u1', '', 25), 
           (90, 'cs', 'u1', '', 25), 
           (91, 'x', 'f8', '', 26), 
           (92, 'y', 'f8', '', 26), 
           (93, 'z', 'f8', '', 26), 
           (94, 'pSigma', 'f4', '', 26), 
           (95, 'vx', 'f4', '', 26), 
           (96, 'vy', 'f4', '', 26), 
           (97, 'vz', 'f4', '', 26), 
           (98, 'vSigma', 'f4', '', 26), 
           (99, 'solType', 'u1', '', 26), 
           (100, 'cs', 'u1', '', 26), 
           (101, 'lat', 'f8', '', 27), 
           (102, 'lon', 'f8', '', 27), 
           (103, 'alt', 'f8', '', 27), 
           (104, 'pSigma', 'f4', '', 27), 
           (105, 'solType', 'u1', '', 27), 
           (106, 'cs', 'u1', '', 27), 
           (107, 'lat', 'f4', '', 28), 
           (108, 'lon', 'f4', '', 28), 
           (109, 'alt', 'f4', '', 28), 
           (110, 'pSigma', 'f4', '', 28), 
           (111, 'solType', 'u1', '', 28), 
           (112, 'cs', 'u1', '', 28), 
           (113, 'hpos', 'f4', '', 29), 
           (114, 'vpos', 'f4', '', 29), 
           (115, 'hvel', 'f4', '', 29), 
           (116, 'vvel', 'f4', '', 29), 
           (117, 'solType', 'u1', '', 29), 
           (118, 'cs', 'u1', '', 29), 
           (119, 'hdop', 'f4', '', 30), 
           (120, 'vdop', 'f4', '', 30), 
           (121, 'tdop', 'f4', '', 30), 
           (122, 'solType', 'u1', '', 30), 
           (123, 'cs', 'u1', '', 30), 
           (124, 'xx', 'f4', '', 31), 
           (125, 'yy', 'f4', '', 31), 
           (126, 'zz', 'f4', '', 31), 
           (127, 'tt', 'f4', '', 31), 
           (128, 'xy', 'f4', '', 31), 
           (129, 'xz', 'f4', '', 31), 
           (130, 'xt', 'f4', '', 31), 
           (131, 'yz', 'f4', '', 31), 
           (132, 'yt', 'f4', '', 31), 
           (133, 'zt', 'f4', '', 31), 
           (134, 'solType', 'u1', '', 31), 
           (135, 'cs', 'u1', '', 31), 
           (136, 'xx', 'f4', '', 32), 
           (137, 'yy', 'f4', '', 32), 
           (138, 'zz', 'f4', '', 32), 
           (139, 'tt', 'f4', '', 32), 
           (140, 'xy', 'f4', '', 32), 
           (141, 'xz', 'f4', '', 32), 
           (142, 'xt', 'f4', '', 32), 
           (143, 'yz', 'f4', '', 32), 
           (144, 'yt', 'f4', '', 32), 
           (145, 'zt', 'f4', '', 32), 
           (146, 'solType', 'u1', '', 32), 
           (147, 'cs', 'u1', '', 32), 
           (148, 'x', 'f8', '', 33), 
           (149, 'y', 'f8', '', 33), 
           (150, 'z', 'f8', '', 33), 
           (151, 'sigma', 'f4', '', 33), 
           (152, 'solType', 'u1', '', 33), 
           (153, 'time', 'i4', '', 33), 
           (154, 'cs', 'u1', '', 33), 
           (155, 'bl0', 'f4', '', 34), 
           (156, 'bl1', 'f4', '', 34), 
           (157, 'bl2', 'f4', '', 34), 
           (158, 'rms', 'f4', '', 34), 
           (159, 'solType', 'u1', '', 34), 
           (160, 'cs', 'u1', '', 34), 
           (161, 'q00', 'f4', '', 35), 
           (162, 'q01', 'f4', '', 35), 
           (163, 'q02', 'f4', '', 35), 
           (164, 'q10', 'f4', '', 35), 
           (165, 'q11', 'f4', '', 35), 
           (166, 'q12', 'f4', '', 35), 
           (167, 'q20', 'f4', '', 35), 
           (168, 'q21', 'f4', '', 35), 
           (169, 'q22', 'f4', '', 35), 
           (170, 'cs', 'u1', '', 35), 
           (171, 'solType', 'u1', '', 36), 
           (172, 'gpsLocked', 'u1', '', 36), 
           (173, 'gloLocked', 'u1', '', 36), 
           (174, 'gpsAvail', 'u1', '', 36), 
           (175, 'gloAvail', 'u1', '', 36), 
           (176, 'gpsUsed', 'u1', '', 36), 
           (177, 'gloUsed', 'u1', '', 36), 
           (178, 'fixProg', 'u1', '', 36), 
           (179, 'cs', 'u1', '', 36), 
           (180, 'pt', 'u4', '', 37), 
           (181, 'cs', 'u1', '', 37), 
           (182, 'usi', 'u1', '', 38), 
           (183, 'cs', 'u1', '', 38), 
           (184, 'name', 'a1', '', 39), 
           (185, 'cs', 'u1', '', 39), 
           (186, 'osn', 'u1', '', 40), 
           (187, 'cs', 'u1', '', 40), 
           (188, 'elev', 'i1', '', 41), 
           (189, 'cs', 'u1', '', 41), 
           (190, 'azim', 'u1', '', 42), 
           (191, 'cs', 'u1', '', 42), 
           (192, 'pr', 'f8', '', 43), 
           (193, 'cs', 'u1', '', 43), 
           (194, 'spr', 'i4', '', 44), 
           (195, 'cs', 'u1', '', 44), 
           (196, 'rpr', 'f4', '', 45), 
           (197, 'cs', 'u1', '', 45), 
           (198, 'srpr', 'i2', '', 46), 
           (199, 'cs', 'u1', '', 46), 
           (200, 'smooth', 'Smooth', '', 47), 
           (201, 'cs', 'u1', '', 47), 
           (202, 'smooth', 'i2', '', 48), 
           (203, 'cs', 'u1', '', 48), 
           (204, 'cp', 'f8', '', 49), 
           (205, 'cs', 'u1', '', 49), 
           (206, 'scp', 'u4', '', 50), 
           (207, 'cs', 'u1', '', 50), 
           (208, 'rcp', 'f4', '', 51), 
           (209, 'cs', 'u1', '', 51), 
           (210, 'rcp', 'i4', '', 52), 
           (211, 'cs', 'u1', '', 52), 
           (212, 'dp', 'i4', '', 53), 
           (213, 'cs', 'u1', '', 53), 
           (214, 'srdp', 'i2', '', 54), 
           (215, 'cs', 'u1', '', 54), 
           (216, 'cnr', 'u1', '', 55), 
           (217, 'cs', 'u1', '', 55), 
           (218, 'cnrX4', 'u1', '', 56), 
           (219, 'cs', 'u1', '', 56), 
           (220, 'flags', 'u2', '', 57), 
           (221, 'cs', 'u1', '', 57), 
           (222, 'amp', 'i2', '', 58), 
           (223, 'cs', 'u1', '', 58), 
           (224, 'amp', 'i2', '', 59), 
           (225, 'cs', 'u1', '', 59), 
           (226, 'tt', 'u2', '', 60), 
           (227, 'cs', 'u1', '', 60), 
           (228, 'ns', 'u1', '', 61), 
           (229, 'solType', 'u1', '', 61), 
           (230, 'cs', 'u1', '', 61), 
           (231, 'delay', 'f4', '', 62), 
           (232, 'cs', 'u1', '', 62), 
           (233, 'res', 'f4', '', 63), 
           (234, 'cs', 'u1', '', 63), 
           (235, 'res', 'f4', '', 64), 
           (236, 'cs', 'u1', '', 64), 
           (237, 'sv', 'u1', '', 65), 
           (238, 'wna', 'i2', '', 65), 
           (239, 'toa', 'i4', '', 65), 
           (240, 'healthA', 'u1', '', 65), 
           (241, 'healthS', 'u1', '', 65), 
           (242, 'config', 'u1', '', 65), 
           (243, 'af1', 'f4', '', 65), 
           (244, 'af0', 'f4', '', 65), 
           (245, 'rootA', 'f4', '', 65), 
           (246, 'ecc', 'f4', '', 65), 
           (247, 'm0', 'f4', '', 65), 
           (248, 'omega0', 'f4', '', 65), 
           (249, 'argPer', 'f4', '', 65), 
           (250, 'deli', 'f4', '', 65), 
           (251, 'omegaDot', 'f4', '', 65), 
           (252, 'cs', 'u1', '', 65), 
           (253, 'gps', 'GPSAlm1', '', 66), 
           (254, 'iod', 'i2', '', 66), 
           (255, 'cs', 'u1', '', 66), 
           (256, 'gps', 'GPSAlm1', '', 67), 
           (257, 'gps', 'GPSAlm1', '', 68), 
           (258, 'sv', 'u1', '', 69), 
           (259, 'frqNum', 'i1', '', 69), 
           (260, 'dna', 'i2', '', 69), 
           (261, 'tlam', 'f4', '', 69), 
           (262, 'flags', 'u1', '', 69), 
           (263, 'tauN', 'f4', '', 69), 
           (264, 'tauSys', 'f8', '', 69), 
           (265, 'ecc', 'f4', '', 69), 
           (266, 'lambda', 'f4', '', 69), 
           (267, 'argPer', 'f4', '', 69), 
           (268, 'delT', 'f4', '', 69), 
           (269, 'delTdt', 'f4', '', 69), 
           (270, 'deli', 'f4', '', 69), 
           (271, 'n4', 'u1', '', 69), 
           (272, 'navType', 'u1', '', 69), 
           (273, 'gammaN', 'f4', '', 69), 
           (274, 'cs', 'u1', '', 69), 
           (275, 'waasPrn', 'u1', '', 70), 
           (276, 'gpsPrn', 'u1', '', 70), 
           (277, 'id', 'u1', '', 70), 
           (278, 'healthS', 'u1', '', 70), 
           (279, 'tod', 'u4', '', 70), 
           (280, 'xg', 'f8', '', 70), 
           (281, 'yg', 'f8', '', 70), 
           (282, 'zg', 'f8', '', 70), 
           (283, 'vxg', 'f4', '', 70), 
           (284, 'vyg', 'f4', '', 70), 
           (285, 'vzg', 'f4', '', 70), 
           (286, 'tow', 'u4', '', 70), 
           (287, 'wn', 'u2', '', 70), 
           (288, 'cs', 'u1', '', 70), 
           (289, 'req', 'GpsEphReqData', '', 71), 
           (290, 'cNavType', 'u1', '', 71), 
           (291, 'lTope', 'i4', '', 71), 
           (292, 'lTopc', 'i4', '', 71), 
           (293, 'dADot', 'f8', '', 71), 
           (294, 'fDelnDot', 'f4', '', 71), 
           (295, 'cURAoe', 'i1', '', 71), 
           (296, 'cURAoc', 'i1', '', 71), 
           (297, 'cURAoc1', 'i1', '', 71), 
           (298, 'cURAoc2', 'i1', '', 71), 
           (299, 'cs', 'u1', '', 71), 
           (300, 'req', 'GpsEphReqData', '', 72), 
           (301, 'bgdE1E5a', 'f4', '', 72), 
           (302, 'bgdE1E5b', 'f4', '', 72), 
           (303, 'ai0', 'f4', '', 72), 
           (304, 'ai1', 'f4', '', 72), 
           (305, 'ai2', 'f4', '', 72), 
           (306, 'sfi', 'u1', '', 72), 
           (307, 'navType', 'u1', '', 72), 
           (308, 'cs', 'u1', '', 72), 
           (309, 'gps', 'GPSEphemeris1', '', 73), 
           (310, 'cs', 'u1', '', 73), 
           (311, 'req', 'GpsEphReqData', '', 74), 
           (312, 'tgd2', 'f4', '', 74), 
           (313, 'navType', 'u1', '', 74), 
           (314, 'cs', 'u1', '', 74), 
           (315, 'sv', 'u1', '', 75), 
           (316, 'frqNum', 'i1', '', 75), 
           (317, 'dne', 'i2', '', 75), 
           (318, 'tk', 'i4', '', 75), 
           (319, 'tb', 'i4', '', 75), 
           (320, 'health', 'u1', '', 75), 
           (321, 'age', 'u1', '', 75), 
           (322, 'flags', 'u1', '', 75), 
           (323, 'r', 'f8', '', 75), 
           (324, 'v', 'f4', '', 75), 
           (325, 'w', 'f4', '', 75), 
           (326, 'tauSys', 'f8', '', 75), 
           (327, 'tau', 'f4', '', 75), 
           (328, 'gamma', 'f4', '', 75), 
           (329, 'fDelTauN', 'f4', '', 75), 
           (330, 'nFt', 'u1', '', 75), 
           (331, 'nN4', 'u1', '', 75), 
           (332, 'flags2', 'u2', '', 75), 
           (333, 'navType', 'u1', '', 75), 
           (334, 'beta', 'f4', '', 75), 
           (335, 'tauSysDot', 'f4', '', 75), 
           (336, 'ec', 'u1', '', 75), 
           (337, 'ee', 'u1', '', 75), 
           (338, 'fc', 'i1', '', 75), 
           (339, 'fe', 'i1', '', 75), 
           (340, 'reserv', 'u2', '', 75), 
           (341, 'cs', 'u1', '', 75), 
           (342, 'waasPrn', 'u1', '', 76), 
           (343, 'gpsPrn', 'u1', '', 76), 
           (344, 'iod', 'u1', '', 76), 
           (345, 'acc', 'u1', '', 76), 
           (346, 'tod', 'u4', '', 76), 
           (347, 'xg', 'f8', '', 76), 
           (348, 'yg', 'f8', '', 76), 
           (349, 'zg', 'f8', '', 76), 
           (350, 'vxg', 'f4', '', 76), 
           (351, 'vyg', 'f4', '', 76), 
           (352, 'vzg', 'f4', '', 76), 
           (353, 'vvxg', 'f4', '', 76), 
           (354, 'vvyg', 'f4', '', 76), 
           (355, 'vvzg', 'f4', '', 76), 
           (356, 'agf0', 'f4', '', 76), 
           (357, 'agf1', 'f4', '', 76), 
           (358, 'tow', 'u4', '', 76), 
           (359, 'wn', 'u2', '', 76), 
           (360, 'flags', 'u2', '', 76), 
           (361, 'cs', 'u1', '', 76), 
           (362, 'recSize', 'u1', '', 77), 
           (363, 'dat', 'SvData0', '', 77), 
           (364, 'cs', 'u1', '', 77), 
           (365, 'prn', 'u1', '', 78), 
           (366, 'time', 'u4', '', 78), 
           (367, 'type', 'u1', '', 78), 
           (368, 'len', 'u1', '', 78), 
           (369, 'data', 'u4', '', 78), 
           (370, 'cs', 'u1', '', 78), 
           (371, 'data', 'GpsNavData1', '', 79), 
           (372, 'data', 'GpsRawNavData1', '', 80), 
           (373, 'recSize', 'u1', '', 81), 
           (374, 'dat', 'SvData1', '', 81), 
           (375, 'cs', 'u1', '', 81), 
           (376, 'num', 'u1', '', 82), 
           (377, 'fcn', 'i1', '', 82), 
           (378, 'time', 'u4', '', 82), 
           (379, 'type', 'u1', '', 82), 
           (380, 'len', 'u1', '', 82), 
           (381, 'data', 'u4', '', 82), 
           (382, 'cs', 'u1', '', 82), 
           (383, 'prn', 'u1', '', 83), 
           (384, 'time', 'u4', '', 83), 
           (385, 'reserv', 'u2', '', 83), 
           (386, 'data', 'u1', '', 83), 
           (387, 'cs', 'u1', '', 83), 
           (388, 'prn', 'u1', '', 84), 
           (389, 'time', 'u4', '', 84), 
           (390, 'type', 'u1', '', 84), 
           (391, 'len', 'u1', '', 84), 
           (392, 'data', 'u1', '', 84), 
           (393, 'cs', 'u1', '', 84), 
           (394, 'prn', 'u1', '', 85), 
           (395, 'time', 'u4', '', 85), 
           (396, 'type', 'u1', '', 85), 
           (397, 'len', 'u1', '', 85), 
           (398, 'data', 'u4', '', 85), 
           (399, 'cs', 'u1', '', 85), 
           (400, 'currFrq', 'i2', '', 86), 
           (401, 'finalFrq', 'i2', '', 86), 
           (402, 'n', 'u1', '', 86), 
           (403, 'm', 'u1', '', 86), 
           (404, 's', 'SpecData', '', 86), 
           (405, 'cs', 'u1', '', 86), 
           (406, 'currFrq', 'i2', '', 87), 
           (407, 'finalFrq', 'i2', '', 87), 
           (408, 'n', 'u1', '', 87), 
           (409, 'm', 'u1', '', 87), 
           (410, 's', 'ExtSpecData', '', 87), 
           (411, 'cs', 'u1', '', 87), 
           (412, 'del', 'SvDelay', '', 88), 
           (413, 'cs', 'u1', '', 88), 
           (414, 'd', 'BandDelay', '', 89), 
           (415, 'cs', 'u1', '', 89), 
           (416, 'time', 'u4', '', 90), 
           (417, 'q00', 'f4', '', 90), 
           (418, 'q01', 'f4', '', 90), 
           (419, 'q02', 'f4', '', 90), 
           (420, 'q12', 'f4', '', 90), 
           (421, 'rms', 'f4', '', 90), 
           (422, 'solType', 'u1', '', 90), 
           (423, 'flag', 'u1', '', 90), 
           (424, 'cs', 'u1', '', 90), 
           (425, 'time', 'u4', '', 91), 
           (426, 'q00', 'f4', '', 91), 
           (427, 'q01', 'f4', '', 91), 
           (428, 'q02', 'f4', '', 91), 
           (429, 'q12', 'f4', '', 91), 
           (430, 'rms', 'f4', '', 91), 
           (431, 'solType', 'u1', '', 91), 
           (432, 'flag', 'u1', '', 91), 
           (433, 'bl0', 'f4', '', 91), 
           (434, 'bl1', 'f4', '', 91), 
           (435, 'bl2', 'f4', '', 91), 
           (436, 'cs', 'u1', '', 91), 
           (437, 'time', 'u4', '', 92), 
           (438, 'pitch', 'f4', '', 92), 
           (439, 'roll', 'f4', '', 92), 
           (440, 'heading', 'f4', '', 92), 
           (441, 'pitchRms', 'f4', '', 92), 
           (442, 'rollRms', 'f4', '', 92), 
           (443, 'headingRms', 'f4', '', 92), 
           (444, 'flags', 'u1', '', 92), 
           (445, 'cs', 'u1', '', 92), 
           (446, 'time', 'u4', '', 93), 
           (447, 'x', 'f4', '', 93), 
           (448, 'y', 'f4', '', 93), 
           (449, 'z', 'f4', '', 93), 
           (450, 'rms', 'f4', '', 93), 
           (451, 'flags', 'u1', '', 93), 
           (452, 'cs', 'u1', '', 93), 
           (453, 'accelerations', 'f4', '', 94), 
           (454, 'angularVelocities', 'f4', '', 94), 
           (455, 'cs', 'u1', '', 94), 
           (456, 'ms', 'i4', '', 95), 
           (457, 'ns', 'i4', '', 95), 
           (458, 'timeScale', 'u1', '', 95), 
           (459, 'cs', 'u1', '', 95), 
           (460, 'offs', 'f4', '', 96), 
           (461, 'cs', 'u1', '', 96), 
           (462, 'offs', 'f8', '', 97), 
           (463, 'timeScale', 'u1', '', 97), 
           (464, 'cs', 'u1', '', 97), 
           (465, 'heading', 'f4', '', 98), 
           (466, 'pitch', 'f4', '', 98), 
           (467, 'solType', 'u1', '', 98), 
           (468, 'cs', 'u1', '', 98), 
           (469, 'sample', 'u2', '', 99), 
           (470, 'scale', 'u2', '', 99), 
           (471, 'reftime', 'u4', '', 99), 
           (472, 'crc16', 'u2', '', 99), 
           (473, 'sample', 'u2', '', 100), 
           (474, 'scale', 'u2', '', 100), 
           (475, 'reftime', 'u4', '', 100), 
           (476, 'clock', 'i2', '', 100), 
           (477, 'flags', 'u2', '', 100), 
           (478, 'svd', 'SvData2', '', 100), 
           (479, 'crc16', 'u2', '', 100), 
           (480, 'sample', 'u2', '', 101), 
           (481, 'delta', 'u2', '', 101), 
           (482, 'word1', 'u4', '', 101), 
           (483, 'word2', 'u4', '', 101), 
           (484, 'word3', 'u4', '', 101), 
           (485, 'word4', 'u4', '', 101), 
           (486, 'word5', 'u4', '', 101), 
           (487, 'word6', 'u4', '', 101), 
           (488, 'word7', 'u4', '', 101), 
           (489, 'word8', 'u4', '', 101), 
           (490, 'word9', 'u4', '', 101), 
           (491, 'crc16', 'u2', '', 101), 
           (492, 'sample', 'u2', '', 102), 
           (493, 'reserved', 'u2', '', 102), 
           (494, 'recSize', 'u1', '', 102), 
           (495, 'Offs', 'ClkOffs', '', 102), 
           (496, 'crc16', 'u2', '', 102), 
           (497, 'reply', 'a1', '', 103), 
           (498, 'error', 'a1', '', 104), 
           (499, 'tot', 'u4', '', 105), 
           (500, 'wn', 'u2', '', 105), 
           (501, 'alpha0', 'f4', '', 105), 
           (502, 'alpha1', 'f4', '', 105), 
           (503, 'alpha2', 'f4', '', 105), 
           (504, 'alpha3', 'f4', '', 105), 
           (505, 'beta0', 'f4', '', 105), 
           (506, 'beta1', 'f4', '', 105), 
           (507, 'beta2', 'f4', '', 105), 
           (508, 'beta3', 'f4', '', 105), 
           (509, 'cs', 'u1', '', 105), 
           (510, 'par', 'IonoParams1', '', 106), 
           (511, 'par', 'IonoParams1', '', 107), 
           (512, 'time', 'u4', '', 108), 
           (513, 'type', 'u1', '', 108), 
           (514, 'data', 'u1', '', 108), 
           (515, 'cs', 'u1', '', 108), 
           (516, 'lt', 'u1', '', 109), 
           (517, 'cs', 'u1', '', 109), 
           (518, 'id', 'u1', '', 110), 
           (519, 'data', 'u1', '', 110), 
           (520, 'cs', 'a1', '', 110), 
           (521, 'params', 'a1', '', 111), 
           (522, 'delim', 'a1', ',@', 111), 
           (523, 'cs', 'a1', '', 111), 
           (524, 'svsCount', 'u1', '', 112), 
           (525, 'targetStream', 'u1', '', 112), 
           (526, 'issue', 'u2', '', 112), 
           (527, 'bitsCount', 'u2', '', 112), 
           (528, 'lastBitTime', 'u4', '', 112), 
           (529, 'uids', 'u1', '', 112), 
           (530, 'pad', 'u1', '', 112), 
           (531, 'hist', 'u4', '', 112), 
           (532, 'x', 'f8', '', 113), 
           (533, 'y', 'f8', '', 113), 
           (534, 'z', 'f8', '', 113), 
           (535, 'id', 'u2', '', 113), 
           (536, 'solType', 'u1', '', 113), 
           (537, 'cs', 'u1', '', 113), 
           (538, 'data', 'u1', '', 114), 
           (539, 'cs', 'u1', '', 114), 
           (540, 'data', 'u1', '', 115), 
           (541, 'crc16', 'u2', '', 115), 
           (542, 'tt', 'u4', '', 116), 
           (543, 'cs', 'u1', '', 116), 
           (544, 'val', 'f4', '', 117), 
           (545, 'cs', 'u1', '', 117), 
           (546, 'cs', 'u1', '', 118);

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
           (50, 'fcn', 'i1', '', 8), 
           (51, 'phase', 'f4', '', 8), 
           (52, 'range', 'f4', '', 8), 
           (53, 'band', 'i1', '', 9), 
           (54, 'signal', 'i1', '', 9), 
           (55, 'delay', 'f4', '', 9), 
           (56, 'header', 'Header', '', 10), 
           (57, 'slot', 'SlotRec', '', 10), 
           (58, 'refrange', 'u4', '', 11), 
           (59, 'usi', 'u1', '', 11), 
           (60, 'num', 'u1', '', 11), 
           (61, 'svstOrDelrange', 'i2', '', 12), 
           (62, 'word1', 'u4', '', 12), 
           (63, 'flags', 'u2', '', 12), 
           (64, 'lock', 'u2', '', 12), 
           (65, 'word2', 'u4', '', 12), 
           (66, 'word1', 'u4', '', 13), 
           (67, 'word2', 'u4', '', 13), 
           (68, 'sv', 'u1', '', 14), 
           (69, 'wna', 'i2', '', 14), 
           (70, 'toa', 'i4', '', 14), 
           (71, 'healthA', 'u1', '', 14), 
           (72, 'healthS', 'u1', '', 14), 
           (73, 'config', 'u1', '', 14), 
           (74, 'af1', 'f4', '', 14), 
           (75, 'af0', 'f4', '', 14), 
           (76, 'rootA', 'f4', '', 14), 
           (77, 'ecc', 'f4', '', 14), 
           (78, 'm0', 'f4', '', 14), 
           (79, 'omega0', 'f4', '', 14), 
           (80, 'argPer', 'f4', '', 14), 
           (81, 'deli', 'f4', '', 14), 
           (82, 'omegaDot', 'f4', '', 14), 
           (83, 'req', 'GpsEphReqData', '', 15), 
           (84, 'cNavType', 'u1', '', 15), 
           (85, 'lTope', 'i4', '', 15), 
           (86, 'lTopc', 'i4', '', 15), 
           (87, 'dADot', 'f8', '', 15), 
           (88, 'fDelnDot', 'f4', '', 15), 
           (89, 'cURAoe', 'i1', '', 15), 
           (90, 'cURAoc', 'i1', '', 15), 
           (91, 'cURAoc1', 'i1', '', 15), 
           (92, 'cURAoc2', 'i1', '', 15), 
           (93, 'tot', 'u4', '', 16), 
           (94, 'wn', 'u2', '', 16), 
           (95, 'alpha0', 'f4', '', 16), 
           (96, 'alpha1', 'f4', '', 16), 
           (97, 'alpha2', 'f4', '', 16), 
           (98, 'alpha3', 'f4', '', 16), 
           (99, 'beta0', 'f4', '', 16), 
           (100, 'beta1', 'f4', '', 16), 
           (101, 'beta2', 'f4', '', 16), 
           (102, 'beta3', 'f4', '', 16), 
           (103, 'cs', 'u1', '', 16), 
           (104, 'recSize', 'u1', '', 17), 
           (105, 'dat', 'SvData0', '', 17), 
           (106, 'cs', 'u1', '', 17), 
           (107, 'prn', 'u1', '', 18), 
           (108, 'time', 'u4', '', 18), 
           (109, 'type', 'u1', '', 18), 
           (110, 'len', 'u1', '', 18), 
           (111, 'data', 'u4', '', 18), 
           (112, 'cs', 'u1', '', 18);

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
    VALUES (57, 1, -2);

-- Наполнение информации о размерностях для пользовательского типа `GpsNavData1`
INSERT INTO `customTypeVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (105, 1, -2);

-- Наполнение информации о размерностях для пользовательского типа `GpsRawNavData1`
INSERT INTO `customTypeVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (111, 1, -2);

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

-- Наполнение информации о размерностях для сообщения `Baselines`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (155, 1, 3), 
           (156, 1, 3), 
           (157, 1, 3), 
           (158, 1, 3), 
           (159, 1, 3);

-- Наполнение информации о размерностях для сообщения `SatIndex`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (182, 1, -2);

-- Наполнение информации о размерностях для сообщения `AntName`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (184, 1, -2);

-- Наполнение информации о размерностях для сообщения `SatNumbers`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (186, 1, -2);

-- Наполнение информации о размерностях для сообщения `SatElevation`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (188, 1, -2);

-- Наполнение информации о размерностях для сообщения `SatAzimuth`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (190, 1, -2);

-- Наполнение информации о размерностях для сообщения `PR`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (192, 1, -2);

-- Наполнение информации о размерностях для сообщения `SPR`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (194, 1, -2);

-- Наполнение информации о размерностях для сообщения `RPR`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (196, 1, -2);

-- Наполнение информации о размерностях для сообщения `SRPR`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (198, 1, -2);

-- Наполнение информации о размерностях для сообщения `SC`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (200, 1, -2);

-- Наполнение информации о размерностях для сообщения `SS`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (202, 1, -2);

-- Наполнение информации о размерностях для сообщения `CP`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (204, 1, -2);

-- Наполнение информации о размерностях для сообщения `SCP`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (206, 1, -2);

-- Наполнение информации о размерностях для сообщения `RCP_RC`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (208, 1, -2);

-- Наполнение информации о размерностях для сообщения `RCP_rc`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (210, 1, -2);

-- Наполнение информации о размерностях для сообщения `DP`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (212, 1, -2);

-- Наполнение информации о размерностях для сообщения `SRDP`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (214, 1, -2);

-- Наполнение информации о размерностях для сообщения `CNR`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (216, 1, -2);

-- Наполнение информации о размерностях для сообщения `CNR_4`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (218, 1, -2);

-- Наполнение информации о размерностях для сообщения `Flags`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (220, 1, -2);

-- Наполнение информации о размерностях для сообщения `IAmp`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (222, 1, -2);

-- Наполнение информации о размерностях для сообщения `QAmp`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (224, 1, -2);

-- Наполнение информации о размерностях для сообщения `TrackingTimeCA`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (226, 1, -2);

-- Наполнение информации о размерностях для сообщения `NavStatus`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (228, 1, -2);

-- Наполнение информации о размерностях для сообщения `IonoDelay`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (231, 1, -2);

-- Наполнение информации о размерностях для сообщения `RangeResidual`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (233, 1, -2);

-- Наполнение информации о размерностях для сообщения `VelocityResidual`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (235, 1, -2);

-- Наполнение информации о размерностях для сообщения `GLOEphemeris`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (323, 1, 3), 
           (324, 1, 3), 
           (325, 1, 3);

-- Наполнение информации о размерностях для сообщения `GpsNavData0`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (363, 1, -2);

-- Наполнение информации о размерностях для сообщения `GpsRawNavData0`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (369, 1, -2);

-- Наполнение информации о размерностях для сообщения `GloNavData`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (374, 1, -2);

-- Наполнение информации о размерностях для сообщения `GloRawNavData`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (381, 1, -2);

-- Наполнение информации о размерностях для сообщения `SbasRawNavData`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (386, 1, 32);

-- Наполнение информации о размерностях для сообщения `GalRawNavData`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (392, 1, -2);

-- Наполнение информации о размерностях для сообщения `CompRawNavData`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (398, 1, -2);

-- Наполнение информации о размерностях для сообщения `Spectrum0`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (404, 1, -2);

-- Наполнение информации о размерностях для сообщения `Spectrum1`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (410, 1, -2);

-- Наполнение информации о размерностях для сообщения `GloDelays`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (412, 1, -2);

-- Наполнение информации о размерностях для сообщения `CalBandsDelay`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (414, 1, -2);

-- Наполнение информации о размерностях для сообщения `RotationMatrix`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (421, 1, 3), 
           (422, 1, 3);

-- Наполнение информации о размерностях для сообщения `RotationMatrixAndVectors`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (430, 1, 3), 
           (431, 1, 3), 
           (433, 1, 3), 
           (434, 1, 3), 
           (435, 1, 3);

-- Наполнение информации о размерностях для сообщения `InertialMeasurements`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (453, 1, 3), 
           (454, 1, 3);

-- Наполнение информации о размерностях для сообщения `RawMeas`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (478, 1, -2);

-- Наполнение информации о размерностях для сообщения `ClockOffsets`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (495, 1, -2);

-- Наполнение информации о размерностях для сообщения `RE`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (497, 1, -2);

-- Наполнение информации о размерностях для сообщения `ER`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (498, 1, -2);

-- Наполнение информации о размерностях для сообщения `Event`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (514, 1, -2);

-- Наполнение информации о размерностях для сообщения `Wrapper`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (519, 1, -2), 
           (520, 1, 2);

-- Наполнение информации о размерностях для сообщения `Params`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (521, 1, -2), 
           (522, 1, 2), 
           (523, 1, 2);

-- Наполнение информации о размерностях для сообщения `LoggingHistory`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (529, 1, -2), 
           (530, 1, -2), 
           (531, 1, -2), 
           (531, 2, -2);

-- Наполнение информации о размерностях для сообщения `Security0`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (538, 1, 5);

-- Наполнение информации о размерностях для сообщения `Security1`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (540, 1, 6);



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
