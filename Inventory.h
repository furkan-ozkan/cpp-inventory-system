#pragma once
#include <vector>
#include <memory>
#include "InventorySlot.h"

const int EMPTY_SLOT_ID = -1;

class Inventory
{
public:
	Inventory(int _inventorySize = 10);
	virtual ~Inventory();

	bool AddItemToFirstEmptyInventorySlot(int _itemID);
	bool AddItemTo(int _itemID, int _inventorySlotIndex);
	int GetItemFrom(int _inventorySlotIndex) const;
	std::vector<int> GetAllItemsInInventory() const;
	void ClearInventory();
	bool ClearInventorySlotWithIndex(int _inventorySlotIndex);


private:
	std::vector<std::unique_ptr<InventorySlot>> _inventorySlots;
};