#define _CRT_SECURE_NO_WARNINGS
#include "Cashier.h"




Cashier::Cashier()
{
}
Cashier::Cashier(BookDatabase* dtbs)
{
	database = dtbs;
}

void Cashier::listIsbn(string isbn)
{
	Book * books = database->getBooks();
	for (int i = 0; i < database->getSize(); i++)
	{
		if (books[i].getIsbn() == isbn)
		{
			cout << books[i];
		}
	}
}


void Cashier::addBookMenu()
{
	cout << "Enter in the ISBN of the book you want to purchase: " << endl;
	string isbn;
	cin >> isbn;
	listIsbn(isbn);
}

void Cashier::removeBookFromCart(int identifier)
{
	int count = 0;
	bool condition = false;
	while (count < cartSize - 1)
	{
		if (condition)
		{
			cart[count] = cart[count++];
		}
		else if (cart[count] == identifier)
		{
			cart[count] = cart[count++];
			condition = true;
		}
		count++;
	}
	cartSize--;
		
}
void Cashier::removeBookMenu()
{
	for (int i = 0; i < cartSize; i++)
	{
		cout << &database[cart[i]];
	}
	cout << "What book would you like to remove?" << endl;
	int identifier = 0;
	cin >> identifier;
	for (int i = 0; i < cartSize; i++)
	{
		if (identifier == cart[i])
		{
			char choice;
			cout << "You have chosen to remove " << &database[cart[i]] << " from you list. Is this acceptable? (y/n)" << endl;
			cin >> choice;
			if (choice == 'y')
			{
				cout << "This book will be removed from your cart. " << endl;
				removeBookFromCart(identifier);
			}
			if (choice == 'n')
			{
				cout << "You will move back to the main menu." << endl;
			}
		}
	}
	system("PAUSE");
}
void Cashier::checkout()
{
	double subtotal = 0;
	for (int i = 0; i < cartSize; i++)
	{
		subtotal += database->getPrice(cart[i]);
	}
	cout << "Serendipity Book Sellers" << endl << endl;
	cout << "Date: " << endl << endl;
	cout << "      ISBN              Title				   Price       " << endl;
	cout << "____________________________________________________________" << endl << endl;
	for (int i = 0; i < cartSize; i++)
	{
		Book* book = database->searchIdentifier(cart[i]);
		cout << book->getIsbn() << "\t" << book->getTitle() << "\t" << book->getRetailPrice();
	}
	cout << "   069-12331-123   Living like a God: Travis Pham    $69.99" << endl;
	
	cout << "\t\t\t\t\t____________________" << endl << endl;
	cout << "\t\t\t\t\tSubtotal: " << subtotal << endl << "\t\t\t\t\tTax: " << "Sales Tax @ 6.25%: " << (subtotal * 0.0625) << endl << "\t\t\t\t\tTotal: " << subtotal + subtotal*0.0625 << endl;
	cout << endl << "Thank You for Shopping at Serendipity!" << endl;
	system("PAUSE");
}
void Cashier::mainMenu()
{
	bool done = false;
	while (!done)
	{
		cout << "What would you like to do?" << endl << endl << "Press '1' to add a book. " << endl << "Press '2' to go to checkout." << endl << "Press '3' to remove a book." << endl << "Press '4' to go back of the menu." << endl;
		int choice = 0;
		cin >> choice;
		if (choice == 1)
		{
			addBookMenu();
		}
		else if (choice == 2)
		{
			checkout();
		}
		else if (choice == 3)
		{
			removeBookMenu();
		}
		else if (choice == 4)
		{
			done = true;
		}
		else
		{
			cout << "Invalid choice! ";
		}
	}
}

