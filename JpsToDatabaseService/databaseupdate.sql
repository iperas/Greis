delimiter $$

DROP TABLE IF EXISTS `commandqueue`;
DROP TABLE IF EXISTS `servicelog`;
DROP TABLE IF EXISTS `commandclassifier`;
DROP TABLE IF EXISTS `servicelogseverityclassifier`;
DROP TABLE IF EXISTS `configinfo`;

CREATE TABLE `commandclassifier` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(100) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `name_UNIQUE` (`name`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8$$


delimiter $$

CREATE TABLE `commandqueue` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `command_id` int(11) NOT NULL,
  `arguments` varchar(1000) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `commandidfk_idx` (`command_id`),
  CONSTRAINT `commandfk` FOREIGN KEY (`command_id`) REFERENCES `commandclassifier` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=14 DEFAULT CHARSET=utf8$$


delimiter $$

CREATE TABLE `configinfo` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(64) NOT NULL,
  `value` varchar(512) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8$$

delimiter $$

CREATE TABLE `servicelog` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `timeStamp` datetime NOT NULL,
  `message` varchar(512) DEFAULT NULL,
  `severity_id` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `serviceidfk_idx` (`severity_id`),
  CONSTRAINT `serviceidfk` FOREIGN KEY (`severity_id`) REFERENCES `servicelogseverityclassifier` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8$$


delimiter $$

CREATE TABLE `servicelogseverityclassifier` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(45) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8$$

DELETE FROM `commandqueue`;
DELETE FROM `commandclassifier`;
DELETE FROM `servicelogseverityclassifier`;
INSERT INTO `commandclassifier` (`id`, `name`) VALUES (1, 'RESTART');
INSERT INTO `commandclassifier` (`id`, `name`) VALUES (2, 'SETCONFIGPROPERTIES');
INSERT INTO `commandclassifier` (`id`, `name`) VALUES (3, 'SHUTDOWN');
INSERT INTO `commandclassifier` (`id`, `name`) VALUES (4, 'PAUSE');
INSERT INTO `commandclassifier` (`id`, `name`) VALUES (5, 'RESUME');
INSERT INTO `servicelogseverityclassifier` (`id`, `name`) VALUES (1, 'FATAL');
INSERT INTO `servicelogseverityclassifier` (`id`, `name`) VALUES (2, 'ERROR');
INSERT INTO `servicelogseverityclassifier` (`id`, `name`) VALUES (3, 'WARNING');
INSERT INTO `servicelogseverityclassifier` (`id`, `name`) VALUES (4, 'INFO');
INSERT INTO `servicelogseverityclassifier` (`id`, `name`) VALUES (5, 'DEBUG');

INSERT INTO `commandqueue` (`command_id`, `arguments`) VALUES (2, "test1=value1;test3=value3");
INSERT INTO `commandqueue` (`command_id`) VALUES (4);
INSERT INTO `commandqueue` (`command_id`) VALUES (1);
INSERT INTO `commandqueue` (`command_id`) VALUES (5);
INSERT INTO `commandqueue` (`command_id`) VALUES (3);

SELECT COMMANDQUEUE.id, COMMANDCLASSIFIER.name, COMMANDQUEUE.arguments 
FROM COMMANDQUEUE, COMMANDCLASSIFIER WHERE COMMANDCLASSIFIER.id = COMMANDQUEUE.command_id ORDER BY id;

SELECT servicelogseverityclassifier.name, servicelog.message FROM servicelog, servicelogseverityclassifier WHERE servicelog.severity_id = servicelogseverityclassifier.id;