#include<iostream>
using namespace std;
template <class T>
class CircularQueue{
    private:
    T queue[5];
    T data;
    T temp;
    int front,rear;
    public:
    CircularQueue(){
        front = rear = -1;
    }
    void enqueue(T data){
        this->data = data;
        if(front == -1 && rear == -1){
            front = 0;
            rear = 0;
        }
        if(rear == 4 && front != 0){
            rear = 0;
        }
        if(rear == 4 && front == 0){
            cout<<"The queue is full....";
            exit(1);
            }
        else if(rear != 0 && front != 0 && rear == front){
            cout<<"The queue is full.....";
            exit(1);
        }
        else
            queue[rear++] = data;
    }
    T dequeue(){
        //if(front == rear)
         //   front = -1;

        if(front == -1){
            cout<<"Queue is empty....";
            exit(1);
            }
        else{
            temp = queue[front];
            //queue[front] = NULL;
            front++;
            if(front == rear)
                rear = front = -1;
            else if(front == 4)
                front = 0;
            //return queue[front];
            }
        return temp;
    }
    int getRear(){
        return rear;
    }
    int getFront(){
        return front;
    }

};
int main(void){
    CircularQueue<int> q;

    char c;
    int data;
    do{
    cout<<"Press 1.To Enqueue 2.To Dequeue 3.To Quit:";
    cin>>c;
    switch(c){
        case '1':
        cout<<"Enter the number to Enqueue: ";cin>>data;
        q.enqueue(data);
        break;
        case '2':
        cout<<q.dequeue()<<" is dequeued."<<endl;
        break;
    }
    }while(c!='3');
    return 0;
}

