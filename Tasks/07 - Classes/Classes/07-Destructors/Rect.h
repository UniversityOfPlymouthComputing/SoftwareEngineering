#pragma once
#include <iostream>
#include <fstream>

class Rect
{
    //Private section - only class Rect member functions can access these
private:
    float width;
    float height;
    double area;
    std::ofstream op;

    void updateArea() {
        area = width * height;
    }

public:
    //Constructor - always called when a new object is created
    Rect(float w, float h, std::string name) {
        width = w;        
        height = h;       
        updateArea();
    }

    //Setter
    void setHeight(float h) {
        if (height != h) {
            height = h;
            updateArea();
        }
    }

    //Setter for Width
    void setWidth(float w) {
        if (width != w) {
            width = w;
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






