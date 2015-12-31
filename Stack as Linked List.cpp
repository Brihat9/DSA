/** Stack as linked list **/

#include<iostream>
using namespace std;

// dynamic implementation of singly linked list
struct node
{
    int data;
    struct node *next;
}*top = NULL;             // points to start of list

class stackaslinkedlist
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
              "Press 1.  to push data into stack\n"
              "      2.  to pop data from stack\n"
              "      3.  to display content of stack\n"
              "      4.  to exit from program\n"
              "after '->'\n"<<endl;
    }

    // inserts data/node at the beginning of the list ie push to stack
    void push(int value)
    {
        if(n==NULL)
        {
            cout<<"ERROR : Overflow."<<endl;
            return;
        }
        setdata(value);
        if(top==NULL)
            top = n;
        else
        {
            n->next=top;
            top=n;
        }
    }

    // removes node from beginning of list ie pop from stack
    void pop()
    {
        temp=top;
        if(temp==NULL)
        {
            cout<<"Stack is empty."<<endl;
            return;
        }
        if(temp->next==NULL)
        {
            top=NULL;
            cout<<temp->data<<" removed from stack."<<endl;
            delete temp;
            return;
        }
        top=temp->next;
        cout<<temp->data<<" removed from stack."<<endl;
        delete temp;
    }

    // displays the content ( data and next address ) of list
    void display()
    {
        temp=top;
        if(temp==NULL)
        {
            cout<<"Stack is Empty."<<endl;
            return;
        }
        do
        {
            cout<<temp->data<<"\t"<<temp->next<<endl;
            temp=temp->next;
        }while(temp!=NULL);
    }
};


// main function starta
int main(void)
{
    stackaslinkedlist s;
    s.menu();
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
            s.push(dat);
            cout<<dat<<" added to stack."<<endl;
            break;
        case 2:                 // removes node from beginning of list
            s.pop();
            break;
        case 3:                // displays the content ( data and next address ) of list
            s.display();
            break;
        case 4:                // exits from program
            return 0;
        default:                // shows main menu / help
            s.menu();
        }
    }
} // main menu ends
