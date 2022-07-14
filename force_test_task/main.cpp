#include <iostream>
#include "MatPoint.h"


void start()
{
    dynamics::MatPoint::KinValues kin_values;

    double mass = 50; // кг
    double force_x = 300; // Н
    double coord_x_0 = 0; // м   - const ?
    double vel_x_0 = 0; // м   - const ?
    double dt = 0.01; // с   - const ?
    double t0 = 0; // с   - const ?
    float end_time = 30; // с    - const ?
    float rec_interval = 0.1; // с    - const ?


    //_mkdir ("records");

    dynamics::MatPoint calculate (force_x / mass, dt, t0, vel_x_0, coord_x_0);
    kin_values.t = calculate.time_run(end_time, kin_values);

    std::cout << "\nt = " << kin_values.t << "  Vx = " << kin_values.v << "x = " << kin_values.x;
}

int main()
{
    system("chcp 1251>nul"); // windows-кодировка в консоли
    start();

    return 0;
    // TODO вынести начальные условия в отдельный файл

    // функция фывода в файл  if (time_moment % 0.1 == 0 )

}
