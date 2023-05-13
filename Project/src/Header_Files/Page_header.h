
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
    cout << "-----------------------------------------Page Replacement Algorithms-----------------------------------------" << endl;
    cout << "                                   Choose any one of the following" << endl;
    cout << "                                   1. First In First Out" << endl;
    cout << "                                   2. Least Recently Used" << endl;
    cout << "                                   3. Optimal" << endl;
    cout << "                                   4. Least Frequently Used" << endl;
    cout << "                                   5. Exit" << endl;
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
            cout<<"Invalid Choice"<<endl;
            break;
    }
}