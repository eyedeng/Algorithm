//from book
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
//           27  16 9 12  54 36 72      9 12 16  27  36 54 72
void print_post_ord(vector<int> preorder,vector<int> inorder)
{
    int len = preorder.size(),L,R;
    if(len == 0)
        return;
    int root = preorder[0];
    for(int i=0; ; i++)
        if(inorder[i] == root)
        {
            L = i;
            break;
        }
    R = len - L - 1;                         // ÕÒ¸ù½Úµã£¬µÝ¹é
    print_post_ord(vector<int>(preorder.begin()+1,preorder.begin()+1+L) ,
                   vector<int>(inorder.begin(), inorder.begin()+L));
    print_post_ord(vector<int>(preorder.begin()+1+L,preorder.begin()+len),
                   vector<int>(inorder.begin()+L+1, inorder.begin()+L+1+len));
    cout<<root<<" ";
}

int main()
{
    //vector<int> v = {83,186,408,419};
    //cout<<coinChange(v,6249);
    //int x = 408;
    //cout<<(find(v.begin(),v.end(),x) - v.begin());
    vector<int> v1 = {27  ,16, 9 ,12,  54, 36 ,72};
    vector<int> v2 = {9 ,12 ,16 , 27,  36, 54 ,72};
    print_post_ord(v1,v2);
    return 0;
}


