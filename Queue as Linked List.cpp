/** Queue as linked list **/

#include<iostream>
using namespace std;

// dynamic implementation of singly linked list
struct node
{
    int data;
    struct node *next;
}*front = NULL;             // points to front of list

class queueaslinkedlist
{
private:
    struct node *n,*temp;
public:
    // sets data field and next field for new node
    void setdata(int value)
    {
        n=new node;                 // memory allocation
        n->data=value;
        n->next=NULL;
    }

    // main menu
    void menu(void)
    {
        cout<<" STACK AS LINKED LIST :: MAIN MENU\n"
              "Press 1.  to add data to queue\n"
              "      2.  to remove data from queue\n"
              "      3.  to display content of queue\n"
              "      4.  to exit from program\n"
              "after '->'\n"<<endl;
    }

    // inserts data/node at the end of the list ie enqueue
    void enqueue(int value)
    {
        setdata(value);
        if(front==NULL)
            front=n;
        else
        {
            temp=front;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=n;
        }
    }

    // removes node from beginning of list ie dequeue
    void dequeue()
    {
        temp=front;
        if(temp==NULL)
        {
            cout<<"Queue is empty."<<endl;
            return;
        }
        if(temp->next==NULL)
        {
            front=NULL;
            cout<<temp->data<<" removed from queue."<<endl;
            delete temp;
            return;
        }
        front=temp->next;
        cout<<temp->data<<" removed from queue."<<endl;
        delete temp;
    }

    // displays the content ( data and next address ) of list
    void display()
    {
        temp=front;
        if(temp==NULL)
        {
            cout<<"Queue is Empty."<<endl;
            return;
        }
        do
        {
            cout<<temp->data<<"\t"<<temp->next<<endl;
            temp=temp->next;
        }while(temp!=NULL);
    }
};


// main function fronta
int main(void)
{
    queueaslinkedlist q;
    q.menu();
    while(1)
    {
        int choice,dat,tem;
        cout<<" - > ";
        cin>>choice;
        switch(choice)
        {
        case 1:                 // inserts data/node at the beginning of the list
            cout<<"enter data to add : ";
            cin>>dat;
            q.enqueue(dat);
            cout<<dat<<" added to queue."<<endl;
            break;
        case 2:                 // removes node from beginning of list
            q.dequeue();
            break;
        case 3:                // displays the content ( data and next address ) of list
            q.display();
            break;
        case 4:                // exits from program
            return 0;
        default:                // shows main menu / help
            q.menu();
        }
    }
} // main menu ends
