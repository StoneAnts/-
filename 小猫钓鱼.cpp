#include<iostream>
#include<stdio.h>
using namespace std;

typedef struct queue      //队列结构体
{
	int data[100];
	int head;
	int tail;
}queue;

typedef struct stack   //栈结构体
{
	int data[100];
	int top;
}stack;

void play(queue q1, queue q2, stack s)
{
	int i, j, n;

	q1.head = q2.head = q1.tail = q2.tail = 0;  
	s.top = 0;
	for(i = 0; i < 6; i++)    //小哼手中的牌，6张
	{
		cin >> q1.data[i];
		q1.tail++;
	}

	for(i = 0; i < 6; i++)  //小哈手中的牌，6张
	{
		cin >> q2.data[i];
		q2.tail++;
	}

	while(q1.head != q1.tail && q2.head != q2.tail)  //当两个队列都不为空时
	{
		s.data[++s.top] = q1.data[q1.head];   //小哼出牌，放到桌子上（出队，进栈）
		q1.head++;
		n=s.top;							//记录此时桌上的牌数
	
			for(i = 1; i < n; i++)
		{
			if(s.data[i] == s.data[n])     //有相同的牌，依次把牌放到手上（出栈，进队）
				for(j = n; j >= i; j--)
				{
					q1.data[q1.tail] = s.data[j];
					s.top--;
					q1.tail++;
				}
		}
		
		s.data[++s.top] = q2.data[q2.head];  //小哈出牌
		q2.head++;
		n=s.top;							//记录此时桌面上的牌
		for(i = 1; i < n; i++)
		{
			if(s.data[i] == s.data[n])		//有相同的牌，依次把牌放到手上（出栈，进队）
				for(j = n; j >= i; j--)
				{
					q2.data[q2.tail] = s.data[j];
					s.top--;
					q2.tail++;
				}
		}
	}

	if(q1.head == q1.tail)
	{
		cout << "小哈赢啦!" << endl;
		cout << "小哈手中的牌是:";

		for(i = q2.head; i < q2.tail; i++)
		{
			cout << q2.data[i] << " ";
		}
	}

	else if(q2.head == q2.tail)
	{
		cout << "小哼赢啦!" << endl;
		cout << "小哼手中的牌是";
		for(i = q1.head; i < q1.tail; i++)
		{
			cout << "q1.data[i]" << " ";
		}
	}

	cout << "桌上还剩" << s.top << "张牌" << endl;
	cout << "那些牌分别是";

	for(i = 1; i <= s.top; i++)
	{
		cout << s.data[i] << " ";
	}
}

int main()
{
	queue q1, q2;	//q1为小哼，q2为小哈
	stack s;			//桌子上的牌栈
	
	play(q1, q2, s);

	return 0;
}

