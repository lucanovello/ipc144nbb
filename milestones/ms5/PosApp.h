#ifndef SENECA_POSAPP_H
#define SENECA_POSAPP_H
#include "POS.h"
struct Item {
	char sku[MAX_SKU_LEN+1];
	char name[MAX_NAME_LEN+1];
	double price;
	int taxed;
	int quantity;
};
struct Item items[MAX_NO_ITEMS];
int noOfItems;
void displayAction(const char* action);
double cost(const struct Item* item);
void listItems(void);
double billDisplay(const struct Item* item);
void display(const struct Item* item);
int search(void);
int selectItems(void);
void POS(void);
void inventory(void);
void addItem(void);
void removeItem(void);
void stockItem(void);
int loadItems(const char filename[]);
int saveItems(const char filename[]);

#endif // !SENECA_POSAPP_H

