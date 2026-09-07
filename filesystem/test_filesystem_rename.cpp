// 练习：C++17 文件系统重命名与错误码
// 目标：观察 filesystem::rename 的 error_code 重载如何报告重命名结果。
// 思路：尝试将相对路径 1234567.txt 重命名为 12345678.txt，再打印 ec.value()；
//       源路径不存在时会报告错误，成功时错误码为 0。
// 要点：路径相对于程序工作目录；若源文件实际存在，运行此示例会执行真实重命名。

//
// Created by wuyang on 2021/1/28.
//

#include <filesystem>
#include <vector>
#include <iostream>

using namespace std;

int main() {
	std::string no_exist_file_or_dir = "1234567.txt";
//	int error_code = 0;
	std::error_code ec;
	filesystem::rename(no_exist_file_or_dir, "12345678.txt", ec);

	std::cout << "rename result " << ec.value() << std::endl;
}
