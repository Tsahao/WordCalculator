//
//  main.cpp
//  WordCalculator
//
//  Created by Tsahao Yu on 9/12/18.
//  Copyright © 2018 Tsahao Yu. All rights reserved.
//
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#define SIZE 256




bool isCharacter(char str)
{
    return ((str >= 'A' && str <= 'z') || (str >='0' && str <= '9'));
}

void countBasic(fstream &outfile, int *cnt)//Basic count mathod
{
    char str[SIZE];
    while(outfile.getline(str,SIZE))
    {
        int tmp = 0;
        
        for(int i=0; i < strlen(str);i++)
        {
            if(str[i] == ' ' || str[i] == '.' || str[i] == ',' || str[i] == '?' || str[i] == '!')
                cnt[1]++;//count the number of words
            
            if(isCharacter(str[i]))
            {
                cnt[0]++;
                tmp++;
            }//count the number of characters

        }
        
    if(tmp != 0) cnt[2]++;//count the numbers of lines
        tmp=0;
    }
    return;
}

int main()
{
    char filename[SIZE];
    int cnt[3]={0};
    
    cout<<"Please input your file path:"<<endl;
    cin.getline(filename,SIZE);
    
    fstream outfile(filename,ios::in);
    countBasic(outfile, cnt);
    
    cout<<"Total number of characters is: "<<cnt[0]<<endl;
    cout<<"Total number of words is: "<<cnt[1]<<endl;
    cout<<"Total number of lines is: "<<cnt[2]<<endl;
    
    outfile.close();
    return 0;
    
}
