#include"conv.h"

char user1[30];

void add_user(char* user)
{
	char data[70] = "/tmp/conv/";
	
	if(opendir(data)!=NULL)
    mkfifo(strcat(data,user),0666);
}

int check_user_availaibility(char* path)
{
	char a[30];

	int fd = open(path,O_RDWR,0777);
    printf("who do you wish to contact ?");
    scanf("%s",a);
	
	seeknfind(fd,a);
	
	strcpy(user1,a);
	
	if(strcmp(seeknfind(fd,"PID:"),"NULL")){
        	printf("online\n");
        	return 1;}
	else{
	       printf("offline\n");
	       return 0;}
		   
	close(fd);
}

void* tx(void* tmp)
{
	int fd;
	char data[70] = "/tmp/conv/";
	char*user;
	char* msg;
	
	tx_data* t=(tx_data*)tmp;
	user=t->id;
	msg=t->msg;
	
    fd = open(strcat(data,user),O_WRONLY);
	
	write(fd,msg,strlen(msg));
	
	
	close(fd);
	return NULL;
}

void* rx(void*a)
{
	int fd,i;
	char data[70] = "/tmp/conv/",ch[100];
	char* user = (char*)a;
	
    fd = open(strcat(data,user), O_RDONLY);
	
    i=read(fd,ch,sizeof(ch));
	
	if (i>0)
	ch[i]='\0';

    printf("%s:%s\n",user1,ch);
	close(fd);
	return NULL;
}

void window(int fd){
	char ch;
    write(1,&ch,read(fd,&ch,1));}
