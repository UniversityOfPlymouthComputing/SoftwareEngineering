#include "Rect_t.h"
#include <iostream>
using namespace std;

static void updateArea(Rect_t&);

Rect_t CreateRect(float w, float h) {
    Rect_t res;
    res.width = w;
    res.height = h;
    updateArea(res);
    return res;
};

//Only visible inside this file
static void updateArea(Rect_t& ref) {
    ref.area = ref.width * ref.height;
}

void setWidth(Rect_t& ref, int w) {
    if (ref.width != w) {
        ref.width = w;
        updateArea(ref);
    }
}

void setHeight(Rect_t& ref, int h) {
    if (ref.height != h) {
        ref.height = h;
        updateArea(ref);
    }
}

double getArea(Rect_t& ref) {
    return ref.area;
}

void display(Rect_t& ref) {
    cout << "Width: " << ref.width << ", Height: " << ref.height << ", Area: " << ref.area << endl;
}