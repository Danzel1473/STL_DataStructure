#include <iostream>
#include <string>
#include <map>
#include <Windows.h>

struct Item
{
	std::string name;
	unsigned int kind = 0;
	int price = 0;
	int code = 0;
};

std::ostream& operator<<(std::ostream& os, const Item& item)
{
	return os << "이름: " << item.name << ", 가격: " << item.price << ", 코드: " << item.code;
}

int main()
{
	std::map<std::string, Item, std::greater<std::string>> items;

	items.insert({ "장검", { "장검", 1, 200, 0 } });
	items.insert({ "해머", { "해머", 1, 1000, 4 } });
	items.insert({ "방패", { "방패", 2, 500, 3 } });

	if (!items.empty())
	{
		std::cout << "저장된 아이템 수: " << items.size() << "\n";
	}

	for (auto& pair : items)
	{
		std::cout << pair.second << "\n";
	}

	auto it = items.find("해머");

	if (it != items.end())
	{
		std::cout << "해머 아이템이 있습니다. 해머의 가격은 " << it->second.price << "입니다.\n";
	}

	if (it != items.end())
	{
		items.erase(it);

		std::cout << "해머 아이템 삭제 후 출력\n";
		for (auto& pair : items)
		{
			std::cout << pair.second << "\n";
		}
	}

	std::cin.get();
}