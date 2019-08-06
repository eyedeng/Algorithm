#include <iostream>
using namespace std;

class CSmaple
{
    int x;
public:
    CSmaple()
    {
        cout<<"Construct 1 Called"<<endl;
    }
    CSmaple(int n)
    {
        x = n;
        cout<<"Construct 2 Called"<<endl;
    }

};
class Test
{
public:
    Test(int n){cout<<1<<"  ";}
    Test(int n,int m){cout<<2<<"  ";}
    Test(){cout<<3<<"  ";}
};
int main()
{
    CSmaple ar1[2];
    cout<<"step1"<<endl;
    CSmaple ar2[2] = {4,5};
    cout<<"step2"<<endl;
    CSmaple ar3[2] = {3};
    cout<<"step3"<<endl;
    CSmaple * ar4 = new CSmaple[2];
    delete []ar4;

    Test arr[3] = {1,Test(1,2)}; // 1 2 3
    Test *parr[3] = {new Test(4),NULL,new Test()};//1 3
    return 0;
}
