#ifndef ESSAY_H
#define ESSAY_H
#include "GradedActivity.h"

class Essay : public GradedActivity {
private:
    double grammar;
    double spelling;
    double length;
    double content;

public:
    Essay();
    void setScores(double g, double s, double l, double c);
    double getGrammar() const;
    double getSpelling() const;
    double getLength() const;
    double getContent() const;
};

#endif