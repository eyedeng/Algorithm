//����̳�
#include <stdio.h>
#include <iostream>
using namespace std;
#define error "ERROR\n"

template<class T>
class Stack
{
private:
    T *base;       //��ָ��
    T *top;        //(ָ��ջ����һ��λ��)
    int stacksize; //����
    //int size_cnt;  // Ԫ�ظ���
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
            cout<<"ջ��\n";
            return;
        }
        *top = e;
        top++;
        //size_cnt++;
    }

    void pop()
    {
        if(empty()){
            cout<<"ջ��\n";
            return;
        }
        top--;
        //size_cnt--;
    }

    T getTop()
    {
        if(empty()){
            cout<<"ջ��\n";
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
    T *base;   //����ַ
    int front;
    int rear;  //βָ��(ָ���β��һ��λ��)
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
            cout<<"����\n";
            return;
        }
        base[rear] = e;
        rear = (rear+1)%maxqsize;  // +1
    }

    void pop()
    {
        if(empty())
        {
            cout<<"�ӿ�\n";
            return;
        }
        front = (front+1)%maxqsize;
    }

    T getFront()
    {
        if(empty())
        {
            cout<<"�ӿ�\n";
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
