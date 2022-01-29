#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main()
{
    std::vector<int> numbers;
    int posHor = 0;
    int posDepth = 0;
    int value;
    int aim = 0;
    std::string command;
    std::ifstream inFS;

    inFS.open("input.txt");

    if (!inFS.is_open())
    {
        std::cout << "Could not open file numFile.txt." << std::endl;
        return 1;
    }

    while (!inFS.eof())
    {
        inFS >> command;
        inFS >> value;

        if (command == "forward")
        {
            posHor += value;
            posDepth += (aim * value);
        }

        else if (command == "down")
        {
            // posDepth += value;
            aim += value;
        }

        if (command == "up")
        {
            // posDepth -= value;
            aim -= value;
        }
    }

    // std::cout << "The horizontal position is: " << posHor << std::endl;
    // std::cout << "The depth is: " << posDepth << std::endl;

    std::cout << "The answer is: " << posDepth * posHor <<std::endl;

    return 0;
}
