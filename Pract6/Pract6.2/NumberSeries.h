#pragma once

#include <iostream>
#include <functional> // �� std::function

class NumberSeries {
private:
    int currentValue;
    std::function<int(int)> transitionFunction; // �������� ��� ������� �� ������

public:
    // �����������
    NumberSeries();
    NumberSeries(int startValue, std::function<int(int)> func);

    // ����� �� ���������� � ������� �� ���������� �������� � ��������
    int next();

    // ����� �� ������� �� �������� �������� � ��������
    int getCurrentValue() const;
    void setCurrentValue(const int currentValue);
};