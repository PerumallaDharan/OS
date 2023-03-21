#include <iostream>
using namespace std;

struct process
{
    int id, burst_time, wait_time, comp_time, tat_time, priority;
    //process *next;
};

bool compare(process p1, process p2)
{
    return p1.priority < p2.priority;
}

void display(process p[], int n)
{
    cout << "PID\tBT\tCT\tTAT\tWT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << p[i].id << "\t" << p[i].burst_time << "\t" 
        << p[i].comp_time << "\t" << p[i].tat_time << "\t" << p[i].wait_time << endl;
    }
}

void priority(process pro[], int n)
{
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

    int total = 0;
    for (int i = 0; i < n; i++)
    {
        pro[i].wait_time = total;
        pro[i].tat_time = pro[i].wait_time + pro[i].burst_time;
        pro[i].comp_time = total+pro[i].burst_time;
        total = total + pro[i].burst_time;
    }
    display(pro, n);
}

int main()
{
    int n;
    cout << "Enter number of process = " << endl;
    cin >> n;
    process pro[n];
    for (int i = 0; i < n; i++)
    {
        pro[i].id = i + 1;
        cout << "Enter burst time of process " << i + 1 << endl;
        cin >> pro[i].burst_time;
        cout << "Enter the priority of the process " << endl;
        cin >> pro[i].priority;
        pro[i].comp_time = 0;
        pro[i].tat_time = 0;
        pro[i].wait_time = 0;
    }
    priority(pro, n);
    return 0;
}