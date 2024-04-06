#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "PosApp.h"
#include "utils.h"

void displayAction(const char* action) {
	printf(">>>> %s...\n", action);
}
void inventory(void) {
	double tav = 0.0;
	int i;
	displayAction("List Items");
	listItems();
	for (i = 0; i < noOfItems; i++) {
		tav += cost(&items[i]) * items[i].quantity;
	}
	printf("                               Total Asset: $  | %13.2lf |\n", tav);
	printf("-----------------------------------------------^---------------^\n");
}
void addItem(void) {
	displayAction("Adding Item");
}
void removeItem(void) {
	displayAction("Remove Item");
}
void stockItem(void) {
	displayAction("Stock Items");
}
void POS(void) {
	displayAction("Point Of Sale");
}
double cost(const struct Item* item) {
	return item->price * (1 + item->taxed * TAX);
}
void listItems(void) {
	char iName[19];
	int i;
	printf(" Row | SKU    | Item Name          | Price |TX | Qty |   Total |\n");
	printf("-----|--------|--------------------|-------|---|-----|---------|\n");
	for (i = 0; i < noOfItems; i++)
	{
		strnCpy(iName, items[i].name, 19);
		printf("%4d | %6s | %-19s| %5.2lf | %c | %3d | %7.2lf |\n",
			i + 1,
			items[i].sku,
			iName,
			items[i].price,
			items[i].taxed ? 'T' : ' ',
			items[i].quantity,
			cost(&items[i]) * items[i].quantity);
	}
	printf("-----^--------^--------------------^-------^---^-----^---------^\n");
}
int loadItems(const char filename[]) {
	noOfItems = 0;
	displayAction("Loading Items");
	FILE* data = fopen(filename, "r");
	if (data == NULL) {
		fprintf(stderr, "ERROR! ERROR! File %s not found. File required to continue...\n", filename);
		return 2;
	}
	while (fscanf(data, "%5[^,],%59[^,],%lf,%d,%d", items[noOfItems].sku, items[noOfItems].name, &items[noOfItems].price, &items[noOfItems].taxed, &items[noOfItems].quantity) == 5) {
		noOfItems += 1;
		flushFile(data);
	};
	fclose(data);
	displayAction("Done!");
	return noOfItems;
}
void saveItems(const char filename[]) {
	displayAction("Saving Items");
}
