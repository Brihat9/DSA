/** SINGLY LINKED LIST :: DYNAMIC IMPLEMENTATION **/
/** ALL CASES OF INSERTION AND DELETION COVERED **/

#include<iostream>
using namespace std;

// dynamic implementation of singly linked list
struct node
{
    int data;
    struct node *next;
}*start = NULL;             // points to start of list

// singly linked list class
class single
{
private:
    int count;
    struct node *n,*temp,*pre,*ppre,*del;
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
        cout<<" SINGLY LINKED LIST :: MAIN MENU\n"
              "Press 1.  to insert at beginning\n"
              "      2.  to insert at end\n"
              "      3.  to insert after specific node\n"
              "      4.  to insert before specific node\n"
              "      5.  to insert at specific position\n"
              "      6.  to delete from beginning\n"
              "      7.  to delete from end\n"
              "      8.  to delete after specific node\n"
              "      9.  to delete before specific node\n"
              "      10. to delete at specific position\n"
              "      11. to display content of list\n"
              "      12. to exit from program\n"
              "after '->'\n"<<endl;
    }

    // inserts data/node at the beginning of the list
    void insertbeg(int value)
    {
        if(n==NULL)
        {
            cout<<"ERROR : Overflow."<<endl;
            return;
        }
        setdata(value);
        if(start==NULL)
            start = n;
        else
        {
            n->next=start;
            start=n;
        }
    }

    // inserts data/node at the end of the list
    void insertend(int value)
    {
        setdata(value);
        if(start==NULL)
            start=n;
        else
        {
            temp=start;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=n;
        }
    }

    // inserts node after given specific node data
    void insertafter(int val,int value)
    {
        setdata(value);
        temp=start;
        if(temp==NULL)
        {
            cout<<"List is empty."<<endl;
            return;
        }
        while(temp->data!=val && temp->next!=NULL)
            temp=temp->next;
        if(temp->data!=val && temp->next==NULL)
        {
            cout<<"ERROR : No node found with given data."<<endl;
            return;
        }
        n->next = temp->next;
        temp->next=n;
    }

    // inserts node before given specific node data
    void insertbef(int val,int value)
    {
        setdata(value);
        temp=start;
        if(temp==NULL)
        {
            cout<<"List is empty."<<endl;
            return;
        }
        while(temp->data!=val && temp->next!=NULL)
        {
            pre=temp;
            temp=temp->next;
        }
        if(temp->data!=val && temp->next==NULL)
        {
            cout<<"ERROR : No node found with given data."<<endl;
            return;
        }
        pre->next=n;
        n->next=temp;
    }

    // inserts node at given specific position
    void insertpos(int pos,int value)
    {
        setdata(value);
        temp=start;
        if(temp==NULL)
        {
            cout<<"List is empty."<<endl;
            return;
        }
        count=2;
        if(pos==1)
        {
            insertbeg(value);
            return;
        }
        while(count<pos && temp->next!=NULL)
        {
            temp=temp->next;
            count++;
        }
        if(temp->next==NULL)
        {
            cout<<"ERROR : No node found in given position."<<endl;
            return;
        }
        n->next=temp->next;
        temp->next=n;
    }

    // removes node from beginning of list
    void deletebeg()
    {
        temp=start;
        if(temp==NULL)
        {
            cout<<"List is empty."<<endl;
            return;
        }
        start=temp->next;
        delete temp;
    }

    // removes node from end of list
    void deleteend()
    {
        temp=start;
        if(temp==NULL)
        {
            cout<<"List is empty."<<endl;
            return;
        }
        while(temp->next!=NULL)
        {
            pre=temp;

            temp=temp->next;
        }
        pre->next=NULL;
        delete temp;
    }

    // removes node after given specific node data
    void deleteafter(int val)
    {
        temp=start;
        if(temp==NULL)
        {
            cout<<"List is empty."<<endl;
            return;
        }
        while(temp->data!=val && temp->next!=NULL)
            temp=temp->next;
        if(temp->data!=val && temp->next==NULL)
        {
            cout<<"ERROR : No node with given data."<<endl;
            return;
        }
        if(temp->next==NULL)
        {
            cout<<"ERROR : No node after given value."<<endl;
            return;
        }
        del=temp->next;
        temp->next = del->next;
        delete del;
    }

    // removes node before given specific node data
    void deletebef(int val)
    {
        temp=start;
        if(temp==NULL)
        {
            cout<<"List is empty."<<endl;
            return;
        }
        while(temp->data!=val && temp->next!=NULL)
        {
            ppre=del;
            del=temp;
            temp=temp->next;
        }
        if(temp->data!=val && temp->next==NULL)
        {
            cout<<"ERROR : No node with given data."<<endl;
            return;
        }
        if(temp==start)
        {
            cout<<"ERROE : No node before given data."<<endl;
            return;
        }
        else if(del==start)
            start=temp;
        else
            ppre->next=del->next;
        delete del;
    }

    // removes node at given specific position
    void deletepos(int val)
    {
        temp=start;
        if(temp==NULL)
        {
            cout<<"List is empty."<<endl;
            return;
        }
        if(val==1)
        {
            deletebeg();
            return;
        }
        count=2;
        while(count<val-1 && temp->next!=NULL)
        {
            temp=temp->next;
            count++;
        }
        if(temp->next==NULL)
        {
            cout<<"ERROR : No node found in given position."<<endl;
            return;
        }
        del=temp->next;
        temp->next=del->next;
        delete del;
    }

    // displays the content ( data and next address ) of list
    void display()
    {
        temp=start;
        if(temp==NULL)
        {
            cout<<"List is Empty."<<endl;
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
    single s;
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
            s.insertbeg(dat);
            break;
        case 2:                 // inserts data/node at the end of the list
            cout<<"enter data to add : ";
            cin>>dat;
            s.insertend(dat);
            break;
        case 3:                 // inserts node after given specific node data
            cout<<"enter data of node after which new node is to be added : ";
            cin>>tem;
            cout<<"enter data to add : ";
            cin>>dat;
            s.insertafter(tem,dat);
            break;
        case 4:                 // inserts node before given specific node data
            cout<<"enter data of node before which new node is to be added : ";
            cin>>tem;
            cout<<"enter data to add : ";
            cin>>dat;
            s.insertbef(tem,dat);
            break;
        case 5:                 // inserts node at given specific position
            cout<<"enter position to insert node : ";
            cin>>tem;
            if(tem<=0)
            {
                cout<<"Invalid position."<<endl;
                break;
            }
            cout<<"enter data to add : ";
            cin>>dat;
            s.insertpos(tem,dat);
            break;
        case 6:                 // removes node from beginning of list
            s.deletebeg();
            break;
        case 7:                 // removes node from end of list
            s.deleteend();
            break;
        case 8:                 // removes node after given specific node data
            cout<<"enter data after which node is to be deleted :";
            cin>>tem;
            s.deleteafter(tem);
            break;
        case 9:                 // removes node before given specific node data
            cout<<"enter data before which node is to be deleted :";
            cin>>tem;
            s.deletebef(tem);
            break;
        case 10:                // removes node at given specific position
            cout<<"enter position to delete node :";
            cin>>tem;
            if(tem<=0)
            {
                cout<<"Invalid position."<<endl;
                break;
            }
            s.deletepos(tem);
            break;
        case 11:                // displays the content ( data and next address ) of list
            s.display();
            break;
        case 12:                // exits from program
            return 0;
        default:                // shows main menu / help
            s.menu();
        }
    }
} // main menu ends
