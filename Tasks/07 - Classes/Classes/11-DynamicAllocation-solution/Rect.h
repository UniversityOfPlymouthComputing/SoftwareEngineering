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
        //Now they are pointers
        string* fileName = nullptr;
        ofstream* outputStream = nullptr;

    private:
        void updateArea() {
            //Recalculate
            area = width * height;

            //Log IF the file has been opened
            if (outputStream) {
                if (outputStream->is_open()) {
                    (*outputStream) << "width: " << width << ", height: " << height << ", area: " << area << endl;
                }
            } 
        }
    public:
        void updateArea(int w, int h)
        {
            width = w;
            height = h;
            updateArea();
        }

        //Constructor - v1 (has an additional parameter used for file logging)
        Rect(double w, double h, string id) {
            //Log message to terminal
            cout << "Constructor running for " << id << endl;

            //Allocate memory
            fileName = new string(id + ".log");
            if (fileName) {
                outputStream = new ofstream(*fileName);
            }
           
            //Defensive stategy - even if unlikely
            if (!fileName || !outputStream) {
                throw exception("Out of memory");
            }

            //Open file (for append if it exists)
            outputStream->open(*fileName, ios::app);
            if (!outputStream->is_open()) {
                cerr << "Cannot create file " << *fileName << endl;
                throw exception("Cannot create file");
            }

            //Initialise members
            width = w;
            height = h;
            updateArea();
        }

        // Constructor - v2 (As no file ID is provided, no file logging will be performed)
        Rect(double w, double h) {
            cout << "Constructor running" << endl;

            //Initialise members
            width = w;
            height = h;
            updateArea();
        }

        //Destructor
        ~Rect() {
            cout << "Destructor running";

            //Only close a file if it has been opened
            if (outputStream) {
                if (outputStream->is_open()) {
                    outputStream->close();
                    cout << " for " << *fileName;
                }
            }

            cout << endl;

            //Free up memory
            if (outputStream) {
                delete outputStream;
                outputStream = nullptr;
            }
            if (fileName) {
                delete fileName;
                fileName = nullptr;
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
            if (fileName) {
                cout << *fileName << ", ";
            }
            cout << "Width: " << width << ", Height : " << height << ", Area : " << area << endl;
        }
    };
}


