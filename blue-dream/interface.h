#ifndef _INTERFACE_
#define _INTERFACE_

int init_sqlite();

/* 用户基本信息表操作 */
int add_user_();
int delete_user_();
int update_user_();
int search_user_();

/* 日记表操作 */
int add_diary_();
int delete_diary_();
int update_diary_();
int search_diary_();

/* Officials'_Protective_Charm 通讯录表操作 */
int add_opc_();
int delete_opc_();
int update_opc_();
int search_opc_();

/* opc_日志表操作 */
int add_opc_diary_();
int delete_opc_diary_();
int update_opc_diary_();
int search_opc_diary_();

#endif