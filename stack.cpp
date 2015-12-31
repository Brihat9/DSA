#include<iostream>
#define N 5
using namespace std;

class stack {
private:
    int array[N];
public:
    int top;
    stack()
    {
        top=-1;
    }
    void push(int a)
    {
        if(top==N-1)
            cout<<"\nERROR : Stack Overflow"<<endl;
        else
        {
            array[++top]=a;
            cout<<a<<" added to stack."<<endl;
        }
    }
    int pop()
    {
        if(top==-1)
            cout<<"\nERROR : Stack Empty"<<endl;
        else
            return array[top--];
    }
};

int main(void)
{
    stack s;
    int a;
    char c;
    do{
        cout<<"\nEnter data to add to stack ( "<<N-(s.top+1)<<" items remaining ) : ";
        cin>>a;
        s.push(a);
        cout<<"\nAnother (y/n) ? ";
        cin>>c;
    }while(c=='y'||c=='Y');
    cout<<"\nRemoving data from stack.\n"<<endl;
    for(int i=s.top;i>-1;i--)
        cout<<s.pop()<<" removed from stack."<<endl;
    return 0;
}
