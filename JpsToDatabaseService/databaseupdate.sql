delimiter $$

CREATE TABLE `commandqueue` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `command` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `commandfk_idx` (`id`),
  CONSTRAINT `commandfk` FOREIGN KEY (`id`) REFERENCES `commandclassifier` (`id`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8$$

CREATE TABLE `commandclassifier` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(100) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `name_UNIQUE` (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8$$

INSERT INTO `commandclassifier` (`name`) VALUES ('PAUSE');