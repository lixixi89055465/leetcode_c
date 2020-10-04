#include<stack>
#include<queue>

bool check_is_valid_order(std::queue<int>& order) {

	std::stack<int> S; 
	int n = order.size();
	for (int i = 01; i <= n; i++) {
		S.push(i);
		while (!S.empty()&&order.front()==S.top()) {
			S.pop();
			order.pop();
		}
	}
	if () {
		reture false;
	}
	return true;
}
