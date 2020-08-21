#include <iostream>
#include <string>

/*‘лаг проверки наличи€ символа в строке. »спользуетс€ дл€ проверки ввода строки пользователем.
¬ходные данные: str - строка дл€ анализа, symbol - символ, наличие которого необходимо проверить.*/
bool symbolDetection(std::string str, char symbol)
{
    for ( unsigned int i = 0; i < str.length(); i++ )
        {
                if ( str [i] == symbol ) return true;
        }
    return false;
}

//‘ункци€ запроса ввода строки пользователем, предотвращающа€ пустой ввод
std::string getString()
{
    std::string userInput;
    // ќбъ€вл€ем наибольшее количество символов дл€ ввода пользователем
    unsigned int maxStringSymbol = userInput.max_size();
    while (true)
    {
        std::cout << "Please, enter not more, than " << maxStringSymbol << " symbols: ";
        std::getline(std::cin, userInput);
        if ( userInput.length() != 0 ) return userInput;
        else std::cout << "Invalid input. You haven't entered any symbols. Please, try again.\n" << std::endl ;
    }
}

/*‘ункци€ запроса ввода строки пользователем с ограничением использовани€ конкретного символа.
»спользуетс€ дл€ контрол€ ввода пользователем строки, удовлетвор€ющей услови€м.
¬ходные данные: symbol - символ, который необходимо запретить дл€ ввода пользователю.*/
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

/*‘ункци€, удал€юща€ из строки последовательно повтор€ющиес€ символы, оставл€€ только один.
»спользуетс€ дл€ удалени€ незначащих символов.
¬ходные данные: inputString - строка, которую необходимо отредактировать, symbol - символ, дубли которого необходимо удалить.*/
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

// ‘ункци€, предназначенна€ дл€ удалени€ повтор€ющихс€ звездочек в строке
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
