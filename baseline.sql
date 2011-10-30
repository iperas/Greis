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
DROP TABLE IF EXISTS `msg_GPSAlm`;
DROP TABLE IF EXISTS `msg_GALAlm`;
DROP TABLE IF EXISTS `msg_GLOAlmanac`;
DROP TABLE IF EXISTS `msg_WAASAlmanac`;
DROP TABLE IF EXISTS `msg_GPSEphemeris`;
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
         `idCustomTypesMeta` BIGINT UNSIGNED NOT NULL,
         PRIMARY KEY (`id`),
         INDEX `idx_fk_customTypeVariablesMeta_idCustomTypesMeta` (`idCustomTypesMeta`),
         CONSTRAINT `fk_customTypeVariablesMeta_idCustomTypesMeta` FOREIGN KEY (`idCustomTypesMeta`) 
            REFERENCES `customTypesMeta` (`id`)
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
         INDEX `idx_fk_messageVariablesMeta_idMessagesMeta` (`idMessagesMeta`),
         CONSTRAINT `fk_messageVariablesMeta_idMessagesMeta` FOREIGN KEY (`idMessagesMeta`) 
            REFERENCES `messagesMeta` (`id`)
       );

-- коды сообщений в соответствии с идентификаторами
CREATE TABLE `messageCodes` (
         id SERIAL,
         code CHAR(2) NOT NULL,
         `idMessagesMeta` BIGINT UNSIGNED NOT NULL,
         PRIMARY KEY (`id`),
         INDEX `idx_fk_messageCodes_idMessagesMeta` (`idMessagesMeta`),
         CONSTRAINT `fk_messageCodes_idMessagesMeta` FOREIGN KEY (`idMessagesMeta`) 
            REFERENCES `messagesMeta` (`id`)
       );

-- custom type 'UtcOffs'
CREATE TABLE `ct_UtcOffs` (
    id SERIAL, 
    `a0` DOUBLE, 
    `a1` FLOAT, 
    `tot` INT UNSIGNED, 
    `wnt` SMALLINT UNSIGNED, 
    `dtls` TINYINT, 
    `dn` TINYINT UNSIGNED, 
    `wnlsf` SMALLINT UNSIGNED, 
    `dtlsf` TINYINT, 
    PRIMARY KEY (`id`));

-- custom type 'Smooth'
CREATE TABLE `ct_Smooth` (
    id SERIAL, 
    `value` FLOAT, 
    `interval` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`));

-- custom type 'SvData0'
CREATE TABLE `ct_SvData0` (
    id SERIAL, 
    `prn` TINYINT, 
    `cnt` TINYINT UNSIGNED, 
    `data` VARCHAR(2000), 
    PRIMARY KEY (`id`));

-- custom type 'SvData1'
CREATE TABLE `ct_SvData1` (
    id SERIAL, 
    `fcn1` TINYINT, 
    `cnt` TINYINT UNSIGNED, 
    `data` VARCHAR(2000), 
    PRIMARY KEY (`id`));

-- custom type 'SvData2'
CREATE TABLE `ct_SvData2` (
    id SERIAL, 
    `header` BIGINT UNSIGNED, 
    `slot` BIGINT UNSIGNED, 
    PRIMARY KEY (`id`));

-- custom type 'Header'
CREATE TABLE `ct_Header` (
    id SERIAL, 
    `refrange` INT UNSIGNED, 
    `usi` TINYINT UNSIGNED, 
    `num` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`));

-- custom type 'SlotRec'
CREATE TABLE `ct_SlotRec` (
    id SERIAL, 
    `svstOrDelrange` SMALLINT, 
    `word1` INT UNSIGNED, 
    `flags` SMALLINT UNSIGNED, 
    `lock` SMALLINT UNSIGNED, 
    `word2` INT UNSIGNED, 
    PRIMARY KEY (`id`));

-- custom type 'ClkOffs'
CREATE TABLE `ct_ClkOffs` (
    id SERIAL, 
    `word1` INT UNSIGNED, 
    `word2` INT UNSIGNED, 
    PRIMARY KEY (`id`));

-- message 'FileId': [JP] File Identifier
CREATE TABLE `msg_FileId` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `id_sugar` VARCHAR(1000), 
    `description` VARCHAR(1000), 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_FileId_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_FileId_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'MsgFmt': [MF] Messages Format
CREATE TABLE `msg_MsgFmt` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `id_sugar` VARCHAR(1000), 
    `majorVer` VARCHAR(1000), 
    `minorVer` VARCHAR(1000), 
    `order` CHAR, 
    `cs` VARCHAR(1000), 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_MsgFmt_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_MsgFmt_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'RcvTime': [~~](RT) Receiver Time
CREATE TABLE `msg_RcvTime` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `tod` INT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RcvTime_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_RcvTime_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'EpochTime': [::](ET) Epoch Time
CREATE TABLE `msg_EpochTime` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `tod` INT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_EpochTime_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_EpochTime_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'RcvDate': [RD] Receiver Date
CREATE TABLE `msg_RcvDate` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `year` SMALLINT UNSIGNED, 
    `month` TINYINT UNSIGNED, 
    `day` TINYINT UNSIGNED, 
    `base` TINYINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RcvDate_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_RcvDate_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'RcvTimeOffset': [TO] Reference Time to Receiver Time Offset
CREATE TABLE `msg_RcvTimeOffset` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `val` DOUBLE, 
    `sval` DOUBLE, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RcvTimeOffset_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_RcvTimeOffset_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'RcvTimeOffsetDot': [DO] Derivative of Receiver Time Offset
CREATE TABLE `msg_RcvTimeOffsetDot` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `val` FLOAT, 
    `sval` FLOAT, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RcvTimeOffsetDot_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_RcvTimeOffsetDot_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'RcvTimeAccuracy': [BP] Rough Accuracy of Time Approximation
CREATE TABLE `msg_RcvTimeAccuracy` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `acc` FLOAT, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RcvTimeAccuracy_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_RcvTimeAccuracy_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'GPSTime': [GT] GPS Time
CREATE TABLE `msg_GPSTime` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `tow` INT UNSIGNED, 
    `wn` SMALLINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_GPSTime_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_GPSTime_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'RcvGPSTimeOffset': [GO] GPS to Receiver Time Offset
CREATE TABLE `msg_RcvGPSTimeOffset` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `val` DOUBLE, 
    `sval` DOUBLE, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RcvGPSTimeOffset_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_RcvGPSTimeOffset_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'GLOTime': [NT] GLONASS Time
CREATE TABLE `msg_GLOTime` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `tod` INT UNSIGNED, 
    `dn` SMALLINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_GLOTime_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_GLOTime_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'RcvGLOTimeOffset': [NO] GLONASS to Receiver Time Offset
CREATE TABLE `msg_RcvGLOTimeOffset` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `val` DOUBLE, 
    `sval` DOUBLE, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RcvGLOTimeOffset_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_RcvGLOTimeOffset_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'RcvGALTimeOffset': [EO] GALILEO to Receiver Time Offset
CREATE TABLE `msg_RcvGALTimeOffset` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `val` DOUBLE, 
    `sval` DOUBLE, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RcvGALTimeOffset_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_RcvGALTimeOffset_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'RcvWAASTimeOffset': [WO] WAAS to Receiver Time Offset
CREATE TABLE `msg_RcvWAASTimeOffset` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `val` DOUBLE, 
    `sval` DOUBLE, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RcvWAASTimeOffset_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_RcvWAASTimeOffset_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'GpsUtcParam': [UO] GPS UTC Time Parameters
CREATE TABLE `msg_GpsUtcParam` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `utc` BIGINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_GpsUtcParam_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_GpsUtcParam_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'WaasUtcParam': [WU] WAAS UTC Time Parameters
CREATE TABLE `msg_WaasUtcParam` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `utc` BIGINT UNSIGNED, 
    `utcsi` TINYINT, 
    `tow` INT UNSIGNED, 
    `wn` SMALLINT UNSIGNED, 
    `flags` TINYINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_WaasUtcParam_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_WaasUtcParam_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'GalUtcGpsParam': [EU] GALILEO UTC and GPS Time Parameters
CREATE TABLE `msg_GalUtcGpsParam` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `utc` BIGINT UNSIGNED, 
    `a0g` FLOAT, 
    `a1g` FLOAT, 
    `t0g` INT UNSIGNED, 
    `wn0g` SMALLINT UNSIGNED, 
    `flags` SMALLINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_GalUtcGpsParam_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_GalUtcGpsParam_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'GloUtcGpsParam': [NU] GLONASS UTC and GPS Time Parameters
CREATE TABLE `msg_GloUtcGpsParam` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
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
    CONSTRAINT `fk_msg_GloUtcGpsParam_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'SolutionTime': [ST] Solution Time-Tag
CREATE TABLE `msg_SolutionTime` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `time` INT UNSIGNED, 
    `solType` TINYINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_SolutionTime_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_SolutionTime_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'Pos': [PO] Cartesian Position
CREATE TABLE `msg_Pos` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `x` DOUBLE, 
    `y` DOUBLE, 
    `z` DOUBLE, 
    `sigma` FLOAT, 
    `solType` TINYINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_Pos_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_Pos_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'Vel': [VE] Cartesian Velocity
CREATE TABLE `msg_Vel` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `x` FLOAT, 
    `y` FLOAT, 
    `z` FLOAT, 
    `sigma` FLOAT, 
    `solType` TINYINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_Vel_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_Vel_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'PosVel': [PV] Cartesian Position and Velocity
CREATE TABLE `msg_PosVel` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
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
    CONSTRAINT `fk_msg_PosVel_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'GeoPos': [PG] Geodetic Position
CREATE TABLE `msg_GeoPos` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `lat` DOUBLE, 
    `lon` DOUBLE, 
    `alt` DOUBLE, 
    `pSigma` FLOAT, 
    `solType` TINYINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_GeoPos_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_GeoPos_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'GeoVel': [VG] Geodetic Velocity
CREATE TABLE `msg_GeoVel` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `lat` FLOAT, 
    `lon` FLOAT, 
    `alt` FLOAT, 
    `pSigma` FLOAT, 
    `solType` TINYINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_GeoVel_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_GeoVel_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'Rms': [SG] Position and Velocity RMS Errors
CREATE TABLE `msg_Rms` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `hpos` FLOAT, 
    `vpos` FLOAT, 
    `hvel` FLOAT, 
    `vvel` FLOAT, 
    `solType` TINYINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_Rms_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_Rms_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'Dops': [DP] Dilution of Precision (DOP)
CREATE TABLE `msg_Dops` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `hdop` FLOAT, 
    `vdop` FLOAT, 
    `tdop` FLOAT, 
    `solType` TINYINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_Dops_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_Dops_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'PosCov': [SP] Position Covariance Matrix
CREATE TABLE `msg_PosCov` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
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
    CONSTRAINT `fk_msg_PosCov_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'VelCov': [SV] Velocity Covariance Matrix
CREATE TABLE `msg_VelCov` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
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
    CONSTRAINT `fk_msg_VelCov_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'BaseLine': [BL] Base Line
CREATE TABLE `msg_BaseLine` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `x` DOUBLE, 
    `y` DOUBLE, 
    `z` DOUBLE, 
    `sigma` FLOAT, 
    `solType` TINYINT UNSIGNED, 
    `time` INT, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_BaseLine_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_BaseLine_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'PosStat': [PS] Position Statistics
CREATE TABLE `msg_PosStat` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
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
    CONSTRAINT `fk_msg_PosStat_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'PosCompTime': [PT] Time of Continuous Position Computation
CREATE TABLE `msg_PosCompTime` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `pt` INT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_PosCompTime_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_PosCompTime_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'SatIndex': [SI] Satellite Indices
CREATE TABLE `msg_SatIndex` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `usi` VARCHAR(2000), 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_SatIndex_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_SatIndex_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'AntName': [AN] Antenna Names
CREATE TABLE `msg_AntName` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `name` VARCHAR(1000), 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_AntName_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_AntName_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'SatNumbers': [NN] GLONASS Satellite System Numbers
CREATE TABLE `msg_SatNumbers` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `osn` VARCHAR(2000), 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_SatNumbers_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_SatNumbers_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'SatElevation': [EL] Satellite Elevations
CREATE TABLE `msg_SatElevation` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `elev` VARCHAR(2000), 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_SatElevation_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_SatElevation_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'SatAzimuth': [AZ] Satellite Azimuths
CREATE TABLE `msg_SatAzimuth` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `azim` VARCHAR(2000), 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_SatAzimuth_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_SatAzimuth_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'PR': [RC], [R1], [R2], [R3], [R5]: Pseudoranges
CREATE TABLE `msg_PR` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `pr` VARCHAR(2000), 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_PR_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_PR_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'SPR': [rc], [r1], [r2], [r3], [r5]: Short Pseudoranges
CREATE TABLE `msg_SPR` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `spr` VARCHAR(2000), 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_SPR_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_SPR_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'RPR': [1R], [2R], [3R], [5R]: Relative Pseudoranges
CREATE TABLE `msg_RPR` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `rpr` VARCHAR(2000), 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RPR_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_RPR_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'SRPR': [1r], [2r], [3r], [5r]: Short Relative Pseudoranges
CREATE TABLE `msg_SRPR` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `srpr` VARCHAR(2000), 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_SRPR_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_SRPR_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'SC': [CC], [C1], [C2], [C3], [C5]: Smoothing Corrections
CREATE TABLE `msg_SC` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `smooth` BIGINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_SC_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_SC_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'SS': [cc], [c1], [c2], [c3], [c5]: Short Smoothing Corrections
CREATE TABLE `msg_SS` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `smooth` VARCHAR(2000), 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_SS_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_SS_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'CP': [PC], [P1], [P2], [P3], [P5]: Carrier Phases
CREATE TABLE `msg_CP` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `cp` VARCHAR(2000), 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_CP_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_CP_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'SCP': [pc], [p1], [p2], [p3], [p5]: Short Carrier Phases
CREATE TABLE `msg_SCP` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `scp` VARCHAR(2000), 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_SCP_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_SCP_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'RCP_RC': [CP], [1P], [2P], [3P], [5P]: Short Relative Carrier Phases
CREATE TABLE `msg_RCP_RC0` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `rcp` VARCHAR(2000), 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RCP_RC0_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_RCP_RC0_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'RCP_rc': [cp], [1p], [2p], [3p], [5p]: Short Relative Carrier Phases
CREATE TABLE `msg_RCP_rc1` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `rcp` VARCHAR(2000), 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RCP_rc1_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_RCP_rc1_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'DP': [DC], [D1], [D2], [D3], [D5]: Doppler
CREATE TABLE `msg_DP` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `dp` VARCHAR(2000), 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_DP_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_DP_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'SRDP': [1d], [2d], [3d], [5d]: Short Relative Doppler
CREATE TABLE `msg_SRDP` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `srdp` VARCHAR(2000), 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_SRDP_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_SRDP_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'CNR': [EC], [E1], [E2], [E3], [E5]: Carrier to Noise Ratio
CREATE TABLE `msg_CNR` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `cnr` VARCHAR(2000), 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_CNR_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_CNR_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'CNR_4': [CE], [1E], [2E], [3E], [5E]: Carrier to Noise Ratio x 
CREATE TABLE `msg_CNR_4` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `cnrX4` VARCHAR(2000), 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_CNR_4_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_CNR_4_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'Flags': [FC], [F1], [F2], [F3], [F5]: Signal Lock Loop Flags
CREATE TABLE `msg_Flags` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `flags` VARCHAR(2000), 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_Flags_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_Flags_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'TrackingTimeCA': [TC] CA/L1 Continuous Tracking Time
CREATE TABLE `msg_TrackingTimeCA` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `tt` VARCHAR(2000), 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_TrackingTimeCA_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_TrackingTimeCA_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'NavStatus': [SS] Satellite Navigation Status
CREATE TABLE `msg_NavStatus` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `ns` VARCHAR(2000), 
    `solType` TINYINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_NavStatus_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_NavStatus_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'IonoDelay': [ID] Ionospheric Delays
CREATE TABLE `msg_IonoDelay` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `delay` VARCHAR(2000), 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_IonoDelay_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_IonoDelay_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'GPSAlm': [GA] GPS Almanac
CREATE TABLE `msg_GPSAlm` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
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
    INDEX `idx_fk_msg_GPSAlm_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_GPSAlm_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'GALAlm': [EA] GALILEO Almanac
CREATE TABLE `msg_GALAlm` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `gps` BIGINT UNSIGNED, 
    `iod` SMALLINT, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_GALAlm_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_GALAlm_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'GLOAlmanac': [NA] GLONASS Almanac
CREATE TABLE `msg_GLOAlmanac` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
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
    CONSTRAINT `fk_msg_GLOAlmanac_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'WAASAlmanac': [WA] WAAS Almanac
CREATE TABLE `msg_WAASAlmanac` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
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
    CONSTRAINT `fk_msg_WAASAlmanac_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'GPSEphemeris': [GE] GPS Ephemeris
CREATE TABLE `msg_GPSEphemeris` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
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
    INDEX `idx_fk_msg_GPSEphemeris_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_GPSEphemeris_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'GLOEphemeris': [NE] GLONASS Ephemeris
CREATE TABLE `msg_GLOEphemeris` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `sv` TINYINT UNSIGNED, 
    `frqNum` TINYINT, 
    `dne` SMALLINT, 
    `tk` INT, 
    `tb` INT, 
    `health` TINYINT UNSIGNED, 
    `age` TINYINT UNSIGNED, 
    `flags` TINYINT UNSIGNED, 
    `r` VARCHAR(2000), 
    `v` VARCHAR(2000), 
    `w` VARCHAR(2000), 
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
    CONSTRAINT `fk_msg_GLOEphemeris_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'WAASEhemeris': [WE] WAAS Ephemeris
CREATE TABLE `msg_WAASEhemeris` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
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
    CONSTRAINT `fk_msg_WAASEhemeris_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'GALEphemeris': [EN] GALILEO Ephemeris
CREATE TABLE `msg_GALEphemeris` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
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
    CONSTRAINT `fk_msg_GALEphemeris_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'GpsNavData': [GD] GPS Raw Navigation Data
CREATE TABLE `msg_GpsNavData` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `recSize` TINYINT UNSIGNED, 
    `dat` BIGINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_GpsNavData_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_GpsNavData_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'GloNavData': [LD] GLONASS Raw Navigation Data
CREATE TABLE `msg_GloNavData` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `recSize` TINYINT UNSIGNED, 
    `dat` BIGINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_GloNavData_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_GloNavData_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'WAASRawMessage': [WD] WAAS Raw Navigation Data
CREATE TABLE `msg_WAASRawMessage` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `prn` TINYINT UNSIGNED, 
    `time` INT UNSIGNED, 
    `reserv` SMALLINT UNSIGNED, 
    `data` VARCHAR(2000), 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_WAASRawMessage_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_WAASRawMessage_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'GALRawMessage': [ED] GALILEO Raw Navigation Data
CREATE TABLE `msg_GALRawMessage` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `prn` TINYINT UNSIGNED, 
    `time` INT UNSIGNED, 
    `type` TINYINT UNSIGNED, 
    `len` TINYINT UNSIGNED, 
    `data` VARCHAR(2000), 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_GALRawMessage_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_GALRawMessage_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'GloPhaseDelay': [gC], [g1], [g2], [g3]: GLONASS Phase Delays
CREATE TABLE `msg_GloPhaseDelay` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `fcn` VARCHAR(2000), 
    `phase` VARCHAR(2000), 
    `range` VARCHAR(2000), 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_GloPhaseDelay_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_GloPhaseDelay_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'RotationMatrix': [MR] Rotation Matrix
CREATE TABLE `msg_RotationMatrix` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `time` INT UNSIGNED, 
    `q00` FLOAT, 
    `q01` FLOAT, 
    `q02` FLOAT, 
    `q12` FLOAT, 
    `rms` VARCHAR(2000), 
    `solType` VARCHAR(2000), 
    `flag` TINYINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RotationMatrix_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_RotationMatrix_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'RotationMatrixAndVectors': [mr] Rotation Matrix and Vectors
CREATE TABLE `msg_RotationMatrixAndVectors` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `time` INT UNSIGNED, 
    `q00` FLOAT, 
    `q01` FLOAT, 
    `q02` FLOAT, 
    `q12` FLOAT, 
    `rms` VARCHAR(2000), 
    `solType` VARCHAR(2000), 
    `flag` TINYINT UNSIGNED, 
    `bl0` VARCHAR(2000), 
    `bl1` VARCHAR(2000), 
    `bl2` VARCHAR(2000), 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RotationMatrixAndVectors_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_RotationMatrixAndVectors_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'RotationAngles': [AR] Rotation Angles
CREATE TABLE `msg_RotationAngles` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
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
    CONSTRAINT `fk_msg_RotationAngles_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'AngularVelocity': [AV] Angular Velocities
CREATE TABLE `msg_AngularVelocity` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `time` INT UNSIGNED, 
    `x` FLOAT, 
    `y` FLOAT, 
    `z` FLOAT, 
    `rms` FLOAT, 
    `flags` TINYINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_AngularVelocity_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_AngularVelocity_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'InertialMeasurements': [IM] Inertial Measurements
CREATE TABLE `msg_InertialMeasurements` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `accelerations` VARCHAR(2000), 
    `angularVelocities` VARCHAR(2000), 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_InertialMeasurements_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_InertialMeasurements_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'ExtEvent': [XA], [XB] External Event
CREATE TABLE `msg_ExtEvent` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `ms` INT, 
    `ns` INT, 
    `timeScale` TINYINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_ExtEvent_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_ExtEvent_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'PPSOffset': [ZA], [ZB] PPS Offset
CREATE TABLE `msg_PPSOffset` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `offs` FLOAT, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_PPSOffset_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_PPSOffset_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'RcvTimeOffsAtPPS': [YA], [YB] Time Offset at PPS Generation Time
CREATE TABLE `msg_RcvTimeOffsAtPPS` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `offs` DOUBLE, 
    `timeScale` TINYINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RcvTimeOffsAtPPS_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_RcvTimeOffsAtPPS_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'RefEpoch': [rE] Reference Epoch
CREATE TABLE `msg_RefEpoch` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `sample` SMALLINT UNSIGNED, 
    `scale` SMALLINT UNSIGNED, 
    `reftime` INT UNSIGNED, 
    `crc16` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RefEpoch_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_RefEpoch_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'RawMeas': [rM] Raw Measurements
CREATE TABLE `msg_RawMeas` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `sample` SMALLINT UNSIGNED, 
    `scale` SMALLINT UNSIGNED, 
    `reftime` INT UNSIGNED, 
    `clock` SMALLINT, 
    `flags` SMALLINT UNSIGNED, 
    `svd` BIGINT UNSIGNED, 
    `crc16` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RawMeas_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_RawMeas_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'PosVelVector': [rV] Receiver’s Position and Velocity
CREATE TABLE `msg_PosVelVector` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
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
    CONSTRAINT `fk_msg_PosVelVector_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'ClockOffsets': [rT] Receiver Clock Offsets
CREATE TABLE `msg_ClockOffsets` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `sample` SMALLINT UNSIGNED, 
    `reserved` SMALLINT UNSIGNED, 
    `recSize` TINYINT UNSIGNED, 
    `Offs` BIGINT UNSIGNED, 
    `crc16` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_ClockOffsets_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_ClockOffsets_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'RE': [RE] Reply
CREATE TABLE `msg_RE` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `reply` VARCHAR(1000), 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RE_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_RE_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'ER': [ER] Error
CREATE TABLE `msg_ER` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `error` VARCHAR(1000), 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_ER_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_ER_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'IonoParams': [IO] Ionospheric Parameters
CREATE TABLE `msg_IonoParams` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
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
    CONSTRAINT `fk_msg_IonoParams_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'Event': [==](EV) Event
CREATE TABLE `msg_Event` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `time` INT UNSIGNED, 
    `type` TINYINT UNSIGNED, 
    `data` VARCHAR(2000), 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_Event_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_Event_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'Latency': [LT] Message Output Latency
CREATE TABLE `msg_Latency` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `lt` TINYINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_Latency_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_Latency_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'Wrapper': [>>] Wrapper
CREATE TABLE `msg_Wrapper` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `id_sugar` TINYINT UNSIGNED, 
    `data` VARCHAR(2000), 
    `cs` VARCHAR(1000), 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_Wrapper_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_Wrapper_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'Params': [PM] Parameters
CREATE TABLE `msg_Params` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `params` VARCHAR(1000), 
    `delim` VARCHAR(1000), 
    `cs` VARCHAR(1000), 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_Params_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_Params_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'LoggingHistory': [LH] Logging History
CREATE TABLE `msg_LoggingHistory` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `svsCount` TINYINT UNSIGNED, 
    `targetStream` TINYINT UNSIGNED, 
    `issue` SMALLINT UNSIGNED, 
    `bitsCount` SMALLINT UNSIGNED, 
    `lastBitTime` INT UNSIGNED, 
    `uids` VARCHAR(2000), 
    `pad` VARCHAR(2000), 
    `hist` VARCHAR(2000), 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_LoggingHistory_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_LoggingHistory_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'BaseInfo': [BI] Base Station Information
CREATE TABLE `msg_BaseInfo` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `x` DOUBLE, 
    `y` DOUBLE, 
    `z` DOUBLE, 
    `id_sugar` SMALLINT UNSIGNED, 
    `solType` TINYINT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_BaseInfo_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_BaseInfo_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'Security': [SE] Security
CREATE TABLE `msg_Security0` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `data` VARCHAR(2000), 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_Security0_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_Security0_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'Security': [SM] Security for [rM]
CREATE TABLE `msg_Security1` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `data` VARCHAR(2000), 
    `crc16` SMALLINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_Security1_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_Security1_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'TrackingTime': [TT] CA/L1 Overall Continuous Tracking Time
CREATE TABLE `msg_TrackingTime` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `tt` INT UNSIGNED, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_TrackingTime_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_TrackingTime_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'RcvOscOffs': [OO] Oscillator Offset
CREATE TABLE `msg_RcvOscOffs` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `val` FLOAT, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_RcvOscOffs_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_RcvOscOffs_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));

-- message 'EpochEnd': [||](EE) Epoch End
CREATE TABLE `msg_EpochEnd` (
    id SERIAL, 
    idEpoch BIGINT UNSIGNED NOT NULL, 
    `cs` TINYINT UNSIGNED, 
    PRIMARY KEY (`id`), 
    INDEX `idx_fk_msg_EpochEnd_idEpoch` (`idEpoch`), 
    CONSTRAINT `fk_msg_EpochEnd_idEpoch` FOREIGN KEY (`idEpoch`) 
        REFERENCES `epochs` (`id`));



-- Наполнение классификатора sizeSpecialValuesClassifier
INSERT INTO `sizeSpecialValuesClassifier` (`id`, `name`) 
    VALUES (-3, 'Fixed'), 
           (-2, 'Fill'), 
           (-1, 'Dynamic');

-- Наполнение классификатора messageValidationsClassifier
INSERT INTO `messageValidationsClassifier` (`name`) 
    VALUES ('Checksum'), 
           ('ChecksumAsHexAscii'), 
           ('Crc16');

-- Наполнение классификатора messageKindsClassifier
INSERT INTO `messageKindsClassifier` (`name`) 
    VALUES ('NonStandardTextMessage'), 
           ('StandardTextMessage'), 
           ('GreisStandardMessage'), 
           ('ForeignStandardMessage'), 
           ('UnknownStandardMessage');

-- Наполнение классификатора messageTypesClassifier
INSERT INTO `messageTypesClassifier` (`name`) 
    VALUES ('Unknown'), 
           ('AlmanacsAndEphemeris');

-- Наполнение мета-информации о пользовательских типах
INSERT INTO `customTypesMeta` (`id`, `name`, `size`, `tableName`) 
    VALUES (1, 'UtcOffs', 23, 'ct_UtcOffs'), 
           (2, 'Smooth', 6, 'ct_Smooth'), 
           (3, 'SvData0', -3, 'ct_SvData0'), 
           (4, 'SvData1', -3, 'ct_SvData1'), 
           (5, 'SvData2', -1, 'ct_SvData2'), 
           (6, 'Header', 6, 'ct_Header'), 
           (7, 'SlotRec', -1, 'ct_SlotRec'), 
           (8, 'ClkOffs', -3, 'ct_ClkOffs');

-- Наполнение мета-информации о сообщениях
INSERT INTO `messagesMeta` (`id`, `name`, `title`, `size`, `idValidation`, `idKind`, `idType`, `tableName`) 
    VALUES (1, 'FileId', '[JP] File Identifier', 85, 1, 3, 1, 'msg_FileId'), 
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
           (55, 'GPSAlm', '[GA] GPS Almanac', 47, 1, 3, 2, 'msg_GPSAlm'), 
           (56, 'GALAlm', '[EA] GALILEO Almanac', 49, 1, 3, 2, 'msg_GALAlm'), 
           (57, 'GLOAlmanac', '[NA] GLONASS Almanac', 46, 1, 3, 2, 'msg_GLOAlmanac'), 
           (58, 'WAASAlmanac', '[WA] WAAS Almanac', 51, 1, 3, 2, 'msg_WAASAlmanac'), 
           (59, 'GPSEphemeris', '[GE] GPS Ephemeris', 123, 1, 3, 2, 'msg_GPSEphemeris'), 
           (60, 'GLOEphemeris', '[NE] GLONASS Ephemeris', 88, 1, 3, 2, 'msg_GLOEphemeris'), 
           (61, 'WAASEhemeris', '[WE] WAAS Ephemeris', 39, 1, 3, 2, 'msg_WAASEhemeris'), 
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
           (80, 'RE', '[RE] Reply', -2, 1, 3, 1, 'msg_RE'), 
           (81, 'ER', '[ER] Error', -2, 1, 3, 1, 'msg_ER'), 
           (82, 'IonoParams', '[IO] Ionospheric Parameters', 39, 1, 3, 1, 'msg_IonoParams'), 
           (83, 'Event', '[==](EV) Event', -2, 1, 3, 1, 'msg_Event'), 
           (84, 'Latency', '[LT] Message Output Latency', 2, 1, 3, 1, 'msg_Latency'), 
           (85, 'Wrapper', '[>>] Wrapper', -2, 2, 3, 1, 'msg_Wrapper'), 
           (86, 'Params', '[PM] Parameters', -2, 2, 3, 1, 'msg_Params'), 
           (87, 'LoggingHistory', '[LH] Logging History', -1, 1, 3, 1, 'msg_LoggingHistory'), 
           (88, 'BaseInfo', '[BI] Base Station Information', 28, 1, 3, 1, 'msg_BaseInfo'), 
           (89, 'Security', '[SE] Security', 6, 1, 3, 1, 'msg_Security0'), 
           (90, 'Security', '[SM] Security for [rM]', 8, 3, 3, 1, 'msg_Security1'), 
           (91, 'TrackingTime', '[TT] CA/L1 Overall Continuous Tracking Time', 5, 1, 3, 1, 'msg_TrackingTime'), 
           (92, 'RcvOscOffs', '[OO] Oscillator Offset', 5, 1, 3, 1, 'msg_RcvOscOffs'), 
           (93, 'EpochEnd', '[||](EE) Epoch End', 1, 1, 3, 1, 'msg_EpochEnd');

INSERT INTO `messageCodes` (`code`, `idMessagesMeta`) 
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

INSERT INTO `messageVariablesMeta` (`name`, `type`, `dimensions`, `requiredValue`, `idMessagesMeta`) 
    VALUES ('id', 'a1', 1, '', 1), 
           ('description', 'a1', 1, '', 1), 
           ('id', 'a1', 1, 'JP', 2), 
           ('majorVer', 'a1', 1, '', 2), 
           ('minorVer', 'a1', 1, '', 2), 
           ('order', 'a1', 1, '', 2), 
           ('cs', 'a1', 1, '', 2), 
           ('tod', 'u4', 1, '', 3), 
           ('cs', 'u1', 1, '', 3), 
           ('tod', 'u4', 1, '', 4), 
           ('cs', 'u1', 1, '', 4), 
           ('year', 'u2', 1, '', 5), 
           ('month', 'u1', 1, '', 5), 
           ('day', 'u1', 1, '', 5), 
           ('base', 'u1', 1, '', 5), 
           ('cs', 'u1', 1, '', 5), 
           ('val', 'f8', 1, '', 6), 
           ('sval', 'f8', 1, '', 6), 
           ('cs', 'u1', 1, '', 6), 
           ('val', 'f4', 1, '', 7), 
           ('sval', 'f4', 1, '', 7), 
           ('cs', 'u1', 1, '', 7), 
           ('acc', 'f4', 1, '', 8), 
           ('cs', 'u1', 1, '', 8), 
           ('tow', 'u4', 1, '', 9), 
           ('wn', 'u2', 1, '', 9), 
           ('cs', 'u1', 1, '', 9), 
           ('val', 'f8', 1, '', 10), 
           ('sval', 'f8', 1, '', 10), 
           ('cs', 'u1', 1, '', 10), 
           ('tod', 'u4', 1, '', 11), 
           ('dn', 'u2', 1, '', 11), 
           ('cs', 'u1', 1, '', 11), 
           ('val', 'f8', 1, '', 12), 
           ('sval', 'f8', 1, '', 12), 
           ('cs', 'u1', 1, '', 12), 
           ('val', 'f8', 1, '', 13), 
           ('sval', 'f8', 1, '', 13), 
           ('cs', 'u1', 1, '', 13), 
           ('val', 'f8', 1, '', 14), 
           ('sval', 'f8', 1, '', 14), 
           ('cs', 'u1', 1, '', 14), 
           ('utc', 'UtcOffs', 1, '', 15), 
           ('cs', 'u1', 1, '', 15), 
           ('utc', 'UtcOffs', 1, '', 16), 
           ('utcsi', 'i1', 1, '', 16), 
           ('tow', 'u4', 1, '', 16), 
           ('wn', 'u2', 1, '', 16), 
           ('flags', 'u1', 1, '', 16), 
           ('cs', 'u1', 1, '', 16), 
           ('utc', 'UtcOffs', 1, '', 17), 
           ('a0g', 'f4', 1, '', 17), 
           ('a1g', 'f4', 1, '', 17), 
           ('t0g', 'u4', 1, '', 17), 
           ('wn0g', 'u2', 1, '', 17), 
           ('flags', 'u2', 1, '', 17), 
           ('cs', 'u1', 1, '', 17), 
           ('tauSys', 'f8', 1, '', 18), 
           ('tauGps', 'f4', 1, '', 18), 
           ('B1', 'f4', 1, '', 18), 
           ('B2', 'f4', 1, '', 18), 
           ('KP', 'u1', 1, '', 18), 
           ('N4', 'u1', 1, '', 18), 
           ('Dn', 'i2', 1, '', 18), 
           ('cs', 'u1', 1, '', 18), 
           ('time', 'u4', 1, '', 19), 
           ('solType', 'u1', 1, '', 19), 
           ('cs', 'u1', 1, '', 19), 
           ('x', 'f8', 1, '', 20), 
           ('y', 'f8', 1, '', 20), 
           ('z', 'f8', 1, '', 20), 
           ('sigma', 'f4', 1, '', 20), 
           ('solType', 'u1', 1, '', 20), 
           ('cs', 'u1', 1, '', 20), 
           ('x', 'f4', 1, '', 21), 
           ('y', 'f4', 1, '', 21), 
           ('z', 'f4', 1, '', 21), 
           ('sigma', 'f4', 1, '', 21), 
           ('solType', 'u1', 1, '', 21), 
           ('cs', 'u1', 1, '', 21), 
           ('x', 'f8', 1, '', 22), 
           ('y', 'f8', 1, '', 22), 
           ('z', 'f8', 1, '', 22), 
           ('pSigma', 'f4', 1, '', 22), 
           ('vx', 'f4', 1, '', 22), 
           ('vy', 'f4', 1, '', 22), 
           ('vz', 'f4', 1, '', 22), 
           ('vSigma', 'f4', 1, '', 22), 
           ('solType', 'u1', 1, '', 22), 
           ('cs', 'u1', 1, '', 22), 
           ('lat', 'f8', 1, '', 23), 
           ('lon', 'f8', 1, '', 23), 
           ('alt', 'f8', 1, '', 23), 
           ('pSigma', 'f4', 1, '', 23), 
           ('solType', 'u1', 1, '', 23), 
           ('cs', 'u1', 1, '', 23), 
           ('lat', 'f4', 1, '', 24), 
           ('lon', 'f4', 1, '', 24), 
           ('alt', 'f4', 1, '', 24), 
           ('pSigma', 'f4', 1, '', 24), 
           ('solType', 'u1', 1, '', 24), 
           ('cs', 'u1', 1, '', 24), 
           ('hpos', 'f4', 1, '', 25), 
           ('vpos', 'f4', 1, '', 25), 
           ('hvel', 'f4', 1, '', 25), 
           ('vvel', 'f4', 1, '', 25), 
           ('solType', 'u1', 1, '', 25), 
           ('cs', 'u1', 1, '', 25), 
           ('hdop', 'f4', 1, '', 26), 
           ('vdop', 'f4', 1, '', 26), 
           ('tdop', 'f4', 1, '', 26), 
           ('solType', 'u1', 1, '', 26), 
           ('cs', 'u1', 1, '', 26), 
           ('xx', 'f4', 1, '', 27), 
           ('yy', 'f4', 1, '', 27), 
           ('zz', 'f4', 1, '', 27), 
           ('tt', 'f4', 1, '', 27), 
           ('xy', 'f4', 1, '', 27), 
           ('xz', 'f4', 1, '', 27), 
           ('xt', 'f4', 1, '', 27), 
           ('yz', 'f4', 1, '', 27), 
           ('yt', 'f4', 1, '', 27), 
           ('zt', 'f4', 1, '', 27), 
           ('solType', 'u1', 1, '', 27), 
           ('cs', 'u1', 1, '', 27), 
           ('xx', 'f4', 1, '', 28), 
           ('yy', 'f4', 1, '', 28), 
           ('zz', 'f4', 1, '', 28), 
           ('tt', 'f4', 1, '', 28), 
           ('xy', 'f4', 1, '', 28), 
           ('xz', 'f4', 1, '', 28), 
           ('xt', 'f4', 1, '', 28), 
           ('yz', 'f4', 1, '', 28), 
           ('yt', 'f4', 1, '', 28), 
           ('zt', 'f4', 1, '', 28), 
           ('solType', 'u1', 1, '', 28), 
           ('cs', 'u1', 1, '', 28), 
           ('x', 'f8', 1, '', 29), 
           ('y', 'f8', 1, '', 29), 
           ('z', 'f8', 1, '', 29), 
           ('sigma', 'f4', 1, '', 29), 
           ('solType', 'u1', 1, '', 29), 
           ('time', 'i4', 1, '', 29), 
           ('cs', 'u1', 1, '', 29), 
           ('solType', 'u1', 1, '', 30), 
           ('gpsLocked', 'u1', 1, '', 30), 
           ('gloLocked', 'u1', 1, '', 30), 
           ('gpsAvail', 'u1', 1, '', 30), 
           ('gloAvail', 'u1', 1, '', 30), 
           ('gpsUsed', 'u1', 1, '', 30), 
           ('gloUsed', 'u1', 1, '', 30), 
           ('fixProg', 'u1', 1, '', 30), 
           ('cs', 'u1', 1, '', 30), 
           ('pt', 'u4', 1, '', 31), 
           ('cs', 'u1', 1, '', 31), 
           ('usi', 'u1', 1, '', 32), 
           ('cs', 'u1', 1, '', 32), 
           ('name', 'a1', 1, '', 33), 
           ('cs', 'u1', 1, '', 33), 
           ('osn', 'u1', 1, '', 34), 
           ('cs', 'u1', 1, '', 34), 
           ('elev', 'i1', 1, '', 35), 
           ('cs', 'u1', 1, '', 35), 
           ('azim', 'u1', 1, '', 36), 
           ('cs', 'u1', 1, '', 36), 
           ('pr', 'f8', 1, '', 37), 
           ('cs', 'u1', 1, '', 37), 
           ('spr', 'i4', 1, '', 38), 
           ('cs', 'u1', 1, '', 38), 
           ('rpr', 'f4', 1, '', 39), 
           ('cs', 'u1', 1, '', 39), 
           ('srpr', 'i2', 1, '', 40), 
           ('cs', 'u1', 1, '', 40), 
           ('smooth', 'Smooth', 1, '', 41), 
           ('cs', 'u1', 1, '', 41), 
           ('smooth', 'i2', 1, '', 42), 
           ('cs', 'u1', 1, '', 42), 
           ('cp', 'f8', 1, '', 43), 
           ('cs', 'u1', 1, '', 43), 
           ('scp', 'u4', 1, '', 44), 
           ('cs', 'u1', 1, '', 44), 
           ('rcp', 'f4', 1, '', 45), 
           ('cs', 'u1', 1, '', 45), 
           ('rcp', 'i4', 1, '', 46), 
           ('cs', 'u1', 1, '', 46), 
           ('dp', 'i4', 1, '', 47), 
           ('cs', 'u1', 1, '', 47), 
           ('srdp', 'i2', 1, '', 48), 
           ('cs', 'u1', 1, '', 48), 
           ('cnr', 'u1', 1, '', 49), 
           ('cs', 'u1', 1, '', 49), 
           ('cnrX4', 'u1', 1, '', 50), 
           ('cs', 'u1', 1, '', 50), 
           ('flags', 'u2', 1, '', 51), 
           ('cs', 'u1', 1, '', 51), 
           ('tt', 'u2', 1, '', 52), 
           ('cs', 'u1', 1, '', 52), 
           ('ns', 'u1', 1, '', 53), 
           ('solType', 'u1', 1, '', 53), 
           ('cs', 'u1', 1, '', 53), 
           ('delay', 'f4', 1, '', 54), 
           ('cs', 'u1', 1, '', 54), 
           ('sv', 'u1', 1, '', 55), 
           ('wna', 'i2', 1, '', 55), 
           ('toa', 'i4', 1, '', 55), 
           ('healthA', 'u1', 1, '', 55), 
           ('healthS', 'u1', 1, '', 55), 
           ('config', 'u1', 1, '', 55), 
           ('af1', 'f4', 1, '', 55), 
           ('af0', 'f4', 1, '', 55), 
           ('rootA', 'f4', 1, '', 55), 
           ('ecc', 'f4', 1, '', 55), 
           ('m0', 'f4', 1, '', 55), 
           ('omega0', 'f4', 1, '', 55), 
           ('argPer', 'f4', 1, '', 55), 
           ('deli', 'f4', 1, '', 55), 
           ('omegaDot', 'f4', 1, '', 55), 
           ('cs', 'u1', 1, '', 55), 
           ('gps', 'GPSAlm', 1, '', 56), 
           ('iod', 'i2', 1, '', 56), 
           ('cs', 'u1', 1, '', 56), 
           ('sv', 'u1', 1, '', 57), 
           ('frqNum', 'i1', 1, '', 57), 
           ('dna', 'i2', 1, '', 57), 
           ('tlam', 'f4', 1, '', 57), 
           ('flags', 'u1', 1, '', 57), 
           ('tauN', 'f4', 1, '', 57), 
           ('tauSys', 'f8', 1, '', 57), 
           ('ecc', 'f4', 1, '', 57), 
           ('lambda', 'f4', 1, '', 57), 
           ('argPer', 'f4', 1, '', 57), 
           ('delT', 'f4', 1, '', 57), 
           ('delTdt', 'f4', 1, '', 57), 
           ('deli', 'f4', 1, '', 57), 
           ('cs', 'u1', 1, '', 57), 
           ('waasPrn', 'u1', 1, '', 58), 
           ('gpsPrn', 'u1', 1, '', 58), 
           ('id', 'u1', 1, '', 58), 
           ('healthS', 'u1', 1, '', 58), 
           ('tod', 'u4', 1, '', 58), 
           ('xg', 'f8', 1, '', 58), 
           ('yg', 'f8', 1, '', 58), 
           ('zg', 'f8', 1, '', 58), 
           ('vxg', 'f4', 1, '', 58), 
           ('vyg', 'f4', 1, '', 58), 
           ('vzg', 'f4', 1, '', 58), 
           ('tow', 'u4', 1, '', 58), 
           ('wn', 'u2', 1, '', 58), 
           ('cs', 'u1', 1, '', 58), 
           ('sv', 'u1', 1, '', 59), 
           ('tow', 'u4', 1, '', 59), 
           ('flags', 'u1', 1, '', 59), 
           ('iodc', 'i2', 1, '', 59), 
           ('toc', 'i4', 1, '', 59), 
           ('ura', 'i1', 1, '', 59), 
           ('healthS', 'u1', 1, '', 59), 
           ('wn', 'i2', 1, '', 59), 
           ('tgd', 'f4', 1, '', 59), 
           ('af2', 'f4', 1, '', 59), 
           ('af1', 'f4', 1, '', 59), 
           ('af0', 'f4', 1, '', 59), 
           ('toe', 'i4', 1, '', 59), 
           ('iode', 'i2', 1, '', 59), 
           ('rootA', 'f8', 1, '', 59), 
           ('ecc', 'f8', 1, '', 59), 
           ('m0', 'f8', 1, '', 59), 
           ('omega0', 'f8', 1, '', 59), 
           ('inc0', 'f8', 1, '', 59), 
           ('argPer', 'f8', 1, '', 59), 
           ('deln', 'f4', 1, '', 59), 
           ('omegaDot', 'f4', 1, '', 59), 
           ('incDot', 'f4', 1, '', 59), 
           ('crc', 'f4', 1, '', 59), 
           ('crs', 'f4', 1, '', 59), 
           ('cuc', 'f4', 1, '', 59), 
           ('cus', 'f4', 1, '', 59), 
           ('cic', 'f4', 1, '', 59), 
           ('cis', 'f4', 1, '', 59), 
           ('cs', 'u1', 1, '', 59), 
           ('sv', 'u1', 1, '', 60), 
           ('frqNum', 'i1', 1, '', 60), 
           ('dne', 'i2', 1, '', 60), 
           ('tk', 'i4', 1, '', 60), 
           ('tb', 'i4', 1, '', 60), 
           ('health', 'u1', 1, '', 60), 
           ('age', 'u1', 1, '', 60), 
           ('flags', 'u1', 1, '', 60), 
           ('r', 'f8', 1, '', 60), 
           ('v', 'f4', 1, '', 60), 
           ('w', 'f4', 1, '', 60), 
           ('tauSys', 'f8', 1, '', 60), 
           ('tau', 'f4', 1, '', 60), 
           ('gamma', 'f4', 1, '', 60), 
           ('fDelTauN', 'f4', 1, '', 60), 
           ('nFt', 'u1', 1, '', 60), 
           ('nN4', 'u1', 1, '', 60), 
           ('flags2', 'u2', 1, '', 60), 
           ('cs', 'u1', 1, '', 60), 
           ('waasPrn', 'u1', 1, '', 61), 
           ('gpsPrn', 'u1', 1, '', 61), 
           ('iod', 'u1', 1, '', 61), 
           ('acc', 'u1', 1, '', 61), 
           ('tod', 'u4', 1, '', 61), 
           ('xg', 'f8', 1, '', 61), 
           ('yg', 'f8', 1, '', 61), 
           ('zg', 'f8', 1, '', 61), 
           ('vxg', 'f4', 1, '', 61), 
           ('vyg', 'f4', 1, '', 61), 
           ('vzg', 'f4', 1, '', 61), 
           ('vvxg', 'f4', 1, '', 61), 
           ('vvyg', 'f4', 1, '', 61), 
           ('vvzg', 'f4', 1, '', 61), 
           ('agf0', 'f4', 1, '', 61), 
           ('agf1', 'f4', 1, '', 61), 
           ('tow', 'u4', 1, '', 61), 
           ('wn', 'u2', 1, '', 61), 
           ('cs', 'u1', 1, '', 61), 
           ('gps', 'GPSEphemeris', 1, '', 62), 
           ('bgdE1E5a', 'f4', 1, '', 62), 
           ('bgdE1E5b', 'f4', 1, '', 62), 
           ('ai0', 'f4', 1, '', 62), 
           ('ai1', 'f4', 1, '', 62), 
           ('ai2', 'f4', 1, '', 62), 
           ('sfi', 'u1', 1, '', 62), 
           ('navType', 'u1', 1, '', 62), 
           ('cs', 'u1', 1, '', 62), 
           ('recSize', 'u1', 1, '', 63), 
           ('dat', 'SvData0', 1, '', 63), 
           ('cs', 'u1', 1, '', 63), 
           ('recSize', 'u1', 1, '', 64), 
           ('dat', 'SvData1', 1, '', 64), 
           ('cs', 'u1', 1, '', 64), 
           ('prn', 'u1', 1, '', 65), 
           ('time', 'u4', 1, '', 65), 
           ('reserv', 'u2', 1, '', 65), 
           ('data', 'u1', 1, '', 65), 
           ('cs', 'u1', 1, '', 65), 
           ('prn', 'u1', 1, '', 66), 
           ('time', 'u4', 1, '', 66), 
           ('type', 'u1', 1, '', 66), 
           ('len', 'u1', 1, '', 66), 
           ('data', 'u1', 1, '', 66), 
           ('cs', 'u1', 1, '', 66), 
           ('fcn', 'i1', 1, '', 67), 
           ('phase', 'f4', 1, '', 67), 
           ('range', 'f4', 1, '', 67), 
           ('cs', 'u1', 1, '', 67), 
           ('time', 'u4', 1, '', 68), 
           ('q00', 'f4', 1, '', 68), 
           ('q01', 'f4', 1, '', 68), 
           ('q02', 'f4', 1, '', 68), 
           ('q12', 'f4', 1, '', 68), 
           ('rms', 'f4', 1, '', 68), 
           ('solType', 'u1', 1, '', 68), 
           ('flag', 'u1', 1, '', 68), 
           ('cs', 'u1', 1, '', 68), 
           ('time', 'u4', 1, '', 69), 
           ('q00', 'f4', 1, '', 69), 
           ('q01', 'f4', 1, '', 69), 
           ('q02', 'f4', 1, '', 69), 
           ('q12', 'f4', 1, '', 69), 
           ('rms', 'f4', 1, '', 69), 
           ('solType', 'u1', 1, '', 69), 
           ('flag', 'u1', 1, '', 69), 
           ('bl0', 'f4', 1, '', 69), 
           ('bl1', 'f4', 1, '', 69), 
           ('bl2', 'f4', 1, '', 69), 
           ('cs', 'u1', 1, '', 69), 
           ('time', 'u4', 1, '', 70), 
           ('pitch', 'f4', 1, '', 70), 
           ('roll', 'f4', 1, '', 70), 
           ('heading', 'f4', 1, '', 70), 
           ('pitchRms', 'f4', 1, '', 70), 
           ('rollRms', 'f4', 1, '', 70), 
           ('headingRms', 'f4', 1, '', 70), 
           ('flags', 'u1', 1, '', 70), 
           ('cs', 'u1', 1, '', 70), 
           ('time', 'u4', 1, '', 71), 
           ('x', 'f4', 1, '', 71), 
           ('y', 'f4', 1, '', 71), 
           ('z', 'f4', 1, '', 71), 
           ('rms', 'f4', 1, '', 71), 
           ('flags', 'u1', 1, '', 71), 
           ('cs', 'u1', 1, '', 71), 
           ('accelerations', 'f4', 1, '', 72), 
           ('angularVelocities', 'f4', 1, '', 72), 
           ('cs', 'u1', 1, '', 72), 
           ('ms', 'i4', 1, '', 73), 
           ('ns', 'i4', 1, '', 73), 
           ('timeScale', 'u1', 1, '', 73), 
           ('cs', 'u1', 1, '', 73), 
           ('offs', 'f4', 1, '', 74), 
           ('cs', 'u1', 1, '', 74), 
           ('offs', 'f8', 1, '', 75), 
           ('timeScale', 'u1', 1, '', 75), 
           ('cs', 'u1', 1, '', 75), 
           ('sample', 'u2', 1, '', 76), 
           ('scale', 'u2', 1, '', 76), 
           ('reftime', 'u4', 1, '', 76), 
           ('crc16', 'u2', 1, '', 76), 
           ('sample', 'u2', 1, '', 77), 
           ('scale', 'u2', 1, '', 77), 
           ('reftime', 'u4', 1, '', 77), 
           ('clock', 'i2', 1, '', 77), 
           ('flags', 'u2', 1, '', 77), 
           ('svd', 'SvData2', 1, '', 77), 
           ('crc16', 'u2', 1, '', 77), 
           ('sample', 'u2', 1, '', 78), 
           ('delta', 'u2', 1, '', 78), 
           ('word1', 'u4', 1, '', 78), 
           ('word2', 'u4', 1, '', 78), 
           ('word3', 'u4', 1, '', 78), 
           ('word4', 'u4', 1, '', 78), 
           ('word5', 'u4', 1, '', 78), 
           ('word6', 'u4', 1, '', 78), 
           ('word7', 'u4', 1, '', 78), 
           ('word8', 'u4', 1, '', 78), 
           ('word9', 'u4', 1, '', 78), 
           ('crc16', 'u2', 1, '', 78), 
           ('sample', 'u2', 1, '', 79), 
           ('reserved', 'u2', 1, '', 79), 
           ('recSize', 'u1', 1, '', 79), 
           ('Offs', 'ClkOffs', 1, '', 79), 
           ('crc16', 'u2', 1, '', 79), 
           ('reply', 'a1', 1, '', 80), 
           ('error', 'a1', 1, '', 81), 
           ('tot', 'u4', 1, '', 82), 
           ('wn', 'u2', 1, '', 82), 
           ('alpha0', 'f4', 1, '', 82), 
           ('alpha1', 'f4', 1, '', 82), 
           ('alpha2', 'f4', 1, '', 82), 
           ('alpha3', 'f4', 1, '', 82), 
           ('beta0', 'f4', 1, '', 82), 
           ('beta1', 'f4', 1, '', 82), 
           ('beta2', 'f4', 1, '', 82), 
           ('beta3', 'f4', 1, '', 82), 
           ('cs', 'u1', 1, '', 82), 
           ('time', 'u4', 1, '', 83), 
           ('type', 'u1', 1, '', 83), 
           ('data', 'u1', 1, '', 83), 
           ('cs', 'u1', 1, '', 83), 
           ('lt', 'u1', 1, '', 84), 
           ('cs', 'u1', 1, '', 84), 
           ('id', 'u1', 1, '', 85), 
           ('data', 'u1', 1, '', 85), 
           ('cs', 'a1', 1, '', 85), 
           ('params', 'a1', 1, '', 86), 
           ('delim', 'a1', 1, ',@', 86), 
           ('cs', 'a1', 1, '', 86), 
           ('svsCount', 'u1', 1, '', 87), 
           ('targetStream', 'u1', 1, '', 87), 
           ('issue', 'u2', 1, '', 87), 
           ('bitsCount', 'u2', 1, '', 87), 
           ('lastBitTime', 'u4', 1, '', 87), 
           ('uids', 'u1', 1, '', 87), 
           ('pad', 'u1', 1, '', 87), 
           ('hist', 'u4', 2, '', 87), 
           ('x', 'f8', 1, '', 88), 
           ('y', 'f8', 1, '', 88), 
           ('z', 'f8', 1, '', 88), 
           ('id', 'u2', 1, '', 88), 
           ('solType', 'u1', 1, '', 88), 
           ('cs', 'u1', 1, '', 88), 
           ('data', 'u1', 1, '', 89), 
           ('cs', 'u1', 1, '', 89), 
           ('data', 'u1', 1, '', 90), 
           ('crc16', 'u2', 1, '', 90), 
           ('tt', 'u4', 1, '', 91), 
           ('cs', 'u1', 1, '', 91), 
           ('val', 'f4', 1, '', 92), 
           ('cs', 'u1', 1, '', 92), 
           ('cs', 'u1', 1, '', 93);

INSERT INTO `customTypeVariablesMeta` (`name`, `type`, `dimensions`, `requiredValue`, `idCustomTypesMeta`) 
    VALUES ('a0', 'f8', 1, '', 1), 
           ('a1', 'f4', 1, '', 1), 
           ('tot', 'u4', 1, '', 1), 
           ('wnt', 'u2', 1, '', 1), 
           ('dtls', 'i1', 1, '', 1), 
           ('dn', 'u1', 1, '', 1), 
           ('wnlsf', 'u2', 1, '', 1), 
           ('dtlsf', 'i1', 1, '', 1), 
           ('value', 'f4', 1, '', 2), 
           ('interval', 'u2', 1, '', 2), 
           ('prn', 'i1', 1, '', 3), 
           ('cnt', 'u1', 1, '', 3), 
           ('data', 'u4', 1, '', 3), 
           ('fcn1', 'i1', 1, '', 4), 
           ('cnt', 'u1', 1, '', 4), 
           ('data', 'u4', 1, '', 4), 
           ('header', 'Header', 1, '', 5), 
           ('slot', 'SlotRec', 1, '', 5), 
           ('refrange', 'u4', 1, '', 6), 
           ('usi', 'u1', 1, '', 6), 
           ('num', 'u1', 1, '', 6), 
           ('svstOrDelrange', 'i2', 1, '', 7), 
           ('word1', 'u4', 1, '', 7), 
           ('flags', 'u2', 1, '', 7), 
           ('lock', 'u2', 1, '', 7), 
           ('word2', 'u4', 1, '', 7), 
           ('word1', 'u4', 1, '', 8), 
           ('word2', 'u4', 1, '', 8);



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
