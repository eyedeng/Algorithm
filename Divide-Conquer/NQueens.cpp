#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> ans;
vector<int> visl;  //  /
vector<int> visr;  //  \

vector<int> visc;  //  |
void r(int row,vector<string> &q,int &n)  // 按row递归:不同row
{
    if(row == n)
    {
        ans.push_back(q);
        return;
    }
    for(int col=0; col<n; col++)
    {
        if(!visc[col] && !visl[row+col] && !visr[row-col + n-1])  // pos 'col' is legal
        {
            visc[col] = visl[row+col] = visr[row-col + n-1] = 1;
            q[row][col] = 'Q';
            r(row+1, q, n);
            q[row][col] = '.';
            visc[col] = visl[row+col] = visr[row-col + n-1] = 0;
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    visl = vector<int>(2*n, 0);
    visr = vector<int>(2*n, 0);
    visc = vector<int>(n, 0);
    vector<string> q(n, string(n,'.'));
    r(0, q, n);
    return ans;
}

// -----------

int col_pos[20];  // col_pos[i]: 第i行皇后所处的列
int cnt = 0;
int N;

bool isLegal(int row)  
{
	for(int i=0; i<row; i++)  //比较慢的判断方式
		if(col_pos[i] == col_pos[row] || abs(col_pos[row]-col_pos[i]) == abs(row-i))
			return false;
	return true;
}
void nqueens_num(int row)
{
	if(row == N)
    {
        cnt++;
        return;
    }
    for(int col=0; col<N; col++)
    {
		col_pos[row] = col;
        if(isLegal(row))  // pos 'col' is legal
        {
            nqueens_num(row+1);
        }
    }
}
int main()
{
	int n = 8;  // <=13
	N = n;
	nqueens_num(0);
	cout<<cnt<<endl;
}
/*
n	1	2	3	4	5	6	7	8	9	10	11	  12	 13	    14	
U	1	0	0	1	2	1	6	12	46	92	341	  1,787	 9,233	45,752	
D	1	0	0	2	10	4	40	92	352	724	2,680 14,200 73,712	365,596
*/
