#include <iostream>
#include <stack>
#include <queue>
#include <string>


bool isBalanced(const std::string& s)
{
	std::stack<char> openBrackets;

	// not Balanced if expr start with open Bracket or all Brackets ate not even number
	if (s[0] == '}' || s[0] == ']' || s[0] == ')' || (s.size() % 2 != 0))
	{
		return false;
	}

	for (size_t i = 0; i < s.size(); i++)
	{
		// push into stack if curr bracket is open
		if (s[i] == '{' || s[i] == '[' || s[i] == '(')
		{
			openBrackets.push(s[i]);
		}
		else
		{
			char currBracket = s[i];
			// mutate curr closed braket to close bracket
			switch (currBracket)
			{
			case '}':
				currBracket = '{';
				break;

			case ']':
				currBracket = '[';
				break;

			case ')':
				currBracket = '(';
				break;

			default:
				break;
			}

			if (!openBrackets.empty() && currBracket == openBrackets.top())
			{
				openBrackets.pop();
			}
			else
			{
				return false;
			}
		}
	}
	return openBrackets.empty();
}

int main()
{
	std::string s;
	std::cin >> s;

	if (isBalanced(s))
	{
		std::cout << "YES";
	}
	else
	{
		std::cout << "NO";
	}

	return 0;
}
