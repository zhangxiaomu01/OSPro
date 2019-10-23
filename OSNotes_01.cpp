//***************************************************************************
//1. Main types of operating system:
/*
- Batch OS
- Time sharing OS
- Distributed OS
- Network OS
- Real Time OS
- Multi-programming / processing / tasking OS
*/


//***************************************************************************
//2. Functions of operating system:
/*
- Interface between user and hardware;
- Allocation of resources;
- Management of memory, security etc.

The goal of OS is to make the usage of computer both convenient and efficient.
*/


//***************************************************************************
//3. Important terms related to OS:
/*
1)Bootstrap Program: The initial program that runs when a computer is powered up
                     or reboot.
    - It's stored in the ROM (read-only memory)
    - It must know how to load the OS and start executing that OS
    - It must locate and load the OS kernel into memory

2)Interrupt: The occurance of an event is typically signalled by an interrupt 
             from a hardware or software;
             Hardware may trigger an interrupt at anytime by sending a signal to
             the CPU, usally by the way of system bus.

3)System Call (Monitor Call): Software may trigger an interrupt by executing a 
                              special operation called system call!


- When a CPU is interrupted, it immediately stops what it is doing and immediately
transfers the execution to a fixed location (usually contains the starting 
address where the service routine of the interrupted is located);
- The interrupt service routine executes;
- On completion, the CPU resumes the interrupted computation.
*/


//***************************************************************************
//4. I/O structore
/*
A general-purpose computer system consists of CPUs and multiple device controllers
that are connected through a system bus.
- Each device controller(maintains local buffer storage and set of special purpose
registers) is in charge of specific type of device.
- Typically, operating system has a device driver for each device controller. The
driver can understand the device controller and present a uniform interface of
the device to the rest of the operating system.

Working of an I/O operation:
1) To start the I/O operation, the device driver loads the appropriate registers
within the device controller;
2) The device controller, in turn, examine the contents of these registers and 
decide which action to take;

//Default transformation
3) The controller starts the transfer of data from the device to the local buffer;
4) Once the transfer of the data completes, the device controller informs the 
device driver via an interrupt that it has finished the operation;
5) The device driver then returns control to the operating system.

This form of interrupt driven I/O is fine for moving small amount of data but can
produce high overhead when used for bulk data movement. To solve this problem,
direct memory access (DMA) is used!

//With DMA, we can start from 1 - 2 - 6 - 7 - 8 here. Much faster.
6) After setting up buffers, pointers and counters for the I/O device, the device
controller transfers an entire block of data directly to or from its own storage
to memory, with no intervention by the CPU.

7) Only one interrupt has been generated per block, to tell the device driver 
that the operation has been completed;

8) While the device controller is performing its operations, CPU is still 
available for other tasks.

*/


//***************************************************************************
//5. Computer System Architecture
/*
Types of computer systems based on the number of General Purpose Processors:
a) Single Processor System
    - One main CPU capable of executing a general purpose instruction set, 
    including instructions from user processes.
    - Other special purpose processors are also present which perform device
    specific task.


b) Multiprocessor System
    - Has two or more processors in close communication, sharing the computer 
    bus and sometimes the clock, memory and peripheral devices.
    - Also known as parallel systems or tightly coupled systems.
    
    Advantages: 
    1) Increased throughput 
    2) Economy of scale
    3) Increased reliability

    Type of multiprocessor system:
    -Symmetric Multiprocessing
        All processors perform similar tasks!
    -Asymmetric Multiprocessing
        One master processor + multiple slave processors!


c)Clustered System
    - Like multiprocessor system, clustered systems gather together multiple 
    CPUs to accomplish computational work.
    - They are composed of two or more individual systems coupled together.
    - Provides high availability.
    - Can be structured asymmetrically or symmetrically.
        -asymmetrical mode:
            1) One machine in hot-standby mode
            2) Others run applications
        -symmetrical mode (preferred):
            1) Two or more hosts run applications
            2) Monitor each other

*/


//***************************************************************************
//6. Operating system structure - Multiprogramming && Multitasking
/*
a) Multiprogramming
    - A single user cannot, in general, keep either the CPU or the I/O device
    busy all the time;
    - Multiprogramming increases CPU utilization by organizing jobs (code and 
    data) so that CPU always has one to execute.
    - Multiprogramming does not provide for the user interaction with the 
    computer system.

b) Multitasking (time-sharing system)
    - CPU executes multiple tasks by switching among them;
    - Switch occurs so frequently that users can interact with each program while
    it is running;
    - Time-sharing requires an interactive (hands-on) computer system, which 
    provides direct communication between the user and the system;
    - A time-sharing operating system allows many users to share the computer
    simultaneously.
        - Each user has at least one separate program in memory;
        - A program that loaded into memory and executing is called a "process"

*/



//***************************************************************************
//7. Operating system service
/*
- User interface (Command line interface vs. Graphic user interface)
- Program execution
- I/O operation
- File system manipulation
- Communications
- Error detection
- Resource allocation
- Accounting
- Protection and security
*/


//***************************************************************************
//8. System calls
/*
System calls provide an interface to the services made available by an operating
system.
System call is a programmatic way in which the computer program requests a 
service from the kernel of the OS. These calls are generally available as routines
written in C and C++. 

Types of system calls:
a) Process Control
    - end, abort
    - load, execute
    - create or terminate process
    - get / set process attributes
    - wait for time
    - wait event, signal event
    - allocate / free memory

b) File Manipulation
    - Create / delete file
    - Open / close file
    - read / write / reposition file
    - get / set file attributes

c) Device Management
    - request / release device
    - read / write / reposition device
    - get / set device attributes
    - logically attach / detach devices

d) Information Maintenance
    - get / set time or date
    - get / set system data
    - get / set process, file and device attributes

e) Communications
    - create / delete communication connection
    - send / receive messages
    - transfer status information
    - attach / detach remote devices
*/


//***************************************************************************
//9. System programs
/*
An important aspect of modern system is the collection of system programs.
- System program provides an convenient environment for program development and
execution;

Some system programs can be divided into the following categories:
    - File Management
        - Create, delete, copy, rename, print, dump.
        - List and generally manipulate files and directories.
    - Status Information
        - Data, time
        - Amount of available memory or disk space
        - Number of users
        - Detailed performance
        - Logging and debugging information etc.
    - File Modification
        - Modify the content of the file
        - Transformation of the file
    - Programming language support
        - Compiler, Assemblers, Debuggers and Interpreters
        (Common programming language such as C, C++, Java or VB are often provided
        to the user with the operating system) 
    - Program loading and executing
        The system may provide: 
            a) Absolute loaders b) Reloacate loaders
            c) Linkage editors  d) Overlay loaders
        Debugging systems for either high-level language or machine language are
        needed as well.
    - Communications
        Creating virtual connections between processes, users or computer systems.
*/


//***************************************************************************
//10. Operating system design & implementation
/*
1. Design goals:
First problem: Defining goals and specification
    - Choice of hardware
    - Types of system
Beyond this highest design level, the requirements may be much harder to specify.
Requirements:
    - User goal
    - System goal

A design principle: Always separate mechanism from policy.

Practical structures of OS:
1) Simple Structure
2) Monolithic Structure
3) Layered Structure
4) Microkernels Structure
5) Modules Structure

*/


//***************************************************************************
//11. Virtual Machine
/*
The fundamental idea behind the virtual machine is to abstract the hardware of 
a single computer (CPU, memory, disk drives, network interface card, and so forth)
into several different execution environment, thereby creating the illusion that
each separate execution environment is running its own private computer.

virtual machine implementation software - runs in actual kernel mode
virtual machine itself - runs in user mode (including virtual machine kernel 
                         mode and virtual machine user mode)

*/


//***************************************************************************
//12. Operating system generation and system boot
/*
A process sometimes known as system generation (SYSGEN) is used to configure or
generate operating system for specific computer site.

The following kinds of information must be determined by SYSGEN program:
- What CPU is to be used?
- How much memory is available?
- What devices are available?
- What operating system options are desired?


System boot:
The procedural of starting a computer by loading the kernel is known as booting.

On most computer systems, a small piece of code known as bootstrap program or 
bootstrap loader locates the kernel. This program is in the form of read-only
memory (ROM), because the RAM is an unknown state at system startup. ROM is 
convenient because it needs no initialization and cannot be infected by a computer
virus.

Firmware - A kind of read-only memory for small devices. (bootstrap program, even
OS can reside in it. Difficult to update!)


When the full bootstrap program has been loaded, it can traverse the file system
to find the OS kernel, load it into memory and start its execution. Only at this
point the system is said to be running!
*/


//***************************************************************************
//13. Process management (processes and threads)
/*
A process can be considered as a program in execution.

A thread is the unit of execution within a process. A process can have multiple
threads.

Process State: defined by the current activity of the process. During the execution
of the process, its state changes accordingly. 
- New state: The process is being created.
- Running state: Instructions are being executed.
- Waiting state: The process is waiting for some event to occur. (I/O or signal)
- Ready state: The process is waiting to be assigned to a processor.
- Terminated state: The process has finished execution.

New state => Admitted => Ready state;
Ready state => Scheduler dispatch => Running state;
Running state => Exit => Terminated state;
Running state => Interrupt => Ready state;
Running state => I/O or Event wait => Waiting state;
Waiting state => I/O or Event completion => Ready state;


Process control block (PCB): representation of a process in OS.
Content of PCB:
    - Process State
    - Process Number(ID)
    - Program Counter
    - Registers
    - Memory Limits
    - List of Open Files
    - CPU Scheduling Information
    - Memory Management Information
    - Accounting Information
    - I/O Status Information
    ...
*/


//***************************************************************************
//14. Process scheduling and context switch
/*
- The objective of multiprogramming is to have some processes running at all 
times, to maximum CPU utilization.
- The objective of time sharing is to switch the CPU among processes so 
frequently that users can interact with each program while it is running.
- To meet these objectives, the process scheduler selects an available process (
possibly from a set of available processes) for program execution on the CPU.
    - For single-processor system, there will never be more than one running  
    process; if there are more processes, the rest will have to wait until the 
    CPU is free and can be rescheduled.

Scheduling queues:
- Job queue: As processes enter the system, they are put into a job queue, which 
             consists of all processes in the system.
- Ready queue: The processes are residing in the main memory and are ready and 
               waiting to execute are kept on a list called the ready queue.


Context Switch:
Interrupts cause the operating system to change a CPU from its current task and 
to run a kernel routine. Such operations happen frequently on general-purpose
systems. 

When an interrupt occurs, the system needs to save the current *Context* of the 
process currently running on the CPU so that it can restore that context when 
the new required processing is done. (Suspending the process and then resume it)
The context is represented in the PCB of the process.

Switching the CPU to another process requires performing a state save of the 
current process and a state restore of different process (Context Switching).
    - Context-switch time is pure overhead, because the system does no useful 
    work while switching;
    - Its speed varies from machine to machine, depending on the memory speed,
    the number of registers that must be copied, and the existance of special
    instructions (such as a single instruction to store or load all registers).
    - Typical speed is a few milliseconds.

*/


//***************************************************************************
//15. Process creation and termination
/*
Process Creation:
- A process may create several new processes, via a create-process system call,
during the course of execution. Each of these new processes may create other 
processes, forming a tree of processes.
- When a process create a new process, two possibilities exist in terms of 
execution:
    a) The parent continue to execute concurrently with its children;
    b) The parent wait until some or all of the children have terminated.
- When a process create a new process, two possibilities exist in terms of 
address space:
    a) The child process is the duplicate of parent process (It has the same 
    program and data as the parent);
    b) The child process has a new program loaded into it.

Process Termination:
- A process terminates when it finishes executing its final statement and ask the
operating system to delete it by using the exit() system call.
- At that point, the process may return a status value (typically an integer) to
its parent process (via the wait() system call).
- All the resources of the process - including physical or virtual memory, open 
files, and I/O buffers - are deallocated by the operating system.

Termination can also occur in other circumstances as well:
- A process can cause the termination of another processes via an appropriate 
system call;
- Usually, such a system call can be invoked only by the parent of the process
that is to be terminated. Otherwise, processes could arbitrarily kill each 
other's jobs. 

A parent may terminate the execution of one of its children for a variaty of 
reasons, such as:
- The child has exceeded its usage of some of the resources that has been 
allocated (To determine whether this happens, the parent must have a mechanism
to inspect the status of the children);
- The task assigned to the child is no longer required;
- The parent is existing, and the OS does not allow a child to continue when its
parent terminates.
*/


//***************************************************************************
//16. Interprocess communication - shared memory && message passing
/*
Processes executing concurrently in the operating system may be either independent
process or cooperating process:
Independent processes - They cannot affect or be affected by other processes 
                        executing in the system;
Cooperating processes - They can affect or be affected by other processes 
                        executing in the system;
Any process that shares data with other processes is a cooperating process.

Reasons for providing process cooperation:
    - Information sharing
    - Computation speedup
    - Modularity
    - Convenience

Cooperating processes require an interprocess communication (IPC) mechanism that
will allow them to change data and information.
There are two fundumental models of interprocess communication:
- ** shared memory **
    - In the shared memory model, a region of memory that is shared by cooperating
    processes is established;
    - Processes can then exchange information by reading and writing data to the 
    shared region.
    - Typically, a shared memory resides in the address space of the process 
    creating the shared memory segment (processes which want to communicate 
    with other processes). Other processes want to communicate using this shared
    memory segment must attach it to their address space.

For example:
    Process A => write => shared memory => read => Process B

Normally, the operating system tries to prevent one process from accessing 
another process's memory. Shared memory requires that two or more processes agree
to remove this restriction.

Producer - consumer problem (A simple case, omit here).

Two kind of buffers: 
- Unbounded buffers 
    - Places no practical limit of the size of the buffer. The consumer may wait
    for new items, but the producer can always produce new item.

- Bounded buffers
    - Assumed a fixed buffer size. In this case, the consumer must wait if the 
    buffer is empty while the producer must wait if the buffer is full.



- ** message passing **
    - In the message passing model, communication takes place by means of messages
    exchange between the coorperating processes.

For example:
    Process A => message sending => kernel => message receiving => Process B

*/