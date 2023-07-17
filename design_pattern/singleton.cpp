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