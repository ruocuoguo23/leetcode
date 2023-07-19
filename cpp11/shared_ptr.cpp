//
// Created by wuyang on 2023/1/23.
//
#include <memory>
#include <iostream>

using namespace std;

class FileObject {

};

int main() {
    // auto ptr problem

    // unique_ptr
    unique_ptr<int> up1(new int(1000));
    cout << *up1 << endl;

    // recommend way
    unique_ptr<int> up2 = make_unique<int>(1001);

    // 赋值和移动都被禁止
//    unique_ptr<int> sp3 = sp2;
//    unique_ptr<int> sp4(sp2);

    unique_ptr<int> up5 = std::move(up2);
    if (up2) {
        cout << "up2 is valid." << endl;
    }

    cout << *up5 << endl;

    // 自定义deleter
    // 针对特殊类型的资源，释放的时候除了调用默认的释放内存函数delete or delete[]，还需要特殊的操作，例如套接字句柄或者文件句柄。
    // 此时可以自定义对象的析构函数

    shared_ptr<int> sp1 = make_shared<int>(100);
    cout << "sp1 use count is " << sp1.use_count() << endl; // 1

    shared_ptr<int> sp2 = sp1;
    // increase use count
    cout << "sp1 use count is " << sp1.use_count() << endl; // 2

    // reset decrease use count
    sp2.reset();

    cout << "sp1 use count is " << sp1.use_count() << endl; // 1

    weak_ptr<int> wp1 = sp1;
    if (wp1.expired())
        return 0;

    auto sp3 = wp1.lock(); // 2
    cout << "sp1 use count is " << sp1.use_count() << ", sp3 value is " << *sp3 << endl; // 2

    sp3.reset(); // 1
    cout << "sp1 use count is " << sp1.use_count() << endl; // 1

    sp1.reset();
    cout << "sp1 use count is " << sp1.use_count() << endl; // 0

    if (wp1.expired()) {
        cout << "w1 is expired." << endl;
    }

    if (auto s = wp1.lock()) {
        cout << "s is available." << endl;
    } else {
        cout << "s is not available." << endl;
    }
}
