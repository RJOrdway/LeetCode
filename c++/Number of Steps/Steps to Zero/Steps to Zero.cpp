// Steps to Zero.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
int numberOfSteps(int);

int main()
{
    std::cout << numberOfSteps(14);
}

int numberOfSteps(int num)
{
    int count = 0;
    while (num > 0)
    {
        if (num % 2 == 0)
            num = num / 2;
        else
            num -= 1;
        count++;
    }
    return count;
}