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