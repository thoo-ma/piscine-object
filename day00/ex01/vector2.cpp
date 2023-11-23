#include <vector>
#include <iostream>

/// @todo bonus ??
/// @todo error handling ?

class Graph;

class Vector2 {

    float x;
    float y;

    Vector2(float x, float y): x(x), y(y) { }

    friend Graph;
};

class Graph {

    private:

    std::vector<Vector2> v;

    bool isPoint(float x, float y) {
        for (std::vector<Vector2>::iterator it = v.begin(); it != v.end(); it++)
            if (it->x == x && it->y == y)
                return true;
        return false;
    }

    public:

    void addPoint(float x, float y) {
        v.push_back(Vector2(x, y));
    }

    void draw() {

        float x_max = 0;
        for (std::vector<Vector2>::iterator it = v.begin(); it != v.end(); it++)
            if (it->x > x_max)
                x_max = it->x;

        float y_max = 0;
        for (std::vector<Vector2>::iterator it = v.begin(); it != v.end(); it++)
            if (it->y > y_max)
                y_max = it->y;

        for (int y = y_max; y >= 0; y--) {
            std::cout << y << " ";
            for (int x = 0; x <= x_max; x++)
                std::cout << (isPoint(x, y) ? "x " : ". ");
            std::cout << std::endl;
        }

        std::cout << "  ";
        for (int i = 0; i <= x_max; i++)
            std::cout << i << " ";
        std::cout << std::endl;

    }

};

int main() {
    Graph graph;
    graph.addPoint(0, 0);
    graph.addPoint(2, 2);
    graph.addPoint(1, 4);
    graph.addPoint(4, 5);
    graph.draw();
    return 0;
}