/** Solution to Tower of Hanoi using Recursion  **/

#include<iostream>
#include<conio.h>
using namespace std;

class towerofhanoi
{
public:
    //function ( no of disk , source , destination , auxiliary )
    void toh(int nitr,char src,char des,char aux)
    {
        //if only one disk, moke the move and return
        if(nitr==1)
        {
            cout<<"   Move disk "<<nitr<<" from peg "<<src<<" to peg "<<des<<endl;
            return;
        }

        // move top n-1 disk from A to B using C as auxiliary
        toh(nitr-1,src,aux,des);

      //getch();
        cout<<"   Move disk "<<nitr<<" from peg "<<src<<" to peg "<<des<<endl;

        //move n-1 disk from B to C using A as auxiliary
        toh(nitr-1,aux,des,src);
    }
};

int main(void)
{
    int num;
    char c;
    towerofhanoi t;
    while(1)
    {
        cout<<"Enter no of disks : ";
        cin>>num;
        // A = source , B = auxiliary , C = destination
        t.toh(num,'A','C','B');

        cout<<endl<<" Again (y/n) : ";
        cin>>c;
        if(c=='n' || c=='N')
            break;
    }
    return 0;
}
