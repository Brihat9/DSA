#include<iostream>
#include<cstring>
#define N 50

using namespace std;

class stack
{
private:
    char array[N];
public:
    int top;

    stack()
    {
        top=-1;
    }

    void push(char a)
    {
        if(top==N-1)
            cout<<"\n ERROR : Stack Overflow\n"<<endl;
        else
            array[++top]=a;
    }

    char pop()
    {
        if(top==-1)
            cout<<"\n ERROR : Stack Empty\n"<<endl;
        else
            return array[top--];
    }

    char data()
    {
        return array[top];
    }
};

class inftopos
{
private:
    int n;
    stack s;
    char infix[N];
    char postfix[N];
public:
    void setdata()
    {
        n=0;
        cout<<" Enter infix expression ( max "<<N<<" character ) : ";
        cin>>infix;
    }

    void intopost()
    {
        int length=strlen(infix);
        for(int i=0;i<length;i++)
        {
            if(infix[i]=='(')
                s.push(infix[i]);

            else if(infix[i]==')')
            {
                do{
                    postfix[n++]=s.pop();
                }while(s.data()!='(');
                s.pop();
            }

            else if((infix[i]>=65 && infix[i]<91) || (infix[i]>=97 && infix[i]<123))
                postfix[n++]=infix[i];

            else if(infix[i]=='+'||infix[i]=='-')
            {
                if(s.data()=='+'||s.data()=='-'||s.data()=='*'||s.data()=='/')
                {
                    do{
                        postfix[n++]=s.pop();
                    }while(s.data()=='/'||s.data()=='*'||s.data()=='+'||s.data()=='-');
                    s.push(infix[i]);
                }
                else
                    s.push(infix[i]);
            }

            else if(infix[i]=='*'||infix[i]=='/')
            {
                if(s.data()=='+'||s.data()=='-')
                    s.push(infix[i]);
                else if(s.data()=='*'||s.data()=='/')
                {
                   do{
                        postfix[n++]=s.pop();
                    }while(s.data()=='/'||s.data()=='*');
                    s.push(infix[i]);
                }
                else
                    s.push(infix[i]);
            }

            else
            {
                cout<<endl<<" Invalid symbol read."<<endl;
                break;
            }
        }

        if(s.top!=-1)
        {
            for(int i=s.top;i>=0;i--)
                postfix[n++]=s.pop();
        }

        postfix[n++]='\0';
    }

    void showdata()
    {
        cout<<endl<<" Postfix expression of "<<infix<<" is\n\n "<<postfix<<endl<<endl;
    }
};

int main(void)
{
    inftopos inf;
   // cout<<endl<<"\t  * * * INFIX TO POSTFIX CONVERTER * * *"<<endl;
   // cout<<"\tAllowed characters : a - z , ( ) , + - * /\n\t\t     SPACE not allowed\n"<<endl;
    inf.setdata();
    inf.intopost();
    inf.showdata();
    return 0;
}
