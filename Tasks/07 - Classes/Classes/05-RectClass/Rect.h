#pragma once
#include <iostream>

class Rect
{
//Private section - only class Rect member functions can access these
private:
    float width;
    float height;
    double area;

    void updateArea() {
        area = width * height;
    }

public:
    //Constructor - always called when a new object is created
    Rect(float w, float h) {
        this->width = w;        //We can use the this pointer
        height = h;             //Or infer it
        updateArea();
    }

    //Setter
    void setHeight(float h) {
        if (height != h) {
            height = h;
            updateArea();
        }
    }

    //Getter
    double getArea() {
        return area;
    }

    //Display utility function
    void display() {
        std::cout << "Width: " << width << ", Height: " << height << ", Area: " << area << std::endl;
    }

};





