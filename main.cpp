#include <iostream>
#include <string>
#include <vector>
#include "ItemManager.h"
#include "Inventory.h"
#include "Item.h"

using namespace std;

// Helper function to print the current inventory status
void PrintInventory(const Inventory& inv, const ItemManager& itemManager, int invSize)
{
    cout << "\n=== CURRENT INVENTORY STATUS ===" << endl;
    for (int i = 0; i < invSize; ++i)
    {
        int itemID = inv.GetItemFrom(i); // Get the item inside the slot
        if (itemID == EMPTY_SLOT_ID)
        {
            cout << "Slot [" << i << "] : EMPTY" << endl;
        }
        else
        {
            Item* item = itemManager.GetItem(itemID); // Get item details from ID
            if (item)
            {
                cout << "Slot [" << i << "] : " << item->GetItemName()
                    << " (ID: " << itemID << ")" << endl;
            }
        }
    }
    cout << "================================" << endl;
}

// Prints all available items in the game database
void PrintAllDatabaseItems(const ItemManager& itemManager)
{
    cout << "\n--- ALL ITEMS IN GAME (DATABASE) ---" << endl;
    const auto& items = itemManager.GetAllItems();
    for (const auto& item : items)
    {
        cout << "ID: " << item->GetItemID() << " | Name: " << item->GetItemName()
            << " | Max Stack: " << item->GetMaxStackAmount() << endl;
    }
    cout << "------------------------------------" << endl;
}

int main()
{
    cout << "Inventory system test starting..." << endl;

    // 1. Create ItemManager and define in-game items
    ItemManager itemManager;
    itemManager.AddItem(make_unique<Item>(1, "Iron Sword", 1, 1));
    itemManager.AddItem(make_unique<Item>(2, "Small Potion", 1, 10));
    itemManager.AddItem(make_unique<Item>(3, "Wooden Shield", 1, 1));
    itemManager.AddItem(make_unique<Item>(4, "Poison Arrow", 1, 99));

    // 2. Create a 5-slot inventory
    const int INVENTORY_SIZE = 5;
    Inventory myInventory(INVENTORY_SIZE);

    int choice = -1;
    while (choice != 0)
    {
        cout << "\n--- ACTION MENU ---" << endl;
        cout << "1. Show All Items in Database (ItemManager)" << endl;
        cout << "2. Show Inventory" << endl;
        cout << "3. Add Item to First Empty Slot (AddItemToFirstEmptyInventorySlot)" << endl;
        cout << "4. Add Item to Specific Slot (AddItemTo)" << endl;
        cout << "5. Clear Specific Slot (ClearInventorySlotWithIndex)" << endl;
        cout << "6. Clear Entire Inventory (ClearInventory)" << endl;
        cout << "0. Exit" << endl;
        cout << "Your Choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice)
        {
        case 1:
            PrintAllDatabaseItems(itemManager);
            break;
        case 2:
            PrintInventory(myInventory, itemManager, INVENTORY_SIZE);
            break;
        case 3:
        {
            int id;
            cout << "ID of the item to add: ";
            cin >> id;
            if (myInventory.AddItemToFirstEmptyInventorySlot(id))
                cout << "> SUCCESS: Item added to first empty slot!" << endl;
            else
                cout << "> ERR: Inventory is Full!" << endl;
            break;
        }
        case 4:
        {
            int id, slotIndex;
            cout << "Item ID: ";
            cin >> id;
            cout << "Which Slot (0-" << INVENTORY_SIZE - 1 << "): ";
            cin >> slotIndex;

            if (myInventory.AddItemTo(id, slotIndex))
                cout << "> SUCCESS: Item added to Slot " << slotIndex << "!" << endl;
            else
                cout << "> ERR: Slot is full or invalid slot number!" << endl;
            break;
        }
        case 5:
        {
            int slotIndex;
            cout << "Slot Number to clear (0-" << INVENTORY_SIZE - 1 << "): ";
            cin >> slotIndex;
            if (myInventory.ClearInventorySlotWithIndex(slotIndex))
                cout << "> SUCCESS: Slot " << slotIndex << " cleared!" << endl;
            else
                cout << "> ERR: Invalid slot number!" << endl;
            break;
        }
        case 6:
            myInventory.ClearInventory();
            cout << "> SUCCESS: Entire inventory cleared!" << endl;
            break;
        case 0:
            cout << "Exiting system. See you!" << endl;
            break;
        default:
            cout << "> ERR: You made an invalid choice." << endl;
            break;
        }
    }

    return 0;
}