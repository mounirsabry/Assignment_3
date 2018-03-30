// FCI – Programming 1 – 2018 - Assignment 2
// Program Name: main.cpp
// Last Modification Date: 04/03/2018
// Author and ID and Group: 20170301 G11
// Teaching Assistant: Khadega
// Purpose: Calculating The Gross Pay.

#include <iostream>

using namespace std;

const float normal_pay = 16.78; // The Normal Pay for an hour.
const float over_pay = 25.17; // The Pay for an extra hour work.

void program(); // The Function that contains the pay calculator.
void check_positive(int &n); // Make Sure That the number is positive.

int main()
{
    string try_again; // To Ask The User if he wants to start the program again.
    program();
    while(true)
    {
        cout << "try again ?" << endl;
        cout << "Enter Yes OR NO : ";
        cin >> try_again;
        if(try_again == "YES" || try_again == "Yes" || try_again == "yes")
        {
            cout << endl;
            program();
            continue;
        }
        else if(try_again == "NO" || try_again == "No" || try_again == "no")
        {
            cout << endl;
            break;
        }
        else
        {
            cout << "Enter A Clear Order" << endl << endl;
        }
    }
    cout << "Thank You for Using The Program" << endl;
    return 0;
}

void program()
{
    int nHours = 0; // The Number of Hours.
    int num_over_time = 0; // The Number of over_time hours.
    int nDependents = 0; // The Number of dependents.
    float gross_pay = 0;

    cout << "Enter The Number of Hours :";
    check_positive(nHours);
    cout << "Enter The Number of dependents :";
    check_positive(nDependents);

    if(nHours > 40)
    {
        num_over_time = nHours - 40; // calculate the over_time.
    }
    gross_pay = nHours * normal_pay + num_over_time * over_pay; // Money from Working Hours.
    if(nDependents >= 3)
    {
        gross_pay = gross_pay - ( 0.7 * gross_pay ); // Dependents Taxes + Constant Taxes.
    }
    else
    {
        gross_pay = gross_pay - ( 0.35 * gross_pay ); // Constant Taxes only.
    }
    cout << "Your Gross Pay is :" << gross_pay << endl << endl;
}

void check_positive(int &n)
{
    while(true)
    {
        cin >> n;
        if(n < 0)
        {
            cout << "Enter A Positive Integer Number :";
        }
        else
        {
            break;
        }
    }
}
