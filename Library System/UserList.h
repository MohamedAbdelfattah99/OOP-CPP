#ifndef USERLIST_H
#define USERLIST_H
#include "User.h"
using namespace std ;
#include <iostream>

class UserList
{
private:
    User* users;
    int capacity;
    int usersCount=0;
public:
    UserList();
    UserList(int capacity);
    void addUser(User user);
    User& searchUser(string name);
    User& searchUser(int id);
    UserList(const UserList&lst);

    void deleteUser(int id);
    friend ostream &operator<<( ostream &output, UserList &userList );
    ~UserList();
void print();
};

#endif // USERLIST_H
