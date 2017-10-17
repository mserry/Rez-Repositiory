#pragma once

template<typename T>
class Singleton
{
public:
	static T& GetInstance();

	Singleton(Singleton const&) = delete;
	Singleton& operator= (Singleton const&) = delete;

protected:
	Singleton() = delete;
	~Singleton() = delete;
};


template <typename T>
T& Singleton<T>::GetInstance()
{
	static T instance;

	return instance;
}
