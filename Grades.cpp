#include "Grades.hpp"

void SpausdintiAtsitiktiniusPazymius(Student& student) {
    vector<int> pazymiai = student.grazintiPazymius();
    const int masyvoDydis = pazymiai.size();
    std::cout << "Sugeneruoti " << masyvoDydis << " atsitiktiniai pazymiai: ";
    for (const int& pazymys : pazymiai) {
        std::cout << pazymys << " ";
    }
    std::cout << std::endl;
    std::cout << "Sugeneruotas atsitiktinis egzamino pazymys: " << student.grazintiEgzPazymi() << std::endl;
}

void Grades::IvestiRankiniuBudu(bool ArZinomasPazymiuSk, int pazymiuSk, Student& student) {
    if (ArZinomasPazymiuSk) {
        if (pazymiuSk > 0) {
            while (student.grazintiPazymius().size() != pazymiuSk) {
                int pazymys = Console::prasytiInt("Iveskite pazymi", GRADE_MIN, GRADE_MAX);
                student.pridetiPazymi(pazymys);
            }
        }
    }
    else {
        while (true) {
            int pazymys = Console::prasytiInt(
                "Iveskite pazymi, jei norite sustoti, veskite -1", GRADE_MIN, GRADE_MAX, -1);
            if (pazymys == -1) {
                break;
            }
            else {
                student.pridetiPazymi(pazymys);
            }
        }
    }

    int egzamino = Console::prasytiInt("Iveskite egzamino pazymi", GRADE_MIN, GRADE_MAX);
    student.pridetiEgzPazymi(egzamino);
}

void Grades::GeneruotiAtsitiktinai(bool ArZinomasPazymiuSk, int pazymiuSk, Student& student) {
    if (ArZinomasPazymiuSk) {
        for (int i = 0; i < pazymiuSk; i++) {
            int pazymys = RND::GeneruotiAtsitiktiniIntervale(GRADE_MIN, GRADE_MAX);
            student.pridetiPazymi(pazymys);
        }
    }
    else {
        while (true) {
            int pazymys = RND::GeneruotiAtsitiktiniIntervale(0, GRADE_MAX);
            if (pazymys == 0) {
                break;
            }
            else {
                student.pridetiPazymi(pazymys);
            }
        }
    }

    int egzamino = RND::GeneruotiAtsitiktiniIntervale(GRADE_MIN, GRADE_MAX);
    student.pridetiEgzPazymi(egzamino);
    SpausdintiAtsitiktiniusPazymius(student);
}