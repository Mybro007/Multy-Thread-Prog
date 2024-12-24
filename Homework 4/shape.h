#pragma once
#include<string>

enum class figure
{
	line = 0,
	sqr,
	cube,
	circle,
	cylinder
};

class Shape
{
protected:
	int type=0;
	int S = 0;
	int V = 0;
public:
	Shape() = default;

	virtual void shift(int m, int n, int k) = 0;
	virtual void scaleX(int a) = 0;
	virtual void scaleY(int d) = 0;
	virtual void scaleZ(int e) = 0;
	virtual void scale(int s) = 0;
	int getType();
};

class Line : public Shape
{
public:
	int x1 = 0;
	int y1 = 0;
	int x2 = 0;
	int y2 = 0;
	Line(int _x1, int _y1, int _x2, int _y2);
	void shift(int m, int n, int k) override;
	void scaleX(int a) override;
	void scaleY(int d) override;
	void scaleZ(int e) override;
	void scale(int s) override;

};

class Sqr : public Shape
{
public:
	int x1 = 0, y1 = 0;
	int	x2 = 0, y2 = 0;
	int	x3 = 0, y3 = 0;
	int	x4 = 0, y4 = 0;
	int a = 0, b = 0;
	Sqr(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3, int _x4, int _y4);
	void shift(int m, int n, int k) override;
	void scaleX(int a) override;
	void scaleY(int d) override;
	void scaleZ(int e) override;
	void scale(int s) override;
};

class Cube : public Shape
{
public:
	int x1 = 0, y1 = 0, z1 = 0;
	int	x2 = 0, y2 = 0, z2 = 0;
	int	x3 = 0, y3 = 0, z3 = 0;
	int	x4 = 0, y4 = 0, z4 = 0;
	int	x5 = 0, y5 = 0, z5 = 0;
	int	x6 = 0, y6 = 0, z6 = 0;
	int	x7 = 0, y7 = 0, z7 = 0;
	int	x8 = 0, y8 = 0, z8 = 0;
	int a = 0, b = 0, c = 0;
	Cube(int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, int _x3, int _y3, int _z3, int _x4, int _y4, int _z4, int _x5, int _y5, int _z5, int _x6, int _y6, int _z6, int _x7, int _y7, int _z7, int _x8, int _y8, int _z8);
	void shift(int m, int n, int k) override;
	void scaleX(int a) override;
	void scaleY(int d) override;
	void scaleZ(int e) override;
	void scale(int s) override;
};

class Circle : public Shape
{
public:
	int x1 = 0;
	int y1 = 0;
	int R = 0;

	Circle(int _x1, int _y1, int _R);
};

class Cilinder : public Shape
{
public:
	int x1 = 0;
	int y1 = 0;
	int R = 0;
	int height = 0;
	
	Cilinder(int _x1, int _y1, int _R, int _height);
};