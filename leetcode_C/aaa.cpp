#include<stack>
#include<queue>

bool check_is_valid_order(std::queue<int>& order) {
	std::stack<int>S;
	int n = (int)order.size();
	for (int i = 0; i < n; i++) {
		S.push(i);
		while (!S.empty() && order.front() == S.top()) {
			S.pop();
			order.pop();
		}
	}
	if (!S.empty() ){
		return false;
	}
	return true;
}

int maincheck_is_valid_order() {
	int n;
	int train;
	scanf_s("%d", &n);
	while (n) {
		scanf_s("%d", &train);
		while (train) {
			std::queue<int>order;
			for (int i = 1; i < n; i++) {
				scanf_s("%d", &train);
				order.push(train);
			}
			if (check_is_valid_order(order)) {
				printf("Yes\n");
			}
			else {
				printf("No\n");
			}
			scanf_s("%d", &train);
		}
		printf("\n");
		scanf_s("%d", &n);
	}
	return 0;
}
