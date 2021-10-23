/*
 Numbering system converter works for binary, octal,hexadecimal and decimals.
 Made by Omar Said Mohammed
 Finished on 10/23/2021
 Took half an hour of continous coding
*/

#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<cmath>
#include <sstream>
#include <iomanip>
#include<Windows.h>
typedef long int l;
using namespace std;
void b_to_dec(string number);
void b_to_hex(string number);
void b_to_oct(string number);
void dec_to_b(string& number);
void oct_to_dec(string number);
void oct_to_b(string& number);
void hex_to_dec(string number);
void hex_to_b(string& number);
char hexadecimal(int result);
int inv_hex(char sample);
int main()
{
	DeleteMenu(GetSystemMenu(GetConsoleWindow(), FALSE), SC_MAXIMIZE, MF_BYCOMMAND);
	cout << "					Welcome to numbering systems converter						" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "************************************************************************************************************************" << endl;
	system("Color 5F");
	int base;
	do {
		cout << "Please enter base 2 or 8 or 10 or 16: ";
		cin >> base;
	} while (base != 2 && base != 8 && base != 10 && base != 16);
	system("Color DE");
	string number;
	cout << "Please enter the number: ";
	cin >> number;
	if (base == 2)
	{
		b_to_dec(number);
		b_to_oct(number);
		b_to_hex(number);
	}
	else if (base == 10)
	{
		dec_to_b(number);
		b_to_oct(number);
		b_to_hex(number);
	}
	else if (base == 8)
	{
		oct_to_dec(number);
		oct_to_b(number);
		b_to_hex(number);
	}
	else
	{
		hex_to_dec(number);
		hex_to_b(number);
	    b_to_oct(number);
	}
	return 0;
}
void b_to_dec(string number)
{
	long float result = 0;
	vector<int>fraction;
	vector<int>whole;
	int i = 0;
	for (i = 0; i < number.length() && number[i] != '.'; i++)
	{
		whole.push_back(number[i] - '0');
	}
	if (i < number.length())
	{
		for (i = ++i; i < number.length(); i++)
		{
			fraction.push_back(number[i] - '0');
		}
	}
	for (i = whole.size() - 1; i >= 0; i--)
	{
		result += (pow(2, -i + whole.size() - 1) * whole.at(i));
	}
	for (i = 0; i < fraction.size(); i++)
	{
		result += (pow(2, -(i + 1)) * fraction.at(i));
	}
	cout << setprecision(100);
	cout << "Binary: " << number << endl;
	cout << "Decimal: " << result << endl;

}
void b_to_oct(string number)
{
	cout << "Octal: ";
	int result,i;
	vector<int>fraction;
	vector<int>whole;
	for (i = 0; i < number.length() && number[i] != '.'; i++)
	{
		whole.push_back(number[i] - '0');
	}
	if (i < number.length())
	{
		for (i = ++i; i < number.length(); i++)
		{
			fraction.push_back(number[i] - '0');
		}
	}
		while (whole.size() % 3 != 0)
		{
			whole.insert(whole.begin(), 0);
		}
		while (fraction.size() % 3 != 0)
		{
			fraction.push_back(0);
		}
		for (int i = 0; i < whole.size(); i+=3)
		{
			result = 0;
			result += (4 * whole.at(i) + 2 * whole.at(i + 1) +  whole.at(i + 2));
			cout << result;
		}
		cout << '.';
		for (int i = 0; i < fraction.size(); i += 3)
		{
			result = 0;
			result += (4 * fraction.at(i) + 2 * fraction.at(i + 1) +  fraction.at(i + 2));
			cout << result;
		}
		cout << endl;

}
void b_to_hex(string number)
{
	cout << "Hexadecimal: ";
	int result, i;
	vector<int>fraction;
	vector<int>whole;
	for (i = 0; i < number.length() && number[i] != '.'; i++)
	{
		whole.push_back(number[i] - '0');
	}
	if (i < number.length())
	{
		for (i = ++i; i < number.length(); i++)
		{
			fraction.push_back(number[i] - '0');
		}
	}
	while (whole.size() % 4 != 0)
	{
		whole.insert(whole.begin(), 0);
	}
	while (fraction.size() % 4 != 0)
	{
		fraction.push_back(0);
	}
	for (int i = 0; i < whole.size(); i += 4)
	{
		result = 0;
		result += (8 * whole.at(i) + 4 * whole.at(i + 1) + 2 * whole.at(i + 2) + whole.at(i + 3));
		if (result < 10)
			cout << result;
		else
			cout << hexadecimal(result);
	}
	cout << '.';
	for (int i = 0; i < fraction.size(); i += 4)
	{
		result = 0;
		result += (8 * fraction.at(i) + 4 * fraction.at(i + 1) + 2 * fraction.at(i + 2)+fraction.at(i+3));
		if (result < 10)
			cout << result;
		else
			cout << hexadecimal(result);
	}
	cout << endl;

}
char hexadecimal(int result)
{
	switch (result)
	{
	case 10:
		return 'A';
	case 11:
		return 'B';
	case 12:
		return 'C';
	case 13:
		return 'D';
	case 14:
		return 'E';
	case 15:
		return 'F';
	}
}
void dec_to_b(string &number)
{
	cout << "Decimal: " << number << endl;
	string whole, fraction;
	l whol, frac=0,i=0,tenth;
	for (i = 0; i < number.size()&&number[i]!='.'; i++)
	{
		whole.push_back(number[i]);
	}
	for (++i; i < number.size(); i++)
	{
		fraction.push_back(number[i]);
	}
	number.clear();
	whol = stoi(whole);
	frac = stoi(fraction);
	while (whol > 0)
	{
		number.append(to_string(whol % 2));
		whol /= 2;
	}
	for (int i = 0, n = number.length(); i < n / 2; i++)
		swap(number[i], number[n - i - 1]);
	tenth = pow(10, fraction.size());
	i = 0;
	if(fraction.size())
	number.push_back('.');
	while (frac > 0 && i < 19)
	{
		frac *= 2;
		if (frac - tenth >= 0)
		{
			number.append("1");
			frac -= tenth;
		}
		else
			number.append("0");
		i++;
	}
	cout << "Binary: " << number << endl;
}
void oct_to_dec(string number)
{
	cout << "Octal: " << number << endl;
	long float result = 0;
	vector<int>fraction;
	vector<int>whole;
	int i = 0;
	for (i = 0; i < number.length() && number[i] != '.'; i++)
	{
		whole.push_back(number[i] - '0');
	}
	if (i < number.length())
	{
		for (i = ++i; i < number.length(); i++)
		{
			fraction.push_back(number[i] - '0');
		}
	}
	for (i = whole.size() - 1; i >= 0; i--)
	{
		result += (pow(8, -i + whole.size() - 1) * whole.at(i));
	}
	for (i = 0; i < fraction.size(); i++)
	{
		result += (pow(8, -(i + 1)) * fraction.at(i));
	}
	cout << setprecision(100);
	cout << "Decimal: " << result << endl;	
}
void oct_to_b(string &number)
{
	cout << "Binary: ";
	int result, i;
	vector<int>fraction;
	vector<int>whole;
	for (i = 0; i < number.length() && number[i] != '.'; i++)
	{
		whole.push_back(number[i] - '0');
	}
	if (i < number.length())
	{
		for (i = ++i; i < number.length(); i++)
		{
			fraction.push_back(number[i] - '0');
		}
	}
	number.clear();
	for (i = 0; i < whole.size(); i++)
	{
		int j = 1;
		while (whole.at(i) > 0||j<4)
		{
			if (whole.at(i) >= 4)
			{
				whole.at(i) -= 4;
				number.push_back('1');
			}
			else if(j==1)
				number.push_back('0');
			else if (whole.at(i) >= 2)
			{
				whole.at(i) -= 2;
				number.push_back('1');
			}
			else if (j == 2)
				number.push_back('0'); 
			else if (whole.at(i) >= 1)
			{
				whole.at(i) -= 1;
				number.push_back('1');
			}
				else if (j == 3)
				number.push_back('0');
			j++;
		}
	}
	if(fraction.size())
	number.push_back('.');
	for (int i = 0; i < fraction.size(); i ++)
	{
		int j = 1;
		while (fraction.at(i) > 0||j<4)
		{
			if (fraction.at(i) >= 4)
			{
				fraction.at(i) -= 4;
				number.push_back('1');
			}
			else if (j == 1)
				number.push_back('0');
			else if (fraction.at(i) >= 2)
			{
				fraction.at(i) -= 2;
				number.push_back('1');
			}
			else if (j == 2)
				number.push_back('0');
			else if (fraction.at(i) >= 1)
			{
				fraction.at(i) -= 1;
				number.push_back('1');
			}
			else if (j == 3)
				number.push_back('0');
			j++;
		}
	}
	while(number[0]!='1')
		number.erase(number.begin());
	while (number[number.length()-1] != '1')
		number.pop_back();
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout<< number<<endl;

}
void hex_to_dec(string number)
{
	cout << "Hexadecimal: " << number << endl;
	long float result = 0;
	vector<int>fraction;
	vector<int>whole;
	int i = 0;
	for (i = 0; i < number.length() && number[i] != '.'; i++)
	{
		whole.push_back(inv_hex(number[i]));
	}
	if (i < number.length())
	{
		for (i = ++i; i < number.length(); i++)
		{
			fraction.push_back(inv_hex(number[i]));
		}
	}
	for (i = whole.size() - 1; i >= 0; i--)
	{
		result += (pow(16, -i + whole.size() - 1) * whole.at(i));
	}
	for (i = 0; i < fraction.size(); i++)
	{
		result += (pow(16, -(i + 1)) * fraction.at(i));
	}
	cout << setprecision(100);
	cout << "Decimal: " << result << endl;
}
void hex_to_b(string& number)
{
	cout << "Binary: ";
	int result, i;
	vector<int>fraction;
	vector<int>whole;
	for (i = 0; i < number.length() && number[i] != '.'; i++)
	{
		whole.push_back(inv_hex(number[i]));
	}
	if (i < number.length())
	{
		for (i = ++i; i < number.length(); i++)
		{
			fraction.push_back(inv_hex(number[i]));
		}
	}
	number.clear();
	for (i = 0; i < whole.size(); i++)
	{
		int j = 1;
		while (whole.at(i) > 0 || j < 5)
		{
			if (whole.at(i) >= 8)
			{
				whole.at(i) -= 8;
				number.push_back('1');
			}
			else if (j == 1)
				number.push_back('0');
			else if (whole.at(i) >= 4)
			{
				whole.at(i) -= 4;
				number.push_back('1');
			}
			else if (j == 2)
				number.push_back('0');
			else if (whole.at(i) >= 2)
			{
				whole.at(i) -= 2;
				number.push_back('1');
			}
			else if (j == 3)
				number.push_back('0');
			else if (whole.at(i) >= 1)
			{
				whole.at(i) -= 1;
				number.push_back('1');
			}
			else if (j == 4)
				number.push_back('0');
			j++;
		}

	}
	if (fraction.size())
		number.push_back('.');
	for (int i = 0; i < fraction.size(); i++)
	{
		int j = 1;
		while (fraction.at(i) > 0 || j < 5)
		{
			if (fraction.at(i) >= 8)
			{
				fraction.at(i) -= 8;
				number.push_back('1');
			}
			else if (j == 1)
				number.push_back('0');
			else if (fraction.at(i) >= 4)
			{
				fraction.at(i) -= 4;
				number.push_back('1');
			}
			else if (j == 2)
				number.push_back('0');
			else if (fraction.at(i) >= 2)
			{
				fraction.at(i) -= 2;
				number.push_back('1');
			}
			else if (j == 3)
				number.push_back('0');
			else if (fraction.at(i) >= 1)
			{
				fraction.at(i) -= 1;
				number.push_back('1');
			}
			else if (j == 4)
				number.push_back('0');
			j++;
		}
	}
	while (number[0] != '1')
		number.erase(number.begin());
	while (number[number.length() - 1] != '1')
		number.pop_back();
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << number << endl;

}
int inv_hex(char sample)
{
	switch (toupper(sample))
	{
	case 'A':
		return 10;
	case 'B':
		return 11;
	case 'C':
		return 12;
	case 'D':
		return 13;
	case 'E':
		return 14;
	case 'F':
		return 15;
	default:
		return sample - '0';
	}
	
}

