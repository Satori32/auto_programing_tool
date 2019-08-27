#include <iostream>
#include <vector>
#include <cstdint>
#include <string>
#include <limits>

#if 0
typedef std::vector<std::uintmax_t> Data;


bool AddOne(Data& D,std::uintmax_t Radix=10) {
	bool F = false;
	size_t i = 0;
	if (D.size() == 0) return false;
	D[0]++;

	for (i = 0; i < D.size()-1; i++) {
		F = false;
		if (D[i] >= Radix) {
			D[i] %= Radix;
			D[i + 1]++;
			F = true;
		}
		else {
			break;
		}
	}

	D[i] %= Radix;

	return F;
	
}



int main() {
	std::string Ch = "0123456789abcdefghijklnmopqrstuvwxyz+-*%=!\"\#\'()~|&^\{\}\;\<\.<>\\{}[]";
	
	Data D(7);
	do {
		for (auto& o : D) {
			std::cout <<Ch[o] << ',';
		}
		std::cout <<"\r";
		
	} while (!AddOne(D,Ch.size()));
}

#else

typedef std::vector<std::uintmax_t> Data;

Data SepDigit(std::uintmax_t N,const std::uintmax_t& Radix=10) {
	Data R;

	while (N) {
		R.push_back(N % Radix);
		N /= Radix;
	}
	return R;
}

int main() {

	std::string Ch = "0123456789abcdefghijklnmopqrstuvwxyz+-*%=!\"\#\'()~|&^\{\}\;\<\.<>\\{}[]";

	for (std::uintmax_t i = 0; i <std::numeric_limits<std::uintmax_t>::max(); i++) {
		Data D = SepDigit(i,Ch.size());
		for (auto& o : D) {
			std::cout << Ch[o] << ',';
		}
		std::cout << "\r";
	}
}


#endif