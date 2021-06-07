#include "BookList.h"
#include<cstdlib>
static int  book_counter=0;
BookList::BookList(int capacity)
{
    this->capacity=capacity;
    books=new Book[capacity];
    for(int i=0; i<capacity; i++)
    {
        books[i].setId(0);
        books[i].setISBN("");
        books[i].setTitle("");
        books[i].setCategory("");
    }
}
BookList::BookList(const BookList&lst)
{
    User temp;
    for(int i=0; i<capacity; i++)
    {
        books[i].setAuthor(lst.books[i].getAuthor());
        books[i].setISBN(lst.books[i].getISBN());
        books[i].setTitle(lst.books[i].getTitle());
        books[i].setCategory(lst.books[i].getCategory());
        books[i].setId(lst.books[i].getId());


    }

}
void BookList::addbook(Book book)
 {

    books[booksCount]=book;
    booksCount++;
}



Book& BookList::searchBook(string name)
{
    Book *temp=new Book();
    for(int i=0; i<capacity; i++)
    {
        if(name==books[i].getTitle())
        {

            *temp=books[i];
        }
    }
    return *temp;
}

Book& BookList::searchBook(int id )
{
    Book *temp=new Book();
    for(int i=0; i<capacity; i++)
    {
        if(id==books[i].getId())
        {

            *temp=books[i];
        }
    }
    return *temp;

}
void BookList::deleteBook(int id)
{
    int index=0;
    bool flag=false;
    for(int i=0; i<capacity; i++)
    {
        if(id==books[i].getId())
        {
            index=i;
            flag=true;
            break;
        }
    }
    if(flag==true)
    {
        for(int i=0; i<capacity; i++)
        {
            if(i==index)
            {
                for(int j=i; j<capacity-1; j++)
                {
                    books[j]=books[j+1];
                }
            }
        }
        book_counter++;
        booksCount--;
    }
}
Book* BookList:: getBooksForUser(User user)
{
    Book arr[booksCount];
    int x=0;
    for(int i=0;i<capacity;i++){
        if(books[i].getAuthor().getId()==user.getId()){
            arr[x]=books[i];
            x++;
        }
    }
  for(int i=0;i<x;i++){
    cout<<arr[i];
  }
    return arr;


}

Book BookList::getTheHighestRatedBook()
{
    Book temp=books[0];
    for(int i=1; i<capacity; i++)
    {
        if(books[i].getAva()>temp.getAva())
        {
            temp=books[i];
        }

    }
    return temp;
}
int BookList::index(Book b1){
int ret=0;
    for(int i=0;i<capacity;i++){
        if(b1==books[i]){
          ret=i;
          break;
        }
    }
    return ret;


}

ostream &operator<<( ostream &output, BookList &booklist )
{
    for(int i=0; i<booklist.booksCount; i++)
    {
        output<<"======book"<<i+1<<"======="<<endl;
        output<<"ID:"<<"  "<<booklist.books[i].getId()<<endl;

        output<<"Ttitle:"<<"  "<<booklist.books[i].getTitle()<<endl;

        output<<"Category:"<<"  "<<booklist.books[i].getCategory()<<endl;

        output<<"ISBN:"<<"  "<<booklist.books[i].getISBN()<<endl;
        output<<"Avarage Rating:"<<"  "<<booklist.books[i].getAva()<<endl;
        output<<"Author Info"<<" "<<booklist.books[i].getAuthor();

        output<<"==================================="<<endl;
    }
    return output;

}


Book& BookList::operator [] (int position){
    if(position<capacity && position>=0){
    return books[position];
    }
    else{
            cout<<"Index error";
            exit(1);
    }
}


BookList ::~BookList()
{
    delete []books;

}

