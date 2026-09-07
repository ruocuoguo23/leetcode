// 练习：函数模板与自定义比较运算
// 目标：让同一个 mmmax 模板比较浮点数和自定义 Size 对象。
// 思路：模板通过 a < b 选择较大对象，并返回其 const 引用；Size 为此提供
//       operator<，传入 const 引用时会调用带 const 限定的成员重载。
// 要点：返回值引用原参数，使用时需要保证被引用对象仍然存活。

//
// Created by 吴洋 on 2023/7/18.
//
#include <iostream>
#include <string>

using namespace std;

template <typename T>
const T& mmmax(const T& a, const T& b) {
    return a < b ? b : a;
}

class Size {
public:
    explicit Size(int s): size(s) {}

    bool operator<(Size& right) {
        cout << "operator < called." << endl;
        return this->size < right.size;
    }

    bool operator<(const Size& right) const {
        //
        cout << "const operator < called." << endl;
        return this->size < right.size;
    }

    int get_size() {
        return size;
    }
private:
    int size;
};

int main() {
    double a1 = 2222.2;
    double b1 = 3333.3;
    cout << "max: " << mmmax(a1, b1) << endl;

    Size a2(10);
    Size b2(11);
    Size c2 = mmmax(a2, b2);
    cout << c2.get_size() << endl;
}