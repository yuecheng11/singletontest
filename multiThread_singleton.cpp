#include <iostream>
#include <pthread.h>
#include <stdlib.h>
using namespace std;

class Myclass
{
public:
	Myclass()
	{
		cout<<"Myclass()"<<endl;
	}
	~Myclass()
	{
		cout<<"~Myclass()"<<endl;
	}
};

template <typename T>
class Singleton
{
public:
	static T* getInstance();
	static void init();
	static void destroy();
private:
	Singleton()
	{
		cout<<"Singleton()"<<endl;
	}
	~Singleton()
	{
		cout<<"~Singleton()"<<endl;
	}

private:
	static T* _pInstance;
	static pthread_once_t _once;
};

template <typename T>
T* Singleton<T>::_pInstance = NULL;

template <typename T>
pthread_once_t	Singleton<T>::_once = PTHREAD_ONCE_INIT;

template <typename T>
void Singleton<T>::init()
{
	//atexit函数注册的函数在main退出的时候被自动调用
	atexit(destroy);
	if(_pInstance == NULL)
		_pInstance = new T;
}



template <typename T>
T* Singleton<T>::getInstance()
{
	//pthread_once函数保证其注册的函数在多线程环境中，只被执行一次
	pthread_once(&_once,init);
	return _pInstance;
}

template <typename T>
void Singleton<T>::destroy()
{
	if(_pInstance != NULL)
		delete _pInstance;
}


int main()
{
	Myclass* p1 = Singleton<Myclass>::getInstance();
	Myclass* p2 = Singleton<Myclass>::getInstance();

	cout<<"p1 = "<<hex<<p1<<endl;
	cout<<"p2 = "<<hex<<p2<<endl;

	return 0;
}

