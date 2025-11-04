//
//  main.cpp
//  Marius_Shaped_Inheritence
//
//  Created by Soren on 5/19/24.
// @author marius@chapman.edu

#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"

int main() {
    Shape* p_shapes[2];

    p_shapes[0] = new Circle(2.0);
    p_shapes[1] = new Rectangle(3.0, 2.0);

    for (int i = 0; i < 2; ++i) {
        p_shapes[i]->displayProperties();
        std::cout << "Area: " << p_shapes[i]->area() << "\n";
        std::cout << "Perimeter: " << p_shapes[i]->perimeter() << "\n";

        p_shapes[i]->scale(2.0);

        p_shapes[i]->displayProperties();
        std::cout << "Area: " << p_shapes[i]->area() << "\n";
        std::cout << "Perimeter: " << p_shapes[i]->perimeter() << "\n";
    }

    delete p_shapes[0];
    delete p_shapes[1];

    return 0;
}
