#include <iostream>

struct Point {
    double x;
    double y;
};

void readPoint(Point& p) {
    std::cin >> p.x >> p.y;
}

void printPoint(const Point& p) {
    std::cout << '(' << p.x << "; " << p.y << ')' << std::endl;
}

double findDistanceFromCenter(const Point& p) {
    double sum = p.x + p.y;
    double distance = sqrt(sum);

    return sum;
}

int main()
{
    Point* p1 = new Point();
    Point* p2 = new Point();

    readPoint(*p1);
    readPoint(*p2);

    printPoint(*p1);
    printPoint(*p2);

    std::cout << findDistanceFromCenter(*p1) << std::endl;
    std::cout << findDistanceFromCenter(*p2) << std::endl;


}