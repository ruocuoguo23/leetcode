// 练习：函数局部静态变量实现单例
// 目标：通过 GetInstance 访问同一个 Singleton1 对象，限制外部直接构造和复制。
// 思路：将构造与析构设为私有，删除复制构造函数；访问函数内定义 static 实例，
//       首次访问时初始化，以后返回同一地址，实例随程序正常结束自动销毁。
// 要点：C++11 保证该局部静态对象初始化的线程安全；不代表后续成员操作自动线程安全。

//
// Created by 吴洋 on 2023/7/17.
//
//#include <pthread.h>
#include <mutex>

using namespace std;


class Singleton1 {
public:
    static Singleton1* GetInstance() {
        static Singleton1 instance;
        return &instance;
    }

    Singleton1(const Singleton1&) = delete;
private:
    Singleton1() = default;
    ~Singleton1() = default;
};

int main() {
    auto p = Singleton1::GetInstance();
//    Singleton1 q(*p);
}