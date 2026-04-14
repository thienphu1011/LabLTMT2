#ifndef GRADEDACTIVITY_H
#define GRADEDACTIVITY_H

class GradedActivity {
private:
    double score;
public:
    GradedActivity();
    GradedActivity(double s);
    void setScore(double s);
    double getScore() const;
    virtual char getLetterGrade() const;
};
GradedActivity::GradedActivity() {
    score = 0.0;
}

GradedActivity::GradedActivity(double s) {
    score = s;
}

void GradedActivity::setScore(double s) {
    score = s;
}

double GradedActivity::getScore() const {
    return score;
}

char GradedActivity::getLetterGrade() const {
    char letterGrade;
    if (score > 89) letterGrade = 'A';
    else if (score > 79) letterGrade = 'B';
    else if (score > 69) letterGrade = 'C';
    else if (score > 59) letterGrade = 'D';
    else letterGrade = 'F';
    return letterGrade;
}
#endif