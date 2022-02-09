#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>

int checkBigger(int countOne, int countZero, std::vector<int> &gamma, std::vector<int> &epsilon)
{

    if (countOne > countZero)
    {
        gamma.push_back(1);
        epsilon.push_back(0);
    }
    else
    {
        gamma.push_back(0);
        epsilon.push_back(1);
    }

    return 0;
}

int main()
{
    std::ifstream inFS;
    inFS.open("input.txt");
    std::string bit;
    std::vector<std::string> bitList;
    std::vector<int> gamma;
    std::vector<int> epsilon;
    int countZero = 0;
    int countOne = 0;
    int counter = 0;

    while (!inFS.eof())
    {
        inFS >> bit;
        bitList.push_back(bit);
    }

    for (int j = 0; j < 12; j++)
    {
        for (int i = 0; i < bitList.size(); i++)
        {
            if (bitList.at(i)[j] == '1')
            {
                countOne += 1;
            }
            else
            {
                countZero += 1;
            }
            // std::cout << bitList.at(i)[0] << std::endl;
        }

        checkBigger(countOne, countZero, gamma, epsilon);
        countOne = 0;
        countZero = 0;
    }

    for (int i = 0; i < gamma.size(); i++)
    {
        std::cout << gamma.at(i);
    }
    std::cout << std::endl;

    for (int i = 0; i < epsilon.size(); i++)
    {
        std::cout << epsilon.at(i);
    }

    return 0;
}