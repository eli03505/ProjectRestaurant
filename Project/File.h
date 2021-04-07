#pragma once
#include<iostream>
#include<fstream>
#include"Client.h"
#include"Notification.h"
using namespace std;

#pragma region File
class File {
public:
	static string filename;
	static void saveIngredient(Stock stock) {
		cout << "Ingredient count:" << stock.getIngredientSize() << endl;
		for (int i = 0; i < stock.getIngredientSize(); i++) {
			stock.getIngredientById(i).getId();
		}
		cout << "Error : " << endl;
	}
};
#pragma endregion