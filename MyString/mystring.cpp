#include <iostream>
#include <string>

using namespace std;

class MyString
{
public:
    MyString(const char* data = nullptr)
    {
        if (data == nullptr) {
            data_ = new char[1];
            data_[0] = '\0';
        } else {
            int len = strlen(data);
            data_ = new char[len + 1];
            strcpy(data_, data);
        }
    }

    MyString(const MyString& other)
    {
        int len = strlen(other.data_);
        data_ = new char[len + 1];
        strcpy(data_, other.data_);
    }

    MyString& operator=(const MyString& other)
    {
        if (this == &other)
            return *this;

        delete[] data_;

        int len = strlen(other.data_);
        data_ = new char[len + 1];
        strcpy(data_, other.data_);
    }

    ~MyString()
    {
        delete[] data_;
    }

    int Size() const
    {
        return strlen(data_);
    }

    const char* Data() const
    {
        return data_;
    }

private:
    char* data_;
};

int main(int argc, char* argv[])
{


    return 0;
}