
// Semaphore and Deadlock
// • Producer Consumer Problem using Semaphores
// • Bankers Algorithm


#include <iostream>
#include "Deadlocks_Headers\producer_consumer.h"
#include "Deadlocks_Headers\banker.h"
using namespace std;

int deadlocks_menu(){
    int n;
    cout << "----------------------------------------------------------------------------------------------------------" << endl;
    cout << "-----------------------------------------Semaphores and Deadlocks-----------------------------------------" << endl;
    cout << "----------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\tChoose any one of the following" << endl;
    cout << "\t\t\t\t\t1. Producer Consumer Problem using Semaphores" << endl;
    cout << "\t\t\t\t\t2. Bankers Algorithm" << endl;
    cout << "\t\t\t\t\t3. Exit" << endl;
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