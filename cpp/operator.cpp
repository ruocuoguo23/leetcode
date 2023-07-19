//
// Created by 吴洋 on 2023/7/17.
//
#include <iostream>

using namespace std;

class Position {
public:
    Position(): x(0), y(0), z(0) {}
    Position(int x, int y, int z): x(x), y(y), z(z) {}
    Position operator+(const Position& another) const {
        Position result{this->x + another.x, this->y + another.y, this->z + another.z};
        return result;
    }

//    void operator=(const Position& another) = delete;
    Position& operator=(const Position& another) {

    }

    int operator[](int index) {
//        if (index<0 || index>2) {
//            return -1;
//        }

        if (index == 0) {
            return x;
        }

        if (index == 1) {
            return y;
        }

        if (index == 2) {
            return z;
        }

        cout << "invalid index at " << index << endl;
        return -1;
    }

private:
    int x;
    int y;
    int z;
};

int main() {
    Position a{1, 1, 1};
    Position b{2, 2, 2};
    // if we do not define +, this operation is invalid
    Position c = a + b;

    Position d{3, 4, 5};
    cout << "d[1] = " << d[1] << endl;

    Position e;
    e = c;
    cout << "e[1] = " << e[1] << endl;
}