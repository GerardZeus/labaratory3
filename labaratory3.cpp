#define _CRT_SECURE_NO_WARNINGS //Для того, чтобы разрешал ste::cpy
#include <iostream>
#include <cstring>// Для работы со строками

class String // Создаём класс "Строка"
{
    char* str; //Указатель на динамический массив символов
public:
    //Конструктор
    String(const char* s = "")
    {
        str = new char[std::strlen(s) + 1]; //Выделяем память для строки
        std::strcpy(str, s);// Копируем строку в динамический массив
    }
    //Конструктор копирования
    String(const String& other)
    {
        str = new char[std::strlen(other.str) + 1]; // Выделяем память для копируемой строки
        std::strcpy(str, other.str); //Копируем строку из другой строки(тавтология)
    }
    //Оператор присваивания копированием
    String& operator = (const String& other)
    {
        delete[] str; //Удаляем старую строку(чтоб избежать утечки памяти)

        str = new char[std::strlen(other.str) + 1]; //Выделяем новую память для строки
        std::strcpy(str, other.str); //Копируем строку из другой строки

        return *this; //Возвращаем текущую строку
    }
    void print() //Функция для вывода строки на экран
    {
        std::cout << str << std::endl;
    }

    //Деструктор
    ~String()
    {
        delete[] str; // Очищаем выделенную память
    }
};

int main()
{
    String a("Hello World!");
    String b = a; //Создаём строку b, применяя конструктор копирования 

    b.print();
    a.print();

    String c("Abrakadabra");
    c = a; //Присваиваем c строку a, применяя оператор присваивания копированием 

    c.print();

    return 0;
}