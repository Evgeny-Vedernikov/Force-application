#include <iostream>
#include "MatPoint.h"
#include "Data.h"

void start()
{
    dynamics::KinValues kin_values;

    double mass = 50; // кг
    double force_x = 300; // Н
    double coord_x0 = 0; // м   - const ?
    double vel_x_0 = 0; // м   - const ?
    double dt = 0.01; // с   - const ?
    double t0 = 0; // с   - const ?
    double end_time = 30; // с    - const ?

    double to_file_interval = 0.1; // с    - const ?
    double to_udp_interval = 1; // с    - const ?


    dynamics::Dispatcher dispatcher("127.0.0.5", 1000, "record.txt", to_file_interval - dt/8, to_udp_interval - dt/8);
    dynamics::MatPoint point_1 (force_x / mass, dt, t0, vel_x_0, coord_x0, dispatcher, &dynamics::Dispatcher::IterationHandler);
    
    kin_values.t = point_1.time_run(end_time, kin_values);

    std::cout << "\nt = " << kin_values.t << "  Vx = " << kin_values.v << "s = " << kin_values.x - coord_x0;
}

int main()
{
    system("chcp 1251>nul"); // windows-кодировка в консоли
    start();

    return 0;
    // TODO вынести начальные условия в отдельный файл

}
