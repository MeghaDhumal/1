#include"Student.h"
#include<conio.h>
#include<fstream>
using namespace std;
class FileIOOperations
{
public:
	static void WriteRecord()
	{
		char wish;
		fstream fs;
		Student s;
		fs.open("StudentData.dat", 
			ios::out | ios::binary);
		do
		{
			s.accept();
			fs.write((char*)&s, 1 * sizeof(Student));
			cout << "\n Do you want add more records";
			cin >> wish;
		} while (wish == 'y' || wish == 'Y');
		fs.close();
	}
	static void ReadRecords()
	{
		fstream fs;
		Student s;
		fs.open("StudentData.dat", ios::in | ios::binary);
		while (fs.read((char*)&s, 1 * sizeof(Student)))
		{
			s.display();
			cout <<"\n The current position of get pointer "
				<< fs.tellg();
		}
		fs.close();
	}

	static bool SearchRecord(int rno)
	{
		fstream fs;
		Student s;
		fs.open("StudentData.dat", ios::in | ios::binary);
		while (fs.read((char*)&s, 1 * sizeof(Student)))
		{
			if (s.getRollNo() == rno)
			{
				s.display();
				fs.close();
				return true;
			}
		}		
		fs.close();
		return false;
	}

	static bool SearchRandom(int rno)
	{
		fstream fs;
		Student s;
		fs.open("StudentData.dat", ios::in | ios::binary);
		cout << "\n The current position of get pointer "
			<< fs.tellg();
		fs.seekg((rno - 1) * sizeof(Student), ios::beg);
		fs.read((char*)&s, 1 * sizeof(Student));
		s.display();
		return true;

	}
};

int main()
{
	bool res;
	int choice;
	char wish;
		do
		{
			cout << "\n 1. Write into File \n " <<
				"2. Read from file \n 3. Search Record "<<
				"\n 4. Search random \n 5.Exit";
			cout << "\n Enter the choice::";
			cin >> choice;
			switch (choice)
			{
			case 1:
				FileIOOperations::WriteRecord();
				break;
			case 2:
				FileIOOperations::ReadRecords();
				break;
			case 3:
				int rno;
				cout << "\n Enter the roll no of record to search";
				cin >> rno;
				res=FileIOOperations::SearchRecord(rno);
				if (res)
				{
					cout << "\n Record found";
				}
				else
				{
					cout << "\n Record Not found";
				}
				break;
			case 4:
				
				cout << "\n Enter the roll no of record to search";
				cin >> rno;
				res = FileIOOperations::SearchRandom(rno);
				break;
			case 5:

				exit(0);

			}
			cout << "\n Do you want perform file operations";
			cin >> wish;
		} while (wish == 'y' || wish == 'Y');
	

	_getch();
	return 0;
}
