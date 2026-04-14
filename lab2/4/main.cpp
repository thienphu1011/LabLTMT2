#include <iostream> 
#include "Essay.h" 
 
using namespace std; 
 
int main() 
{ 
    Essay studentEssay; 
    double grammarScore, spellingScore, lengthScore, contentScore; 
 
    cout << "--- ESSAY GRADING SYSTEM ---\n"; 
    cout << "Enter the scores for the student's essay.\n"; 
 
    cout << "Grammar (0 - 30): "; 
    cin >> grammarScore; 
 
    cout << "Spelling (0 - 20): "; 
    cin >> spellingScore; 
 
    cout << "Correct length (0 - 20): "; 
    cin >> lengthScore; 
 
    cout << "Content (0 - 30): "; 
    cin >> contentScore; 
 
    
    studentEssay.setScores(grammarScore, spellingScore, lengthScore, contentScore); 
 
    
    cout << "\n--- RESULT ---\n"; 
    cout << "Grammar: " << studentEssay.getGrammar() << " / 30\n"; 
    cout << "Spelling: " << studentEssay.getSpelling() << " / 20\n"; 
    cout << "Length: " << studentEssay.getLength() << " / 20\n"; 
    cout << "Content: " << studentEssay.getContent() << " / 30\n"; 
 
    cout << "---------------------\n"; 
    cout << "Total Score: " << studentEssay.getScore() << " / 100\n"; 
    cout << "Final Letter Grade: " << studentEssay.getLetterGrade() << "\n"; 
 
    return 0; 
}
