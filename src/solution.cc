#include "solution.hpp"

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <limits>

std::vector<Item> LoadShoppingItemsFromFile(const std::string& filename) {
  std::ifstream ifs(filename);
  if (!ifs.is_open()) {
    throw std::runtime_error("Unable to open the file.");
  }

  std::vector<Item> shopping_items;
  while (ifs.good()) {
    std::string item_name;
    int quantity = 0;
    double price = 0.0;
    bool flagged = true;

    ifs >> item_name;
    if (ifs.fail()) {
      ifs.clear();
      ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      flagged = false;
    }

    ifs >> quantity;
    if (ifs.fail()) {
      ifs.clear();
      ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      flagged = false;
    }

    ifs >> price;
    if (ifs.fail()) {
      ifs.clear();
      ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      flagged = false;
    }

    Item to_append;
    to_append.item_name = item_name;
    to_append.price = price;
    to_append.quantity = quantity;

    if (flagged) {
      shopping_items.push_back(to_append);
    }

  }

  return shopping_items;
}