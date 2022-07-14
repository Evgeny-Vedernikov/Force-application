#include <iostream>
#include "MatPoint.h"


void data_to_file(double time, double f_inter, double dt, double v, double s)
{
    std::cout << "t, v, s" << time, v, s;
}

void start()
{
    LibMatPoint::MatPoint::KinValues kin_values;

    double mass = 50; // кг
    double force_x = 300; // Н
    double coord_x_0 = 0; // м
    double vel_x_0 = 0; // м
    double dt = 0.01; // с
    double t0 = 0; // с
    float end_time = 30; // с
    float f_interval = 0.1; // с

    double time = t0;
    kin_values.coord_x = coord_x_0;
    kin_values.vel_x = vel_x_0;

    // mkdir("records");

    LibMatPoint::MatPoint calculate (force_x / mass, dt);  // ____ calculate ?
    time = calculate.time_run(time, dt, end_time, kin_values);

    std::cout << "\nx = " << kin_values.coord_x 
        << "  Vx = " << kin_values.vel_x 
        << "  t = " << time;
}


int main()
{
    system("chcp 1251>nul"); // windows-кодировка в консоли
    start();

    return 0;
    // TODO вынести начальные условия в отдельный файл

    // функция фывода в файл  if (time_moment % 0.1 == 0 )

}
