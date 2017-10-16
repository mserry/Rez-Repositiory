#pragma once

template<class T>
class Singleton
{
public:
	static Singleton<T&> GetInstance();

protected:
	Singleton();
	~Singleton();
};



template <typename T>
Singleton<T&> Singleton<T>::GetInstance()
{
	static Singleton<T> instance;

	return instance;
}

template<typename T>
Singleton<T>::Singleton() {}

template<typename T>
Singleton<T>::~Singleton()
{
}



