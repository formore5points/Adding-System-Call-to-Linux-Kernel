#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
if(argc==0) 
{
long int amma = syscall(335);
printf("System call cpuinfo returned %ld\n", amma);
}
if(argc==1) 
{ 

} 
if(argc==2) 
{ 
pid_t pid = argv[2];

long int amma = syscall(335,pid);
} 
if(argc==3) 
{ 

}
return 0;
}
