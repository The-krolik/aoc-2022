#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rps(char first, char second);
char decode(char c);

int main()
{
	FILE *fp;
	char c1, c2, myPick, theirPick;
	int total_score = 0;

	fp = fopen("input.txt", "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);

	while (fscanf(fp, "%c " "%c ", &c1, &c2) != EOF) {
		theirPick = decode(c1);
		myPick = decode(c2);

		total_score += rps(myPick, theirPick);
	}

	printf("total_score: %d\n", total_score);

	return 0;
}

int rps(char first, char second)
{
	int rock = 1;
	int paper = 2;
	int scissors = 3;
	int win = 6;
	int lose = 0;
	int draw = 3;

	if (first == 'r') {
		switch(second) {
			case 'r':
				return rock + draw;
			case 'p':
				return rock + lose;
			case 's':
				return rock + win;
		}
	}
	else if (first == 'p') {
		switch(second) {
			case 'r':
				return paper + win;
			case 'p':
				return paper + draw;
			case 's':
				return paper + lose;
		}
	}
	else if (first == 's') {
		switch(second) {
			case 'r':
				return scissors + lose;
			case 'p':
				return scissors + win;
			case 's':
				return scissors + draw;
		}
	}

	return -1;
}

char decode(char c)
{
	if ((c == 'A') || (c == 'X'))
		return 'r';
	else if ((c == 'B') || (c == 'Y'))
		return 'p';
	else if ((c == 'C') || (c == 'Z'))
		return 's';

	return 0;
}
