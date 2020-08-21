#include <iostream>
#include <string>

/*���� �������� ������� ������� � ������. ������������ ��� �������� ����� ������ �������������.
������� ������: str - ������ ��� �������, symbol - ������, ������� �������� ���������� ���������.*/
bool symbolDetection(std::string str, char symbol)
{
    for ( unsigned int i = 0; i < str.length(); i++ )
        {
                if ( str [i] == symbol ) return true;
        }
    return false;
}

//������� ������� ����� ������ �������������, ��������������� ������ ����
std::string getString()
{
    std::string userInput;
    // ��������� ���������� ���������� �������� ��� ����� �������������
    unsigned int maxStringSymbol = userInput.max_size();
    while (true)
    {
        std::cout << "Please, enter not more, than " << maxStringSymbol << " symbols: ";
        std::getline(std::cin, userInput);
        if ( userInput.length() != 0 ) return userInput;
        else std::cout << "Invalid input. You haven't entered any symbols. Please, try again.\n" << std::endl ;
    }
}

/*������� ������� ����� ������ ������������� � ������������ ������������� ����������� �������.
������������ ��� �������� ����� ������������� ������, ��������������� ��������.
������� ������: symbol - ������, ������� ���������� ��������� ��� ����� ������������.*/
std::string getNoSymbolString(char symbol)
{
    std::cout << "Please, enter your string without symbol '" << symbol << "'." << std::endl;
    std::string noSymbolString;
    bool symbolFlag=true;
    while(symbolFlag)
    {
        noSymbolString = getString();
        symbolFlag = symbolDetection ( noSymbolString, symbol );
        if (symbolFlag == true)
        {
            std::cout << "Input is invalid. Symbol '" << symbol << "' is forbidden. Please, try again.\n" << std::endl;
        }
    }
    return noSymbolString;
}

/*�������, ��������� �� ������ ��������������� ������������� �������, �������� ������ ����.
������������ ��� �������� ���������� ��������.
������� ������: inputString - ������, ������� ���������� ���������������, symbol - ������, ����� �������� ���������� �������.*/
std::string getSingleSymbolString(std::string inputString, char symbol)
{
    std::string singleSymbolString = inputString;
    std::string buferString;
    unsigned int counter = 0;
    while (counter < singleSymbolString.length())
    {
        if ( singleSymbolString[counter] != symbol )
        {
            counter++;
        }
        else if ( singleSymbolString[counter] == singleSymbolString[counter+1] )
        {
            buferString = singleSymbolString.substr(counter+1,(singleSymbolString.length()-counter-1));
            if ( counter == 0)
            {
                singleSymbolString = buferString;
            }
            singleSymbolString.replace(counter, (singleSymbolString.length()-counter),(buferString+""));
        }
        else
        {
            counter++;
        }
    }
    return singleSymbolString;
}

/*

// �������, ��������������� ��� �������� ������������� ��������� � ������
std::string getSingleAsteriskString(std::string inputString)
{
    std::string singleAsteriskString = inputString;
    std::string buferString;
    unsigned int counter = 0;
    while (counter < singleAsteriskString.length())
    {
        if ( singleAsteriskString[counter] != '*' )
            counter++;
        else if ( singleAsteriskString[counter] == singleAsteriskString[counter+1] )
        {
            buferString = singleAsteriskString.substr(counter+1,(singleAsteriskString.length()-counter-1));
            if ( counter == 0)
            {
                singleAsteriskString = buferString;
            }
            singleAsteriskString.replace(counter, (singleAsteriskString.length()-counter),(buferString+""));
        }
        else
            counter++;
    }
    return singleAsteriskString;
}

bool asteriskDetection(std::string str)
{
    for ( unsigned int i = 0; i < str.length(); i++ )
        {
                if ( str [i] == '*' ) return true;
        }
    return false;
}

std::string getNoAsteriskString()
{
    std::string noAsteriskString;
    bool asteriskFlag=true;
    while(asteriskFlag)
    {
        noAsteriskString = getString();
        asteriskFlag = asteriskDetection ( noAsteriskString );
        if (asteriskFlag == true)
        {
            std::cout << "Input is invalid. You have entered asterisks. Please, try again.\n" << std::endl;
        }
    }
    return noAsteriskString;
}
*/
