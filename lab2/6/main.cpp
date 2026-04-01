#include <iostream>
#include <fstream>
#include "FileFilters.h"

using namespace std;

int main() {
    ofstream outFile("input.txt");
    outFile << "Hello World! This is a test file for problem 6.";
    outFile.close();

    ifstream in("input.txt");
    ofstream outCopy("copy.txt");
    CopyFilter cf;
    cf.doFilter(in, outCopy);
    in.close();
    outCopy.close();

    in.open("input.txt");
    ofstream outUpper("upper.txt");
    UppercaseFilter uf;
    uf.doFilter(in, outUpper);
    in.close();
    outUpper.close();

    in.open("input.txt");
    ofstream outEncrypt("encrypt.txt");
    EncryptionFilter ef(5);
    ef.doFilter(in, outEncrypt);
    in.close();
    outEncrypt.close();

    return 0;
}