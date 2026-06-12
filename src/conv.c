#include"conv.h"

char user1[30];

void add_user(char* user)
{
	char data[70] = "/tmp/conv/";
	DIR*dr = opendir(data);
	
	if(dr!=NULL)
        mkfifo(strcat(data,user),0666);
	else
	    mkdir(data,0666);
	
	closedir(dr);
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
	int fd,c;
	char data[70] = "/tmp/conv/";
	char*user;
	char msg2[100];
	
	tx_data* t=(tx_data*)tmp;
	user=t->id;
	
	fd = open(strcat(data,user),O_WRONLY);
	
    while ((c = getchar()) != '\n' && c != EOF)
	{
	} 
		
	while(1){
		fgets(msg2,100,stdin);
		printf("\n");
	    if((write(fd,msg2,strlen(msg2)))==0)
			break;
	}
	
	close(fd);
	return NULL;
}

void* rx(void*a)
{
	int fd,i;
	char data[70] = "/tmp/conv/",ch[100];
	char* user = (char*)a;
	
    fd = open(strcat(data,user), O_RDONLY);
	
	while(1){
       i=read(fd,ch,sizeof(ch));
	
	if (i>0)
	    ch[i]='\0';
    else if(i==0)
		break;
	
    printf("%s:%s\n",user1,ch);}
	close(fd);
	return NULL;
}

void window(int fd){
	char ch;
    write(1,&ch,read(fd,&ch,1));}
