#include"find.h"
#include"conv.h"
#include"s_gnal.h"

int main()
{
	short int fd1,fd2,pid;
	char a[30],str[20],msg[100];
    pthread_t tx_th,rx_th;

    signal(SIGINT, end_conv);
	 
	fd1 = open("./data/userdata.md",O_CREAT|O_RDWR|O_APPEND,0777);
	if(fd1<0) return 1;
	
	printf("Enter your user name :");
	scanf("%s",a);
	add_user(a);
	
    pid = getpid();
	sprintf(str, "%d", pid);
	
    if(find("./data/userdata.md",a)!= NULL){
		printf("Existing user\n");
	    replaceafterfind("./data/userdata.md",a,str);}
    else{
	   fd2 = dup(1);
	   dup2(fd1,1);
	   printf("%s\n",a);
	   printf("PID:%d\n",pid);
       dup2(fd2,1);}
	
    if(check_user_availaibility("./data/userdata.md")){
    	tx_data tx_user;
	    tx_user.id = user1;
	    tx_user.msg =msg;
		
	int c;
    while ((c = getchar()) != '\n' && c != EOF)
	{
	} 
		
	while(1){
	    printf("\n%s:",a);

		fgets(tx_user.msg,sizeof(msg),stdin);
		
	    pthread_create(&rx_th,NULL,rx,a);
        pthread_create(&tx_th,NULL,tx,&tx_user);
		
		pthread_join(tx_th, NULL);
	    pthread_join(rx_th, NULL);
	}

	}

	replaceafterfind("./data/userdata.md",a,"NULL");
	
   return 1;
}
