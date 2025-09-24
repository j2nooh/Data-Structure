// C435455 ȫ����
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool myfunction(int i, int j) { return (i < j); }
struct myclass {
	bool operator() (int i, int j) { return (i > j); }
} myobject;
int main() {
	int myints[] = { 32,71,12,45,26,80,53,33 };

	vector<int> myvector(myints, myints + 8); // 32 71 12 45 26 80 53 33
	vector<int>::iterator it; // using default comparison (operator <):
	cout << "�ʱ� myvector contains:";
	for (it = myvector.begin(); it != myvector.end(); ++it)
		cout << " " << *it; cout << endl;
	cout << endl;
	sort(myvector.begin(), myvector.begin() + 4); // (12 32 45 71) 26 80 53 33
	// using function as comp
	cout << "�� 4���� �������� ���� �� myvector contains :";
	for (it = myvector.begin(); it != myvector.end(); ++it)
		cout << " " << *it; cout << endl;
	cout << endl;
	sort(myvector.begin(), myvector.end(), myobject); // (80 71 53 45 33 32 26 12)
	// print out content:
	cout << "��ü �������� ���� �� myvector contains:";
	for (it = myvector.begin(); it != myvector.end(); ++it)
		cout << " " << *it; cout << endl;
	return 0;
}