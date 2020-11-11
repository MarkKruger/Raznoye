#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <ctime>
#include "Photographer.h"
using namespace std;

void Sort(Photographer* photomans, int len) {
	int j = 0;
	Photographer* temp = new Photographer;
	for (int i = 0; i < len; i++) {
		j = i;
		for (int k = i; k < len; k++)
			if (photomans[j].getRating() > photomans[k].getRating())
				j = k;
		*temp = photomans[i];
		photomans[i] = photomans[j];
		photomans[j] = *temp;
	}
	delete temp;
}

void Photosession(Photographer* photomans, int num) {
	cout << "Photosession result:" << endl;
	int Viewers = 5 + rand() % 25;
	cout << "Number of viewers: " << Viewers << endl;
	if (Viewers >= 10)
		for (int i = 0; i < num; i++) {
			float ViewersRating = 0;
			for (int j = 0; j < Viewers; j++)
				ViewersRating += static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			ViewersRating /= Viewers;

			cout << "Photographer " << i << " raiting: " << photomans[i].getRating() << " + " << ViewersRating << endl;
		}
	cout << endl;
}

int main()
{
	srand(time(0));

	Photographer* photomans1 = new Photographer[2];
	photomans1[0].setFirstName("Igor");
	photomans1[0].setSecondName("Fischenko");
	photomans1[0].setSex(true);
	photomans1[0].setBirthYear(2001);
	photomans1[0].setStartYear(2018);
	photomans1[0].setRating(55.3);
	photomans1[1].setFirstName("Anastasia");
	photomans1[1].setSecondName("Glushko");
	photomans1[1].setSex(false);
	photomans1[1].setBirthYear(1995);
	photomans1[1].setStartYear(2016);
	photomans1[1].setRating(73.1);
	Photographer photoman2("Arnold", "Nemo", true, 1984, 2010, 441.5);

	Photographer* photomans = new Photographer[3];
	for (int i = 0; i < 2; i++)
		photomans[i] = photomans1[i];
	photomans[2] = photoman2;

	for (int i = 0; i < 3; i++)
		Photosession(photomans, 3);

	cout << "Serialize:" << endl;
	cout << "Photographer 1 first name:" << photomans[1].getFirstName() << endl;
	photomans[1].setFirstName("Serizlized");
	cout << "Set photographer 1 first name: Serialized" << endl;
	photomans[1].Serialize();
	cout << "Serialize" << endl;
	photomans[1].setFirstName("Anastasia");
	cout << "Set photographer 1 first name: Anastasia" << endl;
	photomans[1].Deserialize();
	cout << "Deserialize" << endl;
	cout << "Photographer 1 first name: " << photomans[1].getFirstName() << endl << endl;

	Sort(photomans, 3);
	cout << "Sorted photographers:" << endl;
	for (int i = 0; i < 3; i++) {
		cout << i << ". ";
		cout << photomans[i].getFirstName() << " " << photomans[i].getSecondName() << " ";
		cout << photomans[i].getRating() << endl;
	}

	delete[] photomans;
	return 0;
}