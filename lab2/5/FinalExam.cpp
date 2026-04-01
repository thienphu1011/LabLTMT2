#include "FinalExam.h"

FinalExam::FinalExam() {
    numQuestions = 0;
    pointsEach = 0.0;
    numMissed = 0;
}

FinalExam::FinalExam(int questions, int missed) {
    set(questions, missed);
}

void FinalExam::set(int questions, int missed) {
    numQuestions = questions;
    numMissed = missed;
    pointsEach = 100.0 / numQuestions;
    double numericScore = 100.0 - (missed * pointsEach);
    setScore(numericScore);
}

double FinalExam::getNumQuestions() const { return numQuestions; }
double FinalExam::getPointsEach() const { return pointsEach; }
int FinalExam::getNumMissed() const { return numMissed; }