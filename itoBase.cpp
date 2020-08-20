
/*������ ������� ������������ ����� (��� �����) �� ���������� ������� ���������� � ����� ������.
��������:
String itoBase(unsigned int nb, String base); nb � ��� ���������� �����, base � ������� ���������.
��������, �01� - ��������, �012� - ��������, �0123456789abcdef� - ����������������, �������� - ������� ���������� � ��������.
������� ������ ������ ������ ����� ������� ��������������� ����� �� ��������� ������� ���������(���������� ��������, ������������ � ������� , ����� ���) � ��������.
������ �� ������� ���������, ��������������� ������� �� �������� �������, ����������� � ������ ������ ����������.
�������� ������� ������������ ��������� ������� �� ���, �� ��� ���, ���� �� ������ ������ ���.
������ �� ������� ���������, ��������������� ���������� ��������� ��������, �������� � ������ ������ ����������.
*/

#include <iostream>
#include <string>
#include <math.h>


std::string dectoBase(unsigned int nb, std::string base)
 {
    // ������� �� ������� ����� �� ����
    int remainder;
    // ��������� ������� ����� �� ����, ��� ����������� ������ ����� �� ��������� ����� �����
    unsigned int divisionResult = nb;
    // ������ ������ ����������
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

 //������� ��� ������������ ������������ ������� � ��� "���������" � ���������� ������� ���������
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
    // ������� �������
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
