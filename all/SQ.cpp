#include <stdio.h>
#include <iostream>
using namespace std;
//typedef int EleType;
#define error "ERROR\n"

template<class EleType>
class Array
{
private:
    EleType *e;
    int lenth;
    int capacity;

public:
    Array(int c):e(new EleType[c]),lenth(0),capacity(c) {};
    int get_lenth()
    {
        return this->lenth;
    }
    void show()
    {
        for(int i=0; i<lenth; i++)
            cout<<e[i]<<"  ";
        printf("\n");
    }

    void insert(int index,EleType e_)
    {
        if(index+1 > capacity)
            //expand(2);
        if(index < 0){
            cout<<error;
            return;
        }
        for(int i=lenth; i>index; i--)
        {
            e[i] = e[i-1];
        }
        e[index] = e_;
        lenth++;
    }

    EleType at(int index) //��λ������
    {
        return e[index];
    }

    void remove(int index)
    {
        if(index+1>capacity || index<0){
            cout<<error;
            return;
        }
        for(int i=index; i<lenth-1; i++) // -1
        {
            e[i] = e[i+1];
        }
        lenth--;
        if((lenth<<1) < capacity) //����
            ;//shrink(0.5);
    }

    int find(EleType val) //��ֵ����
    {
        for(int i=0; i<lenth; i++)
        {
            if(e[i]==val)
                return i;
        }
        return -1;
    }

    void pos_change(int index,EleType val) //��λ���޸�
    {
        e[index] = val;
    }

    void val_change(EleType val,EleType to) //��ֵ�޸�
    {
        for(int i=0; i<lenth; i++)
        {
            if(e[i]==val)
                e[i] = to;
        }
    }

    void expand(int multiple)
    {
        capacity *= multiple;
        EleType *temp_e = e;    //��¼
        e = new EleType[capacity];
        for(int i=0; i<lenth; i++)
        {
            e[i] = temp_e[i];
        }
        delete[] temp_e;
    }

    void shrink(double multiple)
    {
        capacity *= multiple;
        EleType *temp_e = e;
        e = new EleType[capacity];
        for(int i=0; i<lenth; i++)
        {
             e[i] = temp_e[i];
        }
        delete[] temp_e;
    }

    void pop_back()            //����ĩ��ɾ��Ԫ��
    {
        lenth--;
        if((lenth<<1) < capacity)
            ;//shrink(0.5);
    }

    void push_back(EleType e_) //����ĩ�����Ԫ��
    {
        lenth++;
        if(lenth>capacity)
            //expand(2);
        e[lenth-1] = e_;
    }

};
template<class T>
class Stack :public Array<T>
{
//private:
//    T *base;       //��ָ��
//    T *top;        //(ָ��ջ����һ��λ��)
//    int stacksize; //����
    //int size_cnt;  // Ԫ�ظ���
public:
    Stack(int s):Array<T>(s) {}

    int size()
    {
        return this->get_lenth();
    }

    bool empty()
    {
        return this->get_lenth() == 0;
    }

    void push(T e)
    {
        this->pop_back();
    }

    void pop()
    {
        if(!empty())
            this->pop_back();
    }

    T getTop()
    {
        return this->at(this->get_lenth()-1);
    }

    void show()
    {
        this->show();
    }
};

template<class T>
class LoopQueue :public Array<T>
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
    return 0;
}
