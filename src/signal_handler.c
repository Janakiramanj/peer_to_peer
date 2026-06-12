#include"s_gnal.h"

void end_conv(int sig)
{
	int fd = open("./data/userdata.md",O_RDWR,0777);
	while(replaceafterfindnseek(fd,"PID","NULL"));
	_exit(0);
}