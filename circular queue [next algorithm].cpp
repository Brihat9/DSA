#include<iostream>
#include<cstdlib>
#define N 3

using namespace std;

class queue
{
private:
    int front,rear;
    int array[N],temp;
public:
    queue()
    {
        front=rear=-1;
    }

    void menu(void)
    {
        cout<<"Press 1 to add data in queue\n"
              "      2 to delete data from queue and\n"
              "      3 to exit\n"
              "after '- >'"<<endl;
    }

/** *******************************************************************
*                           Enqueue algorithm
*       1.start
*       2.if(front==(rear+1)%max) then circular queue overflow*
*       3.else
*            rear=(rear+1)%max
*            queue[rear]=data
*            if(front==-1) set front=0
*       4.stop
******************************************************************* **/
    void enqueue(int a)
    {
        if(front==(rear+1)%N)
        {
            cout<<"ERROR : Queue Full"<<endl;
            return;
        }
        else
        {
            rear=(rear+1)%N;
            array[rear]=a;
            cout<<a<<" added to queue"<<endl;
            //cout<<"front = "<<front<<endl<<"rear = "<<rear<<endl<<endl;
            if(front==-1)
                front=0;
        }
    }

/** *******************************************************************
*                           Dequeue Algorithm
*       1.start
*       2.if(front==rear and rear==-1) then circular queue underflow
*       3.else
*           data=queue[front]
*           if(front==rear) then set front and rear to -1
*           else front=(front+1)%max
*       4.stop
******************************************************************* **/
    void dequeue()
    {
        if(rear==-1 and rear==front)
        {
            cout<<"ERROR : Queue Empty"<<endl;
            return;
        }
        else
        {
            temp=array[front];
            cout<<temp<<" removed from queue."<<endl;
            if(rear==front)
                rear=front=-1;
            else
                front=(front+1)%N;
            //cout<<"front = "<<front<<endl<<"rear = "<<rear<<endl<<endl;
        }
    }
};

int main(void)
{
    queue q;
    int data,choice;
    q.menu();
    while(1)
    {
        cout<<endl<<" - > ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<endl<<"Enter data to add in queue ( max = "<<N<<" ) : ";
            cin>>data;
            q.enqueue(data);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            return 0;
        default:
            cout<<endl;
            q.menu();
        }
    }
}
