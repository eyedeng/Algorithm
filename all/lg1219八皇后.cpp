#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 111

int cnt = 0;
int N;
vector<int> visl(30);  //  /
vector<int> visr(30);  //  \

vector<int> visc(20);  //  |
vector<int> col_pos(20);
void nqueens_num(int row)
{
	if(row == N)
    {
        cnt++;
        if(cnt>=1 && cnt<=3)
        {
            for(int i=0; i<N-1; i++)
                cout<<col_pos[i]<<" ";
            cout<<col_pos[N-1]<<endl;
        }
        return;
    }
    for(int col=0; col<N; col++)
    {
        if(!visc[col] && !visl[row+col] && !visr[row-col+N-1])  // pos 'col' is legal
        {
            visc[col] = visl[row+col] = visr[row-col + N-1] = 1;
            col_pos[row] = col+1;
            nqueens_num(row+1);
            visc[col] = visl[row+col] = visr[row-col + N-1] = 0;
        }
    }
}
int main()
{
	cin>>N;
	nqueens_num(0);
	cout<<cnt<<endl;
}

