#include <iostream>
using namespace std;

// Creating a structure for process
struct sjf
{
    int id;
    int bt;
    int waiting_time;
    int turnaround_time;
    int completion_time;
};

// Function to implement SJF
void dosjf()
{
    // Taking the input
    int n;
    cout << "Enter the number of process: ";
    cin >> n;

    // Creating an array of processes
    sjf pro[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the process ID: ";
        cin >> pro[i].id;
        cout << "Enter the burst time for process: ";
        cin >> pro[i].bt;
        pro[i].waiting_time = 0;
        pro[i].turnaround_time = 0;
        pro[i].completion_time = 0;
    }

    // Sorting the processes based on burst time
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (pro[j].bt < pro[min].bt)
            {
                min = j;
            }
        }
        swap(pro[min], pro[i]);
    }

    // Calculating the completion time, turnaround time and waiting time
    int total_time = 0;
    cout << "Process\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << pro[i].id << "\t" << pro[i].bt << "\t\t";
        int waiting_time = total_time;
        cout << waiting_time << "\t\t";
        int turnaround_time = waiting_time + pro[i].bt;
        cout << turnaround_time << "\t\t";
        int completion_time = total_time + pro[i].bt;
        cout << completion_time << endl;
        total_time += pro[i].bt;
    }

    // Calculating the average waiting time and average turnaround time
    cout << "Average waiting time: " << (float)total_time / n << endl;
    cout << "Average turnaround time: " << (float)total_time / n << endl;
}
