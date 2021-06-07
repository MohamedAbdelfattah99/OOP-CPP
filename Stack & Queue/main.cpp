#include <iostream>
using namespace std;
#include <limits>
template<class t>

class MyList
{
protected:
 int size;
    t *lst;
public:

    MyList(int s)
    {
        this->size=s;
        lst=new t[s];

    }
    ~MyList()
    {
        delete[]lst;
    }
    int getSize()
    {
    }
    virtual void addElem(t elem) const
    {
    }
    virtual t  getElem() const
    {
    }
    virtual bool isEmpty () const
    {
    }
    virtual bool isFull() const
    {
    }
    virtual void clearItems()
    {
    }
};
template<class t>

class MyStack : public MyList<t>
{

private:
    int top;
public:
    MyStack(int size):MyList<t>(size)
    {
        top=-1;
        this->size=size;
        this->lst=new t [size];
    }
    int getSize()
    {
        return this->top;

    }
    bool isEmpty()
    {
        bool flag=false;
        if(top==-1)
        {
            flag=true;
        }
        return flag;
    }
    bool isFull()
    {
        bool flag=false;
        if(top>=this->size)
        {
            flag=true;
        }
        return flag;
    }
    void addElem(t elem)
    {
        bool flag=isFull();
        try
        {
            if(flag==true)
            {
                throw "full";
            }
        }
        catch(...)
        {
            cout<<"stack is full"<<endl;
        }

        if(flag==false)
        {
            top++;
            this->lst[top]=elem;
        }

    }
    t getElem()
    {
        t temp;
        if(isEmpty())
            return 0;
        temp=this->lst[top];
        --top;
        return temp;
    }
    void clearItems()
    {
        top=-1;
        this->lst=new t[0];
    }
    void print()
    {
        try
        {
            if(top==-1)
            {
                throw "empty";
            }
        }
        catch(...)
        {
            cout<<"no elements in the stack"<<endl;

        }
        for(int i=top; i>=0; i--)
        {
            cout<<"item: "<<this->lst[i]<<endl;
        }
        cout<<endl;
    }

};
template<class t>

class MyQueue:public MyList<t>
{
private:
    int front;
    int counter;
public:
    MyQueue(int size):MyList<t>(size)
    {
        front=0;
        counter=0;
        this->size=size;
        this->lst=new t [size];
    }
    int getSize()
    {
        return this->front;

    }
    bool isEmpty()
    {
        bool flag=false;
        if(counter==0)
        {
            flag=true;
        }
        return flag;
    }
    bool isFull()
    {
        bool flag=false;
        if(counter==this->size)
        {
            flag=true;
        }
        return flag;
    }
    void addElem(t elem)
    {
        bool flag=isFull();
        try
        {
            if(flag==true)
            {
                throw "full";
            }
        }
        catch(...)
        {
            cout<<"Quee is full"<<endl;
        }

        if(flag==false)
        {

            this->lst[counter]=elem;
            counter++;
        }

    }
    t getElem()
    {
        t temp;
        if(isEmpty())
            return 0;
        temp=this->lst[front];
        this->front++;
        return temp;
    }
    void clearItems()
    {
        counter=0;;
        this->lst=new t[0];
    }
    void print()
    {
        try
        {
            if(counter==0)
            {
                throw "empty";
            }
        }
        catch(...)
        {
            cout<<"no elements in the quee"<<endl;

        }
        for(int i=front; i<counter; i++)
        {
            cout<<"item :"<<this->lst[i]<<endl;
        }
        cout<<endl;
    }

};

class Rectangle
{
    int length;
    int width;
public:
    Rectangle()
    {
        length=0;
        width=0;
    }
    Rectangle(int l,int w)
    {
        if(l<0||w<0)
        {
            throw error();
        }
        length=l;
        width=w;

    }
    int getLength()
    {
        return length;
    }
    int getWidth()
    {
        return width;
    }
    int getArea()
    {
        return (width*length);
    }
    friend ostream& operator<<(ostream& out,const Rectangle&r);

    class error {};

};
ostream& operator<<(ostream& out, Rectangle&r)
{
    out<<"Rect Length "<<r.getLength()<<endl<<"Rect width "<<r.getWidth()<<endl<<"Rect area "<<r.getArea()<<endl;
    return out;

}

book operator++(const obj&p1){
}
int main()
{

    cout<<"1 for Quee 2 for Stack"<<endl;
    int n,items,c;
    cin>>n;
    cout<<"How many items"<<endl;
    try
    {
        cin>>items;
        if(items<=0)
        {
            throw "wrong";
        }
    }
    catch(...)
    {
        cout<<"Number of items cannot be 0 or less"<<endl;
    }
    cout<<"1 for integers 2 for Strings 3 for Rectangle"<<endl;
    cin>>c;

    if(n==1) ///quee
    {
        if(c==1)
        {
            MyQueue <int>qt(items);
            for(int i=0; i<items; i++)
            {
                cout<<"enter int numbers "<<endl;
                int z;
                  try
                {
                    cin>>z;
                    if(!cin)
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw "error";
                    }
                }
                catch(...)
                {
                    cout<<"invalid number set it 0"<<endl;
                    z=0;
                }
                qt.addElem(z);
            }

            qt.print();
        }
        if(c==2)
        {
            MyQueue<string>qt(items);
            for(int i=0; i<items; i++)
            {
                cout<<"enter strings "<<endl;
                string z;
                cin>>z;
                qt.addElem(z);
            }

            qt.print();
        }
        if(c==3)
        {

            MyQueue<Rectangle>qt(items);

            for(int i=0; i<items; i++)
            {
                cout<<"enter rectangle len and with "<<endl;
                int l,w;
                try
                {
                    cin>>l>>w;
                    Rectangle temp(l,w);
                    qt.addElem(temp);

                }
                catch(Rectangle::error)
                {
                    cout<<"Invalid values for len or width"<<endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

            }
            qt.print();
        }

    }
    if(n==2) ///stack
    {
        if(c==1)
        {
            MyStack <int>st(items);
            for(int i=0; i<items; i++)
            {
                cout<<"enter int numbers "<<endl;
                int z;
                try
                {
                    cin>>z;
                    if(!cin)
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw "error";
                    }
                }
                catch(...)
                {
                    cout<<"invalid number set it 0"<<endl;
                    z=0;
                }
                st.addElem(z);
            }
            st.print();
        }
        if(c==2)
        {
            MyStack<string>st(items);
            for(int i=0; i<items; i++)
            {
                cout<<"enter strings "<<endl;
                string z;
                cin>>z;
                st.addElem(z);
            }

            st.print();
        }
        if(c==3)
        {

            MyStack<Rectangle>st(items);
            for(int i=0; i<items; i++)
            {
                cout<<"enter rectangle len and with "<<endl;
                int l,w;
                try
                {
                    cin>>l>>w;
                    Rectangle temp(l,w);
                    st.addElem(temp);

                }
                catch(Rectangle::error)
                {
                    cout<<"Invalid values for len or width"<<endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                st.print();
            }

        }
    }
}






