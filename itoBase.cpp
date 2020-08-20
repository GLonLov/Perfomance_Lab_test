
/*Данная функция конвертирует число (без знака) из десятичной системы исчисления в любую другую.
Прототип:
String itoBase(unsigned int nb, String base); nb – это подаваемое число, base – система счисления.
Например, «01» - двоичная, «012» - троичная, «0123456789abcdef» - шеснадцатиричная, «собачки» - система исчисления в собачках.
Функция решает данную задачу путем деления конвертируемого числа на основание системы счисления(количество символов, используемых в системе , далее ОСС) с остатком.
Символ из системы счисления, соответствующий остатку от операции деления, вставляется в начало строки результата.
Неполное частное подвергается процедуре деления на ОСС, до тех пор, пока не станет меньше ОСС.
Символ из системы счисления, соответствующий финальному неполному частному, ставится в начало строки результата.
*/

#include <iostream>
#include <string>
#include <math.h>


std::string dectoBase(unsigned int nb, std::string base)
 {
    // Остаток от деления числа на базу
    int remainder;
    // Результат деления числа на базу, для правильного старта цикла по умолчанию равен числу
    unsigned int divisionResult = nb;
    // Строка вывода результата
    std::string itoBaseResult;
    while (divisionResult != 0)
    {
        remainder = divisionResult % base.length();
        divisionResult = divisionResult / base.length();
        itoBaseResult.insert(0, base, remainder, 1);
    }
    itoBaseResult.insert(0, base, divisionResult, 1);
    return itoBaseResult;

 }

 //Функция для установления соответствия символа с его "значением" в десятичной системе счисления
unsigned int baseScan(std::string base, char symbol)
{
    for (int i = 0; i < base.length(); i++ )
    {
        if ( base[i] == symbol) return i;
    }
}

unsigned int basetoDec(std::string nb, std::string baseSrc)
{
    unsigned int basetoDecResult = 0;
    // Степень разряда
    unsigned int powerDigitOrder;
    for (int i = 0; i < nb.length() ; i++)
    {
        powerDigitOrder = pow(baseSrc.length(),(nb.length()-i-1));
        basetoDecResult += powerDigitOrder * baseScan( baseSrc, nb[i]);
    }
    return basetoDecResult;
}

std::string itoBase(std::string nb, std::string baseSrc, std::string baseDst)
{
    unsigned int decConv = basetoDec(nb, baseSrc);
    std::string itoBaseResult = dectoBase( decConv, baseDst);
    return itoBaseResult;
}
