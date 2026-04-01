#include "FileFilters.h"
#include <cctype>

void FileFilter::doFilter(ifstream &in, ofstream &out) {
    char ch;
    while (in.get(ch)) {
        out.put(transform(ch));
    }
}

EncryptionFilter::EncryptionFilter(int k) : key(k) {}

char EncryptionFilter::transform(char ch) {
    return ch + key;
}

char UppercaseFilter::transform(char ch) {
    return toupper(ch);
}

char CopyFilter::transform(char ch) {
    return ch;
}