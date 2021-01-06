#include "myRect.h"
#include "myString.h"
#include "myBochka.h"
#include <iostream>

#define stop __asm nop

	// ������� � ��������
	//Rect BoundingRect(Rect r1, Rect r2)
	//{
	//	
	//	Rect temp((r1.Get()[0] + r2.Get()[0]), 
	//			 (r1.Get()[1] + r2.Get()[1]), 
	//			 (r1.Get()[2] + r2.Get()[2]), 
	//			 (r1.Get()[3] + r2.Get()[3]));

	//	return temp;	//	���������� �������� �������� � ������� ������������ ����� ��������
	//					//	�� ����� � ������� ����������������� ���������� ��������
	//};

	Rect BoundingRect(Rect r1, Rect r2)
	{
		
		int x1, x2, y1, y2, xx1, xx2, yy1, yy2;
		r1.GetAll(&x1, &x2, &y1, &y2);			// ����� GetAll
		r2.GetAll(&xx1, &xx2, &yy1, &yy2);		// ����� GetAll
		int res1 = (x1 > xx1) ? x1 : xx1 ;		// ���� ����� ������� ������� �������������� ������ 
												// ����� ������� ������� ��������������
		int res2 = (x2 > xx2) ? x2 : xx2;		// ��� ����� ������ ������ �������
		int res3 = (y1 > yy1) ? y1 : yy1;					// � �.�.
		int res4 = (y2 > yy2) ? y2 : yy2;
		Rect temp(res1, res2, res3, res3);		// ����������� � �����������

		return temp;							// ����������� �����������
		// ���������� r2
		// ���������� r1
	};

	// ������� � ��������
	Rect BoundingRect2(const Rect& r1, const Rect& r2) 
	{
		const int* p1 = r1.Get();
		const int* p2 = r2.Get();
		Rect temp((p1[0] + p2[0]),
				  (p1[1] + p2[1]),
				  (p1[2] + p2[2]),
				  (p1[3] + p2[3]));

		delete p1;
		delete p2;
		return temp;	//	���������� �������� �������� � ������� ������������ ����� ��������
						//	�� ����� � ������� ����������������� ���������� ��������
	};

int main()
{
	setlocale(LC_ALL, "Rus");
	using namespace std;
	{
	//������� 1.���������� ������. �������� ���������� ������.
	//����� ������� ������. 
	//�������� �������� Class View - (����� �� ������� ����� ������� �
	//������ - ������� Rect � MyString)
	//�������� �������� �� ����������� ����� �� ���� ������ ������ - ���
	//���������� ������������ ������� � ������� ����� ������.

	//����� ����������� ���������� ��� �������� ���������� ������?
	
		Rect rect;		// ����� ������������ �� ��������� ( � ������� ������ ��� ������)
		stop			// ������, ������ � ������ ������������� ������������ � ����������� � ����������� ������������� ������������ ��� ����������
	

	//1a. �������� � ���������� ����������� � ����������� ���
	//������������� ���������� ������. �������� ��������� ������ Rect
	//� ������� ������������ � �����������. ���� ���������� ������
	//������ � ���������� ���������, ��������� - ���� ��� ��
	//�������? ��������� ���������� ������.
	//�������� ������� � ������ ������ �� �����, ����������:
	//� ����� ������ ���������� ����� ������������(������?)?

	//���������*: ������ ���� �� ������ ��� ����, ��� �������������
	//����� ��������� "�����������������", �� ���� m_left>m_right ���/�
	//m_top>m_bottom
	//���������: ������, ��� ������������ ������ ������ ����� ���������
	//� �������� ���������� ����� ��������! ��������:

	//! ��� ��������� ��������� ������������� � ������� ���������.
	// left - right - top - bottom
		Rect rrr(4,4,3,3);		// ���������� ������� ��������� � ������� ����������� � �����������


		stop
	//1�. ��� ��������������� ������� ����������� ������������ ��� ����������
	//������������� ������������� ���������� ������, ��������, �����

		Rect rrr2;			// m_left = 0; m_right = 0; m_top = 0; m_bottom = 0


		stop
		//1�. ��������, ���������� � �������� ����� ������ InflateRect(), 
		//������� ����������� ������� �������������� �� �������� ����������
		//(��������� ������� �� ������ - ������ ������� �� ���� ��������).
		//���������: �������� � ���������� ������ ����� �� ������ "�������",
		//�� � � ������� Wizard-a Class View. ��� �����: �������� ��������
		//ClassView ���� �������, �������� �������� ����� Rect � �������
		//������ ������ ���� - � ����������� ����������� ���� ��������
		//Add/Add Member Function... � ������� ����������� ���������� ������
		//"����� ��������" Wizard-� ��� �������� � ���������� �����.

		rrr.InflateRect(2, 1, 3, 4);


		stop
	}

	//������� 2.���������� ������������� � ������� ������.
	//����������� �����������.
	{
		//2�.�������� � ���������� ����������� ����������� � ������ Rect.
		//�������� ������� �� �����, ����������, �����
		//����������� ���������� ��� �������� r1,r2,r3 � r4?
		//���� ����� ���������� ��������� ��������?
		Rect r1;					// ����� ������������ �� ��������� {m_left=0 m_right=0 m_top=0 ...}
		Rect r2(1, 2, 3, 4);		// ����� ������������ � ����������� {m_left=1 m_right=2 m_top=3 ...}
		Rect r3 = r1;				// ����� ������������ �����������(���������� �����)    {m_left=0 m_right=0 m_top=0 ...}
		Rect r4(r2);				// ����� ������������ �����������(��������������� ����� ������) {m_left=1 m_right=2 m_top=3 ...}
		stop


		//2�. �������� � ���������� � ������ Rect ����� InflateRect(),
		//������� ��������� ��� ���������, �� ��������� ������ 1, � 
		//���������� ������� �������������� �� �� �������� ����������.
		//��� ����� �������� ���������� ������� InflateRect()?

		r1.InflateRect(1,1);			// ������ ����� � ����� �����������   r1 {m_left=1 m_right=1 m_top=1 ...}
		r2.InflateRect(2,2);			// ������ ����� � ����� �����������   r2  {m_left=3 m_right=4 m_top=5 ...}
		//����� �� ������� InflateRect() ���������� � ������ �� ���� �������?
		r3.InflateRect(2,2,2,2);		// ������ ����� � ������� �����������  r3 {m_left=2 m_right=2 m_top=2 ...}
		r3.InflateRect(3,3);			// ������ ����� � ����� �����������    r3 {m_left=5 m_right=5 m_top=5 m_bottom=5}
		r3.InflateRect(5);				// ������ ����� � ����� �����������    r3 {m_left=10 m_right=10 m_top=6 m_bottom=6}
		r3.InflateRect();				// ������ ����� � ����� �����������    r3 {m_left=11 m_right=11 m_top=7 m_bottom=7}
		stop

	}
	
	//������� 3.������������� �������. ������������. 
	{
		Rect r;
		//���������������� ��������� ������. ��������� ������
		//�����������

		//int tmp = r.m_left;			// ��� ������� � ���������� ���� ������  // ������ �������� � ��������� ������� ������ ���� ������ � ����


		//������� � ����� Rect ����� void SetAll(...),
		//������� ����������� ���������� ������ ������������
		//��������. �������� ��������� �����, ��������� ������������. 
		r.SetAll(4, 5, 3, 6);

		//������� � ����� Rect ������ ����� GetAll(...),
		//������� "�������" �������� private-���������� ������.
		//�������� ��������� �����, ��������� ������������. 
	
		// ������� � ��������
		 int a = r.Get()[0];	// 4

		 // ������� ������� � �����������
		 int x1, x2, y1, y2;						// ������� �������� � ������� ����� ���������� ��������� ����
		 r.GetAll(&x1, &x2, &y1, &y2);

		 stop
		// ��� ������� ����� ����������� ������ ��� ����� ��������� �������  ���  ������� ������ ����
	}

	{
		//������� 4.�������� ���������� ������ � �������� ���������
		//�������. ����������� ������� ������ �� ��������. ��������
		//�������� � ������������ ����������� ��� �������� ��������
		//�� �����, ����������: � ����� ������ ���������� ���������
		//� ������������ �����������. 
		//�������� ���������� ������� 
		// Rect BoundingRect(Rect, Rect);
		//������� ��������� ��� ������� ������ Rect �� �������� �
		//���������� ������ ������ Rect, ������� �������� ���������������,
		//� ������� ������� �������� ��������������. ��� ����������
		//�������� ���������� � ����������� ������� ������?
		{
			// ���������� ��������� ������������� ������ �� ��������
			//Rect r3 = BoundingRect(Rect(2, 2, 2, 2), Rect(5, 5, 3, 3));

			Rect r1(1, 2, 3, 4), r2(5, 6, 7, 8), r3;
			// 1. ����������� � ����������� ��� r2  + Normalize()	
			// 2. ����������� � ����������� ��� r1 + Normalize() 

			r3 = BoundingRect(r1, r2);				//  {m_left=6 m_right=8 m_top=10 m_bottom=12}
			// 1. ����������� ����������� ��� r2
			// 2. ����������� ����������� ��� r1
			// 3. ������� BoundingRect()
			// 4. ������ ������� - ����� Get()
			// 5. ����������� � �����������
			// 6. ������� �����������
			// 7. �������
			// 8. ����������
			stop

			//	//������� 4�. �������� �������� �� ������.
			//	//�������� ���������� ������� BoundingRect2, ������� ��������� �� ��
			//	//������, �������� ��������� �� ������
			//	//���������� �� ������������ ��� �������� ����������?

			r3 = BoundingRect2(r1, r2);			// {m_left = 6 m_right = 8 m_top = 10 m_bottom=12}
			// 1. �������
			// 2. ����� Get()
			// 3. ����������� � �����������
			// 4. ����������� �����������
			// 5. �������
			stop
		}

		//������� 4�.���������� �� �� ������ (BoundingRect) ������� ������
		Rect r1(1, 2, 3, 4), r2(5, 6, 7, 8), r3;

		r3.BoundingRect(&r1, &r2);		// {m_left = 6 m_right = 8 m_top = 10 m_bottom=12}
		
		stop
	}

	//������� 5. ����� ���������� ������������ � �����������.
	//�������� � ����������
	//����� ���������� ������. ��������� �������� � 
	//������������ (�������������) � �����������. ����������: ����� ���
	//������� �� �������� ���������� �����������, � ����� - ����������?
	{
		Rect r1;							// �������� ������� � ������������� �� ��������� {m_left=0 m_right=0 m_top=0 ...}
		Rect*	pR = new Rect(1,2,1,2);		//  ������������ �������� ������� � ����������� (���������� ���� �� ���������� ����)
		{
			Rect r2(r1);		// ����� ����������� ����������� {m_left=0 m_right=0 m_top=0 ...}
			Rect arRect[2];		// ������ �� ���� �������� Rect (���������� ����������� �� ���������)
			for(int i=0; i<3; i++)
			{
				static Rect r3 (i,i,i,i);		// ����� ������������ � ����������� ��� ������ ����������, ����� ����������� � ����� ���������
				Rect r4(*pR);					// ����� ������������ ����������� �� ��������� pR {m_left=1 m_right=2 m_top=1 ...}
				Rect r5(i,i,i,i);				// ����� ������������ � ����������� 
				
				// ����� ����������� ��� r4
				// ����� ����������� ��� r5
			}
		// ����� ����������� ��� r2
		// ����� ����������� ��� arRect
		}

		// �������� ������������� �������
		delete pR;		// ����� �����������
		stop
		
		// ����� ����������� ��� r1
	}

 
	//������� 6.����������� + ���������� = ��������������
	// ���������. ����� MyString
	// ����������� ������������ (�������������) � ����������� ����������
	//���������� ������������� � ����������� �������
	//C ������� ��������� ���������� ����� ����������
	//������ � ������������ ������ ��� ������-����� ������
	{
		// ���� ����������� ����������� ���������� � ������ ����������
		MyString s1;
		MyString s2 = s1;
		stop
	}

	{
		MyString	str1("It's my string1!");
		//�������� ����� GetString(), ������� ��������� ������ � ���������� ������.
		//� ������� cout � ������ GetString() ������������ ������ ������� str1
		//���������: ���������, ��� ������� ��������� ����������� ����� GetString().


		//��������� 1:
		//����������� ���� ��� ������ ��������:
		std::cout<<str1.GetString()<<std::endl;		// "It's my string1!"

		//��������� 2:
		//����������� ���� ��� �� ������ ��������:
		//str1.GetString()[1] = 'W';				// ������ ������ ������ � ����������� ������
													// ����� ������� const char* GetString()
		//��������� 3:
		//����������� ���� ��� ������ ��������:
		const MyString	str2("It's my string2!");	// ����� ������� char* GetString() const
		std::cout<<str2.GetString()<<std::endl;		// "It's my string2!"  
	}
	stop

	{
		//6a. ���������������� ��������� ��������. ��������� - �����
		//������������ ��� �������. ���������� ��������� ��������� (���?)
			{
				// � ����������� ����������� �������� �������� ������ ��� ���� char* m_pStr
				MyString str1("The first string!");
				MyString str2 = str1;
			}
			stop

				//6�. ���������� ����� SetNewString, ������� ����� �������� ������
				// �� �����

			MyString str3;
			char arr[] = { "It's my string3!" };
			str3.SetNewString(arr);

			std::cout << str3.GetString() << std::endl;

	}

	{
		//������� 7.  ������ � ������� ������� ��������� ������:
		//���� ��� ����� ���������� ������. � ����� ����� � ��������� ������
		//������� ���������� ����� (96%), � ������ � ����.
		//������� �������� 1� ���������� ���������� ���������� �� ����� �����
		//� ������ ��������� ��������: �� ������ ��������
		//���������� �� ������ ����� -> ������ �� ������
		//���������� �� ������ ����� -> ������ � ������.
		//��������� ���������� ����� ��������, �� ������� ������������ ������ �
		//������ ����� ������ ������ 50%.

		int iter = 0;
		Bochka spirt(100, 0.96);
		Bochka water(100, 0);

			while(spirt.getSpirt() > 0.50)			// ����� �� // {m_volume=100.000000 m_spirt=0.499959260 }
			{
				iter++;
				spirt.Pereliv(water);	//��� spirt.Pereliv(water, �����_������);
				water.Pereliv(spirt);	// ����������
				stop
			}
		std::cout << "���������� �����������:" << iter << std::endl;		// 159
	}	


return 0;

}//end_main
