#pragma once
#ifndef Zackster
#define Zackster
#ifndef _INC_STRING
#include <string.h>
#endif
#include <cassert>
namespace ZacksterString
{
	class str
	{
	private:
		int Size;
		char* Str;
	public:
		str()
		{
			Str = new char[1];
			Str[0] = '\0';
			Size = 1;
		}
		str(const char* _Str)
		{
			this->Size = strlen(_Str) + 1;
			delete[] this->Str;
			this->Str = new char[this->Size];
			for (int i = 0; i < this->Size; i++)
			{
				this->Str[i] = _Str[i];
			}
		}
		str(const str& other)
		{
			this->Size = other.Size;
			this->Str = new char[Size];
			for (int i = 0; i < other.Size; i++) this->Str[i] = other.Str[i];
			//	cout << "Copying!" << endl;
		}
		void reverse()
		{
			char buf;
			for (int i = 0; i < (this->Size - 1) / 2; i++)
			{
				buf = this->Str[i];
				this->Str[i] = Str[this->Size - 2 - i];
				Str[this->Size - 2 - i] = buf;
			}
		}
		int compareABC(str& bufStr)
		{
			return strcmp(this->Str, bufStr.Str);
		}
		int compareABC(char* bufStr)
		{
			return strcmp(this->Str, bufStr);
		}
		bool operator == (const str& bufStr)
		{
			if (bufStr.Size != this->Size) return false;
			for (int i = 0; i < this->Size; i++)
			{
				if (bufStr.Str[i] != this->Str[i]) return false;
			}
			return true;
		}
		bool operator == (const char* bufStr)
		{
			if (strlen(bufStr)+1 != this->Size) return false;
			for (int i = 0; i < this->Size; i++)
			{
				if (bufStr[i] != this->Str[i]) return false;
			}
			return true;
		}
		str& operator += (const char* _Str)
		{
			int _SizeStr = 0;
			for (int i = 0; _Str[i] != '\0'; i++) this->addSymb(_Str[i]);
			return *this;
		}
		str& operator += (const str& _Str)
		{
			int _SizeStr = 0;
			for (int i = 0; _Str.Str[i] != '\0'; i++) this->addSymb(_Str.Str[i]);
			return *this;
		}
		char* operator + (const str _Str)
		{
			int newSize = this->Size + _Str.Size - 1;
			char* bufS = new char[newSize+1];
			for (int i = 0; i < this->Size - 1; i++) bufS[i] = this->Str[i];
			for (int i = 0; i < _Str.Size; i++) bufS[i + this->Size - 1] = _Str.Str[i];
			return bufS;
		}
		char* operator + (const char* _Str)
		{
			int newSize = this->Size + strlen(_Str);
			char* bufS = new char[newSize+1];
			for (int i = 0; i < this->Size - 1; i++) bufS[i] = this->Str[i];
			for (unsigned int i = 0; i < strlen(_Str) + 1; i++) bufS[i + this->Size - 1] = _Str[i];
			return bufS;
		}
		str& operator = (const str& _bufStr)
		{
			this->Size = _bufStr.Size;
			delete[] this->Str;
			this->Str = new char[this->Size];
			for (int i = 0; i < this->Size; i++)
			{
				this->Str[i] = _bufStr.Str[i];
			}
			return *this;
		}
		str& operator = (const char* _string)
		{
			this->Size = strlen(_string) + 1;
			delete[] this->Str;
			this->Str = new char[this->Size];
			for (int i = 0; i < this->Size; i++)
			{
				this->Str[i] = _string[i];
			}
			return *this;
		}
		char* line()
		{
			return this->Str;
		}
		void addSymb(char c)
		{
			char* buf = new char[this->Size + 1];
			for (int i = 0; i < Size; i++) buf[i] = this->Str[i];
			this->Size++;
			this->Str = new char[this->Size];
			for (int i = 0; i < Size - 1; i++) this->Str[i] = buf[i];
			this->Str[Size - 2] = c;
			Str[Size - 1] = '\0';
			delete[] buf;
		}
		~str()
		{
			delete[] Str;
		}
		int size()
		{
			return this->Size;
		}
		char& operator[](int r)
		{
			assert(r < this->Size-1 && r >= 0);
			return this->Str[r];
		}
	};
}

#endif
