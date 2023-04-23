
#include <iostream>
#include "PGM.hpp"
#include "PGM.cpp"
using namespace std;
void bresenham(int x1, int y1, int x2, int y2, PGM &img);

int main() {
    setlocale(LC_ALL, "Portuguese");

    PGM img;
    if (img.ler("feep.pgm")) {
        bresenham(0, 0, img.getLargura() - 1, img.getAltura() - 1, img);
        img.gravar("feep_bresenham.pgm");
    }
    return 0;
}

void bresenham(int x1, int y1, int x2, int y2, PGM &img) {
    setlocale(LC_ALL, "Portuguese");
    int dx = std::abs(x2 - x1);
    int dy = std::abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (x1 != x2 || y1 != y2) {
        img.setPixel(x1, y1, 0);
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
    img.setPixel(x1, y1, 0);

    cout << "Fim da execução do bresenham!" << endl;
}
