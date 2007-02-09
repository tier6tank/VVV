/* Please note that this script doesn't maintain   proper order of creation for computed columns if
   they reference other tables.  */
/********************* ROLES **********************/
/********************* UDFS ***********************/
/****************** GENERATORS ********************/
CREATE GENERATOR GEN_FILES_ID;
CREATE GENERATOR GEN_PATHS_ID;
CREATE GENERATOR GEN_VOLUMES_ID;
/******************** DOMAINS *********************/
/******************* PROCEDURES ******************/
/******************** TABLES **********************/
CREATE TABLE FILES
(
  FILE_ID Numeric(18,0) NOT NULL,
  FILE_NAME Varchar(500) CHARACTER SET ISO8859_1,
  FILE_SIZE Numeric(18,0),
  FILE_EXT Varchar(50) CHARACTER SET ISO8859_1,
  FILE_DATETIME Timestamp,
  PATH_ID Numeric(18,0),
  IS_FOLDER Char(1),
  CONSTRAINT PK_FILES PRIMARY KEY (FILE_ID)
);
CREATE TABLE PATHS
(
  PATH_ID Numeric(18,0) NOT NULL,
  VOLUME_ID Numeric(18,0) NOT NULL,
  PATH_NAME Varchar(500) CHARACTER SET ISO8859_1 NOT NULL,
  FATHER_ID Numeric(18,0),
  CONSTRAINT PK_PATHS PRIMARY KEY (PATH_ID)
);
CREATE TABLE VOLUMES
(
  VOLUME_ID Numeric(18,0) NOT NULL,
  VOLUME_NAME Varchar(100) CHARACTER SET ISO8859_1 NOT NULL,
  CONSTRAINT PK_VOLUMES PRIMARY KEY (VOLUME_ID),
  CONSTRAINT UNQ_VOLUMES UNIQUE (VOLUME_NAME)
);
/********************* VIEWS **********************/
/******************* EXCEPTIONS *******************/
/******************** TRIGGERS ********************/
SET TERM ^ ;
CREATE TRIGGER FILES_BI FOR FILES ACTIVE
BEFORE INSERT POSITION 0
AS 
BEGIN 
  IF (NEW.FILE_ID IS NULL) THEN 
    NEW.FILE_ID = GEN_ID(GEN_FILES_ID,1); 
END^
SET TERM ; ^
SET TERM ^ ;
CREATE TRIGGER PATHS_BI FOR PATHS ACTIVE
BEFORE INSERT POSITION 0
AS 
BEGIN 
  IF (NEW.PATH_ID IS NULL) THEN 
    NEW.PATH_ID = GEN_ID(GEN_PATHS_ID,1); 
END^
SET TERM ; ^
SET TERM ^ ;
CREATE TRIGGER VOLUMES_BI FOR VOLUMES ACTIVE
BEFORE INSERT POSITION 0
AS 
BEGIN 
  IF (NEW.VOLUME_ID IS NULL) THEN 
    NEW.VOLUME_ID = GEN_ID(GEN_VOLUMES_ID,1); 
END^
SET TERM ; ^
ALTER TABLE FILES ADD CONSTRAINT FK_FILES_PATHS
  FOREIGN KEY (PATH_ID) REFERENCES PATHS (PATH_ID);
GRANT DELETE, INSERT, REFERENCES, SELECT, UPDATE
 ON FILES TO  SYSDBA WITH GRANT OPTION;
UPDATE RDB$RELATION_FIELDS set RDB$DESCRIPTION = 'ID of the path of the father folder, NULL if none'  where RDB$FIELD_NAME = 'FATHER_ID' and RDB$RELATION_NAME = 'PATHS';
ALTER TABLE PATHS ADD CONSTRAINT FK_PATHS_VOLUMES
  FOREIGN KEY (VOLUME_ID) REFERENCES VOLUMES (VOLUME_ID);
CREATE INDEX PATHS_IDX_FATHER_ID ON PATHS (FATHER_ID);
GRANT DELETE, INSERT, REFERENCES, SELECT, UPDATE
 ON PATHS TO  SYSDBA WITH GRANT OPTION;
GRANT DELETE, INSERT, REFERENCES, SELECT, UPDATE
 ON VOLUMES TO  SYSDBA WITH GRANT OPTION;