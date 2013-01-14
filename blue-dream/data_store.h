#ifndef _DATA_STORE_
#define _DATA_STORE_

int init_sqlite3_();

/* �û�������Ϣ����� */
int insert_user_record(char *sql);
int delete_user_record(char *sql);
int update_user_record(char *sql);
int search_user_record(char *sql, char* , char *);

/* �ռǱ���� */
int insert_diary_record(char *sql);
int delete_diary_record(char *sql);
int update_diary_record(char *sql);
int search_diary_record(char *sql);

/* Officials'_Protective_Charm ͨѶ¼����� */
int insert_opc_record(char *sql);
int delete_opc_record(char *sql);
int update_opc_record(char *sql);
int search_opc_record(char *sql);

/* opc_��־����� */
int insert_opc_diary_record(char *sql);
int delete_opc_diary_record(char *sql);
int update_opc_diary_record(char *sql);
int search_opc_diary_record(char *sql);

#endif