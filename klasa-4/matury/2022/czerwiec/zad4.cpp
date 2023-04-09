#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

bool is_prime_number(int n) {
    if (n < 2)
        return false;

    for (auto i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main()
{
    std::ifstream input("prod.txt");
    std::vector<std::string> numbers;

    while (input.is_open())
    {
        std::string line;
        while (std::getline(input, line))
        {
            numbers.push_back(line);
        }
        input.close();
    }

    std::vector<std::string> reversedNumbersDividedBy17;
    auto maxAbsNumber = 0;
    std::string maxAbsStr = "";
    std::vector<std::string> firstNumbers;
    std::vector<int> allNumbers;
    std::vector<int> repeatedTwiceNumber;
    std::vector<int> repeatedThreeTimesNumber;

    for (std::string line : numbers)
    {
            std::string copyLine = line;
            std::reverse(copyLine.begin(), copyLine.end());
            auto basicNumber = std::stoi(line);
            auto reversedNumber = std::stoi(copyLine);

            // 4.1
            if (std::stoi(copyLine) % 17 == 0)
            {
                reversedNumbersDividedBy17.push_back(copyLine);
            }
            
            // 4.2
            auto calcAbs = std::abs(basicNumber - reversedNumber);
            if (calcAbs > maxAbsNumber)
            {
                maxAbsStr = std::to_string(basicNumber);
                maxAbsNumber = calcAbs;
            }

            // 4.3
            auto a = 0;
            if (is_prime_number(basicNumber) && is_prime_number(reversedNumber))
            {
                firstNumbers.push_back(std::to_string(basicNumber));
            }

            // 4.4
            auto count = std::count(numbers.begin(), numbers.end(), line);
            auto found = std::find(allNumbers.begin(), allNumbers.end(), basicNumber) == allNumbers.end();
            if (found)
            {
                allNumbers.push_back(basicNumber);
            }

            switch (count)
            {
            case 2:
                found = std::find(repeatedTwiceNumber.begin(), repeatedTwiceNumber.end(), basicNumber) == repeatedTwiceNumber.end();
                if (found)
                    repeatedTwiceNumber.push_back(basicNumber);
                break;
            case 3:
                found = std::find(repeatedThreeTimesNumber.begin(), repeatedThreeTimesNumber.end(), basicNumber) == repeatedThreeTimesNumber.end();
                if (found)
                    repeatedThreeTimesNumber.push_back(basicNumber);
            default:
                break;
            }
    }

    // 4.1
    std::cout << "4.1 ";
    for (std::string number : reversedNumbersDividedBy17)
    {
        std::cout << number << ", ";
    }
    std::cout << std::endl;

    // 4.2
    std::cout << "4.2 " << maxAbsStr << " " << maxAbsNumber << std::endl;

    // 4.3
    std::cout << "4.3 ";
    for (std::string number : firstNumbers)
    {
        std::cout << number << ", ";
    }
    std::cout << std::endl;

    // 4.4
    auto count = allNumbers.size();
    std::cout << "4.4 " << count << " " << repeatedTwiceNumber.size() << " " << repeatedThreeTimesNumber.size() << std::endl;
}