#include <iostream>
using namespace std;

void swap(int & a,int & b){
    int temp;
    temp = a; a = b; b = temp;
}

int n = 4;
int & setVal(){
    return n;
}
int main()
{
    int a = 5,b = 8;
    int & r = a;   //reference must initialized
    cout << (r++) << endl;
    cout << a << endl;
    r = b;   // = ��ֵ      // only a reference
    cout << a << endl;

    a = 3,b = 6;
    swap(a,b);
    cout << a<<" "<<b << endl;

    //������Ϊ��������ֵ
    setVal() = 40;
    cout<<n << endl;
}
