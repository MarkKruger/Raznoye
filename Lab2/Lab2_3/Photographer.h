#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <string>
using namespace std;
class Photographer
{
private:
	std::string first_name = "unknown";
	std::string second_name = "unknown";
	bool sex = true;
	int birth_year = 0;
	int start_year = 0;
	float rating = 0;

public:
	Photographer() {
		setFirstName("unknown");
		setSecondName("unknown");
		setSex(true);
		setBirthYear(0);
		setStartYear(2000);
		setRating(0);
	}
	Photographer(std::string first_name, std::string second_name, bool sex, int birth_year, int start_year, float rating) {
		setFirstName(first_name);
		setSecondName(second_name);
		setSex(sex);
		setBirthYear(birth_year);
		setStartYear(start_year);
		setRating(rating);
	}

	void setFirstName(std::string new_first_name) { first_name = new_first_name; }
	void setSecondName(std::string new_second_name) { second_name = new_second_name; }
	void setSex(bool new_sex) { sex = new_sex; }
	void setBirthYear(int new_birth_year) { birth_year = new_birth_year; }
	void setStartYear(int new_start_year) { start_year = new_start_year; }
	void setRating(float new_rating) { rating = new_rating; }

	std::string getFirstName() { return first_name; }
	std::string getSecondName() { return second_name; }
	bool getSex() { return sex; }
	int getBirthYear() { return birth_year; }
	int getStartYear() { return start_year; }
	float getRating() { return rating; }

	void Serialize(const std::string & filename = "Data.txt") {
		std::string str;
		str += CreateParam("first_name", first_name);
		str += CreateParam("second_name", second_name);
		str += CreateParam("sex", sex);
		str += CreateParam("birth_year", birth_year);
		str += CreateParam("start_year", start_year);
		str += CreateParam("rating", rating, false);
		remove(filename.c_str());
		std::ofstream write;
		write.open(filename);
		if (write.is_open())
			write << str;
		write.close();
	}
	void Deserialize(const std::string & filename = "Data.txt") {
		string str;
		ifstream read(filename);
		read >> str;
		read.close();
		bool Last = false;
		while (true) {
			string paramName;
			string paramValue;

			paramName.assign(str, 0, str.find('=') - 1);
			paramValue.assign(str, str.find('=') + 1, (str.find(',', 1) == UINT_MAX ? str.length() : str.find(',')) - str.find('=') - 1);
			str.erase(0, str.find(',') == UINT_MAX ? str.length() - 1 : str.find(',') + 1);
			if (Last) break;
			if (str.find(',') == UINT_MAX)
				Last = true;
			if (paramName == "first_name") first_name = paramValue;
			else if (paramName == "second_name") second_name = paramValue;
			else if (paramName == "_number") istringstream(paramValue) >> std::boolalpha >> sex;
			else if (paramName == "_price") birth_year = atoi(paramValue.c_str());
			else if (paramName == "_year") start_year = atoi(paramValue.c_str());
			else if (paramName == "_mileage") rating = atof(paramValue.c_str());
		}
	}

private:
	template <typename T>
	std::string CreateParam(std::string name, T value, bool coma = true) {
		ostringstream ss;
		ss << name << "=" << value << (coma == true ? "," : "");
		return ss.str();
	}
};

