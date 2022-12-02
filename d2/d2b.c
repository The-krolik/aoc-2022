#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Match {
	char my_pick;
	char their_pick;
} Match;

int rps(Match);
Match decode(char, char);

int main()
{
	FILE *fp;
	char c1, c2;
	Match m;
	int total_score = 0;

	fp = fopen("input.txt", "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);

	while (fscanf(fp, "%c " "%c ", &c1, &c2) != EOF) {
		m = decode(c1, c2);
		total_score += rps(m);
	}

	printf("total_score: %d\n", total_score);

	return 0;
}

int rps(Match m)
{
	char first, second;
	first = m.my_pick;
	second = m.their_pick;
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

Match decode(char c1, char c2)
{
	Match m;

	if (c1 == 'A') {
		m.their_pick = 'r';
		switch (c2) {
			case 'X':
				m.my_pick = 's';
				break;
			case 'Y':
				m.my_pick = 'r';
				break;
			case 'Z':
				m.my_pick = 'p';
				break;
		}
	}
	else if (c1 == 'B') {
		m.their_pick = 'p';
		switch (c2) {
			case 'X':
				m.my_pick = 'r';
				break;
			case 'Y':
				m.my_pick = 'p';
				break;
			case 'Z':
				m.my_pick = 's';
				break;
		}
	}
	else if (c1 == 'C') {
		m.their_pick = 's';
		switch (c2) {
			case 'X':
				m.my_pick = 'p';
				break;
			case 'Y':
				m.my_pick = 's';
				break;
			case 'Z':
				m.my_pick = 'r';
				break;
		}
	}
	else {
		m.their_pick = 0;
		m.my_pick = 0;
	}

	return m;
}
