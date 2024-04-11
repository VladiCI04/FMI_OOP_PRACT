#include "NumberSeries.h"

// Конструктор
NumberSeries::NumberSeries() = default;
NumberSeries::NumberSeries(int startValue, std::function<int(int)> func) : currentValue(startValue), transitionFunction(func) {}

// Метод за генериране и връщане на следващата стойност в редицата
int NumberSeries::next() {
    currentValue = transitionFunction(currentValue);
    return this->currentValue;
}

// Метод за връщане на текущата стойност в редицата
int NumberSeries::getCurrentValue() const {
    return this->currentValue;
}
void NumberSeries::setCurrentValue(const int currentValue) {
    this->currentValue = currentValue;
}