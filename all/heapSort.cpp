void heapify_max(int arr[], int start, int end)
{
    int fa = start;
    int son = 2*fa + 1;
    while(son <= end)
    {
        if(son+1 <= end && arr[son]<arr[son+1])
        {
            son = son+1;
        }
//        if(arr[fa] < arr[son])
//        {
//            swap(arr[fa], arr[son]);
//        }
//        fa = son;
//        son = 2*fa + 1;
        if(arr[fa] > arr[son])
            return;
        else
        {
            swap(arr[fa], arr[son]);
            fa = son;
            son = 2*fa + 1;
        }
    }
}
void heap_sort(int arr[], int len)
{
    for(int i=len/2-1; i>=0; i--)
    {
        heapify_max(arr, i, len-1);
    }
    for(int i=len-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heapify_max(arr, 0, i-1);
    }
}
int main()
{
    int arr[] = { 3, 5, 3, 0, 8, 6, 1, 6 };
    int len = sizeof(arr) /sizeof(int);
    heap_sort(arr, len);
    for(int i: arr)
        cout << i<<" ";
}