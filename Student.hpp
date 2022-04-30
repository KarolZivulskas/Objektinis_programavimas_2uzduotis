#pragma once

#include <deque>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "Definitions.hpp"
#include "Math.hpp"

using std::deque;
using std::list;
using std::string;
using std::vector;

class Student {
private:
	string vardas;
	string pavarde;
	vector<int> pazymiai;
	int egzamino = 0;
	double pazymiuVid = 0;
	double pazymysGalutinis = 0;
	double pazymiuMed = 0;

public:
	explicit Student(const string & = "", const string & = "");
	~Student();

	void skaiciuotiGalutiniPazymi();
	void skaiciuotiVidurki();
	void skaiciuotiMediana();
	int grazintiEgzPazymi() const;
	double grazintiGalutiniPazymi() const;
	string grazintiVarda() const;
	vector<int> grazintiPazymius();
	string grazintiPavarde() const;
	double grazintiMediana() const;
	bool ArNepasiseke() const;
	void SutvarkytiStudenta(const string&);
	void pasalintiPaskutiniPazymi();
	void pridetiEgzPazymi(int);
	void pridetiPazymi(int);
};