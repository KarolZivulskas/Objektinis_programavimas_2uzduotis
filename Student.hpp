#pragma once

#include <deque>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "Definitions.hpp"
#include "Math.hpp"
#include "Person.hpp"

using std::deque;
using std::list;
using std::string;
using std::vector;

class Student : public Person {
private:
	vector<int> pazymiai;
	int egzamino = 0;
	double pazymiuVid = 0;
	double pazymysGalutinis = 0;
	double pazymiuMed = 0;

public:
	explicit Student(const string & = "", const string & = "");

	~Student();                           // destruktorius
	Student(const Student&);             // kopijavimo konstruktorius
	Student& operator=(const Student&);  // kopijavimo priskyrimo operatorius

	friend std::ostream& operator<<(std::ostream&, const Student&);
	friend std::istream& operator>>(std::istream&, Student&);

	const string& grazintiVarda() const override;
	const string& grazintiPavarde() const override;

	void skaiciuotiGalutiniPazymi();
	void skaiciuotiVidurki();
	void skaiciuotiMediana();
	int grazintiEgzPazymi() const;
	double grazintiGalutiniPazymi() const;
	vector<int> grazintiPazymius();
	double grazintiMediana() const;
	bool ArNepasiseke() const;
	void SutvarkytiStudenta(const string&);
	void pasalintiPaskutiniPazymi();
	void pridetiEgzPazymi(int);
	void pridetiPazymi(int);
};