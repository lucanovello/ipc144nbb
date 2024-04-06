#ifndef SENECA_POSAPP_H
#define SENECA_POSAPP_H
#include "POS.h"
struct Item
{
	char sku[MAX_SKU_LEN];
	char name[MAX_NAME_LEN];
	double price;
	int taxed;
	int quantity;
};

struct Item items[MAX_NO_ITEMS];
int noOfItems;

void start(const char* action);
void inventory(void);
void addItem(void);
void removeItem(void);
void stockItem(void);

double cost(const struct Item* item);
void listItems(void);
int loadItems(const char filename[]);
int saveItems(const char filename[]);

double billDisplay(const struct Item* item);
void display(const struct Item* item);
int search(void);
void POS(void);

#endif // !SENECA_POSAPP_H

