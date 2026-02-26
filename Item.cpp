#include "Item.h"
#include <string>

	Item::Item(int itemID, std::string itemName, int currentAmount, int maxStackAmount) :
		_itemID(itemID),
		_itemName(itemName),
		_itemCurrentAmount(currentAmount),
		_itemMaxStackAmount(maxStackAmount)
	{
	}

	Item:: ~Item()
	{

	}

	bool Item::IncreaseAmount() {
		if (_itemCurrentAmount >= _itemMaxStackAmount) return false;
		_itemCurrentAmount++;
		return true;
	}

	bool Item::DecreaseAmount() {
		if (_itemCurrentAmount <= 0) return false;
		_itemCurrentAmount--;
		return true;
	}

	const std::string& Item::GetItemName() const
	{
		return _itemName;
	}

	int Item::GetCurrentAmount() const
	{
		return _itemCurrentAmount;
	}

	int Item::GetMaxStackAmount() const
	{
		return _itemMaxStackAmount;
	}

	int Item::GetItemID() const
	{
		return _itemID;
	}

	bool Item::IsEmpty() const
	{
		return _itemCurrentAmount <= 0;
	}