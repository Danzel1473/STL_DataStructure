#include <iostream>
#include <list>
#include <algorithm>

struct Item
{
	Item(int code = 0, int price = 0)
		:code(code), price(price)
	{
	}
	int code;
	int price;
};

std::ostream& operator<<(std::ostream& os, const Item& item)
{
	return os << "코드: " << item.code << ", 가격: " << item.price;
}

struct ItemLessComparer
{
	bool operator()(const Item& left, const Item& right)
	{
		return left.code < right.code;
	}
};

int main()
{
	std::list<Item> itemList;

	itemList.emplace_front(Item(1, 200));
	itemList.emplace_front(Item(2, 1000));

	itemList.emplace_back(Item(3, 3000));
	itemList.emplace_back(Item(4, 4500));

	for (auto iterator = itemList.begin(); iterator != itemList.end(); ++iterator)
	{
		std::cout << *iterator << "\n";
	}

	itemList.pop_front();

	Item& frontItem = itemList.front();
	
	std::cout << frontItem << "\n";

	itemList.emplace_back(Item(5, 4000));
	itemList.emplace_back(Item(6, 5000));
	itemList.emplace_back(Item(7, 9900));
	itemList.emplace_back(Item(8, 11100));

	std::cout << "\n";

	ItemLessComparer lessComparer;
	itemList.sort(lessComparer);

	for (auto item : itemList)
	{
		std::cout << item << "\n";
	}


	std::cout << "\n";

	itemList.sort([](const Item& left, const Item& right)
	{
		return left.code > right.code;
	}
	);

	for (auto item : itemList)
	{
		std::cout << item << "\n";
	}
}