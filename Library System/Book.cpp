#include "Book.h"
#include "User.h"

using namespace std ;
#include <iostream>
int Book::count = 0;
double static cn=0;
  Book::Book()
    {
        title = "";
        isbn = "" ;
        id = 0;
        category = "";
        averageRating =0;

    };
      Book::Book(string title, string isbn, string category){
            this->title=title;
            this->isbn=isbn;
            this->category=category;
            Book::count++;
            this->id=Book::count;
                this->averageRating=0;
        }
        void Book::print(){
        cout<<this->id<<" "<<this->title<<" "<<this->isbn<<" "<<this->category<<endl;

        }
  Book::Book(const Book& book)
  {

        id = book.id;
        title = book.title;
        isbn = book.isbn;
        category = book.category;
        averageRating=book.averageRating;
        author=book.author;

  }
void Book::setTitle (string name )
    {
        this->title = name;
    }
    string Book::getTitle()
    {
        return title;
    }
void Book::setISBN(string isbn )
    {
        this->isbn = isbn;
    }
    string Book::getISBN()
    {
        return isbn;
    }
    void Book::setCategory (string name )
    {
        this->category = name;
    }
    string Book::getCategory()
    {
        return category;
    }
    void Book::setId(int id  )
    {
        this->id = id;
    }
    int Book::getId()
    {
        return id;
    }
    void Book::setAuthor(User user){
        author=user;
    }
    User Book::getAuthor()
    {
        return author;
    }
double Book::getAva(){
return averageRating;
}
    void Book::rateBook(int rating){
        double temp=(this->averageRating*this->numofratings)+rating;
        this->numofratings++;
        this->averageRating=temp/this->numofratings;

    }

    bool Book::operator==(const Book& book){
        if(this->title==book.title && this->isbn==book.isbn && this->category==book.category &&this->author==book.author){
            return true;
        }
        else{
            return false;
        }



    }

ostream &operator<<(ostream &output, const Book &book)
{
    output <<"Id:  "<< book.id<<endl<<"Title:  " <<book.title <<endl<<"Isbn:  " <<book.isbn<<endl<<"category:  "<<book.category<<endl<<"avarage: "<<book.averageRating;
  //  if(temp.getName()!="")
   // {
        output<<endl<<"Author Info"<<" "<<book.author;
   // }


    output<<endl;
}

istream &operator>>( istream &input, Book &book ){
    cout<<"Enter Tittle ISBN Category"<<endl;
   input >> book.title>> book.isbn >> book.category;
   Book::count++;
   int x = Book::count;
   book.id = x;
 }


