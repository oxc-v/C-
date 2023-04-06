#include <iostream>
#include <string>

using namespace std;

char* strcpy(char* dest, const char* src)
{
    if (dest == nullptr || src == nullptr)
        return nullptr;

    char* ret = dest;
    while ((*dest++ = *src++) != '\0');

    return ret;
}

int main(int argc, char* argv[])
{
    

    return 0;
}