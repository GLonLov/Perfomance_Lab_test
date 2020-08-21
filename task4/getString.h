#ifndef GETSTRING_H_INCLUDED
#define GETSTRING_H_INCLUDED

bool symbolDetection(std::string str, char symbol);
std::string getString();
std::string getNoSymbolString(char symbol);
std::string getSingleSymbolString(std::string inputString, char symbol);

#endif // GETSTRING_H_INCLUDED
