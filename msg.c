#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSQ_KEY 0x41414141
#define TEXT "Hello World!"

#define ERR_EXIT(err) do { perror(err); exit(EXIT_FAILURE); } while (0)

struct msgbuf {
	long mtype;       /* message type, must be > 0 */
	char* mtext;      /* message data */
};

int main() {
	int msqid;
	struct msgbuf msg = { 1, TEXT };

	if ((msqid = msgget(MSQ_KEY, IPC_PRIVATE | IPC_CREAT)) < 0)
		ERR_EXIT("msgget");

	if (msgsnd(msqid, &msg, strlen(TEXT), 0) < 0)
		ERR_EXIT("msgsnd");

	if (msgctl(msqid, IPC_RMID, NULL) < 0)
		ERR_EXIT("msgctl");
}

