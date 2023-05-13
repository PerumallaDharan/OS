
// Semaphore and Deadlock
// • Producer Consumer Problem using Semaphores
// • Bankers Algorithm


#include <iostream>
#include "Deadlocks_Headers\producer_consumer.h"
#include "Deadlocks_Headers\banker.h"
using namespace std;

int deadlocks_menu(){
    int n;
    cout << "-----------------------------------------Semaphores and Deadlocks-----------------------------------------" << endl;
    cout << "                                   Choose any one of the following" << endl;
    cout << "                                   1. Producer Consumer Problem using Semaphores" << endl;
    cout << "                                   2. Bankers Algorithm" << endl;
    cout << "                                   3. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> n;
    system("cls");
    switch (n)
    {
    case 1:
        producer_consumer();
        break;
    case 2:
        banker();
        break;
    case 3:
        exit(0);
        break;
    default:
        cout << "Invalid choice" << endl;
        break;
    }
}