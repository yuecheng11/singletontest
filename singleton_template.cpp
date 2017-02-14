#include <iostream>
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

template<typename T>
class Singleton
{
private:
	class AutoRelease
	{
	public:
		AutoRelease()
		{
			cout<<"AutoRelease() "<<endl;
		}
		~AutoRelease()
		{
			cout<<"~~AutoRelease()"<<endl;
			if(_pinstace != NULL)
			{
				delete _pinstace;
			}
		}
	};
public:
	static T* getInstance();
private:
	Singleton()
	{
		cout<<"Singlton()"<<endl;
	}
	~Singleton()
	{
		cout<<"~Singlton()"<<endl;
	}
private:
	static T* _pinstace;
	static AutoRelease _autoRelease;
};

template<typename T>
T* Singleton<T>::_pinstace = NULL;

template<typename T>
typename Singleton<T>::AutoRelease Singleton<T>::_autoRelease;

template<typename T>
T* Singleton<T>::getInstance()
{
	_autoRelease;
	if(_pinstace == NULL)
	{
		_pinstace = new T;
	}

	return _pinstace;
}


int main()
{
	Myclass* p1 = Singleton<Myclass>::getInstance();
	Myclass* p2 = Singleton<Myclass>::getInstance();

	cout<<"p1 = "<<hex<<p1<<endl;
	cout<<"p2 = "<<hex<<p2<<endl;

	return 0;
}
