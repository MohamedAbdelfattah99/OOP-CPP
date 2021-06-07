#include "User.h"
using namespace std ;
#include <iostream>
int User::count1 = 0;


User::User()
{
    name = "";
    age = 0 ;
    id = 0;
    password = "";
    email = "";
};
User::User(string name, int age, string email, string password)
{
    this->name = name;
    this->age = age;
    this->email = email;
    this->password = password;
    User::count1++;
    this->id = count1;
};

User::User(const User&user)
{
    this->id = user.id;
    this->name = user.name;
    this->age = user.age;
    this->email = user.email;
    this->password = user.password;

};
bool User::operator==(const User& user)
{
    return name == user.name && age == user.age && email == user.email &&password ==user.password &&id==user.id;
}
void User:: setName (string name )
{
    this->name = name;
}
string User:: getName ()
{
    return name;
}

void User:: setPassword (string password)
{
    this->password = password;
}
string User:: getPassword ()
{
    return password;
}
void User:: setEmail (string email )
{
    this->email = email;
}
string User:: getEmail ()
{
    return email;
}
void  User:: setAge(int age )
{
    this->age = age;
}
int User:: getAge ()
{
    return age;
}
void User::setId(int id)
{
    this->id = id;
}
int User:: getId()
{
    return id;
}


ostream &operator<<(ostream &output, const User &user)
{
    output << "ID:" << " " <<user.id << " "<<"Name:" << " " <<user.name <<" " <<"Email:" << " " <<user.email << " "<<"Age:" << " " <<user.age<<" "<<"Password:" << " " <<user.password ;
    cout<<endl;
}
istream &operator>>( istream &input, User &user )
{
    cout<<"Enter Name Age Email password"<<endl;
    input >> user.name >> user.age >> user.email >> user.password;
    User::count1++;
    int x = User::count1;
    user.id = x;
}

