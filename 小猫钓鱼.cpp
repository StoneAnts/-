#include<iostream>
#include<stdio.h>
using namespace std;

typedef struct queue      //���нṹ��
{
	int data[100];
	int head;
	int tail;
}queue;

typedef struct stack   //ջ�ṹ��
{
	int data[100];
	int top;
}stack;

void play(queue q1, queue q2, stack s)
{
	int i, j, n;

	q1.head = q2.head = q1.tail = q2.tail = 0;  
	s.top = 0;
	for(i = 0; i < 6; i++)    //С�����е��ƣ�6��
	{
		cin >> q1.data[i];
		q1.tail++;
	}

	for(i = 0; i < 6; i++)  //С�����е��ƣ�6��
	{
		cin >> q2.data[i];
		q2.tail++;
	}

	while(q1.head != q1.tail && q2.head != q2.tail)  //���������ж���Ϊ��ʱ
	{
		s.data[++s.top] = q1.data[q1.head];   //С�߳��ƣ��ŵ������ϣ����ӣ���ջ��
		q1.head++;
		n=s.top;							//��¼��ʱ���ϵ�����
	
			for(i = 1; i < n; i++)
		{
			if(s.data[i] == s.data[n])     //����ͬ���ƣ����ΰ��Ʒŵ����ϣ���ջ�����ӣ�
				for(j = n; j >= i; j--)
				{
					q1.data[q1.tail] = s.data[j];
					s.top--;
					q1.tail++;
				}
		}
		
		s.data[++s.top] = q2.data[q2.head];  //С������
		q2.head++;
		n=s.top;							//��¼��ʱ�����ϵ���
		for(i = 1; i < n; i++)
		{
			if(s.data[i] == s.data[n])		//����ͬ���ƣ����ΰ��Ʒŵ����ϣ���ջ�����ӣ�
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
		cout << "С��Ӯ��!" << endl;
		cout << "С�����е�����:";

		for(i = q2.head; i < q2.tail; i++)
		{
			cout << q2.data[i] << " ";
		}
	}

	else if(q2.head == q2.tail)
	{
		cout << "С��Ӯ��!" << endl;
		cout << "С�����е�����";
		for(i = q1.head; i < q1.tail; i++)
		{
			cout << "q1.data[i]" << " ";
		}
	}

	cout << "���ϻ�ʣ" << s.top << "����" << endl;
	cout << "��Щ�Ʒֱ���";

	for(i = 1; i <= s.top; i++)
	{
		cout << s.data[i] << " ";
	}
}

int main()
{
	queue q1, q2;	//q1ΪС�ߣ�q2ΪС��
	stack s;			//�����ϵ���ջ
	
	play(q1, q2, s);

	return 0;
}

