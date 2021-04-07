#include<iostream>
#include<Windows.h>
#include<fstream>
#include"Client.h"
#include"Admin.h"
#include"Order.h"
#include"File.h"
using namespace std;

int main() {
	Ingredient mushroom("Mushroom", 1, 1, 1, 1, 10, 1);
	Ingredient meat("Meat", 2, 2, 2, 2, 8, 2);
	Ingredient Rice_sauce("Cheese", 3, 3, 3, 3, 7, 6);
	Ingredient olive("Olive", 4, 4, 4, 4, 5, 3);
	Ingredient spice("Spice", 5, 5, 5, 5, 8, 2);

	Stock ingredient;
	ingredient.addIngredient(mushroom);
	ingredient.addIngredient(meat);
	ingredient.addIngredient(Rice_sauce);
	ingredient.addIngredient(olive);
	ingredient.addIngredient(spice);


	Meal pizza("Pizza", "Fast Food", 8, 15, 2, 10);
	Meal pulov("Pulov", "Milli Yemek", 7.5, 5, 3, 8);
	Meal kabab("Kabab", "Category", 9.9, 25, 3, 5);

	pizza.addIngredient(mushroom);
	pizza.addIngredient(olive);

	pulov.addIngredient(spice);
	pulov.addIngredient(Rice_sauce);

	kabab.addIngredient(meat);
	kabab.addIngredient(mushroom);

	Kitchen meal;
	meal.addMeal(pizza);
	meal.addMeal(pulov);
	meal.addMeal(kabab);

	Admin admin(ingredient, meal);
	Order o(meal, ingredient);
	int num, select;
	while (1) {
		system("color b");
		cout << "1.Admin" << endl;
		cout << "2.Order" << endl;
		cout << "3.Close Tab" << endl;
		cin >> num;
		while (num != 1 && num != 2 && num != 3) {
			cout << "Input again:";
			cin >> num;
		}
		if (num == 1) {
			admin.signin();
			while (1) {
				system("cls");
				cout << "1.Stock control : " << endl;
				cout << "2.Meal Control : " << endl;
				cout << "3.Show Notification :" << endl;
				cout << "4.Back : " << endl;
				cin >> select;
				while (select != 1 && select != 2 && select != 3 && select != 4) {
					cout << "Input again:";
					cin >> select;
				}
				if (select == 1) {
					admin.stockControl();
				}
				else if (select == 2) {
					admin.mealControl();
				}
				else if (select == 3) {
					admin.showNotf();
					cin.ignore();
					cin.get();
				}
				else if (select == 4) {
					break;
				}
			}
		}
		else if (num == 2)
		{
			while (1) {
				int num_;
				cout << "1.Go Order" << endl;
				cout << "2.Back" << endl;
				cin >> num_;
				while (num_ != 1 && num_ != 2) {
					cout << "Input again:";
					cin >> num_;
				}
				if (num_ == 1) {
					o.Menu();
				}
				else if (num_ == 2) {
					break;
				}
			}
		}
	}
}