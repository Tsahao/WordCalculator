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

bool isCharacter(char str)
{
    if((str >= 'A' && str <= 'z') || (str >='0' && str <= '9'))
        return true;
    else
        return false;
}

void countBasic(fstream &outfile, int *cnt)
{
    char str[256];
    while(outfile.getline(str,256))
    {
        int tmp = 0;
        
        for(int i=0; i < strlen(str);i++)
        {
            if(str[i] == ' ' || str[i] == '.' || str[i] == ',' || str[i] == '?' || str[i] == '!')
                cnt[1]++;
            
            if(isCharacter(str[i]))
            {
                cnt[0]++;
                tmp++;
            }

        }
        
    if(tmp != 0)
        cnt[2]++;
        tmp=0;
    }
    return;
}

