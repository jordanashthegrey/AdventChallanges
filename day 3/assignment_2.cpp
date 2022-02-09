#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>

int removeOnes(std::vector<std::string> &bitList, int stringPosition)
{
    int i = 0;
    while (i < bitList.size())
    {
        if ((bitList[i][stringPosition]) == '1')
        {
            bitList.erase(bitList.begin() + i);
        }
        else {
            i++;
        }
    }

    return 0;
}

int removeZeros(std::vector<std::string> &bitList, int StringPosition)
{
    int i = 0;
    while (i < bitList.size())
    {
        if ((bitList[i][StringPosition]) == '0')
        {
            bitList.erase(bitList.begin() + i);
        }
        else {
            i++;
        }
    }

    return 0;
}



int checkBigger(int countOne, int countZero)
{

    if (countOne > countZero)
    {
        return true;
    }
    else if (countZero > countOne)
    {
        return false;
    }
    else if(countOne == countZero){
        return true;
    }
    return 0;
}

std::string calculateOxygen(std::vector<std::string> oxygen){

    int countOne = 0;
    int countZero = 0;

    for (int j = 0; j < 12; j++)
    {
        int i = 0;
        if (oxygen.size() == 1){
            break;
        }
        
        while (i < oxygen.size())
        {
            if (oxygen.at(i)[j] == '1')
            {
                countOne += 1;
                i++;
            }
            else
            {
                countZero += 1;
                i++;
            }
        }
        i = 0;
        if (checkBigger(countOne, countZero) == true)
        {
            removeZeros(oxygen, j);
        }
        else if (checkBigger(countOne, countZero) == false) {
            removeOnes(oxygen, j);
        }
        countOne = 0;
        countZero = 0;
    }

    return oxygen.at(0);

}


std::string calculateCO2(std::vector<std::string> CO2){

    int countOne = 0;
    int countZero = 0;

    for (int j = 0; j < 12; j++)
    {
        int i = 0;
        if (CO2.size() == 1){
            break;
        }
        
        while (i < CO2.size())
        {
            if (CO2.at(i)[j] == '1')
            {
                countOne += 1;
                i++;
            }
            else
            {
                countZero += 1;
                i++;
            }
        }
        i = 0;
        if (checkBigger(countOne, countZero) == true)
        {
            removeOnes(CO2, j);
        }
        else if (checkBigger(countOne, countZero) == false) {
            removeZeros(CO2, j);
        }
        countOne = 0;
        countZero = 0;
    }

    return CO2.at(0);


}
int main()
{
    std::ifstream inFS;
    inFS.open("input.txt");
    std::string bit;
    std::vector<std::string> bitList;
    std::vector<std::string> oxygenRating;
    std::vector<std::string> CO2Rating;
    int countZero = 0;
    int countOne = 0;
    int position = 0;
    bool found = false;

    while (!inFS.eof())
    {
        inFS >> bit;
        bitList.push_back(bit);
    }
    oxygenRating = bitList;
    CO2Rating = bitList;


    std::string oxygen = calculateOxygen(oxygenRating);
    std::string cO2 = calculateCO2(CO2Rating);
    std::cout << oxygen << std::endl;
    std::cout << cO2 << std::endl;
    


    return 0;
}