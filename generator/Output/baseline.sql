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
DROP TABLE IF EXISTS `msg_RcvIrnssTimeOffset`;
DROP TABLE IF EXISTS `msg_GpsUtcParam`;
DROP TABLE IF EXISTS `msg_SbasUtcParam`;
DROP TABLE IF EXISTS `msg_GalUtcGpsParam`;
DROP TABLE IF EXISTS `msg_QzssUtcParam`;
DROP TABLE IF EXISTS `msg_BeiDouUtcParam`;
DROP TABLE IF EXISTS `msg_IrnssUtcParam`;
DROP TABLE IF EXISTS `msg_GloUtcGpsParam`;
DROP TABLE IF EXISTS `msg_SolutionTime`;
DROP TABLE IF EXISTS `msg_Pos`;
DROP TABLE IF EXISTS `msg_SpecificCrtPos0`;
DROP TABLE IF EXISTS `msg_Vel`;
DROP TABLE IF EXISTS `msg_PosVel`;
DROP TABLE IF EXISTS `msg_GeoPos`;
DROP TABLE IF EXISTS `msg_SpecificCrtPos1`;
DROP TABLE IF EXISTS `msg_GeoVel`;
DROP TABLE IF EXISTS `msg_Rms`;
DROP TABLE IF EXISTS `msg_LocalPlanePos`;
DROP TABLE IF EXISTS `msg_RSLocalPlanePos`;
DROP TABLE IF EXISTS `msg_Dops`;
DROP TABLE IF EXISTS `msg_PosCov`;
DROP TABLE IF EXISTS `msg_VelCov`;
DROP TABLE IF EXISTS `msg_Baseline`;
DROP TABLE IF EXISTS `msg_Baselines`;
DROP TABLE IF EXISTS `msg_FullRotationMatrix`;
DROP TABLE IF EXISTS `msg_PosStat`;
DROP TABLE IF EXISTS `msg_PosCompTime`;
DROP TABLE IF EXISTS `msg_ExtSatIndex`;
DROP TABLE IF EXISTS `msg_SatIndex`;
DROP TABLE IF EXISTS `msg_AntName`;
DROP TABLE IF EXISTS `msg_SatNumbers`;
DROP TABLE IF EXISTS `msg_SatElevation`;
DROP TABLE IF EXISTS `msg_SatAzimuth`;
DROP TABLE IF EXISTS `msg_PR`;
DROP TABLE IF EXISTS `msg_SPR`;
DROP TABLE IF EXISTS `msg_RPR`;
DROP TABLE IF EXISTS `msg_SRPR`;
DROP TABLE IF EXISTS `msg_PrCorr`;
DROP TABLE IF EXISTS `msg_SC`;
DROP TABLE IF EXISTS `msg_SS`;
DROP TABLE IF EXISTS `msg_CP`;
DROP TABLE IF EXISTS `msg_SCP`;
DROP TABLE IF EXISTS `msg_RCP_RC0`;
DROP TABLE IF EXISTS `msg_RCP_rc1`;
DROP TABLE IF EXISTS `msg_PhCorr`;
DROP TABLE IF EXISTS `msg_DP`;
DROP TABLE IF EXISTS `msg_SRDP`;
DROP TABLE IF EXISTS `msg_CNR`;
DROP TABLE IF EXISTS `msg_CNR_4`;
DROP TABLE IF EXISTS `msg_CNR_2560`;
DROP TABLE IF EXISTS `msg_CNR_2561`;
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
DROP TABLE IF EXISTS `msg_IrnssAlm`;
DROP TABLE IF EXISTS `msg_GLOAlmanac`;
DROP TABLE IF EXISTS `msg_SBASAlmanac`;
DROP TABLE IF EXISTS `msg_GPSEphemeris0`;
DROP TABLE IF EXISTS `msg_GALEphemeris`;
DROP TABLE IF EXISTS `msg_QZSSEphemeris`;
DROP TABLE IF EXISTS `msg_BeiDouEphemeris`;
DROP TABLE IF EXISTS `msg_GLOEphemeris`;
DROP TABLE IF EXISTS `msg_SBASEhemeris`;
DROP TABLE IF EXISTS `msg_IrnssEphemeris`;
DROP TABLE IF EXISTS `msg_GpsRawNavData0`;
DROP TABLE IF EXISTS `msg_QzssRawNavData`;
DROP TABLE IF EXISTS `msg_GloRawNavData`;
DROP TABLE IF EXISTS `msg_SbasRawNavData`;
DROP TABLE IF EXISTS `msg_GalRawNavData`;
DROP TABLE IF EXISTS `msg_CompRawNavData`;
DROP TABLE IF EXISTS `msg_IrnssRawNavData`;
DROP TABLE IF EXISTS `msg_GpsNavData0`;
DROP TABLE IF EXISTS `msg_QzssNavData`;
DROP TABLE IF EXISTS `msg_GloNavData`;
DROP TABLE IF EXISTS `msg_Spectrum0`;
DROP TABLE IF EXISTS `msg_Spectrum1`;
DROP TABLE IF EXISTS `msg_MDM_Spectrum`;
DROP TABLE IF EXISTS `msg_GloDelays`;
DROP TABLE IF EXISTS `msg_CalBandsDelay`;
DROP TABLE IF EXISTS `msg_RotationMatrix`;
DROP TABLE IF EXISTS `msg_RotationMatrixAndVectors`;
DROP TABLE IF EXISTS `msg_RotationAngles`;
DROP TABLE IF EXISTS `msg_AngularVelocity`;
DROP TABLE IF EXISTS `msg_InertialMeasurements`;
DROP TABLE IF EXISTS `msg_AccMag`;
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
DROP TABLE IF EXISTS `msg_IrnssIonoParams`;
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
DROP TABLE IF EXISTS `ct_UtcOffs`;
DROP TABLE IF EXISTS `ct_ESI`;
DROP TABLE IF EXISTS `ct_Smooth`;
DROP TABLE IF EXISTS `ct_GpsEphReqData`;
DROP TABLE IF EXISTS `ct_GpsEphOptData`;
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
    `dtls` SMALLINT, 
    `dn` SMALLINT UNSIGNED, 
    `wnlsf` SMALLINT UNSIGNED, 
    `dtlsf` SMALLINT, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_ct_UtcOffs_unixTimeEpoch` (`unixTimeEpoch`));

-- custom type 'ESI'
CREATE TABLE `ct_ESI` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `ssid` SMALLINT UNSIGNED, 
    `svid` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_ct_ESI_unixTimeEpoch` (`unixTimeEpoch`));

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
    `sv` SMALLINT UNSIGNED, 
    `tow` INT UNSIGNED, 
    `flags` SMALLINT UNSIGNED, 
    `iodc` SMALLINT, 
    `toc` INT, 
    `ura` SMALLINT, 
    `healthS` SMALLINT UNSIGNED, 
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

-- custom type 'GpsEphOptData'
CREATE TABLE `ct_GpsEphOptData` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `navType` SMALLINT UNSIGNED, 
    `lTope` INT, 
    `lTopc` INT, 
    `dADot` DOUBLE, 
    `cURAoc` SMALLINT, 
    `cURAoc1` SMALLINT, 
    `cURAoc2` SMALLINT, 
    `fIscL1CA` FLOAT, 
    `fIscL5I5` FLOAT, 
    `fIscL1CP` FLOAT, 
    `DAf0` FLOAT, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_ct_GpsEphOptData_unixTimeEpoch` (`unixTimeEpoch`));

-- custom type 'SvData0'
CREATE TABLE `ct_SvData0` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `prn` SMALLINT, 
    `cnt` SMALLINT UNSIGNED, 
    `data` BLOB, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_ct_SvData0_unixTimeEpoch` (`unixTimeEpoch`));

-- custom type 'SvData1'
CREATE TABLE `ct_SvData1` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `fcn1` SMALLINT, 
    `cnt` SMALLINT UNSIGNED, 
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
    `fcn` SMALLINT, 
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
    `band` SMALLINT, 
    `signal` SMALLINT, 
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
    `usi` SMALLINT UNSIGNED, 
    `num` SMALLINT UNSIGNED, 
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
    `sv` SMALLINT UNSIGNED, 
    `wna` SMALLINT, 
    `toa` INT, 
    `healthA` SMALLINT UNSIGNED, 
    `config` SMALLINT UNSIGNED, 
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
    `opt` BIGINT UNSIGNED, 
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
    `cs` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_ct_IonoParams1_unixTimeEpoch` (`unixTimeEpoch`));

-- custom type 'GpsNavData1'
CREATE TABLE `ct_GpsNavData1` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `recSize` SMALLINT UNSIGNED, 
    `dat` BLOB, 
    `cs` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_ct_GpsNavData1_unixTimeEpoch` (`unixTimeEpoch`));

-- custom type 'GpsRawNavData1'
CREATE TABLE `ct_GpsRawNavData1` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `prn` SMALLINT UNSIGNED, 
    `time` INT UNSIGNED, 
    `type` SMALLINT UNSIGNED, 
    `len` SMALLINT UNSIGNED, 
    `data` BLOB, 
    `errCorr` SMALLINT, 
    `cs` SMALLINT UNSIGNED, 
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

-- message 'RcvTime': [~~](RT) Receiver Time4 
CREATE TABLE `msg_RcvTime` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `tod` INT UNSIGNED, 
    `cs` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RcvTime_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_RcvTime_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_RcvTime_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_RcvTime_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_RcvTime_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'EpochTime': [::](ET) Epoch Time5 
CREATE TABLE `msg_EpochTime` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `tod` INT UNSIGNED, 
    `cs` SMALLINT UNSIGNED, 
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
    `month` SMALLINT UNSIGNED, 
    `day` SMALLINT UNSIGNED, 
    `base` SMALLINT UNSIGNED, 
    `cs` SMALLINT UNSIGNED, 
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
    `cs` SMALLINT UNSIGNED, 
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
    `cs` SMALLINT UNSIGNED, 
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
    `cs` SMALLINT UNSIGNED, 
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
    `cs` SMALLINT UNSIGNED, 
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
    `cs` SMALLINT UNSIGNED, 
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
    `cs` SMALLINT UNSIGNED, 
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
    `cs` SMALLINT UNSIGNED, 
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
    `cs` SMALLINT UNSIGNED, 
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
    `cs` SMALLINT UNSIGNED, 
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
    `cs` SMALLINT UNSIGNED, 
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
    `cs` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RcvBeiDouTimeOffset_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_RcvBeiDouTimeOffset_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_RcvBeiDouTimeOffset_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_RcvBeiDouTimeOffset_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_RcvBeiDouTimeOffset_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'RcvIrnssTimeOffset': [Io] IRNSS to Receiver Time Offset 
CREATE TABLE `msg_RcvIrnssTimeOffset` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `val` DOUBLE, 
    `sval` DOUBLE, 
    `cs` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RcvIrnssTimeOffset_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_RcvIrnssTimeOffset_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_RcvIrnssTimeOffset_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_RcvIrnssTimeOffset_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_RcvIrnssTimeOffset_idMessageCode` FOREIGN KEY (`idMessageCode`) 
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
    `utcsi` SMALLINT, 
    `tow` INT UNSIGNED, 
    `wn` SMALLINT UNSIGNED, 
    `flags` SMALLINT UNSIGNED, 
    `cs` SMALLINT UNSIGNED, 
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
    `a1g` FLOAT, 
    `t0g` INT UNSIGNED, 
    `wn0g` SMALLINT UNSIGNED, 
    `flags` SMALLINT UNSIGNED, 
    `cs` SMALLINT UNSIGNED, 
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
    `cs` SMALLINT UNSIGNED, 
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
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_BeiDouUtcParam_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_BeiDouUtcParam_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_BeiDouUtcParam_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_BeiDouUtcParam_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_BeiDouUtcParam_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'IrnssUtcParam': [IU] IRNSS UTC Time Parameters 
CREATE TABLE `msg_IrnssUtcParam` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `utc` BIGINT UNSIGNED, 
    `cs` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_IrnssUtcParam_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_IrnssUtcParam_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_IrnssUtcParam_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_IrnssUtcParam_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_IrnssUtcParam_idMessageCode` FOREIGN KEY (`idMessageCode`) 
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
    `KP` SMALLINT UNSIGNED, 
    `N4` SMALLINT UNSIGNED, 
    `Dn` SMALLINT, 
    `Nt` SMALLINT, 
    `cs` SMALLINT UNSIGNED, 
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
    `solType` SMALLINT UNSIGNED, 
    `cs` SMALLINT UNSIGNED, 
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
    `pSigma` FLOAT, 
    `solType` SMALLINT UNSIGNED, 
    `cs` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_Pos_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_Pos_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_Pos_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_Pos_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_Pos_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'SpecificCrtPos0': [Po] (PoWgs,PoLoc) Cartesian Position in Specific System 
CREATE TABLE `msg_SpecificCrtPos0` (
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
    `solType` SMALLINT UNSIGNED, 
    `system` SMALLINT UNSIGNED, 
    `crsCode` VARCHAR(1000), 
    `cs` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_SpecificCrtPos0_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_SpecificCrtPos0_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_SpecificCrtPos0_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_SpecificCrtPos0_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_SpecificCrtPos0_idMessageCode` FOREIGN KEY (`idMessageCode`) 
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
    `vSigma` FLOAT, 
    `solType` SMALLINT UNSIGNED, 
    `cs` SMALLINT UNSIGNED, 
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
    `solType` SMALLINT UNSIGNED, 
    `cs` SMALLINT UNSIGNED, 
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
    `solType` SMALLINT UNSIGNED, 
    `cs` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_GeoPos_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_GeoPos_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_GeoPos_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_GeoPos_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_GeoPos_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'SpecificCrtPos1': [Pg] (PgWgs,PgLoc) Geodetic Position in Specific System 
CREATE TABLE `msg_SpecificCrtPos1` (
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
    `solType` SMALLINT UNSIGNED, 
    `system` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_SpecificCrtPos1_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_SpecificCrtPos1_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_SpecificCrtPos1_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_SpecificCrtPos1_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_SpecificCrtPos1_idMessageCode` FOREIGN KEY (`idMessageCode`) 
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
    `vSigma` FLOAT, 
    `solType` SMALLINT UNSIGNED, 
    `cs` SMALLINT UNSIGNED, 
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
    `solType` SMALLINT UNSIGNED, 
    `cs` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_Rms_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_Rms_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_Rms_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_Rms_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_Rms_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'LocalPlanePos': [mp] Position in Local Plane 
CREATE TABLE `msg_LocalPlanePos` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `n` DOUBLE, 
    `e` DOUBLE, 
    `u` DOUBLE, 
    `sep` DOUBLE, 
    `pSigma` FLOAT, 
    `solType` SMALLINT UNSIGNED, 
    `geoid` SMALLINT UNSIGNED, 
    `prj` SMALLINT UNSIGNED, 
    `cs` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_LocalPlanePos_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_LocalPlanePos_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_LocalPlanePos_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_LocalPlanePos_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_LocalPlanePos_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'RSLocalPlanePos': [bp] Reference Station Position in Local Plane 
CREATE TABLE `msg_RSLocalPlanePos` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `n` DOUBLE, 
    `e` DOUBLE, 
    `u` DOUBLE, 
    `sep` DOUBLE, 
    `pSigma` FLOAT, 
    `solType` SMALLINT UNSIGNED, 
    `geoid` SMALLINT UNSIGNED, 
    `prj` SMALLINT UNSIGNED, 
    `cs` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RSLocalPlanePos_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_RSLocalPlanePos_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_RSLocalPlanePos_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_RSLocalPlanePos_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_RSLocalPlanePos_idMessageCode` FOREIGN KEY (`idMessageCode`) 
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
    `solType` SMALLINT UNSIGNED, 
    `edop` FLOAT, 
    `cs` SMALLINT UNSIGNED, 
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
    `solType` SMALLINT UNSIGNED, 
    `cs` SMALLINT UNSIGNED, 
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
    `solType` SMALLINT UNSIGNED, 
    `cs` SMALLINT UNSIGNED, 
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
    `solType` SMALLINT UNSIGNED, 
    `time` INT, 
    `cs` SMALLINT UNSIGNED, 
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
    `cs` SMALLINT UNSIGNED, 
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
    `cs` SMALLINT UNSIGNED, 
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
    `solType` SMALLINT UNSIGNED, 
    `gpsLocked` SMALLINT UNSIGNED, 
    `gloLocked` SMALLINT UNSIGNED, 
    `gpsAvail` SMALLINT UNSIGNED, 
    `gloAvail` SMALLINT UNSIGNED, 
    `gpsUsed` SMALLINT UNSIGNED, 
    `gloUsed` SMALLINT UNSIGNED, 
    `fixProg` SMALLINT UNSIGNED, 
    `cs` SMALLINT UNSIGNED, 
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
    `cs` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_PosCompTime_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_PosCompTime_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_PosCompTime_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_PosCompTime_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_PosCompTime_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'ExtSatIndex': [SX] Extended Satellite Indices 
CREATE TABLE `msg_ExtSatIndex` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `esi` BLOB, 
    `cs` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_ExtSatIndex_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_ExtSatIndex_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_ExtSatIndex_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_ExtSatIndex_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_ExtSatIndex_idMessageCode` FOREIGN KEY (`idMessageCode`) 
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
    `cs` SMALLINT UNSIGNED, 
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
    `cs` SMALLINT UNSIGNED, 
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
    `cs` SMALLINT UNSIGNED, 
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
    `cs` SMALLINT UNSIGNED, 
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
    `cs` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_SatAzimuth_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_SatAzimuth_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_SatAzimuth_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_SatAzimuth_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_SatAzimuth_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'PR': [RX], [RC], [R1], [R2], [R3], [R5], [Rl]: Pseudo-ranges 
CREATE TABLE `msg_PR` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `pr` BLOB, 
    `cs` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_PR_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_PR_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_PR_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_PR_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_PR_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'SPR': [rx], [rc], [r1], [r2], [r3], [r5], [rl]: Integer Pseudo-ranges 
CREATE TABLE `msg_SPR` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `spr` BLOB, 
    `cs` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_SPR_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_SPR_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_SPR_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_SPR_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_SPR_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'RPR': [CR], [1R], [2R], [3R], [5R], [lR]: Relative Pseudo-ranges 
CREATE TABLE `msg_RPR` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `rpr` BLOB, 
    `cs` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RPR_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_RPR_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_RPR_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_RPR_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_RPR_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'SRPR': [cr], [1r], [2r], [3r], [5r], [lr]: Integer Relative Pseudo-ranges 
CREATE TABLE `msg_SRPR` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `srpr` BLOB, 
    `cs` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_SRPR_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_SRPR_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_SRPR_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_SRPR_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_SRPR_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'PrCorr': [cm], [1m], [2m], [3m], [5m], [lm]: Pseudo-range Corrections 
CREATE TABLE `msg_PrCorr` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `prc` BLOB, 
    `mode` SMALLINT UNSIGNED, 
    `cs` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_PrCorr_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_PrCorr_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_PrCorr_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_PrCorr_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_PrCorr_idMessageCode` FOREIGN KEY (`idMessageCode`) 
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
    `cs` SMALLINT UNSIGNED, 
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
    `cs` SMALLINT UNSIGNED, 
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
    `cs` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_CP_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_CP_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_CP_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_CP_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_CP_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'SCP': [pc], [p1], [p2], [p3], [p5], [pl]: Integer Carrier Phases 
CREATE TABLE `msg_SCP` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `scp` BLOB, 
    `cs` SMALLINT UNSIGNED, 
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
    `cs` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RCP_RC0_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_RCP_RC0_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_RCP_RC0_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_RCP_RC0_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_RCP_RC0_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'RCP_rc': [cp],[1p],[2p],[3p],[5p],[lp]: Integer Relative Carrier Phases 
CREATE TABLE `msg_RCP_rc1` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `rcp` BLOB, 
    `cs` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RCP_rc1_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_RCP_rc1_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_RCP_rc1_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_RCP_rc1_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_RCP_rc1_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'PhCorr': [cf], [1f], [2f], [3f], [5f], [lf]: Phase Corrections 
CREATE TABLE `msg_PhCorr` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `phc` BLOB, 
    `mode` SMALLINT UNSIGNED, 
    `cs` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_PhCorr_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_PhCorr_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_PhCorr_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_PhCorr_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_PhCorr_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'DP': [DX], [DC], [D1], [D2], [D3], [D5], [Dl]: Doppler 
CREATE TABLE `msg_DP` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `dp` BLOB, 
    `cs` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_DP_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_DP_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_DP_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_DP_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_DP_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'SRDP': [0d],[1d], [2d], [3d], [5d], [ld]: Relative Doppler 
CREATE TABLE `msg_SRDP` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `srdp` BLOB, 
    `cs` SMALLINT UNSIGNED, 
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
    `cs` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_CNR_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_CNR_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_CNR_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_CNR_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_CNR_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'CNR_4': [CE], [1E], [2E], [3E], [5E], [lE]: SNR x 4 
CREATE TABLE `msg_CNR_4` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `cnrX4` BLOB, 
    `cs` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_CNR_4_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_CNR_4_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_CNR_4_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_CNR_4_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_CNR_4_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'CNR_2560': [s0], [s1], [s2], [s3], [s5], [sl]: SNR x 256 
CREATE TABLE `msg_CNR_2560` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `cnrX256` BLOB, 
    `cs` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_CNR_2560_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_CNR_2560_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_CNR_2560_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_CNR_2560_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_CNR_2560_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'CNR_2561': [j0], [j1], [j2], [j3], [j5], [jl]: Data SNR x 256 
CREATE TABLE `msg_CNR_2561` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `cnrX256` BLOB, 
    `cs` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_CNR_2561_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_CNR_2561_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_CNR_2561_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_CNR_2561_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_CNR_2561_idMessageCode` FOREIGN KEY (`idMessageCode`) 
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
    `cs` SMALLINT UNSIGNED, 
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
    `cs` SMALLINT UNSIGNED, 
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
    `cs` SMALLINT UNSIGNED, 
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
    `cs` SMALLINT UNSIGNED, 
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
    `solType` SMALLINT UNSIGNED, 
    `cs` SMALLINT UNSIGNED, 
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
    `cs` SMALLINT UNSIGNED, 
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
    `cs` SMALLINT UNSIGNED, 
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
    `cs` SMALLINT UNSIGNED, 
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
    `sv` SMALLINT UNSIGNED, 
    `wna` SMALLINT, 
    `toa` INT, 
    `healthA` SMALLINT UNSIGNED, 
    `config` SMALLINT UNSIGNED, 
    `af1` FLOAT, 
    `af0` FLOAT, 
    `rootA` FLOAT, 
    `ecc` FLOAT, 
    `m0` FLOAT, 
    `omega0` FLOAT, 
    `argPer` FLOAT, 
    `deli` FLOAT, 
    `omegaDot` FLOAT, 
    `cs` SMALLINT UNSIGNED, 
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
    `cs` SMALLINT UNSIGNED, 
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

-- message 'IrnssAlm': [IA] IRNSS Almanac 
CREATE TABLE `msg_IrnssAlm` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `gps` BIGINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_IrnssAlm_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_IrnssAlm_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_IrnssAlm_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_IrnssAlm_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_IrnssAlm_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'GLOAlmanac': [NA] GLONASS Almanac 
CREATE TABLE `msg_GLOAlmanac` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `sv` SMALLINT UNSIGNED, 
    `frqNum` SMALLINT, 
    `dna` SMALLINT, 
    `tlam` FLOAT, 
    `flags` SMALLINT UNSIGNED, 
    `tauN` FLOAT, 
    `tauSys` DOUBLE, 
    `ecc` FLOAT, 
    `lambda` FLOAT, 
    `argPer` FLOAT, 
    `delT` FLOAT, 
    `delTdt` FLOAT, 
    `deli` FLOAT, 
    `n4` SMALLINT UNSIGNED, 
    `reserved` SMALLINT UNSIGNED, 
    `gammaN` FLOAT, 
    `cs` SMALLINT UNSIGNED, 
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
    `waasPrn` SMALLINT UNSIGNED, 
    `gpsPrn` SMALLINT UNSIGNED, 
    `id_sugar` SMALLINT UNSIGNED, 
    `healthS` SMALLINT UNSIGNED, 
    `tod` INT UNSIGNED, 
    `xg` DOUBLE, 
    `yg` DOUBLE, 
    `zg` DOUBLE, 
    `vxg` FLOAT, 
    `vyg` FLOAT, 
    `vzg` FLOAT, 
    `tow` INT UNSIGNED, 
    `wn` SMALLINT UNSIGNED, 
    `cs` SMALLINT UNSIGNED, 
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
    `opt` BIGINT UNSIGNED, 
    `cs` SMALLINT UNSIGNED, 
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
    `sfi` SMALLINT UNSIGNED, 
    `navType` SMALLINT UNSIGNED, 
    `DAf0` FLOAT, 
    `cs` SMALLINT UNSIGNED, 
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
    `cs` SMALLINT UNSIGNED, 
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
    `navType` SMALLINT UNSIGNED, 
    `DAf0` FLOAT, 
    `cs` SMALLINT UNSIGNED, 
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
    `sv` SMALLINT UNSIGNED, 
    `frqNum` SMALLINT, 
    `dne` SMALLINT, 
    `tk` INT, 
    `tb` INT, 
    `health` SMALLINT UNSIGNED, 
    `age` SMALLINT UNSIGNED, 
    `flags` SMALLINT UNSIGNED, 
    `r` BLOB, 
    `v` BLOB, 
    `w` BLOB, 
    `tauSys` DOUBLE, 
    `tau` FLOAT, 
    `gamma` FLOAT, 
    `fDelTauN` FLOAT, 
    `nFt` SMALLINT UNSIGNED, 
    `nN4` SMALLINT UNSIGNED, 
    `flags2` SMALLINT UNSIGNED, 
    `navType` SMALLINT UNSIGNED, 
    `beta` FLOAT, 
    `tauSysDot` FLOAT, 
    `ec` SMALLINT UNSIGNED, 
    `ee` SMALLINT UNSIGNED, 
    `fc` SMALLINT, 
    `fe` SMALLINT, 
    `reserv` SMALLINT UNSIGNED, 
    `cs` SMALLINT UNSIGNED, 
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
    `waasPrn` SMALLINT UNSIGNED, 
    `gpsPrn` SMALLINT UNSIGNED, 
    `iod` SMALLINT UNSIGNED, 
    `acc` SMALLINT UNSIGNED, 
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
    `cs` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_SBASEhemeris_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_SBASEhemeris_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_SBASEhemeris_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_SBASEhemeris_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_SBASEhemeris_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'IrnssEphemeris': [IE] IRNSS Ephemeris 
CREATE TABLE `msg_IrnssEphemeris` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `gps` BIGINT UNSIGNED, 
    `navType` SMALLINT UNSIGNED, 
    `cs` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_IrnssEphemeris_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_IrnssEphemeris_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_IrnssEphemeris_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_IrnssEphemeris_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_IrnssEphemeris_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'GpsRawNavData0': [gd] GPS Raw Navigation Data 
CREATE TABLE `msg_GpsRawNavData0` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `prn` SMALLINT UNSIGNED, 
    `time` INT UNSIGNED, 
    `type` SMALLINT UNSIGNED, 
    `len` SMALLINT UNSIGNED, 
    `data` BLOB, 
    `errCorr` SMALLINT, 
    `cs` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_GpsRawNavData0_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_GpsRawNavData0_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_GpsRawNavData0_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_GpsRawNavData0_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_GpsRawNavData0_idMessageCode` FOREIGN KEY (`idMessageCode`) 
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

-- message 'GloRawNavData': [lD] GLONASS Raw Navigation Data 
CREATE TABLE `msg_GloRawNavData` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `num` SMALLINT UNSIGNED, 
    `fcn` SMALLINT, 
    `time` INT UNSIGNED, 
    `type` SMALLINT UNSIGNED, 
    `len` SMALLINT UNSIGNED, 
    `data` BLOB, 
    `errCorr` SMALLINT, 
    `cs` SMALLINT UNSIGNED, 
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
    `prn` SMALLINT UNSIGNED, 
    `time` INT UNSIGNED, 
    `type` SMALLINT UNSIGNED, 
    `len` SMALLINT UNSIGNED, 
    `data` BLOB, 
    `errCorr` SMALLINT, 
    `cs` SMALLINT UNSIGNED, 
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
    `prn` SMALLINT UNSIGNED, 
    `time` INT UNSIGNED, 
    `type` SMALLINT UNSIGNED, 
    `len` SMALLINT UNSIGNED, 
    `data` BLOB, 
    `errCorr` SMALLINT, 
    `cs` SMALLINT UNSIGNED, 
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
    `prn` SMALLINT UNSIGNED, 
    `time` INT UNSIGNED, 
    `type` SMALLINT UNSIGNED, 
    `len` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_CompRawNavData_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_CompRawNavData_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_CompRawNavData_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_CompRawNavData_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_CompRawNavData_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'IrnssRawNavData': [id] IRNSS Raw Navigation Data 
CREATE TABLE `msg_IrnssRawNavData` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `prn` SMALLINT UNSIGNED, 
    `time` INT UNSIGNED, 
    `type` SMALLINT UNSIGNED, 
    `len` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_IrnssRawNavData_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_IrnssRawNavData_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_IrnssRawNavData_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_IrnssRawNavData_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_IrnssRawNavData_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'GpsNavData0': [GD] GPS Raw Navigation Data (obsolete) 
CREATE TABLE `msg_GpsNavData0` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `recSize` SMALLINT UNSIGNED, 
    `dat` BLOB, 
    `cs` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_GpsNavData0_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_GpsNavData0_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_GpsNavData0_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_GpsNavData0_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_GpsNavData0_idMessageCode` FOREIGN KEY (`idMessageCode`) 
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

-- message 'GloNavData': [LD] GLONASS Raw Navigation Data (obsolete) 
CREATE TABLE `msg_GloNavData` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `recSize` SMALLINT UNSIGNED, 
    `dat` BLOB, 
    `cs` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_GloNavData_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_GloNavData_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_GloNavData_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_GloNavData_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_GloNavData_idMessageCode` FOREIGN KEY (`idMessageCode`) 
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
    `n` SMALLINT UNSIGNED, 
    `m` SMALLINT UNSIGNED, 
    `s` BLOB, 
    `cs` SMALLINT UNSIGNED, 
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
    `n` SMALLINT UNSIGNED, 
    `m` SMALLINT UNSIGNED, 
    `s` BLOB, 
    `cs` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_Spectrum1_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_Spectrum1_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_Spectrum1_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_Spectrum1_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_Spectrum1_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'MDM_Spectrum': [ms] Modem Spectrum 
CREATE TABLE `msg_MDM_Spectrum` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `frq` INT, 
    `pwr` INT, 
    `cs` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_MDM_Spectrum_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_MDM_Spectrum_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_MDM_Spectrum_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_MDM_Spectrum_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_MDM_Spectrum_idMessageCode` FOREIGN KEY (`idMessageCode`) 
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
    `cs` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_GloDelays_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_GloDelays_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_GloDelays_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_GloDelays_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_GloDelays_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'CalBandsDelay': [gR]: Code Delays of Receiver RF Bands 
CREATE TABLE `msg_CalBandsDelay` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `d` BLOB, 
    `cs` SMALLINT UNSIGNED, 
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
    `flag` SMALLINT UNSIGNED, 
    `cs` SMALLINT UNSIGNED, 
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
    `flag` SMALLINT UNSIGNED, 
    `bl1` BLOB, 
    `bl2` BLOB, 
    `cs` SMALLINT UNSIGNED, 
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
    `p` FLOAT, 
    `r` FLOAT, 
    `h` FLOAT, 
    `sp` FLOAT, 
    `sr` FLOAT, 
    `sh` FLOAT, 
    `solType` BLOB, 
    `flags` SMALLINT UNSIGNED, 
    `cs` SMALLINT UNSIGNED, 
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
    `flags` SMALLINT UNSIGNED, 
    `cs` SMALLINT UNSIGNED, 
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
    `cs` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_InertialMeasurements_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_InertialMeasurements_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_InertialMeasurements_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_InertialMeasurements_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_InertialMeasurements_idMessageCode` FOREIGN KEY (`idMessageCode`) 
        REFERENCES `messageCode` (`id`));

-- message 'AccMag': [MA] Accelerometer and Magnetometer Measurements 
CREATE TABLE `msg_AccMag` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `time` INT UNSIGNED, 
    `accelerations` BLOB, 
    `induction` BLOB, 
    `magnitude` FLOAT, 
    `temperature` FLOAT, 
    `calibrated` SMALLINT UNSIGNED, 
    `cs` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_AccMag_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_AccMag_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_AccMag_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_AccMag_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_AccMag_idMessageCode` FOREIGN KEY (`idMessageCode`) 
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
    `timeScale` SMALLINT UNSIGNED, 
    `cs` SMALLINT UNSIGNED, 
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
    `cs` SMALLINT UNSIGNED, 
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
    `timeScale` SMALLINT UNSIGNED, 
    `cs` SMALLINT UNSIGNED, 
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
    `solType` SMALLINT UNSIGNED, 
    `cs` SMALLINT UNSIGNED, 
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
    `cs` SMALLINT UNSIGNED, 
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

-- message 'IrnssIonoParams': [II] IRNSS Ionospheric Parameters 
CREATE TABLE `msg_IrnssIonoParams` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    epochIndex INT UNSIGNED NOT NULL, 
    unixTimeEpoch BIGINT UNSIGNED NOT NULL, 
    idMessageCode BIGINT UNSIGNED NOT NULL, 
    bodySize INT NOT NULL, 
    `par` BIGINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_IrnssIonoParams_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_IrnssIonoParams_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_IrnssIonoParams_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_IrnssIonoParams_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_IrnssIonoParams_idMessageCode` FOREIGN KEY (`idMessageCode`) 
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
    `type` SMALLINT UNSIGNED, 
    `data` BLOB, 
    `cs` SMALLINT UNSIGNED, 
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
    `lt` SMALLINT UNSIGNED, 
    `cs` SMALLINT UNSIGNED, 
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
    `id_sugar` SMALLINT UNSIGNED, 
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
    `svsCount` SMALLINT UNSIGNED, 
    `targetStream` SMALLINT UNSIGNED, 
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
    `solType` SMALLINT UNSIGNED, 
    `cs` SMALLINT UNSIGNED, 
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
    `cs` SMALLINT UNSIGNED, 
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
    `cs` SMALLINT UNSIGNED, 
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
    `cs` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RcvOscOffs_idEpoch` (`idEpoch`), 
    INDEX `idx_fk_msg_RcvOscOffs_unixTimeEpoch` (`unixTimeEpoch`), 
    INDEX `idx_fk_msg_RcvOscOffs_idMessageCode` (`idMessageCode`), 
    CONSTRAINT `fk_msg_RcvOscOffs_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epoch` (`id`), 
    CONSTRAINT `fk_msg_RcvOscOffs_idMessageCode` FOREIGN KEY (`idMessageCode`) 
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
           (2, 'ESI', 2, 'ct_ESI'), 
           (3, 'Smooth', 6, 'ct_Smooth'), 
           (4, 'GpsEphReqData', 122, 'ct_GpsEphReqData'), 
           (5, 'GpsEphOptData', 36, 'ct_GpsEphOptData'), 
           (6, 'SvData0', 42, 'ct_SvData0'), 
           (7, 'SvData1', 18, 'ct_SvData1'), 
           (8, 'SpecData', -1, 'ct_SpecData'), 
           (9, 'ExtSpecData', -1, 'ct_ExtSpecData'), 
           (10, 'SvDelay', 9, 'ct_SvDelay'), 
           (11, 'BandDelay', 6, 'ct_BandDelay'), 
           (12, 'SvData2', -1, 'ct_SvData2'), 
           (13, 'Header', 6, 'ct_Header'), 
           (14, 'SlotRec', 14, 'ct_SlotRec'), 
           (15, 'ClkOffs', 8, 'ct_ClkOffs'), 
           (16, 'GPSAlm1', 46, 'ct_GPSAlm1'), 
           (17, 'GPSEphemeris1', 158, 'ct_GPSEphemeris1'), 
           (18, 'IonoParams1', 39, 'ct_IonoParams1'), 
           (19, 'GpsNavData1', -2, 'ct_GpsNavData1'), 
           (20, 'GpsRawNavData1', -2, 'ct_GpsRawNavData1');

-- Наполнение мета-информации о сообщениях
INSERT INTO `messageMeta` (`id`, `name`, `title`, `size`, `idValidation`, `idKind`, `idType`, `tableName`) 
    VALUES (1, 'FileId', '[JP] File Identifier ', 85, 0, 3, 1, 'msg_FileId'), 
           (2, 'MsgFmt', '[MF] Messages Format ', 9, 2, 3, 1, 'msg_MsgFmt'), 
           (3, 'RcvTime', '[~~](RT) Receiver Time4 ', 5, 1, 3, 1, 'msg_RcvTime'), 
           (4, 'EpochTime', '[::](ET) Epoch Time5 ', 5, 1, 3, 1, 'msg_EpochTime'), 
           (5, 'RcvDate', '[RD] Receiver Date ', 6, 1, 3, 1, 'msg_RcvDate'), 
           (6, 'RcvTimeOffset', '[TO] Reference Time to Receiver Time Offset ', 17, 1, 3, 1, 'msg_RcvTimeOffset'), 
           (7, 'RcvTimeOffsetDot', '[DO] Derivative of Receiver Time Offset ', 9, 1, 3, 1, 'msg_RcvTimeOffsetDot'), 
           (8, 'RcvTimeAccuracy', '[BP] Rough Accuracy of Time Approximation ', 5, 1, 3, 1, 'msg_RcvTimeAccuracy'), 
           (9, 'GPSTime', '[GT] GPS Time ', 7, 1, 3, 1, 'msg_GPSTime'), 
           (10, 'RcvGPSTimeOffset', '[GO] GPS to Receiver Time Offset ', 17, 1, 3, 1, 'msg_RcvGPSTimeOffset'), 
           (11, 'GLOTime', '[NT] GLONASS Time ', 7, 1, 3, 1, 'msg_GLOTime'), 
           (12, 'RcvGLOTimeOffset', '[NO] GLONASS to Receiver Time Offset ', 17, 1, 3, 1, 'msg_RcvGLOTimeOffset'), 
           (13, 'RcvGALTimeOffset', '[EO] GALILEO to Receiver Time Offset ', 17, 1, 3, 1, 'msg_RcvGALTimeOffset'), 
           (14, 'RcvSBASTimeOffset', '[WO] SBAS to Receiver Time Offset ', 17, 1, 3, 1, 'msg_RcvSBASTimeOffset'), 
           (15, 'RcvQZSSTimeOffset', '[QO] QZSS to Receiver Time Offset ', 17, 1, 3, 1, 'msg_RcvQZSSTimeOffset'), 
           (16, 'RcvBeiDouTimeOffset', '[CO] BeiDou to Receiver Time Offset ', 17, 1, 3, 1, 'msg_RcvBeiDouTimeOffset'), 
           (17, 'RcvIrnssTimeOffset', '[Io] IRNSS to Receiver Time Offset ', 17, 1, 3, 1, 'msg_RcvIrnssTimeOffset'), 
           (18, 'GpsUtcParam', '[UO] GPS UTC Time Parameters ', 24, 0, 3, 1, 'msg_GpsUtcParam'), 
           (19, 'SbasUtcParam', '[WU] SBAS UTC Time Parameters ', 32, 1, 3, 1, 'msg_SbasUtcParam'), 
           (20, 'GalUtcGpsParam', '[EU] GALILEO UTC and GPS Time Parameters ', 40, 1, 3, 1, 'msg_GalUtcGpsParam'), 
           (21, 'QzssUtcParam', '[QU] QZSS UTC Time Parameters ', 24, 1, 3, 1, 'msg_QzssUtcParam'), 
           (22, 'BeiDouUtcParam', '[CU] BeiDou UTC Time Parameters ', 24, 0, 3, 1, 'msg_BeiDouUtcParam'), 
           (23, 'IrnssUtcParam', '[IU] IRNSS UTC Time Parameters ', 24, 1, 3, 1, 'msg_IrnssUtcParam'), 
           (24, 'GloUtcGpsParam', '[NU] GLONASS UTC and GPS Time Parameters ', 27, 1, 3, 1, 'msg_GloUtcGpsParam'), 
           (25, 'SolutionTime', '[ST] Solution Time-Tag ', 6, 1, 3, 1, 'msg_SolutionTime'), 
           (26, 'Pos', '[PO] Cartesian Position ', 30, 1, 3, 1, 'msg_Pos'), 
           (27, 'SpecificCrtPos0', '[Po] (PoWgs,PoLoc) Cartesian Position in Specific System ', 36, 1, 3, 1, 'msg_SpecificCrtPos0'), 
           (28, 'Vel', '[VE] Cartesian Velocity ', 18, 1, 3, 1, 'msg_Vel'), 
           (29, 'PosVel', '[PV] Cartesian Position and Velocity ', 46, 1, 3, 1, 'msg_PosVel'), 
           (30, 'GeoPos', '[PG] Geodetic Position ', 30, 1, 3, 1, 'msg_GeoPos'), 
           (31, 'SpecificCrtPos1', '[Pg] (PgWgs,PgLoc) Geodetic Position in Specific System ', 36, 0, 3, 1, 'msg_SpecificCrtPos1'), 
           (32, 'GeoVel', '[VG] Geodetic Velocity ', 18, 1, 3, 1, 'msg_GeoVel'), 
           (33, 'Rms', '[SG] Position and Velocity RMS Errors ', 18, 1, 3, 1, 'msg_Rms'), 
           (34, 'LocalPlanePos', '[mp] Position in Local Plane ', 42, 1, 3, 1, 'msg_LocalPlanePos'), 
           (35, 'RSLocalPlanePos', '[bp] Reference Station Position in Local Plane ', 42, 1, 3, 1, 'msg_RSLocalPlanePos'), 
           (36, 'Dops', '[DP] Dilution of Precision (DOP) ', 18, 1, 3, 1, 'msg_Dops'), 
           (37, 'PosCov', '[SP] Position Covariance Matrix ', 42, 1, 3, 1, 'msg_PosCov'), 
           (38, 'VelCov', '[SV] Velocity Covariance Matrix ', 42, 1, 3, 1, 'msg_VelCov'), 
           (39, 'Baseline', '[BL] Baseline ', 34, 1, 3, 1, 'msg_Baseline'), 
           (40, 'Baselines', '[bL] Attitude Baselines ', 52, 1, 3, 1, 'msg_Baselines'), 
           (41, 'FullRotationMatrix', '[mR] Attitude Full Rotation Matrix ', 37, 1, 3, 1, 'msg_FullRotationMatrix'), 
           (42, 'PosStat', '[PS] Position Statistics ', 9, 1, 3, 1, 'msg_PosStat'), 
           (43, 'PosCompTime', '[PT] Time of Continuous Position Computation ', 5, 1, 3, 1, 'msg_PosCompTime'), 
           (44, 'ExtSatIndex', '[SX] Extended Satellite Indices ', -2, 1, 3, 1, 'msg_ExtSatIndex'), 
           (45, 'SatIndex', '[SI] Satellite Indices ', -2, 1, 3, 1, 'msg_SatIndex'), 
           (46, 'AntName', '[AN] Antenna Names ', -2, 1, 3, 1, 'msg_AntName'), 
           (47, 'SatNumbers', '[NN] GLONASS Satellite System Numbers ', -2, 1, 3, 1, 'msg_SatNumbers'), 
           (48, 'SatElevation', '[EL] Satellite Elevations ', -2, 1, 3, 1, 'msg_SatElevation'), 
           (49, 'SatAzimuth', '[AZ] Satellite Azimuths ', -2, 1, 3, 1, 'msg_SatAzimuth'), 
           (50, 'PR', '[RX], [RC], [R1], [R2], [R3], [R5], [Rl]: Pseudo-ranges ', -1, 1, 3, 1, 'msg_PR'), 
           (51, 'SPR', '[rx], [rc], [r1], [r2], [r3], [r5], [rl]: Integer Pseudo-ranges ', -1, 1, 3, 1, 'msg_SPR'), 
           (52, 'RPR', '[CR], [1R], [2R], [3R], [5R], [lR]: Relative Pseudo-ranges ', -1, 1, 3, 1, 'msg_RPR'), 
           (53, 'SRPR', '[cr], [1r], [2r], [3r], [5r], [lr]: Integer Relative Pseudo-ranges ', -1, 1, 3, 1, 'msg_SRPR'), 
           (54, 'PrCorr', '[cm], [1m], [2m], [3m], [5m], [lm]: Pseudo-range Corrections ', -1, 1, 3, 1, 'msg_PrCorr'), 
           (55, 'SC', '[CC],[C1],[C2],[C3],[C5],[Cl]: Smoothing Corrections ', -2, 1, 3, 1, 'msg_SC'), 
           (56, 'SS', '[cc],[c1],[c2],[c3],[c5],[cl]: Smoothing Corrections ', -2, 1, 3, 1, 'msg_SS'), 
           (57, 'CP', '[PC], [P1], [P2], [P3], [P5], [Pl]: Carrier Phases ', -2, 1, 3, 1, 'msg_CP'), 
           (58, 'SCP', '[pc], [p1], [p2], [p3], [p5], [pl]: Integer Carrier Phases ', -2, 1, 3, 1, 'msg_SCP'), 
           (59, 'RCP_RC', '[CP],[1P],[2P],[3P],[5P],[lP]: Relative Carrier Phases ', -2, 1, 3, 1, 'msg_RCP_RC0'), 
           (60, 'RCP_rc', '[cp],[1p],[2p],[3p],[5p],[lp]: Integer Relative Carrier Phases ', -2, 1, 3, 1, 'msg_RCP_rc1'), 
           (61, 'PhCorr', '[cf], [1f], [2f], [3f], [5f], [lf]: Phase Corrections ', -1, 1, 3, 1, 'msg_PhCorr'), 
           (62, 'DP', '[DX], [DC], [D1], [D2], [D3], [D5], [Dl]: Doppler ', -1, 1, 3, 1, 'msg_DP'), 
           (63, 'SRDP', '[0d],[1d], [2d], [3d], [5d], [ld]: Relative Doppler ', -1, 1, 3, 1, 'msg_SRDP'), 
           (64, 'CNR', '[EC], [E1], [E2], [E3], [E5], [El]: SNR ', -2, 1, 3, 1, 'msg_CNR'), 
           (65, 'CNR_4', '[CE], [1E], [2E], [3E], [5E], [lE]: SNR x 4 ', -2, 1, 3, 1, 'msg_CNR_4'), 
           (66, 'CNR_2560', '[s0], [s1], [s2], [s3], [s5], [sl]: SNR x 256 ', -1, 1, 3, 1, 'msg_CNR_2560'), 
           (67, 'CNR_2561', '[j0], [j1], [j2], [j3], [j5], [jl]: Data SNR x 256 ', -1, 1, 3, 1, 'msg_CNR_2561'), 
           (68, 'Flags', '[FC],[F1],[F2],[F3],[F5],[Fl]: Signal Lock Loop Flags ', -2, 1, 3, 1, 'msg_Flags'), 
           (69, 'IAmp', '[ec], [e1], [e2], [e3], [e5]: Raw Inphases (I) ', -1, 1, 3, 1, 'msg_IAmp'), 
           (70, 'QAmp', '[qc], [q1], [q2], [q3], [q5]: Raw Quadratures (Q) ', -1, 1, 3, 1, 'msg_QAmp'), 
           (71, 'TrackingTimeCA', '[TC] CA/L1 Continuous Tracking Time ', -2, 1, 3, 1, 'msg_TrackingTimeCA'), 
           (72, 'NavStatus', '[SS] Satellite Navigation Status ', -2, 1, 3, 1, 'msg_NavStatus'), 
           (73, 'IonoDelay', '[ID] Ionospheric Delays ', -2, 1, 3, 1, 'msg_IonoDelay'), 
           (74, 'RangeResidual', '[rr] Satellite Range Residuals ', -1, 1, 3, 1, 'msg_RangeResidual'), 
           (75, 'VelocityResidual', '[vr] Satellite Velocity Residuals ', -1, 1, 3, 1, 'msg_VelocityResidual'), 
           (76, 'GPSAlm0', '[GA] GPS Almanac ', 47, 1, 3, 2, 'msg_GPSAlm0'), 
           (77, 'GALAlm', '[EA] GALILEO Almanac ', 49, 1, 3, 2, 'msg_GALAlm'), 
           (78, 'QZSSAlm', '[QA] QZSS Almanac ', 47, 0, 3, 2, 'msg_QZSSAlm'), 
           (79, 'BeiDouAlm', '[CA] BeiDou Almanac ', 47, 0, 3, 2, 'msg_BeiDouAlm'), 
           (80, 'IrnssAlm', '[IA] IRNSS Almanac ', 47, 0, 3, 2, 'msg_IrnssAlm'), 
           (81, 'GLOAlmanac', '[NA] GLONASS Almanac ', -3, 1, 3, 2, 'msg_GLOAlmanac'), 
           (82, 'SBASAlmanac', '[WA] SBAS Almanac ', 51, 1, 3, 2, 'msg_SBASAlmanac'), 
           (83, 'GPSEphemeris0', '[GE] GPS Ephemeris ', 159, 1, 3, 2, 'msg_GPSEphemeris0'), 
           (84, 'GALEphemeris', '[EN] GALILEO Ephemeris ', 149, 1, 3, 2, 'msg_GALEphemeris'), 
           (85, 'QZSSEphemeris', '[QE] QZSS Ephemeris ', 160, 1, 3, 2, 'msg_QZSSEphemeris'), 
           (86, 'BeiDouEphemeris', '[CN] BeiDou Ephemeris ', 132, 1, 3, 2, 'msg_BeiDouEphemeris'), 
           (87, 'GLOEphemeris', '[NE] GLONASS Ephemeris ', -3, 1, 3, 2, 'msg_GLOEphemeris'), 
           (88, 'SBASEhemeris', '[WE] SBAS Ephemeris ', 73, 1, 3, 2, 'msg_SBASEhemeris'), 
           (89, 'IrnssEphemeris', '[IE] IRNSS Ephemeris ', 124, 1, 3, 2, 'msg_IrnssEphemeris'), 
           (90, 'GpsRawNavData0', '[gd] GPS Raw Navigation Data ', -2, 1, 3, 1, 'msg_GpsRawNavData0'), 
           (91, 'QzssRawNavData', '[qd] QZSS Raw Navigation Data ', -1, 0, 3, 1, 'msg_QzssRawNavData'), 
           (92, 'GloRawNavData', '[lD] GLONASS Raw Navigation Data ', -2, 1, 3, 1, 'msg_GloRawNavData'), 
           (93, 'SbasRawNavData', '[WD] SBAS Raw Navigation Data ', 41, 1, 3, 1, 'msg_SbasRawNavData'), 
           (94, 'GalRawNavData', '[ED] GALILEO Raw Navigation Data ', -2, 1, 3, 1, 'msg_GalRawNavData'), 
           (95, 'CompRawNavData', '[cd] BeiDou Raw Navigation Data ', 7, 0, 3, 1, 'msg_CompRawNavData'), 
           (96, 'IrnssRawNavData', '[id] IRNSS Raw Navigation Data ', 7, 0, 3, 1, 'msg_IrnssRawNavData'), 
           (97, 'GpsNavData0', '[GD] GPS Raw Navigation Data (obsolete) ', -2, 1, 3, 1, 'msg_GpsNavData0'), 
           (98, 'QzssNavData', '[QD] QZSS Raw Navigation Data (obsolete) ', -1, 0, 3, 1, 'msg_QzssNavData'), 
           (99, 'GloNavData', '[LD] GLONASS Raw Navigation Data (obsolete) ', -2, 1, 3, 1, 'msg_GloNavData'), 
           (100, 'Spectrum0', '[sp] Spectrum ', -1, 1, 3, 1, 'msg_Spectrum0'), 
           (101, 'Spectrum1', '[sP] Extended Spectrum ', -1, 1, 3, 1, 'msg_Spectrum1'), 
           (102, 'MDM_Spectrum', '[ms] Modem Spectrum ', 9, 1, 3, 1, 'msg_MDM_Spectrum'), 
           (103, 'GloDelays', '[gC], [g1], [g2], [g3]: GLONASS Delays ', -2, 1, 3, 1, 'msg_GloDelays'), 
           (104, 'CalBandsDelay', '[gR]: Code Delays of Receiver RF Bands ', -1, 1, 3, 1, 'msg_CalBandsDelay'), 
           (105, 'RotationMatrix', '[MR] Rotation Matrix ', 37, 1, 3, 1, 'msg_RotationMatrix'), 
           (106, 'RotationMatrixAndVectors', '[mr] Rotation Matrix and Vectors ', 73, 1, 3, 1, 'msg_RotationMatrixAndVectors'), 
           (107, 'RotationAngles', '[AR] Rotation Angles ', 33, 1, 3, 1, 'msg_RotationAngles'), 
           (108, 'AngularVelocity', '[AV] Angular Velocities ', 22, 1, 3, 1, 'msg_AngularVelocity'), 
           (109, 'InertialMeasurements', '[IM] Inertial Measurements ', 25, 1, 3, 1, 'msg_InertialMeasurements'), 
           (110, 'AccMag', '[MA] Accelerometer and Magnetometer Measurements ', 38, 1, 3, 1, 'msg_AccMag'), 
           (111, 'ExtEvent', '[XA], [XB] External Event ', 10, 1, 3, 1, 'msg_ExtEvent'), 
           (112, 'PPSOffset', '[ZA], [ZB] PPS Offset ', 5, 1, 3, 1, 'msg_PPSOffset'), 
           (113, 'RcvTimeOffsAtPPS', '[YA], [YB] Time Offset at PPS Generation Time ', 10, 1, 3, 1, 'msg_RcvTimeOffsAtPPS'), 
           (114, 'HeadAndPitch', '[ha] Heading and Pitch ', 10, 1, 3, 1, 'msg_HeadAndPitch'), 
           (115, 'RefEpoch', '[rE] Reference Epoch ', 10, 3, 3, 1, 'msg_RefEpoch'), 
           (116, 'RawMeas', '[rM] Raw Measurements ', -1, 3, 3, 1, 'msg_RawMeas'), 
           (117, 'PosVelVector', '[rV] Receiver’s Position and Velocity ', 42, 3, 3, 1, 'msg_PosVelVector'), 
           (118, 'ClockOffsets', '[rT] Receiver Clock Offsets ', -2, 3, 3, 1, 'msg_ClockOffsets'), 
           (119, 'RE', '[RE] Reply ', -2, 0, 3, 1, 'msg_RE'), 
           (120, 'ER', '[ER] Error ', -2, 0, 3, 1, 'msg_ER'), 
           (121, 'IonoParams0', '[IO] GPS Ionospheric Parameters ', 39, 1, 3, 1, 'msg_IonoParams0'), 
           (122, 'QzssIonoParams', '[QI] QZSS Ionospheric Parameters ', 39, 0, 3, 1, 'msg_QzssIonoParams'), 
           (123, 'BeiDouIonoParams', '[CI] BeiDou Ionospheric Parameters ', 39, 0, 3, 1, 'msg_BeiDouIonoParams'), 
           (124, 'IrnssIonoParams', '[II] IRNSS Ionospheric Parameters ', 39, 0, 3, 1, 'msg_IrnssIonoParams'), 
           (125, 'Event', '[==](EV) Event ', -2, 1, 3, 1, 'msg_Event'), 
           (126, 'Latency', '[LT] Message Output Latency ', 2, 1, 3, 1, 'msg_Latency'), 
           (127, 'Wrapper', '[>>] Wrapper ', -2, 2, 3, 1, 'msg_Wrapper'), 
           (128, 'Params', '[PM] Parameters ', -2, 0, 3, 1, 'msg_Params'), 
           (129, 'LoggingHistory', '[LH] Logging History ', -1, 0, 3, 1, 'msg_LoggingHistory'), 
           (130, 'BaseInfo', '[BI] Base Station Information ', 28, 1, 3, 1, 'msg_BaseInfo'), 
           (131, 'Security0', '[SE] Security ', 6, 1, 3, 1, 'msg_Security0'), 
           (132, 'Security1', '[SM] Security for [rM] ', 8, 3, 3, 1, 'msg_Security1'), 
           (133, 'TrackingTime', '[TT] CA/L1 Overall Continuous Tracking Time ', 5, 1, 3, 1, 'msg_TrackingTime'), 
           (134, 'RcvOscOffs', '[OO] Oscillator Offset ', 5, 1, 3, 1, 'msg_RcvOscOffs');

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
           ('Io', 17), 
           ('UO', 18), 
           ('WU', 19), 
           ('EU', 20), 
           ('QU', 21), 
           ('CU', 22), 
           ('IU', 23), 
           ('NU', 24), 
           ('ST', 25), 
           ('PO', 26), 
           ('Po', 27), 
           ('VE', 28), 
           ('PV', 29), 
           ('PG', 30), 
           ('Pg', 31), 
           ('VG', 32), 
           ('SG', 33), 
           ('mp', 34), 
           ('bp', 35), 
           ('DP', 36), 
           ('SP', 37), 
           ('SV', 38), 
           ('BL', 39), 
           ('bL', 40), 
           ('mR', 41), 
           ('PS', 42), 
           ('PT', 43), 
           ('SX', 44), 
           ('SI', 45), 
           ('AN', 46), 
           ('NN', 47), 
           ('EL', 48), 
           ('AZ', 49), 
           ('RX', 50), 
           ('RC', 50), 
           ('R1', 50), 
           ('R2', 50), 
           ('R3', 50), 
           ('R5', 50), 
           ('Rl', 50), 
           ('rx', 51), 
           ('rc', 51), 
           ('r1', 51), 
           ('r2', 51), 
           ('r3', 51), 
           ('r5', 51), 
           ('rl', 51), 
           ('CR', 52), 
           ('1R', 52), 
           ('2R', 52), 
           ('3R', 52), 
           ('5R', 52), 
           ('lR', 52), 
           ('cr', 53), 
           ('1r', 53), 
           ('2r', 53), 
           ('3r', 53), 
           ('5r', 53), 
           ('lr', 53), 
           ('cm', 54), 
           ('1m', 54), 
           ('2m', 54), 
           ('3m', 54), 
           ('5m', 54), 
           ('lm', 54), 
           ('CC', 55), 
           ('C1', 55), 
           ('C2', 55), 
           ('C3', 55), 
           ('C5', 55), 
           ('Cl', 55), 
           ('cc', 56), 
           ('c1', 56), 
           ('c2', 56), 
           ('c3', 56), 
           ('c5', 56), 
           ('cl', 56), 
           ('PC', 57), 
           ('P1', 57), 
           ('P2', 57), 
           ('P3', 57), 
           ('P5', 57), 
           ('Pl', 57), 
           ('pc', 58), 
           ('p1', 58), 
           ('p2', 58), 
           ('p3', 58), 
           ('p5', 58), 
           ('pl', 58), 
           ('CP', 59), 
           ('1P', 59), 
           ('2P', 59), 
           ('3P', 59), 
           ('5P', 59), 
           ('lP', 59), 
           ('cp', 60), 
           ('1p', 60), 
           ('2p', 60), 
           ('3p', 60), 
           ('5p', 60), 
           ('lp', 60), 
           ('cf', 61), 
           ('1f', 61), 
           ('2f', 61), 
           ('3f', 61), 
           ('5f', 61), 
           ('lf', 61), 
           ('DX', 62), 
           ('DC', 62), 
           ('D1', 62), 
           ('D2', 62), 
           ('D3', 62), 
           ('D5', 62), 
           ('Dl', 62), 
           ('0d', 63), 
           ('1d', 63), 
           ('2d', 63), 
           ('3d', 63), 
           ('5d', 63), 
           ('ld', 63), 
           ('EC', 64), 
           ('E1', 64), 
           ('E2', 64), 
           ('E3', 64), 
           ('E5', 64), 
           ('El', 64), 
           ('CE', 65), 
           ('1E', 65), 
           ('2E', 65), 
           ('3E', 65), 
           ('5E', 65), 
           ('lE', 65), 
           ('s0', 66), 
           ('s1', 66), 
           ('s2', 66), 
           ('s3', 66), 
           ('s5', 66), 
           ('sl', 66), 
           ('j0', 67), 
           ('j1', 67), 
           ('j2', 67), 
           ('j3', 67), 
           ('j5', 67), 
           ('jl', 67), 
           ('FC', 68), 
           ('F1', 68), 
           ('F2', 68), 
           ('F3', 68), 
           ('F5', 68), 
           ('Fl', 68), 
           ('ec', 69), 
           ('e1', 69), 
           ('e2', 69), 
           ('e3', 69), 
           ('e5', 69), 
           ('qc', 70), 
           ('q1', 70), 
           ('q2', 70), 
           ('q3', 70), 
           ('q5', 70), 
           ('TC', 71), 
           ('SS', 72), 
           ('ID', 73), 
           ('rr', 74), 
           ('vr', 75), 
           ('GA', 76), 
           ('EA', 77), 
           ('QA', 78), 
           ('CA', 79), 
           ('IA', 80), 
           ('NA', 81), 
           ('WA', 82), 
           ('GE', 83), 
           ('EN', 84), 
           ('QE', 85), 
           ('CN', 86), 
           ('NE', 87), 
           ('WE', 88), 
           ('IE', 89), 
           ('gd', 90), 
           ('qd', 91), 
           ('lD', 92), 
           ('WD', 93), 
           ('ED', 94), 
           ('cd', 95), 
           ('id', 96), 
           ('GD', 97), 
           ('QD', 98), 
           ('LD', 99), 
           ('sp', 100), 
           ('sP', 101), 
           ('ms', 102), 
           ('gC', 103), 
           ('g1', 103), 
           ('g2', 103), 
           ('g3', 103), 
           ('gR', 104), 
           ('MR', 105), 
           ('mr', 106), 
           ('AR', 107), 
           ('AV', 108), 
           ('IM', 109), 
           ('MA', 110), 
           ('XA', 111), 
           ('XB', 111), 
           ('ZA', 112), 
           ('ZB', 112), 
           ('YA', 113), 
           ('YB', 113), 
           ('ha', 114), 
           ('rE', 115), 
           ('rM', 116), 
           ('rV', 117), 
           ('rT', 118), 
           ('RE', 119), 
           ('ER', 120), 
           ('IO', 121), 
           ('QI', 122), 
           ('CI', 123), 
           ('II', 124), 
           ('==', 125), 
           ('LT', 126), 
           ('>>', 127), 
           ('PM', 128), 
           ('LH', 129), 
           ('BI', 130), 
           ('SE', 131), 
           ('SM', 132), 
           ('TT', 133), 
           ('OO', 134);

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
           (49, 'val', 'f8', '', 17), 
           (50, 'sval', 'f8', '', 17), 
           (51, 'cs', 'u1', '', 17), 
           (52, 'utc', 'UtcOffs', '', 18), 
           (53, 'utc', 'UtcOffs', '', 19), 
           (54, 'utcsi', 'i1', '', 19), 
           (55, 'tow', 'u4', '', 19), 
           (56, 'wn', 'u2', '', 19), 
           (57, 'flags', 'u1', '', 19), 
           (58, 'cs', 'u1', '', 19), 
           (59, 'utc', 'UtcOffs', '', 20), 
           (60, 'a1g', 'f4', '', 20), 
           (61, 't0g', 'u4', '', 20), 
           (62, 'wn0g', 'u2', '', 20), 
           (63, 'flags', 'u2', '', 20), 
           (64, 'cs', 'u1', '', 20), 
           (65, 'utc', 'UtcOffs', '', 21), 
           (66, 'cs', 'u1', '', 21), 
           (67, 'utc', 'UtcOffs', '', 22), 
           (68, 'utc', 'UtcOffs', '', 23), 
           (69, 'cs', 'u1', '', 23), 
           (70, 'tauSys', 'f8', '', 24), 
           (71, 'tauGps', 'f4', '', 24), 
           (72, 'B1', 'f4', '', 24), 
           (73, 'B2', 'f4', '', 24), 
           (74, 'KP', 'u1', '', 24), 
           (75, 'N4', 'u1', '', 24), 
           (76, 'Dn', 'i2', '', 24), 
           (77, 'Nt', 'i2', '', 24), 
           (78, 'cs', 'u1', '', 24), 
           (79, 'time', 'u4', '', 25), 
           (80, 'solType', 'u1', '', 25), 
           (81, 'cs', 'u1', '', 25), 
           (82, 'x', 'f8', '', 26), 
           (83, 'y', 'f8', '', 26), 
           (84, 'z', 'f8', '', 26), 
           (85, 'pSigma', 'f4', '', 26), 
           (86, 'solType', 'u1', '', 26), 
           (87, 'cs', 'u1', '', 26), 
           (88, 'x', 'f8', '', 27), 
           (89, 'y', 'f8', '', 27), 
           (90, 'z', 'f8', '', 27), 
           (91, 'pSigma', 'f4', '', 27), 
           (92, 'solType', 'u1', '', 27), 
           (93, 'system', 'u1', '', 27), 
           (94, 'crsCode', 'a1', '', 27), 
           (95, 'cs', 'u1', '', 27), 
           (96, 'x', 'f4', '', 28), 
           (97, 'y', 'f4', '', 28), 
           (98, 'z', 'f4', '', 28), 
           (99, 'vSigma', 'f4', '', 28), 
           (100, 'solType', 'u1', '', 28), 
           (101, 'cs', 'u1', '', 28), 
           (102, 'x', 'f8', '', 29), 
           (103, 'y', 'f8', '', 29), 
           (104, 'z', 'f8', '', 29), 
           (105, 'pSigma', 'f4', '', 29), 
           (106, 'vx', 'f4', '', 29), 
           (107, 'vy', 'f4', '', 29), 
           (108, 'vz', 'f4', '', 29), 
           (109, 'vSigma', 'f4', '', 29), 
           (110, 'solType', 'u1', '', 29), 
           (111, 'cs', 'u1', '', 29), 
           (112, 'lat', 'f8', '', 30), 
           (113, 'lon', 'f8', '', 30), 
           (114, 'alt', 'f8', '', 30), 
           (115, 'pSigma', 'f4', '', 30), 
           (116, 'solType', 'u1', '', 30), 
           (117, 'cs', 'u1', '', 30), 
           (118, 'lat', 'f8', '', 31), 
           (119, 'lon', 'f8', '', 31), 
           (120, 'alt', 'f8', '', 31), 
           (121, 'pSigma', 'f4', '', 31), 
           (122, 'solType', 'u1', '', 31), 
           (123, 'system', 'u1', '', 31), 
           (124, 'lat', 'f4', '', 32), 
           (125, 'lon', 'f4', '', 32), 
           (126, 'alt', 'f4', '', 32), 
           (127, 'vSigma', 'f4', '', 32), 
           (128, 'solType', 'u1', '', 32), 
           (129, 'cs', 'u1', '', 32), 
           (130, 'hpos', 'f4', '', 33), 
           (131, 'vpos', 'f4', '', 33), 
           (132, 'hvel', 'f4', '', 33), 
           (133, 'vvel', 'f4', '', 33), 
           (134, 'solType', 'u1', '', 33), 
           (135, 'cs', 'u1', '', 33), 
           (136, 'n', 'f8', '', 34), 
           (137, 'e', 'f8', '', 34), 
           (138, 'u', 'f8', '', 34), 
           (139, 'sep', 'f8', '', 34), 
           (140, 'pSigma', 'f4', '', 34), 
           (141, 'solType', 'u1', '', 34), 
           (142, 'geoid', 'u1', '', 34), 
           (143, 'prj', 'u2', '', 34), 
           (144, 'cs', 'u1', '', 34), 
           (145, 'n', 'f8', '', 35), 
           (146, 'e', 'f8', '', 35), 
           (147, 'u', 'f8', '', 35), 
           (148, 'sep', 'f8', '', 35), 
           (149, 'pSigma', 'f4', '', 35), 
           (150, 'solType', 'u1', '', 35), 
           (151, 'geoid', 'u1', '', 35), 
           (152, 'prj', 'u2', '', 35), 
           (153, 'cs', 'u1', '', 35), 
           (154, 'hdop', 'f4', '', 36), 
           (155, 'vdop', 'f4', '', 36), 
           (156, 'tdop', 'f4', '', 36), 
           (157, 'solType', 'u1', '', 36), 
           (158, 'edop', 'f4', '', 36), 
           (159, 'cs', 'u1', '', 36), 
           (160, 'xx', 'f4', '', 37), 
           (161, 'yy', 'f4', '', 37), 
           (162, 'zz', 'f4', '', 37), 
           (163, 'tt', 'f4', '', 37), 
           (164, 'xy', 'f4', '', 37), 
           (165, 'xz', 'f4', '', 37), 
           (166, 'xt', 'f4', '', 37), 
           (167, 'yz', 'f4', '', 37), 
           (168, 'yt', 'f4', '', 37), 
           (169, 'zt', 'f4', '', 37), 
           (170, 'solType', 'u1', '', 37), 
           (171, 'cs', 'u1', '', 37), 
           (172, 'xx', 'f4', '', 38), 
           (173, 'yy', 'f4', '', 38), 
           (174, 'zz', 'f4', '', 38), 
           (175, 'tt', 'f4', '', 38), 
           (176, 'xy', 'f4', '', 38), 
           (177, 'xz', 'f4', '', 38), 
           (178, 'xt', 'f4', '', 38), 
           (179, 'yz', 'f4', '', 38), 
           (180, 'yt', 'f4', '', 38), 
           (181, 'zt', 'f4', '', 38), 
           (182, 'solType', 'u1', '', 38), 
           (183, 'cs', 'u1', '', 38), 
           (184, 'x', 'f8', '', 39), 
           (185, 'y', 'f8', '', 39), 
           (186, 'z', 'f8', '', 39), 
           (187, 'sigma', 'f4', '', 39), 
           (188, 'solType', 'u1', '', 39), 
           (189, 'time', 'i4', '', 39), 
           (190, 'cs', 'u1', '', 39), 
           (191, 'bl0', 'f4', '', 40), 
           (192, 'bl1', 'f4', '', 40), 
           (193, 'bl2', 'f4', '', 40), 
           (194, 'rms', 'f4', '', 40), 
           (195, 'solType', 'u1', '', 40), 
           (196, 'cs', 'u1', '', 40), 
           (197, 'q00', 'f4', '', 41), 
           (198, 'q01', 'f4', '', 41), 
           (199, 'q02', 'f4', '', 41), 
           (200, 'q10', 'f4', '', 41), 
           (201, 'q11', 'f4', '', 41), 
           (202, 'q12', 'f4', '', 41), 
           (203, 'q20', 'f4', '', 41), 
           (204, 'q21', 'f4', '', 41), 
           (205, 'q22', 'f4', '', 41), 
           (206, 'cs', 'u1', '', 41), 
           (207, 'solType', 'u1', '', 42), 
           (208, 'gpsLocked', 'u1', '', 42), 
           (209, 'gloLocked', 'u1', '', 42), 
           (210, 'gpsAvail', 'u1', '', 42), 
           (211, 'gloAvail', 'u1', '', 42), 
           (212, 'gpsUsed', 'u1', '', 42), 
           (213, 'gloUsed', 'u1', '', 42), 
           (214, 'fixProg', 'u1', '', 42), 
           (215, 'cs', 'u1', '', 42), 
           (216, 'pt', 'u4', '', 43), 
           (217, 'cs', 'u1', '', 43), 
           (218, 'esi', 'ESI', '', 44), 
           (219, 'cs', 'u1', '', 44), 
           (220, 'usi', 'u1', '', 45), 
           (221, 'cs', 'u1', '', 45), 
           (222, 'name', 'a1', '', 46), 
           (223, 'cs', 'u1', '', 46), 
           (224, 'osn', 'u1', '', 47), 
           (225, 'cs', 'u1', '', 47), 
           (226, 'elev', 'i1', '', 48), 
           (227, 'cs', 'u1', '', 48), 
           (228, 'azim', 'u1', '', 49), 
           (229, 'cs', 'u1', '', 49), 
           (230, 'pr', 'f8', '', 50), 
           (231, 'cs', 'u1', '', 50), 
           (232, 'spr', 'i4', '', 51), 
           (233, 'cs', 'u1', '', 51), 
           (234, 'rpr', 'f4', '', 52), 
           (235, 'cs', 'u1', '', 52), 
           (236, 'srpr', 'i2', '', 53), 
           (237, 'cs', 'u1', '', 53), 
           (238, 'prc', 'i2', '', 54), 
           (239, 'mode', 'u1', '', 54), 
           (240, 'cs', 'u1', '', 54), 
           (241, 'smooth', 'Smooth', '', 55), 
           (242, 'cs', 'u1', '', 55), 
           (243, 'smooth', 'i2', '', 56), 
           (244, 'cs', 'u1', '', 56), 
           (245, 'cp', 'f8', '', 57), 
           (246, 'cs', 'u1', '', 57), 
           (247, 'scp', 'u4', '', 58), 
           (248, 'cs', 'u1', '', 58), 
           (249, 'rcp', 'f4', '', 59), 
           (250, 'cs', 'u1', '', 59), 
           (251, 'rcp', 'i4', '', 60), 
           (252, 'cs', 'u1', '', 60), 
           (253, 'phc', 'i2', '', 61), 
           (254, 'mode', 'u1', '', 61), 
           (255, 'cs', 'u1', '', 61), 
           (256, 'dp', 'i4', '', 62), 
           (257, 'cs', 'u1', '', 62), 
           (258, 'srdp', 'i2', '', 63), 
           (259, 'cs', 'u1', '', 63), 
           (260, 'cnr', 'u1', '', 64), 
           (261, 'cs', 'u1', '', 64), 
           (262, 'cnrX4', 'u1', '', 65), 
           (263, 'cs', 'u1', '', 65), 
           (264, 'cnrX256', 'u2', '', 66), 
           (265, 'cs', 'u1', '', 66), 
           (266, 'cnrX256', 'u2', '', 67), 
           (267, 'cs', 'u1', '', 67), 
           (268, 'flags', 'u2', '', 68), 
           (269, 'cs', 'u1', '', 68), 
           (270, 'amp', 'i2', '', 69), 
           (271, 'cs', 'u1', '', 69), 
           (272, 'amp', 'i2', '', 70), 
           (273, 'cs', 'u1', '', 70), 
           (274, 'tt', 'u2', '', 71), 
           (275, 'cs', 'u1', '', 71), 
           (276, 'ns', 'u1', '', 72), 
           (277, 'solType', 'u1', '', 72), 
           (278, 'cs', 'u1', '', 72), 
           (279, 'delay', 'f4', '', 73), 
           (280, 'cs', 'u1', '', 73), 
           (281, 'res', 'f4', '', 74), 
           (282, 'cs', 'u1', '', 74), 
           (283, 'res', 'f4', '', 75), 
           (284, 'cs', 'u1', '', 75), 
           (285, 'sv', 'u1', '', 76), 
           (286, 'wna', 'i2', '', 76), 
           (287, 'toa', 'i4', '', 76), 
           (288, 'healthA', 'u1', '', 76), 
           (289, 'config', 'u1', '', 76), 
           (290, 'af1', 'f4', '', 76), 
           (291, 'af0', 'f4', '', 76), 
           (292, 'rootA', 'f4', '', 76), 
           (293, 'ecc', 'f4', '', 76), 
           (294, 'm0', 'f4', '', 76), 
           (295, 'omega0', 'f4', '', 76), 
           (296, 'argPer', 'f4', '', 76), 
           (297, 'deli', 'f4', '', 76), 
           (298, 'omegaDot', 'f4', '', 76), 
           (299, 'cs', 'u1', '', 76), 
           (300, 'gps', 'GPSAlm1', '', 77), 
           (301, 'iod', 'i2', '', 77), 
           (302, 'cs', 'u1', '', 77), 
           (303, 'gps', 'GPSAlm1', '', 78), 
           (304, 'gps', 'GPSAlm1', '', 79), 
           (305, 'gps', 'GPSAlm1', '', 80), 
           (306, 'sv', 'u1', '', 81), 
           (307, 'frqNum', 'i1', '', 81), 
           (308, 'dna', 'i2', '', 81), 
           (309, 'tlam', 'f4', '', 81), 
           (310, 'flags', 'u1', '', 81), 
           (311, 'tauN', 'f4', '', 81), 
           (312, 'tauSys', 'f8', '', 81), 
           (313, 'ecc', 'f4', '', 81), 
           (314, 'lambda', 'f4', '', 81), 
           (315, 'argPer', 'f4', '', 81), 
           (316, 'delT', 'f4', '', 81), 
           (317, 'delTdt', 'f4', '', 81), 
           (318, 'deli', 'f4', '', 81), 
           (319, 'n4', 'u1', '', 81), 
           (320, 'reserved', 'u1', '', 81), 
           (321, 'gammaN', 'f4', '', 81), 
           (322, 'cs', 'u1', '', 81), 
           (323, 'waasPrn', 'u1', '', 82), 
           (324, 'gpsPrn', 'u1', '', 82), 
           (325, 'id', 'u1', '', 82), 
           (326, 'healthS', 'u1', '', 82), 
           (327, 'tod', 'u4', '', 82), 
           (328, 'xg', 'f8', '', 82), 
           (329, 'yg', 'f8', '', 82), 
           (330, 'zg', 'f8', '', 82), 
           (331, 'vxg', 'f4', '', 82), 
           (332, 'vyg', 'f4', '', 82), 
           (333, 'vzg', 'f4', '', 82), 
           (334, 'tow', 'u4', '', 82), 
           (335, 'wn', 'u2', '', 82), 
           (336, 'cs', 'u1', '', 82), 
           (337, 'req', 'GpsEphReqData', '', 83), 
           (338, 'opt', 'GpsEphOptData', '', 83), 
           (339, 'cs', 'u1', '', 83), 
           (340, 'req', 'GpsEphReqData', '', 84), 
           (341, 'bgdE1E5a', 'f4', '', 84), 
           (342, 'bgdE1E5b', 'f4', '', 84), 
           (343, 'ai0', 'f4', '', 84), 
           (344, 'ai1', 'f4', '', 84), 
           (345, 'ai2', 'f4', '', 84), 
           (346, 'sfi', 'u1', '', 84), 
           (347, 'navType', 'u1', '', 84), 
           (348, 'DAf0', 'f4', '', 84), 
           (349, 'cs', 'u1', '', 84), 
           (350, 'gps', 'GPSEphemeris1', '', 85), 
           (351, 'cs', 'u1', '', 85), 
           (352, 'req', 'GpsEphReqData', '', 86), 
           (353, 'tgd2', 'f4', '', 86), 
           (354, 'navType', 'u1', '', 86), 
           (355, 'DAf0', 'f4', '', 86), 
           (356, 'cs', 'u1', '', 86), 
           (357, 'sv', 'u1', '', 87), 
           (358, 'frqNum', 'i1', '', 87), 
           (359, 'dne', 'i2', '', 87), 
           (360, 'tk', 'i4', '', 87), 
           (361, 'tb', 'i4', '', 87), 
           (362, 'health', 'u1', '', 87), 
           (363, 'age', 'u1', '', 87), 
           (364, 'flags', 'u1', '', 87), 
           (365, 'r', 'f8', '', 87), 
           (366, 'v', 'f4', '', 87), 
           (367, 'w', 'f4', '', 87), 
           (368, 'tauSys', 'f8', '', 87), 
           (369, 'tau', 'f4', '', 87), 
           (370, 'gamma', 'f4', '', 87), 
           (371, 'fDelTauN', 'f4', '', 87), 
           (372, 'nFt', 'u1', '', 87), 
           (373, 'nN4', 'u1', '', 87), 
           (374, 'flags2', 'u2', '', 87), 
           (375, 'navType', 'u1', '', 87), 
           (376, 'beta', 'f4', '', 87), 
           (377, 'tauSysDot', 'f4', '', 87), 
           (378, 'ec', 'u1', '', 87), 
           (379, 'ee', 'u1', '', 87), 
           (380, 'fc', 'i1', '', 87), 
           (381, 'fe', 'i1', '', 87), 
           (382, 'reserv', 'u2', '', 87), 
           (383, 'cs', 'u1', '', 87), 
           (384, 'waasPrn', 'u1', '', 88), 
           (385, 'gpsPrn', 'u1', '', 88), 
           (386, 'iod', 'u1', '', 88), 
           (387, 'acc', 'u1', '', 88), 
           (388, 'tod', 'u4', '', 88), 
           (389, 'xg', 'f8', '', 88), 
           (390, 'yg', 'f8', '', 88), 
           (391, 'zg', 'f8', '', 88), 
           (392, 'vxg', 'f4', '', 88), 
           (393, 'vyg', 'f4', '', 88), 
           (394, 'vzg', 'f4', '', 88), 
           (395, 'vvxg', 'f4', '', 88), 
           (396, 'vvyg', 'f4', '', 88), 
           (397, 'vvzg', 'f4', '', 88), 
           (398, 'agf0', 'f4', '', 88), 
           (399, 'agf1', 'f4', '', 88), 
           (400, 'tow', 'u4', '', 88), 
           (401, 'wn', 'u2', '', 88), 
           (402, 'flags', 'u2', '', 88), 
           (403, 'cs', 'u1', '', 88), 
           (404, 'gps', 'GPSEphemeris1', '', 89), 
           (405, 'navType', 'u1', '', 89), 
           (406, 'cs', 'u1', '', 89), 
           (407, 'prn', 'u1', '', 90), 
           (408, 'time', 'u4', '', 90), 
           (409, 'type', 'u1', '', 90), 
           (410, 'len', 'u1', '', 90), 
           (411, 'data', 'u4', '', 90), 
           (412, 'errCorr', 'i1', '', 90), 
           (413, 'cs', 'u1', '', 90), 
           (414, 'data', 'GpsRawNavData1', '', 91), 
           (415, 'num', 'u1', '', 92), 
           (416, 'fcn', 'i1', '', 92), 
           (417, 'time', 'u4', '', 92), 
           (418, 'type', 'u1', '', 92), 
           (419, 'len', 'u1', '', 92), 
           (420, 'data', 'u4', '', 92), 
           (421, 'errCorr', 'i1', '', 92), 
           (422, 'cs', 'u1', '', 92), 
           (423, 'prn', 'u1', '', 93), 
           (424, 'time', 'u4', '', 93), 
           (425, 'type', 'u1', '', 93), 
           (426, 'len', 'u1', '', 93), 
           (427, 'data', 'u1', '', 93), 
           (428, 'errCorr', 'i1', '', 93), 
           (429, 'cs', 'u1', '', 93), 
           (430, 'prn', 'u1', '', 94), 
           (431, 'time', 'u4', '', 94), 
           (432, 'type', 'u1', '', 94), 
           (433, 'len', 'u1', '', 94), 
           (434, 'data', 'u1', '', 94), 
           (435, 'errCorr', 'i1', '', 94), 
           (436, 'cs', 'u1', '', 94), 
           (437, 'prn', 'u1', '', 95), 
           (438, 'time', 'u4', '', 95), 
           (439, 'type', 'u1', '', 95), 
           (440, 'len', 'u1', '', 95), 
           (441, 'prn', 'u1', '', 96), 
           (442, 'time', 'u4', '', 96), 
           (443, 'type', 'u1', '', 96), 
           (444, 'len', 'u1', '', 96), 
           (445, 'recSize', 'u1', '', 97), 
           (446, 'dat', 'SvData0', '', 97), 
           (447, 'cs', 'u1', '', 97), 
           (448, 'data', 'GpsNavData1', '', 98), 
           (449, 'recSize', 'u1', '', 99), 
           (450, 'dat', 'SvData1', '', 99), 
           (451, 'cs', 'u1', '', 99), 
           (452, 'currFrq', 'i2', '', 100), 
           (453, 'finalFrq', 'i2', '', 100), 
           (454, 'n', 'u1', '', 100), 
           (455, 'm', 'u1', '', 100), 
           (456, 's', 'SpecData', '', 100), 
           (457, 'cs', 'u1', '', 100), 
           (458, 'currFrq', 'i2', '', 101), 
           (459, 'finalFrq', 'i2', '', 101), 
           (460, 'n', 'u1', '', 101), 
           (461, 'm', 'u1', '', 101), 
           (462, 's', 'ExtSpecData', '', 101), 
           (463, 'cs', 'u1', '', 101), 
           (464, 'frq', 'i4', '', 102), 
           (465, 'pwr', 'i4', '', 102), 
           (466, 'cs', 'u1', '', 102), 
           (467, 'del', 'SvDelay', '', 103), 
           (468, 'cs', 'u1', '', 103), 
           (469, 'd', 'BandDelay', '', 104), 
           (470, 'cs', 'u1', '', 104), 
           (471, 'time', 'u4', '', 105), 
           (472, 'q00', 'f4', '', 105), 
           (473, 'q01', 'f4', '', 105), 
           (474, 'q02', 'f4', '', 105), 
           (475, 'q12', 'f4', '', 105), 
           (476, 'rms', 'f4', '', 105), 
           (477, 'solType', 'u1', '', 105), 
           (478, 'flag', 'u1', '', 105), 
           (479, 'cs', 'u1', '', 105), 
           (480, 'time', 'u4', '', 106), 
           (481, 'q00', 'f4', '', 106), 
           (482, 'q01', 'f4', '', 106), 
           (483, 'q02', 'f4', '', 106), 
           (484, 'q12', 'f4', '', 106), 
           (485, 'rms', 'f4', '', 106), 
           (486, 'solType', 'u1', '', 106), 
           (487, 'flag', 'u1', '', 106), 
           (488, 'bl1', 'f4', '', 106), 
           (489, 'bl2', 'f4', '', 106), 
           (490, 'cs', 'u1', '', 106), 
           (491, 'time', 'u4', '', 107), 
           (492, 'p', 'f4', '', 107), 
           (493, 'r', 'f4', '', 107), 
           (494, 'h', 'f4', '', 107), 
           (495, 'sp', 'f4', '', 107), 
           (496, 'sr', 'f4', '', 107), 
           (497, 'sh', 'f4', '', 107), 
           (498, 'solType', 'u1', '', 107), 
           (499, 'flags', 'u1', '', 107), 
           (500, 'cs', 'u1', '', 107), 
           (501, 'time', 'u4', '', 108), 
           (502, 'x', 'f4', '', 108), 
           (503, 'y', 'f4', '', 108), 
           (504, 'z', 'f4', '', 108), 
           (505, 'rms', 'f4', '', 108), 
           (506, 'flags', 'u1', '', 108), 
           (507, 'cs', 'u1', '', 108), 
           (508, 'accelerations', 'f4', '', 109), 
           (509, 'angularVelocities', 'f4', '', 109), 
           (510, 'cs', 'u1', '', 109), 
           (511, 'time', 'u4', '', 110), 
           (512, 'accelerations', 'f4', '', 110), 
           (513, 'induction', 'f4', '', 110), 
           (514, 'magnitude', 'f4', '', 110), 
           (515, 'temperature', 'f4', '', 110), 
           (516, 'calibrated', 'u1', '', 110), 
           (517, 'cs', 'u1', '', 110), 
           (518, 'ms', 'i4', '', 111), 
           (519, 'ns', 'i4', '', 111), 
           (520, 'timeScale', 'u1', '', 111), 
           (521, 'cs', 'u1', '', 111), 
           (522, 'offs', 'f4', '', 112), 
           (523, 'cs', 'u1', '', 112), 
           (524, 'offs', 'f8', '', 113), 
           (525, 'timeScale', 'u1', '', 113), 
           (526, 'cs', 'u1', '', 113), 
           (527, 'heading', 'f4', '', 114), 
           (528, 'pitch', 'f4', '', 114), 
           (529, 'solType', 'u1', '', 114), 
           (530, 'cs', 'u1', '', 114), 
           (531, 'sample', 'u2', '', 115), 
           (532, 'scale', 'u2', '', 115), 
           (533, 'reftime', 'u4', '', 115), 
           (534, 'crc16', 'u2', '', 115), 
           (535, 'sample', 'u2', '', 116), 
           (536, 'scale', 'u2', '', 116), 
           (537, 'reftime', 'u4', '', 116), 
           (538, 'clock', 'i2', '', 116), 
           (539, 'flags', 'u2', '', 116), 
           (540, 'svd', 'SvData2', '', 116), 
           (541, 'crc16', 'u2', '', 116), 
           (542, 'sample', 'u2', '', 117), 
           (543, 'delta', 'u2', '', 117), 
           (544, 'word1', 'u4', '', 117), 
           (545, 'word2', 'u4', '', 117), 
           (546, 'word3', 'u4', '', 117), 
           (547, 'word4', 'u4', '', 117), 
           (548, 'word5', 'u4', '', 117), 
           (549, 'word6', 'u4', '', 117), 
           (550, 'word7', 'u4', '', 117), 
           (551, 'word8', 'u4', '', 117), 
           (552, 'word9', 'u4', '', 117), 
           (553, 'crc16', 'u2', '', 117), 
           (554, 'sample', 'u2', '', 118), 
           (555, 'reserved', 'u2', '', 118), 
           (556, 'Offs', 'ClkOffs', '', 118), 
           (557, 'crc16', 'u2', '', 118), 
           (558, 'reply', 'a1', '', 119), 
           (559, 'error', 'a1', '', 120), 
           (560, 'tot', 'u4', '', 121), 
           (561, 'wn', 'u2', '', 121), 
           (562, 'alpha0', 'f4', '', 121), 
           (563, 'alpha1', 'f4', '', 121), 
           (564, 'alpha2', 'f4', '', 121), 
           (565, 'alpha3', 'f4', '', 121), 
           (566, 'beta0', 'f4', '', 121), 
           (567, 'beta1', 'f4', '', 121), 
           (568, 'beta2', 'f4', '', 121), 
           (569, 'beta3', 'f4', '', 121), 
           (570, 'cs', 'u1', '', 121), 
           (571, 'par', 'IonoParams1', '', 122), 
           (572, 'par', 'IonoParams1', '', 123), 
           (573, 'par', 'IonoParams1', '', 124), 
           (574, 'time', 'u4', '', 125), 
           (575, 'type', 'u1', '', 125), 
           (576, 'data', 'u1', '', 125), 
           (577, 'cs', 'u1', '', 125), 
           (578, 'lt', 'u1', '', 126), 
           (579, 'cs', 'u1', '', 126), 
           (580, 'id', 'u1', '', 127), 
           (581, 'data', 'u1', '', 127), 
           (582, 'cs', 'a1', '', 127), 
           (583, 'params', 'a1', '', 128), 
           (584, 'svsCount', 'u1', '', 129), 
           (585, 'targetStream', 'u1', '', 129), 
           (586, 'issue', 'u2', '', 129), 
           (587, 'bitsCount', 'u2', '', 129), 
           (588, 'lastBitTime', 'u4', '', 129), 
           (589, 'uids', 'u1', '', 129), 
           (590, 'pad', 'u1', '', 129), 
           (591, 'hist', 'u4', '', 129), 
           (592, 'x', 'f8', '', 130), 
           (593, 'y', 'f8', '', 130), 
           (594, 'z', 'f8', '', 130), 
           (595, 'id', 'u2', '', 130), 
           (596, 'solType', 'u1', '', 130), 
           (597, 'cs', 'u1', '', 130), 
           (598, 'data', 'u1', '', 131), 
           (599, 'cs', 'u1', '', 131), 
           (600, 'data', 'u1', '', 132), 
           (601, 'crc16', 'u2', '', 132), 
           (602, 'tt', 'u4', '', 133), 
           (603, 'cs', 'u1', '', 133), 
           (604, 'val', 'f4', '', 134), 
           (605, 'cs', 'u1', '', 134);

INSERT INTO `customTypeVariableMeta` (`id`, `name`, `greisType`, `requiredValue`, `idCustomTypeMeta`) 
    VALUES (1, 'a0', 'f8', '', 1), 
           (2, 'a1', 'f4', '', 1), 
           (3, 'tot', 'u4', '', 1), 
           (4, 'wnt', 'u2', '', 1), 
           (5, 'dtls', 'i1', '', 1), 
           (6, 'dn', 'u1', '', 1), 
           (7, 'wnlsf', 'u2', '', 1), 
           (8, 'dtlsf', 'i1', '', 1), 
           (9, 'ssid', 'u1', '', 2), 
           (10, 'svid', 'u1', '', 2), 
           (11, 'value', 'f4', '', 3), 
           (12, 'interval', 'u2', '', 3), 
           (13, 'sv', 'u1', '', 4), 
           (14, 'tow', 'u4', '', 4), 
           (15, 'flags', 'u1', '', 4), 
           (16, 'iodc', 'i2', '', 4), 
           (17, 'toc', 'i4', '', 4), 
           (18, 'ura', 'i1', '', 4), 
           (19, 'healthS', 'u1', '', 4), 
           (20, 'wn', 'i2', '', 4), 
           (21, 'tgd', 'f4', '', 4), 
           (22, 'af2', 'f4', '', 4), 
           (23, 'af1', 'f4', '', 4), 
           (24, 'af0', 'f4', '', 4), 
           (25, 'toe', 'i4', '', 4), 
           (26, 'iode', 'i2', '', 4), 
           (27, 'rootA', 'f8', '', 4), 
           (28, 'ecc', 'f8', '', 4), 
           (29, 'm0', 'f8', '', 4), 
           (30, 'omega0', 'f8', '', 4), 
           (31, 'inc0', 'f8', '', 4), 
           (32, 'argPer', 'f8', '', 4), 
           (33, 'deln', 'f4', '', 4), 
           (34, 'omegaDot', 'f4', '', 4), 
           (35, 'incDot', 'f4', '', 4), 
           (36, 'crc', 'f4', '', 4), 
           (37, 'crs', 'f4', '', 4), 
           (38, 'cuc', 'f4', '', 4), 
           (39, 'cus', 'f4', '', 4), 
           (40, 'cic', 'f4', '', 4), 
           (41, 'cis', 'f4', '', 4), 
           (42, 'navType', 'u1', '', 5), 
           (43, 'lTope', 'i4', '', 5), 
           (44, 'lTopc', 'i4', '', 5), 
           (45, 'dADot', 'f8', '', 5), 
           (46, 'cURAoc', 'i1', '', 5), 
           (47, 'cURAoc1', 'i1', '', 5), 
           (48, 'cURAoc2', 'i1', '', 5), 
           (49, 'fIscL1CA', 'f4', '', 5), 
           (50, 'fIscL5I5', 'f4', '', 5), 
           (51, 'fIscL1CP', 'f4', '', 5), 
           (52, 'DAf0', 'f4', '', 5), 
           (53, 'prn', 'i1', '', 6), 
           (54, 'cnt', 'u1', '', 6), 
           (55, 'data', 'u4', '', 6), 
           (56, 'fcn1', 'i1', '', 7), 
           (57, 'cnt', 'u1', '', 7), 
           (58, 'data', 'u4', '', 7), 
           (59, 'spec', 'i2', '', 8), 
           (60, 'spec', 'i2', '', 9), 
           (61, 'agcmin', 'u1', '', 9), 
           (62, 'agcmax', 'u1', '', 9), 
           (63, 'fcn', 'i1', '', 10), 
           (64, 'phase', 'f4', '', 10), 
           (65, 'range', 'f4', '', 10), 
           (66, 'band', 'i1', '', 11), 
           (67, 'signal', 'i1', '', 11), 
           (68, 'delay', 'f4', '', 11), 
           (69, 'header', 'Header', '', 12), 
           (70, 'slot', 'SlotRec', '', 12), 
           (71, 'refrange', 'u4', '', 13), 
           (72, 'usi', 'u1', '', 13), 
           (73, 'num', 'u1', '', 13), 
           (74, 'svstOrDelrange', 'i2', '', 14), 
           (75, 'word1', 'u4', '', 14), 
           (76, 'flags', 'u2', '', 14), 
           (77, 'lock', 'u2', '', 14), 
           (78, 'word2', 'u4', '', 14), 
           (79, 'word1', 'u4', '', 15), 
           (80, 'word2', 'u4', '', 15), 
           (81, 'sv', 'u1', '', 16), 
           (82, 'wna', 'i2', '', 16), 
           (83, 'toa', 'i4', '', 16), 
           (84, 'healthA', 'u1', '', 16), 
           (85, 'config', 'u1', '', 16), 
           (86, 'af1', 'f4', '', 16), 
           (87, 'af0', 'f4', '', 16), 
           (88, 'rootA', 'f4', '', 16), 
           (89, 'ecc', 'f4', '', 16), 
           (90, 'm0', 'f4', '', 16), 
           (91, 'omega0', 'f4', '', 16), 
           (92, 'argPer', 'f4', '', 16), 
           (93, 'deli', 'f4', '', 16), 
           (94, 'omegaDot', 'f4', '', 16), 
           (95, 'req', 'GpsEphReqData', '', 17), 
           (96, 'opt', 'GpsEphOptData', '', 17), 
           (97, 'tot', 'u4', '', 18), 
           (98, 'wn', 'u2', '', 18), 
           (99, 'alpha0', 'f4', '', 18), 
           (100, 'alpha1', 'f4', '', 18), 
           (101, 'alpha2', 'f4', '', 18), 
           (102, 'alpha3', 'f4', '', 18), 
           (103, 'beta0', 'f4', '', 18), 
           (104, 'beta1', 'f4', '', 18), 
           (105, 'beta2', 'f4', '', 18), 
           (106, 'beta3', 'f4', '', 18), 
           (107, 'cs', 'u1', '', 18), 
           (108, 'recSize', 'u1', '', 19), 
           (109, 'dat', 'SvData0', '', 19), 
           (110, 'cs', 'u1', '', 19), 
           (111, 'prn', 'u1', '', 20), 
           (112, 'time', 'u4', '', 20), 
           (113, 'type', 'u1', '', 20), 
           (114, 'len', 'u1', '', 20), 
           (115, 'data', 'u4', '', 20), 
           (116, 'errCorr', 'i1', '', 20), 
           (117, 'cs', 'u1', '', 20);

-- Наполнение информации о размерностях для пользовательского типа `SvData0`
INSERT INTO `customTypeVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (55, 1, 10);

-- Наполнение информации о размерностях для пользовательского типа `SvData1`
INSERT INTO `customTypeVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (58, 1, 4);

-- Наполнение информации о размерностях для пользовательского типа `SpecData`
INSERT INTO `customTypeVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (59, 1, -2);

-- Наполнение информации о размерностях для пользовательского типа `ExtSpecData`
INSERT INTO `customTypeVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (60, 1, -2), 
           (61, 1, -2), 
           (62, 1, -2);

-- Наполнение информации о размерностях для пользовательского типа `SvData2`
INSERT INTO `customTypeVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (70, 1, -2);

-- Наполнение информации о размерностях для пользовательского типа `GpsNavData1`
INSERT INTO `customTypeVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (109, 1, -2);

-- Наполнение информации о размерностях для пользовательского типа `GpsRawNavData1`
INSERT INTO `customTypeVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (115, 1, -2);

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

-- Наполнение информации о размерностях для сообщения `SpecificCrtPos0`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (94, 1, 5);

-- Наполнение информации о размерностях для сообщения `Baselines`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (191, 1, 3), 
           (192, 1, 3), 
           (193, 1, 3), 
           (194, 1, 3), 
           (195, 1, 3);

-- Наполнение информации о размерностях для сообщения `ExtSatIndex`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (218, 1, -2);

-- Наполнение информации о размерностях для сообщения `SatIndex`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (220, 1, -2);

-- Наполнение информации о размерностях для сообщения `AntName`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (222, 1, -2);

-- Наполнение информации о размерностях для сообщения `SatNumbers`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (224, 1, -2);

-- Наполнение информации о размерностях для сообщения `SatElevation`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (226, 1, -2);

-- Наполнение информации о размерностях для сообщения `SatAzimuth`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (228, 1, -2);

-- Наполнение информации о размерностях для сообщения `PR`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (230, 1, -2);

-- Наполнение информации о размерностях для сообщения `SPR`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (232, 1, -2);

-- Наполнение информации о размерностях для сообщения `RPR`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (234, 1, -2);

-- Наполнение информации о размерностях для сообщения `SRPR`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (236, 1, -2);

-- Наполнение информации о размерностях для сообщения `PrCorr`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (238, 1, -2);

-- Наполнение информации о размерностях для сообщения `SC`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (241, 1, -2);

-- Наполнение информации о размерностях для сообщения `SS`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (243, 1, -2);

-- Наполнение информации о размерностях для сообщения `CP`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (245, 1, -2);

-- Наполнение информации о размерностях для сообщения `SCP`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (247, 1, -2);

-- Наполнение информации о размерностях для сообщения `RCP_RC`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (249, 1, -2);

-- Наполнение информации о размерностях для сообщения `RCP_rc`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (251, 1, -2);

-- Наполнение информации о размерностях для сообщения `PhCorr`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (253, 1, -2);

-- Наполнение информации о размерностях для сообщения `DP`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (256, 1, -2);

-- Наполнение информации о размерностях для сообщения `SRDP`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (258, 1, -2);

-- Наполнение информации о размерностях для сообщения `CNR`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (260, 1, -2);

-- Наполнение информации о размерностях для сообщения `CNR_4`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (262, 1, -2);

-- Наполнение информации о размерностях для сообщения `CNR_2560`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (264, 1, -2);

-- Наполнение информации о размерностях для сообщения `CNR_2561`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (266, 1, -2);

-- Наполнение информации о размерностях для сообщения `Flags`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (268, 1, -2);

-- Наполнение информации о размерностях для сообщения `IAmp`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (270, 1, -2);

-- Наполнение информации о размерностях для сообщения `QAmp`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (272, 1, -2);

-- Наполнение информации о размерностях для сообщения `TrackingTimeCA`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (274, 1, -2);

-- Наполнение информации о размерностях для сообщения `NavStatus`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (276, 1, -2);

-- Наполнение информации о размерностях для сообщения `IonoDelay`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (279, 1, -2);

-- Наполнение информации о размерностях для сообщения `RangeResidual`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (281, 1, -2);

-- Наполнение информации о размерностях для сообщения `VelocityResidual`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (283, 1, -2);

-- Наполнение информации о размерностях для сообщения `GLOEphemeris`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (365, 1, 3), 
           (366, 1, 3), 
           (367, 1, 3);

-- Наполнение информации о размерностях для сообщения `GpsRawNavData0`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (411, 1, -2);

-- Наполнение информации о размерностях для сообщения `GloRawNavData`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (420, 1, -2);

-- Наполнение информации о размерностях для сообщения `SbasRawNavData`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (427, 1, 32);

-- Наполнение информации о размерностях для сообщения `GalRawNavData`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (434, 1, -2);

-- Наполнение информации о размерностях для сообщения `GpsNavData0`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (446, 1, -2);

-- Наполнение информации о размерностях для сообщения `GloNavData`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (450, 1, -2);

-- Наполнение информации о размерностях для сообщения `Spectrum0`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (456, 1, -2);

-- Наполнение информации о размерностях для сообщения `Spectrum1`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (462, 1, -2);

-- Наполнение информации о размерностях для сообщения `GloDelays`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (467, 1, -2);

-- Наполнение информации о размерностях для сообщения `CalBandsDelay`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (469, 1, -2);

-- Наполнение информации о размерностях для сообщения `RotationMatrix`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (476, 1, 3), 
           (477, 1, 3);

-- Наполнение информации о размерностях для сообщения `RotationMatrixAndVectors`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (485, 1, 3), 
           (486, 1, 3), 
           (488, 1, 3), 
           (489, 1, 3);

-- Наполнение информации о размерностях для сообщения `RotationAngles`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (498, 1, 3);

-- Наполнение информации о размерностях для сообщения `InertialMeasurements`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (508, 1, 3), 
           (509, 1, 3);

-- Наполнение информации о размерностях для сообщения `AccMag`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (512, 1, 3), 
           (513, 1, 3);

-- Наполнение информации о размерностях для сообщения `RawMeas`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (540, 1, -2);

-- Наполнение информации о размерностях для сообщения `ClockOffsets`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (556, 1, -2);

-- Наполнение информации о размерностях для сообщения `RE`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (558, 1, -2);

-- Наполнение информации о размерностях для сообщения `ER`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (559, 1, -2);

-- Наполнение информации о размерностях для сообщения `Event`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (576, 1, -2);

-- Наполнение информации о размерностях для сообщения `Wrapper`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (581, 1, -2), 
           (582, 1, 2);

-- Наполнение информации о размерностях для сообщения `Params`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (583, 1, -2);

-- Наполнение информации о размерностях для сообщения `LoggingHistory`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (589, 1, -2), 
           (590, 1, -2), 
           (591, 1, -2), 
           (591, 2, -2);

-- Наполнение информации о размерностях для сообщения `Security0`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (598, 1, 5);

-- Наполнение информации о размерностях для сообщения `Security1`
INSERT INTO `messageVariableSizeForDimension` (`idVariable`, `dimensionNumber`, `size`) 
    VALUES (600, 1, 6);



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
