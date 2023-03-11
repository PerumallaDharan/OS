#include <iostream>
using namespace std;

struct node
{
    int id, wait_time, arr_time, comp_time, tat_time, burst_time;
    node *next;
}

class Queue
{
private:
    node *front, *rear;

public:
    Queue()
    {
        front = rear = NULL;
    }
    bool isEmpty()
    {
        return front == NULL;
    }
    Queue addnode(int id, int arr_time, int burst_time)
    {
        node *np = new node();
        np->id = 0;
        np->wait_time = 0;
        np->arr_time = 0;
        np->comp_time = 0;
        np->tat_time = 0;
        np->burst_time = 0;
        np->next = 0;
        if (isEmpty())
        {
            front = np;
            rear = np;
        }
        else
        {
            rear->next = np;
            rear = np;
        }
    }
    node deletenode()
    {
        node np;
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            np.id = -1;
            return np;
        }
        else
        {
            np = *front;
            front = front->next;
            if (front == NULL)
            {
                rear = NULL;
            }
            return np;
        }
    }
};

int main()
{
    Queue n;
    n.addnode(1,0,3);
    n.addnode(2,0,7);
    n.addnode(3,5,1);
    

}