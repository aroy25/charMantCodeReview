#include <iostream>

using namespace std;

//this extracrt characteristic part of a number string 
bool characteristic(const char numString[], int& c) 
{
    int i = 0;
    while (numString[i] == ' ') i++; // skip first spaces

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
//writing som test code to make sure the function works
void testChar(const)