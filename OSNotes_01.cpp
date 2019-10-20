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

