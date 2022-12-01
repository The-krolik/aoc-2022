#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void try_to_insert(int val, int *list, int size);

int main() {
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int sum = 0;
	int grand_total = 0;
	int list[3] = {0, 0, 0};
	
	fp = fopen("input.txt", "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);

	while ((read = getline(&line, &len, fp)) != -1) {
		if (strcmp(line, "\n")) {
			line[strcspn(line, "\n")] = 0;
			sum += atoi(line);
		}
		else {
			try_to_insert(sum, list, 3);
			sum = 0;
		}
	}

	for (int i = 0; i < 3; i++) {
		grand_total += list[i];
		printf("%d: %d\n", i, list[i]);
	}
	printf("grand total: %d\n", grand_total);
	fclose(fp);

	return 0;
}

void try_to_insert(int val, int *list, int size) {
	int i, pivot;

	for (i = 0; i < size; i++) {
		if (val > list[i]) {
			pivot = list[i];
			list[i] = val;
			try_to_insert(pivot, list, size);
			return;
		}
	}
}
