#include "Point.h"

// �����������
Point::Point(int x, int y)
{
	m_x = x;
	m_y = y;
};

// ����������� �����������
Point::Point(const Point& otherClass)
{
	m_x = otherClass.m_x;
	m_y = otherClass.m_y;
};

// ���������� ��������� +=
Point& Point::operator+=(const Point& RightObject)
{
	m_x = m_x + RightObject.m_x;
	m_y = m_y + RightObject.m_y;
	return *this;

};
Point& Point::operator+=(const int value)
{
	m_x = m_x + value;
	m_y = m_y + value;
	return *this;

};

//���������� ��������� +
Point& Point::operator+(const Point& RightObject)
{
	*this += RightObject;	// ����� �������������� ������ +=
	return *this;
};
Point& Point::operator+(const int value)
{
	this->m_x += value;
	this->m_y += value;
	return *this;
};

// ����������� �������� ��������� - (-pt1;)
Point& Point::operator-()
{
	this->m_x = -m_x;
	this->m_y = -m_y;
	return *this;
};

// ����������� �������� ��������� + (+pt1;)
Point& Point::operator+()
{
	return *this;
};