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

    EleType at(int index) //按位置搜索
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
        if((lenth<<1) < capacity) //条件
            ;//shrink(0.5);
    }

    int find(EleType val) //按值搜索
    {
        for(int i=0; i<lenth; i++)
        {
            if(e[i]==val)
                return i;
        }
        return -1;
    }

    void pos_change(int index,EleType val) //按位置修改
    {
        e[index] = val;
    }

    void val_change(EleType val,EleType to) //按值修改
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
        EleType *temp_e = e;    //记录
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

    void pop_back()            //数组末端删除元素
    {
        lenth--;
        if((lenth<<1) < capacity)
            ;//shrink(0.5);
    }

    void push_back(EleType e_) //数组末端添加元素
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
//    T *base;       //底指针
//    T *top;        //(指向栈顶上一个位置)
//    int stacksize; //容量
    //int size_cnt;  // 元素个数
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
    return 0;
}
