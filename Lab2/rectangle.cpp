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
	// 위에 제시된 출력창의 포맷에 맞게 출력할 수 있도록 구성
}

int Rectangle::Area()
{ 
	return width * height;
	// 면적값을 산출하여 반환하기
}

bool Rectangle::LessThan(Rectangle& s)
{ 
	if (this->Area() < s.Area()) return true;
	else return false; 
	// 사각형의 면적(Area())이 작은 경우 작은 사각형으로 결정
	// 한 줄로 쓰시오 : return Area() < s.Area(); 
}

bool Rectangle::Equal(Rectangle& s)
{ 
	if (this == &s) return true;
	if ((xLow == s.xLow) && (yLow == s.yLow)
		&& (height == s.height) && (width == s.width)) return true;
	else return false;
	// 교재 내용: 위치, 넓이, 높이 모두 같아야 동일한 사각형으로 결정
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
	// Rectangle s의 멤버 변수 값 포맷에 맞추어 출력하기
}

bool Rectangle::operator<(Rectangle& s) {
	if (this->Area() < s.Area()) return true;
	else return false;
}

bool Rectangle::operator==(Rectangle& s) {
	return (Area()) == (s.Area());
	// 면적이 동일한 경우 true
}