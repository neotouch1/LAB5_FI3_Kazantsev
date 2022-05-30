#include"shapes.h"
#include <iostream>

using namespace std;

template <class T>
class Triangle :
  public  Shapes
{
private:
  int height;
  T** Array;
public:
  Triangle();
  Triangle(int _height, T _sign);
  Triangle(const Triangle& triangle);
  ~Triangle();

  int GetHeight();
  T GetSign();

  void SetHeight(int _height);
  float Area() override;
  ostream& print(ostream& off) override;
  bool operator == (const Triangle& other);
};
inline Triangle<char>::Triangle()
{
  height = 3;
  Array = new char* [height];
  for (int i = 0; i < height; i++)
    Array[i] = new char[height];
  for (int i = 0; i < height; i++)
    for (int j = 0; j < i; j++)
      Array[i][j] = '*';
}

template<class T>
inline Triangle<T>::Triangle(int _height, T _sign)
{
  height = _height + 1;
  Array = new T * [height];
  for (int i = 0; i < height; i++)
    Array[i] = new T[height];
  for (int i = 0; i < height; i++)
    for (int j = 0; j < i; j++)
      Array[i][j] = _sign;
}

template<class T>
inline Triangle<T>::Triangle(const Triangle& triangle)
{
  if (Array != 0)
  {
    for (int i = 0; i < height; i++)
      delete[] Array[i];
    delete[] Array;
  }
  height = triangle.height;
  Array = new T * [height];
  for (int i = 0; i < height; i++)
    Array[i] = new T[height];
  for (int i = 0; i < height; i++)
    for (int j = 0; j < i; j++)
      Array[i][j] = triangle.Array[i][j];
}

template<class T>
inline Triangle<T>::~Triangle()
{
  if (Array != 0)
  {
    for (int i = 0; i < height; i++)
      delete[] Array[i];
    delete[] Array;
    Array = 0;
    height = 0;
  }
}

template<class T>
inline int Triangle<T>::GetHeight()
{
  return height - 1;
}

template<class T>
inline T Triangle<T>::GetSign()
{
  return T();
}

template<class T>
inline void Triangle<T>::SetHeight(int _height)
{
  T tmp = this->GetSign();
  if (Array != 0)
  {
    for (int i = 0; i < height; i++)
      delete[] Array[i];
    delete[] Array;
  }
  height = _height + 1;
  Array = new T * [height];
  for (int i = 0; i < height; i++)
    Array[i] = new T[height];
  for (int i = 0; i < height; i++)
    for (int j = 0; j < i; j++)
      Array[i][j] = tmp;
}

template<class T>
inline float Triangle<T>::Area()
{
  return ((height - 1) * (height - 1)) / 2;
}

template<class T>
inline ostream& Triangle<T>::print(ostream& off)
{
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < i; j++)
      off << Array[i][j];
    off << endl;
  }
  return off;
}

template<class T>
inline bool Triangle<T>::operator == (const Triangle& other)
{
  if (height == other.height && Array[0][0] == other.Array[0][0])
    return true;
  return false;
}

