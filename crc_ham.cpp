#include<bits/stdc++.h>
using namespace std;

void crc()
{
    int size_div;
    cout<<"Enter size of divisor\n";
    cin>>size_div;
    cout<<"Enter the divisor\n";

    int div[size_div];
    for(int i=0;i<size_div;i++)
        cin>>div[i];
    
    int size_ex = size_div - 1;

    int size_inp, arr[size_inp+size_ex];
    cout<<"Enter size of input\n";
    cin>>size_inp;
    cout<<"Enter the divisor\n";
    
    for(int i=0;i<size_inp;i++)
        cin>>arr[i];

    for(int i=size_inp;i<size_inp+size_ex;i++)
        arr[i] = 0;

    int rem[size_div];

    int start = 0 , end = size_div,flag=0; 

    while(end<=size_inp+size_ex)
    {
        
        if(arr[start] == 0)
        {

            if(end == size_inp+size_ex)
                flag=1;
            start++;
            end++; 
        }
        else
        {
            int i=start, j=end;
            int pos = 0;
            while(i<j)
            {
                arr[i] = arr[i] ^ div[pos];
                rem[pos] = arr[i];
                pos++;
                i++;

            }
            start++;
            end++;
        }
    }

    if(flag)
    {
        for(int i=2;i<size_div;i++)
            cout<<rem[i];
        cout<<0;
    }
    else
    {
        for(int i=1;i<size_div;i++)
        cout<<rem[i];
    }
    

}

void hammingcode()
{

    map<int,vector<int>> mp;

    mp[0]=vector<int>{1,3,5,7,9,11};
    mp[1]=vector<int>{2,3,6,7,10,11};
    mp[2]=vector<int>{4,5,6,7,12};
    mp[3]=vector<int>{8,9,10,11,12};


    string s;
    cout<<"Enter the string\n";
    cin>>s;

    reverse(s.begin(), s.end());

    int m = s.length();
    int r=0;

    for (int i=0;i<20;i++)
    {
        if(m+1+i < pow(2,i))
        {
            r=i;
            break;
        }    
    }


    int arr[m+r+1];
    int x=0;
    for(int i=0;i<m+r+1;i++)
    {
        for(int j=0;j<r;j++)
        {
            if(i==pow(2,j))
            {
                arr[i] = -1;
                break;
            }
        }
    }

    for(int i=1;i<m+r+1;i++)
    {
        if(arr[i]!=-1 && s[x]=='1')
        {
            arr[i]=1;
            x++;
        }    
        else if(arr[i]!=-1 && s[x]=='0')
        {
            arr[i]=0;
            x++;
        }
    }

    
    vector<int> v;
    int rbit[r];
    for(int i=0;i<r;i++)
    {
        v = mp[i];
        int sum = arr[v[1]];
        for(int j=2;j<v.size();j++)
        {
            sum=sum ^ arr[v[j]];
        }
        rbit[i]=sum;
    }

    int c=0;
    for(int i=1;i<m+r+1;i++)
    {
        if(arr[i] == -1)
        {
            arr[i]=rbit[c];
            c++;
        }
    }

    for(int i=1;i<m+r+1;i++)
        cout<<arr[i];
}

int main()
{
    // crc();
    hammingcode();
}