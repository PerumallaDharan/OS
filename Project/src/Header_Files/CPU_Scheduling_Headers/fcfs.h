#include <iostream>
using namespace std;

struct fcfs
{
    int pid, arrival_time, burst_time, wait_time, completion_time, turn_around_time;
};

void dofcfs()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    fcfs q[n];
    for (int i = 0; i < n; i++)
    {
        cout << endl;
        cout << "Enter the process ID: ";
        cin >> q[i].pid;
        cout << "Enter the arrival time: ";
        cin >> q[i].arrival_time;
        cout << "Enter the burst time: ";
        cin >> q[i].burst_time;
        q[i].wait_time = 0;
        q[i].completion_time = 0;
        q[i].turn_around_time = 0;
    }

    // Sorting the processes based on arrival time
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (q[j].arrival_time > q[j + 1].arrival_time)
            {
                fcfs temp = q[j];
                q[j] = q[j + 1];
                q[j + 1] = temp;
            }
        }
    }

    // Calculating the completion time, turn around time and wait time
    int time = 0;
    for (int i = 0; i < n; i++)
    {
        if (q[i].arrival_time > time)
        {
            time = q[i].arrival_time;
        }
        q[i].completion_time = time + q[i].burst_time;
        q[i].turn_around_time = q[i].completion_time - q[i].arrival_time;
        q[i].wait_time = q[i].turn_around_time - q[i].burst_time;
        time = q[i].completion_time;
    }

    // Printing the table
    cout << endl;
    cout << endl;
    cout << "Process ID\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWait Time" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << q[i].pid << "\t\t" << q[i].arrival_time << "\t\t" << q[i].burst_time << "\t\t" << q[i].completion_time << "\t\t" << q[i].turn_around_time << "\t\t" << q[i].wait_time << endl;
    }

    // Calculating the average wait time and average turn around time
    float avg_wait_time = 0, avg_turn_around_time = 0;
    for (int i = 0; i < n; i++)
    {
        avg_wait_time += q[i].wait_time;
        avg_turn_around_time += q[i].turn_around_time;
    }
    avg_wait_time /= n;
    avg_turn_around_time /= n;
    cout << endl;
    cout << "Average Wait Time: " << avg_wait_time << endl;
    cout << "Average Turn Around Time: " << avg_turn_around_time << endl;
}
