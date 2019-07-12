 // segment tree array存储 区间和
 // https://www.youtube.com/watch?v=e_bK-dgPvfM
#include <bits/stdc++.h>
using namespace std;
#define MAX_LEN 1000
// 与 tree 有关加"node"，其余与原数组有关
void build_tree(int arr[], int tree[], int node, int start,int end)
{
    if(start == end)
    {
        tree[node] = arr[start];
        return;
    }
    int mid = (start+end) / 2;
    int left_node = 2*node + 1;
    int right_node = 2*node + 2;
    build_tree(arr, tree, left_node, start, mid);  // 递归建树
    build_tree(arr, tree, right_node, mid+1, end);
    tree[node] = tree[left_node] + tree[right_node];  // 左右之和
}
void update_tree(int arr[], int tree[], int node, int start,int end,int idx,int val)  // arr[idx] = val
{
    if(start == end)
    {
        arr[idx] = val;    // 注意对应关系
        tree[node] = val;
        return;
    }
    int mid = (start+end) / 2;
    int left_node = 2*node + 1;
    int right_node = 2*node + 2;
    if(idx <= mid)
    {
        update_tree(arr, tree, left_node, start, mid, idx, val);
    }
    else
    {
        update_tree(arr, tree, right_node, mid+1, end, idx, val);
    }
    tree[node] = tree[left_node] + tree[right_node];  // update sum
}
int query_tree(int arr[], int tree[], int node, int start,int end,int L,int R)  // sum(arr[L..R])
{
    //cout<<start<<","<<end<<endl;
    // arr[..L..R..start..end..] || arr[..start..end..L..R..]
    if(R < start || L > end)   //out of query range
    {
        return 0;
    }
    // arr[..L..start..end..R..]
    if(L <= start && end <= R) // in query range
    {
        return tree[node];     // 不再继续递归
    }
    if(start == end)
    {
        return tree[node];   //arr[start]
    }
    int mid = (start+end) / 2;
    int left_node = 2*node + 1;
    int right_node = 2*node + 2;
    int left_sum = query_tree(arr, tree, left_node, start, mid, L, R);
    int right_sum = query_tree(arr, tree, right_node, mid+1, end, L, R);
    return left_sum + right_sum;
}
int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11};
    int size = 6;
    int tree[MAX_LEN] = {0};
    build_tree(arr, tree, 0, 0, size-1);
    for(int i=0; i<15; i++)
        cout<<tree[i]<<" ";
    putchar('\n');
    update_tree(arr, tree, 0, 0, size-1, 4, 6);
    for(int i=0; i<15; i++)
        cout<<tree[i]<<" ";
    putchar('\n');
    cout<<query_tree(arr, tree, 0, 0, size-1, 2, 5)<<endl;
    return 0;
}
