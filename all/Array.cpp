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
            resize(2*capacity);
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
            //shrink(0.5);
            resize(capacity/2);
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

    void resize(int capa)
    {
        capacity = capa;
        EleType *temp_e = new EleType[capacity];
        for(int i=0; i<lenth; i++)
        {
             temp_e[i] = e[i];
        }
        e = temp_e;
        delete[] temp_e;
    }

    void pop_back()            //数组末端删除元素
    {
        lenth--;
        if((lenth<<1) < capacity)
            //shrink(0.5);
            resize(capacity/2);
    }

    void push_back(EleType e_) //数组末端添加元素
    {
        lenth++;
        if(lenth>capacity)
            //expand(2);
            resize(capacity*2);
        e[lenth-1] = e_;
    }

};

int main()
{
    int ta[5] = {2,4,3,6,7};
    Array<int> a(8);

    for(int i=0; i<5; i++)
        a.insert(i,ta[i]);
    a.show();
    cout<<"3 at position: "<<a.find(3)<<endl;
    a.remove(3);
    a.show();
    cout<<"6 at position: "<<a.find(6)<<endl;
    a.pos_change(0,10);
    a.val_change(3,4);a.val_change(4,3);
    a.show();
    //a.expand(2);
    for(int i=4; i<20; i++)
        a.insert(i,i*i);
    a.show();
    //cout<<"capacity: "<<a.capacity<<endl;
    for(int i=a.get_lenth()-1; i>5; i--)
        a.remove(i);
    a.show();
    //cout<<"capacity: "<<a.capacity<<endl;
    a.pop_back();a.pop_back();
    a.show();
    a.push_back(100);
    a.show();
    return 0;
}
