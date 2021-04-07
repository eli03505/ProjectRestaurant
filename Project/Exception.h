#pragma once
#include<iostream>
using namespace std;

#pragma region Exception
class Exception {
	string message;
	string source;
	string error_time;
	int line;
public:
	Exception(const string& message, const string& source, int line, string error_time) {
		setMessage(message);
		setSource(source);
		setLine(line);
		setErrorTime(error_time);
	}
	void setMessage(const string& message)
	{
		this->message = message;
	}
	string getMessage()
	{
		return message;
	}
	void setSource(const string& source) {
		this->source = source;
	}
	string getSource()const {
		return source;
	}
	void setLine(const int line) {
		this->line = line;
	}
	int getLine()const {
		return line;
	}
	void setErrorTime(string error_time)
	{
		this->error_time = error_time;
	}
	string getErrorTime()const {
		return error_time;
	}
	void show() {
		cout << "Error : " << getMessage() << endl;
		cout << "Source : " << getSource() << endl;
		cout << "Line : " << getLine() << endl;
		cout << "Time : " << getErrorTime() << endl;
	}
};
#pragma endregion

class DatabaseException :public Exception
{
public:
	DatabaseException(string message, string source, int line, string error_time) :
		Exception(message, source, line, error_time) {}
};
#pragma once
