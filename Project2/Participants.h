#pragma once
#include <string>
#include <iostream>
#include "Obstacles.h"

using namespace std;

class Participant {
private:
	string name_;
	double distance_;
	double height_;
public:
	Participant(string name, double distance, double length) {
		name_ = name;
		distance_ = distance;
		height_ = length;
	}
	string getName() {
		return name_;
	}
	void run() {
		cout << name_ << " is running!" << endl;
	}
	void jump() {
		cout << name_ << " is jumping!" << endl;
	}
	bool overcomeObstacle(Obstacles& obstacle) {
		if (height_ >= obstacle.getHeight() && distance_ >= obstacle.getDistance()) {
			cout << name_ << " can overcome the obstacle!" << endl;
			return 1;
		}
		else {
			cout << name_ << " cannot overcome the obstacle." << endl;
			return 0;
		}
	}
};
	
class Man : public Participant {
private:

public:
	Man(string name) : Participant(name, 20.0, 3.0) {}
};

class Cat : public Participant {
private:

public:
	Cat(string name) : Participant(name, 1.0, 2.0) {}
};

class Robot : public Participant {
private:

public:
	Robot(string name) : Participant(name, 50.0, 30.0) {}
};