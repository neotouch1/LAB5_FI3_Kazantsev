#include"shapes.h"
#include <iostream>

using namespace std;

template <class T>
class Rectangle : 
  public  Shapes
{
private:
int part1;
  int part2;
  T** Array;
public:
  Rectangle();
  Rectangle(int _part1, int _part2, T _sign);
  Rectangle(const Rectangle& rectangle);
  ~Rectangle();
  
  int GetPart1();
  int GetPart2();
  T GetSign();

  void SetPart(int _part1, int _part2);
  float Area() override;
  ostream& print(ostream& off) override;
  bool operator ==(const Rectangle& other);
};
inline Rectangle<char>::Rectangle()
{
  part1 = 1;
  part2 = 1;
  Array = new char* [1];
  Array[0] = new char[1];
  Array[0][0] = '*';

}

template<class T>
inline Rectangle<T>::Rectangle(int _part1, int _part2, T _sign)
{
  part1 = _part1;
  side2 = _part2;

  Array = new T * [part1];
  for (int i = 0; i < part1; i++)
    Array[i] = new T[part2];
  for (int i = 0; i < part1; i++)
    for (int j = 0; j < part2; j++)
      Array[i][j] = _sign;
}

template<class T>
inline Rectangle<T>::Rectangle(const Rectangle& rectangle)
{
  if (Array != 0)
  {
    for (int i = 0; i < side1; i++)
      delete[] Array[i];
    delete[] Array;
  }
  side1 = rectangle.side1;
  side2 = rectangle.side2;
  
  Array = new T * [side1];
  for (int i = 0; i < side1; i++)
    Array[i] = new T[side2];
  for (int i = 0; i < side1; i++)
    for (int j = 0; j < side2; j++)
      Array[i][j] = rectangle.Array[i][j];
}

template<class T>
inline Rectangle<T>::~Rectangle()
{
  if (Array != 0)
  {
    for (int i = 0; i < part1; i++)
      delete[] Array[i];
    delete[] Array;
    Array = 0;
    part1 = 0;
    part2 = 0;
  }
}

template<class T>
inline int Rectangle<T>::GetPart1()
{
  return part1;
}

template<class T>
inline int Rectangle<T>::GetPart2()
{
  return part2;
}

template<class T>
inline T Rectangle<T>::GetSign()
{
  return Array[0][0];
}

template<class T>
inline void Rectangle<T>::SetPart(int _part1, int _part2)
{
  T tmp = Array[0][0];
  if (Array != 0)
  {
    for (int i = 0; i < part1; i++)
      delete[] Array[i];
    delete[] Array;
  }
  part1 = _part1;
  part2 = _part2;
  
  Array = new T * [part1];
  for (int i = 0; i < part1; i++)
    Array[i] = new T[part2];
  for (int i = 0; i < part1; i++)
    for (int j = 0; j < part2; j++)
      Array[i][j] = tmp;
}

template<class T>
inline float Rectangle<T>::Area()
{
  return part1 * part2;
}

template<class T>
inline ostream& Rectangle<T>::print(ostream& off)
{
  for (int i = 0; i < part1; i++)
  {
    for (int j = 0; j < part2; j++)
      off << Array[i][j];
    off << endl;
  }
  return off;
}

template<class T>
inline bool Rectangle<T>::operator == (const Rectangle& other)
{
  if (part1 == other.part1 && part2 == other.part2 && Array[0][0] == other.Array[0][0])
    return true;
  return false;
}