#include "shapelist.h"
#include <algorithm>

void ShapeList::moveToBack(Shape *sp)
{

    auto it = find(this->begin(), this->end(), sp);
    if (it != this->end())
    {
        rotate(this->begin(), it, it + 1);
    }
    else
    {
        error("error from ShapeList::moveToFront: shape does not in list");
    }
};
void ShapeList::moveToFront(Shape *sp)
{
    auto it = find(this->begin(), this->end(), sp);
    if (it != this->end())
    {
        rotate(it, it + 1, it + 2);
    }
    else
    {
        error("error from ShapeList::moveToFront: shape does not in list");
    }
};
void ShapeList::moveForward(Shape *sp)
{
    auto it = find(this->begin(), this->end(), sp);
    if (it != this->end())
    {
        rotate(it - 1, it, it + 1);
    }
    else
    {
        error("error from ShapeList::moveToFront: shape does not in list");
    }
};
void ShapeList::moveBackward(Shape *sp)
{
    auto it = find(this->begin(), this->end(), sp);
    if (it != this->end())
    {
        rotate(it - 1, it, it + 1);
    }
    else
    {
        error("error from ShapeList::moveToFront: shape does not in list");
    }
};

void ShapeList::draw(GWindow &gw) const
{
    for (Shape *sp : *this)
    {
        sp->draw(gw);
    }
};

Shape* ShapeList::getShapeAt(double x,double y){
    for(Shape* sp:*this){
        if(sp->contains(x,y)){
            return sp;
        }
    }
return nullptr;
};