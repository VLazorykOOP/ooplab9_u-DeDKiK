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

        
//     Завдання 3 

struct Client {
    int month;
    int year;
    int code;
    int duration;
};

int main() {
    std::vector<Client> clients = {
        {1, 2022, 1, 2},
        {2, 2022, 2, 1},
        {1, 2022, 3, 3},
        {3, 2022, 4, 2},
        {2, 2022, 5, 3},
        {3, 2022, 6, 2},
        {1, 2023, 7, 4},
        {2, 2023, 8, 3},
        {3, 2023, 9, 2},
        {1, 2023, 10, 5},
        {2, 2023, 11, 3},
        {3, 2023, 12, 2}
    };

    auto max_duration_client = std::max_element(clients.begin(), clients.end(),
        [](const Client& c1, const Client& c2) {
            if (c1.duration != c2.duration) {
                return c1.duration < c2.duration;
            }
            else if (c1.year != c2.year) {
                return c1.year < c2.year;
            }
            else {
                return c1.month < c2.month;
            }
        });

    std::cout << "Max duration: " << max_duration_client->duration << std::endl;
    std::cout << "Month: " << max_duration_client->month << std::endl;
    std::cout << "Year: " << max_duration_client->year << std::endl;
    std::cout << "Code: " << max_duration_client->code << std::endl;

    return 0;
}
