#ifndef SHAPE_H
#define SHAPE_H


#include "Vector2D.h"
#include <iomanip>

class Shape
{
public:
	Shape():
		vector2D(Vector2D(0.0, 0.0)), area(0)
	{}

	Shape(const Vector2D& vector2D):
		vector2D(vector2D), area(0)
	{}

	//std::string getCenter()
	//{
	//	return this->vector2D.operator std::string();
	//}
	Vector2D getCenter()
	{
		return this->vector2D;
	}

	double getArea()
	{
		return this->area;
	}

public:
	double area;
	Vector2D vector2D;
};

#endif // !SHAPE_H