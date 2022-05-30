#include"shapes.h"
#include"square.h"
#include <iostream>

using namespace std;

template <class T>
class Cube : 
	public  Shapes
{
private:
	int part;
	T*** Array;
public:
	Cube();
	Cube(int a, T _mark);
	Cube(const Cube& cube);
	~Cube();

	int GetPart();
	T GetSign();
	
	void SetPart(int _part);
	float Area() override;
	ostream& print(ostream& off) override;
	bool operator == (const Cube& other);
};

template<class T>
inline Cube<T>::Cube()
{
	part = 1;
	Array = new T * *[part];
	for (int i = 0; i < part; i++)
	{
		Array[i] = new T * [part];
		for (int j = 0; j < part; j++)
			Array[i][j] = new T[part];
	}
	Array[0][0][0] = '*';
}

template<class T>
inline Cube<T>::Cube(int a, T _sign)
{
	part = a;
	Array = new T * *[part];
	for (int i = 0; i < part; i++)
	{
		Array[i] = new T * [part];
		for (int j = 0; j < part; j++)
			Array[i][j] = new T[part];
	}
	for (int i = 0; i < part; i++)
		for (int j = 0; j < part; j++)
			for (int l = 0; l < part; l++)
				Array[i][j][l] = _sign;
}

template<class T>
inline Cube<T>::Cube(const Cube& cube)
{
	if (Array != 0)
	{
		for (int i = 0; i < part; i++)
			for (int j = 0; j < part; j++)
				delete[] Array[i][j];
		for (int i = 0; i < part; i++)
			delete[] Array[i];
		delete[] Array;
	}
	side = cube.part;
	Array = new T * *[part];
	for (int i = 0; i < part; i++)
	{
		Array[i] = new T * [part];
		for (int j = 0; j < part; j++)
			Array[i][j] = new T[part];
	}
	for (int i = 0; i < part; i++)
		for (int j = 0; j < part; j++)
			for (int l = 0; l < part; l++)
				Array[i][j][l] = cube.Array[i][j][l];
}

template<class T>
inline Cube<T>::~Cube()
{
	if (Array != 0)
	{
		for (int i = 0; i < part; i++)
			for (int j = 0; j < part; j++)
				delete[] Array[i][j];
		for (int i = 0; i < part; i++)
			delete[] Array[i];
		delete[] Array;
		Array = 0;
		part = 0;
	}
}

template<class T>
inline int Cube<T>::GetPart()
{
	return part;
}

template<class T>
inline T Cube<T>::GetSign()
{
	return Array[0][0][0];
}

template<class T>
inline void Cube<T>::SetPart(int _part)
{
	T tmp = Array[0][0][0];
	if (Array != 0)
	{
		for (int i = 0; i < part; i++)
			for (int j = 0; j < part; j++)
				delete[] Array[i][j];
		for (int i = 0; i < part; i++)
			delete[] Array[i];
		delete[] Array;
	}
	side = _part;
	Array = new T * *[part];
	for (int i = 0; i < part; i++)
	{
		Array[i] = new T * [part];
		for (int j = 0; j < part; j++)
			Array[i][j] = new T[part];
	}
	for (int i = 0; i < part; i++)
		for (int j = 0; j < part; j++)
			for (int l = 0; l < part; l++)
				Array[i][j][l] = tmp;
}

template<class T>
inline float Cube<T>::Area()
{
	return part * part * 6;
}

template<class T>
inline ostream& Cube<T>::print(ostream& off)
{
	Square<T> tmp(part, Array[0][0][0]);
	tmp.print(off);
	return off;
}

template<class T>
inline bool Cube<T>::operator == (const Cube& other)
{
	if (part == other.part && Array[0][0][0] == other.Array[0][0][0])
		return true;
	return false;
}
