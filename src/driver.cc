#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "solution.hpp"

int main() {
  try {
    std::string test_input_file = "./test-input/test-listWithSpaces.txt";
    std::vector<Item> shopping_items =
        LoadShoppingItemsFromFile(test_input_file);

    std::cout << "Printing shopping items...\n";
    for (const Item& item : shopping_items) {
      std::cout << "\t" << item.item_name << " " << item.quantity << " "
                << item.price << "\n";
    }
    std::cout << "Printing complete!\n";

  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}