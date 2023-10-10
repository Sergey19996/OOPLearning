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



		  






	myString operator +(const myString& input)
	{
		myString Help;


		Help.size = this->size + input.size;
		Help.AddArray(*this, Help.size, input); //help Class Calling this function

		return  Help;

	}




	myString operator -(const myString& input)
	{
		myString Help;


		Help.size = this->size - input.size;
		Help.SubArray(*this, Help.size, input); //help Class Calling this function

		return  Help;

	}




private:

	char* arr =nullptr;
	char size =0 ;

protected:
	 


	void AddArray(const myString& input1, int NewSize, const myString& input2)
	{
		this->arr = new char[NewSize+1];    //this Array it's meaning the aray which class we called this function. 

		for (int x = 0; x < NewSize; x++)  // MyString Help Class Called this Array. array own this class. 
		{
			if (x == input1.size)
			{

				for (int i = 0; i < input2.size; i++,x++)
				{
					this->arr[x] = input2.arr[i];
				}


				break;
			}
			this->arr[x] = input1.arr[x];
		}

		this->arr[NewSize] = '\0';

	}



	void SubArray(const myString& input1, int NewSize, const myString& input2)
	{
		this->arr = new char[NewSize + 1];    //this Array it's meaning the aray which class we called this function. 

		for (int x = 0; x < NewSize; x++)  // MyString Help Class Called this Array. array own this class. 
		{
			if (x == input1.size)
			{

				for (int i = 0; x < NewSize; i++, x++)   //we must check on amout of   difference values x and NewSize
				{
					this->arr[x] = input2.arr[i];
				}


				break;
			}
			this->arr[x] = input1.arr[x];
		}

		this->arr[NewSize] = '\0';

	}








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
	myString a("212");

	myString b ("3");

	myString c = a - b;

	 //a = b = c;   Must do this  
	c.Print();

	return 0;
}