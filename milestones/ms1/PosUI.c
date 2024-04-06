#include <stdio.h>
#include "PosUI.h"
#include "utils.h"
#include "PosApp.h"

int menu(void) {
	printf("The Sene-Store");
	nl();
	printf("1- Inventory");
	nl();
	printf("2- Add item");
	nl();
	printf("3- Remove item");
	nl();
	printf("4- Stock item");
	nl();
	printf("5- POS");
	nl();
	printf("0- exit program");
	nl();
	printf("> ");
	return 0;
}

void runPos(const char filename[]) {
	int done = 0;
	int selection = 0;
	loadItems(filename);
	while (!done) {
		menu();
		selection = getIntMM(0, 5, "Selection");
	switch (selection) {
		case 1:
			inventory();
			break;
		case 2:
			addItem();
			break;
		case 3:
			removeItem();
			break;
		case 4:
			stockItem();
			break;
		case 5:
			POS();
			break;
		case 0:
			saveItems(filename);
			printf("Goodbye!\n");
	nl();
			done = 1;
			break;
		default:
			break;
		}
	}
}