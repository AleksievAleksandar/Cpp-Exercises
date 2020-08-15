#ifndef RESOURCE_H
#define RESOURCE_H

#include "ResourceType.h"
#include <sstream>

namespace SoftUni
{
	class Resource
	{
	public:
		Resource() = default;

		ResourceType getType() const
		{
			return this->resourceType;
		}

		int getId() const
		{
			return this->id;
		}

		std::string getLink() const
		{
			return this->link;
		}

	private:
		int id;
		ResourceType resourceType;
		std::string link;
	
	public:
		friend std::istream& operator >> (std::istream &stream, Resource &resource)
		{
			stream >> resource.id;

			std::string type;
			stream >> type;
			if (type == "Demo")
			{
				resource.resourceType = ResourceType::DEMO;
			}
			else if (type == "Presentation")
			{
				resource.resourceType = ResourceType::PRESENTATION;
			}
			else
			{
				resource.resourceType = ResourceType::VIDEO;
			}

			stream >> resource.link;

			return stream;
		}
	};

	std::ostream& operator << (std::ostream& stream, const Resource& resource)
	{
		stream << resource.getId() << " ";
		stream << resource.getType() << " ";
		stream << resource.getLink();

		return stream;
	}

	bool operator < (const Resource& a, const Resource & b)
	{
		return a.getId() < b.getId();
	}
}

#endif // !RESOURCE_H 

