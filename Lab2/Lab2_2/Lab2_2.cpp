#include "Fraction.h"
using namespace std;

int Fraction::FractionNum = 0;
int main()
{
	cout << "Fraction Num = " << Fraction::getFractionNum() << endl << endl;

	Fraction fraction1(18, 6);
	Fraction fraction2(double(5.2));
	cout << "fraction1 = " << fraction1 << endl;
	cout << "fraction2 = " << fraction2 << endl << endl;

	cout << "fraction1 + fraction2 = " << fraction1 + fraction2 << endl;
	cout << "fraction1 - fraction2 = " << fraction1 - fraction2 << endl;
	cout << "fraction1 * fraction2 = " << fraction1 * fraction2 << endl;
	cout << "fraction1 / fraction2 = " << fraction1 / fraction2 << endl << endl;

	cout << "gcd(7, 14) = " << Fraction::gcd(7, 14) << endl;
	cout << "gcd(150, 45) = " << Fraction::gcd(150, 45) << endl << endl;

	cout << "PrintAsFraction(0.75) = ";
	Fraction::printAsFraction(0.75);
	cout << endl;
	cout << "PrintAsFraction(16.75) = ";
	Fraction::printAsFraction(16.75);
	cout << endl << endl;

	cout << "Fraction Num = " << Fraction::getFractionNum() << endl;

	return 0;
}