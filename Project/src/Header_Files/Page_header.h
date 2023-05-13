
// Page Replacement Algorithms
// • First In First Out
// • Least Recently Used
// • Optimal
// • Least Frequently Used

#include <iostream>
#include "Page_Replacement_Headers\fifo.h"
#include "Page_Replacement_Headers\lru.h"
#include "Page_Replacement_Headers\optimal.h"
#include "Page_Replacement_Headers\lfu.h"
using namespace std;

int page_menu()
{
    int n;
    cout << "-------------------------------------------------------------------------------------------------------------" << endl;
    cout << "-----------------------------------------Page Replacement Algorithms-----------------------------------------" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\tChoose any one of the following" << endl;
    cout << "\t\t\t\t\t1. First In First Out" << endl;
    cout << "\t\t\t\t\t2. Least Recently Used" << endl;
    cout << "\t\t\t\t\t3. Optimal" << endl;
    cout << "\t\t\t\t\t4. Least Frequently Used" << endl;
    cout << "\t\t\t\t\t5. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> n;
    system("cls");
    switch (n)
    {
    case 1:
        dofifo();
        break;
    case 2:
        dolru();
        break;
    case 3:
        dooptimal();
        break;
    case 4:
        dolfu();
        break;
    case 5:
        exit(0);
        break;
    default:
        cout << "Invalid Choice" << endl;
        break;
    }
}