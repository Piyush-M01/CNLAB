#include<bits/stdc++.h>
using namespace std;

void checksum()
{
    int size, ele[size];
    cout<<"Enter the size"<<"\n";
    cin>>size;
    cout<<"Enter the elements"<<"\n";
    
    for(int i=0;i<size;i++)
        cin>>ele[i];
    
    int sum = 0;

    for(int i=0;i<size;i++)
        sum=sum+ele[i];
    
    int check_sum = ~sum;

    if (check_sum == 0)
        cout<<"Error free ";
    else
        cout<<"error";
}

void bitstuffing()
{
    string s,s1="";
    
    cout<<"Enter the string"<<"\n";
    cin>>s;

    int count = 0;

    for(int i=0;i<s.length();i++)
    {    
        s1=s1+s[i];

        if(count == 5)
        {
            count = 0;
            i=i+1;
        }

        if(s[i]=='1')
            count++;
        else
            count = 0;
    }

    cout<<"Bit Unstuffed: "<<s1;

}

void charactercount()
{
    string s;
    
    cout<<"Enter the string"<<"\n";
    cin>>s;

    int num = s[0] - '0';

    cout<<"Num of characters to display: "<<num<<"\n";

    if(num<s.length() || num>s.length())
        cout<<"Incorrect TX";
    else
        cout<<s.substr(1,num);

}

int main()
{
    int choice;

    cout<<"Enter choice \n";
    cin>>choice;

    switch (choice)
    {
    case 1:
        checksum();
        break;
    
    case 2:
        bitstuffing();
        break;

    case 3:
        charactercount();
        break;

    default:
        break;
    }

}