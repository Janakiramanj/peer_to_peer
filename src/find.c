#include"find.h"

int seek;

char* find(char* path,char* search_string){

	int fd = open(path,O_RDONLY,0777);
        if(fd<0){
	printf("%s doesn't Exist !!\n",path);
        return NULL;}

	int i=0;

    char ch;
    char* buff = malloc(30);
	
	
while(read(fd,&ch,1)){

	if((ch!=' ')&&(ch!='\n')&&(ch!='\t')){
	  buff[i] = ch;
	  i++;}
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

		if((ch==' ')||(ch=='\n')||(ch=='\t'))
		{

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
				if((ch!=' ')&&(ch!='\n')&&(ch!='\t')){
				buff[i]=ch;
				
				i++;}
			}
			buff[i+1]='\0';
			return buff;
		}
		
		}
		else
		lseek(fd,-1,SEEK_CUR);
	}
}

return NULL;
}

char* seeknfind(int fd,char* search_string){

    int i=0;
    char ch;
    char* buff = malloc(30);

while(read(fd,&ch,1)){

	if((ch!=' ')&&(ch!='\n')&&(ch!='\t')){
	  buff[i] = ch;
	  i++;}
	  
	else
	{
	           while(i){
			buff[i]='\0';
			i--;}
	           buff[i]='\0';
	}

	if(i==strlen(search_string))
	{
		
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
				if(read(fd,&ch,1)==0)
					break;
				if((ch!=' ')&&(ch!='\n')&&(ch!='\t')){
				buff[i]=ch;
				i++;}
			}
			buff[i+1]='\0';

			return buff;
		}

	}
}

return NULL;
}
