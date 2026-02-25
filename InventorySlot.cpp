#include "InventorySlot.h"

InventorySlot::~InventorySlot() {}

bool InventorySlot::SetItem(Item item)
{

}

Item InventorySlot::GetHoldedItem()
{

}

bool InventorySlot::IsEmpty()
{
	return _holdedItem == nullptr;
}