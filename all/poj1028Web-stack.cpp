#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string op,web;
    stack<string> backs,forws;
    backs.push("http://www.acm.org/");
    cin>>op;
    while(op!="QUIT")
    {
        if(op=="VISIT")
        {
            cin>>web;
            cout<<web<<endl;
            backs.push(web);
            while(!forws.empty()) //Çå¿Õ
                forws.pop();
        }
        else if(op=="BACK")
        {
            if(backs.size()!=1){
                forws.push(backs.top());
                backs.pop();
                cout<<backs.top()<<endl;
            }
            else cout<<"Ignored"<<endl;
        }
        else
        {
            if(forws.size()>=1){
                backs.push(forws.top());
                forws.pop();
                cout<<backs.top()<<endl;
            }
            else cout<<"Ignored"<<endl;
        }
        cin>>op;
    }

    return 0;
}
