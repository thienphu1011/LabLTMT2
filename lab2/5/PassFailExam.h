#ifndef PASSFAILEXAM_H
#define PASSFAILEXAM_H
#include "GradedActivity.h"

class PassFailExam : public GradedActivity {
private:
    double minPassingScore;
public:
    PassFailExam(double minPass = 70.0);
    char getLetterGrade() const override;
};

#endif