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

#endif