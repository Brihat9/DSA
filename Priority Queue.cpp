/**     Priority Queue using multiple Linear Queue  **/

#include<iostream>
#define MAX_PRIORITY 3         //max number of priority
#define MAX_ELEMENT 2           //max element in one priority queue
using namespace std;

class queue
{
private:
    int rear,front,data[MAX_ELEMENT];
public:
    //constructor
    queue()
    {
        rear=front=-1;
    }
    //insert element in queue
    void enqueue(int a)
    {
        if(front==-1 and rear==-1)
            front=rear=0;
        if(rear>MAX_ELEMENT-1)
        {
            cout<<"ERROR : Queue Full in priority ";
            return;
        }
        else
        {
            data[rear++]=a;
            cout<<a<<" added to priority ";
        }
    }

    //remove element from queue
    int dequeue(void)
    {
        int temp;
        if(front==-1 or front>=rear)
            return 1;
        else
        {
            temp=data[front++];
            cout<<temp<<" removed from priority ";
            return 0;
        }
    }

    //show content
    void show()
    {
        for(int i=front;i<rear;i++)
            cout<<"\t"<<data[i];
        cout<<endl;
    }
};

class pqueue
{
private:
    queue q[MAX_PRIORITY];
public:
    //main menu
    void menu(void)
    {
        cout<<"Press 1 to enqueue\n"
              "      2 to dequeue\n"
              "      3 to view content\n"
              "      4 to exit after '- >'."<<endl;
    }

    //inserts element in given priority
    void insert(int d,int pr)
    {
        q[pr-1].enqueue(d);
        cout<<pr<<endl;
    }

    //removes element of highest priority ( FCFS in case of same priority )
    int remove()
    {
        for(int i=0;i<MAX_PRIORITY;i++)
            if(q[i].dequeue()==0)
            {
                cout<<i+1<<endl;
                break;
            }
            else
                cout<<"Priority Queue "<<i+1<<" is empty"<<endl;
    }

    //view content of given priority
    void show(int a)
    {
        q[a-1].show();
    }
};

int main(void)
{
    int choice,ch,data;
    pqueue p;
    p.menu();
    while(1)
    {
    cout<<" - > ";
    cin>>choice;
    switch(choice)
        {
            int temp;
        case 1://insert element
            cout<<"Enter priority number [1-"<<MAX_PRIORITY<<"] : ";
            cin>>ch;
            if (ch<1 or ch>MAX_PRIORITY)
            {
                cout<<"INVALID CHOICE. TRY AGAIN"<<endl;
                continue;
            }
            cout<<"Enter data to add : ";
            cin>>data;
            p.insert(data,ch);
            break;
        case 2://delete element
            p.remove();
            break;
        case 3://view content
            cout<<"Enter priority number [1-"<<MAX_PRIORITY<<"] : ";
            cin>>ch;
            if (ch<1 or ch>MAX_PRIORITY)
            {
                cout<<"INVALID CHOICE. TRY AGAIN"<<endl;
                continue;
            }
            p.show(ch);
            break;
        case 4://exit
            return 0;
        default:
            cout<<"INVALID CHOICE"<<endl;
        }
    }
    //return 0;
}
