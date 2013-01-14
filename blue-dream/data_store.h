#ifndef _DATA_STORE_
#define _DATA_STORE_

int init_sqlite3_();

/* 用户基本信息表操作 */
int insert_user_record(char *sql);
int delete_user_record(char *sql);
int update_user_record(char *sql);
int search_user_record(char *sql, char* , char *);

/* 日记表操作 */
int insert_diary_record(char *sql);
int delete_diary_record(char *sql);
int update_diary_record(char *sql);
int search_diary_record(char *sql);

/* Officials'_Protective_Charm 通讯录表操作 */
int insert_opc_record(char *sql);
int delete_opc_record(char *sql);
int update_opc_record(char *sql);
int search_opc_record(char *sql);

/* opc_日志表操作 */
int insert_opc_diary_record(char *sql);
int delete_opc_diary_record(char *sql);
int update_opc_diary_record(char *sql);
int search_opc_diary_record(char *sql);

#endif