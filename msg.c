#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>

#define MSG_COPY        040000  /* copy (not remove) all queue messages */

#define ERR_EXIT(err) do { perror(err); exit(EXIT_FAILURE); } while (0)

#define MSQ_KEY 0x41414141
#define MTYPE 1
#define BUFSZ 1024
#define TEXT "Hello World!"

struct msgbuf {
	long mtype;
	char mtext[BUFSZ];
};


int main() {
	int msqid;
	ssize_t nread;
	struct msgbuf msg = { MTYPE, TEXT };

	if ((msqid = msgget(MSQ_KEY, IPC_PRIVATE | IPC_CREAT | S_IRWXU)) < 0)
		ERR_EXIT("msgget");

	if (msgsnd(msqid, &msg, strlen(msg.mtext), 0) < 0)
		ERR_EXIT("msgsnd");

	if ((nread = msgrcv(msqid, &msg, BUFSZ, MTYPE, 0)) < 0)
		ERR_EXIT("msgrcv");

	printf("[%lu] Text: %s\n", nread, msg.mtext);

	if (msgctl(msqid, IPC_RMID, NULL) < 0)
		ERR_EXIT("msgctl");
}

