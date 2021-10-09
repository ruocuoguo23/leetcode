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
