#include"find.h"

struct data{
	char*id;
    char*msg;};
	
typedef struct data tx_data;

extern char user1[30];
extern char user2[30];
//extern tx_data tx_user;

int check_user_availaibility(char*);
void* tx(void*);
void* rx(void*);
void window(int);
void add_user(char*);
