// Implement multilevel queue scheduling

// Read the details of n processes, like process ID, Type of process, Burst time, Priority
// (If the process is student process), etc. Find the completion time,
// turn around time, wait time of each of the pricesses and also find the averages.

// Arrival time is 0 for all the processes.

// Print the gantt chart.

// 1. System Processes                   :           FCFS
// 2. Interactive Processes              :           Round Robin with TQ=2
// 3. Interactive editing Processes      :           Round Robin with TQ=4
// 4. Batch Processes                    :           SJF
// 5. Student Processes                  :           Priority Scheduling

#include <iostream>
#include <climits>
#include<vector>
using namespace std;

struct Process
{
    int pid, burst_time, priority, process_type;
    int turnaround_time, completion_time, wait_time;
};

int main()
{
    int n;
    cout << "Enter the total number of processes" << endl;
    cin >> n;

    Process pro[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter process ID" << endl;
        cin >> pro[i].pid;

        cout << "Enter the type of process (1. System, 2. Interactive, 3. Interactive Editing, 4. Batch, 5. Student)" << endl;
        cin >> pro[i].process_type;

        switch (pro[i].process_type)
        {
        case 1:
            cout << "Enter the burst time of the system process" << endl;
            cin >> pro[i].burst_time;
            break;

        case 2:
            cout << "Enter the burst time of the interactive process" << endl;
            cin >> pro[i].burst_time;
            break;

        case 3:
            cout << "Enter the burst time of the interactive editing process" << endl;
            cin >> pro[i].burst_time;
            break;

        case 4:
            cout << "Enter the burst time of the batch process" << endl;
            cin >> pro[i].burst_time;
            break;

        case 5:
            cout << "Enter the burst time of the student process" << endl;
            cin >> pro[i].burst_time;

            cout << "Enter the priority of the student process" << endl;
            cin >> pro[i].priority;
            break;

        default:
            break;
        }
    }

    int time = 0;
    int total_time = 0;
    int system_time = 0, interactive_time = 0, editing_time = 0, batch_time = 0, student_time = 0;
    int system_count = 0, interactive_count = 0, editing_count = 0, batch_count = 0, student_count = 0;

    // Queue for each level
    Process system_q[n], interactive_q[n], editing_q[n], batch_q[n], student_q[n];
    int system_front = 0, interactive_front = 0, editing_front = 0, batch_front = 0, student_front = 0;
    int system_rear = -1, interactive_rear = -1, editing_rear = -1, batch_rear = -1, student_rear = -1;

    while (true)
    {
        // Checking for completion
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (pro[i].completion_time > 0)
            {
                count++;
            }
        }
        if (count == n)
        {
            break;
        }

        // Adding processes to appropriate queue based on process type
        for (int i = 0; i < n; i++)
        {
            if (pro[i].burst_time > 0 && pro[i].completion_time == 0)
            {
                switch (pro[i].process_type)
                {
                case 1:
                    system_rear++;
                    system_q[system_rear] = pro[i];
                    system_count++;
                    break;
                case 2:
                    interactive_rear++;
                    interactive_q[interactive_rear] = pro[i];
                    interactive_count++;
                    break;
                case 3:
                    editing_rear++;
                    editing_q[editing_rear] = pro[i];
                    editing_count++;
                    break;
                case 4:
                    batch_rear++;
                    batch_q[batch_rear] = pro[i];
                    batch_count++;
                    break;
                case 5:
                    student_rear++;
                    student_q[student_rear] = pro[i];
                    student_count++;
                    break;
                default:
                    break;
                }
            }
        }
        // Running processes from highest priority to lowest
        if (system_count > 0)
        {
            int time_quantum = system_q[system_front].burst_time;
            if (time_quantum > system_count)
            {
                time_quantum = system_count;
            }
            for (int i = 0; i < time_quantum; i++)
            {
                system_q[system_front].burst_time--;
                system_time++;
                time++;
            }
            if (system_q[system_front].burst_time == 0)
            {
                pro[system_q[system_front].pid - 1].completion_time = time;
                pro[system_q[system_front].pid - 1].turnaround_time = pro[system_q[system_front].pid - 1].completion_time;
                pro[system_q[system_front].pid - 1].wait_time = pro[system_q[system_front].pid - 1].turnaround_time - system_q[system_front].burst_time;
                system_front++;
                system_count--;
            }
        }
        else if (interactive_count > 0)
        {
            int time_quantum = 2;
            if (time_quantum > interactive_count)
            {
                time_quantum = interactive_count;
            }
            for (int i = 0; i < time_quantum; i++)
            {
                interactive_q[interactive_front].burst_time--;
                interactive_time++;
                time++;
            }
            if (interactive_q[interactive_front].burst_time == 0)
            {
                pro[interactive_q[interactive_front].pid - 1].completion_time = time;
                pro[interactive_q[interactive_front].pid - 1].turnaround_time = pro[interactive_q[interactive_front].pid - 1].completion_time;
                pro[interactive_q[interactive_front].pid - 1].wait_time = pro[interactive_q[interactive_front].pid - 1].turnaround_time - interactive_q[interactive_front].burst_time;
                interactive_front++;
                interactive_count--;
            }
            else
            {
                interactive_rear++;
                interactive_q[interactive_rear] = interactive_q[interactive_front];
                interactive_front++;
            }
        }
        else if (editing_count > 0)
        {
            int time_quantum = 4;
            if (time_quantum > editing_count)
            {
                time_quantum = editing_count;
            }
            for (int i = 0; i < time_quantum; i++)
            {
                editing_q[editing_front].burst_time--;
                editing_time++;
                time++;
            }
            if (editing_q[editing_front].burst_time == 0)
            {
                pro[editing_q[editing_front].pid - 1].completion_time = time;
                pro[editing_q[editing_front].pid - 1].turnaround_time = pro[editing_q[editing_front].pid - 1].completion_time;
                pro[editing_q[editing_front].pid - 1].wait_time = pro[editing_q[editing_front].pid - 1].turnaround_time - editing_q[editing_front].burst_time;
                editing_front++;
                editing_count--;
            }
            else
            {
                editing_rear++;
                editing_q[editing_rear] = editing_q[editing_front];
                editing_front++;
            }
        }
        else if (batch_count > 0)
        {
            int min_burst_time = INT_MAX;
            int min_burst_time_index = -1;
            for (int i = 0; i < batch_count; i++)
            {
                if (batch_q[i].burst_time < min_burst_time)
                {
                    min_burst_time = batch_q[i].burst_time;
                    min_burst_time_index = i;
                }
            }
            for (int i = 0; i < min_burst_time; i++)
            {
                batch_q[min_burst_time_index].burst_time--;
                batch_time++;
                time++;
            }
            if (batch_q[min_burst_time_index].burst_time == 0)
            {
                pro[batch_q[min_burst_time_index].pid - 1].completion_time = time;
                pro[batch_q[min_burst_time_index].pid - 1].turnaround_time = pro[batch_q[min_burst_time_index].pid - 1].completion_time;
                pro[batch_q[min_burst_time_index].pid - 1].wait_time = pro[batch_q[min_burst_time_index].pid - 1].turnaround_time - batch_q[min_burst_time_index].burst_time;
                for (int i = min_burst_time_index; i < batch_count - 1; i++)
                {
                    batch_q[i] = batch_q[i + 1];
                }
                batch_count--;
            }
        }
        else if (student_count > 0)
        {
            int max_priority = INT_MIN;
            int max_priority_index = -1;
            for (int i = 0; i < student_count; i++)
            {
                if (student_q[i].priority > max_priority)
                {
                    max_priority = student_q[i].priority;
                    max_priority_index = i;
                }
            }
            for (int i = 0; i < student_q[max_priority_index].burst_time; i++)
            {
                student_q[max_priority_index].burst_time--;
                student_time++;
                time++;
            }
            if (student_q[max_priority_index].burst_time == 0)
            {
                pro[student_q[max_priority_index].pid - 1].completion_time = time;
                pro[student_q[max_priority_index].pid - 1].turnaround_time = pro[student_q[max_priority_index].pid - 1].completion_time;
                pro[student_q[max_priority_index].pid - 1].wait_time = pro[student_q[max_priority_index].pid - 1].turnaround_time - student_q[max_priority_index].burst_time;
                for (int i = max_priority_index; i < student_count - 1; i++)
                {
                    student_q[i] = student_q[i + 1];
                }
                student_count--;
            }
        }
        else
        {
            time++;
        }
    }

    // Calculating averages
    float avg_tat_time = 0, avg_wait_time = 0;
    for (int i = 0; i < n; i++)
    {
        avg_tat_time += pro[i].turnaround_time;
        avg_wait_time += pro[i].wait_time;
    }
    avg_tat_time /= n;
    avg_wait_time /= n;

    // Printing Gantt Chart
    cout << "\nGantt Chart:\n";
    vector<Process> gantt;
    for (int i = 0; i < gantt.size(); i++)
    {
        cout << "|" << gantt[i].pid << "|";
    }
    cout << "\n\n";

    // Printing process details
    // cout << "PID\tType\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWait Time\n";
    // for (
}