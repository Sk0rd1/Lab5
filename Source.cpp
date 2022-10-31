#include <iostream>
using namespace std;

class Square
{
	float side;
public:
	Square();
	Square(float);
	~Square();
	float getSide();
	void setSide(float);
	void print();
	Square operator +(const Square& other)
	{
		Square temp;
		temp.side = sqrt(this->side * this->side + other.side * other.side);
		return temp;
	};
	Square operator ++()
	{
		this->side++;
		return *this;
	};
	friend ostream& operator <<(ostream &out, const Square &other);
};

ostream& operator <<(ostream& out, const Square& other)
{
	cout << " Side = " << other.side << "   Square = " << other.side * other.side << "\n";
	return out;
}

Square::Square()
{
	this->side = 0;
}

Square::Square(float i)
{
	this->side = i;
}

Square::~Square(){}

float Square::getSide()
{
	return this->side;
}

void Square::setSide(float i)
{
	this->side = i;
}

void Square::print()
{
	cout << " Side = " << side << "   Square = " << side * side << "\n";
}

int main()
{
	Square a;
	cout << a;
	++a;
	cout << a;
	Square b(2);
	Square c = a + b;
	cout << c;

}