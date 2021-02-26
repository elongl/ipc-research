# System V Message Queues

## Questions

### Unanswered
- What happens if a filled message queue is truncated with msgctl to a smaller size
- Can you create a msqid that would result in a negative id
- What's the biggest `msg_ctlmax` that you can set in msgctl
- What happens if a process attempts to msgrcv while `free_msg::cond_resched`
- Will failing (goto) between (`ss_add`)[https://elixir.bootlin.com/linux/latest/source/ipc/msg.c#L899] and `ss_del` create a dangling sender 

### Answered



## TODOs

