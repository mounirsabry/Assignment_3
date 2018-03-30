#include <iostream>
using namespace std;

int temp=0;
string word="";
bool check1=true;
const int sizee = 9 ;
int used_array[9];
int array1[9];
int array2[9];

void print_arr0(int arr[],int sizee)  // For Printing array
{
    for(int i=0;i<sizee;i++)
    {
        if(arr[i]!=0)
        {
        cout<<arr[i];
        cout<<" ";
        }
    }
    cout<<endl;
}

void print_arr(int arr[],int sizee)  // For Printing array
{
    for(int i=0;i<sizee;i++)
    {
        cout<<arr[i];
        cout<<" ";
    }
    cout<<endl;
}

void check(int arr[9],int used_array[9],int n,int u)
{
    while(true)
    {
        check1=true;
        cin>>temp;
        if(temp>9 || temp<1)
        {
            cout<<"The Number Must be between 1 and 9 :";
            continue;
        }
        for(int i=0;i<9;i++)
        {
            if(temp==used_array[i])
            {
                check1=false;
                break;
            }
        }
        if(check1==true)
        {
            used_array[u]=temp;
            arr[n]=temp;
            break;
        }
        else
        {
            cout<<"Choose A non used number :";
            continue;
        }
    }
}

bool checkwin(int arr[],int n)
{
    for(int a=0;a<n;a++)
    {
        for(int b=0;b<n;b++)
        {
            for(int c=0;c<n;c++)
            {
                if(a==b)
                {
                    b++;
                }
                if(b==c)
                {
                    c++;
                }
                if(arr[a]==0 || arr[b]==0 || arr[c]==0)
                {
                    break;
                }
                if(arr[a]==arr[b] || arr[a]==arr[c] || arr[b]==arr[c])
                {
                    break;
                }
                if(arr[a]+arr[b]+arr[c]==15)
                {
                    cout<<arr[a]<<" + "<<arr[b]<<" + "<<arr[c]<<"=15"<<endl;
                    return true;
                }
            }
        }
    }
    return false;
}

string Game()
{
    int used_array[9]={0};
    int array1[9]={0};
    int array2[9]={0};
    int n1=0;
    int n2=0;
    
    for(int i=0;i<9;)
    {
        // Player 1 Turn .
        if(i!=0)
        {
            cout<<"The Used Numbers Are "; // Print The Used Numbers For The User .
            print_arr0(used_array,sizee);
            cout<<"Your Choosen Numbers Are "; // Print The Numbers That Player 1 Have .
            print_arr0(array1,sizee);
        }
        cout<<"Player 1 Choose A number :";
        check(array1,used_array,n1,i);
        n1++;
        i++;
        cout<<endl; // Leave An Empty line between each player (additional) .
        if(i>4)
        {
            if(checkwin(array1,n1)==true)
            {
                return "Player 1 Is The Winner";
            }
        }
        if(i==9)
        {
            break;
        }
        // Player 2 Turn
        cout<<"The Used Numbers Are "; // Print The Used Numbers For The User .
        print_arr0(used_array,sizee);
        if(i!=1)
        {
            cout<<"Your Choosen Numbers Are "; // Print The Numbers That Player 2 Have .
            print_arr0(array2,sizee);
        }
        cout<<"Player 2 Choose A Number :";
        check(array2,used_array,n2,i);
        n2++;
        i++;
        cout<<endl; // Leave An Empty line between each player (additional) .
        if(i>4)
        {
            if(checkwin(array2,n2)==true)
            {
                return "Player 2 Is The Winner";
            }
        }
    }
    return "Draw";
}

int main()
{
    cout<<Game()<<endl;
    while(true)
    {
        cout<<"PLay Again,(yes or no)? ";
        cin>>word;
        if(word=="yes" || word=="Yes" || word=="YES")
        {
        cout<<Game()<<endl;
        }
        else if(word=="no" || word=="NO" || word=="No")
        {
            break;
        }
        else
        {
            cout<<"Please Enter A Clear Order"<<endl;
            continue;
        }
    }
    cout<<"Thank You For Trying The Game"<<endl;
	return 0;
}
