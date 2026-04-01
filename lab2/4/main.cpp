#include <iostream>
#include "Essay.h"

using namespace std;

int main() {
    Essay studentEssay;
    studentEssay.setScores(28.5, 18.0, 15.5, 29.0);

    cout << studentEssay.getScore() << "\n";
    cout << studentEssay.getLetterGrade() << "\n";

    return 0;
}