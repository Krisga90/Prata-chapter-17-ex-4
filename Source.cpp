#include <iostream>
#include <fstream>
#include <string>


bool open_read_file(std::ifstream &file, const char * file_name);
bool open_write_file(std::ofstream &file, const char * file_name);
void write_file(std::ofstream &file_w, std::ifstream &file_r_1, std::ifstream &file_r_2);
std::string name(int number);

/////////////////////
int main()
{
	std::string r_file_name_1, r_file_name_2;
	std::ifstream r_file_1, r_file_2;
	r_file_name_1 = name(1);
	r_file_name_2 = name(2);
	if (!open_read_file(r_file_1, r_file_name_1.c_str()) || !open_read_file(r_file_2, r_file_name_2.c_str()))
	{
		std::cout << "pliki o podanej nazwie nie znajduja sie w odpowiednim katalogu" << std::endl;
		std::cin.get();
		return 1;
	}
	std::ofstream w_file;
	std::string w_file_name;

	w_file_name = name(0);
	if (!open_write_file(w_file, w_file_name.c_str()))
	{
		return 1;
		std::cin.get();
	}
	
	write_file(w_file, r_file_1, r_file_2);

	
	std::cin.get();
	return 0;

}
////////////////



bool open_read_file(std::ifstream &file,const char * file_name)
{
	file.open(file_name);
	if (!file.is_open())
	{
		std::cout << "nieudana proba otwarcia pliku wejsciowego, " << file_name<<std::endl;
		return false;
	}
	return true;
}

bool open_write_file(std::ofstream &file,const char * file_name)
{
	file.open(file_name);
	if (!file.is_open())
	{
		std::cout << "nieudana proba otwarcia pliku wyjsciowego, " << file_name << std::endl;
		return false;
	}
	return true;
}

void write_file(std::ofstream &file_w, std::ifstream &file_r_1, std::ifstream &file_r_2)
{
	char ch;
	while (!file_r_1.eof() && !file_r_2.eof())
	{
		while (file_r_1.get(ch) && ch != '\n')
			file_w.put(ch);
		file_w.put(' ');
		while (file_r_2.get(ch) && ch != '\n')
			file_w.put(ch);
		file_w<< "\n";

		file_r_1.peek();	//modificates flags
		file_r_2.peek();
	
	}
	while (!file_r_1.eof())
	{
		while (file_r_1.get(ch) && ch != '\n')
			file_w.put(ch);
		file_w <<"\n";
		file_r_1.peek();

	}
	while (!file_r_2.eof())
	{
		while (file_r_2.get(ch) && ch != '\n')
			file_w.put(ch);
		file_w << "\n";
		file_r_2.peek();
	}
	file_r_1.close();
	file_r_2.close();
	file_w.close();
}

std::string name(int number)
{
	std::string temp;
	if (number > 0)
	{
		std::cout << "Podaj nazwe " << number << " pliku do odczytu: ";
		std::cin >> temp;
		while (std::cin.get() != '\n')
			continue;
	}

	if (number == 0)
	{
		std::cout << "Podaj nazwe pliku do zapisu: ";
		std::cin >> temp;
		while (std::cin.get() != '\n')
			continue;
	}
	return temp;
}