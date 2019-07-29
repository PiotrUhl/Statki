#pragma once
//#include <utility>
struct Point {
public:
	int x;
	int y;
	/*Point(const int _x, const int _y) : x(_x), y(_y) {}
	Point() = default;
	Point(const Point&) = default;
	//Point(const Point&&) = default;
	Point& operator=(const Point&) = default;
	//Point& operator=(const Point&&) = default;*/
	bool operator==(const Point& other) {
		if (x == other.x && y == other.y)
			return true;
		else
			return false;
	}
};