#include <iostream>

using namespace std;

class GradedActivity {
private:
    double score;
public:
    GradedActivity() { score = 0.0; }
    GradedActivity(double s) { score = s; }
    void setScore(double s) { score = s; }
    double getScore() const { return score; }
    
    char getLetterGrade() const {
        char letterGrade;
        if (score > 89) letterGrade = 'A';
        else if (score > 79) letterGrade = 'B';
        else if (score > 69) letterGrade = 'C';
        else if (score > 59) letterGrade = 'D';
        else letterGrade = 'F';
        return letterGrade;
    }
};

class Essay : public GradedActivity {
private:
    double grammar;
    double spelling;
    double length;
    double content;

public:
    Essay() : GradedActivity() {
        grammar = 0.0;
        spelling = 0.0;
        length = 0.0;
        content = 0.0;
    }

    void setScores(double g, double s, double l, double c) {
        grammar = (g > 30) ? 30 : g;
        spelling = (s > 20) ? 20 : s;
        length = (l > 20) ? 20 : l;
        content = (c > 30) ? 30 : c;
        
        setScore(grammar + spelling + length + content);
    }

    double getGrammar() const { return grammar; }
    double getSpelling() const { return spelling; }
    double getLength() const { return length; }
    double getContent() const { return content; }
};

int main() {
    Essay studentEssay;
    studentEssay.setScores(28.5, 18.0, 15.5, 29.0);

    cout << studentEssay.getScore() << "\n";
    cout << studentEssay.getLetterGrade() << "\n";

    return 0;
}