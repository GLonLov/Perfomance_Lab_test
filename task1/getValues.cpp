#include <iostream>
#include <string>
#include <math.h>

unsigned int getUnsignedInt()
{
    // ќбъ€вл€ем наибольшее возможное целое число дл€ ввода пользователем
    unsigned int maxIntValue = (pow(2, (sizeof(int)*8))-1);
    while (true)
    {
        std::cout << "Please, enter any positive decimal integer from 0 to " << maxIntValue << ": ";
        double inputValue;
        std::cin >> inputValue;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            std::cout << "Input is invalid. You have entered invalid symbol. Please, try again.\n";
        }
        else if (inputValue < 0)
            std::cout << "Input is invalid. Entered numeral is negative. Please, try again.\n";
        else if (inputValue > maxIntValue)
            std::cout << "Input is invalid. Entered numeral is bigger, than " << maxIntValue << ". Please, try again.\n";
        else if (inputValue-floor(inputValue) != 0)
            std::cout << "Input is invalid. Entered numeral has a decimal point. Please, try again.\n";
        else
        {
            std::cin.ignore(32767,'\n');
            return (unsigned int) inputValue;
        }

    }
}

bool spaceDetection(std::string str)
{
    for ( unsigned int i = 0; i < str.length(); i++ )
        {
                if ( str [i] == ' ' ) return true;
        }
    return false;
}

std::string getString()
{
    std::string userInput;
    // ќбъ€вл€ем наибольшее количество символов дл€ ввода пользователем
    unsigned int maxStringSymbol = userInput.max_size();
    while (true)
    {
        std::cout << "Please, insert a set of unique symbols(or a single symbol) without spaces, but no more than " << maxStringSymbol << " symbols: " << std::endl;
        std::getline(std::cin, userInput);
        if ( userInput.length() != 0 ) return userInput;
        else std::cout << "Invalid input. You haven't entered any symbols. Please, try again.\n" << std::endl ;
    }
}

std::string getNoSpacesString()
{
    std::string noSpacesString;
    bool spaceFlag=true;
    while(spaceFlag)
    {
        noSpacesString = getString();
        spaceFlag = spaceDetection ( noSpacesString );
        if (spaceFlag == true)
        {
            std::cout << "Input is invalid. You have entered spaces. Please, try again.\n" << std::endl;
        }
    }
    return noSpacesString;
}

bool isNotUnique(std::string str)
{
    for ( unsigned int i = 0; i < str.length(); i++ )
        {
            for ( unsigned int j = 0; j < str.length(); j++)
            {
                if ( i == j ) continue;
                if (str[i] == str[j]) return true;
            }
        }
    return false;
}

std::string getUniqueString()
{
    std::string userUniqueString;
    bool notUniqueFlag = true;
    while (notUniqueFlag)
    {
        userUniqueString = getString();
        notUniqueFlag = isNotUnique (userUniqueString);
        if (isNotUnique (userUniqueString) == true)
        {
            std::cout << "Input is invalid. You have entered recurrent symbols. Please, try again.\n" << std::endl;
        }
    }
    //std::cout << userUniqueString;
    return userUniqueString;
}

std::string getUniqueStringNoSpaces()
{
    std::string userUniqueStringNoSpaces;
    bool notUniqueFlag = true;
    while (notUniqueFlag)
    {
        userUniqueStringNoSpaces = getNoSpacesString();
        notUniqueFlag = isNotUnique (userUniqueStringNoSpaces);
        if (isNotUnique (userUniqueStringNoSpaces) == true)
        {
            std::cout << "Input is invalid. You have entered recurrent symbols. Please, try again.\n" << std::endl;
        }
    }
    //std::cout << userUniqueString;
    return userUniqueStringNoSpaces;
}


bool isCompatible(std::string number, std::string numeralSystem)
{
    //—четчик дл€ проверки
    unsigned int counter = 0;
    for ( unsigned int i = 0; i < number.length() ; i++)
    {
        for ( unsigned int j = 0; j < numeralSystem.length(); j++)
        {
            if ( number[i] != numeralSystem[j])
            {
                counter++;
            }
            else break;
        }
        if ( counter == numeralSystem.length()) return false;
        else counter = 0;
    }
    return true;
}

bool getYorN (std::string question)
{
    char userAnswer;
    while (true)
    {
        std::cout << question;
        std::cin >> userAnswer;
        if (userAnswer == 'Y' || userAnswer == 'y') return true;
        if (userAnswer == 'N'|| userAnswer == 'n') return false;
        else std::cout << "Invalid input, please, try again.\n" << std::endl;
    }
}
