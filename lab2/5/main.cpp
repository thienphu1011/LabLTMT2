#include <iostream>
#include "GradedActivity.h"
#include "PassFailExam.h"
#include "Essay.h"
#include "FinalExam.h"
#include "CourseGrades.h"

using namespace std;

int main() {
    GradedActivity lab;
    lab.setScore(85.0);

    PassFailExam pfExam;
    pfExam.setScore(75.0);

    Essay essay;
    essay.setScores(25.0, 18.0, 15.0, 28.0);

    FinalExam finalExam(50, 4);

    CourseGrades course;
    course.setLab(&lab);
    course.setPassFailExam(&pfExam);
    course.setEssay(&essay);
    course.setFinalExam(&finalExam);

    course.print();

    return 0;
}