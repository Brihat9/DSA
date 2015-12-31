#include<iostream>
#include<cstdlib>
#define MAX_NODE 5
using namespace std;

class queueaslist                             //queue implementation of list
{
private:
    int avail;
    int front,rear;
    struct nodetype             //definition of a node with one data field and next field
    {
        int data,next;
    }node[MAX_NODE];

public:
    queueaslist()                       //initialization
    {
        avail=0;
        front=rear=-1;
        for(int i=0;i<MAX_NODE-1;i++)
            node[i].next=i+1;
        node[MAX_NODE-1].next=-1;
    }

    void menu(void)                 //main menu
    {
        cout<<"Press 1 to add data in queue\n"
              "      2 to delete data from queue and\n"
              "      3 to exit\n"
              "after '- >'"<<endl;
    }

    int getnode()               //returns any of available node
    {
        int p;
        if(avail==-1)
        {
            cout<<"ERROR : Queue Full"<<endl;
            exit(1);
        }
        else
        {
            p=avail;
            avail=node[avail].next;
            return p;
        }
    }

    void freenode(int p)            //free given node and put it into available node list
    {
        node[p].next=avail;
        avail=p;
    }

    int empty()                 //checks whether list(queue) is empty or not
    {
        return (front==-1 ? 1 : 0);
    }

    void insert(int a)          //inserts data in queue( ie in a node of list)
    {
        int p;
        p=getnode();
        node[p].data=a;
        node[p].next=-1;
        if(rear==-1)
            front=p;
        else
            node[rear].next=p;
        rear=p;
    }

    int remove()                //removes data element from queue
    {
        int p,x;
        if(empty())
        {
            cout<<"ERROR : Queue Empty"<<endl;
            exit(1);
        }
        else
        {
            p=front;
            x=node[front].data;
            front=node[p].next;
            if(front==-1)
                rear=-1;
            freenode(p);
            return x;
        }
    }
};

int main(void)
{
    queueaslist q;
    int data,choice;
    q.menu();
    while(1)
    {
        cout<<endl<<" - > ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<endl<<"Enter data to add in queue ( max = "<<MAX_NODE<<" ) : ";
            cin>>data;
            q.insert(data);
            cout<<data<<" added to queue."<<endl;
            break;
        case 2:
            data=q.remove();
            cout<<data<<" removed from queue"<<endl;
            break;
        case 3:
            return 0;
        default:
            cout<<endl;
            q.menu();
        }
    }
}
