#ifndef COMPANY_H
#define COMPANY_H

#include <sstream>
#include <vector>

class HasId
{
public:
	HasId() = default;
	virtual int getId() const = 0;
};

class HasInfo : public HasId
{
public:
	HasInfo() = default;
	virtual std::string getInfo() const = 0;
};

class Company : public HasInfo
{
private:
	int id;
	std::string name;
	std::vector<std::pair<char, char> > employees;

public:
	Company();
	Company(int id, std::string name, std::vector<std::pair<char, char> > employees);

	int getId() const override;
	std::string getName() const;
	std::vector<std::pair<char, char> > getEmployees() const;
	std::string getInfo() const;
	friend std::ostream& operator<<(std::ostream& stream, const Company& c);
	friend std::istream& operator>>(std::istream& stream, Company& c);
};


#endif // !COMPANY_H