#include <iostream>
using namespace std;
class person
{
public:
    int age;
    int level;
    person(int a,int l)
    {
        age = a;
        level = l;
    }
    inline bool operator ==(const person &per)const
    {
        if(age == per.age)
            return true;
        return false;
    }
};
struct node
{
    int xbuzyin;
    int ybuzyout;
    void printsomw(int a)
    {
        cout<<a<<endl;
    }
} N;
int main()
{
    person p1(20,3);
    person p2(20,4);
    cout<< (p1==p2)<<endl;
    N.printsomw(1000);
    N.xbuzyin = 3;
    person persnew(30,6);
    return 0;
}
