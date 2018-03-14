#include"CySeqList.h"

int main()
{
	SeqList* s;
	SeqListInit(&s);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPrint(s);
	printf("\n");
	SeqListPushFront(&s, 2);
	SeqListPushFront(&s, 1);
	SeqListPushFront(&s, 0);
	SeqListPrint(s);
	printf("\n");
	printf("����0?>%d\n", SeqListFind(s, 0)->_data);
	printf("����1?>%d\n", SeqListFind(s, 1)->_data);
	printf("����2?>%d\n", SeqListFind(s, 2)->_data);
	printf("����3?>%d\n", SeqListFind(s, 3)->_data);
	printf("����4?>%d\n", SeqListFind(s, 4)->_data);
	printf("����5?>%d\n", SeqListFind(s, 5)->_data);
	printf("����6?>%d\n", SeqListFind(s, 6));
	printf("��������>%d\n", SeqListLength(s));
	printf("�м�Ԫ��>%d\n", SeqListMid(s)->_data);
	printf("�ж��Ƿ���ѭ������>%d\n", SeqListFloyd(s));
	/*SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPrint(s);
	printf("\n");*/

	/*SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPrint(s);
	printf("\n");*/

	system("pause");
	return 0;
}