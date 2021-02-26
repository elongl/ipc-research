# System V Message Queues

# Leads
- `msgrcv` does not have a second `ipc_valid_object` validation.


## Questions & Wonders
### Unanswered
- What happens if a filled message queue is truncated with msgctl to a smaller size
- Can you create a msqid that would result in a negative id
- What's the biggest `msg_ctlmax` that you can set in msgctl
- What happens if a process attempts to msgrcv while `free_msg::cond_resched`
- Will failing (goto) between (`ss_add`)[https://elixir.bootlin.com/linux/latest/source/ipc/msg.c#L899] and `ss_del` create a dangling sender 
- Why aren't atomic operations used (here)[https://elixir.bootlin.com/linux/latest/source/ipc/msg.c#L934]
- What happens if you specify both `MSG_COPY` and `MSG_NOERROR` no `msgrcv`. Especially if `bufsz` is smaller than `msg->m_ts`

### Answered


## TODOs
- [x] Deepen into RCU.


## Code Auditing
- [x] msgsnd
- [ ] msgrcv
- [ ] msgget
- [ ] msgctl

