#include <iostream>

using namespace std;

class ShippingCostStrategy {
public:
    virtual ~ShippingCostStrategy() = default;

    virtual double calculateCost(double weight) = 0;
};

class GroundShipping : public ShippingCostStrategy {
public:
    double calculateCost(double weight) override {
        return weight * 1.5;
    }

};

class AirShipping : public ShippingCostStrategy {
public:
    double calculateCost(double weight) override {
        return weight * 3.0;
    }

};

class WaterShipping : public ShippingCostStrategy {
public:
    double calculateCost(double weight) override {
        return weight * 2.2;
    }

};

class Order {
private:
    ShippingCostStrategy* stratergy;
    double weight;
public:
    Order (double weight, ShippingCostStrategy* stratergy):
        weight(weight), stratergy(stratergy){}

    void setShippingStratergy(ShippingCostStrategy* stratergy) {
        this->stratergy = stratergy;
    }

    double calculateShippingCost() {
        return stratergy->calculateCost(this->weight);
    }
};
int main()
{
    GroundShipping ground;
    AirShipping air;
    WaterShipping water;

    Order order(10.0, &ground);
    cout << order.calculateShippingCost() << endl;
    order.setShippingStratergy(&air);
    cout << order.calculateShippingCost() << endl;
    order.setShippingStratergy(&water);
    cout << order.calculateShippingCost() << endl;
}
