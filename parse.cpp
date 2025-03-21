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
    
}