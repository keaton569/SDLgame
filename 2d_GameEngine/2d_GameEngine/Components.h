#pragma once
#include "ECS.h"

class PositionComponent : public Component
{
public:
	int x() { return xpos; }
	int y() { return ypos; }

	void init() override {
	
		xpos = 0;
		ypos = 0;

	}
	void setPosition(int x, int y) {
	
		xpos = x;
		ypos = y;
	
	}


	void update() override {
	
		xpos++;
		ypos++;
	
	}

private:
	int xpos;
	int ypos;
};

