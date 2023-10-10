#include <iostream>


using namespace std;

class myString
{
public:

	myString(const char* input)             //Constructor for char input
	{
		for (int i = 0; i < 250; i++)       //initialize amount of int in input 
		{
			 
			if (input[i] =='\0')
			{
				size = i;
				
				InitArr(i, input);  // Call Init Arr
				break;
			}

		}

	}
	myString()        //Constructor when do nothing
	{
		char* arr = nullptr;
	}

	myString(const myString & input)      //Constructor For copy  we must use reference for out input because we put there no point(указатель)
	{
		size = input.size;

		InitArr(size, input.arr);
		


	}
	~myString()
	{
		delete[] arr;
	}




	void Print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i];
		}
	}



private:

	char* arr =nullptr;
	char size =0 ;

protected:
	 



	void InitArr(int size, const char* input)     //This setter is travel through input array and write all in our array
	{
		arr = new char[size+1];

		for (int i = 0; i < size; i++)
		{
			arr[i] = input[i];

			
		}
		arr[size] = '\0';
	}

};

int main()
{
	myString a("1");

	myString b (a);
	
	return 0;
}