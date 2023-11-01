#pragma once
#include <iostream>
#include <fstream>

using namespace std;

namespace COMP1000 {

    class Rectangle {
    private:
        double width;
        double height;
        double area;
        string fileName;
        ofstream outputStream;

    private:
        void updateArea() {
            //Recalculate
            area = width * height;
            //Log
            outputStream << "width: " << width << ", height: " << height << ", area: " << area << endl;
        }
    public:
        Rectangle(double w, double h, string id) {
            //Open file (for append if it exists)
            fileName = id + ".log";
            outputStream.open(fileName, ios::app);
            if (!outputStream.is_open()) {
                cerr << "Cannot create file " << fileName << endl;
                throw exception("Cannot create file");
            }

            width = w;
            height = h;
            updateArea();
        }

        ~Rectangle() {
            cout << "Closing " << fileName << endl;
            outputStream.close();
        }

        double getArea() {
            return area;
        }

        void setHeight(double h)
        {
            if (height != h) {
                height = h;
                updateArea();
            }
        }

        void setWidth(double w) {
            if (width != w) {
                width = w;
                updateArea();
            }
        }
    };
}


