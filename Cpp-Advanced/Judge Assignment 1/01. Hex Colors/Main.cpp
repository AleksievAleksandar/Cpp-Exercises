#include <iostream>
#include <sstream>
#include <string>

const size_t RGBsize = 3;
const size_t twoCharsOsStr = 2;

void calculateRGBfromHEXtoINT(int RGB[3], const std::string& hexColor)
{
	size_t arrCnt = 0;
	size_t indx = 1;

	while (indx < hexColor.size())
	{
		std::string twoDigits = hexColor.substr(indx, twoCharsOsStr);
		indx += 2;

		std::stringstream iss;
		iss << std::hex << twoDigits;

		int number;
		iss >> number;

		RGB[arrCnt] = static_cast<int>(number);
		arrCnt++;
	}
}

std::string computeAvaregeCollor(const std::string& firstCol, const std::string& secondCol)
{
	int RGBfirst[3];
	int RGBsecond[3];

	calculateRGBfromHEXtoINT(RGBfirst, firstCol);
	calculateRGBfromHEXtoINT(RGBsecond, secondCol);

	std::stringstream ss;
	ss << "#";

	for (size_t i = 0; i < RGBsize; i++)
	{
		int number = (RGBfirst[i] + RGBsecond[i]) / 2;	
		ss << std::hex << number;

		if (number == 0)
		{
			ss << "0";
		}
	}

	return ss.str();
}

int main()
{
	std::string firstCol;
	std::string secondCol;

	std::cin >> firstCol >> secondCol;

	std::cout << computeAvaregeCollor(firstCol, secondCol);

	return 0;
}
