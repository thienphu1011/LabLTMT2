#ifndef COURSEGRADES_H
#define COURSEGRADES_H

class GradedActivity;
class PassFailExam;
class Essay;
class FinalExam;

class CourseGrades {
private:
    GradedActivity* grades[4];
public:
    CourseGrades();
    void setLab(GradedActivity* aLab);
    void setPassFailExam(PassFailExam* aPf);
    void setEssay(Essay* anEssay);
    void setFinalExam(FinalExam* aFinal);
    void print() const;
};

#endif