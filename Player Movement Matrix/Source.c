#include <stdio.h>
#include <stdlib.h>     
#include <time.h>      


char getDir(int dir) {

	if (dir == 65 || dir == 97) {
		return 'l';
	}
	else if (dir == 68 || dir == 100) {
		return 'r';
	}
	else if (dir == 87 || dir == 119) {
		return 'u';
	}
	else if (dir == 83 || dir == 115) {
		return 'd';
	}
	else {
		return ' ';
	}
}

void initMap(char map[20][30], int rows, int cols) {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			map[i][j] = '_';
		}
	}
}

void printMap(char map[20][30], int rows, int cols) {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			printf("%c ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void setPlayer(char map[20][30], int rows, int cols, int posX, int posY) {

	if ((posX >= 0 && posX < cols) &&
		(posY >= 0 && posY < rows)) {
		map[posY][posX] = 'O';
	}

}


int main()
{
	char map[20][30];

	int pX = 10;
	int pY = 10;

	initMap(map, 20, 30);
	setPlayer(map, 20, 30, pX, pY);
	printMap(map, 20, 30);

	char key;
	
	scanf_s("%c", &key);

	while (key != 'q' && key != 'Q') {
	
		char dir = getDir(key);

	
		switch (dir) {
		case 'l':
			pX--;
			break;
		case 'r':
			pX++;
			break;
		case 'u':
			pY--;
			break;
		case 'd':
			pY++;
			break;
		default:
			break;
		}

		system("CLS");
		initMap(map, 20, 30);
		setPlayer(map, 20, 30, pX, pY);
		printMap(map, 20, 30);

		scanf_s(" %c", &key);
	}

	return 0;
}