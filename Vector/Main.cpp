#include <iostream>
#include <vector>
#include "Main.h"

int main()
{
	std::vector<int> v;

	IsEmpty(v);

	for (int i = 0; i < 1000; ++i)
	{
		v.emplace_back(i + 1);
	}

	for (auto it = v.begin(); it != v.end();)
	{
		it = v.erase(it);
		if (it != v.end())
		{
			++it;
		}
	}

	//for (int i = 0; i < 100; ++i)
	//{

	//	auto iterator = v.begin() + i;
	//	
	//	
	//	v.erase(iterator);
	//}

	// ���� ���� ������ �����͸� ���� delete ����� ��
	v.clear();

	IsEmpty(v);

	v.shrink_to_fit();

	std::cin.get();
}

void IsEmpty(std::vector<int>& v)
{
	if (v.empty())
	{
		std::cout << "vector�� �����\n";
	}
}
