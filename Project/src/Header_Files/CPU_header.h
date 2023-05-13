
// CPU scheduling algorithms
// • First Come First Serve
// • Shortest Job First
// • Priority
// • Preemptive Priority
// • Round Robin


#include <iostream>
#include "CPU_Scheduling_Headers\fcfs.h"
#include "CPU_Scheduling_Headers\sjf.h"
#include "CPU_Scheduling_Headers\priority.h"
#include "CPU_Scheduling_Headers\preemptive.h"
#include "CPU_Scheduling_Headers\roundrobin.h"
using namespace std;

int cpu_menu()
{
    int n;
    cout << "-----------------------------------------------------------------------------------------------------------" << endl;
    cout << "-----------------------------------------CPU Scheduling Algorithms-----------------------------------------" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\tChoose any one of the following" << endl;
    cout << "\t\t\t\t\t1. FCFS" << endl;
    cout << "\t\t\t\t\t2. SJF" << endl;
    cout << "\t\t\t\t\t3. Priority" << endl;
    cout << "\t\t\t\t\t4. Preemptive Priority (Priority is assigned randomly)" << endl;
    cout << "\t\t\t\t\t5. Round Robin" << endl;
    cout << "\t\t\t\t\t6. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> n;
    system("cls");
    switch (n)
    {
    case 1:
        dofcfs();
        break;
    case 2:
        dosjf();
        break;
    case 3:
        dopriority();
        break;
    case 4:
        doprepriority();
        break;
    case 5:
        doroundrobin();
        break;
    case 6:
        exit(0);
    default:
        cout << "Invalid choice" << endl;
        break;
    }
}
