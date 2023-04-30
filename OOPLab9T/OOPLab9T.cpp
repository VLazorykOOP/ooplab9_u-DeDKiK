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
    
    // Завдання 2

    int main() {
    std::vector<int> V0 = { 1, 2, 3 };
    int N = 3;
    std::vector<std::vector<int>> V = { {1, 2, 3}, {2, 3, 4}, {1, 2, 3, 4} };

    int count = 0;
    std::vector<int> setV0(V0.begin(), V0.end());
    for (int i = 0; i < N; i++) {
        std::vector<int> setVI(V[i].begin(), V[i].end());
        if (std::includes(setVI.begin(), setVI.end(), setV0.begin(), setV0.end())) {
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;

}
