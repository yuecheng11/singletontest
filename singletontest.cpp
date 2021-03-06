#include <iostream>

using namespace std;

class Singleton
{
public:
	static Singleton* GetInstance();
	
	static void destroy()
	{
		cout<<"destroy func"<<endl;
		delete pInstance;
	}
	
private:
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
};

Singleton* Singleton::pInstance = NULL;

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

	Singleton::destroy();

	return 0;
}
	
