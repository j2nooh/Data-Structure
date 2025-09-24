#pragma once
#ifndef RECTANGLE_H
#define RECTANGLE_H
using namespace std;

class Rectangle {
public:
	Rectangle(int, int, int, int); // constructor
	~Rectangle(); // destructor
	void Print();
	int Area();
	bool LessThan(Rectangle&); // ������ ������ true
	bool EqualSize(Rectangle&); // ������ �����ϸ� true
	bool Equal(Rectangle&); // ������ Equal (��� ����� �����ϸ� true)
	int GetHeight();
	int GetWidth();

	// ������ ����ȭ
	bool operator<(Rectangle&);   // ������ ������ true
	bool operator==(Rectangle&);  // ������ ������ true
	friend ostream& operator<<(ostream&, Rectangle&);

private:
	int xLow, yLow, height, width;
};
#endif