#include <iostream>

using namespace std;

class bigint
{
private:
    string number1 , number2 , resultNumber;
    char number1_sign = '+' , number2_sign = '-';
public:
    bigint()
    {
        number1 = ""; number2 = ""; resultNumber = "";
    }
    bigint( string num1 , string num2 )
    {
        while ( valid( num1 ) == false || valid( num2 ) == false )
        {
            cout << "Invalid numbers \n";
            cout << "Enter new numbers \n";
            cout << "Enter number 1 :  ";
            cin  >> num1;
            cout << "Enter number 2 :  ";
            cin  >> num2;
        }
        number1 = num1; number2 = num2;
        resultNumber = "";
    }
    void setN1( string num )
    {
        while ( !valid( num ) )
        {
            cout << "Invalid number \n";
            cout << "Enter new number \n";
            cout << "Enter number :  ";
            cin  >> num;
        }
        number1 = num;
    }
    void setN2( string num )
    {
        while ( !valid( num ) )
        {
            cout << "Invalid number \n";
            cout << "Enter new number \n";
            cout << "Enter number :  ";
            cin  >> num;
        }
        number2 = num;
    }
    string getNum1()
    {
        return number1;
    }
    string getNum2()
    {
        return number2;
    }
    string getRes()
    {
        return resultNumber;
    }
    bool valid ( string x )
    {
        for ( int i = 0; i < x.length(); i++ )
            if ( !( isdigit( x[i] ) == true || x[i] == '+' || x[i] == '-') ) return false;
        return true;
    }
    void detectSign()
    {
        if ( number1[0] == '-' ) number1_sign = '-';
        if ( number2[0] == '-' ) number2_sign = '-';

        if ( !isdigit( number1[0] ) ) number1.erase( 0,1 );
        if ( !isdigit( number2[0] ) ) number2.erase( 0,1 );
    }
    void leadingZeros()
    {
        if ( number1.length() > number2.length() )
        {
            int len = number1.length() - number2.length();
            for ( int i = 0; i < len; i++ )
                number2 = '0' + number2;
        }
        else if ( number2.length() > number1.length() )
        {
            int len = number2.length() - number1.length();
            for ( int i = 0; i < len; i++ )
                number1 = '0' + number1;
        }
    }
    void sumation()
    {
        int carry = 0;
        for ( int i = number1.length()-1; i > -1; i-- )
        {
            int sumChr = ( number1[i] - '0' ) + ( number2[i] - '0' ) + carry;

            char digit = char( sumChr%10 + '0' );
            resultNumber = digit + resultNumber;

            if ( sumChr > 9 ) carry = 1;
            else carry = 0;
        }
        if ( carry ) resultNumber = '1' + resultNumber;
    }
    void sub()
    {
        int carry = 0;
        for ( int i = number1.length()-1; i > -1; i-- )
        {
            if ( number1[ i ] - '0' >= number2[ i ] - '0' )
            {
                char digit = char( (number1[i] - '0') - ( number2[i] - '0' ) + carry );
                if ( i > 0 )
                    resultNumber = digit + resultNumber;
                carry = 0;
            }

            else
            {
                char digit = char( ( ( number1[ i ] - '0' + 10) - ( number2[ i ] - '0' ) + carry ) + '0' );
                if ( i > 0 )
                    resultNumber = digit + resultNumber;
                carry = -1;
            }
        }
    }


};

int main()
{
    bigint calc( "15" , "8" );
    calc.detectSign();
    calc.leadingZeros();

    cout << calc.getNum1() << " "  << calc.getNum2() << endl << endl;


    calc.sub();
    cout << calc.getRes();


    return 0;
}





