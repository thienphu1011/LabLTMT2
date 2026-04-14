#include "CourseClasses.h" 
#include <iostream> 
#include <iomanip> 
using namespace std; 


char GradedActivity::getLetterGrade() const 
{ 
    if (score > 89) 
        return 'A'; 
    else if (score > 79) 
        return 'B'; 
    else if (score > 69) 
        return 'C'; 
    else if (score > 59) 
        return 'D'; 
    else 
        return 'F'; 
} 


PassFailExam::PassFailExam(int questions, int missed, double minPass) 
{ 
    minPassingScore = minPass; 
    double pointsEach = 100.0 / questions;
    double numericScore = 100.0 - (missed * pointsEach); 
    setScore(numericScore); 
} 

char PassFailExam::getLetterGrade() const 
{ 
    if (getScore() >= minPassingScore) 
        return 'P'; 
    else 
        return 'F'; 
} 


Essay::Essay(double grammar, double spelling, double length, double content) 
{ 
    setScore(grammar + spelling + length + content); 
} 


FinalExam::FinalExam() 
{ 
    numQuestions = 0; 
    pointsEach = 0.0; 
    numMissed = 0; 
}  
FinalExam::FinalExam(int questions, int missed) 
{ 
    set(questions, missed); 
}  
void FinalExam::set(int questions, int missed)
{ 
    numQuestions = questions; 
    numMissed = missed; 
    pointsEach = 100.0 / numQuestions; 
    double numericScore = 100.0 - (missed * pointsEach); 
    setScore(numericScore); 
} 


CourseGrades::CourseGrades() 
{ 
    for (int i = 0; i < 4; i++) 
    { 
        grades[i] = nullptr; 
    } 
}  
void CourseGrades::setLab(GradedActivity *a) { grades[0] = a; } 
void CourseGrades::setPassFailExam(PassFailExam *a) { grades[1] = a; } 
void CourseGrades::setEssay(Essay *a) { grades[2] = a; } 
void CourseGrades::setFinalExam(FinalExam *a) { grades[3] = a; }  

void CourseGrades::print() const 
{ 
    cout << "--------------------------------------------------\n"; 
    cout << "COURSE GRADES REPORT\n"; 
    cout << "--------------------------------------------------\n"; 

    if (grades[0] != nullptr) 
        cout << "Lab Activity   : Score = " << setw(5) << grades[0]->getScore() << ", Grade = " << grades[0]->getLetterGrade() << endl; 
    if (grades[1] != nullptr) 
        cout << "Pass/Fail Exam : Score = " << setw(5) << grades[1]->getScore() << ", Grade = " << grades[1]->getLetterGrade() << endl; 
    if (grades[2] != nullptr) 
        cout << "Essay          : Score = " << setw(5) << grades[2]->getScore() << ", Grade = " << grades[2]->getLetterGrade() << endl; 
    if (grades[3] != nullptr) 
        cout << "Final Exam     : Score = " << setw(5) << grades[3]->getScore() << ", Grade = " << grades[3]->getLetterGrade() << endl; 

    cout << "--------------------------------------------------\n"; 
} 

int main(){
    double labScore; 
    int pfQuestions, pfMissed; 
    double pfMinPass; 
    double grammar, spelling, length, content; 
    int finalQuestions, finalMissed; 

    cout << "==================================================\n"; 
    cout << "           STUDENT COURSE GRADES PROGRAM          \n"; 
    cout << "==================================================\n\n"; 

    
    cout << "[1] Enter Lab Activity information:\n"; 
    cout << "    - Lab Score (0-100): "; 
    cin >> labScore; 
    GradedActivity lab(labScore); 

    
    cout << "\n[2] Enter Pass/Fail Exam information:\n"; 
    cout << "    - Total number of questions: "; 
    cin >> pfQuestions; 
    cout << "    - Number of questions missed: "; 
    cin >> pfMissed; 
    cout << "    - Minimum passing score (e.g., 70): "; 
    cin >> pfMinPass; 
    PassFailExam pfExam(pfQuestions, pfMissed, pfMinPass); 

    
    cout << "\n[3] Enter Essay scores:\n"; 
    cout << "    - Grammar score (max 30): "; 
    cin >> grammar; 
    cout << "    - Spelling score (max 20): "; 
    cin >> spelling; 
    cout << "    - Length score (max 20): "; 
    cin >> length; 
    cout << "    - Content score (max 30): "; 
    cin >> content; 
    Essay essay(grammar, spelling, length, content); 

    // 4. Input Final Exam information 
    cout << "\n[4] Enter Final Exam information:\n"; 
    cout << "    - Total number of questions: "; 
    cin >> finalQuestions; 
    cout << "    - Number of questions missed: "; 
    cin >> finalMissed; 
    FinalExam finalExam(finalQuestions, finalMissed); 

    
    CourseGrades course; 
    course.setLab(&lab); 
    course.setPassFailExam(&pfExam); 
    course.setEssay(&essay); 
    course.setFinalExam(&finalExam); 

    // Print the grades report 
    cout << "\n"; 
    course.print(); 
    return 0; 
}
