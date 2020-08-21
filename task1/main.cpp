#include <iostream>
#include <string>
#include "numeralSystemConverter.h"
#include "getValues.h"

int main()
{
    std::cout << "Welcome to a universal numeral system converter for positive integers. It can work with any user-defined numeral systems." << std::endl;
    std::cout << "You will have to enter all necessary data manually through command line interface.\n" << std::endl;
    std::cout << "You should know the following rules:" << std::endl;
    std::cout << "1.Converter works only with positive integers. That means minus \' - \' or plus \' + \' will be recognized as a part of an integer." << std::endl;
    std::cout << "2.Space \' \' cannot be used as an input symbol neither in numbers, nor in numeral systems." << std::endl;
    std::cout << "3.Numeral system has a special format - set of symbols, except space \' \'. For example:" << std::endl;
    std::cout << "3.1.\"01\" describes binary system;" << std::endl;
    std::cout << "3.2.\"0123456789\" describes decimal system;" << std::endl;
    std::cout << "3.3.\"0123456789abcdef\" describes hexadecimal system;" << std::endl;
    std::cout << "3.4. Value of every symbol is defined according to its position in the string." << std::endl;
    std::cout << "3.5. Converter is case-sensitive. That means, for example, \"0123456789abcdef\" is not the same as \"0123456789ABCDEF\"\n" << std::endl;

    std::string userNumber;
    std::string userNumeralSourceSystem;
    bool correctInput = false;
    while (!correctInput)
    {
        std::cout << "Enter your number in your numeral system." << std::endl;
        userNumber = getNoSpacesString();
        std::cout << std::endl;
//        std::cout << userNumber << std::endl;
//        std::cout << userNumber.length() << std::endl;
        std::cout << "Please, enter the description of your source numeral system." << std::endl;
        std::cout << "Make sure, that all symbols in the number, you want to convert, are presented in your source numeral system." << std::endl;
        userNumeralSourceSystem = getUniqueStringNoSpaces();
//        std::cout << userNumeralSourceSystem << std::endl;
        std::cout << std::endl;
        if (isCompatible(userNumber, userNumeralSourceSystem) == false)
        {
            std::cout << "Entered number is not compatible with your source numeral system." << std::endl;
            std::cout << "One of the symbols cannot be found in the numeral system." << std::endl;
            if ( getYorN("Do you want to enter your number and numeral system again? Y/N : ") == false) return 0;
        }
        else correctInput = true;
    }
    std::cout << "Please, enter the description of your destination numeral system" << std::endl;
    std::string userNumeralDestinationSystem = getUniqueStringNoSpaces();
    std::cout << std::endl;
//    std::cout << userNumeralDestinationSystem << std::endl;
    std::cout << "Your number " << userNumber << " is converted from \n\" " << userNumeralSourceSystem << " \"" ;
    std::cout << "into \" " << userNumeralDestinationSystem << " \". \n The result is: ";
    std::cout << itoBase(userNumber, userNumeralSourceSystem,userNumeralDestinationSystem) << std::endl;
    return 0;
}
