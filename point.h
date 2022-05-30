#include <iostream>
#include"shapes.h"

using namespace std;

template <class T>
class Point :
  public  Shapes
{
private:
  T sign;
public:
  Point();
  Point(T _sign);
  Point(const Point& point);
  
  T Get();
  float Area() override;
  
  ostream& print(ostream& off) override;
  bool operator ==(const Point& other);
};

template<class T>
inline Point<T>::Point()
{
  sign = '.';
}

template<class T>
inline Point<T>::Point(T _sign)
{
  sign = _sign;
}

template<class T>
inline Point<T>::Point(const Point& point)
{
  sign = point.sign;
}

template<class T>
inline T Point<T>::Get()
{
  return sign;
}

template<class T>
inline float Point<T>::Area()
{
  return 0;
}

template<class T>
inline ostream& Point<T>::print(ostream& off)
{
  off << this->Get();
  return off;
}

template<class T>
inline bool Point<T>::operator==(const Point& other)
{
  if (sign == other.sign)
    return true;
  return false;
}
