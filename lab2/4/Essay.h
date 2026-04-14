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


Essay::Essay() : GradedActivity() {
    grammar = 0.0;
    spelling = 0.0;
    length = 0.0;
    content = 0.0;
}

void Essay::setScores(double g, double s, double l, double c) {
    grammar = (g > 30) ? 30 : g;
    spelling = (s > 20) ? 20 : s;
    length = (l > 20) ? 20 : l;
    content = (c > 30) ? 30 : c;
    setScore(grammar + spelling + length + content);
}

double Essay::getGrammar() const { return grammar; }
double Essay::getSpelling() const { return spelling; }
double Essay::getLength() const { return length; }
double Essay::getContent() const { return content; }

#endif