#include <iostream>
#include <chrono>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <iomanip>
#include "SHA256.h"
#include "uint256.h"
#include "func.h"

uint32_t nonce=0;
std::string s;
uint n=0;

int main(){
	
	std::cout << "Enter difficulty: (The difficulty ranges from 0 to 234, doubling at each step)" << std::endl;
	std::cin >> n;
	if (n>234){
		std::cout << "!!!!Invalid difficulty, asshole!!!!" << std::endl;
		return 0;
	}
	std::cout << "Enter string:" << std::endl;
	std::cin >> s;

	auto start = std::chrono::steady_clock::now();

	while (nonce < 0x1000000){
		std::string s2=s+hex32rev(nonce);
		++nonce;
		SHA256 sha,sha2;
		sha.update(s2);
		uint8_t * digest = sha.digest();
		sha2.update(digest,32);
		uint8_t * digest2 = sha2.digest();
		
		if (byterev(SHA256::toString(digest2)) <Target(n).GetHex()){
			std::cout << "\nThe winning ticket is: " << s2 << std::endl;
			std::cout << "Target: " << Target(n).GetHex() << std::endl;
			std::cout << "Hash:   " << SHA256::toString(digest2) << std::endl;
			goto end;
		}
		
		delete[] digest;
		delete[] digest2;
	}

	std::cout << "\nTarget: " << Target(n).GetHex() << std::endl;
	std::cout << "Better luck next time!" << std::endl;
	
	end:
	
	auto end = std::chrono::steady_clock::now();
	auto tempo = end-start;
	
	std::cout << std::chrono::duration <double> (tempo).count() << "s" << std::endl;
	
	return 0;
}
