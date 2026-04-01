#ifndef FILEFILTERS_H
#define FILEFILTERS_H

#include <fstream>

using namespace std;

class FileFilter {
public:
    virtual char transform(char ch) = 0;
    void doFilter(ifstream &in, ofstream &out);
};

class EncryptionFilter : public FileFilter {
private:
    int key;
public:
    EncryptionFilter(int k);
    char transform(char ch) override;
};

class UppercaseFilter : public FileFilter {
public:
    char transform(char ch) override;
};

class CopyFilter : public FileFilter {
public:
    char transform(char ch) override;
};

#endif