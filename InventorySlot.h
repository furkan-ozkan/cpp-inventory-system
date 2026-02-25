#include "Item.h"
#include <memory>
#pragma once

class InventorySlot
{
public:
	InventorySlot();
	virtual ~InventorySlot() {}

	bool SetItem(Item item) {}
	Item GetHoldedItem() {}

	bool IsEmpty() {}


private:
	std::unique_ptr<Item> _holdedItem;
};

