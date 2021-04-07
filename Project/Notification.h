#pragma once
#include<iostream>
using namespace std;

#pragma region Notification
class Notification {
	string text;
	string created_date;
	int not_id;
public:
	static int id;
	Notification() : text(""), created_date("") {}

	Notification(const string& text)
	{
		this->not_id = ++id;
		setText(text);
		setCreatedTime();
	}
	void setText(const string& text)
	{
		this->text = text;
	}
	string getText() const {
		return this->text;
	}
	void setCreatedTime()
	{
		this->created_date = __TIME__;
	}
	int getId() {
		return not_id;
	}
	string getCreatedTime() const {
		return this->created_date;
	}
	void printMessage();
	~Notification() {}

};
#pragma endregion
int Notification::id = 0;

#pragma region NotfIngredient
class NotIngredient :public Notification {
public:
	NotIngredient(string text) :Notification(text) {}
	void printMessage()
	{
		cout << "****Notification****" << endl;
		cout << "ID:" << getId() << endl;
		cout << "Text:" << getText() << endl;
		cout << "Time:" << getCreatedTime() << endl;
	}
};
#pragma endregion