#pragma once
#include <iostream>
#include <fstream>

using namespace std;

namespace COMP1000 {

    class Rect {
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
            if (outputStream.is_open()) {
                outputStream << "width: " << width << ", height: " << height << ", area: " << area << endl;
            }
        }
    public:
        //Constructor
        Rect(double w, double h, string id) {
            //Log message to terminal
            cout << "Constructor running for " << id << endl;

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

        //Destructor
        ~Rect() {
            cout << "Destructor running for " << fileName << endl;
            if (outputStream.is_open()) {
                outputStream.close();
            }
        }

        //Setters and getters
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

        // Output to terminal
        void display() {
            cout << fileName << ", Width: " << width << ", Height: " << height << ", Area: " << area << endl;
        }
    };
}


