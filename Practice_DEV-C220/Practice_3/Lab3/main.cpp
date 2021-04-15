
#include <string>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <iterator>
#include <memory>
#include"functions.h"
#include <vector>
#include"MySaveClass.h"
#include <list>
#include"MyArray.h"

using namespace std;

int main()
{
	
	//������� 1. ����� ��������� �������� (Raw String Literals)
	//�������� ������, ��������: my name is "Marina"
	//�) ��� ������������� Raw String Literals
	//�) ����������� Raw String Literals
	//�) �������� ����������� (Delimeter)

	{
		std::cout << "my name is \"Marina\"" << std::endl;

		std::string str1 = R"(my name is "Marina")";							// ������������� ������� R  - �������������� ����������� �� ������������ \<������>
		std::cout << str1 << std::endl;

		std::string str2 = R"delimeter(my name is "Marina")delimeter";			// ������������� delimeter
		std::cout << str2 << std::endl;
		__asm nop
	}

	//////////////////////////////////////////////////////////////////////////////////////////////
	//������� 2. ���������� ���������� ���������� � ������� constexpr-�������.
	//
	//���������/�����������: 
	//		- constexpr � ������� ������ �������� �� ������������ ���������� return <���������>; (����!)
	//		- �� ��� ��������� ����� �������� ����� ������ constexpr � �������, � ��������� �����������
	//		  ����� 
	//		- ���� �������� ����������� constexpr- ������� - ��� ���������, ���������� �������� ���������
	//		  �� ����� ����������

	//��������� ��� ����, ��� ���������� ��������� �������� �� ����� ���������� (���� � ��������
	//				��������� ������������ ���������, ��������� ����������� �� ����� ����������).
	//				��� �������� ���������� ������� ���������� ������ � ������������, �����������
	//				����������� constexpr-�������:

	{	//��������:
		int ar[factorial(3)];

		//���
		constexpr int n = factorial(5);
		int ar1[n];

		//����������:
		int m = 7;
		//constexpr int n1 = factorial(m);	// ������, �������� �� const
		//int ar1[n1];
		
		//� ���?
		int n2 = factorial(m);

		__asm nop
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////////
	//������� 3a. ������� � ������� ����������������� �������� �� ��������� ������������� ����������
	//� ��������, ��������: ������ "100000000" -> � �������� 256
	//��������� ��������� ����������� �������� 0b
	//����� ����� ����������������� �������� �������� ������ � �������, ��������: 100000000_b
	//������� ������������ ���������������� ������� � ������������ ���������� - const char*

	//��� ��� ���� ���� � ���������, ������� ��������� �������� �� ����� ����������
	// => ���������� ���������������� ������� ����������� constexpr - �������
	//���������/�����������: 
	//		- constexpr � ������� ������ �������� �� ������������ ���������� return <���������>;
	//		- �� ��� ��������� ����� �������� ����� ������ constexpr � �������,
	//		- ������� ����� ���� ����������� (���� �������� ����� ������� - ��� ���������,
	//		  ���������� �������� ��������� ������ ����������� ������� �� ����� ����������)

	{
	/*constexpr*/ auto result = 100000000_convertToDec;
	std::cout << result << std::endl;			// 256
		__asm nop

	}

	//������� 3b. ������� � ��������� �������� �������������, ��������: 256 -> "0b100000000"
	//��� ��� ������ ����� ���� ����� �����, �������� � ����� ���������� ������ std::string
	//=> ������������ �������� �� ����� ���� constexpr!
	//���������: ������������ std::bin ���� ��� => �������������� � �������� ������
	//�������� ������ �������
	//���������: ���������� �������� � ����� ���������� ��������� CHAR_BIT - <cstdint>

	{
		std::string sBin= 256_toBinStr;		// 100000000
		__asm nop
	}


	//////////////////////////////////////////////////////////////////////////////////////////////
	//������� 4�. constexpr - ������� 
	//������� ����� (������ ������?) ��� �������� � ��������������� ���������� ��������.
	//� ������ ������ ����:
	//	���������� ��� �������� ������������ � ������������� ��������,
	//	������ ��� ��������� ������� �� ��������
	//	����� ��� �������� - �������� �� ��������� �������� � ��������
	//	�����, ������� �������� ����� �������� ������� ���� � ��������� �������������� ��������:
	//							���� ����������� ���������, �� ��� � ����������
	//							���� ������ ������������ ��������, ���������� �����������
	//							���� ������ ������������� ��������, ���������� ������������

	//��������� ��� ����, ��� ���������� ��������� �������� �� ����� ����������. 

	{
		constexpr MySaveClass test(0, 10);
		constexpr auto val = test.getMin();
		int res = test.findValue(-1);
		int res2 = test.findValue(3);

		MySaveClass test1("1"s, "2"s);
		//constexpr auto val1 = test1.getMax();		// ������

	__asm nop
	}	
	/***************************************************************/
//������� 5.
	/*
	���������� ������ ������� ��� ������ ����� ������������������� (vector, list, deque, set � ����������� �������), ������� ����� ���������:
	�	��� ������� ������ ����,
	�	��� � ��������� �� ������� ������ ���� (��������� ������������� ����������� => � ���� ������ ������� �������� �������� �� ������)
	���������: if constexpr
	*/
	{
		std::vector<std::string> vec{"T-Shirt", "Shirt", "Tie", "Jacket"};
		PrintAll(vec);

		std::list<std::string*> l{ new std::string("ZZZ"), new std::string("AAA") };
		PrintAll(l);

		// delete l
		l.clear();
		
		__asm nop
	}

	/***************************************************************/
	//������� 6.
		/* ���������� ������ ������� �������� ���� ��������.
		���� ������ ��������� �������� ��������, �� ��� �������� ������� ����� ��������� �� �������� ������� ���������. ��� ���� �������� ������� � ������ �������� ������ ���� ������ � ���� �� ����.
		���������: if constexpr, is_same
		*/
	{
		std::vector<int> vect{ 3,4,5,6,7 };
		auto result = Sum(vect, 5);
		auto result2 = Sum(10, 5);			// ������ ������ ��������� �� ������
		std::cout << "\nVector:" << std::endl;
		for ( const auto& i : vect )
		{
			std::cout << i << " ";
		}

		__asm nop
	}


	/***************************************************************/
//������� 7.
	/* 	���������� ������ ������� ������ �� ������ �������� ��������� ������ �������� (stack, queue, priority_queue)
	���������: if constexpr, is_same
	������������� ����� ��������, ���� � �������� �������� ���������.
	*/
	{
		std::queue<std::string> q;
		q.push("Lead");
		q.push("Build");
		q.push("Release");
		PrintAdapter(q);

		std::queue<std::string, std::list<std::string>> q1;
		q1.push("Lead");
		q1.push("Build");
		q1.push("Release");
		PrintAdapter(q1);

		stack <int> st;
		st.push(10);
		st.push(20);
		st.push(30);
		PrintAdapter(st);

		__asm nop
	}

	/***************************************************************/
//������� 8.
	/* 	���������� ������ constexpr ������� Smth(), ������� ������ ���������� �������� ������� ����
	���������: constexpr, if constexpr
	*/
	/*const int x1 = 1;
	const double x2 = 2.2;
	const char* x3 = "abc";*/

	constexpr int res1 = Smth<1>();							//res1 = 1
	constexpr double res2 = Smth<2>();							//res2 = 2.2
	//  /*constexpr???*/ std::string res3 = Smth(3);				//res3 = "abc"

	__asm nop
	//***************************************************************/
	//������� 9.

		/*���������������� deduction guide � ��� ������ ����� ���������� �������
		����� ������ ������, ������� ������������� ���������� ������������ ������ ���������
		����������� � ���������� ������ ����. */
		
		

		
		//��������� ���������� ����������������� ����������� �������� �������������.
			{
				MyArray<int, 5> ar1;

				MyArray ar2("ABC");
				MyArray<char, 4> ar22;
				int ar[] = { 1,2,3 };
				MyArray ar3{ ar };

				MyArray<int, 5> ar33{ar, 3};

				__asm nop
			}
		

	
}