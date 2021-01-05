// ����:
// ������� ������������. ����������� �������. ����������� ������.
// ������� ����.
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <tchar.h>
#include"MyString.h"
#include "Rect.h"
#include "Circle.h"
#include "Shape.h"
#include <cstdarg>


#define	  stop __asm nop

// ������� ����������  ��������� �����
//���������� ���������� �� ������ � ���������� � ���� �����������
	MyString __cdecl JoinToSentence(const char* str1, ...)
	{
		MyString mystr;

		//char* p = reinterpret_cast<char*>(&n) + sizeof(int);		// ��������������� ��������� �� ������ �������
		int count = 0;												// ������� �������� � ������ 
		int size = 0;												// ������ �����������
		const char* p = str1;										// ��������� �� ������ ������

		// ������ ������ ����� ������
		// ���� �� ���������� ����������
		while (p)
		{
			// �������� �� ������ ���������
			if (!p)
			{
				continue;
			}
			// ���� �� ��������
			while (*p)
			{
				std::cout << *p << " ";
				p++;
				count++;											// ������� ���������� ��������
			}
			p +=  1;												// ��������� � ���������� ��������	// +1 ��� ���������� ����
			size += count + 1;										// ����������� �������� ������� �����������	// +1 ���������� ����
			count = 0;												// �������� ��� ��������� ������
		}

		char* temp = new char[size];								// ������� ������ ��� �����
		temp[0] = 0;
		p = str1;

		// ���������� � ��������� �����������
		while (p)
		{
			strcat(temp, p);			// ��������� ������ � ���������
			int size = strlen(p);		// ������ ������ ������
			p += size;					// ��������� �� ������ ������ ������, � ���������� ���������
		}
		// ������ ���������� � ������ �� ���� ������
		mystr.SetNewString(temp);

		//delete[] i;
		delete[] p;
		delete[] temp;
		return mystr;
		
	}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Rus");
	//������� 1.������ �������� ������.
	{
	//�������� � ������������������ ������ ar �� ��������
	 //���� MyString. 
		const int N=5;
		MyString str1[N] = {MyString("Egor"), MyString("Ivan"),MyString("Kolja") };
  
	//�������� - ������ �����-������ ������
		for (size_t i = 0; i < N; i++)
		{
			std::cout << str1[i].GetString() << std::endl;	// Egor
															// Ivan
															// Ivan
															// empty...
															// empty...
		}
				
	//�������� ������ const int N=5; , �� ������� ������ ���������������.
			
	}
	stop

	//������� 2.������ ���������� �� ������� ������.
	{
	//�������� � ������������������ ������ arPtr �� N
	//���������� �� ������� ���� MyString (���� ������� 
	//��������� �����������!).
		const int M = 5;
		MyString* str2[M] = {new MyString("Egor"), new MyString("Ivan"), new MyString("Kolja") };
		//������ �����-������ ������
		for (size_t i = 0; i < M; i++)
		{

				std::cout << str2[i]->GetString() << std::endl;	// Egor
																// Ivan
																// Kolja
		}				
		// ���  str2[3]->GetString()  str2[4]->GetString()
		// ������ // �� �������� ������, this  = nullptr. str2[3] - (0x00000000 <NULL>)
		// ������ // �� �������� ������, this  = nullptr. str2[4] - (0x00000000 <NULL>)

		for (size_t i = 0; i < M; i++)
		{
			delete str2[i];
		}

		//�������� ������ const int N=5; , �� ������� ������ ���������������.

	}
		stop

	{
		//������� 3.������� ������������.��������� ������������,
		// ������������ � ������� �����.

		//�������� �������� �������:
		//������� ����� Shape (������� ��������� ����� ������)
		//� ��� ����������� ������ Rect � Circle.
		//���������: ����� ������ � ������ ����� ������ � �������
		//� ����������� ������ (��������, ����� ������ ����� �������
		//������� => � ������� ������ ����� ������ ����������, �������
		//����� ���������� ���� ������.
		//���������: ��� �������� ����� �������� ������������ (RED,GREEN,BLUE...);

		Rect rect(1,2,3,4,Shape::GREEN);
		// ������� ������ �������������
		// Shape() -> Rect()

		 std::cout << rect.GetColor() << std::endl;

		 Circle circle(-4, 4, 5, Shape::GREEN);
		 // ������� ������ �������������
		 // Shape() -> Circle()
	
		 std::cout << circle.GetColor() << std::endl;

		 // ������� ������������
		 // ~Shape() > ~Circle() > ~Shape() > ~Rect()

		//� ������������� ����������� ������� ������������� ��������
		//���������-����� ������������ �������� ������.
		//��� �������� � ����������� ������� ������������ ���� ����������
		//������������������ ������� ������������� � ������������ ��������
		//� ������������ �������

		 
		stop
	}

//////////////////////////////////////////////////////////////////////

	//������� 4.����������� �������.
	//4�) ������������� ������ Shape,Rect � Circle:
	//�������� � ������ ����� public ����� void WhereAmI().
	//���������� ������ ������� ������ �������� ��������� 
	//���������� ���� "Now I am in class Shape(Rect ��� Circle)".
	//��������� ����������� ��������, ��������� ���������.


	{
		Shape s;
		Rect r(-4, 4, 10, -10, Shape::GREEN);
		Circle c(5, 5,4, Shape::YELLOW);

	
		//����� ������ ������ ���������� � ��������� ��������???
		s.WhereAmI();	//	����� ������ Shape
		r.WhereAmI();	//	����� ������ Rect
		c.WhereAmI();	//	����� ������ Circle
		stop


		Shape* pShape = &s;
		Shape* pRect = &r;
		Shape* pCircle = &c;
    	pShape->WhereAmI();	//	����� ������ Shape
		pRect->WhereAmI();	//	����� ������ Shape
		pCircle->WhereAmI(); //	����� ������ Shape
		stop


		//��������� ... �������� ������������
		Shape& rShape = s;	//��������� s
		Shape& rRect = r;	//��������� r
		Shape& rCircle = c; //��������� c
		rShape.WhereAmI();	//����� ����������� rShape	// ����� ������ Shape
		rRect.WhereAmI();	//����� �����������	rRect	// ����� ������ Shape
		rCircle.WhereAmI(); //����� ����������� rCircle	// ����� ������ Shape
		stop
	}

	//4�) �������� � ������� � ����������� ������ �����������
	// ����� WhereAmIVirtual(). �� �������� � 4� ��������
	// ����������� ����� ����������� ��������, ���������� �
	// ������, ������������ � ���������� ���������.
	//��������� ����� ��������, ��������� �������.
	{
		std::cout << "\n������� 4.�" << std::endl;
		Shape s;
		Rect r(-4, 4, 10, -10, Shape::GREEN);
		Circle c(5, 5,4, Shape::YELLOW);

	
		//����� ������ ������ ���������� � ��������� ��������???
		// �� �������! �� �������, �������� ������������ �������������, ����
		// ����� ������ �������������� ����������� ��������� ��� ������.
		// ������ ��� ��� �� ���������
		s.WhereAmIVirtual();	//	����� ������ Shape
		r.WhereAmIVirtual();	//	����� ������ Rect
		c.WhereAmIVirtual();	//	����� ������ Circle
		stop

		
		Shape* pShape = &s;
		Shape* pRect = &r;
		Shape* pCircle = &c;
		pShape->WhereAmIVirtual();	//	����� ������ Shape
		pRect->WhereAmIVirtual();	//	����� ������ Rect
		pCircle->WhereAmIVirtual(); //	����� ������ Circle
		stop


		//��������� ... �������� ������������
		Shape& rShape = s;	//��������� s
		Shape& rRect = r;	//��������� r
		Shape& rCircle = c; //��������� c
		rShape.WhereAmIVirtual();	//����� ����������� rShape	// ����� ������ Shape
		rRect.WhereAmIVirtual();	//����� �����������	rRect	// ����� ������ Rect
		rCircle.WhereAmIVirtual(); //����� ����������� rCircle	// ����� ������ Circle
		stop

		//	~Shape() > ~Circle() > ~Shape() > ~Rect() > ~Shape()
	}


//////////////////////////////////////////////////////////////////////

	//������� 5.����������� �����������.
	//������������� ������:
	//a) ������� ���������������
	// ����������� (��� ��������� ����� virtual).
	//���������� ������� �����������
	//������ �������� ��������� ���������� ����
	// "Now I am in Shape's destructor!" ���
	// "Now I am in Rect's destructor!"
	//��������� ��������. ��������� ���������.
	{
		std::cout << "\n������� 5" << std::endl;
		Shape s;
		Rect r(-4, 4, 10, -10, Shape::GREEN);
		Circle c(5, 5, 4, Shape::YELLOW);

		//Now I am in Circle's destructor!
		//Now I am in Shape's destructor!
		//Now I am in Rect's destructor!
		//Now I am in Shape's destructor!
		//Now I am in Shape's destructor!
	}

	// b) �������� � ���������� ������������ �������� ����� virtual 
	//��������� ��������.��������� �������.
	{
		std::cout << "\n������� 5.�" << std::endl;
		Shape* s = new Shape();
		Rect* r = new Rect(-4, 4, 10, -10, Shape::GREEN);
		Circle* c= new Circle(5, 5, 4, Shape::YELLOW);
		//  ����������� �� ����������

		delete s;
		delete r;
		delete c;
	/*	Now I am in Shape's destructor!
		Now I am in Rect's destructor!
		Now I am in Shape's destructor!
		Now I am in Circle's destructor!
		Now I am in Shape's destructor!*/
		stop
	}
	
	//���������: ����� ������������ ���������� � ��������� ������?
		//���� � ������������� ������� �����-�� �������������
		//�� ������� - ����������
		//���� �� ��������, ��� � ����������� ��������� ����-��
		//�� ������� - ��������
	{
		//Rect r(-4, 4, 10, -10, Shape::GREEN);
		//Shape* ar[] = { new Shape(r), new Rect(r), new Circle(r), new Circle() };
		//�������� ��� ������� �������� ������� ����� WhereAmIVirtual()


		stop
	}


	//������� 6*. � ��� ����������� ������� 1) � 2)
	{
		Shape* pShapes = new Rect[10];//1)
		Rect* pRects = new Rect[10];//2)

		//���������� ������� ����� WhereAmIVirtual() ��� ������� �������� ����� �������� -
		//� ��� ����������� ��������???
		//for (size_t i = 0; i < 10; i++)
		//{
		//	pShapes[i].WhereAmIVirtual();	// ����� ������ Rect
		//  // ������ ��� ������ pShapes[1].WhereAmIVirtual()
		//}

		for (size_t i = 0; i < 10; i++)
		{
			pRects[i].WhereAmIVirtual();	// ����� ������ Rect
		}
		

		//���������� ����������� ����������� ������
		// �������� ������� �������� pShapes
			delete[] pShapes;
		// �������� ������� �������� pRects
			delete[] pRects;
	}



//////////////////////////////////////////////////////////////////////

	//������� 7.����������� ������� � �������� ���������� ������� ���������. 

	{
		Rect r(-4, 4, 10, -10, Shape::GREEN);
		Shape* p = &r;	
		p->WhereAmIVirtual();  // ����� ������ Rect
		stop


		//4a �������� ���������� ������� ���������.
		//����������� ������� r � ��������� p �������� ����������� �������
		//WhereAmIVirtual()������ Shape

		p->Shape::WhereAmIVirtual(); // ����� ������ Shape

		// ���������� Rect
		// ���������� Shape
	}


//////////////////////////////////////////////////////////////////////
/*
	//������� 8.����� ����������� �������. 
	//������� � ������� ����� ����� void Inflate(int); ���������:
	//����� �� ����������� ����� ����� ��� �������� ������? => ��� ��� ����� ��������.
	//���������� ���� ����� ��� ����������� �������.
	{
		Rect r(...);
		Shape* p = &r;
		p->Inflate(5);
		Circle c(...);
		p = &c;
		p->Inflate(5);
	}
*/


//////////////////////////////////////////////////////////////////////
	//������� 9. �������� ���������� �������, ������� ����� ��������� �����
	//���������� ���������� �� ������, � ���������� ������ MyString,
	//� ������� ������ ����� ������������� ����������
	

	MyString str = JoinToSentence("My", "Name", "is", "Sergey", nullptr);	

////////////////////////////////////////////////////////////////////////
/*
	//������� 10.����������� (union) C++. ������� ����.
	//1.
	//�������� ��������� ������ ��� ��������� ������������� �������� �����:
	//Bin - ��� ��������� �������������
	//Hex - ��� ����������������� �������������
	//Oct - ��� ������������� �������������.
	//��������� 1: - ��� �������� ����������� ������� ����.
	//��������� 2: - ������������� � ����� ��������������� ������� ���� �� ������,
	//��� ��� ��� ��� ����� ������� ����������� (union).
	//2.
	//� ������ ������ ������� ����� Show, ������� ������ �������� �������� �
	//��������������� ����
	//3.
	//����������� ����������� MyByte ������������ ������������ ����������� ��������������
	//����� � ��� �� ��������� ��-�������:
	//�) ��������: ����������, �����������������, ������������, �������� �������� ����� 
	//          � ����� ������, ��������������� ��������� �������� (���� ���� ������������);
	//�) �������� ��������� (��������� ����������� ���������) �����������������,
	//			������������, �������� �����;
	//�) �������� ��������� ��������, ������������ ��� ����������������� �����;

	MyByte byte(0x1f);
	byte.ShowHex();
	byte.ShowBin();
	//...


*/
	return 0;
}//endmain

