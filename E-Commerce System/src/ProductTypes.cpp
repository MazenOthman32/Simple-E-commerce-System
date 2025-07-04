#include "../include/ProductTypes.h"
#include <ctime>

ExpirableShippableProduct::ExpirableShippableProduct(std::string name, double price, int quantity, time_t expiryDate, double weight)
    : Product(name, price, quantity), expiryDate(expiryDate), weight(weight) {}

bool ExpirableShippableProduct::isExpired() const { return time(nullptr) > expiryDate; }
bool ExpirableShippableProduct::isShippable() const { return true; }
double ExpirableShippableProduct::getWeight() const { return weight; }
std::string ExpirableShippableProduct::getName() const { return name; }

ExpirableNonShippableProduct::ExpirableNonShippableProduct(std::string name, double price, int quantity, time_t expiryDate)
    : Product(name, price, quantity), expiryDate(expiryDate) {}

bool ExpirableNonShippableProduct::isExpired() const { return time(nullptr) > expiryDate; }
bool ExpirableNonShippableProduct::isShippable() const { return false; }

NonExpirableShippableProduct::NonExpirableShippableProduct(std::string name, double price, int quantity, double weight)
    : Product(name, price, quantity), weight(weight) {}

bool NonExpirableShippableProduct::isExpired() const { return false; }
bool NonExpirableShippableProduct::isShippable() const { return true; }
double NonExpirableShippableProduct::getWeight() const { return weight; }
std::string NonExpirableShippableProduct::getName() const { return name; }

NonExpirableNonShippableProduct::NonExpirableNonShippableProduct(std::string name, double price, int quantity)
    : Product(name, price, quantity) {}

bool NonExpirableNonShippableProduct::isExpired() const { return false; }
bool NonExpirableNonShippableProduct::isShippable() const { return false; }