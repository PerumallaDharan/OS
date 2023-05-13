# Operating Systems Project

## Project Description
- This project is a simulation of a CPU scheduler, Disc Scheduler,Deadlock Handler and Page Replacer all at a place for your convenience. 
- The project is written in C++ and uses the algorithms of the above mentioned schedulers to simulate the working of the schedulers.
- Can be used to understand the working of the schedulers and the algorithms used in them even for a beginner.
- The project is divided into 4 parts
    - CPU Scheduler
    - Disc Scheduler
    - Deadlock Handler
    - Page Replacer
- Each part has its own folder in the src folder
    - CPU Scheduler
        - [FCFS](https://github.com/PerumallaDharan/Operating_Systems/blob/master/Project/src/Header_Files/CPU_Scheduling_Headers/fcfs.h)
        - [SJF](https://github.com/PerumallaDharan/Operating_Systems/blob/master/Project/src/Header_Files/CPU_Scheduling_Headers/sjf.h)
        - [Priority](https://github.com/PerumallaDharan/Operating_Systems/blob/master/Project/src/Header_Files/CPU_Scheduling_Headers/priority.h)
        - [Preemptive Priority](https://github.com/PerumallaDharan/Operating_Systems/blob/master/Project/src/Header_Files/CPU_Scheduling_Headers/preemptive.h)
        - [Round Robin](https://github.com/PerumallaDharan/Operating_Systems/blob/master/Project/src/Header_Files/CPU_Scheduling_Headers/roundrobin.h)
    - Disc Scheduler
        - [FCFS](https://github.com/PerumallaDharan/Operating_Systems/blob/master/Project/src/Header_Files/Disc_Scheduling_Headers/pagefcfs.h)
        - [SSTF](https://github.com/PerumallaDharan/Operating_Systems/blob/master/Project/src/Header_Files/Disc_Scheduling_Headers/pagesstf.h)
        - [SCAN](https://github.com/PerumallaDharan/Operating_Systems/blob/master/Project/src/Header_Files/Disc_Scheduling_Headers/pagescan.h)
        - [LOOK](https://github.com/PerumallaDharan/Operating_Systems/blob/master/Project/src/Header_Files/Disc_Scheduling_Headers/pagelook.h)
    - Deadlock Handler
        - [Producer Consumer](https://github.com/PerumallaDharan/Operating_Systems/blob/master/Project/src/Header_Files/Deadlocks_Headers/producer_consumer.h)
        - [Banker's Algorithm](https://github.com/PerumallaDharan/Operating_Systems/blob/master/Project/src/Header_Files/Deadlocks_Headers/banker.h)
    - Page Replacer
        - [FIFO](https://github.com/PerumallaDharan/Operating_Systems/blob/master/Project/src/Header_Files/Page_Replacement_Headers/fifo.h)
        - [LRU](https://github.com/PerumallaDharan/Operating_Systems/blob/master/Project/src/Header_Files/Page_Replacement_Headers/lru.h)
        - [Optimal](https://github.com/PerumallaDharan/Operating_Systems/blob/master/Project/src/Header_Files/Page_Replacement_Headers/optimal.h)
        - [LFU](https://github.com/PerumallaDharan/Operating_Systems/blob/master/Project/src/Header_Files/Page_Replacement_Headers/lfu.h)

<hr>

## How to run the project
- Clone the repository
    ```bash
    $ git clone https://github.com/PerumallaDharan/Operating_Systems.git
    ```
- Open the project in Visual Studio
- First go the folder where the project is cloned
    ```bash
    $ cd Project
    $ cd src
    ```
- Run the main.cpp file
    ```bash
    $ g++ main.cpp
    ```
- Run the executable file
    ```bash
    $ ./a.exe
    ```

<hr>

## Project Structure
- The project is divided into 4 parts
    - CPU Scheduler
    - Disc Scheduler
    - Deadlock Handler
    - Page Replacer
- Each part has its own folder in the src folder
- Each part describes about the algorithm used and the implementation of the algorithm in C++.

- The main.cpp file is the driver file which calls the functions of each part and displays the output.

<hr>

## Team Members
- [Perumalla Dharan](https://github.com/PerumallaDharan)        
- [Tarun Teja Kudeti]()       
- [Subrahmanya Sastry N](https://github.com/PavanNVSS)   
- [Vatala Pahlgun](https://github.com/Vatala-Phalgun)          
- [Grandhi Dinesh](https://github.com/dinesh-grandhi)

<hr>

## Contributions
Contributions to this repository are welcome. If you find any bugs or would like to add additional algorithms or codes, feel free to create a pull request or open an issue.

<hr />

