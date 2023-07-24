//
// Created by 吴洋 on 2023/7/23.
//
#include <thread>
#include <iostream>
#include <mutex>

using namespace std;

void f1(int n) {
    cout << "hello world, " << n << "." << endl;
    cout << this_thread::get_id() << endl;
}

// with lock
mutex mtx1;

void f2() {
    lock_guard<mutex> lock(mtx1);
    for (int index = 0; index < 5; ++ index) {
        cout << this_thread::get_id() << ": " << index << endl;
    }
}

void f3() {
    unique_lock<mutex> lock(mtx1);
    for (int index = 0; index < 5; ++ index) {
        cout << this_thread::get_id() << ": " << index << endl;
    }
}

int main() {
//    thread t1(f1, 1);
//    t1.join(); // join here will wait t1 finish.
//    t1.detach(); // detach会让这个线程后台运行

//    thread t2(f2);
//    thread t3(f2);
//    t2.join();
//    t3.join();

    thread t4(f3);
    thread t5(f3);
    t4.join();
    t5.join();

    cout << "all finish." << endl;
}