//˫����� deque
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

	//ʹ��assign()��ֵ  assign�ڼ�����о��Ǹ�ֵ����˼
	for (i = 0; i < 20; ++i)
		ideq[i] = i;

	//���deque
	printf("���deque������:\n");
	for (i = 0; i < 20; ++i)
		printf("%d ", ideq[i]);
	putchar('\n');

	//��ͷβ����������
	printf("\n��ͷβ����������...\n");
	ideq.push_back(100);
	ideq.push_front(i);

	//���deque
	printf("\n���deque������:\n");
//	for (pos = ideq.begin(); pos != ideq.end(); pos++)
//		printf("%d ", *pos);
    sort(ideq.begin(),ideq.end());
    for(i=0; i<ideq.size(); i++)
    {
        printf("%d ",ideq[i]);
    }
	putchar('\n');

	//����
	const int FINDNUMBER = 19;
	printf("\n����%d\n", FINDNUMBER);
	pos = find(ideq.begin(), ideq.end(), FINDNUMBER);
	if (pos != ideq.end())
		printf("find %d success\n", *pos);
	else
		printf("find failed\n");

	//��ͷβɾ������
	printf("\n��ͷβɾ������...\n");
	ideq.pop_back();
	ideq.pop_front();

	//���deque
	printf("\n���deque������:\n");
	for (pos = ideq.begin(); pos != ideq.end(); pos++)
		printf("%d ", *pos);
	putchar('\n');
	return 0;
}
