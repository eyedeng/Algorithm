#include <iostream>
using namespace std;

int main()
{
    int i=10;
    int * pn = new int[i*10];
    pn[0] = 20;
    cout<<pn[0]<<" "<<pn[1];

    delete [] pn;
}
