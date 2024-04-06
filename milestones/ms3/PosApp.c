#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
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
double cost(const struct Item* item) {
	return item->price * (1 + item->taxed * TAX);
}
void listItems(void) {
	char iName[20];
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
	while (fscanf(data, "%6[^,],%60[^,],%lf,%d,%d", items[noOfItems].sku, items[noOfItems].name, &items[noOfItems].price, &items[noOfItems].taxed, &items[noOfItems].quantity) == 5) {
		noOfItems += 1;
		flushFile(data);
	};
	fclose(data);
	displayAction("Done!");
	return noOfItems;
}
int saveItems(const char filename[]) {
	int i;
	displayAction("Saving Items");

	FILE* file = fopen(filename, "w");
	if (file == NULL) {
		fprintf(stderr, "Could not open >>%s<<\n", filename);
		return 2;
	}
	for (i = 0; i < noOfItems; i++)
	{
		struct Item item = items[i];
		fprintf(file, "%s,%s,%lf,%d,%d\n", item.sku, item.name, items[i].price, items[i].taxed, items[i].quantity);
	};
	fclose(file);
}
double billDisplay(const struct Item* item) {
	double totalCost = 0.0;
	int i;
	char iName[15];
	strnCpy(iName, item->name, 14);
	printf("| %-14s|%10.2lf | %3s |\n", iName, cost(item), item->taxed ? "Yes" : "   ");
	totalCost += cost(item);
	return totalCost;
}
void display(const struct Item* item) {
	printf("=============v\n");
	printf("Name:        %s\n", item->name);
	printf("Sku:         %s\n", item->sku);
	printf("Price:       %.2lf\n", item->price);
	if (item->taxed) {
		printf("Price + tax: %.2lf\n", cost(item));
	}
	else {
		printf("Price + tax: N/A\n");
	}
	printf("Stock Qty:   %d\n", item->quantity);
	printf("=============^\n");
}
int search(void) {
	char sku[MAX_SKU_LEN + 1];
	int i;
	printf("Sku: ");
	fgets(sku, MAX_SKU_LEN, stdin);
	if (sku[strlen(sku) - 1] == '\n') {
		sku[strlen(sku) - 1] = '\0';
	}
	if (sku[0] == '\0') {
		return -2;
	}
	for (i = 0; i < noOfItems; i++)
	{
		if (strcmp(sku, items[i].sku) == 0) {
			return i;
		}
	}
	return -1;

}
void POS(void) {
	displayAction("Point Of Sale");
	struct Item* bill[MAX_BILL_ITEMS + 1];
	int billItemCounter = 0;
	double billTotal = 0;
	int i;
	int skuResult = search();
	while (skuResult != -2 && billItemCounter < MAX_BILL_ITEMS) {
		if (skuResult == -1) {
			printf("SKU not found!\n");
		}
		else if (skuResult >= 0) {
			if (items[skuResult].quantity <= 0) {
				printf("Item sold out!\n");
			}
			else {
				items[skuResult].quantity--;
				bill[billItemCounter] = &items[skuResult];
				display(bill[billItemCounter]);
				billTotal += cost(bill[billItemCounter]);
				billItemCounter++;
			}
		}
		skuResult = search();
	}

	printf("+---------------v-----------v-----+\n");
	printf("| Item          |     Price | Tax |\n");
	printf("+---------------+-----------+-----+\n");
	
	for ( i = 0; i < billItemCounter; i++)
	{
		billDisplay(bill[i]);
	}
	printf("+---------------^-----------^-----+\n");
	printf("| total:              %.2lf |\n", billTotal);
	printf("^---------------------------^\n");

}

