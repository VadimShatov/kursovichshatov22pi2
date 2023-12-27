/** @file main.cpp
 * @author Шатов В.С.
 * @version 1.08
 * @brief Справка по использованию
 * @date 26.12.2023
 * @copyright ИБСТ ПГУ
 */
#include <iostream>
#include <string>
#include "server.hpp"
#include "datareader.hpp"
#include <cryptopp/hex.h>
#include "md5h.hpp"
#include <string.h>
#include <cryptopp/md5.h>
#include <boost/program_options.hpp>

namespace bust = boost::program_options;

/**
 * @brief Структура для хранения параметров сервера по умолчанию
 */
 
struct {

    uint32_t p = 33333; ///< Порт по умолчанию
    std::string d = "data.txt"; ///< Путь к файлу данных по умолчанию
    std::string l = "log.txt"; ///< Путь к файлу журнала по умолчанию

    bool p_not_set()
    {
        return (p == 33333);
    }
    bool d_not_set()
    {
        return (d == "data.txt");
    }
    bool l_not_set()
    {
        return (l == "log.txt");
    }
} parameters;

/**
 * @brief Выводит справку по использованию аргументов командной строки
 */
 
void help()
{
    std::cout << "enter -h / --help for help;\n"
              "enter -d / --data-path for the determine the path to the client database file.;\n"
              "enter -l / --log-path for the determine the path to the log file.;\n"
              "enter -p / --port for the port\n";
}

/**
 * @brief Главная функция приложения сервера
 * @param argc Количество аргументов командной строки
 * @param argv Массив аргументов командной строки
 * @return Код завершения
 */
 
int main(int argc, const char* argv[])
{
    std::string file_path;
    int port;
    std::string local_path;

    try {
        bust::options_description desc("Options");
        desc.add_options()
        ("help,h", "Create assistance message")
        ("data-path,d", bust::value<std::string>(&file_path)->default_value("data.txt"), "path to the data with clients")
        ("log-path,l", bust::value<std::string>(&local_path)->default_value("log.txt"), "path to the log file")
        ("port,p", bust::value<int>(&port)->default_value(33333), "port");

        bust::variables_map vm;
        bust::store(bust::parse_command_line(argc, argv, desc), vm);
        bust::notify(vm);

        if (vm.count("help")) {
            help();
            return 1;
        }

        parameters.d = file_path;
        parameters.p = port;
        parameters.l = local_path;

        if (parameters.p_not_set() && parameters.d_not_set() && parameters.l_not_set()) {
            help();
        }

        server srvr = server(file_path, port, local_path);
        while (true) {
            srvr.connect();
            if (srvr.authentication() == true)
                srvr.operations();
        }
    } catch(ErrorLogin &e) {
        std::cerr << e.what() << std::endl;
    } catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
        log_entry(local_path, e.what());
    }
    return 0;
}
