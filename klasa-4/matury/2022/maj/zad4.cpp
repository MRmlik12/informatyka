#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

int main()
{
	std::ifstream file("przyklad.txt");
	std::string firstLine;
	std::vector<int> lines;

	// 1
	auto snCount = 0;
	auto currentRow = 0;

	// 2
	auto topNumber = 0;
	auto topFactorCount = 0;
	auto topDifferentFacotrsNumber = 0;
	auto topDiffrentFactorsCount = 0;

	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
		{
			auto number = std::stoi(line);
			lines.push_back(number);
#pragma region 1
			auto first = line[0];
			auto lenght = line.length();
			auto lastNumber = line[lenght - 1];

			if (currentRow == 0)
				firstLine = line;

			if (first == lastNumber)
				snCount++;

			int mNumber = 0;
			int multipliers = 0;
			for (auto i = 2; mNumber >= 420; i++)
			{
				mNumber *= i;
				multipliers++;
			}
#pragma endregion
#pragma region 2
			int divider = 2;
			auto cNumber = number;
			std::vector<int> factors;
			while (cNumber > 1)
			{
				while (cNumber % divider == 0)
				{
					factors.push_back(divider);
					cNumber /= divider;
				}
				divider++;
			}

			if (topFactorCount < factors.size())
			{
				topNumber = number;
				topFactorCount = factors.size();
			}

			std::sort(factors.begin(), factors.end());
			factors.erase(std::unique(factors.begin(), factors.end()), factors.end());

			if (topDiffrentFactorsCount < factors.size())
			{
				topDifferentFacotrsNumber = number;
				topDiffrentFactorsCount = factors.size();
			}
#pragma endregion

			currentRow++;
		}
	}
	file.close();

	std::cout << "4.1"
		<< " = " << snCount << " " << firstLine << std::endl;
	std::cout << "4.2" << "=" << " " << topNumber << " " 
		<< topFactorCount << " " << topDifferentFacotrsNumber << " " << topDiffrentFactorsCount << std::endl;

#pragma region 3
	auto lineLenght = lines.size();
	std::sort(lines.begin(), lines.end());
	std::ofstream answerA("trojki.txt");
	for (int x = 0; x < lineLenght; x++)
	{
		for (int y = x + 1; y < lineLenght; y++)
		{
			if (lines[y] % lines[x] != 0)
				continue;

			for (int z = y + 1; z < lineLenght; z++)
			{
				if (lines[z] % lines[y] != 0)
					continue;

				answerA << lines[x] << " " << lines[y] << " " << lines[z] << std::endl;

				for (int a = z + 1; a < lineLenght; a++)
				{
					if (lines[a] % lines[z] != 0)
						continue;

					for (int b = a + 1; b < lineLenght; b++) {
						if (lines[b] % lines[a] != 0)
							continue;

						std::cout << "4.3 b)" << " " << lines[x] << " " << lines[y] << " " 
							<< lines[z] << " " << lines[a] << " " << lines[b] << std::endl;
					}
				}
			}
		}
	}
	answerA.close();
#pragma endregion

	return 0;
}