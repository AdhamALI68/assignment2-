/*
------------------------------------------------------------------
* Author: Adham Ahmed 
* ID: 900223243
* problem: 1
* Date: 26/2/2022
------------------------------------------------------------------
*/
#include "point.h"
#include<ctime>
point::point() 
{
    //initilaizing x and y =0
    x=0;
    y=0;
}
point::point(float a,float b)
{
    x=a;
    y=b;
}
float point:: get_x()
{
    return x;
}
float point:: get_y()
{
    return y;
}
void point:: set_x(float a)
{
    x=a;
}
void point:: set_y(float b)
{
    y=b;
}
void point::display()
{
    cout<<"x coordinate: "<<x<<" , "<<"y coordinate: "<<y<<endl;
}
double point:: distance( point &p)
{
    return sqrt(pow(x-p.x,2))+pow(y-p.y,2); //formula to get the distance
}

point center(point* a,int n) // a function to get the center point of every cluster
{
    // intilaizing the total of x's and y's =0
    double cx=0;
    double cy=0;

    for(int i=0;i<n;i++)// getting the average 
    {
        cx=cx+(*(a+i)).get_x();
        cy=cy+(*(a+i)).get_y();
    }
    point t(cx/n,cy/n);
    return t;
}
void closest (point* a,point* b,int n,point p) //function that get two dynamic arrays with their size and it is responsible 
//to say wether this point close to cluster a or b 
{
// calling function center to get the center point
    point r1= center(a,n); 
    point r2= center(b,n); 

    if(p.distance(r1)<p.distance(r2)) //condition if r1 (cluster A) smaller than r2 (cluster B)
    {
         cout<<"p ("<< p.get_x()<<","<<p.get_y()<<") is closest to cluster A"<<endl;
    }
    else
    {
        cout<<"p ("<< p.get_x()<<","<<p.get_y()<<") is closest to cluster B"<<endl;
    }
}
int main()
{
    srand(time(0)); // for the rand
    int size=200; // size of arrays

    // declaring dynamic arrays of type point
    point*a=new point[size];
    point*b=new point[size];


    for(int i=0; i<size;i++) //setting the x and y coordinates of cluster a
    {
        //rand function that produce float numbers between 90 and 70
       (*(a+i)).set_x(70.0 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(90.0-70.0))));
        (*(a+i)).set_y(70.0 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(90.0-70.0))));

    }

    for(int i=0; i<size;i++) //setting the x and y coordinates of cluster b
    {
        //rand function that produce float numbers between 40 and 20
        (*(b+i)).set_x(20.0 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(40.0-20.0))));
        (*(b+i)).set_y(20.0 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(40.0-20.0))));

    }

    cout<<"center of cluster A is "<<endl; 
    // displaying the center point of cluster A
    center(a,size).display();

    cout<<"center of cluster B is "<<endl; 
    // displaying the center point of cluster B
    center(b,size).display();

    for(int i=0;i<20;i++)
    {
        point p;

        //setting the x and y coordinates of the 20 points
        //rand function that produce float numbers between 100 and 5
        p.set_x(5.0 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(100.0-5.0))));
        p.set_y(5.0 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(100.0-5.0))));

        closest(a,b,size,p); // calling function closest to know wether this point close to A and B

    }

    return 0;
}
