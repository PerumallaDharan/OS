#include <iostream>
using namespace std;

struct process
{
    string id;
    int at;
    int bt;
    int res;
    int wt;
    int tat;
    int ct;
    int rt;
};

void rr(process p[], int n, int st)
{

    int tt = 0;
    for (int i = 0; i < n; i++)
    {
        tt += p[i].bt;
    }
    cout << endl
         << "Gant Chart" << endl;
    cout << "Pid\t"
         << "Remaining Time\t"
         << "start Time\t"
         << "End Time" << endl;
    int ct = 0;
    while (ct < tt)
    {

        for (int i = 0; i < n; i++)
        {

            if (p[i].rt == p[i].bt)
                p[i].res = ct;
            if (p[i].rt > 0)
            {
                cout << p[i].id << "\t" << p[i].rt << "\t\t" << ct << "\t\t";
                if (p[i].rt <= st)
                {
                    ct += p[i].rt;
                    p[i].ct = ct;
                    p[i].rt = 0;
                }
                else
                {
                    ct += st;
                    p[i].rt -= st;
                }
                cout << ct << endl;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        p[i].tat = p[i].ct;
        p[i].wt = p[i].tat - p[i].bt;
    }
    cout << endl
         << "Complete Table" << endl;
    cout << "Pid\t\tArrival Time\tBurst Time\tResponse\tCompletion Time\tWaiting Time\tTurnaround Time " << endl;
    int avg_tat = 0, avg_wt = 0;
    for (int i = 0; i < n; i++)
    {
        cout << p[i].id << "\t\t" << p[i].at << "\t\t" << p[i].bt << "\t\t" << p[i].res
             << "\t\t    " << p[i].ct << "\t\t    " << p[i].wt << "\t\t    " << p[i].tat << endl;
        avg_tat += p[i].tat;
        avg_wt += p[i].wt;
    }
    cout << endl
         << "Average Turn Around Time = " << avg_tat / n << endl;
    cout << "Average Wait Time = " << avg_wt / n << endl;
}

int main()
{
    int n, slice;
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter slice time: ";
    cin >> slice;
    process p[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter process id " << i + 1 << " : ";
        cin >> p[i].id;
        cout << "Enter process " << p[i].id << "'s burst time: ";
        cin >> p[i].bt;
        p[i].at = 0;
        p[i].wt = 0;
        p[i].tat = 0;
        p[i].ct = 0;
        p[i].rt = p[i].bt;
    }
    rr(p, n, slice);
    return 0;
}
