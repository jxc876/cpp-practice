#include <ostream>

// aggregate type
struct Point {
    int x;
    int y;
};

void print(Point p) {
    //std::cout << p.x << ", " << p.y << std::endl;
    printf("{ x: %d, y:%d }\n", p.x, p.y);
}

int main() {
    Point p = {};
    p.x = 10;
    p.y = 20;
    print(p);
}