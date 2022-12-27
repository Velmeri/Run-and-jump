#pragma once

class Obstacles {
private:
	double height_;
	double distance_;
public:
	Obstacles() : height_(0.0), distance_(0.0) {}
	Obstacles(double height, double distance) : height_(height), distance_(distance) {}

	double getHeight() const {
		return height_;
	}

	void setHeight(double height_and) {
		this->height_ = height_and;
	}

	double getDistance() const {
		return distance_;
	}

	void setDistance(double length) {
		this->distance_ = length;
	}
};

class Treadmill : public Obstacles {
public:
	Treadmill(double length) : Obstacles(0.0, length) {}
};

class Wall : public Obstacles {
public:
	Wall(double height) : Obstacles(height, 0.0) {}
};