#include <iostream>
using namespace std;

int time_slice;

struct process
{
    int id, burst_time, comp_time, wait_time, tat_time, resp_time;
};

void round_robin(process pro[], int n)
{
    int time_taken = 0;
    int total = 0;
    int remaining_burst_time[n];
    for (int i = 0; i < n; i++)
    {
        remaining_burst_time[i] = pro[i].burst_time;
        total += pro[i].burst_time;
    }

    while (time_taken < total)
    {
        for (int i = 0; i < n; i++)
        {
            if (remaining_burst_time[i] == pro[i].burst_time)
                pro[i].resp_time = time_taken;
            if (remaining_burst_time[i] > 0)
            {
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
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        pro[i].tat_time = pro[i].comp_time;
        pro[i].wait_time = pro[i].tat_time - pro[i].burst_time;
        // pro[i].resp_time = pro[i].wait_time;
    }
}

int main()
{
    int n;
    cout << "Enter the number of processes: " << endl;
    cin >> n;
    cout << "Enter the time slice: " << endl;
    cin >> time_slice;

    process pro[n];
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

    round_robin(pro, n);

    cout << "Process\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\tResponse Time" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << pro[i].id << "\t" << pro[i].burst_time << "\t\t" << pro[i].comp_time << "\t\t" << pro[i].tat_time << "\t\t" << pro[i].wait_time << "\t\t" << pro[i].resp_time << endl;
    }

    return 0;
}
