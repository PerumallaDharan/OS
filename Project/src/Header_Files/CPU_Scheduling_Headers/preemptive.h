#include <bits/stdc++.h>
using namespace std;

struct preemptive
{
    int id, a_time, b_time, comp_time, wait_time, tat_time, priority, rem_time;
};

bool compare(preemptive p1, preemptive p2)
{
    return p1.a_time < p2.a_time;
}

void doprepriority()
{
    // Taking input
    int n;
    cout << "Enter the number of processes " << endl;
    cin >> n;

    // Creating an array of processes
    preemptive pro[n];
    for (int i = 0; i < n; i++)
    {
        pro[i].id = i + 1;
        cout << "Enter the arrival time for process " << i + 1 << endl;
        cin >> pro[i].a_time;
        cout << "Enter the burst time for process " << i + 1 << endl;
        cin >> pro[i].b_time;
        pro[i].comp_time = 0;
        pro[i].tat_time = 0;
        pro[i].wait_time = 0;
        pro[i].rem_time = pro[i].b_time;
        pro[i].priority = (rand() % 10) + 1;
    }

    // Sorting the processes based on arrival time
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (compare(pro[j], pro[min]))
            {
                min = j;
            }
        }
        swap(pro[min], pro[i]);
    }

    // Calculating the completion time, turnaround time and waiting time
    int total_time = 0;
    for (int i = 0; i < n; i++)
    {
        total_time += pro[i].b_time;
    }

    int current_time = 0;
    while (current_time <= total_time)
    {
        // index of the process with highest priority
        int highest_priority_idx = -1;
        int highest_priority = INT_MAX;

        // find the process with highest priority
        for (int i = 0; i < n; i++)
        {
            // check if the process has arrived and has remaining time
            if (pro[i].a_time <= current_time && pro[i].rem_time > 0 && pro[i].priority < highest_priority)
            {
                // update the highest priority process
                highest_priority_idx = i;
                highest_priority = pro[i].priority;
            }
        }

        // if no process has arrived yet
        if (highest_priority_idx == -1)
        {
            current_time++;
            continue;
        }

        // reduce the remaining time of the process
        pro[highest_priority_idx].rem_time--;

        // if the process has completed execution
        if (pro[highest_priority_idx].rem_time == 0)
        {
            pro[highest_priority_idx].comp_time = current_time + 1;
            pro[highest_priority_idx].tat_time = pro[highest_priority_idx].comp_time - pro[highest_priority_idx].a_time;
            pro[highest_priority_idx].wait_time = pro[highest_priority_idx].tat_time - pro[highest_priority_idx].b_time;
        }

        current_time++;
    }

    // Displaying the output
    cout << "Process\t\tBT\t\tAT\t\tCompletion Time\t\tWait Time\t\tTurnaround Time\t\t Priority" << endl;
    cout << "-------\t\t---\t\t---\t\t--------------\t\t---------\t\t---------------\t\t----------" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << pro[i].id << "\t\t" << pro[i].b_time << "\t\t"
             << pro[i].a_time << "\t\t  " << pro[i].comp_time << "\t\t\t   "
             << pro[i].wait_time << "\t\t\t   " << pro[i].tat_time
             << "\t\t\t   " << pro[i].priority << endl;
    }
    cout << "-------\t\t---\t\t---\t\t--------------\t\t---------\t\t---------------\t\t----------" << endl;

    // Calculating the average waiting time and average turnaround time
    float avg_wait_time = 0, avg_tat_time = 0;
    for (int i = 0; i < n; i++)
    {
        avg_wait_time += pro[i].wait_time;
        avg_tat_time += pro[i].tat_time;
    }
    avg_wait_time /= n;
    avg_tat_time /= n;
    cout << "Average Waiting Time: " << avg_wait_time << endl;
    cout << "Average Turnaround Time: " << avg_tat_time << endl;
}
