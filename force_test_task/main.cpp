#include <iostream>
#include "MatPoint.h"

void start()
{
    LibMatPoint::mat_point::DynValues dyn_values;

    double mass = 50; // кг
    double force_x = 300; // Н
    double coord_x_0 = 0; // м
    double vel_x_0 = 0; // м
    double dt = 0.01;
    double t0 = 0;
    double end_time = 30; // с

    double time = t0;

    dyn_values.coord_x = coord_x_0;
    dyn_values.vel_x = vel_x_0;

    LibMatPoint::mat_point calculate (force_x / mass, dt);
    calculate.run(time, dt, end_time, dyn_values);

    std::cout << "\nx = " << dyn_values.coord_x 
        << "  Vx = " << dyn_values.vel_x 
        << "  t = " << time;
}

void main()
{
    system("chcp 1251>nul"); // windows-кодировка в консоли
    start();


    // TODO вынести начальные условия в отдельный файл

    // функция фывода в файл  if (time_moment % 0.1 == 0 )

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
