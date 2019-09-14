#include "bartender.h"

std::vector<int> BlendWines(int K, std::vector<int> R){
	int N = R.size();
	for(auto &i:R){
		if(i>5) i-=4;
		else i=1;
	}
	return R;
}
