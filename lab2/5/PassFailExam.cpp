#include "PassFailExam.h"

PassFailExam::PassFailExam(double minPass) : minPassingScore(minPass) {}

char PassFailExam::getLetterGrade() const {
    if (getScore() >= minPassingScore) {
        return 'P';
    }
    return 'F';
}