#include <iostream>
#include <chrono>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include "SHA256.h"
#include "uint256.h"

uint32_t nonce=0;
std::string s;
uint256 diff=0x100000;
uint n=0;

int main() {
	
	std::cout << "Enter difficulty: (The difficulty ranges from 0 to 234, doubling at each step)" << std::endl;
	std::cin >> n;
	if (n>234){
		std::cout << "!!!!Invalid difficulty, asshole!!!!" << std::endl;
		return 0;
	}
	std::cout << "Enter string:" << std::endl;
	std::cin >> s;
	
	uint j=234-n;
	for(int i=0; i<=j;++i)
	diff+=diff;

	while (nonce < 0x1000000){
		std::string s2=s+std::to_string(nonce);
		++nonce;
		SHA256 sha,sha2;
		sha.update(s2);
		uint8_t * digest = sha.digest();
		sha2.update(digest,32);
		uint8_t * digest2 = sha2.digest();
		
		if (SHA256::toString(digest2)<diff.GetHex()){
			std::cout << "\nThe winning ticket is: " << s2 << std::endl;
			std::cout << "Target: " << diff.GetHex() << std::endl;
			std::cout << "Hash:   " << SHA256::toString(digest2) << std::endl;
			goto end;
		}
		
		delete[] digest;
		delete[] digest2;
	}
	std::cout << "\nTarget: " << diff.GetHex() << std::endl;
	std::cout << "Better luck next time!" << std::endl;
	
	end:
	return 0;
}
