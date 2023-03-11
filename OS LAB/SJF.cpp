#include <iostream>
using namespace std;
struct process
{
    int id;
    int bt;
    int waiting_time;
    int turnaround_time;
    int completion_time;
};
bool compare(process p1, process p2)
{
    return p1.bt < p2.bt;
}
void sjf(process processes[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (processes[j].bt < processes[min].bt)
            {
                min = j;
            }
        }
        swap(processes[min], processes[i]);
    }
    int total_time = 0;
    cout << "Process\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << processes[i].id << "\t" << processes[i].bt << "\t\t";
        int waiting_time = total_time;
        cout << waiting_time << "\t\t";
        int turnaround_time = waiting_time + processes[i].bt;
        cout << turnaround_time << "\t\t";
        int completion_time = total_time + processes[i].bt;
        cout << completion_time << endl;
        total_time += processes[i].bt;
    }
}
int main()
{
    int n;
    cout << "Enter the number of processes = ";
    cin >> n;
    process processes[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the burst time for process " << i + 1 << ": ";
        cin >> processes[i].bt;
        processes[i].id = i + 1;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
        processes[i].completion_time = 0;
    }
    sjf(processes, n);
    return 0;
}
