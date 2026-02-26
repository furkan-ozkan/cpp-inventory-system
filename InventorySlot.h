#include "Item.h"
#include <memory>
#pragma once

class InventorySlot
{
public:
	InventorySlot() = default;
	virtual ~InventorySlot();

	bool SetItem(int itemID);
	int GetHoldedItem();

	bool IsEmpty();
	void ClearSlot();


private:
	int _holdingItemID = -1;
};

