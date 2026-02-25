#pragma once
#include <vector>
#include <memory>
#include "Item.h"

class Inventory
{
public:
private:
	std::vector<std::unique_ptr<Item>> _inventorySlots;
};