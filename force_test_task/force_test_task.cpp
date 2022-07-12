// force_test_task.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Dynamics.h"

void test()
{
    LibDynamics::Dynamics::Input input{0,0,0,0,0,0};
    LibDynamics::Dynamics::Output output{0,0,0};
    LibDynamics::Dynamics calculate;
    calculate.iteration(input, output);
}

int main()
{
    system("chcp 1251>nul"); // windows-кодировка в консоли

    // TODO вынести начальные условия в отдельный файл
    // TODO создать объект класса Мат.точка и передавать Динамике его, а не отдаельные переменные
    double mass = 50; // кг
    double force_x = 300; // Н
    double coord_x0 = 0; // м
    double vel_x0 = 0; // м/с
    double time_moment0 = 0; // c
    double end_time = 30; // с
    

    double vel_x = vel_x0;
    double coord_x = coord_x0;
    double time_moment = time_moment0;

    while (time_moment < end_time)
    {
        LibDynamics::Dynamics; //input coord_x, Vel_x, Force_x, mass, time_moment, d_time
            // time_moment = output.time
            // Vel_x = output.Vel_x
            // coord_x = output.coord_x

        // функция фывода в файл
        // if (time_moment % 0.1 == 0 )


    }

    std::cout << (time_moment, vel_x, coord_x - coord_x0) << std::endl;
                      
                           //test();
    
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
