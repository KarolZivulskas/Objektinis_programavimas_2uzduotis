#pragma once

#include <string>

using std::string;

class Person {
protected:
    string vardas;
    string pavarde;

public:
    explicit Person(const string& vardas = "", const string& pavarde = "") {
        this->vardas = vardas;
        this->pavarde = pavarde;
    }

    virtual const string& grazintiVarda() const = 0;
    virtual const string& grazintiPavarde() const = 0;

    void nustatytiVarda(const string& vardas) {
        this->vardas = vardas;
    }

    void nustatytiPavarde(const string& pavarde) {
        this->pavarde = pavarde;
    }
};
