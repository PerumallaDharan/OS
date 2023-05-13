// Simulate First In First Out Page Replacement Algorithm

// Inintialising header files
#include <iostream>
using namespace std;

// Main function
int dofifo()
{
    // Taking input from the user
    int n;
    cout << "Enter the number of pages: ";
    cin >> n;

    // Taking input from the user
    int pages[n];
    cout << "Enter the pages: ";
    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }

    // Taking input from the user
    int cap;
    cout << "Enter the capacity of the frame: ";
    cin >> cap;

    // Initialising the frame
    int frame[cap];
    for (int i = 0; i < cap; i++)
    {
        frame[i] = -1;
    }

    // Simulating FIFO Page Replacement Algorithm
    int page_fault = 0;
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = 0; j < cap; j++)
        {
            if (frame[j] == pages[i])
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            frame[index] = pages[i];
            index = (index + 1) % cap;
            page_fault++;
        }
    }

    // Printing the result
    cout << "Number of page faults: " << page_fault << endl;
}