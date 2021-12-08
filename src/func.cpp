#include <string>
#include <cstring>
#include <vector>
#include <iomanip>
#include "uint256.h"
#include "func.h"

uint256 Target(uint n){
	uint256 diff=0x100000;
	uint j=234-n;
	for(uint i=0; i<=j;++i)
		diff+=diff;
	return diff;
}

std::string hex32rev(uint32_t n){
	std::stringstream ss;
	ss << std::setw(8) << std::setfill('0') << std::hex << n;  
	return byterev(ss.str());
}

std::string byterev(std::string s){
	char psz[s.size() + 1];
	const uint8_t * data=reinterpret_cast<const uint8_t*> (s.c_str());
	for (size_t i = 0; i < s.size()/2; i++){
		sprintf(psz + i*2, "%c", ((unsigned char*)data)[s.size() - 2*i - 2]);
		sprintf(psz + i*2+1, "%c", ((unsigned char*)data)[s.size() - 2*i - 1]);
	}
	return std::string(psz, s.size());
}
