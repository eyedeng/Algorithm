#include <iostream>
using namespace std;

// 迭代
int binary_search(const int arr[], int start,int end, int key)
{
    int idx = -1;
    int mid;
    while(start <= end)
    {
        mid = start + (end - start) / 2; //(s+e + s-s)/2
        if(arr[mid] > key)  // 左
            end = mid - 1;
        else if(arr[mid] < key)  // 右
            start = mid + 1;
        else{
            idx = mid;
            break;
        }
    }
    return idx;
}

// 尾递归 S: O(log n)
int binary_search_r(const int arr[], int start,int end, int key)
{
    if(start > end)
        return -1;

    int mid = start + (end - start) / 2;
    if(arr[mid] > key)
        return binary_search_r(arr, start, mid-1, key);
    else if(arr[mid] < key)
        return binary_search_r(arr, mid+1, end, key);
    else
        return mid;
}

int main()
{
    int a[] = {1, 3, 4, 6, 7, 8, 10, 13, 14};
    cout<< binary_search(a, 0, sizeof(a)/sizeof(a[0])-1, 4) << endl;
    return 0;
}
