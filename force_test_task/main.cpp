#include "MatPoint.h"
#include "Data.h"
#include "FileWriter.h"
#include "NetworkWriter.h"
#include <iostream>

void start(const std::string& out_file, const std::string& host, int16_t port)
{
    double mass = 50; // кг
    double force_x = 300; // Н
    double vel_x_0 = 0; // м
    double dt = 0.01; // с
    double t0 = 0; // с
    double end_time = 30; // с

    double to_file_interval = 0.1; // с
    double to_network_interval = 1; // с


    dynamics::MatPoint point(force_x / mass, dt, {t0, vel_x_0, 0 });
    dynamics::FileWriter filewriter(end_time, out_file);
    dynamics::NetworkWriter networkwriter(end_time, host, port);
    dynamics::Dispatcher dispatcher(point, filewriter, networkwriter, end_time, to_file_interval - dt / 8, to_network_interval - dt / 8);

    dynamics::KinValues kin_values = dispatcher.run();

    std::cout << "\nt = " << kin_values.t << "   Vx = " << kin_values.v << "   s = " << kin_values.s;
}

int main()
{
    system("chcp 1251>nul"); // windows-кодировка в консоли

    start("out.txt", "192.168.0.13", 1000);

    return 0;

}
