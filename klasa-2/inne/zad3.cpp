#include <iostream>

int main()
{
    int userinput; 
    int sum = 0;

    std::cout << "Podaj liczbe naturalna" << std::endl;
    std::cin >> userinput;

    if( userinput <= 0)
    {
        std::cout << "0" << std::endl;
        return 0;
    }
   
    for (int i = 1; i < userinput + 1; i++)
    {
        sum = sum + i;
    }

    std::cout << sum << std::endl;

    return 0;
}