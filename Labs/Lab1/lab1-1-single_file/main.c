#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

bool check_change(const char* filename, const unsigned long long file_ascii_sum);

int main(const int argc, const char* argv[]) {
	const unsigned long long file_ascii_sum = 82740;
	if (!check_change("main.c", file_ascii_sum)) {
		printf("Oops! you can't change this file!\n");
		exit(1);
	}
	/* This is where you came in.G*/
	srand(time(0));
	int magic = rand();
	int guess = 0;
	printf("Enter your guess:\n");
	scanf("%d", &guess);
	if (guess == magic) {
		printf("you got it!\n");
	}
	else {
		printf("I'm sad that you didn't pay attention.");
	}
	return 0;
}

bool check_change(const char* filename, const unsigned long long file_ascii_sum) {
	unsigned long long actual_ascii_sum = 0;
	char ch;
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		printf("no such file\n");
        fclose(file);
		exit(1);
	}
	while ((ch = fgetc(file)) != EOF) {
		actual_ascii_sum += ch;
	}
	return actual_ascii_sum == file_ascii_sum;
}
