#ifndef SHIPPING_SERVICE_H
#define SHIPPING_SERVICE_H

#include "Product.h"
#include <string>
#include <vector>

class ShippingService {
public:
    static void shipItems(const std::vector<Shippable*>& items, const std::vector<int>& quantities);
};

#endif