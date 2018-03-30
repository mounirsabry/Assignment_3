// FCI – Programming 1 – 2018 - Assignment 2  
// Program Name:   Team_Task.cpp 
// Last Modification Date: 03/02/2018 
// Author1 and ID and Group: 20170301 G11 
// Author2 and ID and Group: 20170295 G11 
// Author3 and ID and Group: 20170294 G11 
// Teaching Assistant: khadega  
// Purpose: Help User With The broken digits on the keypad.

#include <iostream>

using namespace std;

int main()
{
    int number = 0 ; // The Number That the user enter.
    int num1 = 0 ; // The first digit ( From Right ) of The Number.
    int num2 = 0 ; // The Second digit ( From Right ) of The Number.
    int num3 = 0 ; // The Third digit ( From Right ) of The Number.
    int num11 = 0 ; // A copy from num1.
    int num22 = 0 ; // A copy from num2.
    int num33 = 0 ; // A copy from num3.
    
    cout << "enter The Number from 1 : 999 :" ;
    while ( true ) // Make Sure That The Number is between 1 and 999.
    {
        cin >> number ;
        if( number > 999 || number <= 0 )
        {
            cout << "Enter A Number between 1 and 999 :" ;
            continue ;
        }
        break ;
    }
    while ( number > 0 ) // exctract The Digits from the Number That the user enter.
    {
        num1 = number % 10 ;
        num11 = num1 ;
        number = number / 10 ;


        num2 = number % 10 ;
        num22 = num2 ;
        number = number / 10 ;

        num3 = number % 10 ;
        num33 = num3 ;
        number = number / 10 ;
    }
    if ( num1 == 1 || num1 == 4 || num1 == 7  || num2 ==1 || num2 == 4 || num2 == 7 || num3 ==1 || num3 == 4 || num3 == 7 ) 
    // The cases that the number digits has a problem.
    {
        if ( num11 == 1 || num11 == 4 || num11 == 7 )
        {
            num11 = num11 + 1 ;
        }
        if ( num22 == 1 || num22 == 4 || num22 == 7)
        {
            num22 = ( num22 * 10 ) + num11 + ( 10 - num11 ) ;
        }
        else
        {
            num22 = ( num22 * 10 ) + num11 ;
        }

        if ( num33 == 1 || num33 == 4 || num33 == 7 )
        {
            num33 = ( num33 * 100 ) + num22 + ( 100 - num22 ) ;
        }
        else
        {
            num33 = ( num33 * 100 ) + num22 ;
        }
        cout << "the max number is : "<< num33 << endl ;

        if ( num1 == 1 || num1 == 4 || num1 == 7 )
        {
            num1 = num1 - 1 ;
        }
        if ( num2 == 1 || num2 == 4 || num2 == 7 )
        {
            num2 = ( ( num2 * 10 ) + num1 ) - ( num1 + 1 ) ;
        }
        else
        {
            num2 = ( num2 * 10 ) + num1 ;
        }
        if ( num3 == 1 || num3 == 4 || num3 == 7 )
        {
            num3 = ( ( num3 * 100 ) + num2 ) - ( num2 + 1 ) ;
        }
        else
        {
            num3 = ( num3 * 100 ) + num2 ;
        }
        cout << "the min number is : " << num3 << endl ;
    }
    else // Print That The Number is Correct.
    {
        cout << num3 << num2 << num1 ;
    }
    return 0 ;
}
