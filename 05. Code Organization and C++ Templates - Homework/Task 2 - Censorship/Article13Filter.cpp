#include "Article13Filter.h"

Article13Filter::Article13Filter(std::set<std::string> copyrighted):
	copyrighted(copyrighted)
{
}

bool Article13Filter::blockIfCopyrighted(std::string s)
{
	if (this->isCopyrighted(s))
	{
		this->blocked.push_back(s);
		return true;
	}
	return false;
}

bool Article13Filter::isCopyrighted(std::string s)
{
	for (auto& i : this->copyrighted)
	{
		if (s == i)
		{
			return true;
		}
	}
	return false;
}

std::vector<std::string> Article13Filter::getBlocked()
{
	return this->blocked;
}
