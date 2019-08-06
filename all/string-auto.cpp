#include <iostream>
#include <string>
#include <ctime>
using namespace std;

clock_t start,stop;

int main()
{
    start = clock();
    string name = "abcdefghijklmhikldsajfieahudbv";
    for(auto &s : name) // yingyong
    {
        s = toupper(s);  //xiugai
    }
    //for(int i =0;i<name.length(); i++)
    //    name[i] = toupper(name[i]);
    name = "大写："+name;
    cout<<name<<endl;
    cout<<name.size()<<endl;;

    stop = clock();
    cout << ((double)(stop-start)/CLK_TCK) <<endl;
    return 0;
}
