#include "machine.h"
#include "proc.h"
#include <stdio.h>

int main()
{
	 struct statics stat;
	 machine_init(&stat);
	 struct system_info info;
	 struct top_proc proc;
	 
	 
	 //for(;;)
	 {
		 get_system_info(&info);
		 printf("load_avg:%.2f%%\n",(float)info.load_avg[0]);
		 printf("load_avg:%.2f%%\n",(float)info.load_avg[1]);
		 printf("load_avg:%.2f%%\n",(float)info.load_avg[2]);

		 printf("Used CPU:%.2f%%\n",(float)info.cpustates[0]/10);
		 printf("Nice CPU:%.2f%%\n",(float)info.cpustates[1]/10);
		 printf("System CPU:%.2f%%\n",(float)info.cpustates[2]/10);
		 printf("Idle CPU:%.2f%%\n",(float)info.cpustates[3]/10);
		 
		 printf("total memroy:%d\n", info.memory[0]);
		 printf("free memroy:%d\n", info.memory[1]);
		 printf("buffers:%d\n", info.memory[2]);
		 printf("cached:%d\n", info.memory[3]);
		 printf("total swap:%d\n", info.memory[4]);
		 printf("free swap:%d\n", info.memory[5]);
	
		 //sleep(2);
		 printf("..................................\n");

		 //get_system_info(&info);
		 
		 read_one_proc_stat( (pid_t)6464, &proc);

		 printf("time:%d\n", proc.time);
		 printf("pri:%d\n", proc.pri);
		 printf("nice:%d\n", proc.nice);
		 printf("size:%ld\n", proc.size);
		 printf("rss:%ld\n", proc.rss);

		 printf("..................................\n");
	
		 struct top_proc *p = &proc;
	
		 printf("%s\n",format_next_process(p));
	 }
	return 0;
}
