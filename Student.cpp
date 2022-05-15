#include "Student.hpp"

Student::Student(const string& vardas, const string& pavarde) {
    this->vardas = vardas;
    this->pavarde = pavarde;
}

Student::~Student() = default; // destruktorius

Student::Student(const Student & student) { // kopijavimo konstruktorius
    vardas = student.vardas;
    pavarde = student.pavarde;
    pazymiai = student.pazymiai;
    egzamino = student.egzamino;
    pazymysGalutinis = student.pazymysGalutinis;
    pazymiuVid = student.pazymiuVid;
    pazymiuMed = student.pazymiuMed;
}

Student& Student::operator=(const Student& student) { // kopijavimo priskyrimo operatorius
    if (this == &student) {
        return *this;
    }

    vardas = student.vardas;
    pavarde = student.pavarde;
    pazymiai = student.pazymiai;
    egzamino = student.egzamino;
    pazymysGalutinis = student.pazymysGalutinis;
    pazymiuVid = student.pazymiuVid;
    pazymiuMed = student.pazymiuMed;

    return *this;
}

std::ostream& operator<<(std::ostream& out, const Student& student) {
    out << "Vardas: " << student.vardas << '\n'
        << "Pavarde: " << student.pavarde << '\n'
        << "Pazymiai: [ ";
    for (int grade : student.pazymiai) {
        out << grade << " ";
    }
    out << "]" << '\n'
        << "Egzamino pazymys: " << student.egzamino << '\n'
        << "Galutinis pazymys: " << student.pazymysGalutinis << '\n'
        << "Pazymiu vidurkis: " << student.pazymiuVid << '\n'
        << "Pazymiu mediana: " << student.pazymiuMed;

    return out;
}

std::istream& operator>>(std::istream& in, Student& student) {
    in >> student.vardas >> student.pavarde;
    return in;
}

const string& Student::grazintiVarda() const {
    return vardas;
}

const string& Student::grazintiPavarde() const {
    return pavarde;
}

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

vector<int> Student::grazintiPazymius() {
    return pazymiai;
}

double Student::grazintiMediana() const {
    return pazymiuMed;
}

bool Student::ArNepasiseke() const {
    return pazymysGalutinis < 5;
}

void Student::SutvarkytiStudenta(const string& rezTipas) {
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