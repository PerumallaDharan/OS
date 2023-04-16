#include <iostream>
using namespace std;

struct process
{
    int pid, burst_time, waiting_time, turnaround_time, completion_time;
};

int main()
{
    int n;
    cout << "Enter the number of process = ";
    cin >> n;
    process pro[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the process ID = ";
        cin >> pro[i].pid;
        cout << "Enter the burst time for process = ";
        cin >> pro[i].burst_time;
        pro[i].waiting_time = 0;
        pro[i].turnaround_time = 0;
        pro[i].completion_time = 0;
    }

    // Sorting the process according to the burst time
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (pro[j].burst_time < pro[min].burst_time)
            {
                min = j;
            }
        }
        swap(pro[min], pro[i]);
    }

    // Calculating the completion time, turn around time and wait time
    int time = 0;
    for (int i = 0; i < n; i++)
    {
        time += pro[i].burst_time;
        pro[i].completion_time = time;
        pro[i].turnaround_time = pro[i].completion_time;
        pro[i].waiting_time = pro[i].turnaround_time - pro[i].burst_time;
    }

    // Printing the table
    cout << endl;
    cout << endl;
    cout << "Process ID\tBurst Time\tWaiting Time\tTurn Around Time\tCompletion Time" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << pro[i].pid << "\t\t" << pro[i].burst_time << "\t\t" << pro[i].waiting_time << "\t\t" << pro[i].turnaround_time << "\t\t" << pro[i].completion_time << endl;
    }

    // Calculating the average waiting time and turn around time
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    for (int i = 0; i < n; i++)
    {
        avg_waiting_time += pro[i].waiting_time;
        avg_turnaround_time += pro[i].turnaround_time;
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    cout << endl;
    cout << "Average Waiting Time = " << avg_waiting_time << endl;
    cout << "Average Turn Around Time = " << avg_turnaround_time << endl;

    return 0;
}
