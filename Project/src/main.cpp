// CPU scheduling algorithms
// • First Come First Serve
// • Shortest Job First
// • Priority
// • Round Robin
// Semaphore and Deadlock
// • write a C program to implement the Producer & consumer Problem using Semaphore.
// • Write a C program to simulate Bankers algorithm for the purpose of deadlock avoidance.
// Page Replacement Algorithms
// • First In First Out
// • Least Recently Used
// • Optimal
// • Least Frequently Used
// • Second Chance

#include <iostream>
#include "Header_Files\CPU_header.h"
#include "Header_Files\Page_header.h"
#include "Header_Files\Disc_header.h"
using namespace std;

int main()
{
    int n;
    while (true)
    {
        cout << "Welcome" << endl;
        cout << "Choose any one of the following" << endl;
        cout << "1. CPU Scheduling Algorithms" << endl;
        cout << "2. Page Replacement Algorithms" << endl;
        cout << "3. Disk Scheduling Algorithms" << endl;
        cout << "4. Semaphores and Deadlocks" << endl;
        cout << "5. File Allocation Techniques" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> n;
        switch (n)
        {
        case 1:
            cpu_menu();
            break;
        case 2:
            page_menu();
            break;
        case 3:
            disc_menu();
            break;
        default:
            break;
        }
    }
}
