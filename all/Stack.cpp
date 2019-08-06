#include <stack>
#include <iostream>
#include <string>
using namespace std;
int calcu(int a,int b,char c)
{
    switch (c)
    {
        case '+':return b+a;
        case '-':return b-a;
        case '*':return b*a;
        case '/':return b/a;
    }
    return -1000;

}
void trans()
{
    string str(2);
    str[0] = 'x';
    str[1] = 'y';
    cout<<str;
    char c;
    int i=0;
    while(cin>>c && c!='.')
    {
        str[i] = c;
        i++;cout<<c;
    }
    cout<<endl<<"str";
    cout<<str;
//    while(--i)
//        cout<<str.at(i);

}
int main()
{
    trans();
    cout<<"over";
    stack<int> s;
    char c=0;
    while(cin>>c && c!='#')
    {
        if(!(c>='0' && c<='9')){
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();
            int t = calcu(a,b,c);
            //cout<<t<<endl;
            s.push(t);
        }
        else
            s.push(c-'0');
    }
    cout<<s.top();
}
