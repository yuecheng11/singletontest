#include <iostream>

using namespace std;

class Singleton
{
public:
	static Singleton* GetInstance();
	
	#if 0
	static void destroy()
	{
		cout<<"destroy func"<<endl;
		delete pInstance;
	}
	#endif
	
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
			if(pInstance != NULL)
			{
				delete pInstance;
				cout<<"~~AutoRelease()"<<endl;
			}
		}
	};
	
	Singleton()
	{
		cout<<"construct Singleton()"<<endl;
	}

	~Singleton()
	{
		cout<<"~Singleton()"<<endl;
	}

private:
	static Singleton* pInstance;
	static AutoRelease _autoRelease;
};

Singleton* Singleton::pInstance = NULL;
Singleton::AutoRelease Singleton::_autoRelease;

 Singleton* Singleton:: GetInstance()
{
	if(pInstance == NULL)
	{
		cout<<"func GetInstance, create Singleton"<<endl;
		pInstance = new Singleton;
	}

	return pInstance;
}
	

int main(int argc,char* argv[])
{
	Singleton *p1 = Singleton::GetInstance();
	Singleton *p2 = Singleton::GetInstance();
	Singleton *p3 = Singleton::GetInstance();
	cout<<"p1 = "<<p1<<", p2 = "<<p2<<" p3 = "<<p3<<endl;

	//Singleton::destroy();

	return 0;
}
	
