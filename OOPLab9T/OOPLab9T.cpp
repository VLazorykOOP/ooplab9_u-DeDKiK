// OOPLab9T.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>

int main()
{
    std::cout << "Lab №9. STL. \n";
    
//     Завдання 1
    
     std::deque<int> d{ 1, 2, 3, 0, 4, 0, 5 };

    // Використовуємо зворотні ітератори для пошуку останнього нульового елемента
    auto it = std::find(d.rbegin(), d.rend(), 0);

    // Якщо нульовий елемент знайдений, то він видаляється
    if (it != d.rend()) {
        d.erase((++it).base()); // Перетворюємо зворотний ітератор в звичайний за допомогою функції-члена base()
    }

    // Виводимо результат
    for (int x : d) {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    return 0;
}
