#include <iostream>
using namespace std;

//required function prototypes
bool characteristic(const char numString[], int& c);
bool mantissa(const char numString[], int& numerator, int& denominator);

//operator functions
bool add(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len);
bool subtract(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len);
bool multiply(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len);
bool divide(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len);

//helper functions
int improperFraction(int& charNum, int& num, int& den);
void getCommonDenom(int& n1, int& d1, int& n2, int& d2, int& commonDen);
void getResult(int& num, int& den, char* result, int& len);
void convertIntToChar(int& num, int& index, char* resultArr, int& len);
void inverseFraction (int& num, int& den);

//master operator functions
bool arithmeticOperation (int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len, char symbol);

int main()
{
    //this c-string, or array of 8 characters, ends with the null terminating character '\0'
    //['1', '2', '3', '.', '4', '5', '6', '\0']
    const char number[] = "123.456";
    int c, n, d;

    //if both conversions from c-string to integers can take place
    if(characteristic(number, c) && mantissa(number, n, d))
    {
        //do some math with c, n, and d
        cout<<"c: "<<c<<endl;
        cout<<"n: "<<n<<endl;
        cout<<"d: "<<d<<endl;
    }
    else //at least one of the conversions failed
    {
        //handle the error on input
        cout<<"Error on input"<<endl;
    }

    //room for 9 characters plus the null terminating character
    char answer[10];
    int c1, n1, d1;
    int c2, n2, d2;

    //initialize the values
    c1 = 24;
    n1 = 0;
    d1 = 5;

    c2 = 2;
    n2 = 0;
    d2 = 4;

    //if the c-string can hold at least the characteristic
    if(add(c1, n1, d1, c2, n2, d2, answer, 10))
    {
        //display string with answer 4.1666666 (cout stops printing at the null terminating character)
        cout<<"Answer: "<<answer<<endl;
    }
    else
    {
        //display error message
        cout<<"Error on add"<<endl;
    }

    if(subtract(c1, n1, d1, c2, n2, d2, answer, 10))
    {
        //display string with answer 4.1666666 (cout stops printing at the null terminating character)
        cout<<"Answer: "<<answer<<endl;
    }
    else
    {
        //display error message
        cout<<"Error on subtract"<<endl;
    }
    
    if(multiply(c1, n1, d1, c2, n2, d2, answer, 10))
    {
        //display string with answer 4.1666666 (cout stops printing at the null terminating character)
        cout<<"Answer: "<<answer<<endl;
    }
    else
    {
        //display error message
        cout<<"Error on multiply"<<endl;
    }
    
    if(divide(c1, n1, d1, c2, n2, d2, answer, 10))
    {
        //display string with answer
        cout<<"Answer: "<<answer<<endl;
    }
    else
    {
        //display error message
        cout<<"Error on divide"<<endl;
    }

    return 0;

} 
// Added in the characteristc function from my parse.cpp // parse.cpp was my test area// complete updated
bool characteristic(const char numString[], int& c) 
{
    int i = 0;
    while (numString[i] == ' ') i++; // skip first spaces if any

    int sign = 1;
    // start with checking for a sign's that could be there 
    if(numString[i] == '-' || numString[i] == '+')
    {
        if(numString[i] == '-') sign = -1; 
        i++; 
    }
    //make sure the a character that shows is a digit
    if (numString[i] < '0' || numString[i] > '9') return false;

    c = 0;
    while (numString[i] >= '0' && numString[i] <= '9') // Convert that num characters to an int value
    {
        c = c * 10 + (numString[i] - '0'); 
        i++;
    }
    c *= sign;
    return true; // Return true since a valid char was there
}
//--
bool mantissa(const char numString[], int& numerator, int& denominator)
{
    int i = 0;
    while(numString[i] == ' ') i++; //skip the beginning spaces if any
    if (numString[i] == '-' || numString[i] == '+') i++; //check for signs 
    while(numString[i] >= '0' && numString[i] <= '9') i++; 

    numerator = 0;
    denominator = 1;

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
    return true;
}
//--
//-------------------------------------------------
//Each operator function returns the result of the
//helper function based on which function is called
//-------------------------------------------------
//
bool add(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
    //'+' confirms this is addition
    return arithmeticOperation(c1, n1, d1, c2, n2, d2, result, len, '+');
}
//--
bool subtract(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
    //'-' confirms this is subtraction
    return arithmeticOperation(c1, n1, d1, c2, n2, d2, result, len, '-');
}
//--
bool multiply(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
    //'*' confirms this is multiplication
    return arithmeticOperation(c1, n1, d1, c2, n2, d2, result, len, '*');
}
//--
bool divide(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
    //'/' confirms this is division
    return arithmeticOperation(c1, n1, d1, c2, n2, d2, result, len, '/');
}
//--
int improperFraction(int& charNum, int& num, int& den)
{
    //ex: 2 3/4 -> num = (2 * 4) + 3;
    return num = (charNum * den) + num;
}
//--
void getCommonDenom(int& n1, int& d1, int& n2, int& d2, int& commonDen)
{
    //establishes common denominator
    commonDen = d1 * d2;
    
    //updates numerator
    n1 *= d2;
    n2 *= d1;
    
    //updates denominator to all match
    d1 = d2 = commonDen;
}
//--
void getResult(int& num, int& den, char* result, int& len)
{
    //get characteristic number
    int charNum = num / den;
    //establish index
    int index = 0;
    
    //converts charactistic number into character
    convertIntToChar(charNum, index, result, len);
    
    //gets the mantissa
    int remain = num % den;
    
    if (remain != 0)
    {
        //inserts decimal into array, incremates by one
        result[index] = '.';
        index++;
        
        //while the remainder is NOT zero and the index is not at the edge
        while (remain != 0 && index < (len-1))
        {
            //get new characteristic number
            charNum = (remain * 10) / den;
            //get new remainder
            remain = (remain * 10) % den;
            //insert characteristic into array
            convertIntToChar(charNum, index, result, len);
        }
    }
    
    //Adds terminating character into array
    result[index] = '\0';
}
//--
void convertIntToChar(int& num, int& index, char* resultArr, int& len)
{
    //creates temporary array and establishes index
    char numChar[len];
    int numCharIndex = 0;
    
    //checks for negative numbers and/or if the number is 0
    if (num < 0)
    {
        resultArr[index] = '-';
        num *= -1;
        index++;
    }
    else if (num == 0)
    {
        resultArr[index] = '0';
        index++;
        return;
    }
    
    //as long as the number is not zero
    while (num > 0)
    {
        //inserts number into array
        numChar[numCharIndex] = '0' + (num % 10);
        //gets rid of digit inserted
        num /= 10;
        //incremates through array
        numCharIndex++;
    }
    
    // Length of array check
    for (int j = numCharIndex-1; j >= 0; j--)
    {
        resultArr[index] = numChar[j];
        index++;
    }
}
//--
void inverseFraction (int& num, int& den)
{
    //Creates holder value for num, then sets num and den equal to each other
    int num2 = num;
    num = den;
    den = num2;
}

bool arithmeticOperation (int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len, char symbol)
{
    //gets numerator of improper fractions
    int n1_improper = improperFraction(c1, n1, d1);
    int n2_improper = improperFraction(c2, n2, d2);
    
    //assumes false;
    bool retVal = false;
    
    if (symbol == '+' || symbol == '-')
    {
        //Establishes common denominator and matches the numerators
        int commonDen = 0;
        getCommonDenom(n1_improper, d1, n2_improper, d2, commonDen);
        
        //establishes variable for total of numerators
        int n3;
        
        //equation depending on operator
        if (symbol == '+')
        {
            n3 = n1_improper + n2_improper;
        }
        else
        {
            n3 = n1_improper - n2_improper;
        }
        
        //get result and set retval as true
        getResult(n3, commonDen, result, len);
        retVal = true;
    }
    else if (symbol == '*' || symbol == '/')
    {
        //if division, inverse the function
        if (symbol == '/')
        {
            inverseFraction(n2_improper, d2);
        }
        
        //math for total numerator and denominator
        int n3 = n1_improper * n2_improper;
        int d3 = d1 * d2;
        
        //get result and set retval as true
        getResult(n3, d3, result, len);
        retVal = true;
    }
    
    //returns the retval
    return retVal;
}
