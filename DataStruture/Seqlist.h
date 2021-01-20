#include "Sysutil.h"
#define ELEMTYPE int
#define SEQLIST_DEFAULT_SIZE 5
size_t i = 0;
typedef struct Seqlist
{
	//ָ������ڴ�ռ��ָ�롣
	ELEMTYPE *base;
	//���ٵ��ڴ�ռ��������
	size_t capacity;
	//���������ݵĴ�С
	size_t size;

}Seqlist;
//����Ľṹ�����͵�ָ�룬pstΪ�ṹ�����͵ģ�������int*
void SeqlistInit(Seqlist *pst);
void SeqlistPushBack(Seqlist *pst,ELEMTYPE x);
void SeqlistShowList(Seqlist *pst);
void SeqlistPushFront(Seqlist *pst, ELEMTYPE x);
void SeqlistPopBack(Seqlist *pst);
void SeqlistPopFront(Seqlist *pst);
int Seqlistlength(Seqlist *pst);
int SeqlistCapcity(Seqlist *pst);
void SeqlistClear(Seqlist *pst);
void SeqlistDestroy(Seqlist *pst);
void SeqlistSort(Seqlist *pst);
int SeqlistFind(Seqlist *pst, ELEMTYPE x);
void SeqlistDelVal(Seqlist *pst,ELEMTYPE item);
bool IsFull(Seqlist *pst)
{
	return pst->size >= pst->capacity;
}
bool IsEmpty(Seqlist *pst)
{
	return pst->size == 0;
}
void SeqlistInit(Seqlist *pst)
{
	pst->base = (ELEMTYPE*)malloc(SEQLIST_DEFAULT_SIZE * sizeof(ELEMTYPE));
	//pst->base = NULL;
	//����Ŀռ䲻Ϊ�գ��ټ������½��У���Ϊ�գ���������ʧ�ܣ�һ��Ҫassert��
	assert(pst->base != NULL);
	memset(pst->base, 0, sizeof(ELEMTYPE)*SEQLIST_DEFAULT_SIZE);
	pst->capacity = SEQLIST_DEFAULT_SIZE;
	pst->size = 0;
}
void SeqlistPushBack(Seqlist *pst, ELEMTYPE x)
{
	 assert(pst);
	//���Ļ������ܲ��룬�������Ļ��൱����Խ���ˡ�
	// assert(!IsFull(pst));
	 assert(!IsFull(pst));
	//��x���ڵ�size+1��λ�á���Ϊarr[i]������ǵ�i+1��Ԫ�أ���ΪĿǰ��˳����Ԫ��
	//��СΪsize,β��һ�������� size+1�ĵط����롣
	pst->base[pst->size] = x;
	pst->size++;
}
void SeqlistShowList(Seqlist *pst)
{
	assert(pst);
	size_t i = 0;
	for (i = 0; i<pst->size;i++)
	{
		printf("%d ", pst->base[i]);
	}
	printf("\n");
}
void SeqlistPushFront(Seqlist *pst, ELEMTYPE x)
{
	//����Ҫ����һ��
	assert(pst!=NULL);
	//����д�ǲ��Եġ�
	assert(IsFull(pst));
	//����
	for (i = pst->size; i>0;i--)
	{
		pst->base[i] = pst->base[i - 1];
	}
	pst->base[i] = x;
	pst->size++;
	//����д��
	//x = pst->base[i];
	//����д����Ӧ���ǰ�pst->size++,������base++;pst->base++;
}
void SeqlistPopBack(Seqlist *pst)
{
	if (IsEmpty(pst))
	{
		printf("˳����Ѿ��գ����ܱ�ɾ��\n");
	}
	pst->size--;
}
void SeqlistPopFront(Seqlist *pst)
{
	if (IsEmpty(pst))
	{
		printf("˳����Ѿ��գ����ܱ�ɾ��\n");
	}
	for (i = 0; i < pst->size; i++)
	{
		pst->base[i] = pst->base[i + 1];
	}
	//��һ�б���Ҫ�У�����size�����Ĭ�ϴ�СΪ0����ʼ����ʱ��Ϊ0��
	pst->size--;
}
int Seqlistlength(Seqlist *pst){ return pst->size; }
int SeqlistCapcity(Seqlist *pst){ return pst->capacity;}
void SeqlistClear(Seqlist *pst){ pst->size = 0; }
void SeqlistDestroy(Seqlist *pst)
{
	assert(pst);
	free(pst->base);
	//��̬���ٵ��ڴ�Ҫ�����ͷţ����������ڴ�й©��
	//��baseҪ��Ϊ��ָ�룬������������ڴ�й©��
	pst->base = NULL;
	pst->capacity = 0;
	pst->size = 0;
}
//ð�������˼��
//����ѭ�������ѭ������������������9,8,7�����մ�С�����˳��
//��һ�ˣ���9�������1����
//�ڶ��ˣ���8�������һ����
//��ô����Ҫ�������ˣ���Ϊ7��Ȼ�ڵ�һ����
//i��Ԫ����Ҫi-1��;
//9��8��7��6��5
//ÿһ�ˣ�9��Ŀ��ܣ���Ҫ4�αȽϡ�
//8�Ļ���Ҫ3�αȽϣ���Ϊ����Ԫ���Ѿ������
void SeqlistSort(Seqlist *pst)
{
	size_t j = 0;
	int max = pst->base[i];
	for (i = 0; i <(pst->size)-1; i++)
	{
		//����ÿһ��,������������
		for (j = 0; j < (pst->size) - 1 - i; j++)
		{
			//�ƺ�û���ã�
			//max = pst->base[j];
			if (pst->base[j]>pst->base[j + 1])
			{
				//����������;
				int tmp = 0;
				tmp = pst->base[j];
				pst->base[j] = pst->base[j + 1];
				pst->base[j + 1] = tmp;
			}
		}
	}
}
int SeqlistFind(Seqlist *pst, ELEMTYPE x)
{
	//˳����ҷ�;
	for (i = 0; i < pst->size; i++)
	{
		if (x == pst->base[i])
			return i+1;
	}
	return -1;
}
void SeqlistDelVal(Seqlist *pst,ELEMTYPE item)
{
	//�ٺ٣�����Ҫע��Ŷ������Ĳ�������Ϊpst,�������һ����ַ��������ȡ��ַ�ģ�
	int index = SeqlistFind(pst, item);
	if (index == -1)
		printf("Ҫɾ����Ԫ�ز�����\n");
	return;
	//for (i = item; i < pst->size; i++)
	//{
	//	pst->base[i] = pst->base[i + 1];
	//	//����Ԫ�ظ�������;
	//	pst->size--;
	//}
}