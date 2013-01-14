// blue-dream.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include "error.h"

#include "interface.h"

void table_info(){
	ResultPrint(stdout, "user table operation\n");
	ResultPrint(stdout, "user_diary table operation\n");
	ResultPrint(stdout, "opc table operation\n");
	ResultPrint(stdout, "opc_diary table operation\n");
}

void user_info(){
	ResultPrint(stdout, "insert into user table operation\n");
	ResultPrint(stdout, "delete from user table operation\n");
	ResultPrint(stdout, "updata user table operation\n");
	ResultPrint(stdout, "select from user table operation\n");
}

void user_diary_info(){
	ResultPrint(stdout, "insert into user_diary table operation\n");
	ResultPrint(stdout, "delete from user_diary table operation\n");
	ResultPrint(stdout, "updata user_diary table operation\n");
	ResultPrint(stdout, "select from user_diary table operation\n");
}

void opc_info(){
	ResultPrint(stdout, "insert into opc table operation\n");
	ResultPrint(stdout, "delete from opc table operation\n");
	ResultPrint(stdout, "updata opc table operation\n");
	ResultPrint(stdout, "select from opc table operation\n");
}

void opc_diary_info(){
	ResultPrint(stdout, "insert into opc_diary table operation\n");
	ResultPrint(stdout, "delete from opc_diary table operation\n");
	ResultPrint(stdout, "updata opc_diary table operation\n");
	ResultPrint(stdout, "select from opc_diary table operation\n");
}

int login()// int certificate
{
	return search_user_();
}

int main(int argc, char* argv[])
{
	int count = 10000;

	init_sqlite();
	if(login() != 1)
	{
		printf("login err.\n");
		return -1;
	}

	int table_flag, operate_flag;
	ResultPrint(stdout, "***** This is a test command. *****\n");
	while(1){
		table_info();
		scanf("%d", &table_flag);
		switch(table_flag){
		case 1: 
			while(1) {
				user_info();
				scanf("%d", &operate_flag);
				if(operate_flag == 5) break;
				switch(operate_flag){
				case 1:
					add_user_();
					break;
				case 2:
					delete_user_();
					break;
				case 3:
					update_user_();
					break;
				case 4:
					search_user_();
					break;
				default: break;
				}
			}
			break;
		case 2:
			while(1) {
				user_diary_info();
				scanf("%d", &operate_flag);
				if(operate_flag == 5) break;
				switch(operate_flag){
				case 1:
					add_diary_();
					break;
				case 2:
					delete_diary_();
					break;
				case 3:
					update_diary_();
					break;
				case 4:
					search_diary_();
					break;
				default: break;
				}
			}
			
			break;
		case 3:
			while(1) {
				opc_info();
				scanf("%d", &operate_flag);
				if(operate_flag == 5) break;
				switch(operate_flag){
				case 1:
					add_opc_();
					break;
				case 2:
					delete_opc_();
					break;
				case 3:
					update_opc_();
					break;
				case 4:
					search_opc_();
					break;
				default: break;
				}
			}
			
			break;
		case 4:
			while(1) {
				opc_diary_info();
				scanf("%d", &operate_flag);
				if(operate_flag == 5) break;
				switch(operate_flag){
				case 1:
					add_opc_diary_();
					break;
				case 2:
					delete_opc_diary_();
					break;
				case 3:
					update_opc_diary_();
					break;
				case 4:
					search_opc_diary_();
					break;
				default: break;
				}
			}
			break;
		case 5:
			exit(1);
			break;
		default: break;
		}
	}
//	Sleep(200000);
	return 0;
}

