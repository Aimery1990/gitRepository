
#include <iostream>
#include <string.h>


using namespace std;


class MemLake{

public:
	MemLake() = default;

	MemLake( size_t sz )
	{
		
		this->space = new char[sz];
		this->size = sz;
	}

	MemLake( const MemLake & ano )
	{
		if(this != &ano )
		{
			this->space = new char[ano.size];
			this->size = ano.size;
			memcpy( this->space, ano.space, ano.size );
		}
	}
	
	MemLake( MemLake && ano )
	{
		
	}

	virtual MemLake & operator=( const MemLake & ano )
	{
		if(this != &ano )
		{
			delete [] this->space;			
			this->space = new char[ano.size];
			this->size = ano.size;
			memcpy( this->space, ano.space, ano.size );
		}
		return *this;
	}

	virtual MemLake & operator=( MemLake && ano )
	{
		return *this;
	}

	virtual ~MemLake()
	{
		if(this->space!=nullptr)
			delete [] this->space;
		this->size = 0;
	}

	char * Get_Mem() const
	{
		return space;
	}
	
	

private:
	char * space;
	size_t size;

};


int main()
{
	
	return 0;
}
