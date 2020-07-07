#define pi 3.14159265358979323846

#include <iostream>
#include <cmath>
#include <locale.h>

using namespace std;

class Complex         // класс " омплексное число"
{
private:
	double re, im;      // действительна€ и мнима€ части

public:
	// конструкторы 

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

	Complex(const Complex &c)   // конструктор копировани€
	{
		re = c.re;
		im = c.im;
	}

	// деструктор
	~Complex()
	{
	}

	// оператор присваивани€
	Complex& operator = (Complex &c)
	{
		re = c.re;
		im = c.im;

		return (*this);
	}


	// оператор +=
	Complex& operator += (Complex &c)
	{
		re += c.re;
		im += c.im;
		return *this;
	}

	// оператор сложени€
	Complex operator + (const Complex &c)
	{
		return Complex(re + c.re, im + c.im);
	}

	// оператор вычитани€
	Complex operator - (const Complex &c)
	{
		return Complex(re - c.re, im - c.im);
	}

	// оператор умножени€
	Complex operator * (const Complex &c)
	{
		return Complex(re * c.re - im * c.im, re * c.im + im * c.re);
	}

	// оператор делени€
	Complex operator / (const Complex &c)
	{
		Complex temp;

		double r = c.re * c.re + c.im * c.im;
		temp.re = (re * c.re + im * c.im) / r;
		temp.im = (im * c.re - re * c.im) / r;

		return temp;
	}

	// укажем дружественные операторы, которым мы разрешаем доступ
	// к личным (private) данным
	friend ostream & operator<< (ostream &, const Complex &);
	friend istream & operator>> (istream &, Complex &);

	double abs(const Complex &c) //модуль
	{
		return sqrt(c.re * c.re + c.im * c.im);
	}

	double phase(const Complex &c) //фаза
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

	double pow(const Complex &c, double p) //степень
	{
		double trig = abs(c)*(cos(phase(c.re))+sin(phase(c.im)));
		return 
	}
};


// перегрузка оператора <<
ostream& operator<< (ostream &out, const Complex &c)
{
	out << "(" << c.re << ", " << c.im << ")";
	return out;
}

// перегрузка оператора >>
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
	cout <<"—ложение"<< a + b << endl;
	cout << "¬ычитание" << a - b << endl;
	cout <<"”множение:"<< a * b << endl;
	cout << "ƒеление:" << a / b << endl;
	cout << "ћодуль a(5, 2):" << res.abs(a) << endl;
	cout << "ћодуль b(3, -3):" << res.abs(b) << endl;
	cout << "‘аза a(5, 2) в радианах:" << res.phase(a) << endl;
	cout << "‘аза b(3, -3) в радианах:" << res.phase(b) << endl;

	cout << "¬ведите степень:";
	cin >> p;
	cout << "¬озведение в степень b(3, -3):" << res.pow(b,p,zb) << endl;
	cout << "¬озведение в степень a(5, 2):" << res.pow(a,p,za) << endl;
	return 0;
}