#ifndef BOOKLIST_H
#define BOOKLIST_H
#include "User.h"
#include "Book.h"
using namespace std ;
#include <iostream>

class BookList
{
private:
    Book* books;
    int capacity;
    int booksCount=0;
public:
    BookList(const BookList& anotherList);
    BookList(int capacity);
    int index(Book b1);
    void addbook(Book book);
    Book& searchBook(string name);
    Book& searchBook(int id);
    void deleteBook(int id);
    Book getTheHighestRatedBook();
    Book* getBooksForUser(User);
    Book & operator [] (int position);
    friend ostream &operator<<( ostream &output, BookList &booklist );
    ~BookList();

};



#endif // BOOKLIST_H
