#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++)
    {
        int val;
        cin>>val;
        arr[i] = val;
    }

    int count = 0,max = 0;

    for(int i =0 ; i<n; i++)
    {
        if(arr[i] == 1)
        {
            count++;
            if(count>max)
                max = count;
        }

        else if(arr[i] == 0)
            count = 0;
    }

    cout<<max<<"  number of ones\n";

}

