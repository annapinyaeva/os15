#include "common.h"
#define MESSAGE "Hello Server!!!\n"
int
 main()
 {
int writefd;
int msglen;
int count;
char message[10];
long long int;
for (count=0; count<=5; ++count) {
sleep(5);
T=(long long int) time(0);
sprintf(message,"%lli",T);
message[9]='\n';
printf("FIFO Client...\n");
if ((writefd=open(FIFO_NAME,O_WRONLY))<0)
{ fprintf(stderr, "%s: It is impossible to open FIFO (%s)\n",
    __FILE__,strerror(errno));
exit(-1);}
msglen=strlen(MESSAGE);
if(write(writefd,MESSAGE,msglen)!=msglen)
{ fprintf(stderr,"%s: Error writing in FIFO (%s)\n",
	__FILE__,strerror(errno));
    exit(-2);}
close(writefd);
exit(0);
}
}