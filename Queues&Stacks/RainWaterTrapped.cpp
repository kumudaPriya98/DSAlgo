#include <iostream>
#include <vector>
using namespace std;


int trap(const vector<int> &A) {
	vector<int> left_max(A.size()), right_max(A.size());
	left_max[0] = 0;
	for(int i=1; i<A.size(); i++)
		left_max[i] = max(left_max[i-1], A[i-1]);
	right_max[A.size() - 1] = 0;
	for(int i=A.size() - 2; i >= 0; i--)
		right_max[i] = max(right_max[i+1], A[i+1]);
	
	int result = 0;
	for(int i=0; i<A.size(); i++) {
		int val = min(left_max[i], right_max[i]) - A[i];
		if(val > 0) result += val;
	}
	return result;

}