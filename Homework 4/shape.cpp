#define _USE_MATH_DEFINES
#include"shape.h"
#include<cmath>

int Shape::getType()
{
	return type;
}

Line::Line(int _x1, int _y1, int _x2, int _y2)
{
	type = static_cast<int>(figure::line);
	x1 = _x1; y1 = _y1;
	x2 = _x2; y2 = _y2;
}

void Line::shift(int m, int n, int k)
{
	x1 += m;
	x2 += m;
	y1 += n;
	y2 += n;
}

void Line::scaleX(int a)
{
	x1 *= a;
	x2 *= a;
}

void Line::scaleY(int d)
{
	y1 *= d;
	y2 *= d;
}

void Line::scale(int s)
{
	x1 /= s;
	x2 /= s;
	y1 /= s;
	y2 /= s;
}

Sqr::Sqr(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3, int _x4, int _y4)
{
	type = static_cast<int>(figure::sqr);
	x1 = _x1; y1 = _y1;
	x2 = _x2; y2 = _y2;
	x1 = _x3; y1 = _y3;
	x2 = _x4; y2 = _y4;
	a = abs(x1 - x2);
	b = abs(y1 - y2);
	S = a * b; 
}

void Sqr::shift(int m, int n, int k)
{
	x1 += m;
	x2 += m;
	x3 += m;
	x4 += m;
	y1 += n;
	y2 += n;
	y3 += n;
	y4 += n;
}

void Sqr::scaleX(int a)
{
	x1 *= a;
	x2 *= a;
	x3 *= a;
	x4 *= a;
}

void Sqr::scaleY(int d)
{
	y1 *= d;
	y2 *= d;
	y3 *= d;
	y4 *= d; 
}

void Sqr::scale(int s)
{
	x1 /= s;
	x2 /= s;
	x3 /= s;
	x4 /= s;
	y1 /= s;
	y2 /= s;
	y3 /= s;
	y4 /= s;
}

Cube::Cube(int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, int _x3, int _y3, int _z3, int _x4, int _y4, int _z4, int _x5, int _y5, int _z5, int _x6, int _y6, int _z6, int _x7, int _y7, int _z7, int _x8, int _y8, int _z8)
{
	type = static_cast<int>(figure::cube);
	x1 = _x1; y1 = _y1; z1 = _z1;
	x2 = _x2; y2 = _y2; z2 = _z2;
	x3 = _x3; y3 = _y3; z3 = _z3;
	x4 = _x4; y4 = _y4; z4 = _z4;
	x5 = _x5; y5 = _y5; z5 = _z5;
	x6 = _x6; y6 = _y6; z6 = _z6;
	x7 = _x7; y7 = _y7; z7 = _z7;
	x8 = _x8; y8 = _y8; z8 = _z8;
	a = abs(x1 - x2);
	b = abs(y1 - y2);
	c = abs(z1 - z2);
	S = 2 * a * b + 2 * a * c + 2 * b * c;
	V = a * b * c;
}

void Cube::shift(int m, int n, int k)
{
	x1 += m;
	x2 += m;
	x3 += m;
	x4 += m;
	x5 += m;
	x6 += m;
	x7 += m;
	x8 += m;
	y1 += n;
	y2 += n;
	y3 += n;
	y4 += n;
	y5 += n;
	y6 += n;
	y7 += n;
	y8 += n;
	z1 += k;
	z2 += k;
	z3 += k;
	z4 += k;
	z5 += k;
	z6 += k;
	z7 += k;
	z8 += k;
}

void Cube::scaleX(int a)
{
	x1 *= a;
	x2 *= a;
	x3 *= a;
	x4 *= a;
	x5 *= a;
	x6 *= a;
	x7 *= a;
	x8 *= a;
}

void Cube::scaleY(int d)
{
	y1 *= d;
	y2 *= d;
	y3 *= d;
	y4 *= d;
	y5 *= d;
	y6 *= d;
	y7 *= d;
	y8 *= d;
}

void Cube::scaleZ(int e)
{
	z1 *= e;
	z2 *= e;
	z3 *= e;
	z4 *= e;
	z5 *= e;
	z6 *= e;
	z7 *= e;
	z8 *= e;
}

void Cube::scale(int s)
{
	x1 /= s;
	x2 /= s;
	x3 /= s;
	x4 /= s;
	x5 /= s;
	x6 /= s;
	x7 /= s;
	x8 /= s;
	y1 /= s;
	y2 /= s;
	y3 /= s;
	y4 /= s;
	y5 /= s;
	y6 /= s;
	y7 /= s;
	y8 /= s;
	z1 /= s;
	z2 /= s;
	z3 /= s;
	z4 /= s;
	z5 /= s;
	z6 /= s;
	z7 /= s;
	z8 /= s;
}

Circle::Circle(int _x1, int _y1, int _R)
{
	x1 = _x1;
	y1 = _y1;
	R = _R;
	S = M_PI * R * R;
}

Cilinder::Cilinder(int _x1, int _y1, int _R, int _height)
{
	x1 = _x1;
	y1 = _y1;
	R = _R;
	height = _height;
	S = M_PI * R * R + 2 * R * height;
	V = M_PI * R * R * height;
}