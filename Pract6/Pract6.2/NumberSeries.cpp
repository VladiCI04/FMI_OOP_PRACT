#include "NumberSeries.h"

// �����������
NumberSeries::NumberSeries() = default;
NumberSeries::NumberSeries(int startValue, std::function<int(int)> func) : currentValue(startValue), transitionFunction(func) {}

// ����� �� ���������� � ������� �� ���������� �������� � ��������
int NumberSeries::next() {
    currentValue = transitionFunction(currentValue);
    return this->currentValue;
}

// ����� �� ������� �� �������� �������� � ��������
int NumberSeries::getCurrentValue() const {
    return this->currentValue;
}
void NumberSeries::setCurrentValue(const int currentValue) {
    this->currentValue = currentValue;
}