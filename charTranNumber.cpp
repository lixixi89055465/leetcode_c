#include<stdio.h>
#include<string>

int mainnumber() {
	int number = 0;
	std::string s = "12345";
	for (int i = 0; i < s.length(); i++) {
		number = number * 10 + s[i] - '0';
	}
	printf("number = %d \n", number+10000);
	return 0;
}
