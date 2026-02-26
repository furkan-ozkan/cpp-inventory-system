#pragma once
#include <memory>
#include <vector>
#include "Item.h"

class ItemManager
{
public:
	bool AddItem(std::unique_ptr<Item> newItem);
	Item* GetItem(int id) const;
	const std::vector<std::unique_ptr<Item>>& GetAllItems() const;
private:
	std::vector<std::unique_ptr<Item>> _itemList;
};

