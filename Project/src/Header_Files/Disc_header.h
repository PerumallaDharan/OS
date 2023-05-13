
// Disk Scheduling Algorithms
// • FCFS
// • SSTF
// • SCAN
// • LOOK


#include <iostream>
#include "Disc_Scheduling_Headers\pagefcfs.h"
#include "Disc_Scheduling_Headers\pagesstf.h"
#include "Disc_Scheduling_Headers\pagescan.h"
#include "Disc_Scheduling_Headers\pagelook.h"
using namespace std;

int disc_menu()
{
    int n;
    cout << "------------------------------------------------------------------------------------------------------------" << endl;
    cout << "-----------------------------------------Disk Scheduling Algorithms-----------------------------------------" << endl;
    cout << "------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\tChoose any one of the following" << endl;
    cout << "\t\t\t\t\t1. FCFS" << endl;
    cout << "\t\t\t\t\t2. SSTF" << endl;
    cout << "\t\t\t\t\t3. SCAN" << endl;
    cout << "\t\t\t\t\t4. LOOK" << endl;
    cout << "\t\t\t\t\t5. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> n;
    system("cls");
    switch (n)
    {
    case 1:
        dopagefcfs();
        break;
    case 2:
        dopagesstf();
        break;
    case 3:
        dopagescan();
        break;
    case 4:
        dopagelook();
        break;
    case 5:
        exit(0);
        break;
    default:
        break;
    }
}