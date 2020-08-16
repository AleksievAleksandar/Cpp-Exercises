#ifndef JOIN_H
#define JOIN_H

#include <sstream>
#include <vector>

template<typename T>
std::string join(const std::vector<T> &numbers, const std::string &joinStr)
{
	std::ostringstream oss;
	
	for (size_t i = 0; i < numbers.size() - 1; i++)
	{
		oss << numbers[i];
		oss << joinStr;
	}
	oss << numbers[numbers.size() - 1];
	
	return oss.str();

	//std::ostringstream os;
	//for (int i = 0; i < numbers.size(); i++) {
	//	os << numbers[i];
	//	if (i < numbers.size() - 1) {
	//		os << joinStr;
	//	}
	//}
	//return os.str();
}

#endif // !JOIN_H

