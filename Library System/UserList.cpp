#include "UserList.h"
static int delete_counter=0;
UserList::UserList(){
    this->capacity=0;
    users=new User[capacity];

};
UserList::UserList(int capacity)
{
    this->capacity=capacity;
    users=new User[capacity];
    for(int i=0; i<capacity; i++)
    {
        users[i].setAge(0);
        users[i].setId(0);
        users[i].setName("");
        users[i].setEmail("");
        users[i].setPassword("");

    }
}
void UserList::addUser(User user)
{

    users[usersCount]=user;
    usersCount++;
}

UserList::UserList(const UserList&lst){
for(int i=0;i<this->capacity;i++){
    this->users[i].setAge(lst.users[i].getAge());
        this->users[i].setId(lst.users[i].getId());
    this->users[i].setEmail(lst.users[i].getEmail());

        this->users[i].setPassword(lst.users[i].getPassword());


}


}

User& UserList::searchUser(string name)
{
    User *temp=new User();
    for(int i=0; i<capacity; i++)
    {
        if(name==users[i].getName())
        {

            *temp=users[i];
        }
    }
    return *temp;
}

User& UserList::searchUser(int id )
{
    User *temp=new User();
    for(int i=0; i<capacity; i++)
    {
        if(id==users[i].getId())
        {

            *temp=users[i];
        }
    }
    return *temp;

}
    void UserList::deleteUser(int id){
        int index=0;
        bool flag=false;
        for(int i=0;i<capacity;i++){
            if(id==users[i].getId()){
            index=i;
            flag=true;
            break;
            }
        }
if(flag ==true){
    for(int i=0;i<capacity;i++){
            if(i==index){
                for(int j=i;j<capacity-1;j++){
                    users[j]=users[j+1];
                }
            }
        }
        delete_counter++;
        usersCount--;
}
    }


void UserList::print()
{
    for(int i=0; i<capacity; i++)
    {
        cout<<users[i]<<endl;
    }

}
ostream &operator<<( ostream &output, UserList &userList ){
for(int i=0;i<userList.usersCount;i++){
        output<<"======User"<<i+1<<"======="<<endl;
    output<<"Name:"<<" "<<userList.users[i].getName()<<endl;
    output<<"Email:"<<" "<<userList.users[i].getEmail()<<endl;
    output<<"Id:"<<" "<<userList.users[i].getId()<<endl;
    output<<"Age:"<<" "<<userList.users[i].getAge()<<endl;




}
}

UserList ::~UserList()
{
    delete []users;

}

