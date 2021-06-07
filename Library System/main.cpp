#include <iostream>
#include "User.h"
#include "Book.h"
#include "UserList.h"
#include "BookList.h"
using namespace std;
///Authors: Mohamed Abdelfattah && Mohamed Ashraf
int main()
{

    cout<<"Enter User list size"<<endl;
    int userSize;
    cin>>userSize;
    UserList user_list(userSize);
    cout<<"Enter Book list size"<<endl;
    int book_size;
    cin>>book_size;
    BookList book_list(book_size);
    while(true)
    {
        int choice;
        cout<<"Select One of follwing:"<<endl<<"1-Book menu"<<endl<<"2-user menu"<<endl<<"3:exit"<<endl;
        cin>>choice;
        bool flag=false;
        if(choice==1)
        {
            while (true)
            {
                cout<<"Book Menu"<<endl<<"1-Create book and add it to the list"<<endl<<"2-search for a book"<<endl<<"3-display all books"<<endl;
                cout<<"4-Get the hight rating book"<<endl<<"5-Get all books for user"<<endl<<"6-Copy a book list to a new list"<<endl;
                cout<<"7-back to main menu"<<endl;
                int x;
                cin>>x;
                if(x==7)
                {
                    break;

                }
                if(x==1)
                {
                    Book temp;
                    cin>>temp;
                    cout<<"1-assign author"<<endl<<"2-continue"<<endl;
                    int n;
                    cin>>n;
                    if(n==1)
                    {
                        int id;
                        cout<<"enter user id"<<endl;
                        cin>>id;
                        User u1=user_list.searchUser(id);
                        temp.setAuthor(u1);

                    }

                    book_list.addbook(temp);

                    if(n==2)
                    {
                        continue;
                    }
                }
                if(x==2)
                {
                    cout<<"1-Search by id"<<endl<<"2-Search by name"<<endl<<"3-To back to Book Menu"<<endl;
                    int y;
                    cin>>y;
                    if(y==1)
                    {

                        cout<<"Enter Id"<<endl;
                        int id;
                        cin>>id;
                        Book b1=book_list.searchBook(id);
                        int index=book_list.index(b1);
                        cout<<b1;
                        cout<<"1-update author"<<endl<<"2-update name"<<endl<<"3-update category"<<endl<<"4-Delete book"<<endl;
                        cout<<"5-Rate book"<<endl<<"6-go back to book menu"<<endl;

                        int n;
                        cin>>n;
                        if(n==1)
                        {
                            User temp;
                            cout<<"Update Author info"<<endl;
                            cin>>temp;
                            book_list[index].setAuthor(temp);
                        }
                        if(n==2)
                        {
                            string name;
                            cout<<"Enter New book Name"<<endl;
                            cin>>name;
                            book_list[index].setTitle(name);

                        }
                        if(n==3)
                        {
                            string cat;
                            cout<<"Enter new book category"<<endl;
                            cin>>cat;
                            book_list[index].setCategory(cat);
                        }
                        if(n==4)
                        {
                            book_list.deleteBook(id);
                        }
                        if(n==5)
                        {
                            int rate;
                            cout<<"Enter Book rate"<<endl;
                            cin>>rate;
                            book_list[index].rateBook(rate);
                        }
                        if(n==6)
                        {
                            continue;
                        }
                    }
                    if(y==2)
                    {
                        cout<<"Enter Name"<<endl;
                        string name;
                        cin>>name;
                        Book b1=book_list.searchBook(name);
                        cout<<b1;
                        cout<<"1-delete book"<<endl<<"2-back to book menu"<<endl;
                        int n;
                        cin>>n;
                        if(n==1)
                        {
                            int id=b1.getId();
                            book_list.deleteBook(id);
                        }
                        if(n==2)
                        {
                            continue;
                        }
                    }
                }
                if(x==3)
                {
                    cout<<book_list;
                }
                if(x==4)
                {
                    Book temp=book_list.getTheHighestRatedBook();
                    cout<<temp;
                }
                if(x==5)
                {
                    int id;
                    cout<<"enter user id "<<endl;
                    cin>>id;

                    User u1=user_list.searchUser(id);
                    Book *temp;
                    temp=book_list.getBooksForUser(u1);
                    //cout<<temp<<endl;


                }
                if(x==6)
                {
                    BookList newlist(book_size);
                    newlist=book_list;
                    cout<<"New list"<<endl;
                    cout<<newlist;
                }
            }
        }
        if(choice==2)
        {

            while (true ||flag==true)
            {
                flag=false;
                cout<<"User Menu"<<endl<<"1-Create user and add it to the list"<<endl<<"2-search for a user"<<endl<<"3-display all users"<<endl<<"4:Back to main menu"<<endl;
                int x;
                cin>>x;
                if(x==4)
                {
                    break;
                }
                if(x==1)
                {

                    User temp;
                    cin>>temp;
                    user_list.addUser(temp);
                }
                if(x==2)
                {
                    cout<<"1-Search by id"<<endl<<"2-Search by name"<<endl<<"3-To back to User Menu"<<endl;
                    int y;
                    cin>>y;
                    if(y==1)
                    {
                        cout<<"Enter Id"<<endl;
                        int id;
                        cin>>id;
                        User u1=user_list.searchUser(id);
                        cout<<u1;
                        cout<<"1-delete User"<<endl<<"2-back to user menu"<<endl;

                        int n;
                        cin>>n;
                        if(n==1)
                        {
                            user_list.deleteUser(id);
                        }
                        if(n==2)
                        {
                            flag=true;
                        }
                    }
                    if(y==2)
                    {
                        cout<<"Enter Name"<<endl;
                        string name;
                        cin>>name;
                        User u1=user_list.searchUser(name);
                        cout<<u1;
                        cout<<"1-delete User"<<endl<<"2-back to user menu"<<endl;
                        int n;
                        cin>>n;
                        if(n==1)
                        {
                            int id=u1.getId();
                            user_list.deleteUser(id);
                        }
                        if(n==2)
                        {
                            flag=true;
                        }
                    }
                    if(y==3)
                    {
                        flag=true;
                    }
                }
                if(x==3)
                {
                    cout<<user_list;
                }


            }

        }
        if(choice==3)
        {
            return 0;
        }
    }
}
