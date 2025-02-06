#include <iostream>.
#include <deque>

int main()
{
	std::deque<int> deque;

	deque.emplace_back(100);
	deque.emplace_front(200);

	for (auto& value : deque)
	{
		std::cout << value << "\n";
	}

	std::cout << "\n";

	for (auto iterator = deque.begin(); iterator != deque.end(); ++iterator)
	{
		std::cout << *iterator << "\n";
	}

	std::cout << "\n";

	auto data = deque.back();

	deque.pop_back();

	std::cout << data << "\n";
	std::cout << "\n";

	deque.clear();
	if (deque.empty())
	{
		std::cout << "deque is empty\n";
	}

	std::cin.get();
}