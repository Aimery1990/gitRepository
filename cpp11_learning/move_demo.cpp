
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#define DEFAULT_MEMSZ	(1024)


class MemLake{

public:
	MemLake() = default;

	MemLake( size_t sz = DEFAULT_MEMSZ ):space(new char[sz]), size(sz)
	{
		cout << "MemLake( size_t sz )" << endl;
		// this->space = new char[sz];
		// this->size = sz;
	}

	MemLake( const MemLake & ano ):space(new char[ano.size]), size(ano.size)
	{
		cout << "MemLake( const MemLake & ano )" << endl;
		// this->space = new char[ano.size];
		// this->size = ano.size;
		memcpy( this->space, ano.space, ano.size );
	}
	
	MemLake( MemLake && ano ):space(nullptr), size(0)
	{
		cout << "MemLake( MemLake && ano )" << endl;
		// this->space = ano.space;
		// this->size = ano.size;

		// ano.space = nullptr;
		// ano.size = 0;
		
		*this = std::move(ano);
	}

	MemLake & operator=( const MemLake & ano )
	{
		cout << "MemLake & operator=( const MemLake & ano )" << endl;
		if(this != &ano )
		{
			if(this->space)
				delete [] this->space;			
			this->space = new char[ano.size];
			this->size = ano.size;
			memcpy( this->space, ano.space, ano.size );
		}
		return *this;
	}

	MemLake & operator=( MemLake && ano )
	{
		cout << "MemLake & operator=( MemLake && ano )" << endl;
		if(this != &ano)
		{
			if(this->space)
				delete [] this->space;
			this->space = ano.space;
			this->size = ano.size;

			ano.space = nullptr;
			ano.size = 0;
		}

		return *this;
	}

	virtual ~MemLake()
	{
		cout << "virtual ~MemLake()" << endl;
		if(this->space)
			delete [] this->space;
		this->size = 0;
	}

	char * Mem_Space() const
	{
		return space;
	}

	size_t Mem_Len() const
	{
		return size;
	}
	
	

private:
	char * space;
	size_t size;

};


int main()
{

	MemLake m1(2048);
	MemLake m2(m1);
	MemLake && m3 = std::move(m2);
	printf("%p %ld\n", m2.Mem_Space(), m2.Mem_Len());
	printf("%p %ld\n", m3.Mem_Space(), m3.Mem_Len());
	MemLake m4 = m2;
	printf("%p %ld\n", m4.Mem_Space(), m4.Mem_Len());
	m4 = std::move(m3);
	printf("%p %ld\n", m4.Mem_Space(), m4.Mem_Len());
	printf("%p %ld\n", m3.Mem_Space(), m3.Mem_Len());
	printf("%p %ld\n", m2.Mem_Space(), m2.Mem_Len());
	MemLake m5 = move(m4);
	printf("%p %ld\n", m4.Mem_Space(), m4.Mem_Len());
	printf("%p %ld\n", m5.Mem_Space(), m5.Mem_Len());

	MemLake * mp = new MemLake(4096);

	memcpy(mp->Mem_Space(), "apiejisuerjgoeioefkkfokefiofiwokf", mp->Mem_Len());
	cout << mp->Mem_Space() << endl;

	delete mp;

	
	return 0;
}
