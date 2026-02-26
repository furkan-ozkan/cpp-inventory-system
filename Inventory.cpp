#include "Inventory.h"
#include "InventorySlot.h"

Inventory::Inventory(int _inventorySize)
{
	_inventorySlots.reserve(_inventorySize);
	for (uint16_t i = 0; i < _inventorySize; i++)
	{
		_inventorySlots.emplace_back(std::make_unique<InventorySlot>());
	}
}
Inventory::~Inventory() {}

bool Inventory::AddItemToFirstEmptyInventorySlot(int _itemID)
{
	int _addSlotIndex;
	for (auto& inventorySlot: _inventorySlots)
	{
		if (inventorySlot->IsEmpty())
		{
			inventorySlot->SetItem(_itemID);
			return true;
		}
	}
	return false;
}
bool Inventory::AddItemTo(int _itemID, int _inventorySlotIndex)
{
	if (_inventorySlotIndex < 0 ||
		_inventorySlotIndex >= _inventorySlots.size())
		return false;
	if (_inventorySlots[_inventorySlotIndex]->GetHoldedItem() != EMPTY_SLOT_ID)
		return false;
	_inventorySlots[_inventorySlotIndex]->SetItem(_itemID);
	return true;
}
int Inventory::GetItemFrom(int _inventorySlotIndex) const
{
	if (_inventorySlotIndex < 0 ||
		_inventorySlotIndex >= _inventorySlots.size())
		return EMPTY_SLOT_ID;

	return _inventorySlots[_inventorySlotIndex]->GetHoldedItem();
}
std::vector<int> Inventory::GetAllItemsInInventory() const
{
	std::vector<int> m_TempItemList;
	for (auto& itemSlot: _inventorySlots)
	{
		if (!itemSlot->IsEmpty())
		{
			m_TempItemList.emplace_back(itemSlot->GetHoldedItem());
		}
	}
	return m_TempItemList;
}
void Inventory::ClearInventory()
{
	for (auto& itemSlot : _inventorySlots)
	{
		itemSlot->ClearSlot();
	}
}
bool Inventory::ClearInventorySlotWithIndex(int _inventorySlotIndex)
{
	if (_inventorySlotIndex < 0 ||
		_inventorySlotIndex >= _inventorySlots.size())
		return false;

	_inventorySlots[_inventorySlotIndex]->ClearSlot();
	return true;
}