#include"find.h"

void replaceafterfind(char* path,char* search_string,char* replace_string){

	int i=0;
    char ch;
	
	int fd = open(path,O_RDWR,0777);
	
	if(fd<0)
	    printf("referred path Doesn't Exist !!\n");
	
#ifdef peer_to_peer	
	if(seeknfind(fd,search_string) == NULL){
	   printf(" contact is not registered ");
	   exit(0);}
	
	search_string="PID";
#endif

	char* buff = malloc(30);
	
while(read(fd,&ch,1)){
	
	if((ch!=' ')&&(ch!='\n')&&(ch!='\t')){
	  buff[i] = ch;
	  i++;
	}
	else
	{
	        while(i){
		     	buff[i]='\0';
			    i--;}
	        buff[i]='\0';
	}

	if(i==strlen(search_string))
	{
		
		read(fd,&ch,1);

		lseek(fd,-1,SEEK_CUR);
		buff[i+1]='\0';
		
		if(strcmp(search_string,buff))
		{
			while(i){
				buff[i]='\0';
				i--;}
			buff[i]='\0';
		}
		else
		{	
			while(i){
				buff[i]='\0';
				i--;}
			buff[i]='\0';

			while((ch!='\n'))
			{
				read(fd,&ch,1);
				buff[i]=ch;
				i++;
			}
			
			i=i-2;
				if(i==strlen(replace_string)){
					lseek(fd,-(i+1),SEEK_CUR);
				    write(fd,replace_string,strlen(replace_string));
					write(fd,"\n",1);
					break;}
				else{
					lseek(fd,-(i+1),SEEK_CUR);
					write(fd,replace_string,strlen(replace_string));
					
					lseek(fd,-1,SEEK_CUR);
					read(fd,&ch,1);
					
					while((ch!='\n')&&(ch!='\0')){
					read(fd,&ch,write(fd,"\0",1));
					}
				    break;}
		}

	}
} 
}

int replaceafterfindnseek(int fd,char* search_string,char* replace_string){

	int i=0;
    char ch;
	
	if(fd<0)
	    printf("referred path Doesn't Exist !!\n");

	char* buff = malloc(30);
	
while(read(fd,&ch,1)){
	
	if((ch!=' ')&&(ch!='\n')&&(ch!='\t')){
	  buff[i] = ch;
	  i++;
	}
	else
	{
	        while(i){
		     	buff[i]='\0';
			    i--;}
	        buff[i]='\0';
	}

	if(i==strlen(search_string))
	{
		
		read(fd,&ch,1);

		lseek(fd,-1,SEEK_CUR);
		buff[i+1]='\0';
		
		if(strcmp(search_string,buff))
		{
			while(i){
				buff[i]='\0';
				i--;}
			buff[i]='\0';
		}
		else
		{	
			while(i){
				buff[i]='\0';
				i--;}
			buff[i]='\0';

			while((ch!='\n'))
			{
				read(fd,&ch,1);
				buff[i]=ch;
				i++;
			}
			
			i=i-2;
				if(i==strlen(replace_string)){
					lseek(fd,-(i+1),SEEK_CUR);
				    write(fd,replace_string,strlen(replace_string));
					write(fd,"\n",1);
					break;}
				else{
					lseek(fd,-(i+1),SEEK_CUR);
					write(fd,replace_string,strlen(replace_string));
					
					lseek(fd,-1,SEEK_CUR);
					read(fd,&ch,1);
					
					while((ch!='\n')&&(ch!='\0')){
					read(fd,&ch,write(fd,"\0",1));
					}
				    break;}
		}

	}
} 

return read(fd,&ch,1);
}
