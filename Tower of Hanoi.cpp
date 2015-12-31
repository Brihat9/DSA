/** Solution to Tower of Hanoi using Recursion  **/

#include<iostream>
#include<conio.h>
using namespace std;

class towerofhanoi
{
private:
    int n;
public:
    void setdata()
    {
        do{
            cout<<"\n\n\t*** TOWER OF HANOI SOLUTION ***\n\n Enter no of disks in tower of hanoi : ";
            cin>>n;
            if(n<=0)
                cout<<"  Invalid number of disks."<<endl;
        }while(n<=0);
    }

    //function ( no of disk , source , destination , auxiliary )
    void toh(int n,char src,char des, char aux)
    {
        //if only one disk, moke the move and return
        if(n==1)
        {
            cout<<"   Move disk "<<n<<" from peg "<<src<<" to peg "<<des<<endl;
            return;
        }

        // move top n-1 disk from A to B using C as auxiliary
        toh(n-1,src,aux,des);

      //getch();
        cout<<"   Move disk "<<n<<" from peg "<<src<<" to peg "<<des<<endl;

        //move n-1 disk from B to C using A as auxiliary
        toh(n-1,aux,des,src);
    }

    int getn(void)
    {
        return n;
    }
};

int main(void)
{
    char c;
    towerofhanoi t;
    while(1)
    {
        t.setdata();
        int num=t.getn();

        // A = source , B = auxiliary , C = destination
        t.toh(num,'A','C','B');

        cout<<endl<<" Again (y/n) : ";
        cin>>c;
        if(c=='n' || c=='N')
            break;
    }
    return 0;
}
