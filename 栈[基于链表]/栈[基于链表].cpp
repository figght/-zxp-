// 栈[基于链表].cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

/**************顺序不可变!!!*************/
#define LEN_LStack_DEF		sizeof(struct tagLStack)
#define	TURE				(1)
//#define FALSE				(0)
#define FAIL				(0)
#define UNDERFLOW			(-1)//下溢
#define OVERFLOW			(-2)//上溢
typedef int ElemData;

typedef struct tagLStack{
	ElemData data;
	struct tagLStack * next;
}LStack;
/*****************end********************/

void LClearStack(LStack * top);			//置空栈
int LEmptyStack(LStack * top);			//检测栈是否为空
int LPush(LStack ** top, ElemData data);	//压栈
ElemData LPop(LStack ** top);			//弹栈
void ClearStdin();						//消除输入流中的错误输入
int Conver10_d(int n,int m);

int main()
{
	int jinzhi,zhi;

	printf("要转换的进制为:");
	while (scanf_s("%d", &jinzhi) == 1)
	{
		ClearStdin();
		printf("要转换的值为:");
		while (scanf_s("%d",&zhi) == 1)
		{
			ClearStdin();
			Conver10_d(jinzhi,zhi);
			printf("要转换的值为:");
		}
		printf("要转换的进制为:");
	}
}

void LClearStack(LStack * top)
{
	LStack * p;
	
	p = top;
	while (p != NULL)
	{
		p = p->next;
		free(p);
	}
	free(top);
	top = p;
}

int LEmptyStack(LStack * top)
{
	if(top == NULL)	return TURE;
	else return FALSE;
}

int LPush(LStack ** top, ElemData data)
{
	LStack *p;
	if ((p = (LStack *)malloc(LEN_LStack_DEF)) == NULL)return FAIL;
	p->data = data;
	p->next = *top;
	*top = p;
	return 0;
}

ElemData LPop(LStack * *top)
{
	ElemData data;
	LStack * p;

	if(LEmptyStack(*top))return UNDERFLOW;
	else {
		p = *top;
		data = (*top)->data;
		*top = (*top)->next;
		free(p);
		return data;
	}
}

void ClearStdin()
{
	while (getchar() != '\n');
}

int Conver10_d(int n, int m)
{
	ElemData t,zz = 0;
	LStack *top = NULL;

	//s = (LStack *)malloc(LEN_LStack_DEF);
	
	while (m != 0)
	{
		t = m % n;
		m = m / n;
		LPush(&top,t);
	}
	while (!LEmptyStack(top))
	{
		t = LPop(&top);
		zz = zz * 10 + t;
	}printf("转换的值为:%d\n", zz);
	return zz;
}
