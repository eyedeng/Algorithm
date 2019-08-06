#include <stdio.h>
#include <iostream>
using namespace std;

class CRectangle{
public:
    int w,h;
    void init(int w,int h){
        this->w = w;
        this->h = h;
    }
    int Area(){
        return w*h;
    }
    int Permeter()
    {
        return 2*(w+h);
    }

};
/*void printRec(CRectangle r){
    cout << r.Area()<<endl;

}*/
void printRec(CRectangle &r){ // reference
    cout << r.Area()<<endl;
    r.h = 10;
}
int main()
{
    CRectangle r;
    r.init(3,4);
    CRectangle *rp;
	rp = &r;
	cout << rp->h<<"="<<r.h<<endl<< r.Permeter()<<endl;
    cout <<rp->Area() <<endl;
    CRectangle &rr = r;
    rr.h = 5;
    cout<< r.h<< endl;

    printRec(r);
    cout << r.Area()<<endl;
    return 0;
}
