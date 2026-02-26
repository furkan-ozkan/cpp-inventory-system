#include "InventorySlot.h"

InventorySlot::~InventorySlot() {}

bool InventorySlot::SetItem(int itemID)
{
	if (_holdingItemID == -1)
	{
		_holdingItemID = itemID;
		return true;
	}
	return false;
}

int InventorySlot::GetHoldedItem()
{
	return _holdingItemID;
}

bool InventorySlot::IsEmpty()
{
	return _holdingItemID == -1;
}

void InventorySlot::ClearSlot()
{
	_holdingItemID = -1;
}