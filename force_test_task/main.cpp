#include "MatPoint.h"
#include "Data.h"
#include "FileWriter.h"
#include <iostream>

void Start()
{
    double mass = 50; // кг
    double force_x = 300; // Н
    double coord_x0 = 0; // м
    double vel_x_0 = 0; // м
    double dt = 0.01; // с
    double t0 = 0; // с
    double end_time = 30; // с

    double to_file_interval = 0.1; // с
    double to_network_interval = 1; // с
    std::string host = "192.168.2.202";
    int16_t port = 1000;
    std::string out_file = "out.txt";

    dynamics::KinValues kin_values;
    dynamics::Dispatcher dispatcher(host, port, out_file, to_file_interval - dt/8, to_network_interval - dt/8, end_time);
    dynamics::MatPoint point_1 (force_x / mass, dt, t0, vel_x_0, coord_x0, dispatcher, &dynamics::Dispatcher::DataHandler);
    
    kin_values.t = point_1.TimeRun(end_time, kin_values);

    std::cout << "\nt = " << kin_values.t << "  Vx = " << kin_values.v << "s = " << kin_values.x - coord_x0;
}

int main()
{
    system("chcp 1251>nul"); // windows-кодировка в консоли
    Start();

    return 0;

}
