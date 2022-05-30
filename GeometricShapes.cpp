#include <iostream>
#include"point.h"
#include"line.h"
#include"circle.h"
#include"rectangle.h"
#include"square.h"
#include"cube.h"
#include"triangle.h"
#include"shapes.h"
#include "container.h"

using namespace std;

int main()
{
  Container Cont;
  Point <char> point;
  Line <char> line(8, '-');
  Circle <char> circle(3, '*');
  Rectangle <int> rectangle(3, 5, 1);
  Square <int> square(5, 1);
  Cube <char> cube(5, '*');
  Triangle <char> triangle(4, '^');
  
  Cont.Add(point);
  Cont.Add(line);
  Cont.Add(circle);
  Cont.Add(rectangle);
  Cont.Add(square);
  Cont.Add(cube);
  Cont.Add(triangle);
  
  cout << "point:" << endl;
  Cont.Out(point);
  cout << endl;
  
  cout << "line:" << endl;
  Cont.Out(line);
  cout << endl;
  
  cout << "circle:" << endl;
  Cont.Out(circle);
  cout << endl;
  
  cout << "rectangle:" << endl;
  Cont.Out(rectangle);
  cout << endl;

  cout << "square:" << endl;
  Cont.Out(square);
  cout << endl;

  cout << "cube:" << endl;
  Cont.Out(cube);
  cout << endl;
  
  cout << "triangle:" << endl;
  Cont.Out(triangle);
  
  if (square.Area() > cube.Area())
    Cont.Delete(cube);
  
  if (square.Area() < cube.Area())
    Cont.Delete(square);
  
  cout << " [___  Container ___] " << endl << Cont;
  return 0;
}
