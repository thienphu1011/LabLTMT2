#include <iostream>
#include "CourseGrades.h"
#include "GradedActivity.h"
#include "PassFailExam.h"
#include "Essay.h"
#include "FinalExam.h"

using namespace std;

CourseGrades::CourseGrades() {
    for (int i = 0; i < 4; i++) {
        grades[i] = nullptr;
    }
}

void CourseGrades::setLab(GradedActivity* aLab) {
    grades[0] = aLab;
}

void CourseGrades::setPassFailExam(PassFailExam* aPf) {
    grades[1] = aPf;
}

void CourseGrades::setEssay(Essay* anEssay) {
    grades[2] = anEssay;
}

void CourseGrades::setFinalExam(FinalExam* aFinal) {
    grades[3] = aFinal;
}

void CourseGrades::print() const {
    for (int i = 0; i < 4; i++) {
        if (grades[i] != nullptr) {
            cout << grades[i]->getScore() << " " << grades[i]->getLetterGrade() << "\n";
        }
    }
}