#define pi 3.14159265358979323846

#include <iostream>
#include <cmath>
#include <locale.h>

using namespace std;

class Complex         // ����� "����������� �����"
{
private:
	double re, im;      // �������������� � ������ �����

public:
	// ������������ 

	Complex()
	{
	};

	Complex(double r)
	{
		re = r;
		im = 0;
	}

	Complex(double r, double i)
	{
		re = r;
		im = i;
	}

	Complex(const Complex &c)   // ����������� �����������
	{
		re = c.re;
		im = c.im;
	}

	// ����������
	~Complex()
	{
	}

	// �������� ������������
	Complex& operator = (Complex &c)
	{
		re = c.re;
		im = c.im;

		return (*this);
	}


	// �������� +=
	Complex& operator += (Complex &c)
	{
		re += c.re;
		im += c.im;
		return *this;
	}

	// �������� ��������
	Complex operator + (const Complex &c)
	{
		return Complex(re + c.re, im + c.im);
	}

	// �������� ���������
	Complex operator - (const Complex &c)
	{
		return Complex(re - c.re, im - c.im);
	}

	// �������� ���������
	Complex operator * (const Complex &c)
	{
		return Complex(re * c.re - im * c.im, re * c.im + im * c.re);
	}

	// �������� �������
	Complex operator / (const Complex &c)
	{
		Complex temp;

		double r = c.re * c.re + c.im * c.im;
		temp.re = (re * c.re + im * c.im) / r;
		temp.im = (im * c.re - re * c.im) / r;

		return temp;
	}

	// ������ ������������� ���������, ������� �� ��������� ������
	// � ������ (private) ������
	friend ostream & operator<< (ostream &, const Complex &);
	friend istream & operator>> (istream &, Complex &);

	double abs(const Complex &c) //������
	{
		return sqrt(c.re * c.re + c.im * c.im);
	}

	double phase(const Complex &c) //����
	{
		if (c.re > 0 and c.im > 0)
			return atan(c.im / c.re);
		if (c.re < 0 and c.im > 0)
			return atan(c.im / c.re) + pi;
		if (c.re < 0 and c.im < 0)
			return atan(c.im / c.re) - pi;
		if (c.re > 0 and c.im < 0)
			return atan(c.im / c.re);
	}

	double pow(const Complex &c, double p) //�������
	{
		double trig = abs(c)*(cos(phase(c.re))+sin(phase(c.im)));
		return 
	}
};


// ���������� ��������� <<
ostream& operator<< (ostream &out, const Complex &c)
{
	out << "(" << c.re << ", " << c.im << ")";
	return out;
}

// ���������� ��������� >>
istream& operator>> (istream &in, Complex &c)
{
	in >> c.re >> c.im;
	return in;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Complex a(5, 2);
	Complex b(3, -3);
	Complex res;
	Complex za(res.abs(a)*(cos(res.phase(b))), res.abs(a)*(sin(res.phase(b))));
	Complex zb(res.abs(a)*(cos(res.phase(b))), res.abs(a)*(sin(res.phase(b))));
	double p;

	cout << "a = " << a << "; b =" << b << endl;
	cout <<"��������"<< a + b << endl;
	cout << "���������" << a - b << endl;
	cout <<"���������:"<< a * b << endl;
	cout << "�������:" << a / b << endl;
	cout << "������ a(5, 2):" << res.abs(a) << endl;
	cout << "������ b(3, -3):" << res.abs(b) << endl;
	cout << "���� a(5, 2) � ��������:" << res.phase(a) << endl;
	cout << "���� b(3, -3) � ��������:" << res.phase(b) << endl;

	cout << "������� �������:";
	cin >> p;
	cout << "���������� � ������� b(3, -3):" << res.pow(b,p,zb) << endl;
	cout << "���������� � ������� a(5, 2):" << res.pow(a,p,za) << endl;
	return 0;
}