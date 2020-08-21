#include <iostream>
#include <string>
#include "getString.h"

bool isEqual(std::string string1, std::string string2, char symbol);
bool onlySymbolLeft(std::string,unsigned int index, char symbol);

int main()
{
    char asterisk = '*';
    std::string string1 = getNoSymbolString(asterisk);
    std::string string2 = getString();
    if (isEqual(string1, string2, asterisk) == true)
    {
        std::cout << "\" " << string1 << " \" " << "\" " << string2 << " \" " << "- OK" <<std::endl;
    }
    else
    {
        std::cout << "\" " << string1 << " \" " << "\" " << string2 << " \" " << "- KO" <<std::endl;
    }
    return 0;
}


/*
Функция для сравнения равенства двух строк, в одной из которых используется специальный символ,
который заменяет собой количество любых символов.
Входные данные:
1. string1 - строка для сравнения без специальных символов;
2. string2 - строка для сравнения, которая может содержать специальный универсальный символ;
3. symbol - универсальный символ, который заменяет собой количество любых символов
*/
bool isEqual (std::string string1, std::string string2, char symbol)
{
    std::string buferString2 = getSingleSymbolString(string2, symbol);
    unsigned int indexString1 = 0;
    unsigned int indexString2 = 0;
    bool symbolFlag = false;
    unsigned int symbolPosition;
    while( indexString1 < string1.length() )
    {
        // else if (buferString2[buferString2.length()-1] != symbol) return false;
        while ( indexString2 < buferString2.length() )
        {
            std::cout << indexString1 << " - " << indexString2 << std::endl;
            if (string1[indexString1] == buferString2[indexString2])
            {
                std::cout << "- " << string1[indexString1] << " and " << buferString2[indexString2] << " are equal." << std::endl;
                indexString1++;
                indexString2++;
                //break;
            }
            else if (buferString2[indexString2] == symbol)
            {
                std::cout << "- " << string1[indexString1] << " and " << buferString2[indexString2] << " are not equal, but " << buferString2[indexString2] << "is " << symbol << std::endl;
                symbolPosition = indexString2;
                symbolFlag = true;
                indexString2++;
            }
            else if (symbolFlag == true)
            {
                std::cout << "- " << string1[indexString1] << " and " << buferString2[indexString2] << " are not equal, but " << symbolFlag << "is on." << std::endl;
                if (indexString1 < string1.length())
                {
                    indexString1++;
                    indexString2 = symbolPosition;
                }
                else
                {
                    break;
                }

                //break;
            }
            else
            {
                std::cout << "- " << string1[indexString1] << " and " << buferString2[indexString2] << " are not equal, and " << symbolFlag << "is off." << std::endl;
                return false;
            }

            if ( indexString1 >= string1.length() && onlySymbolLeft(buferString2, indexString2, symbol) == true )
                break;
            else if (string1 == (buferString2 + symbol))
            {
                std::cout << "- " << buferString2 << " check has ended sucessfully" <<std::endl;
                return true;
            }

        }
        if (indexString2 == buferString2.length())
        {
            if (indexString1 == string1.length())
            {
                std::cout << "- " << buferString2 << " check has ended sucessfully" <<std::endl;
                break;
            }
            else if (buferString2[indexString2-1] == symbol)
            {
                std::cout << "- " << buferString2 << " check has ended sucessfully" <<std::endl;
                break;
            }
            else
            {
                indexString2 = symbolPosition;
                std::cout << "- " << string1 << " has not ended, we need to check further;" <<std::endl;
            }
        }
        else break;

    }
    if ( (indexString1 == string1.length() && indexString2 < buferString2.length()) && ( (string1+symbol) != buferString2.substr(1,buferString2.length()-1)))
    {
        return false;
    }
    else
    {
        return true;
    }
}


//Функция проверяет символы строки после указателя Index. Возвращает true, если остался только один symbol, или false, если символов несколько или он отличен от symbol.
bool onlySymbolLeft(std::string str,unsigned int index, char symbol)
{
    //Количество оставшихся символов
    unsigned int symbolsLeft = str.length()-index-1;
    if(symbolsLeft == 1 && str[index+1] == symbol)
        return true;
    else
        return false;
}
