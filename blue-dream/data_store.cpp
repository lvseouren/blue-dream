// console_sqlite_socialize system 1.0
// 760736077@qq.com qiang.zhou@veno2.com
// copyright 2012-2014
// think you for your criticism

#include <stdio.h>
#include <Windows.h>
#include "sqlite3.h"
#include "error.h"
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

int create_sqlite3_table(sqlite3 *db)
{
	int i=0;
	char* zErrMsg;
	char sql[MAX_TABLE_COUNT][500]={
		"create table IF NOT EXISTS user('id' INTEGER PRIMARY KEY AUTOINCREMENT, \
			 username varchar(32), passwd varchar(16))", 
		"create table IF NOT EXISTS user_diary('id' INTEGER PRIMARY KEY AUTOINCREMENT, \
			 username varchar(32), title varchar(64), contents varchar(1024), date DATE)", 
		"create table IF NOT EXISTS opc('id' INTEGER PRIMARY KEY AUTOINCREMENT, \
			 username varchar(32), opcname varchar(32), birthday varchar(8), phone varchar(16), address varchar(128), company varchar(64), residence varchar(128), characters varchar(128))",
		"create table IF NOT EXISTS opc_diary('id' INTEGER PRIMARY KEY AUTOINCREMENT, \
			 username varchar(32), opcname varchar(32), title varchar(64), contents varchar(1024), date DATE)"};
	for(i = 0; i < MAX_TABLE_COUNT; i++){
		if (sqlite3_exec(db, sql[i], callback, 0, &zErrMsg) != SQLITE_OK)
		{
			ResultPrint(stderr, "sql - error: %s - %s\n", sql[i], zErrMsg);
			return -1;
		}
	}
	return true;
}

int init_sqlite3_()
{
	int rc = 0;
	rc = sqlite3_open("blue_dream.db", &db);//1 打开数据库(open)
	if(rc)
	{
		printf("Content-type: text/html\n\n");
		ResultPrint(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return false;
	}
	// 创建表
	if(create_sqlite3_table(db) != 1){
		return ResultPrint(stderr, "create table function is err!\n");
	}
	return true;
}


int exec_sql(char *sql){
	char* zErrMsg;
	if(strlen(sql) <= 0)
	{
		ResultPrint(stderr, "SQL grammar(syntax) err\n");
		return -1;
	}

	if (sqlite3_exec(db, sql, callback, 0, &zErrMsg) != SQLITE_OK)
	{
		ResultPrint(stderr, "sql - error: %s - %s\n", sql, zErrMsg);
		return -1;
	}
	return true;
}


/* 用户基本信息表操作 */
int insert_user_record(char *sql){
	//insert into user(id,name,passwd) values(1,'admin','venoadmin')
	return exec_sql(sql);
}

int delete_user_record(char *sql){
	// sprintf(sql, "delete from [table] where name '%s'", user_name);
	return exec_sql(sql);
}

int update_user_record(char *sql){
	// sprintf(sql, "uptate [table] set userid = '%s' where name='%s'", user_id, user_name);
	return exec_sql(sql);
}

int search_user_record(char *sql, char *name = NULL, char *password = NULL){

	int rc = 0;
	sqlite3_stmt *stmt;
//	int id;
	char *tname, *tpassword;

	rc = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, 0);
	if(rc)
	{ 
		fprintf(stderr, "can't open statement: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return -1;
	}

//	printf("%10s %10s %10s\n", "id", "name", "password");
//	printf("%10s %10s %10s\n", "---", "---", "---");
	while(sqlite3_step(stmt) == SQLITE_ROW){
//		id = sqlite3_column_int(stmt, 0);
		tname = (char*)sqlite3_column_text(stmt, 1);
		tpassword = (char*)sqlite3_column_text(stmt, 2);
		if(strcmp(tname, name) == 0 && strcmp(tpassword, password) == 0)
		{
			sqlite3_finalize(stmt);
			return 2;
		}
//		printf("%10d %10s %10s\n", id, name, password);
	}

	sqlite3_finalize(stmt);
//	sqlite3_close(db);
	return 1;
}

/* 日记表操作 */
int insert_diary_record(char *sql){

	return exec_sql(sql);
}

int delete_diary_record(char *sql){

	return exec_sql(sql);
}

int update_diary_record(char *sql){

	return exec_sql(sql);
}

int search_diary_record(char *sql){

	int rc = 0;
	sqlite3_stmt *stmt;
	int id;
	char *name, *title, *contents, *date;

	rc = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, 0);
	if(rc)
	{ 
		fprintf(stderr, "can't open statement: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return -1;
	}

	printf("%3s %8s %16s %32s %16s\n", "id", "name", "title", "contents", "date");
	printf("%3s %8s %16s %32s %16s\n", "---", "---", "---", "---", "---");
	while(sqlite3_step(stmt) == SQLITE_ROW){
		id = sqlite3_column_int(stmt, 0);
		name = (char*)sqlite3_column_text(stmt, 1);
		title = (char*)sqlite3_column_text(stmt, 2);
		contents = (char*)sqlite3_column_text(stmt, 3);
		date = (char*)sqlite3_column_text(stmt, 4);

		printf("%3d %8s %16s %32s %16s\n", id, name, title, contents, date);
	}

	sqlite3_finalize(stmt);
//	sqlite3_close(db);
	return true;
}

/* Officials'_Protective_Charm 通讯录表操作 */
int insert_opc_record(char *sql){

	return exec_sql(sql);
}

int delete_opc_record(char *sql){

	return exec_sql(sql);
}

int update_opc_record(char *sql){

	return exec_sql(sql);
}

int search_opc_record(char *sql){

	int rc = 0;
	sqlite3_stmt *stmt;
	int id;
	char *name, *opcname, *birthday, *phone, *address, *company, *residence, *characters;

	rc = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, 0);
	if(rc)
	{ 
		fprintf(stderr, "can't open statement: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return -1;
	}

	printf("%3s %8s %10s %8s %11s %16s %16s %16s %16s\n", 
		"id", "name", "opcname", "birthday", "phone", "address", "company", "residence", "characters");
	printf("%3s %8s %10s %8s %11s %16s %16s %16s %16s\n",
		"---", "---", "---", "---", "---", "---", "---", "---", "---");
	while(sqlite3_step(stmt) == SQLITE_ROW){
		id = sqlite3_column_int(stmt, 0);
		name = (char*)sqlite3_column_text(stmt, 1);
		opcname = (char*)sqlite3_column_text(stmt, 2);
		birthday = (char*)sqlite3_column_text(stmt, 3);
		phone = (char*)sqlite3_column_text(stmt, 4);
		address = (char*)sqlite3_column_text(stmt, 5);
		company = (char*)sqlite3_column_text(stmt, 6);
		residence = (char*)sqlite3_column_text(stmt, 7);
		characters = (char*)sqlite3_column_text(stmt, 8);

		printf("%3d %8s %10s %8s %11s %16s %16s %16s %16s\n", 
			id, name, opcname, birthday, phone, address, company, residence, characters);
	}

	sqlite3_finalize(stmt);
//	sqlite3_close(db);
	return true;
}

/* opc_日志表操作 */
int insert_opc_diary_record(char *sql){

	return exec_sql(sql);
}

int delete_opc_diary_record(char *sql){

	return exec_sql(sql);
}

int update_opc_diary_record(char *sql){

	return exec_sql(sql);
}

int search_opc_diary_record(char *sql){

	int rc = 0;
	sqlite3_stmt *stmt;
	int id;
	char *name, *opcname, *title, *contents, *date;

	rc = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, 0);
	if(rc)
	{ 
		fprintf(stderr, "can't open statement: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return -1;
	}

	printf("%3s %8s %8s %16s %32s %16s\n", "id", "name", "opcname", "title", "contents", "date");
	printf("%3s %8s %8s %16s %32s %16s\n", "---", "---", "---", "---", "---", "---");
	while(sqlite3_step(stmt) == SQLITE_ROW){
		id = sqlite3_column_int(stmt, 0);
		name = (char*)sqlite3_column_text(stmt, 1);
		opcname = (char*)sqlite3_column_text(stmt, 2);
		title = (char*)sqlite3_column_text(stmt, 3);
		contents = (char*)sqlite3_column_text(stmt, 4);
		date = (char*)sqlite3_column_text(stmt, 5);

		printf("%3d %8s %8 %16s %32s %16s\n", id, name, opcname, title, contents, date);
	}

	sqlite3_finalize(stmt);
//	sqlite3_close(db);
	return true;
}