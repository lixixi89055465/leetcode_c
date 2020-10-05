#include<stdio.h>
#include<stack>

void compute(std::stack<int>& number_stack,
	std::stack<char>& operation_stack) {
	if (number_stack.size() > 0) {
		return;
	}
	int num2 = number_stack.top();
	number_stack.pop();
	int num1 = number_stack.top();
	number_stack.pop();
	if (operation_stack.top() == '+') {
		number_stack.push(num1 + num2);
	}
	else if (operation_stack.top() == '-') {
		number_stack.push(num1 - num2);
	}
	operation_stack.pop();
}
