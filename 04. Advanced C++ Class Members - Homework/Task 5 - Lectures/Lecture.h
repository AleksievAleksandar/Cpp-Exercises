#ifndef LECTURE_H
#define LECTURE_H

#include <vector>
#include <map>
#include "Resource.h"

namespace SoftUni
{
	class Lecture
	{
	public:
		Lecture() = default;
		friend Lecture operator << (Lecture& lecture, const Resource& resource);
		friend std::vector<ResourceType> operator << (std::vector<ResourceType>& resType, const Lecture& lecture);

		int operator [] (ResourceType& resType)
		{
			std::map<ResourceType, int>::iterator itr;
			switch (resType)
			{
			case ResourceType::DEMO:
				itr = this->resourceTypes.find(resType);
				break;
			case ResourceType::PRESENTATION:
				itr = this->resourceTypes.find(resType);
				break;
			case ResourceType::VIDEO:
				itr = this->resourceTypes.find(resType);
				break;
			default:
				break;
			}

			return itr->second;
		}

		std::vector<Resource>::iterator begin()
		{
			this->getResources();
			return this->resources.begin();
		}

		std::vector<Resource>::iterator end()
		{
			return this->resources.end();
		}

	private:
		std::vector<Resource> resources;
		std::map<int, Resource> resourcesRaw;
		std::map<ResourceType, int> resourceTypes;

	private:
		void getResources()
		{
			for (auto& i : this->resourcesRaw)
			{
				this->resources.push_back(i.second);
				this->resourceTypes[i.second.getType()]++;
			}
		}
	};

	Lecture operator << (Lecture &lecture, const Resource &resource)
	{
		lecture.resourcesRaw[resource.getId()] = resource;

		return lecture;
	}

	std::vector<ResourceType> operator << (std::vector<ResourceType>& resType, const Lecture& lecture)
	{
		for (auto& i : lecture.resourceTypes)
		{
			resType.push_back(i.first);
		}
		return resType;
	}
}

#endif // !RESOURCE_H 
