// 练习：三维坐标类的运算符重载
// 目标：通过 Position 演示 +、[] 和 = 的自定义行为。
// 思路：operator+ 按坐标分量相加并返回新对象；operator[] 按下标读取分量，
//       下标不在 0～2 时打印提示并返回 -1。
// 实现状态：operator= 仍是空实现，既未复制成员，也未返回 Position&；
//           当前赋值示例不能作为正确实现，执行到该函数末尾会产生未定义行为。

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