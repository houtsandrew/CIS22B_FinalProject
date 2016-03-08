#define _CRT_SECURE_NO_WARNINGS
#include "BookDatabase.h"

BookDatabase::BookDatabase()
{
	books = new Book[1024];
	identifierCount = 1;
	size = 0;
	databaseFile = "database.txt";
}

BookDatabase::~BookDatabase()
{
	delete[] books;
}

void BookDatabase::readFile()
{
	try
	{
		ifstream fin;
		fin.open(databaseFile);
		if (fin.fail())
		{
			throw "Failed to open " + databaseFile + " for reading.\n";
		}

		fin >> identifierCount;
		fin >> size;

		string tempAuthor, tempDateAdded, tempIsbn, tempPublisher, tempTitle;
		int tempIdentifier;
		double tempRetailPrice, tempWholesaleCost;

		for (int i = 0; i < size; i++)
		{
			fin.ignore();
			getline(fin, tempAuthor);
			fin.ignore();
			getline(fin, tempDateAdded);
			fin >> tempIdentifier;
			fin.ignore();
			getline(fin, tempIsbn);
			fin.ignore();
			getline(fin, tempPublisher);
			fin >> tempRetailPrice;
			fin.ignore();
			getline(fin, tempTitle);
			fin >> tempWholesaleCost;
			books[i].setAll(tempTitle, tempAuthor, tempIsbn, tempPublisher, tempWholesaleCost, tempRetailPrice, tempDateAdded, tempIdentifier);
		}
	}
	catch (string e)
	{
		cout << e;
	}
}

void BookDatabase::writeFile()
{
	try
	{
		// if file already exists, renames it to file.bak
		// if file.bak already exists, delete it
		ifstream ifile(databaseFile.c_str());
		if (ifile)
		{
			string newName = databaseFile + ".bak";
			ifstream bakIsFile(newName.c_str());
			if (bakIsFile)
			{
				remove(newName.c_str());
			}
			rename(databaseFile.c_str(), newName.c_str());
		}

		ofstream fout;
		fout.open(databaseFile);
		if (fout.fail())
		{
			throw "Failed to open " + databaseFile + " for writing.\n";
		}

		fout << identifierCount << endl;
		fout << size << endl;
		for (int i = 0; i < size; i++)
		{
			fout << books[i].getAuthor() << endl;
			fout << books[i].getDateAdded() << endl;
			fout << books[i].getIdentifier() << endl;
			fout << books[i].getIsbn() << endl;
			fout << books[i].getPublisher() << endl;
			fout << books[i].getRetailPrice() << endl;
			fout << books[i].getTitle() << endl;
			fout << books[i].getWholesaleCost() << endl;
		}
	}
	catch (string e)
	{
		cout << e;
	}
}

const void BookDatabase::setDatabaseFile(string file)
{
	databaseFile = file;
}

string BookDatabase::getDatabaseFile()
{
	return databaseFile;
}

void BookDatabase::addBook(Book book)
{
	books[size].setAll(book.getTitle(), book.getAuthor(), book.getIsbn(), book.getPublisher(),
		book.getWholesaleCost(), book.getRetailPrice(), book.getDateAdded(), identifierCount);
	identifierCount++;
	size++;
}
int BookDatabase::getPrice(int identifier)
{
	return 0;
}
void BookDatabase::printBook(int identifier)
{

}
void BookDatabase::printISBN(string isbn)
{

}
const Book * BookDatabase::getBooks()
{
	return books;
}
int BookDatabase::getSize()
{
	return size;
}
void BookDatabase::removeBook(int isbn)
{

}
int BookDatabase::searchIdentifier(int identifier)
{
	int count = 0;
	while (count < size)
	{
		if (books[count].getIdentifier() == identifier)
		{
			return count;
		}
		count++;
	}
	return -1;
}

int BookDatabase::operator[](int i)
{
	return searchIdentifier(i);
}

int BookDatabase::sellBook(int identifier)
{
	return 0;
}

