/*
------------------------------------------------------------------
* Author: Adham Ahmed 
* ID: 900223243
* problem: 1
* Date: 26/2/2022
------------------------------------------------------------------
*/

#include <iostream>
#include <cmath>
using namespace std;

class point // making a class called point
{
    private: //private section that contains x and y
    float x;
    float y;

    public:
    //overloaded constructors
    point();
    point(float a,float b);
    
    //getters
    float get_x();
    float get_y();

    //setters
    void set_x(float a);
    void set_y(float b);

    void display();// displays the x an y of the cluster
    double distance( point & p);// calculating the distance


};