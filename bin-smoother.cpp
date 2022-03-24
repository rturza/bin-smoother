#include<bits/stdc++.h>
#include <stdio.h>
#include<string.h>
using namespace std;

int main()

{
    char str[1000];
    cout<<"Enter the input as string : ";
    scanf("%s",str);
    int str_length = strlen(str);


    int array[str_length] = { 0 };

    int k = 0, i, sum = 0;


    for (i = 0; str[i] != '\0'; i++)
    {


        if (str[i] == ',')
        {
            k++;
            continue;
        }

        else
        {


            array[k] = array[k] * 10 + (str[i] - 48);
        }
    }

///Array sorting:
    int swap;


    for (int c = 0 ; c < k; c++)
    {
        for (int d = 0 ; d < k - c ; d++)
        {
            if (array[d] > array[d+1])
            {
                swap       = array[d];
                array[d]   = array[d+1];
                array[d+1] = swap;
            }
        }
    }

    cout<<"Enter the bin size: ";
    int bin_size;
    cin>> bin_size;
    int p=1,d;
    int arr[bin_size];
    cout << "Select your example choice: \n";
    cout << "1. Smoothing by means \n" << "2. Smoothing by boundary \n";
    cout << "Your choice [1/2]: ";
    cin>>d;

    ///Smooting by means:
    if(d==1)
    {
        for(int i=0; i<=k; i=i+bin_size)
        {
            int sum=0;
            for (int j=0; j<bin_size; j++)
                sum=sum+array[i+j];


            cout<< "Bin "<< p++ << ": ";
            for(int j=0; j<bin_size; j++)
            {

                cout<< sum/bin_size ;
                if (j!=bin_size-1)
                {
                    cout<< ", ";
                }
            }

            cout<< endl;
        }
    }
    ///Smoothing By Boundary:
    if(d==2)
    {

        for(int i=0; i<=k; i=i+bin_size)
        {

            for(int j=0; j<bin_size; j++)
                if (array[i+j]-array[i] < array[i+bin_size-1]-array[i+j])
                    arr[j]=array[i];
                else
                    arr[j]=array[i+bin_size-1]    ;

            cout<< "Bin "<< p++ << ": ";
            for(int j=0; j<bin_size; j++)
            {
                cout<< arr[j];
                if (j!=bin_size-1)
                {
                    cout<< ", ";
                }

            }
            cout << endl;
        }
    }
}

