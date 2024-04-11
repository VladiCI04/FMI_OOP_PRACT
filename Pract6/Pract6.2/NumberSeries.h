#pragma once

#include <iostream>
#include <functional> // За std::function

class NumberSeries {
private:
    int currentValue;
    std::function<int(int)> transitionFunction; // Указател към функция на преход

public:
    // Конструктор
    NumberSeries();
    NumberSeries(int startValue, std::function<int(int)> func);

    // Метод за генериране и връщане на следващата стойност в редицата
    int next();

    // Метод за връщане на текущата стойност в редицата
    int getCurrentValue() const;
    void setCurrentValue(const int currentValue);
};