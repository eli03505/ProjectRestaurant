#pragma once
#include<iostream>
#include"Client.h"
#include"Notification.h"
#include"Exception.h"
#include"Stock.h"
#include <synchapi.h>
using namespace std;

enum StockControl
{
	DeleteIngredients = 1, ShowAllIngredient, ShowIngedientById, Increase, Decrease,
	UpdateIngredient, Back
};

enum MealControl
{
	DeleteMeal = 1, DeleteAllMeal, UpdateMeal, ShowMealById, ShowAllMeals,
	FindMealById, BackMeal
};

#pragma region Admin
class Admin
{
	Stock a;
	Kitchen b;
	const string username_admin = "fsda";
	const string password = "12012";
	vector<NotIngredient> ingredients;
public:
	Admin(Stock a, Kitchen b)
	{
		this->a = a;
		this->b = b;
	}
	void deleteNotfIngredient()
	{
		ingredients.push_back(NotIngredient("Ingredient deleted"));
	}
	void increaseNot()
	{
		ingredients.push_back(NotIngredient("Ingredined increase"));
	}

	void decreaseNotf()
	{
		ingredients.push_back(NotIngredient("Ingredient decrease:"));
	}

	void updateIngNotf()
	{
		ingredients.push_back(NotIngredient("Ingredient Updated:"));
	}

	void deletenotNotfIngredient()
	{
		ingredients.push_back(NotIngredient("Ingredient cant be deleted"));
	}

	void increasenotNot()
	{
		ingredients.push_back(NotIngredient("Ingredient cant be increased"));
	}

	void decreasenotNot()
	{
		ingredients.push_back(NotIngredient("Ingredient cant be decrease:"));
	}

	void updateIngnotNot()
	{
		ingredients.push_back(NotIngredient("Ingredient cant be Updated:"));
	}

	void deleteMealNot()
	{
		ingredients.push_back(NotIngredient("Meal deleted"));
	}

	void deleteNotMealNot()
	{
		ingredients.push_back(NotIngredient("Meal cant be deleted"));
	}

	void updateMealNot()
	{
		ingredients.push_back(NotIngredient("Meal updated"));
	}

	void updateNotMealNot()
	{
		ingredients.push_back(NotIngredient("Meal cant be updated"));
	}

	void showNotfIngredient()
	{
		for (auto i = ingredients.begin();
			i != ingredients.end(); i++)
		{
			i->printMessage();
		}
	}
	bool login(string username, string password)
	{

		if (username == username_admin && password == password)
		{
			system("color a");
			return true;
		}
		else if (username == username_admin && password != password)
		{
			cout << "Password is incorrect:" << endl;
			return false;
		}
		else if (username != username_admin && password == password)
		{
			cout << "Username is incorrect:" << endl;
			return false;
		}
		else if (username != username_admin && password != password)
		{
			cout << "Username and password are incorrect:" << endl;
			return false;
		}
	}
	void signin() {
		while (1) {
			system("cls");
			string username, password;
			cout << "Input username:";
			cin >> username;
			cout << "Password:";
			cin >> password;

			if (login(username, password)) {
				break;
			}
			else
			{
				cout << "Input again" << endl;
			}
		}
	}
	void stockControl()
	{
		while (1) {
			system("color b");
			cout << "1.Delete Ingredient:" << endl;
			cout << "2.Show All Ingredients:" << endl;
			cout << "3.Show Ingredient by id:" << endl;
			cout << "4.Increase ingredient:" << endl;
			cout << "5.Decrease ingredient:" << endl;
			cout << "6.Update ingredient:" << endl;
			cout << "7.Back:" << endl;
			int choice;
			cout << "Choice:";
			cin >> choice;
			switch (choice)
			{
			case DeleteIngredients: {
				try {
					int delet;
					cout << "Input id:";
					cin >> delet;
					a.deleteIngredientById(delet);
					deleteMealNot();
				}
				catch (Exception ex) {
					deletenotNotfIngredient();
					ex.show();
				}
				cin.ignore();
				cin.get();
				break;
			}
			case ShowAllIngredient:
				try {
					a.showAllIngredients();
				}
				catch (Exception ex)
				{
					ex.show();
				}
				cin.ignore();
				cin.get();
				break;
			case ShowIngedientById: {
				try
				{
					int id_;
					cout << "Input id:";
					cin >> id_;
					a.showIngredientById(id_);
				}
				catch (Exception ex)
				{
					ex.show();
				}
				cin.ignore();
				cin.get();
				break;
			}
			case Increase:
				try {
					int id_increase, amount_increase;
					cout << "Input id:";
					cin >> id_increase;
					cout << "Amount:";
					cin >> amount_increase;
					a.increment(id_increase, amount_increase);
					increaseNot();
				}
				catch (Exception ex) {
					increasenotNot();
					ex.show();
				}
				cin.ignore();
				cin.get();
				break;
			case Decrease:
				try {
					int id_decrease, amount_decrease;
					cout << "Input id:";
					cin >> id_decrease;
					cout << "Amount:";
					cin >> amount_decrease;
					a.decrement(id_decrease, amount_decrease);
					decreaseNotf();
				}
				catch (Exception ex) {
					decreasenotNot();
					ex.show();
				}
				cin.ignore();
				cin.get();
				break;
			case UpdateIngredient: {
				try {
					int update;
					cout << "Input id:";
					cin >> update;
					a.updateIngredientById(update);
					updateIngNotf();
				}
				catch (Exception ex) {
					updateIngnotNot();
					ex.show();
				}
				cin.ignore();
				cin.get();
				break;
			}
			case Back:
				return;
				break;
			}
		}
	}
	void mealControl() {
		while (1) {
			system("color 2");
			cout << "1.Delete Meal :" << endl;
			cout << "2.Delete All Meal :" << endl;
			cout << "3.Update Meal :" << endl;
			cout << "4.Show Meal by Id :" << endl;
			cout << "5.Show All Meal :" << endl;
			cout << "6.Search meal by name :" << endl;
			cout << "7.Back : " << endl;
			int choice;
			cout << "Choice:";
			cin >> choice;
			switch (choice) {
			case DeleteMeal: {
				try {
					int id;
					cout << "Input id:";
					cin >> id;
					b.deleteMealById(id);
					deleteMealNot();
				}
				catch (Exception ex) {
					deleteNotMealNot();
					ex.show();
				}
				cin.ignore();
				cin.get();
				break;
			}
			case DeleteAllMeal: {
				b.deleteAllMeals();
				cout << "All meals Deleted:" << endl;
				cin.ignore();
				cin.get();
				break;
			}
			case UpdateMeal: {
				try {
					int id;
					cout << "Input id:";
					cin >> id;
					b.updateMealById(id);
					updateMealNot();
				}
				catch (Exception ex)
				{
					updateNotMealNot();
					ex.show();
				}
				cin.ignore();
				cin.get();
				break;
			}
			case ShowMealById: {
				try {
					int id;
					cout << "Input id:";
					cin >> id;
					b.showMealById(id);
				}
				catch (Exception ex) {
					ex.show();
				}
				cin.ignore();
				cin.get();
				break;
			}
			case ShowAllMeals: {
				try {
					b.showAllMeals();

				}
				catch (Exception ex) {
					ex.show();
				}
				cin.ignore();
				cin.get();
				break;
			}
			case FindMealById: {
				string _name;
				cout << "Input name:";
				cin >> _name;
				b.findMealByName(_name);
				cin.ignore();
				cin.get();
				break;
			}
			case BackMeal:
				return;
				break;
			}
		}
	}
	void showNotf() {
		showNotfIngredient();
	}
};
#pragma endregion
