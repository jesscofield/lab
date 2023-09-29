#include <iostream>
#include <cmath>

using namespace std;

struct Point{
	
    double x, y;
    
    Point(): x(0), y(0){
    }
    
    Point(double x, double y){
    	
        this->x = x;
        this->y = y;
    }
};

class Circle{
    
public:
    Point center;
    double r;

public:
    Circle(int x, int y, int r) : center(x, y), r(r){  
    }

    bool intersect(const Circle& other){
        
        double distance = sqrt((center.x - other.center.x) * (center.x - other.center.x) + (center.y - other.center.y) * (center.y - other.center.y));
        int sumOfRadii = r + other.r;

        return(distance <= sumOfRadii);
    }
};

class Line{
	
public:
	double a;
    double b;
    double c;

    
    Line(int a, int b, int c) : a(a), b(b), c(c){
    }
    
    void intersection(Circle circle){
        
        int distance = (abs(a * circle.center.x + b * circle.center.y + c)) / sqrt(a * a + b * b);

        if(circle.r == distance)
           cout << "line touches the circle" << endl;
           
        else if(circle.r > distance)
           cout << "line intersects with the circle" << endl;
           
        else
           cout << "line is outside the circle" << endl;
    }
};

Point symmetricMapping(const Point& point, Line line){
    Point reflectedPoint;

    double distance = (line.a * point.x + line.b * point.y + line.c) / sqrt(line.a * line.a + line.b * line.b);

    reflectedPoint.x = point.x - 2 * line.a * distance;
    reflectedPoint.y = point.y - 2 * line.b * distance;

    return reflectedPoint;
}

void symmetricMappingForCircle(Circle& circle, Line line){
    
    Point center = circle.center;
    center = symmetricMapping(center, line);
}

Point inversion(const Point& point, const Point& center, double radius){
    Point invertedPoint;

    double distanceToCenter = sqrt((point.x - center.x) * (point.x - center.x) + (point.y - center.y) * (point.y - center.y));

    if(distanceToCenter < radius){
        
       cout << "point is inside the circle; inversion undefined" << endl;

       invertedPoint.x = 0;
       invertedPoint.y = 0;
    }
    
    else{
        
        invertedPoint.x = center.x + (radius * radius * (point.x - center.x)) / ((point.x - center.x) * (point.x - center.x) + (point.y - center.y) * (point.y - center.y));
        invertedPoint.y = center.y + (radius * radius * (point.y - center.y)) / ((point.x - center.x) * (point.x - center.x) + (point.y - center.y) * (point.y - center.y));
    }

    return invertedPoint;
}

void inversionForCircle(Circle& circle, const Point& inversionCenter, double inversionRadius){
    
    Point center = circle.center;
    center = inversion(center, inversionCenter, inversionRadius);
}

int main(){
	
    Line line = Line(1, 8, 3);
    Circle circle = Circle(0, 0, 9);
    
    line.intersection(circle);

    Circle circle1(-9, 6, 15);
    Circle circle2(15, -20, 10);

    if(circle1.intersect(circle2)) 
       cout << "circle 1 and circle 2 intersect" << endl;
    
    else
       cout << "circle 1 and circle 2 do not intersect" << endl;

    Line line2 = Line(3, 0, 0);
    Point point = Point(2, 3);

    Point reflectedPoint = symmetricMapping(point, line2);

    cout << "original point: (" << point.x << "; " << point.y << ")" << endl;
    cout << "reflected point: (" << reflectedPoint.x << "; " << reflectedPoint.y << ")" << endl;

    Point center = Point(0, 0);
    double radius = 2;
    point = Point(3, 4);

    Point invertedPoint = inversion(point, center, radius);

    cout << "original point: (" << point.x << "; " << point.y << ")" << endl;
    cout << "inverted point: (" << invertedPoint.x << "; " << invertedPoint.y << ")" << endl;
    
    cout << "original circle: (" << circle.center.x << ", " << circle.center.y << ", " << circle.r << ")" << endl;

    Line line3 = Line(1, 2, -3);
    symmetricMappingForCircle(circle, line3);
    
    cout << "reflected circle: (" << circle.center.x << ", " << circle.center.y << ", " << circle.r << ")" << endl;
    
    cout << "original circle: (" << circle.center.x << ", " << circle.center.y << ", " << circle.r << ")" << endl;
    
    Point inversionCenter = Point(0, 0);
    double inversionRadius = 5;
    inversionForCircle(circle, inversionCenter, inversionRadius);
    
    cout << "inverted circle: (" << circle.center.x << ", " << circle.center.y << ", " << circle.r << ")" << endl;

    return 0;
}
