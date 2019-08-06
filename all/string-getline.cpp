#include <string>
#include <iostream>
using namespace std;

int main()
{
    int a[] {1,2,3,5};
    cout<<a[3]<<endl;
    string text;
    getline(cin, text); // a line

    int vowels = 0;
    int consonants = 0;

    for(const auto& ch : text) //基于区域的for循环
    {
        if(isalpha(ch))
            switch (tolower(ch))
            {
            case 'a':case 'e':case 'i':
            case 'o':case 'u':
                vowels++;
                break;
            default:
                consonants++;
                break;
            }
    }
    cout<<"v:"<<vowels<<"  c:"<<consonants<<endl;

    string nLineText;
    getline(cin,nLineText,'#'); // get # over
    cout<<nLineText<<endl;
    return 0;
}
