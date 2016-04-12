#ifndef PROC_H
#define	PROC_H

#include <unistd.h>

int machine_init(struct statics * statics);
void get_system_info(struct system_info *info);
void read_one_proc_stat(pid_t pid, struct top_proc *proc);
char *format_next_process(struct top_proc *p);

#endif
