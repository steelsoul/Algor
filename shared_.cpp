// Example program
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

template <typename T>
class myshared;

template<typename T>
struct counter 
{
    static int count;
};

template <typename T>
int counter<T>::count = 0;

template <typename T>
class myshared
{
    public:
    
    myshared()
    : ptr(new T)
    {
        cout << "created, counter: " << cntr.count << endl;
    }
    
    myshared(const myshared<T>& other)
    {        
        this->ptr = other.ptr;
        cntr.count++;
        cout << "copied, counter: " << cntr.count << endl;
    }    
    
    T& operator=(const myshared<T>& other)
    {
        if (&other != this)
        {
            this->ptr = other.ptr;
            cntr.count++;
            cout << "operator=, counter: " << cntr.count << endl;
        }
        return *this;
    }
    
    ~myshared()
    {
        if (cntr.count == 0)
        {
            cout << "removed." << endl;
            delete ptr;
        } 
        else
        {            
            cntr.count--;
            cout << "decreased counter: " << cntr.count << endl;
        }
    }
    
    T& operator*()
    {
        cout << "operator*" << endl;
        return *ptr;
    }
    
    const T& operator*() const
    {
        cout << "const operator*" << endl;
        return *ptr;
    }
    
    private:
    
    T* ptr;
    counter<T> cntr;
};

template <>
class myshared<char*>
{
    public:
    
    myshared(char* str)
    : ptr(new T[sizeof(str)/sizeof(char)])
    {
        memcpy(ptr, str, sizeof(str));
        cout << "[char*] created, counter: " << cntr.count << endl;
    }
    
    myshared(const myshared<char*>& other)
    {        
        memcpy(this->ptr, other.ptr, sizeof(other.ptr));
        cntr.count++;
        cout << "[char*] copied, counter: " << cntr.count << endl;
    }    
    
    T& operator=(const myshared<T>& other)
    {
        if (&other != this)
        {
            this->ptr = other.ptr;
            cntr.count++;
            cout << "[char*] operator=, counter: " << cntr.count << endl;
        }
        return *this;
    }
    
    ~myshared()
    {
        if (cntr.count == 0)
        {
            cout << "[char*] removed." << endl;
            delete ptr;
        } 
        else
        {            
            cntr.count--;
            cout << "[char*] decreased counter: " << cntr.count << endl;
        }
    }
    
    T& operator*()
    {
        cout << "[char*] operator*" << endl;
        return *ptr;
    }
    
    const T& operator*() const
    {
        cout << "[char*] const operator*" << endl;
        return *ptr;
    }
    
    private:
    
    T* ptr;
    counter<T> cntr;
};

int main()
{
    myshared<int> mshr;
    *mshr = 10;
    cout << "mshr: " << *mshr << endl;
    myshared<int> other = mshr;
    myshared<int> another(other);
    
    myshared<char*> strshared("string");
}
