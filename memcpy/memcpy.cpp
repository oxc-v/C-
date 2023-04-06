#include <iostream>
#include <string>
#include <cstddef>

using namespace std;

void* memcpy(void* dest, const void* src, std::size_t n) {
    const char* s = static_cast<const char*>(src);
    char* d = static_cast<char*>(dest);

    // 处理字节不对齐的部分，一个字节一个字节复制
    while (n && (reinterpret_cast<std::size_t>(s) % alignof(std::max_align_t) != 0)) {
        *d++ = *s++;
        --n;
    }

    // 处理剩下的内存部分，使用移动字长的方式复制
    std::size_t word_size = sizeof(std::size_t);
    const std::size_t* s_word = reinterpret_cast<const std::size_t*>(s);
    std::size_t* d_word = reinterpret_cast<std::size_t*>(d);

    while (n >= word_size) {
        *d_word++ = *s_word++;
        n -= word_size;
    }

    // 处理剩下的不足一个字长的内存部分，一个字节一个字节复制
    s = reinterpret_cast<const char*>(s_word);
    d = reinterpret_cast<char*>(d_word);

    while (n--) {
        *d++ = *s++;
    }

    return dest;
}


int main(int argc, char* argv[])
{
    string str("Hello, world!");
    char* buf = new char[str.size() + 1];
    memcpy(buf, str.c_str(), str.size() + 1);
    cout << buf << endl;

    return 0;
}