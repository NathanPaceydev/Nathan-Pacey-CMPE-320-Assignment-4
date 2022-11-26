/* Assignment 4 - Structural Improvements
 *
 * Implementation file: ShapesGood.cpp
 * Student: Nathan Pacey	netid:18njp		Student Number:20153310		Class: CMPE320
 *
 */

#include <iostream>
using namespace std;
#include <string>
#include "ShapesGood.h"


// ################### SHAPE CLASS #######################
// Top class constructor
Shape::Shape(const int length, const int width, string outLineColor) : length(length), width(width), outLineColor(outLineColor) { }

// constructor for copying
Shape::Shape(const Shape& shape){
    // call attributes
    this->length = shape.getLength();
    this->width = shape.getWidth();
    this->outLineColor = shape.getLineColor();
}

// ******** GETTERS **********
int Shape::getLength() const { 
    return length; 
}

int Shape::getWidth() const { 
    return width; 
}

// included outline color here since all shapes have it
string Shape::getLineColor() const {
    return outLineColor;
}

Shape::~Shape() {} //destructor

// comparable overload method
Shape& Shape::operator=(const Shape&){
    this->length = getLength();
    this->width = getWidth();
    return *this;
}



// ################ FILLABLE CLASS ###################
// Fillable constructor
Fillable::Fillable(const string fillColor) {
    this->fillColor = getFill(); // call attribute
}

//************ Getters ********************
string Fillable::getFill() { return fillColor; }

// 'draw' the filling
void Fillable::drawFill(){ cout << " With " << getFill() << " fill."; }

Fillable::~Fillable(){} // destructor



// ########### TEXT CLASS ##########################################
// Text constructor
Text::Text(string text) {
    this->message = getText(); // call attribute
}

// **** Getter *****
string Text::getText() {
    return message;
}

// 'draw' the TEXT
void Text::drawText() {
    cout << " Containing the text: \"" << getText() << "\".";
}

Text::~Text(){} // destructor



// ################ SQUARE CLASS EXTENDS SHAPE ###############################
Square::Square(const int length, const int width, const string outLineColor) : Shape(length, width, outLineColor) { } // constructor

void Square::draw() {  // output the square
    cout << "\nDrawing a " + getLineColor() + " square."; 
}

Square::~Square() {} //destructor



// ################ CIRCLE CLASS EXTENDS SHAPE ################################
Circle::Circle(int length, int width, string outlineColor) : Shape(length, width, outlineColor) { } // constructor

// 'draw' the Circle
void Circle::draw() {
    cout << "\nDrawing a " + getLineColor() + " circle.";
}

Circle::~Circle() {} // destructor



// ##################### ARC CLASS EXTENDS SHAPE #################################
Arc::Arc(int length, int width, string outlineColor) : Shape(length, width, outlineColor) { } // constructor

// 'draw' the Arc
void Arc::draw() {
    cout << "\nDrawing a " + getLineColor() + " arc.";
}

Arc::~Arc() {} // destructor



// ################### FILLEDSQUARE CLASS EXTENDS SQUARE AND FILLED ###############################
FilledSquare::FilledSquare(const int length, const int width, const string outLineColor, const string fillColor) : Square(length, width, outLineColor), Fillable(fillColor) {}

// 'draw' filled square
void FilledSquare::filledSquaredraw() {
    // reduce code by calling other classes methods
    draw(); // this refers the Square::draw
    drawFill(); // don't need to include Fillable::drawFill() since FilledSquare Extends Fillable and no other methods in class
}

FilledSquare::~FilledSquare() {} // destructor



// ################# FILLED TEXT SQUARE EXTENDS SQUARE, FILLED and TEXT ###########################
// constructor
FilledTextSquare::FilledTextSquare(const int length, const int width, const string outLineColor, const string fillColor, const string message) :Square(length, width, outLineColor), Fillable(fillColor), Text(message) {}

// 'draw' a Filled Text Square
void FilledTextSquare::filledTextSquaredraw() {
    // reduce code by calling other classes methods
    draw(); // this refers the Square::draw
    drawFill(); // don't need to include Fillable::drawFill() since FilledSquare Extends Fillable and no other methods in class
    drawText(); // this is Text::drawText()
}

FilledTextSquare::~FilledTextSquare() {} // destructor



// ################### FILLED CIRCLE CLASS EXTENDS CIRCLE AND FILLED ##############################
FilledCircle::FilledCircle(int length, int width, string outlineColor, string fillColor) : Circle(length, width, outlineColor), Fillable(fillColor) {} //constructor
void FilledCircle::filledCircledraw() {
    // reduce code by calling other classes methods
    draw(); // this is Circle::draw()
    drawFill(); // this is Fillable::drawFill()
}

FilledCircle::~FilledCircle() {} // destructor

