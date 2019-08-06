#include <iostream>
using namespace std;

class Location
{
private:
    int x,y;
public:
    void init(int X=0,int Y=0) //È±Ê¡²ÎÊý
    {
        x = X; y = Y;
    }
    void valueX(int val){ x = val; }
    int valueX() {return x; }
    void print();
};
void Location::print()
{
    cout<<x<<","<<y<<endl;
}
int main()
{
    Location lo;
    lo.init(5);
    lo.valueX(7);
    cout<<lo.valueX()<<endl;
    lo.print();
}
