// Including the required header files
#include <iostream>
using namespace std;

// Declaring the global variables
int time_slice;

// Defining the structure for the process
struct roundrobin
{
    int id, burst_time, comp_time, wait_time, tat_time, resp_time;
};

// Defining the function for the round robin scheduling
void doroundrobin()
{
    // Defining the variables
    int n;
    cout << "Enter the number of processes " << endl;
    cin >> n;
    cout << "Enter the time slice " << endl;
    cin >> time_slice;

    // Taking the input of the burst time of the processes
    roundrobin pro[n];
    for (int i = 0; i < n; i++)
    {
        pro[i].id = i + 1;
        cout << "Enter burst time of process " << i + 1 << ": " << endl;
        cin >> pro[i].burst_time;
        pro[i].comp_time = 0;
        pro[i].tat_time = 0;
        pro[i].wait_time = 0;
        pro[i].resp_time = 0;
    }

    // Defining the variables
    int time_taken = 0;
    int total = 0;
    int remaining_burst_time[n];
    for (int i = 0; i < n; i++)
    {
        remaining_burst_time[i] = pro[i].burst_time;
        total += pro[i].burst_time;
    }

    // Printing the gant chart
    cout << endl
         << "Gant Chart of the given processes" << endl;
    cout << "Pid\t"
         << "Remaining Time\t"
         << "Start Time\t"
         << "End Time" << endl;
    cout << "---------------------------------------------" << endl;

    // Calculating the completion time, turn around time and wait time
    while (time_taken < total)
    {
        for (int i = 0; i < n; i++)
        {
            if (remaining_burst_time[i] == pro[i].burst_time)
                pro[i].resp_time = time_taken;
            if (remaining_burst_time[i] > 0)
            {
                cout << pro[i].id << "\t   " << remaining_burst_time[i] << "\t\t   " << time_taken << "\t\t   ";

                if (remaining_burst_time[i] <= time_slice)
                {
                    time_taken += remaining_burst_time[i];
                    pro[i].comp_time = time_taken;
                    remaining_burst_time[i] = 0;
                }
                else
                {
                    time_taken += time_slice;
                    remaining_burst_time[i] -= time_slice;
                }
                cout << time_taken << endl;
            }
        }
    }

    // Printing the process table
    cout << endl
         << endl;
    cout << "Process\t   Burst Time\t   Completion Time   \t  Turnaround Time   \t   Waiting Time   \t   Response Time" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "   " << pro[i].id << "\t     " << pro[i].burst_time << "\t\t\t    " << pro[i].comp_time
             << "\t\t\t    " << pro[i].tat_time << "\t\t\t    " << pro[i].wait_time << "\t\t    " << pro[i].resp_time << endl;
    }

    // Calculating the turn around time and wait time
    int avg_tat = 0, avg_wt = 0;
    for (int i = 0; i < n; i++)
    {
        pro[i].tat_time = pro[i].comp_time;
        pro[i].wait_time = pro[i].tat_time - pro[i].burst_time;
        // pro[i].resp_time = pro[i].wait_time;
        avg_tat += pro[i].tat_time;
        avg_wt += pro[i].wait_time;
    }
    cout << endl
         << endl;
    // Printing the average turn around time and average wait time
    cout << "Average Turn Around Time = " << avg_tat / n << endl;
    cout << "Average Wait Time = " << avg_wt / n << endl;
}
