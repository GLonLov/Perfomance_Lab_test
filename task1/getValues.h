#ifndef GETVALUES_H_INCLUDED
#define GETVALUES_H_INCLUDED

unsigned int getUnsignedInt();
std::string getString();
std::string getUniqueString();
std::string getUniqueStringNoSpaces();
std::string getNoSpacesString();
bool isNotUnique(std::string str);
bool spaceDetection(std::string str);
bool isCompatible(std::string number, std::string numeralSystem);
bool getYorN (std::string question);

#endif // GETVALUES_H_INCLUDED
