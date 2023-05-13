// Initialising the header files
#include <iostream>
using namespace std;

// Producer function
int producer(int &mutex, int &empty, int &full)
{
    // Decrement the mutex variable
    mutex--;
    // Decrement the empty variable
    empty--;
    // Increment the full variable
    full++;
    // Print a message to indicate that the producer has produced an item
    cout << "Producer produces the item" << endl;
    // Increment the mutex variable
    mutex++;
}

// Consumer function
int consumer(int &mutex, int &empty, int &full)
{
    // Decrement the mutex variable
    mutex--;
    // Decrement the full variable
    full--;
    // Increment the empty variable
    empty++;
    // Print a message to indicate that the consumer has consumed an item
    cout << "Consumer consumes the item" << endl;
    // Increment the mutex variable
    mutex++;
}

// Main function
int producer_consumer()
{
    // Declare variables
    int n, mutex = 1, full = 0, empty = 3, x = 0;

    // Get the number of items from the user
    cout << "Enter the number of items: ";
    cin >> n;

    // While there are still items to produce or consume
    while (n != 0)
    {
        // Print a menu of options to the user
        cout << "1. Producer\n2. Consumer\n3. Exit" << endl;

        // Get the user's choice
        cout << "Enter your choice: ";
        cin >> x;

        // Switch on the user's choice
        switch (x)
        {
        case 1:
            // If the user chooses to produce an item
            if ((mutex == 1) && (empty != 0))
            {
                // Call the producer function
                producer(mutex, empty, full);
            }
            else
            {
                // Print a message to indicate that the buffer is full
                cout << "Buffer is full" << endl;
            }
            break;
        case 2:
            // If the user chooses to consume an item
            if ((mutex == 1) && (full != 0))
            {
                // Call the consumer function
                consumer(mutex, empty, full);
            }
            else
            {
                // Print a message to indicate that the buffer is empty
                cout << "Buffer is empty" << endl;
            }
            break;
        case 3:
            // If the user chooses to exit
            exit(0);
            break;
        default:
            // If the user enters an invalid choice
            cout << "Invalid choice" << endl;
            break;
        }
        n--;
    }
}