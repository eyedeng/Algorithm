#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
struct Vector
{
    double x,y;
    Vector(double _x,double _y):x(_x),y(_y) { }
    Vector() { }

};
Vector operator + (const Vector &p,const Vector &q)
{
    return Vector(p.x+q.x,p.y+q.y);
}
Vector operator - (const Vector &p,const Vector &q)
{
    return Vector(p.x-q.x,p.y-q.y);
}
Vector operator * (double k,const Vector &q)
{
    return Vector(k*q.x,k*q.y);
}
double operator * (const Vector &p,const Vector &q)
{
    return (p.x*q.x + p.y*q.y);
}

double length(Vector p)
{
    return sqrt(p*p);
}
Vector unit(Vector p)
{
    return 1/length(p) * p;
}
double project(Vector p,Vector q)
{
    return p*unit(q);
}
double operator ^ (const Vector &p,const Vector &q)
{
    return (p.x*q.y - p.y*q.x);
}
int main()
{
    Vector a(3,4),b(10,0),c;
    c = a^b;
    //cout<<a^b<<endl;

}
