#include <iostream>
#include <vector>

std::vector<int> french(std::vector<int> *n) {
	
	n->push_back(88);
	
	return *n;
}


int main() {
	int y = 8;
	int *x = nullptr;
	x = &y;

	std::vector<int> v;
	std::vector<int> w;
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	w = french(&v);

	for(int x : w) {
		std::cout << x << std::endl;
	}

	// operationally, passing a pointer to another functino is the same as passing a reference (according to c++ std)
	

	std::cout << *x << std::endl;
}
