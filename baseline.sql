-- USE `world`;
USE DATABASE `world`;
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

INSERT INTO `messagesmeta` (`name`, `title`, `idKind`, `idType`, `tableName`)
    VALUES
(
{name: VARCHAR},
{title: VARCHAR},
{idKind: BIGINT UNSIGNED},
{idType: BIGINT UNSIGNED},
{tableName: VARCHAR}
);


-- Наполнение классификатора messageKindsClassifier
INSERT INTO `messageKindsClassifier` (messageKind) 
    VALUES ('NonStandardTextMessage'), 
           ('StandardTextMessage'), 
           ('GreisStandardMessage'), 
           ('ForeignStandardMessage'), 
           ('UnknownStandardMessage');

-- Наполнение классификатора messageKindsClassifier
INSERT INTO `messageTypesClassifier` (messageType) 
    VALUES ('Unknown'), 
           ('AlmanacsAndEphemeris');

-- Мета-информация для сообщений
INSERT INTO `messagesmeta` (`name`, `title`, `idKind`, `idType`, `tableName`) 
    VALUES ('FileId', '[JP] File Identifier', 3, 1, 'FileId'), 
           ('MsgFmt', '[MF] Messages Format', 3, 1, 'MsgFmt'), 
           ('RcvTime', '[~~](RT) Receiver Time', 3, 1, 'RcvTime'), 
           ('EpochTime', '[::](ET) Epoch Time', 3, 1, 'EpochTime'), 
           ('RcvDate', '[RD] Receiver Date', 3, 1, 'RcvDate'), 
           ('RcvTimeOffset', '[TO] Reference Time to Receiver Time Offset', 3, 1, 'RcvTimeOffset'), 
           ('RcvTimeOffsetDot', '[DO] Derivative of Receiver Time Offset', 3, 1, 'RcvTimeOffsetDot'), 
           ('RcvTimeAccuracy', '[BP] Rough Accuracy of Time Approximation', 3, 1, 'RcvTimeAccuracy'), 
           ('GPSTime', '[GT] GPS Time', 3, 1, 'GPSTime'), 
           ('RcvGPSTimeOffset', '[GO] GPS to Receiver Time Offset', 3, 1, 'RcvGPSTimeOffset'), 
           ('GLOTime', '[NT] GLONASS Time', 3, 1, 'GLOTime'), 
           ('RcvGLOTimeOffset', '[NO] GLONASS to Receiver Time Offset', 3, 1, 'RcvGLOTimeOffset'), 
           ('RcvGALTimeOffset', '[EO] GALILEO to Receiver Time Offset', 3, 1, 'RcvGALTimeOffset'), 
           ('RcvWAASTimeOffset', '[WO] WAAS to Receiver Time Offset', 3, 1, 'RcvWAASTimeOffset'), 
           ('GpsUtcParam', '[UO] GPS UTC Time Parameters', 3, 1, 'GpsUtcParam'), 
           ('WaasUtcParam', '[WU] WAAS UTC Time Parameters', 3, 1, 'WaasUtcParam'), 
           ('GalUtcGpsParam', '[EU] GALILEO UTC and GPS Time Parameters', 3, 1, 'GalUtcGpsParam'), 
           ('GloUtcGpsParam', '[NU] GLONASS UTC and GPS Time Parameters', 3, 1, 'GloUtcGpsParam'), 
           ('SolutionTime', '[ST] Solution Time-Tag', 3, 1, 'SolutionTime'), 
           ('Pos', '[PO] Cartesian Position', 3, 1, 'Pos'), 
           ('Vel', '[VE] Cartesian Velocity', 3, 1, 'Vel'), 
           ('PosVel', '[PV] Cartesian Position and Velocity', 3, 1, 'PosVel'), 
           ('GeoPos', '[PG] Geodetic Position', 3, 1, 'GeoPos'), 
           ('GeoVel', '[VG] Geodetic Velocity', 3, 1, 'GeoVel'), 
           ('Rms', '[SG] Position and Velocity RMS Errors', 3, 1, 'Rms'), 
           ('Dops', '[DP] Dilution of Precision (DOP)', 3, 1, 'Dops'), 
           ('PosCov', '[SP] Position Covariance Matrix', 3, 1, 'PosCov'), 
           ('VelCov', '[SV] Velocity Covariance Matrix', 3, 1, 'VelCov'), 
           ('BaseLine', '[BL] Base Line', 3, 1, 'BaseLine'), 
           ('PosStat', '[PS] Position Statistics', 3, 1, 'PosStat'), 
           ('PosCompTime', '[PT] Time of Continuous Position Computation', 3, 1, 'PosCompTime'), 
           ('SatIndex', '[SI] Satellite Indices', 3, 1, 'SatIndex'), 
           ('AntName', '[AN] Antenna Names', 3, 1, 'AntName'), 
           ('SatNumbers', '[NN] GLONASS Satellite System Numbers', 3, 1, 'SatNumbers'), 
           ('SatElevation', '[EL] Satellite Elevations', 3, 1, 'SatElevation'), 
           ('SatAzimuth', '[AZ] Satellite Azimuths', 3, 1, 'SatAzimuth'), 
           ('PR', '[RC], [R1], [R2], [R3], [R5]: Pseudoranges', 3, 1, 'PR'), 
           ('SPR', '[rc], [r1], [r2], [r3], [r5]: Short Pseudoranges', 3, 1, 'SPR'), 
           ('RPR', '[1R], [2R], [3R], [5R]: Relative Pseudoranges', 3, 1, 'RPR'), 
           ('SRPR', '[1r], [2r], [3r], [5r]: Short Relative Pseudoranges', 3, 1, 'SRPR'), 
           ('SC', '[CC], [C1], [C2], [C3], [C5]: Smoothing Corrections', 3, 1, 'SC'), 
           ('SS', '[cc], [c1], [c2], [c3], [c5]: Short Smoothing Corrections', 3, 1, 'SS'), 
           ('CP', '[PC], [P1], [P2], [P3], [P5]: Carrier Phases', 3, 1, 'CP'), 
           ('SCP', '[pc], [p1], [p2], [p3], [p5]: Short Carrier Phases', 3, 1, 'SCP'), 
           ('RCP_RC', '[CP], [1P], [2P], [3P], [5P]: Short Relative Carrier Phases', 3, 1, 'RCP_RC'), 
           ('RCP_rc', '[cp], [1p], [2p], [3p], [5p]: Short Relative Carrier Phases', 3, 1, 'RCP_rc'), 
           ('DP', '[DC], [D1], [D2], [D3], [D5]: Doppler', 3, 1, 'DP'), 
           ('SRDP', '[1d], [2d], [3d], [5d]: Short Relative Doppler', 3, 1, 'SRDP'), 
           ('CNR', '[EC], [E1], [E2], [E3], [E5]: Carrier to Noise Ratio', 3, 1, 'CNR'), 
           ('CNR_4', '[CE], [1E], [2E], [3E], [5E]: Carrier to Noise Ratio x ', 3, 1, 'CNR_4'), 
           ('Flags', '[FC], [F1], [F2], [F3], [F5]: Signal Lock Loop Flags', 3, 1, 'Flags'), 
           ('TrackingTimeCA', '[TC] CA/L1 Continuous Tracking Time', 3, 1, 'TrackingTimeCA'), 
           ('NavStatus', '[SS] Satellite Navigation Status', 3, 1, 'NavStatus'), 
           ('IonoDelay', '[ID] Ionospheric Delays', 3, 1, 'IonoDelay'), 
           ('GPSAlm', '[GA] GPS Almanac', 3, 2, 'GPSAlm'), 
           ('GALAlm', '[EA] GALILEO Almanac', 3, 2, 'GALAlm'), 
           ('GLOAlmanac', '[NA] GLONASS Almanac', 3, 2, 'GLOAlmanac'), 
           ('WAASAlmanac', '[WA] WAAS Almanac', 3, 2, 'WAASAlmanac'), 
           ('GPSEphemeris', '[GE] GPS Ephemeris', 3, 2, 'GPSEphemeris'), 
           ('GLOEphemeris', '[NE] GLONASS Ephemeris', 3, 2, 'GLOEphemeris'), 
           ('WAASEhemeris', '[WE] WAAS Ephemeris', 3, 2, 'WAASEhemeris'), 
           ('GALEphemeris', '[EN] GALILEO Ephemeris', 3, 2, 'GALEphemeris'), 
           ('GpsNavData', '[GD] GPS Raw Navigation Data', 3, 1, 'GpsNavData'), 
           ('GloNavData', '[LD] GLONASS Raw Navigation Data', 3, 1, 'GloNavData'), 
           ('WAASRawMessage', '[WD] WAAS Raw Navigation Data', 3, 1, 'WAASRawMessage'), 
           ('GALRawMessage', '[ED] GALILEO Raw Navigation Data', 3, 1, 'GALRawMessage'), 
           ('GloPhaseDelay', '[gC], [g1], [g2], [g3]: GLONASS Phase Delays', 3, 1, 'GloPhaseDelay'), 
           ('RotationMatrix', '[MR] Rotation Matrix', 3, 1, 'RotationMatrix'), 
           ('RotationMatrixAndVectors', '[mr] Rotation Matrix and Vectors', 3, 1, 'RotationMatrixAndVectors'), 
           ('RotationAngles', '[AR] Rotation Angles', 3, 1, 'RotationAngles'), 
           ('AngularVelocity', '[AV] Angular Velocities', 3, 1, 'AngularVelocity'), 
           ('InertialMeasurements', '[IM] Inertial Measurements', 3, 1, 'InertialMeasurements'), 
           ('ExtEvent', '[XA], [XB] External Event', 3, 1, 'ExtEvent'), 
           ('PPSOffset', '[ZA], [ZB] PPS Offset', 3, 1, 'PPSOffset'), 
           ('RcvTimeOffsAtPPS', '[YA], [YB] Time Offset at PPS Generation Time', 3, 1, 'RcvTimeOffsAtPPS'), 
           ('RefEpoch', '[rE] Reference Epoch', 3, 1, 'RefEpoch'), 
           ('RawMeas', '[rM] Raw Measurements', 3, 1, 'RawMeas'), 
           ('PosVelVector', '[rV] Receiver’s Position and Velocity', 3, 1, 'PosVelVector'), 
           ('ClockOffsets', '[rT] Receiver Clock Offsets', 3, 1, 'ClockOffsets'), 
           ('RE', '[RE] Reply', 3, 1, 'RE'), 
           ('ER', '[ER] Error', 3, 1, 'ER'), 
           ('IonoParams', '[IO] Ionospheric Parameters', 3, 1, 'IonoParams'), 
           ('Event', '[==](EV) Event', 3, 1, 'Event'), 
           ('Latency', '[LT] Message Output Latency', 3, 1, 'Latency'), 
           ('Wrapper', '[>>] Wrapper', 3, 1, 'Wrapper'), 
           ('Params', '[PM] Parameters', 3, 1, 'Params'), 
           ('LoggingHistory', '[LH] Logging History', 3, 1, 'LoggingHistory'), 
           ('BaseInfo', '[BI] Base Station Information', 3, 1, 'BaseInfo'), 
           ('Security', '[SE] Security', 3, 1, 'Security'), 
           ('Security', '[SM] Security for [rM]', 3, 1, 'Security'), 
           ('TrackingTime', '[TT] CA/L1 Overall Continuous Tracking Time', 3, 1, 'TrackingTime'), 
           ('RcvOscOffs', '[OO] Oscillator Offset', 3, 1, 'RcvOscOffs'), 
           ('EpochEnd', '[||](EE) Epoch End', 3, 1, 'EpochEnd');


