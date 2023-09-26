#ifndef _shape_h
#define _shape_h

#include <string>
#include "gwindow.h"

class Shape
{
public:
    void setLocation(double x, double y);
    void move(double x, double y);
    void setColor(std::string color);
    virtual void draw(GWindow &gw) = 0;
    virtual bool contains(double x, double y) = 0;

protected:
    Shape();
    std::string color;
    double x, y;
};

class Line : public Shape
{
public:
    Line(double x1, double y1, double x2, double y2);

    virtual void draw(GWindow &gw);
    virtual bool contains(double x, double y);

private:
    double dx;
    double dy;
};

class Rect : public Shape
{
public:
    Rect(double x, double y, double width, double height);
    virtual void draw(GWindow &gw);
    virtual bool contains(double x, double y);

private:
    double width, height;
};

class Oval : public Shape
{
public:
    Oval(double x, double y, double width, double height);
    virtual void draw(GWindow &gw);
    virtual bool contains(double x, double y);

private:
    double width, height;
};

class Square : public Shape
{
public:
    Square(double x, double y, double size);
    virtual void draw(GWindow &gw);
    virtual bool contains(double x, double y);

private:
    double size;
};

class Square : public Shape
{
public:
    /*
    x,y are the coordinates of the upper left corner
    size is the size of square
    four coordinates would be
    (x,y)-----------------------------(x+sqrt(size),y)
    |                                               |
    |                                               |
    |                                               |
    |                                               |
    |                                               |
    |                                               |
    |                                               |
    |                                               |
    |                                               |
    |                                               |
    |                                               |
    |                                               |
    |                                               |
    |                                               |
    |                                               |
    |                                               |
    (x,y+sqrt(size))-------(x+sqrt(size),y+sqrt(size))

    */
    Square(double x, double y, double size);
    virtual void draw(GWindow &gw);
    virtual bool contains(double x, double y);

private:
    double size;
};

#endif