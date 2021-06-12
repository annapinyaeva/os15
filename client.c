#include "common.h"
#define MESSAGE "Hello Server!!!\n"

int main()
{
int writefd;
int msglen;
printf("FIFO Client...\n");
if((writefd=open(FIFO_NAME,O_WRONLY))<0)
{
fprintf(stderr,"%s:It is impossible to open FIFO (%s)\n",
    __FILE__,strerror(errno));
exit(-1);
}
msglen=strlen(MESSAGE);
if(write(writefd,MESSAGE,msglen)!=msglen)
{
fprintf(stderr,"%s: Error writing in FIFO (%s)\n",
	__FILE__,strerror(errno));
exit(-2);
}
close (writefd);
exit(0);
}