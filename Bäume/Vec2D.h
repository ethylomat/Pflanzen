#ifndef VEC2D_H
#define VEC2D_H

class Vec2D
{
public:
	Vec2D():
		x(0), y(0) {}
    Vec2D(int x, int y) :
        x(x), y(y) {}

	Vec2D operator+(const Vec2D& b) {
		Vec2D c;
		c.x = this->x + b.x;
		c.y = this->y + b.y;
		return c;
	}

	Vec2D& operator+=(const Vec2D& b){
		this->x += b.x;
		this->y += b.y;
		return *this;
	}

	bool operator==(const Vec2D& rhs){
		return (this->x != rhs.x || this->y != rhs.y);
	}
	bool operator!=(const Vec2D& rhs){
		return !(*this == rhs);
	}


	int x;
	int y;
};

#endif
