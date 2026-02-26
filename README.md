# Basic C++ Inventory System

This is my first attempt at writing a project in C++. It is a simple, console-based inventory management system designed to practice core C++ concepts, memory management, and Object-Oriented Programming (OOP).

## Features
* **Item Database (`ItemManager`)**: Acts as a central repository holding all available in-game items.
* **Inventory Management**: Creates an inventory with a customizable number of slots.
* **Adding Items**: Supports adding items to the first available empty slot or a specific slot index.
* **Clearing Slots**: Allows clearing a specific slot or emptying the entire inventory at once.
* **Interactive Console Menu**: Includes a basic `while` loop menu to test adding, viewing, and clearing items dynamically.

## Concepts & Tools Used
* **C++ Standard Template Library (STL)**: Used `std::vector` to manage collections of items and slots.
* **Smart Pointers**: Utilized `std::unique_ptr` and `std::make_unique` to handle memory safely and avoid manual memory allocation/deallocation.
* **Modularity**: Separated class declarations and implementations into `.h` and `.cpp` files.

## What I Focused On
* **Const Correctness**: Used `const` and references (`const std::string&`, `const std::vector&`) to prevent unnecessary copying of data and to protect read-only variables.
* **ID-Based Tracking**: To keep the inventory lightweight, `InventorySlot` instances do not store actual `Item` objects. Instead, they store a simple integer `itemID`. 
* **State Management**: Used a constant `-1` value to cleanly represent an empty slot state.
