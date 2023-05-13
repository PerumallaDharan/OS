// Operating System Project
//
// Group Members:
// 1. Perumalla Dharan        |      AP21110010201
// 2. Tarun Teja Kudeti       |      AP21110010205
// 3. Subrahmanya Sastry N    |      AP21110010209
// 4. Vatala Pahlgun          |      AP21110010223
// 5. Grandhi Dinesh          |      AP21110010240

#include <iostream>
#include "Header_Files\CPU_header.h"
#include "Header_Files\Page_header.h"
#include "Header_Files\Disc_header.h"
#include "Header_Files\Deadlocks.h"
using namespace std;

int main()
{
    int n;
    while (true)
    {
        cout << "----------------------------------------------------------------------------------------------------------" << endl;
        cout << "-----------------------------------------Operating System Project-----------------------------------------" << endl;
        cout << "----------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << "                                               Welcome" << endl;
        cout << "                                   Choose any one of the following" << endl;
        cout << "                                   1. CPU Scheduling Algorithms" << endl;
        cout << "                                   2. Page Replacement Algorithms" << endl;
        cout << "                                   3. Disk Scheduling Algorithms" << endl;
        cout << "                                   4. Semaphores and Deadlocks" << endl;
        cout << "                                   5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> n;
        system("cls");
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
        case 4:
            deadlocks_menu();
            break;
        default:
            break;
        }
    }
}
