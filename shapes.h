#include <iostream>

using namespace std;

class Shapes
{
public:
  virtual ~Shapes() {}
  virtual float Area() = 0;
  virtual ostream& print(ostream& off) = 0;
  
  friend ostream& operator<<(ostream& off, Shapes& other)
  {
    return other.print(off);
  }
  
  bool operator > (Shapes& other)
  {
    if (this->Area() > other.Area())
      return true;
    return false;
  }
  
  bool operator < (Shapes& other)
  {
    if (this->Area() < other.Area())
      return true;
    return false;
  }
};
