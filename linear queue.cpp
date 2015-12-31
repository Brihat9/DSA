#include<iostream>
#define N 3
using namespace std;
class queue
{
private:
    int front,rear,temp;
    int array[N];
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

    void insert(int a)
    {
        if(front=rear==-1)
            front=rear=0;
        if(rear>N-1)
            cout<<"ERROR : Queue Full"<<endl;
        else
        {
            array[rear++]=a;
            cout<<a<<" added in queue."<<endl;
        }
    }

    void remove()
    {
        if(front==-1 or front>=rear)
            cout<<endl<<"ERROR : Queue Empty"<<endl;
        else
        {
            temp=array[front++];
            cout<<endl<<temp<<" removed from queue."<<endl;
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
            q.insert(data);
            break;
        case 2:
            q.remove();
            break;
        case 3:
            return 0;
        default:
            cout<<endl;
            q.menu();
        }
    }
}
