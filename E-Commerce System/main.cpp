#include "include/Cart.h"
#include "include/Customer.h"
#include "include/ProductTypes.h"
#include "include/ShippingService.h"
#include <bits/stdc++.h>
using namespace std ;
#define endl '\n'
#define debug(x) cerr << "\n" << (#x) << " is " << (x) << endl;
void FastI_O(){ ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr) ; }
// BEFORE coding are you sure you understood the statement correctly?
// PLEASE do not forget to read the sample explanation carefully.
// WATCH out for overflows & RTs in general.
// TEST your idea or code on the corner cases.
// ANALYZE each idea you have thoroughly.
// Sky is the limit ❤
// You don't have to be great to start… But you have to start to be GREAT ❤❤
// Hard Work Beat The Talent When The Talent Don't Work Hard❤
const int N = 2e5 + 1  ;


void checkout(Customer& customer, Cart& cart) {
    if (cart.isEmpty()) throw runtime_error("Cart is empty.");

    double subtotal = 0;
    double shippingFee = 0;
    bool hasShippable = false;

    vector<Shippable*> shippableItems;
    vector<int> shippableQuantities;

    cout << "** Checkout receipt **\n";
    for (const auto& item : cart.getItems()) {
        if (item.product->isExpired()) throw runtime_error(item.product->getName() + " is expired.");
        if (item.quantity > item.product->getQuantity())
            throw runtime_error(item.product->getName() + " out of stock.");

        double totalItemPrice = item.product->getPrice() * item.quantity;
        subtotal += totalItemPrice;
        item.product->reduceStock(item.quantity);

        cout << item.quantity << "x " << item.product->getName() << " " << totalItemPrice << "\n";

        if (item.product->isShippable()) {
            hasShippable = true;
            auto* s = dynamic_cast<Shippable*>(item.product.get());
            shippableItems.push_back(s);
            shippableQuantities.push_back(item.quantity);
        }
    }

    if (hasShippable) shippingFee = 30;
    double total = subtotal + shippingFee;
    customer.deduct(total);

    if (hasShippable)
        ShippingService::shipItems(shippableItems, shippableQuantities);

    cout << "----------------------\n";
    cout << "Subtotal " << subtotal << "\n";
    cout << "Shipping " << shippingFee << "\n";
    cout << "Amount " << total << "\n";
    cout << "Balance after payment: " << customer.balance << "\n";
}

int main() {
    time_t now = time(nullptr);
    time_t future = now + 60 * 60 * 24 * 10; // 10 days later

    auto cheese = make_shared<ExpirableShippableProduct>("Cheese", 100, 5, future, 0.2);
    auto biscuits = make_shared<ExpirableShippableProduct>("Biscuits", 150, 3, future, 0.7);
    auto tv = make_shared<NonExpirableShippableProduct>("TV", 300, 10, 5.0);
    auto scratchCard = make_shared<NonExpirableNonShippableProduct>("Scratch Card", 50, 20);

    Customer customer("Ali", 1000);
    Cart cart;

    try {
        cart.add(cheese, 2);
        cart.add(biscuits, 1);
        cart.add(scratchCard, 1);
        checkout(customer, cart);
    } catch (const exception& e) {
        // debug(e.what()) ;
        cerr << "Checkout failed: " << e.what() << endl;
    }

    return 0;
}
