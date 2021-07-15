# Adding-System-Call-to-Linux-Kernel
Adding a system call to a linux kernel

# Goal
In this project, I will implement a system call to linux kernel and then I will build this
kernel. After building, I will call my own system call in my code is working into user space. The
detailed scenario is given in the below.

# Implementation Details & Requirements
My code running into user space should run the system call is named as “systeminfo”. My
code will take two parameters as -p and -all. Firstly, it prints information about CPU such as
processor, vendor id, CPU family, model name, CPU MHz.

Additionally, it may be taken as same or different time optionally the following parameters:

● “-p processID”, it prints some details about the given process ID such as user, pid,
start_time, command.

● “-all”, it prints the length of time since the system was booted, as well as the amount of
time since then that the system has been idle, the number of active tasks on the system and
and the total number of processes on the system.

The sample executing formats:

./systeminfo.out > only CPU information

./systeminfo.out -all > CPU+system statistics

./systeminfo.out -p 1425 > CPU+process detail

./systeminfo.out -all -p 1425 > CPU+sys.statistics+ps.detail

The sample output should be like that, if two parameters were used:

CPU Information:

vendor_id : xx

cpu family : xx

model : xx

model name : xx

Parameter#[process_id]-Process Information:

name: xx

state: xx

uid : xx

pid : xx

ppid : xx

Parameter#all-System Statistics:

system was booted since : xx

system has been idle since : xx

the number of active tasks : xx

the total number of processes : xx
![Screenshot](https://user-images.githubusercontent.com/50989796/125800333-30c5eda4-bd47-43e4-99e1-59a398bdd8ce.png)

