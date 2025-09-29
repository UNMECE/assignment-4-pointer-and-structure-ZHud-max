#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

#define SIZE 5

void add_item(Item* item_list, double price, char* sku, char* category, 
								char* name, int index) {
	
	item_list[index].price = price;
	item_list[index].sku = (char *) malloc(sizeof(char) * (strlen(sku) + 1));
	item_list[index].category = (char *) malloc(sizeof(char) * (strlen(category) + 1));
	item_list[index].name = (char *) malloc(sizeof(char) * (strlen(name) + 1));

	strcpy(item_list[index].name, name);
	strcpy(item_list[index].sku, sku);
	strcpy(item_list[index].category, category);

}

void free_items(Item* item_list, int size) {

	for (int i = 0; i < size; i++) {
		free(item_list[i].sku);
		free(item_list[i].name);
		free(item_list[i].category);
	}

	free(item_list);
	
}

double average_price(Item *item_list, int size) {

	double total;

	for (int i = 0; i < size; i++) {
		total += item_list[i].price;
	}
	
	return total / size;

}

void print_items(Item *item_list, int size) {

	for (int i = 0; i < size; i++) {
	
		printf("###############\n");
		printf("Item name = %s\n", item_list[i].name);
		printf("Item sku = %s\n", item_list[i].sku);
		printf("Item category = %s\n", item_list[i].category);
		printf("Item price = $%.2f\n", item_list[i].price);

	}

	printf("###############\n");

}

void find_item(Item* item_list, char* search , int size) {

	int index = 0;

	while (index < size || strcmp(item_list[index].sku, search) != 0) {
		
		if (strcmp(item_list[index].sku, search) == 0) {
			printf("Item found:\n");
			printf("Name: %s\n", item_list[index].name);
			printf("Category: %s\n", item_list[index].category);
			printf("Price: $%.2f\n", item_list[index].price);
			return;
		}

		index++;
	}

	printf("Item not found\n");
	
}


int main(int argc, char* argv[]) {

	if (argc != 2) {
		printf("Please enter an SKU!\n");
		return 1;
	}

	Item* item_list = malloc(SIZE * sizeof(Item));

	if (item_list == NULL) {
		printf("Memory allocation failed\n");
		return 1;
	}

	add_item(item_list, 200.00, "12345", "Food", "Beans", 0);
	add_item(item_list, 8.00, "67891", "Sports", "Pickleball", 1);
	add_item(item_list, 429.832, "01112", "Games", "Chessboard", 2);
	add_item(item_list, 3.50, "13141", "Unknown", "Forbidden Tomb", 3);
	add_item(item_list, 3900.01, "51617", "Entertainment", "HAM Radio", 4);

	print_items(item_list, SIZE);

	printf("Average price of all items = $%.2f\n", average_price(item_list, SIZE));

	find_item(item_list, argv[1], SIZE);

	free_items(item_list, SIZE);

	return 0;

}
