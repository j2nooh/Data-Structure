#include <iostream>
#include "rectangle.h"
using namespace std;

Rectangle::Rectangle(int x = 0, int y = 0, int h = 0, int w = 0)
: xLow(x), yLow(y), height(h), width(w) {}

Rectangle::~Rectangle() {}

void Rectangle::Print()
{ 
	cout << "xLow: " << xLow << ", yLow: " << yLow;
	cout << ", height: " << height << ", width: " << width << endl;
	// ���� ���õ� ���â�� ���˿� �°� ����� �� �ֵ��� ����
}

int Rectangle::Area()
{ 
	return width * height;
	// �������� �����Ͽ� ��ȯ�ϱ�
}

bool Rectangle::LessThan(Rectangle& s)
{ 
	if (this->Area() < s.Area()) return true;
	else return false; 
	// �簢���� ����(Area())�� ���� ��� ���� �簢������ ����
	// �� �ٷ� ���ÿ� : return Area() < s.Area(); 
}

bool Rectangle::Equal(Rectangle& s)
{ 
	if (this == &s) return true;
	if ((xLow == s.xLow) && (yLow == s.yLow)
		&& (height == s.height) && (width == s.width)) return true;
	else return false;
	// ���� ����: ��ġ, ����, ���� ��� ���ƾ� ������ �簢������ ����
}

int Rectangle::GetHeight() { return height; }

int Rectangle::GetWidth() { return width; }

bool Rectangle::EqualSize(Rectangle& s) {
	return Area() == s.Area();
}

ostream& operator<<(ostream& os, Rectangle& s) {
	os << "xLow: " << s.xLow << ", yLow: " << s.yLow;
	os << ", height: " << s.height << ", width: " << s.width << endl;
	return os;
	// Rectangle s�� ��� ���� �� ���˿� ���߾� ����ϱ�
}

bool Rectangle::operator<(Rectangle& s) {
	if (this->Area() < s.Area()) return true;
	else return false;
}

bool Rectangle::operator==(Rectangle& s) {
	return (Area()) == (s.Area());
	// ������ ������ ��� true
}