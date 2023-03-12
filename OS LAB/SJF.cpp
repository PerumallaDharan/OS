#include <iostream>
using namespace std;
struct process
{
    int id;
    int bt;
    int waiting_time=0;
    int turnaround_time=0;
    int completion_time=0;
};
bool compare(process p1, process p2)
{
    return p1.bt < p2.bt;
}
void sjf(process pro[], int n)
{
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
}
int main()
{
    int n;
    cout << "Enter the number of process = ";
    cin >> n;
    process pro[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the burst time for process " << i + 1 << " = ";
        cin >> pro[i].bt;
        pro[i].id = i + 1;
        pro[i].waiting_time = 0;
        pro[i].turnaround_time = 0;
        pro[i].completion_time = 0;
    }
    sjf(pro, n);
    return 0;
}
