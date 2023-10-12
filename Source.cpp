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
		SetIndex();

	}
	myString()        //Constructor when do nothing
	{
		char* arr = nullptr;
		SetIndex();
	}

	myString(const myString & input)      //Constructor For copy  we must use reference for out input because we put there no point(указатель)
	{
		size = input.size;

		InitArr(size, input.arr);
		
		

	}
	myString( myString&& input)      //Constructor For move we must use reference for out input because we put there no point(указатель)
	{
		size = input.size;

		arr = input.arr;
		input.arr = nullptr;

		

	}
	~myString()
	{
		delete[] arr;
	}


	void Print()
	{
		cout << idex;
	}
	

	myString operator +(const myString& input)
	{
		myString Help;


		Help.size = this->size + input.size;
		Help.AddArray(*this, Help.size, input); //help Class Calling this function

		return  Help;

	}

	myString& operator =(const myString& input)
	{
		


		this->size =  input.size;
		this->InitArr( this->size, input.arr); //help Class Calling this function

		return  *this;

	}


	myString& operator ++()    //Class& Mean selfame 
	{

		this->size += 1;

		this->PlusPlus(this->size);

		return  *this;

	}

	myString& operator ++(const int input)    //Class& Mean selfame for increment in right Side 
	{

		this->size += 1;

		this->PlusPlus(this->size);

		return  *this;

	}



	myString& operator --()    //Class& Mean selfame 
	{

		this->size -= 1;
		if (this->size <0)
		{
			this->size = 0;
		}
		if (this->size ==0)    
		{
			if (this->arr !=nullptr)            //if array ==0 we rewrite it in hard where first symbol is gonna be e,pty
			{
				delete[] this->arr;
				this->arr = new char[1];         //when we create a dynamic place for parametrs, we create numbers of slots . one means one slot  not 0 and one.
				arr[0] = '\0';
				//arr[1] = '\0';
			}


			return  *this;
		}

		this->MinusMinus(this->size);

		return  *this;

	}




	myString operator -(const myString& input)
	{
		myString Help;


		Help.size = this->size - input.size;
		if (Help.size<0)
		{
			Help.size = 0;
		}
		Help.SubArray(*this, Help.size, input); //help Class Calling this function

		return  Help;

	}


	bool operator <(const myString& input)
	{
		if (this->size <  input.size)
		{
			
			return false;

		}
		
		return true;
	}
	bool operator >(const myString& input)
	{
		if (this->size > input.size)
		{
			cout << "true";
			return false;

		}
		cout << "false";
		return true;
	}


	char& operator [](int index)
	{
		if (index >size)
		{
			cout << arr[size-1];
			return arr[size-1];
		}
		if (index<0)
		{
			cout << arr[0];
			return arr[0];
		}
		cout << arr[index];
		return arr[index];
	
	}

private:

	char* arr =nullptr;
	char size =0 ;
	bool more = false;
	static int IndAm;
	int idex;

protected:
	 
	void SetIndex()
	{
		IndAm++;

		idex = IndAm;

		cout << "Amount of class := " << IndAm << "Index Current : = " << IndAm << endl;
	}

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



	void PlusPlus(int size)     //This setter is travel through input array and write all in our array
	{


		
		//arr = new char[size + 1];

		if (arr !=nullptr)          //if our array not empty, we copy all in our help array
		{
			char* helpArr = new char[size + 1];
			for (int i = 0; i < size-1; i++)        //size - 1, just for keep the border of our old array. 
			{
				helpArr[i] = arr[i];


			}
			helpArr[size - 1] = '+';
			helpArr[size] = '\0';

			delete[] arr;
			arr = new char[size + 1];

			for (int i = 0; i < size; i++)        //size - 1, just for keep the border of our old array. 
			{
				arr[i] = helpArr [i] ;


			}
			arr[size] = '\0';
			delete[] helpArr;


		}
		if (arr ==nullptr)
		{
			arr = new char[size + 1];
			arr[0] = '+';
			arr[size] = '\0';
		}
		
		
	}


	void MinusMinus(int size)     //This setter is travel through input array and write all in our array
	{



		//arr = new char[size + 1];

		if (arr != nullptr)          //if our array not empty, we copy all in our help array
		{
			char* helpArr = new char[size + 1];
			for (int i = 0; i < size; i++)        //size - 1, just for keep the border of our old array. 
			{
				helpArr[i] = arr[i];


			}
			
			helpArr[size] = '\0';

			delete[] arr;
			arr = new char[size + 1];

			for (int i = 0; i < size; i++)        //size - 1, just for keep the border of our old array. 
			{
				arr[i] = helpArr[i];


			}
			arr[size] = '\0';
			delete[] helpArr;


		}
		if (arr == nullptr)
		{
			arr = new char[size + 1];
			arr[0] = '-';
			arr[size] = '\0';
		}


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


int myString::IndAm = 0;     //set it by 0


int main()
{
	myString a;

	myString b;



	myString d = a + b;

	myString s("awdaw");
	cout << endl;
	
	s.Print();
//	bool s = a > b;
	
//	cout << s;



	


	//a.Print();

	return 0;
}

