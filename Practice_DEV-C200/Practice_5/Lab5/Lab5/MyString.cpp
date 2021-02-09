#include "MyString.h"
#include"Counter.h"		// � ���� ������������� ������ ��������� ����������
#include <tchar.h>

/*
*	������������
*/
MyString::MyString(const char* str)
{
	if (str)
	{
		//TODO
		// �������� ����� �� ������, ���� ��� ����� ������ � ������ ����� �������
		//m_pMyCounter = new Counter(str);	// ������� ������
		m_pMyCounter = Counter::find(str);
	}
	else
	{
		m_pMyCounter = nullptr;
	}
};

MyString::MyString(const MyString& object)		// ����������� �����������
{
	this->m_pMyCounter = object.m_pMyCounter;	// ����������� ��������� �� ������
	this->m_pMyCounter->AddOwner();				// ������� ��������� �� ����� ������
};

MyString::MyString(MyString&& otherStr)			//  ������������ ����������� move
{
	this->m_pMyCounter = otherStr.m_pMyCounter;
	otherStr.m_pMyCounter = nullptr;
};			

MyString::~MyString()
{
	if (m_pMyCounter)	// �������� �� ������� ���������
	{
		m_pMyCounter->RemoveOwner();	// ������� ���������
	}
};

/*
*	������
*/
const char* MyString::GetString() const		// ����� ��������� ��������
{
	// TODO
	if ( m_pMyCounter->m_pStr )
	{
		return m_pMyCounter->m_pStr;
	}
	return "empty";
};

void MyString::SetNewString(const char* source)
{
		// TODO
		/*delete[] this->m_pMyCounter->m_pStr;
		this->m_pMyCounter->m_pStr = new char[ strlen(source) + 1 ];
		strcpy(this->m_pMyCounter->m_pStr, source);*/

	
};

/*
*	����������
*/
MyString& MyString::operator=(const MyString& object)	// ���������� ��������� �����������/ ������������
{
	// TODO
	if ( this->m_pMyCounter != object.m_pMyCounter )
	{
		if ( this->m_pMyCounter )
		{
			this->m_pMyCounter->RemoveOwner();
		}
		this->m_pMyCounter = object.m_pMyCounter;
		if ( this->m_pMyCounter )
		{
			this->m_pMyCounter->AddOwner();
		}
	}
	return *this;
};

MyString& MyString::operator=(MyString&& object)	// ���������� ��������� ����������� move
{
	if ( this != &object )
	{
		

	}


	return *this;
};
