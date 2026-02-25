#pragma once
#include <string>

class Item
{
public:
	Item(std::string itemName, int currentAmount = 1, int maxStackAmount = 1);
	virtual ~Item() {}

	bool IncreaseAmount() {}
	bool DecreaseAmount() {}

	const std::string& GetItemName() const {}
	int GetCurrentAmount() const {}
	int GetMaxStackAmount() const {}

	bool IsEmpty() const {}

private:
	std::string _itemName;
	int _itemMaxStackAmount;
	int _itemCurrentAmount;
};