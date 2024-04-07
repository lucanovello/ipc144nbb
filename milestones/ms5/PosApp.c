#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "PosApp.h"
#include "utils.h"

void displayAction(const char* action) {
	printf(">>>> %s...\n", action);
}
double cost(const struct Item* item) {
	return item->price * (1 + item->taxed * TAX);
}
void listItems(void) {
	char iName[20];
	int i;
	printf("-----v--------v--------------------v-------v---v-----v---------v\n");
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
double billDisplay(const struct Item* item) {
	double totalCost = 0.0;
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
int selectItems(void) {
	int selection;
	printf("Select an item:\n");
	listItems();
	printf("Select row: ");
	selection = getIntMM(1, noOfItems, "Row Number");
	return selection;
}
void POS(void) {
	displayAction("Point Of Sale");
	struct Item* bill[MAX_BILL_ITEMS];
	int billItemCounter = 0;
	double billTotal = 0;
	int i;
	int skuResult;
	do {
		skuResult = search();
		if (skuResult == -2) {
			break;
		}
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
	} while (billItemCounter < MAX_BILL_ITEMS);
	if (billItemCounter > 0) {
		printf("+---------------v-----------v-----+\n");
		printf("| Item          |     Price | Tax |\n");
		printf("+---------------+-----------+-----+\n");

		for (i = 0; i < billItemCounter; i++)
		{
			billDisplay(bill[i]);
		}
		printf("+---------------^-----------^-----+\n");
		printf("| total:              %.2lf |\n", billTotal);
		printf("^---------------------------^\n");
	}
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
	struct Item newItem;
	displayAction("Adding Item");
	if (noOfItems < MAX_NO_ITEMS) {
		printf("SKU: ");
		scanf("%6[^\n]", &newItem.sku);
		flushKey();
		printf("Name: ");
		scanf("%60[^\n]", &newItem.name);
		flushKey();
		printf("Price: ");
		newItem.price = getDbl();
		printf("Is the item Taxed? ");
		newItem.taxed = yes();
		printf("Quantity: ");
		newItem.quantity = getIntMM(0, MAX_STOCK_NUMBER, "Quantity");
		items[noOfItems] = newItem;
		noOfItems++;
		displayAction("Done!");
	}
	else {
		printf("This system cannot store more that %d different Items in the inventory!\n", MAX_NO_ITEMS);
	}
}
void removeItem(void) {
	int selected;
	int i;
	displayAction("Remove Item");
	selected = selectItems() - 1;
	for ( i = selected; i < noOfItems; i++) {
		items[i] = items[i + 1];
	}
	noOfItems--;
	displayAction("Done!");
}
void stockItem(void) {
	int rowSelected;
	int qtyToAdd = 0;
	displayAction("Stock Items");
	rowSelected = selectItems();
	printf("Quantity to add: ");
	qtyToAdd = getIntMM(1, MAX_STOCK_NUMBER - items[rowSelected - 1].quantity, "Quantity to Add");
	items[rowSelected - 1].quantity += qtyToAdd;
	display(&items[rowSelected - 1]);
	displayAction("Done!");
}
int loadItems(const char filename[]) {
	noOfItems = 0;
	displayAction("Loading Items");
	FILE* data = fopen(filename, "r");
	if (data == NULL) {
		fprintf(stderr, "ERROR! ERROR! File %s not found. File required to continue...\n", filename);
		return 2;
	}
	while (fscanf(data, "%[^,],%[^,],%lf,%d,%d", items[noOfItems].sku, items[noOfItems].name, &items[noOfItems].price, &items[noOfItems].taxed, &items[noOfItems].quantity) == 5) {
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
		return -1;
	}
	for (i = 0; i < noOfItems; i++)
	{
		struct Item item = items[i];
		fprintf(file, "%s,%s,%.2lf,%d,%d\n", item.sku, item.name, items[i].price, items[i].taxed, items[i].quantity);
	};
	fclose(file);
	displayAction("Done!");
	return 0;
}