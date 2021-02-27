#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>


#define ERR_EXIT(err) do { perror(err); exit(EXIT_FAILURE); } while (0)

#define MSQ_KEY 0x41414141
#define MTYPE 1
#define BUFSIZE 1024
#define TEXT "Hello World!"

struct msgbuf {
	long mtype;       /* message type, must be > 0 */
	char* mtext;      /* message data */
};


int main() {
	int msqid;
	char buf[BUFSIZE] = { TEXT };
	struct msgbuf msg = { MTYPE, buf };

	if ((msqid = msgget(MSQ_KEY, IPC_PRIVATE | IPC_CREAT | S_IRWXU)) < 0)
		ERR_EXIT("msgget");

	if (msgsnd(msqid, &msg, strlen(TEXT), 0) < 0)
		ERR_EXIT("msgsnd");

	if (msgrcv(msqid, &msg, BUFSIZE, MTYPE, 0) < 0)
		ERR_EXIT("msgrcv");

	printf("Text: %s\n", msg.mtext);

	if (msgctl(msqid, IPC_RMID, NULL) < 0)
		ERR_EXIT("msgctl");
}

