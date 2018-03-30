// FCI – Programming 1 – 2018 - Assignment 2
// Program Name: cipher_task.cpp
// Last Modification Date: 04/03/2018
// Author and ID and Group: 20170301 G11
// Teaching Assistant: Khadega.
// Purpose: encrypt message Using the Caesar cipher.

#include <iostream>

using namespace std;

const int alpha_size=26; // The Size of the English Alphabet.
const int small_min=97; // The ASCII Number of The First Small Character.
const int small_max=122; // The ASCII Number of The Last Small Character.
const int capital_min=65; // The ASCII Number of The First Capital Character.
const int capital_max=90; // The ASCII Number of The Last Capital Character.

char open_app(); // presenting the welcome message and ask user to choose between cipher and decipher.
void cipher_function(); // to encrypt the message.
void decipher_function();// to crack the message.
bool check_input(string message); // to make sure that the user enter a message consists of characters only.
bool check_number(int number); // to make sure that the user enter a positive integer number of shifts.
char shift_letter(char letter,int n); // shift a letter a right direction.
char check_over(char letter); // to return the character to the start of alphabet when he gets outside of the range.
char de_shift_letter(char letter,int n); // shift a letter a left direction.
char de_check_over(char letter); // to return the character to the start of alphabet when he gets outside of the range.
void print_message(char new_message[],int sizee); // print the final message.

int main()
{
    string try_again; // to ask the user the user if he wants to do anything else.
    if(open_app() == '3')
    {
        return 0;
    }
    while(true)
    {
        cout << "Do You Want to do anything else ?" << endl;
        cout << "Enter Yes or No :";
        cin >> try_again;
        if(try_again == "Yes" || try_again == "yes" || try_again == "YES")
        {
            cout << endl;
            if(open_app() == '3')
            {
                break;
            }
        }
        else if(try_again == "No" || try_again == "no" || try_again == "NO")
        {
            break;
        }
        else // to prevent the user from entering a non valid number.
        {
            cout << "Enter A Clear Order " << endl;
        }
    }
    cout << endl << "Thank You For Using This Program" << endl;
    return 0;
}

char open_app()
{
    char choose;
    cout << "\tHello User" << endl;
    cout << "What do you want to do today ?" << endl << endl;
    while(true)
    {
        cout << "to Cipher A message Enter 1" << endl;
        cout << "to DeCipher A message Enter 2" << endl;
        cout << "to end the program enter 3" << endl << endl;
        cout << "Your Answer ? ";
        cin >> choose;
        if(choose == '1')
        {
            cipher_function();
            return '1';
        }
        else if(choose == '2' )
        {
            decipher_function();
            return '2';
        }
        else if(choose == '3' )
        {

            return '3';
        }
        else
        {
            cout << "Enter A Valid Number " << endl;
            continue ;
        }

    }
}

void cipher_function()
{
    int num_of_shifts=0;    // Store The number of shifts the user want.
    string message; // The input message.
    char temp; // store the char from message temporary while encrypted it.
    // Welcome Message.
    cout << endl <<"\tWelcome , This Program uses Caesar Cipher To encrypt messages " << endl << endl;
    // Input Message.
    cout << "Please Enter The Message :";
    while(true) // Check The Validity Of The Number.
    {
        cin >> message;
        if(check_input(message)==false)
        {
            cout << "Enter A message consists of character only :";
            continue;
        }
        cout << endl;
        break;
    }
    // Input Number Of Shifts.
    cout << "Please Enter The Number Of Shifts :";
    while(true) // Check The Validity OF The Number.
    {
        cin >> num_of_shifts;
        if(check_number(num_of_shifts)==false)
        {
            cout << "Enter A Non Negative Number :";
            continue;
        }
        break;
    }
    while(num_of_shifts > 26)
    {
        num_of_shifts = num_of_shifts - 26;
    }
    // Array for The New Message.
    char new_message[message.size()];
    // Shifting Letters.
    for(int i=0;i<message.size();i++)
    {
        temp=shift_letter(message[i],num_of_shifts);
        temp=check_over(temp);
        new_message[i]=temp;
    }
    cout << "The Encrypted Message is :";
    print_message(new_message,message.size());
    cout << endl;


    cout << endl << endl;
}

void decipher_function()
{
    int num_of_shifts=0;    // Store The number of shifts the user want.
    string message; // The input message.
    char temp; // store the char from message temporary while decipher it.
    // Welcome Message.
    cout << endl << "\tWelcome , This Program uses Caesar Cipher To Decipher messages " << endl << endl;
    // Input Message.
    cout << "Please Enter The Message :";
    while(true) // Check The Validity Of The Number.
    {
        cin >> message;
        if(check_input(message)==false)
        {
            cout << "Enter A message consists of character only :";
            continue;
        }
        cout << endl;
        break;
    }
    // Input Number Of Shifts.
    cout << "Please Enter The Number Of Shifts :";
    while(true) // Check The Validity OF The Number.
    {
        cin >> num_of_shifts;
        if(check_number(num_of_shifts)==false)
        {
            cout << "Enter A Non Negative Number :";
            continue;
        }
        break;
    }
    while(num_of_shifts > 26)
    {
        num_of_shifts = num_of_shifts - 26;
    }
    // Array for The New Message.
    char new_message[message.size()];
    // Shifting Letters.
    for(int i=0;i<message.size();i++)
    {
        temp=de_shift_letter(message[i],num_of_shifts);
        temp=de_check_over(temp);
        new_message[i]=temp;
    }
    cout << "The Original Message is :";
    print_message(new_message,message.size());
    cout << endl;


    cout << endl << endl;
}

bool check_input(string message)
{
    for(int i=0;i<message.size();i++)
        {
            if(!(int(message[i])>=capital_min && int(message[i])<=capital_max) && !(int(message[i])>=small_min && int(message[i])<=small_max))
            {
                return false;
            }
        }
        return true;
}

bool check_number(int number)
{
    if(number<0)
    {
        return false;
    }

    return true;
}

char shift_letter(char letter,int n)   // Shifting Letter.
{
    if(int(letter)>=small_min && int(letter)<=small_max)
    {
        letter=(int(letter))+n;
    }
    else if(int(letter)>=capital_min && int(letter)<=capital_max)
    {
        letter=(int(letter))+n;
    }
    return letter;
}

char check_over(char letter) // Make Sure That the Letter after shifting is still readable
{
    if(int(letter)>small_max)
    {
        letter=(int(letter))-alpha_size;
    }
    else if(int(letter)>capital_max && int(letter)<small_min)
    {
        letter=(int(letter))-alpha_size;
    }
    return letter;
}

char de_shift_letter(char letter,int n)   // Shifting Letter.
{
    if(int(letter)>=small_min && int(letter)<=small_max)
    {
        letter=(int(letter))-n;
    }
    else if(int(letter)>=capital_min && int(letter)<=capital_max)
    {
        letter=(int(letter))-n;
    }
    return letter;
}

char de_check_over(char letter) // Make Sure That the Letter after shifting is still readable
{
    if(int(letter)<small_min && int(letter)>capital_max)
    {
        letter=(int(letter))+alpha_size;
    }
    else if(int(letter)<small_min)
    {
        letter=(int(letter))+alpha_size;
    }
    return letter;
}

void print_message(char text[],int sizee)
{
    for(int i=0;i<sizee;i++)
    {
        cout << text[i] ;
    }
}
