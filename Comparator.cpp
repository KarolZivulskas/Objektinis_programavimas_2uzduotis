#include "Comparator.hpp"

bool Comparator::RikiuotiPagalGalutiniMazejant(const Student& a, const Student& b) {
    return a.grazintiGalutiniPazymi() > b.grazintiGalutiniPazymi();
}

bool Comparator::RikiuotiPagalVardaDidejant(const Student& a, const Student& b) {
    string aPavarde = a.grazintiPavarde();
    string bPavarde = b.grazintiPavarde();

    string aVardas = a.grazintiVarda();
    string bVardas = b.grazintiVarda();

    return aPavarde != bPavarde
        ? aPavarde < bPavarde
        : aVardas < bVardas;
}