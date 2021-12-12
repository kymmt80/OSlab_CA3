#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int
sys_set_hrrn_for_system(void){
  int inp;
  if(argint(0, &inp) < 0)
    return -1;
  set_hrrn_for_system(inp);
}
int
sys_set_hrrn_for_process(void){
  int inp,pid;
  if(argint(0, &pid) < 0)
    return -1;
  if(argint(1, &inp) < 0)
    return -1;
  set_hrrn_for_process(pid,inp);
}
int
sys_print_all_information(void){
  print_all_information();
}
int
sys_change_process_queue(void){
  int inp,pid;
  if(argint(0, &pid) < 0)
    return -1;
  if(argint(1, &inp) < 0)
    return -1;
  change_process_queue(pid,inp);
}
