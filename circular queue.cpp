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

    void enqueue(int a)
    {
        if(front==-1 and rear==-1)
            front=rear=0;
        if(front==0 and rear>N-1)
        {
            cout<<"ERROR : Queue Full"<<endl;
            return;
        }
        else
        {
            if(rear==N-1 and front!=0)
                rear=0;
            else
            {
                array[rear++]=a;
                cout<<a<<" added to queue"<<endl;
                cout<<"front = "<<front<<endl<<"rear = "<<rear<<endl<<endl;
            }
        }
    }

    void dequeue()
    {
        if(front==-1)
        {
            cout<<"ERROR : Queue Empty"<<endl;
            return;
        }
        else
        {
            temp=array[front++];
            cout<<temp<<" removed from queue."<<endl;
            cout<<"front = "<<front<<endl<<"rear = "<<rear<<endl<<endl;
            if(rear==front)
                rear=front=-1;
            else if(front==N-1)
                front=0;
            else
                front++;
            cout<<"front = "<<front<<endl<<"rear = "<<rear<<endl;
        }
    }
};

int main(void)
{
  /*  queue q;
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
*/
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.dequeue();
    q.enqueue(4);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    return 0;
}
