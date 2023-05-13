// Initialising the header files
#include <iostream>
using namespace std;

// Creating a structure for the process
struct priority
{
    int id, burst_time, wait_time, comp_time, tat_time, priority;
};

// Function to display the process
void display(priority p[], int n)
{
    cout << "PID\tBT\tCT\tTAT\tWT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << p[i].id << "\t" << p[i].burst_time << "\t"
             << p[i].comp_time << "\t" << p[i].tat_time << "\t" << p[i].wait_time << endl;
    }
}

// Function to implement the priority scheduling
void dopriority()
{
    // Taking the input
    int n;
    cout << "Enter number of process = " << endl;
    cin >> n;

    // Creating an array of process
    priority pro[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the process id = " << endl;
        cin >> pro[i].id;
        cout << "Enter burst time of process = ";
        cin >> pro[i].burst_time;
        cout << "Enter the priority of the process = ";
        cin >> pro[i].priority;
        pro[i].comp_time = 0;
        pro[i].tat_time = 0;
        pro[i].wait_time = 0;
    }

    // Sorting the process based on priority
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (pro[j].priority < pro[min].priority)
            {
                min = j;
            }
        }
        swap(pro[min], pro[i]);
    }

    // Calculating the completion time, turnaround time and waiting time
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        // pro[i].wait_time = total;
        // pro[i].tat_time = pro[i].wait_time + pro[i].burst_time;
        // pro[i].comp_time = total + pro[i].burst_time;
        // total = total + pro[i].burst_time;
        total += pro[i].burst_time;
        pro[i].comp_time = total;
        pro[i].tat_time = pro[i].comp_time;
        pro[i].wait_time = pro[i].tat_time - pro[i].burst_time;
    }
    display(pro, n);

    // Calculating the average waiting time and average turnaround time
    float avg_wait_time = 0, avg_tat_time = 0;
    for (int i = 0; i < n; i++)
    {
        avg_wait_time += pro[i].wait_time;
        avg_tat_time += pro[i].tat_time;
    }
    cout << "Average waiting time = " << avg_wait_time / n << endl;
    cout << "Average turnaround time = " << avg_tat_time / n << endl;
}
