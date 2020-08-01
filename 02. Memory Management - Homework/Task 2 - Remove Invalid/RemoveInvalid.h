#pragma once

#include <list>

void removeInvalid(std::list<Company*>& companies)
{
	std::list<Company*>::iterator i = companies.begin();

	while (i != companies.end()) {
		Company* c = *i;
		if (c->getId() < 0) {
			delete c;
			i = companies.erase(i);
			//companies.erase(i);
			//i = companies.begin();
		}
		else {
			i++;
		}
	}
}