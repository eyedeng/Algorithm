//双向队列 deque
//by MoreWindows http://blog.csdn.net/morewindows
#include <deque>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	deque<int> ideq(20); //Create a deque ideq with 20 elements of default value 0
	deque<int>::iterator pos;
	deque<int>::const_iterator cpos;
	int i;

	//使用assign()赋值  assign在计算机中就是赋值的意思
	for (i = 0; i < 20; ++i)
		ideq[i] = i;

	//输出deque
	printf("输出deque中数据:\n");
	for (i = 0; i < 20; ++i)
		printf("%d ", ideq[i]);
	putchar('\n');

	//在头尾加入新数据
	printf("\n在头尾加入新数据...\n");
	ideq.push_back(100);
	ideq.push_front(i);

	//输出deque
	printf("\n输出deque中数据:\n");
//	for (pos = ideq.begin(); pos != ideq.end(); pos++)
//		printf("%d ", *pos);
    sort(ideq.begin(),ideq.end());
    for(i=0; i<ideq.size(); i++)
    {
        printf("%d ",ideq[i]);
    }
	putchar('\n');

	//查找
	const int FINDNUMBER = 19;
	printf("\n查找%d\n", FINDNUMBER);
	pos = find(ideq.begin(), ideq.end(), FINDNUMBER);
	if (pos != ideq.end())
		printf("find %d success\n", *pos);
	else
		printf("find failed\n");

	//在头尾删除数据
	printf("\n在头尾删除数据...\n");
	ideq.pop_back();
	ideq.pop_front();

	//输出deque
	printf("\n输出deque中数据:\n");
	for (pos = ideq.begin(); pos != ideq.end(); pos++)
		printf("%d ", *pos);
	putchar('\n');
	return 0;
}
