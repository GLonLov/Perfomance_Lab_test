#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>


void paramLine(double x1, double y1, double z1, double x2, double y2, double z2);
void paramLineMas(double m1[3], double m2[3], double p[3]);
void canonLineMas(double m1[3], double m2[3], double p[3]);
bool isonLine(double m1[3], double p[3], double check[3]);
bool isonSphere(double m1[3], double center[3], double radius);
bool solveSquareEquation( double a, double b, double c, double result[2]);
bool isDigit(char sourceString);
unsigned int searchString(std::string sourceString, std::string targetString);
using namespace std;

int main()
{
    double m1[3] = {0, 0, 0};
    std::cout << "Hello world!" << std::endl;
    std::cout << "Please, enter first point coordinates." << std::endl;
    std::cout << "x = " ;
    cin >> m1[0];
    std::cout << "y = " ;
    cin >> m1[1];
    std::cout << "z = " ;
    cin >> m1[2];
    double m2[3] = {0, 0, 0};
    std::cout << "Please, enter second point coordinates." << std::endl;
    std::cout << "x = " ;
    cin >> m2[0];
    std::cout << "y = " ;
    cin >> m2[1];
    std::cout << "z = " ;
    cin >> m2[2];
    //Координаты вектора
    double p[3] = {0, 0, 0};
    double center[3] = {0, 0, 0};
    std::cout << "Please, enter sphere center coordinates." << std::endl;
    std::cout << "x = " ;
    cin >> center[0];
    std::cout << "y = " ;
    cin >> center[1];
    std::cout << "z = " ;
    cin >> center[2];
    double radius = 0;
    std::cout << "Please, enter sphere radius." << std::endl;
    std::cout << "R = " ;
    cin >> radius;
    //Массив для вывода результатов решения квадратного уравнения
    double squareEquation[2] = {0, 0};
    //Координаты точек пересечения прямой со сферой
    double collisionPoint1[3] = {0, 0, 0};
    double collisionPoint2[3] = {0, 0, 0};
    paramLineMas(m1, m2, p);

/*    std::string strInput;
//    std::string strLine;
//    std::string strSphere;

    ifstream inf("line.sphere.txt");
    if (!inf)
	{
		std::cerr << "Uh oh, line.sphere.txt could not be opened for reading!" << std::endl;
		exit(1);
	}
    while (inf)
	{
		getline(inf, strInput);
	}
    std::cout << strInput <<  std::endl;
    std::cout << searchString(strInput, "line") <<  std::endl;;
    std::cout << searchString(strInput, "sphere") <<  std::endl;;
    unsigned int linePosition = searchString(strInput, "line");
    unsigned int spherePosition = searchString(strInput, "sphere");
    if ( linePosition < spherePosition)
    {
        strLine = strInput.substr(linePosition,(spherePosition-linePosition));
        strSphere = strInput.substr(spherePosition,strInput.length()-1);
    }
    else
    {
        strSphere = strInput.substr(spherePosition,(linePosition-spherePosition));
        strLine = strInput.substr(linePosition,strInput.length()-1);
    }
    std::cout << strSphere <<  std::endl;;
    std::cout << strLine <<  std::endl;;
    unsigned int radiusPosition = searchString(strSphere, "radius");
    unsigned int centerPosition = searchString(strSphere, "center");
    std::string buferString;
    unsigned int indexBufer = 0;
    unsigned int index = 0;
    for (unsigned int i = searchString(strLine, "[")+1; i < searchString(strLine, "]"); i++)
    {
        if (isDigit(strLine[i]) == true)
        {
            buferString.insert(indexBufer, strLine, i, 1);
        }
        else if ()
        {
            m1[index] = std::stod(buferString);
            indexBufer = 0;
            index++;
        }
    }
    std::cout << m1[0] <<  std::endl;
    std::cout << m1[1] <<  std::endl;
    std::cout << m1[2] <<  std::endl;
    std::cout << strLine <<  std::endl;


    for (unsigned int i = searchString(strLine, "[")+1; i < searchString(strLine, "]"); i++)
    {
        m1[index] = std::stod(strLine.substr());
        std::cout <<  m1[index] <<  std::endl;;
    }

    std::string strLineCoord1 = strLine.substr(searchString(strLine, "["),(strLine.length() - searchString(strLine, "[") - searchString(strLine, "]")));
//    strLine.erase(searchString(strLine, "["),searchString(strLine, "]"));
//    std::string strLineCoord2 = strLine.substr(searchString(strLine, "["),searchString(strLine, "]"));
    std::cout << strLineCoord1 <<  std::endl;;
//    std::cout << strLineCoord2 <<  std::endl;;

*/

    if ( p[1] != 0 )
    {
        // С целью дальнейшего решения задачи возникла необходимость создать промежуточные переменные
        double q = p[0]/p[1];
        double s = p[2]/p[1];
        double t = q * m1[1] - m1[0];
        double u = s * m1[1] - m1[2];
        // Определяем коэффициенты квадратного уравнения
        double a = pow(q,2) + 1 + pow(s,2);
        double b = - (2 * q * ( t + center[0] ) + 2 * center[1] + 2 * s * ( u + center[2] ));
        double c = pow( ( t + center[0] ), 2 ) + pow( center[1], 2 ) +  pow( ( u + center[2] ), 2 ) - pow ( radius, 2 );
        if (solveSquareEquation( a, b, c, squareEquation) == 1)
        {
            collisionPoint1[1] = squareEquation[0];
            collisionPoint1[0] = q * collisionPoint1[1] - t;
            collisionPoint1[2] = s * collisionPoint1[1] - u;
            collisionPoint2[1] = squareEquation[1];
            collisionPoint2[0] = q * collisionPoint2[1] - t;
            collisionPoint2[2] = s * collisionPoint2[1] - u;
            std::cout << "Collision Point 1" << std::endl;
            std::cout << collisionPoint1[0] << std::endl;
            std::cout << collisionPoint1[1] << std::endl;
            std::cout << collisionPoint1[2] << std::endl;
            std::cout << "Collision Point 2" << std::endl;
            std::cout << collisionPoint2[0] << std::endl;
            std::cout << collisionPoint2[1] << std::endl;
            std::cout << collisionPoint2[2] << std::endl;

            if ( isonLine( m1, p, collisionPoint1) == true && isonSphere(collisionPoint1, center, radius) == true)
                std::cout << "Collision Point 1 is SUCCESS!!!" << std::endl;
            if ( isonLine( m1, p, collisionPoint2) == true && isonSphere(collisionPoint2, center, radius) == true)
                std::cout << "Collision Point 2 is SUCCESS!!!" << std::endl;
            return 0;
        }
    }
    else if ( p[0] != 0 )
    {
        collisionPoint1[1] = m1[1];
        collisionPoint2[1] = m1[1];
        // С целью дальнейшего решения задачи возникла необходимость создать промежуточные переменные
        double s = p[2]/p[0];
        double u = s * m1[0] - m1[2];
        // Определяем коэффициенты квадратного уравнения
        double a = 1 + pow(s,2);
        double b = - (2 * center[0] + 2 * s * ( u + center[2] ));
        double c = pow( center[0] , 2 ) +  pow( ( u + center[2] ), 2 ) + pow(m1[1] - center[1],2)- pow ( radius, 2 );
        if (solveSquareEquation( a, b, c, squareEquation) == 1)
        {
            collisionPoint1[0] = squareEquation[0];
            collisionPoint1[2] = s * collisionPoint1[0] - u;
            collisionPoint2[0] = squareEquation[1];
            collisionPoint2[2] = s * collisionPoint2[0] - u;
            std::cout << "Collision Point 1" << std::endl;
            std::cout << collisionPoint1[0] << std::endl;
            std::cout << collisionPoint1[1] << std::endl;
            std::cout << collisionPoint1[2] << std::endl;
            std::cout << "Collision Point 2" << std::endl;
            std::cout << collisionPoint2[0] << std::endl;
            std::cout << collisionPoint2[1] << std::endl;
            std::cout << collisionPoint2[2] << std::endl;

            if ( isonLine( m1, p, collisionPoint1) == true && isonSphere(collisionPoint1, center, radius) == true)
                std::cout << "Collision Point 1 is SUCCESS!!!" << std::endl;
            if ( isonLine( m1, p, collisionPoint2) == true && isonSphere(collisionPoint2, center, radius) == true)
                std::cout << "Collision Point 2 is SUCCESS!!!" << std::endl;
            return 0;
        }
    }
    else if ( p[2] != 0 )
    {
        collisionPoint1[0] = m1[0];
        collisionPoint1[1] = m1[1];
        collisionPoint2[0] = m1[0];
        collisionPoint2[1] = m1[1];
        double a = 1;
        double b = -2;
        double c = pow( center[2] , 2 ) + pow( (m1[0]-center[0]), 2) + pow( (m1[1]-center[1]), 2) - pow( radius, 2 ) ;
        if (solveSquareEquation( a, b, c, squareEquation) == 1)
        {
            collisionPoint1[2] = squareEquation[0];
            collisionPoint2[0] = squareEquation[1];
            collisionPoint2[2] = squareEquation[1];
            std::cout << "Collision Point 1" << std::endl;
            std::cout << collisionPoint1[0] << std::endl;
            std::cout << collisionPoint1[1] << std::endl;
            std::cout << collisionPoint1[2] << std::endl;
            std::cout << "Collision Point 2" << std::endl;
            std::cout << collisionPoint2[0] << std::endl;
            std::cout << collisionPoint2[1] << std::endl;
            std::cout << collisionPoint2[2] << std::endl;

            if ( isonLine( m1, p, collisionPoint1) == true && isonSphere(collisionPoint1, center, radius) == true)
                std::cout << "Collision Point 1 is SUCCESS!!!" << std::endl;
            if ( isonLine( m1, p, collisionPoint2) == true && isonSphere(collisionPoint2, center, radius) == true)
                std::cout << "Collision Point 2 is SUCCESS!!!" << std::endl;
            return 0;
        }
    }

    return 0;
}

//Функция принимает координаты двух точек и выводит на экран систему параметрических уравнений, описывающих прямую в пространстве
void paramLine(double x1, double y1, double z1, double x2, double y2, double z2)
{
    // координаты вектора прямой
    double p1 = x2 - x1;
    double p2 = y2 - y1;
    double p3 = z2 - z1;
    std::cout << "x = " << p1 << " * t + (" << x1 << ")" << std::endl;
    std::cout << "y = " << p2 << " * t + (" << y1 << ")" << std::endl;
    std::cout << "z = " << p3 << " * t + (" << z1 << ")" << std::endl;
}

//Функция принимает координаты двух точек в виде массива и выдает координаты вектора, описываюего прямую
void paramLineMas(double m1[3], double m2[3], double p[3])
{
    char coord[3] = {'x','y','z'};
    for (int i = 0 ; i <= 2 ; i++)
    {
        p[i] = m2[i] - m1[i];
        std::cout << coord [i] << " = " << p[i] << " * t + (" << m1[i] << ")" << std::endl;
    }
}


//Функция принимает координаты двух точек в виде массива и выводит на экран канонические уравнения прямой
void canonLineMas(double m1[3], double m2[3], double p[3])
{
    char coord[3] = {'x','y','z'};
    paramLineMas( m1, m2, p);
    for (int i = 0 ; i <= 2 ; i++)
    {
        if ( p[i] == 0)
        {
            std::cout << coord [i] << " - ( " << m1[i] << " ) = 0 " << std::endl;
        }
        else
        std::cout << "( ( "<< coord [i] << " - " << m1[i] << " ) / " << p[i] << ")" << std::endl;
    }
}


//Функция проверяет, принадлежит ли точка с координатами check прямой. Принимает координату точки и вектора описывающего прямую и координаты проверяемой точки.
//ВАЖНО! Нельзя направлять пустой вектор.
bool isonLine(double m1[3], double p[3], double check[3])
{
    double canonResult[3] = {0, 0, 0};
    bool isCorrect[3] = {0, 0, 0};
    int sumIsCorrect = 0;
    for (int i = 0 ; i <= 2 ; i++)
    {
        if ( p[i] != 0)
        {
            canonResult[i] = (check[i] - m1[i])/p[i];
        }
        else if (check[i] != m1[i]) return false;
        else isCorrect[i] = 1;
    }
    for (int i = 0 ; i <= 2 ; i++)
    {
        sumIsCorrect = sumIsCorrect + isCorrect[i];
    }
    if ( sumIsCorrect == 2 ) return true;
    if ( sumIsCorrect == 1 )
    {
        if (isCorrect[0] == 1 && canonResult[1] == canonResult[2]) return true;
        if (isCorrect[1] == 1 && canonResult[0] == canonResult[2]) return true;
        if (isCorrect[2] == 1 && canonResult[0] == canonResult[1]) return true;
    }
    else if (canonResult[0] == canonResult[1] && canonResult[1] == canonResult[2]) return true;
    return false;
}

//Функция проверяет, принадлежит ли точка сфере. Принимает координаты точки, координаты центра сферы и радиус
bool isonSphere(double m1[3], double center[3], double radius)
{
    double buffer;
    //Подставляем координаты точки в уравнение, описывающее все точки сферы
    buffer = pow((m1[0] - center[0]),2) + pow((m1[1] - center[1]),2) + pow((m1[2] - center[2]),2) - pow(radius,2);
    if ( buffer == 0 ) return true;
    else return false;
}

//Функция решения квадратного уравнения. Принимает коэффициенты уравнения и массив для хранения результата.
// Возвращает true, если уравнение решено, возвращает false, если уравнение не имеет решений.
bool solveSquareEquation( double a, double b, double c, double result[2])
{
    std::cout << a << " * x^2 + " << b << " * x + " << c << " = 0" << std::endl;
    //Дискриминант
    double D = pow(b,2) - 4 * a * c;
    if ( D >= 0 )
    {
        result[0] = (-b + sqrt(D)) / ( 2 * a );
        result[1] = (-b - sqrt(D)) / ( 2 * a );
        return 1;
    }
    else return 0;
}

//Функция ищет в строке sourceString, всю строку searchString, возвращает положение первого символа строки
unsigned int searchString(std::string sourceString, std::string targetString)
{
    int counter =0;
    int startcheck;
    for (unsigned int i = 0; i < sourceString.length(); i++)
    {
        if ( sourceString[i] == targetString[0])
        {
            startcheck = i;
            for (unsigned int j = 0; j < targetString.length(); j++)
            {
                if ( sourceString[i] == targetString[j])
                {
                    counter++;
                }
                else break;
                i++;
            }
            i = startcheck;
            if (counter == targetString.length())
            {
                return i;
            }
            else counter = 0;
        }
    }
    std::cerr << "Word was not found!!!" << endl;
}

bool isDigit(char sourceString)
{
    if (sourceString == '0' || sourceString == '1' || sourceString == '2' || sourceString == '3' || sourceString == '4' || sourceString == '5' || sourceString == '6' || sourceString == '7' || sourceString == '8' || sourceString == '9'|| sourceString == '.' )
    {
        return true;
    }
    return false;
}
