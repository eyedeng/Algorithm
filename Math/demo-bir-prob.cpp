#include <bits/stdc++.h>
using namespace std;

int main()
{
    srand(time(NULL));
    vector<int> birthday;
    for(int i=1; i<=28; i++)
    {
        birthday.push_back( rand()%366 );
    }
    sort(birthday.begin(), birthday.end());
    for(int d:birthday)
        cout<<d<<" ";
    return 0;
}
