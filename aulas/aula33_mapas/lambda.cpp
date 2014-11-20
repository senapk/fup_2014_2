#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main(){
	vector<int> vi = {1, 2, 3, 15, 5, 6, 7, 9};
	int maior_que = 0;
	auto it = find_if(vi.begin(), vi.end(), [&](int num)->bool{
		return num > maior_que;
	});
	cout << *it << endl;

	return 0;
	
}










