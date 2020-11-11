#pragma once
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

class Fraction {
private:
	int up_value = 0;
	int down_value = 0;

public:
	Fraction(int up, int down) {
		Clear();
		FractionNum++;
		up_value = up;
		down_value = down;
		Reduce();
	}
	Fraction(double fract) {
		Clear();
		FractionNum++;
		double d = fract;
		Reduce(fract);
	}

	double Get() {
		if (up_value != 0)
			return double(up_value) / down_value;
		else return 0;
	}
	void Reduce() {
		Reduce(Get());
	}

	static int FractionNum;
	static int getFractionNum() {
		return FractionNum;
	}

	static int gcd(int n, int m) {
		int n1 = abs(n);
		int m1 = abs(m);
		int min = n1 > m1 ? m1 : n1;
		long nod = 1L;
		for (long i = min; i > 0; i--) {
			if (n1 % i == 0 && m1 % i == 0) {
				nod = i;
				break;
			}
		}
		return nod;
	}

	static void printAsFraction(double fract) {
		int up = 0;
		int down = 1;
		ostringstream ss;
		ss << fract;
		string s_up = ss.str();
		int point_pos = s_up.find('.');
		if (point_pos == -1) {
			up = atoi(s_up.c_str());
			down = 1;
		}
		else {
			s_up.erase(point_pos, 1);
			up = atoi(s_up.c_str());
			for (size_t i = 0; i < s_up.length() - point_pos; i++)
				down *= 10;
			int temp = gcd(up, down);
			up /= temp;
			down /= temp;
		}

		if (up != 0) cout << up << '/' << down;
		else cout << 0;
	}
	static void printAsFraction(char* decimal_fraction) {
		printAsFraction(atof(decimal_fraction));
	}

	Fraction operator + (Fraction value) {
		return Fraction(Get() + value.Get());
	}
	template <typename T>
	Fraction operator + (T value) {
		return Fraction(Get() + value);
	}
	Fraction operator - (Fraction value) {
		return Fraction(Get() - value.Get());
	}
	template <typename T>
	Fraction operator - (T value) {
		return Fraction(Get() - value);
	}
	Fraction operator * (Fraction value) {
		return Fraction(Get() * value.Get());
	}
	template <typename T>
	Fraction operator * (T value) {
		return Fraction(Get() * value);
	}
	Fraction operator / (Fraction value) {
		return Fraction(Get() / value.Get());
	}
	template <typename T>
	Fraction operator / (T value) {
		return Fraction(Get() / value);
	}

	friend ostream & operator << (ostream& os, const Fraction& value) {
		if (value.up_value != 0)
			os << value.up_value << '/' << value.down_value;
		else os << 0;
		return os;
	}

private:
	void Reduce(double value) {
		int up = 0;
		int down = 1;
		ostringstream ss;
		ss << value;
		string s_up = ss.str();
		int point_pos = s_up.find('.');
		if (point_pos == -1) {
			up = atoi(s_up.c_str());
			down = 1;
		}
		else {
			s_up.erase(point_pos, 1);
			up = atoi(s_up.c_str());
			for (size_t i = 0; i < s_up.length() - point_pos; i++)
				down *= 10;
			int temp = gcd(up, down);
			up /= temp;
			down /= temp;
		}
		up_value = up;
		down_value = down;
	}

	void Clear() {
		up_value = 0;
		down_value = 0;
	}
};