#include "stdafx.h"
#include "error.h"
#include "sqlite3.h"
#include "data_store.h"

#define MAX_TABLE_COUNT 4
sqlite3 *db;

//回调函数(callback)
static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
	int i = 0;
	printf("Content-type: text/html\n\n");
	for (i=0; i<argc; i++)
	{    
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

int create_sqlite3_table(sqlite3 *db){
	int i=0;
	char* zErrMsg;
	char sql[MAX_TABLE_COUNT][500]={"create table IF NOT EXISTS user('id' int(10) NOT NULL, name varchar(20), passwd varchar(20))",
									"create table IF NOT EXISTS diary('id' int(10) NOT NULL, name varchar(20), passwd varchar(20))", 
									"create table IF NOT EXISTS opc('id' int(10) NOT NULL, name varchar(20), passwd varchar(20))",
									"create table IF NOT EXISTS opc_diary('id' int(10) NOT NULL, name varchar(20), passwd varchar(20))"};
	for(i = 0; i < MAX_TABLE_COUNT; i++){
		if (sqlite3_exec(db, sql[i], callback, 0, &zErrMsg) != SQLITE_OK)
		{
			ResultPrint(stderr, "sql - error: %s - %s\n", sql[i], zErrMsg);
			return -1;
		}
	}
	return true;
}

int init_sqlite3_(){
	//int nrow = 0, ncolumn = 0;
	//char **azResult = NULL;
	//char *zErrMsg = 0;
	//char username[] = "admin";
	//char passwd[] = "1";
	int rc = 0;
	rc = sqlite3_open("test1.db", &db);//1 打开数据库(open)
	if(rc)
	{
		printf("Content-type: text/html\n\n");
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return ResultPrint(stderr, "it's err!\n");
	}
	// 创建表
	if(create_sqlite3_table(db) != true){
		return ResultPrint(stderr, "create table function is err!\n");
	}
	return true;
}

/* 用户基本信息表操作 */
int add_user_record(char *sql){
	//insert into user(id,name,passwd) values(1,'admin','venoadmin')
	return true;
}

int delete_user_record(char *sql){

	return true;
}

int updata_user_record(char *sql){

	return true;
}

int search_user_record(char *sql){

	return true;
}

/* 日记表操作 */
int add_diary_record(char *sql){

	return true;
}

int delete_diary_record(char *sql){

	return true;
}

int updata_diary_record(char *sql){

	return true;
}

int search_diary_record(char *sql){

	return true;
}

/* Officials'_Protective_Charm 通讯录表操作 */
int add_opc_record(char *sql){

	return true;
}

int delete_opc_record(char *sql){

	return true;
}

int updata_opc_record(char *sql){

	return true;
}

int search_opc_record(char *sql){

	return true;
}

/* opc_日志表操作 */
int add_opc_diary_record(char *sql){

	return true;
}

int delete_opc_diary_record(char *sql){

	return true;
}

int updata_opc_diary_record(char *sql){

	return true;
}

int search_opc_diary_record(char *sql){

	return true;
}