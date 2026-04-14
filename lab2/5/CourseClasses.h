#ifndef COURSECLASSES_H 
#define COURSECLASSES_H 

class GradedActivity { 
private: 
    double score; 
public: 
    GradedActivity() { score = 0.0; } 
    GradedActivity(double s) { score = s; } 
     
    void setScore(double s) { score = s; } 
    double getScore() const { return score; } 
    virtual char getLetterGrade() const; 
}; 
 

class PassFailExam : public GradedActivity { 
private: 
    double minPassingScore; 
public: 
    PassFailExam(int questions, int missed, double minPass); 
    char getLetterGrade() const override; 
}; 
 

class Essay : public GradedActivity { 
public: 
    Essay(double grammar, double spelling, double length, double content); 
};

 
class FinalExam : public GradedActivity { 
private: 
    int numQuestions; 
    double pointsEach; 
    int numMissed; 
public: 
    FinalExam(); 
    FinalExam(int questions, int missed); 
    void set(int, int); 
    double getNumQuestions() const { return numQuestions; } 
    double getPointsEach() const { return pointsEach; } 
    int getNumMissed() const { return numMissed; } 
}; 
 

class CourseGrades { 
private: 
    GradedActivity* grades[4]; 
public: 
    CourseGrades(); 
    void setLab(GradedActivity* a); 
    void setPassFailExam(PassFailExam* a); 
    void setEssay(Essay* a); 
    void setFinalExam(FinalExam* a); 
    void print() const; 
}; 

#endif 
