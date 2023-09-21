#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>

bool check_change(const char* filename);

int main(const int argc, const char* argv[]) {
	if (!check_change("main.c")) {
		printf("Oops! you can't change this file!\n");
		exit(1);
	}
	/* This is where you came in. */
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

bool check_change(const char* filename) {
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		printf("no such file\n");
        fclose(file);
		exit(1);
	}
	FILETIME lastWriteTime;
	if (!GetFileTime((HANDLE)_get_osfhandle(_fileno(file)), NULL, NULL, &lastWriteTime)) {
        printf("get time error\n");
        fclose(file);
		exit(1);
    }

	FILE* time_file = fopen("time.txt", "r");
	if (time_file == NULL) {
		time_file = fopen("time.txt", "w");
		fprintf(time_file, "%lu %lu\n", lastWriteTime.dwLowDateTime, lastWriteTime.dwHighDateTime);
		fclose(time_file);
		exit(1);
	}
	else {
		DWORD dwL, dwH;
		fscanf(time_file, "%lu %lu", &dwL, &dwH);
		if (dwL == lastWriteTime.dwLowDateTime && dwH == lastWriteTime.dwHighDateTime) {
			return true;
		}
		return false;
	}
}
