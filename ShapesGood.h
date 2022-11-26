/* Assignment 4 - Structural Improvements
 *
 * Header file: ShapesGood.h
 * Student: Nathan Pacey	netid:18njp		Student Number:20153310		Class: CMPE320
 *
 */

using namespace std;
#include <string>
#pragma once


// Top parent class SHAPE
class Shape {

public:
    Shape(const int length, const int width, const string outLineColor); // constructor
    Shape(const Shape& shape); // copying constructor
    
    //getters
    int getLength() const;
    int getWidth() const;
    std::string getLineColor() const;

    virtual void draw() = 0; // note this makes the parent class abstract
    Shape& operator=(const Shape& shape); // comparitor overload method
    virtual ~Shape(); // destructor

private:
    // attributes of the shape class
    int length;
    int width;
    string outLineColor;
};


// class for filled in shapes
class Fillable {

public:
    Fillable(const string fillColor); //constructor
    string getFill(); //gettter
    virtual void drawFill(); // display the fill
    virtual ~Fillable(); // destructor

private:
    string fillColor; // shapes that are filled have a fill color
};


// class for shapes with text
class Text {

public:
    Text(const string message); // constructor
    string getText(); // getter
    virtual void drawText(); // 'draw' the text
    virtual ~Text(); // destructor

private:
    string message; // text of shape
};


// Class Extends Shape -> Square
class Square : public Shape {

public:
    Square(const int length, const int width, const string outLineColor); // constructor
    virtual void draw(); // 'draw' the Square
    virtual ~Square(); // destructor
};


// Class Extends Shape -> Circle
class Circle : public Shape {

public:
    Circle(int length, int width, string outLineColor); // constructor
    virtual void draw(); // 'draw' Circle
    virtual ~Circle(); // destructor
};


// Class Extends Shape -> Arc
class Arc : public Shape {

public:
    Arc(int length, int width, string outLineColor); // constructor
    virtual void draw(); // 'draw' Arc
    virtual ~Arc(); // destructor
};


// Class Extends Square and Fillable -> FilledSquare
class FilledSquare : public Square, public Fillable {

public:
    FilledSquare(const int length, const int width, const string outLineColor, const string fillColor);
    // constructor
    virtual void filledSquaredraw();
    virtual ~FilledSquare(); // destructor
};


// Class Extends Circle and Fillable -> FilledCircle
class FilledCircle : public Circle, public Fillable {

public:
    FilledCircle(int length, int width, string outLineColor, string fillColor); // constructor
    virtual void filledCircledraw(); // 'draw' Filled Circle
    virtual ~FilledCircle(); // destructor
};


// Class Extends Square, Fillable anmd Text -> FilledTextSquare
class FilledTextSquare : public Square, public Fillable, public Text {

public:
    FilledTextSquare(const int length, const int width, const string outLineColor, const string fillColor, const string message); // constructor
    virtual void filledTextSquaredraw();
    virtual ~FilledTextSquare(); // destructor
};
