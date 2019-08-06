#include <stdio.h>
#include <iostream>
#include <vector>
//
using namespace std;

template<class T>
T MaxElement(T a[],int n)
{
    T tempMax = a[0];
    for(int i=1;i<n ;i++ )
        if(a[i]>tempMax)
            tempMax = a[i];
    return tempMax;
}

template<class T>
void print(T a)
{
    cout<< a<<"in print1"<<endl;
}
template<class T1,class T2>
void print(T1 a,T2 b)
{
    cout<< a<<","<< b<<endl;
    //return 0;
}
void print(int a)
{
    cout<< a<<"in print3 first call"<<endl;;
}

template <typename input_iterator_tag,typename _Tp>  //#include <numeric>
_Tp accumulate(input_iterator_tag _fist,input_iterator_tag _last,_Tp _init)
{
    for( ; _fist!=_last; _fist++)
        _init += *_fist;
    return _init;
}

int main()
{
    double a[4] = {3.4,4.6,1.3,6.5};
    char c[5] = {'3','d','z','!','&'};
    cout << MaxElement(a,4)<<endl;
    cout << MaxElement(c,4)<<endl;

    print(10);
    print(10.01);
    print(10,11.1);


    vector<int> sum;
    for(int i=1; i<=10; i++)
        sum.push_back(i*i);
    for(vector<int>::iterator it = sum.begin(); it!=sum.end(); it++)
        cout<<*it<<" ";
    cout<<endl;
    int Sum = accumulate(sum.begin(),sum.end(),10);
    cout<<Sum;
    return 0;
}

