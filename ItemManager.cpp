#include "ItemManager.h"
#include <string>


bool ItemManager::AddItem(std::unique_ptr<Item> newItem)
{
	_itemList.push_back(std::move(newItem));
	return true;
}

Item* ItemManager::GetItem(int id) const
{
	for (auto& item : _itemList)
	{
		if (item->GetItemID() == id)
		{
			return item.get();
		}
	}
	return nullptr;
}

const std::vector<std::unique_ptr<Item>>& ItemManager::GetAllItems() const
{
	return _itemList;
}