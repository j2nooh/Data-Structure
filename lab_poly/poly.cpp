#include <iostream>
#include "poly.h"
using namespace std;

istream& operator>> (istream& is, Polynomial& p) {
    // #terms and (coefficoent, exponent)�� pair���� �о���δ�.
    // ���� ������ �׺��� �ԷµǾ� ����ȴٰ� �����Ѵ�.
    int noofterms; float coef; int exp;
    is >> noofterms;
    for (int i = 0; i < noofterms; i++) {
        is >> coef >> exp; // ����� ���� pair�� �о���δ�.
        p.NewTerm(coef, exp);
    }
    return is;
}
ostream& operator<< (ostream& os, Polynomial& p) {
    // ���˿� �°� ����ϴ� �ڵ� �Է�
    for (int i = 0; i < p.terms; i++)
    {
        if (p.termArray[i].exp > 1) // ������ 2�� �̻��̸�
        {
            if (p.termArray[i].coef == 1)
                os << "x^" << p.termArray[i].exp;  // ����� 1�̸�, "x^����" ���
            else if (p.termArray[i].coef == -1)
                os << "-x^" << p.termArray[i].exp;  // ����� -1�̸�, "-x^����" ���
            else
                os << p.termArray[i].coef << "x^" << p.termArray[i].exp;  // �׿� ����� ���, "���x^����" ���
        }
        else if (p.termArray[i].exp == 1)  // ������ 1���� ���,
        {
            if (p.termArray[i].coef == 1)
                os << "x";  // ����� 1�̸�, "x" ���
            else if (p.termArray[i].coef == -1)
                os << "-x";  // ����� -1�̸�, "-x" ���
            else
                os << p.termArray[i].coef << "x";  // �׿� ����� ��� "���x" ���
        }
        else
            os << p.termArray[i].coef;  // ������̸� ����� ���

        if (i < p.terms - 1) { // ������ �� ������
            if (p.termArray[i + 1].coef > 0) {
                os << " +";  // ���� i+1 ���� ��� ���� ����̸� " +" ���
            }
            else {
                os << "  ";  // ���� i+1 ���� ��� ���� ������ ��� "  " ���
            }
        }
    }
    os << endl;
    return os;
}

Polynomial::Polynomial() :capacity(1), terms(0)
{
    termArray = new Term[capacity];
}
void Polynomial::NewTerm(const float theCoeff, const int theExp)
{
    // ���׽� �ڿ� ���ο� ���� �߰��ϴ� �Լ��� ���翡 ����
    if (terms == capacity)
    {  // termArray�� ũ�⸦ �ι�� Ȯ��
        capacity *= 2;
        Term* temp = new Term[capacity];  // ���ο� �迭
        copy(termArray, termArray + terms, temp);
        delete[] termArray;  // ���� �޸� ��ȯ
        termArray = temp;
    }
    termArray[terms].coef = theCoeff;
    termArray[terms++].exp = theExp;
}
Polynomial Polynomial::operator+(Polynomial& b)
{
    //������ Add�� ������ �Լ��� �̸��� �ٲٸ� ��
    Polynomial c; // �� ����
    int aPos = 0, bPos = 0;
    while ((aPos < terms) && (bPos < b.terms))
        if (termArray[aPos].exp == b.termArray[bPos].exp) {
            float t = termArray[aPos].coef + b.termArray[bPos].coef;
            if (t) c.NewTerm(t, termArray[aPos].exp);
            aPos++; bPos++;
        }
        else if (termArray[aPos].exp < b.termArray[bPos].exp) {
            c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
            bPos++;
        }
        else {
            c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
            aPos++;
        }
    // *this�� ������ �׵��� �߰��Ѵ�.
    for (; aPos < terms; aPos++)
        c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
    // b(x)�� ������ �׵��� �߰��Ѵ�.
    for (; bPos < b.terms; bPos++)
        c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
    return c;
}