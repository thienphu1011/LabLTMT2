#ifndef FINALEXAM_H
#define FINALEXAM_H
#include "GradedActivity.h"

class FinalExam : public GradedActivity {
private:
    int numQuestions;
    double pointsEach;
    int numMissed;
public:
    FinalExam();
    FinalExam(int questions, int missed);
    void set(int questions, int missed);
    double getNumQuestions() const;
    double getPointsEach() const;
    int getNumMissed() const;
};

#endif