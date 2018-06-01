#include "Rectangle.hpp"
using namespace std;

Rectangle::Rectangle()
{

}

Rectangle::Rectangle(int corner_x, int corner_y)
{
	x = corner_x;
	y = corner_y;
	nom = "Rect" + to_string(x) +"-" + to_string(y);
	is_image = 1; // N'a pas d'image à la création
}
/*
int get_x(Rectangle *R)
{
	return R->x;
	
}

int get_y(Rectangle *R)
{
	return R->y;
}

int get_is_image(Rectangle* R)
{
	return R->is_image;
}

void set_is_image(Rectangle* R, int is_im)
{
	R->is_image = is_im;
}*/

Rectangle::~Rectangle()
{
	cout<<"Destructeur Rectangle"<<endl;
}