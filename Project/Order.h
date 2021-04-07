#pragma once
#include"Client.h"
#include"Notification.h"

double price = 0;
enum ClientControl {
	ShawAllMeals = 1, Detail, Search, Buy, BBack
};
#pragma region Order
class Order {
	Kitchen kitch;
	Stock stock;
	vector<Notification> order;
public:
	Order(Kitchen kitch, Stock s) {
		this->kitch = kitch;
		this->stock = stock;
	}
	void notfAddIng() {
		order.push_back(NotIngredient("Customer add new ingredient"));
	}
	bool checkAmount(int id, int amount) {
		Meal item = kitch.getMealById(id);
		if (id > kitch.getMeal().size()) {
			throw Exception("There is not meal here", __FILE__, __LINE__, __TIME__);
		}
		else {
			if (amount > item.getAmount()) {
				return false;
			}
			return true;
		}
	}
	void buyProduct(int id, int amount) {
		Meal item = kitch.getMealById(id);
		price = price + item.getPrice() * amount;
		item.setAmount(item.getAmount() - amount);
	}
	void addMoreIngredient(int id) {
		Ingredient item = stock.getIngredientById(id);
		if (item.getId() == NULL || item.getAmount() == 0) {
			throw DatabaseException("We can't add this ingredient", __FILE__, __LINE__, __TIME__);
		}
		else {
			price = price + item.getingPrice();
			item.setAmount(item.getAmount() - 1);
			notfAddIng();
		}
	}
	void Menu() {
		while (1) {
			system("color 3");
			cout << "1.Show all Meals:" << endl;
			cout << "2.Show detail:" << endl;
			cout << "3.Find Meal:" << endl;
			cout << "4.Buy:" << endl;
			cout << "5.Back:" << endl;
			int choice;
			cout << "Choice:";
			cin >> choice;
			switch (choice) {
			case ShawAllMeals: {
				try {
					kitch.showAllMeals();
				}
				catch (Exception ex) {
					ex.show();
				}
				break;
			}
			case Detail: {
				int id;
				cout << "Input ID:";
				cin >> id;
				try {
					kitch.getRecipe(id);
				}
				catch (Exception ex) {
					ex.show();
				}
				break;
			}
			case Search: {
				string name;
				cout << "Input name:";
				cin >> name;
				kitch.findMealByName(name);
				cin.ignore();
				cin.get();
				break;
			}
			case Buy: {
				int id, amount;
				cout << "Meal id:";
				cin >> id;
				while (id > kitch.getMealSize()) {
					cout << "Input again:";
					cin >> id;
				}
				cout << "Amount:";
				cin >> amount;
				try {
					if (checkAmount(id, amount) == true) {
						while (1) {
							char choice;
							cin >> choice;
							try {
								if (choice == 121 || choice == 89)
								{
									int i_id;
									cout << "ID:";
									cin >> i_id;
									addMoreIngredient(i_id);
								}
								else {
									break;
								}
							}
							catch (Exception ex) {
								ex.show();
							}
						}
						buyProduct(id, amount);
						cout << "Bon Appetit!" << endl;
						cout << "Price:" << price << endl;
						char select;
						int rate;
						cout << "Do you want to Rate?Yes or No:";
						cin >> select;
						if (select == 80 || select == 100) {
							cout << "Input Rate (0-9)!";
							cin >> rate;
							if (rate < 0 || rate>9)
							{
								cout << "Rate 0-9 please:";
								cin >> rate;
							}
							cout << "Thank rate! " << rate << endl;
						}
					}
					else {
						cout << "There is no food in the kitchen:";
					}
				}
				catch (Exception ex) {
					ex.show();
				}
				break;
			}
			case ClientControl::BBack: {
				return;
			}
			}
		}
	}
};
#pragma endregion