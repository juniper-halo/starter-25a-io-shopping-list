#include "solution.hpp"

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

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
    char throw_away = '\0';

    ifs >> item_name >> throw_away;
    if (ifs.fail()) {
      throw std::invalid_argument("invalid value received.");
    }

    ifs >> quantity >> throw_away;
    if (ifs.fail()) {
      throw std::invalid_argument("invalid value received.");
    }

    ifs >> price >> throw_away;
    if (ifs.fail()) {
      throw std::invalid_argument("invalid value received.");
    }

    Item to_append;
    to_append.item_name = item_name;
    to_append.price = price;
    to_append.quantity = quantity;

    shopping_items.push_back(to_append);

  }

  if (shopping_items.empty()) {
    throw std::invalid_argument("Empty file received.");
  }

  return shopping_items;
}