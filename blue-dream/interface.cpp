#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data_store.h"
#include "interface.h"
#include "error.h"

char sql[2048];

int init_sqlite(){
	init_sqlite3_();
	return 1;
}

/* 用户基本信息表操作 */
int add_user_(){
	char name[32], password[16];
	ResultPrint(stdout, "username(32)");
	scanf("%s", &name);
	ResultPrint(stdout, "password(16)");
	scanf("%s", &password);
	sprintf(sql, "insert into user(username,passwd) values('%s','%s')", name, password);
	insert_user_record(sql);
	return 1;
}
int delete_user_(){
	return 1;
}
int update_user_(){
	return 1;
}
int search_user_(){
	// search_user_ just for login.
	// TODO: if the username and password is exist and right, return 0;
	// TODO: esle show the username or password is error.
	char username[16], password[16];
	printf("Please input the User: ");
	scanf("%s", &username);
	printf("Please input the password: ");
	scanf("%s", &password); // TODO: how to not show the character.

	if(strlen(username) < 1 || strlen(password) < 1)
		return -1;

	char* sql = "select * from user";
	int err = search_user_record(sql, username, password);
	if(2 == err)
	{
		fprintf(stdout, "\nlogin success...\n");
		return 1;
	}
	else if(1 == err)
		fprintf(stdout, "\nname or password err...\n");
	else
		fprintf(stderr, "\nlogin failed!\n");
	return 0;
}

/* 日记表操作 */
int add_diary_(){
	char name[32], password[16];
//	ResultPrint(stdout, "username(32)");
//	scanf("%s", &name);
//	ResultPrint(stdout, "password(16)");
//	scanf("%s", &password);
	sprintf(sql, "insert into user_diary(username, title, contents, date) values('qiang1','first diary', 'test content. you are beautiful.', datetime('now', 'localtime'))");// 没有now()
	insert_user_record(sql);
	return 1;
}
int delete_diary_(){
	return 1;
}
int update_diary_(){
	return 1;
}
int search_diary_(){

	char* sql = "select * from user_diary";
	int err = search_diary_record(sql);
	if(err == -1)
	{
		fprintf(stdout, "\nsearch_diary_ err...\n");
		return 0;
	}
	return 1;
}

/* Officials'_Protective_Charm 通讯录表操作 */
int add_opc_(){
	return 1;
}
int delete_opc_(){
	return 1;
}
int update_opc_(){
	return 1;
}
int search_opc_(){
	char* sql = "select * from opc";
	int err = search_opc_record(sql);
	if(err == -1)
	{
		fprintf(stdout, "\nopc_ err...\n");
		return 0;
	}
	return 1;
}

/* opc_日志表操作 */
int add_opc_diary_(){
	return 1;
}
int delete_opc_diary_(){
	return 1;
}
int update_opc_diary_(){
	return 1;
}
int search_opc_diary_(){
	char* sql = "select * from opc_diary";
	int err = search_opc_diary_record(sql);
	if(err == -1)
	{
		fprintf(stdout, "\nsearch_opc_diary_ err...\n");
		return 0;
	}
	return 1;
}