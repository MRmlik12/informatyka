#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <numeric>
#include <algorithm>

int main()
{
	std::vector<std::string> out;
	const char seperator = ' ';
	std::ifstream file("input.txt");
	int previousChange = 0;
	int topChange = 1;
	std::string previousCommand;
	std::string topCommand;

	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
		{
			std::string command = "";
			std::string argument = "";
			std::stringstream stream(line);
			std::getline(stream, command, ' ');
			std::getline(stream, argument, ' ');

			if (previousCommand != command) 
            {
				previousChange = 1;
			}

			if (previousCommand == command)
				previousChange++;

			if (previousChange > topChange) 
            {
				topChange = previousChange;
				topCommand = command;
			}

			previousCommand = command;

			if (command == "DOPISZ") 
            {
				out.push_back(argument);
			}
			else if (command == "ZMIEN") 
            {
				out.pop_back();
				out.push_back(argument);
			}
			else if (command == "USUN") 
            {
				out.pop_back();
			}
			else if (command == "PRZESUN") 
            {
				for (auto i = std::begin(out); i != std::end(out); i++) {
					auto a = i->c_str();
					if (a == argument) {
						char x = i->at(0);
						if (x != 'Z')
							x++;
						else
							x = 'A';

						i->replace(0, 1, std::string(1, x));

						break;
					}
				}
			}
		}
		file.close();

		std::cout << out.size() << std::endl;
		std::string str = std::accumulate(out.begin(), out.end(), std::string{});
		std::cout << str << std::endl;
		std::cout << topChange + 1 << std::endl;
		std::cout << topCommand << std::endl;

		std::sort(out.begin(), out.end(), std::greater<std::string>());
		int countChar = -1;
		for (auto i = out.begin(); i < out.end(); i++) 
        {
			if (i->c_str() != out[0])
				break;
			countChar++;
		}
		std::cout << out[0] << " " << countChar << std::endl;
	}
}
