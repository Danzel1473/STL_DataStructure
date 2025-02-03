#include <iostream>
#include <list>

using namespace std;

struct Point
{
	Point(string name, int x = 0, int y = 0)
		:name(name), x(x), y(y)
	{
	}

	string name = "";
	int x;
	int y;
};

ostream& operator<<(ostream& os, const Point& point)
{
	return os << point.name << " (" << point.x << ", " << point.y << ")";
}

int main()
{
	list<Point> diagram;

	diagram.emplace_back("A", 50, 200);
	diagram.emplace_back("B", 20, 80);
	diagram.emplace_back("C", 75, 10);
	diagram.emplace_back("D", 130, 80);
	diagram.emplace_back("E", 100, 200);

	for (auto& point : diagram)
	{
		cout << point << "\n";
	}

	diagram.emplace_back("F", 180, 150);

}