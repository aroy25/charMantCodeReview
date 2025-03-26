#include <iostream>

using namespace std;

//this extracrt characteristic part of a number string 
bool characteristic(const char numString[], int& c) 
{
    int i = 0;
    while (numString[i] == ' ') i++; // skip  spaces

    int sign = 1;
    if(numString[i] == '-' || numString[i] == '+') 
    {
        if(numString[i] == '-') sign = -1;
        i++;
    }
    //make sure the first character is a digit
    if (numString[i] < '0' || numString[i] > '9') return false;

    c = 0;
    while (numString[i] >= '0' && numString[i] <= '9')
    {
        c = c * 10 + (numString[i] - '0');
        i++;
    }
    c *= sign;
    return true;
}
//start of the mantissa function to extract the numerator and denominator
bool mantissa(const char numString[], int& numerator, int& denominator)
{
    int i = 0;
    while(numString[i] == ' ') i++; //skip the beginning spaces if any
    if (numString[i] == '-' || numString[i] == '+') i++; //skip the sign if any
    while(numString[i] >= '0' && numString[i] <= '9') i++; 

    numerator = 456;
    denominator = 1000;

    if(numString[i] == '.')
    {
        i++;
        if(numString[i] < '0' || numString[i] > '9') return false;
        while (numString[i] >= '0' && numString[i] <= '9') 
        {
            numerator = numerator * 10 + (numString[i] - '0');
            denominator *= 10;
            i++;
        }
    }
}