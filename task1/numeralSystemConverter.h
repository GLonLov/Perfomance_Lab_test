#ifndef NUMERALSYSTEMCONVERTER_H_INCLUDED
#define NUMERALSYSTEMCONVERTER_H_INCLUDED

std::string dectoBase(unsigned int nb, std::string base);
std::string itoBase(std::string nb, std::string baseSrc, std::string baseDst);
unsigned int basetoDec(std::string nb, std::string baseSrc);
unsigned int baseScan(std::string base, char symbol);

#endif // NUMERALSYSTEMCONVERTER_H_INCLUDED
