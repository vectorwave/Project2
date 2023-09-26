#include <string>
#include <cmath>
#include "gwindow.h"
#include "shape.h"
using namespace std;

Shape::Shape() {
	setColor("Black");
}

void Shape::setLocation(double x, double y) {
	this->x = x;
	this->y = y;
}

void Shape::move(double dx, double dy) {
	x += dx;
	y += dy;
}

void Shape::setColor(string color){
	this->color = color;
}

Line::Line(double x1,double y1,double x2,double y2){
	this->x = x1;
	this->y = y1;
	this->dx = x2-x1;
	this->dy = y2-y1;
}

void Line::draw(GWindow& gw){
	gw.setColor(color);
	gw.drawLine(x,y,x+dx,y+dy);
}


/*
formula for distance of a point and a line
|A*px + B*py + C| / sqrt(A^2 + B^2)
where A = y2 - y1, B = x1 - x2, C = (y2-y1)*x1 - (x2-x1)*y1 
*/
bool Line::contains(double x, double y){
	
	double C = dy*this->x - dx*this->y;
	double distance = abs(dy*x + dx*y + C)/sqrt(dy*dy+dx*dx);
	return distance < 0;
}

Rect::Rect(double x,double y,double width,double height){
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

void Rect::draw(GWindow& gw){
	gw.setColor(color);
	gw.fillRect(x,y,width,height);
}

bool Rect::contains(double x,double y){
	return x>=this->x && x<=this->x+width && y>=this->y && y<=this->y+height;
}

Oval::Oval(double x,double y,double width,double height){
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

void Oval::draw(GWindow& gw){
	gw.setColor(color);
	gw.fillOval(x,y,width,height);
}

bool Oval::contains(double x,double y){
	
	double a = this->height/2;
	double b = this->width/2;
	double dx = x - this->x - b;
	double dy = y - this->y - a;
	
	return (dx*dx)/(a*a) + (dy*dy)/(b*b) <= 1;
}

Square::Square(double x, double y, double size)
{
    setLocation(x, y);
    this->size = size;
}

void Square::draw(GWindow &gw)
{
    gw.setColor(color);
	auto length = sqrt(size);
    gw.fillRect(x, y, length, length);
}

bool Square::contains(double x, double y){
	double length = sqrt(size);
	return x >= this->x && x <= this->x + length && y >= this->y && y <= this->y + length;