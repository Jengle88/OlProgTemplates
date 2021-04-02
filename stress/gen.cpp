#include <iostream>
#include <cstdlib>

int main(){
	srand(time(0));
	int k = 1 + rand() % 100;
	std::cout << k;
	return 0;
}
