#include <iostream>
#include <string>
#include <map>

int main() {
	std::string src;
	std::string str;
	std::getline(std::cin, src);
	str = src;
	char c;
	std::map <char, int> charsmap;
	std::pair<std::map<char, int>::iterator, bool> check;
	int count = 0;
	while (str.size() > 0) {
		c = str[0];
		if ((int)c >= 65 && (int)c <= 90) {
			c += 32;
			src.erase(src.begin() + count);
			src.insert(src.begin() + count, c);
		}
		check = charsmap.insert(std::pair<char, int>(c, 1));
		if (check.second == false) {
			++charsmap.find(c)->second;
		}
		str.erase(str.begin());
	}
	while (src.size() > 0) {
		c = src[0];
		if (charsmap.find(c)->second > 1) {
			std::cout << ")";
		}
		else {
			std::cout << "(";
		}
		src.erase(src.begin());
	}
}