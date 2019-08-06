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
int main()
{
    string s;
    cin>>s;
    stack<char> num;
    stack<int> ans;
    for(int i=0; s[i]!='@'; i++)
    {
        if(s[i]=='.'){
            int n = 0,k=1;
            while(!num.empty()){
                n += (num.top()-'0')*k;
                num.pop();
                k*=10;
            }
            ans.push(n);
        }
        else if(s[i]>='0' && s[i]<='9'){
            num.push(s[i]);
        }
        else{
            int a = ans.top(); ans.pop();
            int b = ans.top(); ans.pop();
            int t = calcu(a,b,s[i]);
            ans.push(t);
        }
    }
    cout<<ans.top()<<endl;
}
