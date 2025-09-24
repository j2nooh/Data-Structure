// C435455 홍진우
#include <iostream>
#include "rectangle.h"
using namespace std;

int main() {
	Rectangle r(2, 3, 4, 6), s(1, 2, 6, 6);

	cout << "<rectangle r> "; r.Print();
	cout << "<rectangle s> "; s.Print();

	if (r.LessThan(s))
		cout << "s is bigger";
	else if (r.EqualSize(s))
		cout << "Same Size";
	else cout << "r is bigger";
	cout << endl << endl;

	// operator overloading 관련부분
	// 연산자 다중화를 이용하여 r과 s의 정보 출력 및 면적 비교
	cout << "<rectangle r> " << r;
	cout << "<rectangle s> " << s;
	if (r < s) cout << "s is bigger";
	else if (r == s) cout << "Same Size";
	else cout << "r is bigger";
}