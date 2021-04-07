#pragma once
#include"Client.h"
#include"Notification.h"

#pragma region Not
class Not {
	vector<Notification> not_;
public:
	Not() :not_(NULL) {}
	void addNotf(Notification notf) {
		not_.push_back(notf);
	}
	void show() {
		for (auto i = not_.begin(); i != not_.end(); i++) {
			i->printMessage();
		}
	}
	void deleteAll() {

	}
};
#pragma endregion