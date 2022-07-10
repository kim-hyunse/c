
#include <stdio.h>
#include "schedule.h"

#define MAX_PROC_NUM 100
#define PROC_STATE_INIT 0
#define PROC_STATE_READY 1
#define PROC_STATE_RUNNING 2
#define PROC_STATE_TERMINATE 3

typedef struct process_
{
	int pid;
	int state;
	int begin_time;
	int burst_time;
	int remaining_time;
	int response_time;
	int finish_time;
}Process;

Process proc_list[MAX_PROC_NUM];

int processor;
int method;
int cpu_use = -1;
int preemptive = 0;

void set_schedule(int m)
{
	method = m;
	if (m == 3)
	{
		preemptive = 1;
	}
}

void read_proc_list(const char* file_name)
{
	//read file list
	FILE* file = fopen(file_name, "r");
	fseek(file, 0, SEEK_SET);
	fscanf(file, "%d", &processor);
	for (int i = 0; i < processor; i++)
	{
		fscanf(file, "%d %d %d", &proc_list[i].pid, &proc_list[i].begin_time, &proc_list[i].burst_time);
		proc_list[i].state = PROC_STATE_INIT;
		proc_list[i].finish_time = 10000;
		proc_list[i].response_time = 10000;
		proc_list[i].remaining_time = proc_list[i].burst_time;
	}
	fclose(file);
}

void non_preemptive_switch()
{
	int index = -1;
	int value = 10000;

	for (int i = 0; i < processor;i++)
	{
		if (proc_list[i].state == PROC_STATE_READY)
		{
			int val;
			//FCFS
			if (method == 1)
			{
				val = proc_list[i].begin_time;
			}
			//SJF
			else if (method == 2)
			{
				val = proc_list[i].burst_time;
			}
			if (val< value)
			{
				value = val;
				index = i;
			}

		}
	}
	if (index > -1)
	{
		proc_list[index].state = PROC_STATE_RUNNING;
	}
	cpu_use = index;

	return;
}

void preemptive_switch()
{
	int index = -1;
	int value = 10000;

	for (int i = 0; i < processor;i++)
	{
		if ((proc_list[i].state == PROC_STATE_READY)||(proc_list[i].state == PROC_STATE_RUNNING))
		{
			int val;
			if (method == 3)
			{
				proc_list[i].state = PROC_STATE_READY;
				val = proc_list[i].remaining_time;
			}
			if (val < value)
			{
				value = val;
				index = i;
			}

		}
	}
	if (index > -1)
	{
		proc_list[index].state = PROC_STATE_RUNNING;
	}
	cpu_use = index;

}

int check_terminate_all()
{
	//if terminate?
	int terminate_all = 1;
	for (int i = 0; i < processor; i++)
	{
		if (proc_list[i].state != PROC_STATE_TERMINATE)
		{
			terminate_all = 0;
			break;
		}
	}
	return terminate_all;
}

int do_schedule(int tick)
{
	if (check_terminate_all())
		return -1;
	int nready = 0;
	for (int i = 0; i < processor;i++)
	{
		if (proc_list[i].begin_time == tick)
		{
			proc_list[i].state = PROC_STATE_READY;
			nready = 1;
		}
	}
	if (cpu_use >= 0)
	{
		proc_list[cpu_use].remaining_time--;
		if (preemptive == 1)
		{
			preemptive_switch();
		}
		if (proc_list[cpu_use].remaining_time == 0)
		{
			proc_list[cpu_use].finish_time = tick;
			proc_list[cpu_use].state = PROC_STATE_TERMINATE;
			if (check_terminate_all())
				return -1;
			if (preemptive == 0)
			{
				non_preemptive_switch();
			}
			else if (preemptive == 1)
			{
				preemptive_switch();
			}
		}
	}
	else {
		if (nready)
		{
			if (preemptive == 0)
			{
				non_preemptive_switch();
			}
			else if (preemptive == 1)
			{
				preemptive_switch();
			}
		}
	}
	if (proc_list[cpu_use].response_time > tick)
	{
		proc_list[cpu_use].response_time = tick;
	}
	if (cpu_use > -1)
		return proc_list[cpu_use].pid;
	
	return 0;
}

void print_performance()
{
	int sum_turnaround = 0;
	int sum_wait = 0;
	int sum_response = 0;

	printf("\n==================================================================================================\n");
	printf(" PID        begin      finish      Turn around time    wating time        Response time   \n");
	printf("==================================================================================================\n");
	for (int i = 0; i < processor; i++)
	{
		int turnaround = proc_list[i].finish_time - proc_list[i].begin_time;
		int wait = proc_list[i].finish_time - proc_list[i].begin_time - proc_list[i].burst_time;
		int response = proc_list[i].response_time - proc_list[i].begin_time;
		sum_turnaround += turnaround;
		sum_wait += wait;
		sum_response += response;
		printf("%4d %10d %10d %12d %18d %19d\n", proc_list[i].pid, proc_list[i].begin_time, proc_list[i].finish_time, turnaround, wait, response);
	}
	printf("_________________________________________________________________________________________________\n");
	printf(" average:                %16.2f     %18.2f    %19.2f\n",
		(float)sum_turnaround / (float)processor,
		(float)sum_wait / (float)processor,
		(float)sum_response / (float)processor);
	printf("==================================================================================================\n");

}