// 练习：auto 类型推导与尾置返回类型
// 目标：观察普通变量、引用以及函数模板返回值的类型推导。
// 思路：auto a = 10 推导为 int，auto& d = a 绑定引用，修改 a 后 d 同步变化；
//       add 模板用 decltype(t + u) 作为尾置返回类型，使结果类型随参数运算决定。
// 要点：同一条 auto 声明包含多个变量时，推导出的类型必须一致。

//
// Created by wuyang on 2023/1/23.
//
#include <iostream>

using namespace std;

template<typename T, typename U>
auto add(T t, U u) -> decltype(t + u) {
    return t + u;
}

int main() {
    // right, a is int
    auto a = 10;

    // wrong, can not be different type
//    auto b = 15, c = 2.5;

    auto &d = a;
    cout << d << endl;

    a = 15;
    cout << d << endl;

    int e = 3, f = 4;
    auto result = add(e, f);
    cout << result << endl;

    return 0;
}
