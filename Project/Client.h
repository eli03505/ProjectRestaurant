#pragma once
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include"Notification.h"
#include"Exception.h"
using namespace std;

#pragma region Ingredient
class Ingredient {
protected:
	string name;
	double fats;
	double protein;
	double carbogydrates;
	int kcal;
	int amount;
	double ingPrice;
	int id;
public:
	static int myid;
	Ingredient() = default;
	Ingredient(const string& name, double fats, double protein, double carbogydrates,
		int kcal, double ingPrice, int amount) {
		setName(name);
		setFat(fats);
		setProtein(protein);
		setCarbogydrates(carbogydrates);
		setKcal(kcal);
		setingPrice(ingPrice);
		setAmount(amount);
	}
	Ingredient(const Ingredient& other) {
		setId(other.id);
		setName(other.name);
		setFat(other.fats);
		setProtein(other.protein);
		setCarbogydrates(other.carbogydrates);
		setKcal(other.kcal);
		setingPrice(other.ingPrice);
		setAmount(other.amount);
	}
	void setId(const int id) {
		this->id = id;
	}
	int getId()const {
		return id;
	}
	string getName() const {
		return name;
	}
	void setName(const string& name) {
		this->name = name;
	}
	double getFat() const {
		return fats;
	}
	void setFat(double fats)
	{
		this->fats = fats;
	}
	double getProtein() const
	{
		return protein;
	}
	void setProtein(double protein)
	{
		this->protein = protein;
	}
	double getCarbogydrates() const
	{
		return carbogydrates;
	}
	void setCarbogydrates(double carbogydrates)
	{
		this->carbogydrates = carbogydrates;
	}
	int getKcal() const
	{
		return kcal;
	}
	void setKcal(int kcal)
	{
		this->kcal = kcal;
	}
	int getAmount() const {
		return amount;
	}
	void setAmount(int amount) {
		this->amount = amount;
	}
	double getingPrice() const {
		return ingPrice;
	}
	void setingPrice(double ingPrice) {
		this->ingPrice = ingPrice;
	}
	void show() const {
		cout << "****Ingredient****" << endl;
		cout << "Id : " << getId() << endl;
		cout << "Name : " << getName() << endl;
		cout << "Fat : " << getFat() << endl;
		cout << "Protein : " << getProtein() << endl;
		cout << "Carbogydrates : " << getCarbogydrates() << endl;
		cout << "Kcal : " << getKcal() << endl;
		cout << "Ingredient Price :" << getingPrice() << endl;
		cout << "Amount : " << getAmount() << endl;
	}
};
#pragma endregion

#pragma region Meal
class Meal {
	string name;
	string category;
	double rating;
	double price;
	double tax;
	vector<Ingredient> ingredients;
	int meal_id;
	int amount;
public:
	static int id;
	Meal() = default;
	Meal(const string& name, const string& category, double rating, double price,
		double tax, int amount) {
		meal_id = ++id;
		setName(name);
		setCategory(category);
		setRating(rating);
		setPrice(price);
		setTax(tax);
		setAmount(amount);
	}
	void setMealId(const int id) {
		this->id = id;
	}
	int getMealId()const {
		return id;
	}
	string getName() const {
		return name;
	}
	void setName(const string& name) {
		this->name = name;
	}
	string getCategory() const
	{
		return category;
	}
	void setCategory(const string& category)
	{
		this->category = category;
	}
	double getRating() const
	{
		return rating;
	}
	void setRating(double rating)
	{
		this->rating = rating;
	}
	double getPrice() const
	{
		return price;
	}
	void setPrice(double price)
	{
		this->price = price;
	}
	double getTax() const
	{
		return tax;
	}
	void setTax(double tax)
	{
		this->tax = tax;
	}
	int getAmount() const
	{
		return amount;
	}
	void setAmount(int amount)
	{
		this->amount = amount;
	}
	void addIngredient(Ingredient& ingredient)
	{
		ingredients.push_back(ingredient);
	}
	void deleteMeal(int id)
	{
		ingredients.erase(ingredients.begin() + id);
	}
	void deleteAll()
	{
		ingredients.clear();
	}
	vector<Ingredient> getIngredientById(int id)
	{
		vector<Ingredient> ing;
		for (auto i = ingredients.begin();
			i != ingredients.end(); i++)
		{
			if (id == i->getId())
			{
				return ing;
			}
		}
	}
	void printRecipe() {
		for (auto i = ingredients.begin(); i != ingredients.end(); i++)
		{
			i->show();
		}
	}
	void showMeal() const {
		cout << "ID:" << meal_id << endl;
		cout << "Name:" << getName() << endl;
		cout << "Category:" << getCategory() << endl;
		cout << "Rating:" << getRating() << endl;
		cout << "Price:" << getPrice() << endl;
		cout << "Tax:" << getTax() << endl;
		cout << "Amount:" << getAmount() << endl;
	}
};
#pragma endregion
int Meal::id = 0;

#pragma region Stock
class Stock {
	vector<Ingredient> ingredients;
	vector<NotIngredient> notf_ingredients;
public:
	Ingredient* ingredient;
	Stock() :ingredient(nullptr) {}
	Ingredient getIngredientById(int id) {
		return ingredients.at(id - 1);
	}
	int getIngredientSize() {
		return ingredients.size();
	}
	void increment(int id, int amount) {
		if (id > ingredients.size())
		{
			throw DatabaseException("We cant increase amount!", __FILE__, __LINE__, __TIME__);
		}
		int new_amount = ingredients[id - 1].getAmount() + amount;
		ingredients[id - 1].setAmount(new_amount);
	}
	void decrement(int id, int amount) {
		if (id > ingredients.size() || amount > ingredients[id - 1].getAmount())
		{
			throw DatabaseException("We cant decrease amount!", __FILE__, __LINE__, __TIME__);

		}
		int new_amount = ingredients[id - 1].getAmount() - amount;
		ingredients[id - 1].setAmount(new_amount);
	}
	void deleteAllIngredients() {
		ingredients.clear();
	}
	void deleteIngredientById(int id)
	{
		if (id > ingredients.size()) {
			throw DatabaseException("There is no ingredient here", __FILE__, __LINE__, __TIME__);
		}
		ingredients.erase(ingredients.begin() + id - 1);
	}
	void findIngredientByName(string name) {
		for (auto i = ingredients.begin(); i != ingredients.end(); i++) {
			if (name == i->getName()) {
				i->show();
			}
		}
	}
	void deleteNotfIngredient() {
		notf_ingredients.push_back(NotIngredient("Ingredient deleted"));
	}
	void increaseNotf() {
		notf_ingredients.push_back(NotIngredient("Ingredient increase"));
	}
	void decreaseNotf() {
		notf_ingredients.push_back(NotIngredient("Ingredient decrease:"));
	}
	void showNotfIngredient() {
		auto i = notf_ingredients.begin();
		i != notf_ingredients.end();
		i->printMessage();
	}
	void updateIngredientById(int id)
	{
		if (id > ingredients.size())
		{
			throw DatabaseException("Has no ingredients", __FILE__, __LINE__, __TIME__);
		}
		string name;
		double fats, protein, carbogydrates;
		int kcal, n;
		while (1) {
			system("color Green");
			cout << "1.Name : " << endl;
			cout << "2.Fats : " << endl;
			cout << "3.Protein : " << endl;
			cout << "4.Karbohidrat : " << endl;
			cout << "5.Kcal : " << endl;
			cout << "Which field do you want to update : ";
			cin >> n;
			while (n < 1 || n>5)
			{
				cout << "Input again : " << endl;
				cin >> n;
			}
			switch (n)
			{
			case 1:
				cout << "Updating name:" << endl;
				cout << "Name:";
				cin >> name;
				ingredients[id - 1].setName(name);
				break;
			case 2:
				cout << "Updating Fat:" << endl;
				cout << "Fat:";
				cin >> fats;
				ingredients[id - 1].setFat(fats);
				break;
			case 3:
				cout << "Updating Protein:" << endl;
				cout << "Protein:";
				cin >> protein;
				ingredients[id - 1].setProtein(protein);
				break;
			case 4:
				cout << "Updating Karbohidrat:" << endl;
				cout << "Karbohidrat:";
				cin >> carbogydrates;
				ingredients[id - 1].setCarbogydrates(carbogydrates);
				break;
			case 5:
				cout << "Updating Kcal:" << endl;
				cout << "Kcal:";
				cin >> kcal;
				ingredients[id - 1].setKcal(kcal);
				break;
			}
			char s;
			cout << "Do you want to update again:y/n";
			cin >> s;
			if (s != 120 && s != 80) {
				return;
			}
		}
	}
	void addIngredient(Ingredient ing)
	{
		ingredients.push_back(ing);
	}
	void showIngredientById(int id)
	{
		if (id > ingredients.size())
		{
			throw DatabaseException("No product", __FILE__, __LINE__, __TIME__);
		}
		ingredients[id - 1].show();
	}
	void showAllIngredients() {
		int counter = 0;
		for (auto i = ingredients.begin();
			i != ingredients.end(); i++)
		{
			i->show();
			++counter;
		}
		if (counter == 0)
		{
			throw DatabaseException("No ingredients here", __FILE__, __LINE__, __TIME__);
		}
	}
};
#pragma endregion 

#pragma region Kitchen
class Kitchen {
	vector<Meal> meals;
	Stock s;
	int amount;
	vector<NotIngredient> notf_ingredients;
public:
	Kitchen() :meal(nullptr) {}
	Meal* meal;
	int getAmount() const {
		return amount;
	}
	void deleteAllMeals()
	{
		meals.clear();
	}
	void getRecipe(int id)
	{
		if (id > meals.size()) {
			throw DatabaseException("There is no meals here", __FILE__, __LINE__, __TIME__);
		}
		meals[id - 1].printRecipe();
	}
	void deleteNotfIngredient() {
		notf_ingredients.push_back(NotIngredient("Meal deleted"));
	}
	void deleteMealById(int id) {
		throw DatabaseException("There is no meal here", __FILE__, __LINE__, __TIME__);
		meals.erase(meals.begin() + id - 1);
	}
	void updateMealById(int id)
	{
		throw DatabaseException("There is not meal here!", __FILE__, __LINE__, __TIME__);
		string name, category;
		double rating, price, tax;
		int n;
		while (1)
		{
			system("color b");
			cout << "1.Name : " << endl;
			cout << "2.Category : " << endl;
			cout << "3.Rating : " << endl;
			cout << "4.Price  :" << endl;
			cout << "5.Tax : " << endl;
			cout << "Which field do you want to update:";
			cin >> n;
			while (n < 1 || n>5) {
				cout << "Input again:" << endl;
				cin >> n;
			}
			switch (n) {
			case 1:
				cout << "Updating name:" << endl;
				cout << "Name:";
				cin >> name;
				meals[id - 1].setName(name);
				break;
			case 2:
				cout << "Updating category:" << endl;
				cout << "category:";
				cin >> category;
				meals[id - 1].setCategory(category);
				break;
			case 3:
				cout << "Updating Rating:" << endl;
				cout << "Rating:";
				cin >> rating;
				meals[id - 1].setRating(rating);
				break;
			case 4:
				cout << "Updating Price:" << endl;
				cout << "Price:";
				cin >> price;
				meals[id - 1].setPrice(price);
				break;
			case 5:
				cout << "Updating Tax:" << endl;
				cout << "Tax:";
				cin >> tax;
				meals[id - 1].setTax(tax);
				break;
			}
			char s;
			cout << "Do you want to update again:y/n";
			cin >> s;
			if (s != 121 && s != 89)
				return;
		}
	}
	void findMealByName(string name) {
		int counter = 0;
		for (auto i = meals.begin(); i != meals.end(); i++)
		{
			if (name == i->getName())
			{
				i->showMeal();
				++counter;
			}
		}
		if (counter == 0)
			cout << "There is no meal in here:" << endl;
	}
	void addMeal(Meal meal)
	{
		meals.push_back(meal);
	}
	void showMealById(int id)
	{
		if (id > meals.size())
		{
			throw DatabaseException("There is no product here", __FILE__, __LINE__, __TIME__);

		}
		meals[id - 1].showMeal();
	}
	void showAllMeals()
	{
		int counter = 0;
		for (auto i = meals.begin();
			i != meals.end(); i++)
		{
			i->showMeal();
			++counter;
		}
		if (counter == 0)
		{
			throw DatabaseException("There is no meal here", __FILE__, __LINE__, __TIME__);
		}
	}
	Meal getMealById(int id)
	{
		if (id > meals.size())
		{
			throw DatabaseException("There is no product here", __FILE__, __LINE__, __TIME__);
		}
		else
		{
			return meals.at(id - 1);
		}
	}
	int getMealSize()
	{
		return meals.size();
	}
	vector<Meal> getMeal()
	{
		return meals;
	}
};
#pragma endregion