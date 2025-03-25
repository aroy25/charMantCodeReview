#include <iostream>
using namespace std;

//required function prototypes
bool characteristic(const char numString[], int& c);
bool mantissa(const char numString[], int& numerator, int& denominator);

bool add(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len);
bool subtract(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len);

bool multiply(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len);
bool divide(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len);

int improperFraction(int& charNum, int& num, int& den);
void commonDenom(int& n1, int& d1, int& n2, int& d2, int& commonDen);
void getResult(int& num, int& den, char* result, int& len);
void convertIntToChar(int& num, int& index, char* resultArr, int& len);
void inverseFraction (int& num, int& den);

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
    c1 = 23;
    n1 = 3;
    d1 = 5;

    c2 = 2;
    n2 = 7;
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
//--
bool characteristic(const char numString[], int& c)
{
    //hard coded return value to make the main() work
    c = 123;
    return true;
}
//--
bool mantissa(const char numString[], int& numerator, int& denominator)
{
    //hard coded return value to make the main() work
    numerator = 456;
    denominator = 1000;
    return true;
}
//--
bool add(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
    return arithmeticOperation(c1, n1, d1, c2, n2, d2, result, len, '+');
}
//--
bool subtract(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
    return arithmeticOperation(c1, n1, d1, c2, n2, d2, result, len, '-');
}
//--
bool multiply(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
    return arithmeticOperation(c1, n1, d1, c2, n2, d2, result, len, '*');
}
//--
bool divide(int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len)
{
    return arithmeticOperation(c1, n1, d1, c2, n2, d2, result, len, '/');
}
//--
int improperFraction(int& charNum, int& num, int& den)
{
    return num = (charNum * den) + num;
}
//--
void commonDenom(int& n1, int& d1, int& n2, int& d2, int& commonDen)
{
    commonDen = d1 * d2;
    
    n1 *= d2;
    n2 *= d1;
    
    d1 = d2 = commonDen;
}
//--
void getResult(int& num, int& den, char* result, int& len)
{
    int charNum = num / den;
    int index = 0;
    
    convertIntToChar(charNum, index, result, len);
    
    result[index] = '.';
    index++;
    
    int remain = num % den;
    //int remainCopy = remain;
    
    if (remain != 0)
    {
        //Check math here
        while (remain != 0 && index < (len-1))
        {
            charNum = (remain * 10) / den;
            remain = (remain * 10) % den;
            convertIntToChar(charNum, index, result, len);
        }
    }
    
    result[index] = '\0';
}
//--
void convertIntToChar(int& num, int& index, char* resultArr, int& len)
{
    char numChar[len];
    int numCharIndex = 0;
    
    if (num == 0)
    {
        resultArr[index] = '0';
        index++;
        return;
    }
    else if (num < 0)
    {
        resultArr[index] = '-';
        num *= -1;
        index++;
    }
    
    while (num > 0)
    {
        numChar[numCharIndex] = '0' + (num % 10);
        num /= 10;
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
    int num2 = num;
    num = den;
    den = num2;
}

bool arithmeticOperation (int c1, int n1, int d1, int c2, int n2, int d2, char result[], int len, char symbol)
{
    int n1_improper = improperFraction(c1, n1, d1);
    int n2_improper = improperFraction(c2, n2, d2);
    
    bool retVal = false;
    
    if (symbol == '+')
    {
        int commonDen = 0;
        commonDenom(n1_improper, d1, n2_improper, d2, commonDen);
        
        int n3 = n1_improper + n2_improper;
        getResult(n3, commonDen, result, len);
        
        retVal = true;
    }
    else if (symbol == '-')
    {
        int commonDen = 0;
        commonDenom(n1_improper, d1, n2_improper, d2, commonDen);
        
        int n3 = n1_improper - n2_improper;
        getResult(n3, commonDen, result, len);
        
        retVal = true;
    }
    else if (symbol == '*')
    {
        int n3 = n1_improper * n2_improper;
        int d3 = d1 * d2;
        
        getResult(n3, d3, result, len);
        
        retVal = true;
    }
    else if (symbol == '/')
    {
        inverseFraction(n2_improper, d2);
        
        int n3 = n1_improper * n2_improper;
        int d3 = d1 * d2;
        
        getResult(n3, d3, result, len);
        
        retVal = true;
    }
    else
    {
        retVal = false;
    }
    
    return retVal;
}
