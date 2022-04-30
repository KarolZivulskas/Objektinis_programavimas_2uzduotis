#include "Student.hpp"

Student::Student(const string& vardas, const string& pavarde) {
    this->vardas = vardas;
    this->pavarde = pavarde;
}

Student::~Student() = default;

void Student::skaiciuotiGalutiniPazymi() {
    pazymysGalutinis = 0.4 * pazymiuVid + 0.6 * egzamino;
}
void Student::skaiciuotiVidurki() {
    pazymiuVid = Math::VidurkioSkaiciavimas(pazymiai);
}

void Student::skaiciuotiMediana() {
    pazymiuMed = Math::MedianosPaieska(pazymiai);
}

int Student::grazintiEgzPazymi() const {
    return egzamino;
}

double Student::grazintiGalutiniPazymi() const {
    return pazymysGalutinis;
}

string Student::grazintiVarda() const {
    return vardas;
}

vector<int> Student::grazintiPazymius() {
    return pazymiai;
}
string Student::grazintiPavarde() const {
    return pavarde;
}

double Student::grazintiMediana() const {
    return pazymiuMed;
}

bool Student::ArNepasiseke() const {
    return pazymysGalutinis < 5;
}

void Student::SutvarkytiStudenta(const string & rezTipas) {
    if (rezTipas == RESULT_TYPE_MEAN) {
        skaiciuotiVidurki();
        skaiciuotiGalutiniPazymi();
    }
    else if (rezTipas == RESULT_TYPE_MEDIAN) {
        skaiciuotiMediana();
    }
    else if (rezTipas == RESULT_TYPE_BOTH) {
        skaiciuotiVidurki();
        skaiciuotiGalutiniPazymi();
        skaiciuotiMediana();
    }
}

void Student::pasalintiPaskutiniPazymi() {
    pazymiai.pop_back();
}

void Student::pridetiEgzPazymi(int egzamino) {
    this->egzamino = egzamino;
}

void Student::pridetiPazymi(int pazymys) {
    pazymiai.push_back(pazymys);
}