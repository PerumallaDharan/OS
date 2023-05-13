#include <iostream>
#include "Disc_Scheduling_Headers\pagefcfs.h"
#include "Disc_Scheduling_Headers\pagesstf.h"
#include "Disc_Scheduling_Headers\pagescan.h"
#include "Disc_Scheduling_Headers\pagelook.h"
using namespace std;

int disc_menu()
{
    int n;
    cout << "Disk Scheduling Algorithms" << endl;
    cout << "Choose any one of the following" << endl;
    cout << "1. FCFS" << endl;
    cout << "2. SSTF" << endl;
    cout << "3. SCAN" << endl;
    cout << "4. LOOK" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> n;
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