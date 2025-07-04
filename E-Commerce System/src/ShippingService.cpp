#include "../include/ShippingService.h"
#include <iomanip>
#include <iostream>

void ShippingService::shipItems(const std::vector<Shippable*>& items, const std::vector<int>& quantities) {
    std::cout << "** Shipment notice **\n";
    double totalWeight = 0.0;
    for (size_t i = 0; i < items.size(); ++i) {
        std::cout << quantities[i] << "x " << items[i]->getName()
                  << " " << std::fixed << std::setprecision(0) << items[i]->getWeight() * 1000 << "g\n";
        totalWeight += items[i]->getWeight() * quantities[i];
    }
    std::cout << "Total package weight " << totalWeight << "kg\n";
}