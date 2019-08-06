//不会继承
#include <stdio.h>
#include <iostream>
using namespace std;
#define error "ERROR\n"

template<class T>
class Stack
{
private:
    T *base;       //底指针
    T *top;        //(指向栈顶上一个位置)
    int stacksize; //容量
    //int size_cnt;  // 元素个数
public:
    Stack(int s): base(new T[s]),top(base),stacksize(s) {};

    int size()
    {
        return top - base;
    }

    bool empty()
    {
        return top == base;
    }

    bool full()
    {
        return top-base == stacksize;
    }

    void push(T e)
    {
        if(full()){
            cout<<"栈满\n";
            return;
        }
        *top = e;
        top++;
        //size_cnt++;
    }

    void pop()
    {
        if(empty()){
            cout<<"栈空\n";
            return;
        }
        top--;
        //size_cnt--;
    }

    T getTop()
    {
        if(empty()){
            cout<<"栈空\n";
            return -1;
        }
        return *(top-1);
    }

    void show()
    {
        for(T *iterator = base; iterator!=top; iterator++)
        {
            cout<<(*iterator)<<"  ";
        }
        cout<<endl;
    }
};

template<class T>
class LoopQueue
{
private:
    T *base;   //基地址
    int front;
    int rear;  //尾指针(指向队尾下一个位置)
    int maxqsize;
public:
    LoopQueue(int m): base(new T[m]),front(0),rear(0),maxqsize(m) {};
    int size()
    {
        return (rear - front + maxqsize) % maxqsize;
    }

    bool empty()
    {
        return front == rear;
    }

    bool full()
    {
        return (rear+1)%maxqsize == front;
    }

    void push(T e)
    {
        if(full())
        {
            cout<<"队满\n";
            return;
        }
        base[rear] = e;
        rear = (rear+1)%maxqsize;  // +1
    }

    void pop()
    {
        if(empty())
        {
            cout<<"队空\n";
            return;
        }
        front = (front+1)%maxqsize;
    }

    T getFront()
    {
        if(empty())
        {
            cout<<"队空\n";
            return -1;
        }
        return base[front];
    }

    int getCapacity()
    {
        return maxqsize - 1;
    }

    void show()
    {
        for(int i=front; i!=rear; i=(i+1)%maxqsize)
        {
            cout<<base[i]<<"  ";
        }
        cout<<endl;
    }
};
int main()
{
    Stack<int> s(10);
    for(int i=1; i<=8; i++)
        s.push(i);
    s.show();
    s.pop();s.pop();
    s.show();
    cout<<"top: "<<s.getTop()<<endl;
    cout<<"size: "<<s.size()<<endl;
    cout<<"empty?: "<<s.empty()<<endl;
    for(int i=0; i<6; i++)
        s.pop();
    cout<<"top: "<<s.getTop()<<endl;
    cout<<"size: "<<s.size()<<endl;
    cout<<"empty?: "<<s.empty()<<endl;
    cout<<"_______\n\n";

    LoopQueue<char> q(10);
    cout<<"Capacity: "<<q.getCapacity()<<endl;
    for(char c='a',i=0; i<8; i++)
        q.push(c+i);
    q.show();
    q.pop();q.pop();
    q.show();
    cout<<"front: "<<q.getFront()<<endl;
    cout<<"size: "<<q.size()<<endl;
    cout<<"empty?: "<<q.empty()<<endl;
    for(int i=0; i<6; i++)
        q.pop();
    cout<<"front: "<<q.getFront()<<endl;
    cout<<"size: "<<q.size()<<endl;
    cout<<"empty?: "<<q.empty()<<endl;
}
