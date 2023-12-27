/** @file ProgramError.hpp
 * @author Шатов В.С.
 * @version 1.08
 * @brief Обработка ошибок, с последующей записью в журнал
 * @date 26.12.2023
 * @copyright ИБСТ ПГУ
 */
#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>
#include <stdexcept>

/**
 * @brief Класс обработки ошибок чтения файла данных пользователей
 */
class ErrorRead: public std::invalid_argument
{
public:
    ErrorRead(const std::string& s) : std::invalid_argument(s) {}
    ErrorRead(const char * s) : std::invalid_argument(s) {}
};


/**
 * @brief Класс обработки ошибок записи в журнал
 */
class ErrorLogin: public std::runtime_error
{
public:
    ErrorLogin(const std::string& s) : std::runtime_error(s) {}
    ErrorLogin(const char * s) : std::runtime_error(s) {}
};


/**
 * @brief Класс обработки ошибок аутентификации
 */
class ErrorAuth: public std::invalid_argument
{
public:
    ErrorAuth(const std::string& s) : std::invalid_argument(s) {}
    ErrorAuth(const char * s) : std::invalid_argument(s) {}
};


/**
 * @brief Функция записи ошибок в журнал
 * @param local_path - путь к файлу журнала
 * @param what - содержание ошибки
 * @return description_string - строка с логом ошибки
 */
inline std::string log_entry(std::string local_path, std::string what)
{
    std::string description_string;
    std::ofstream file(local_path.c_str(), std::ios::app);
    if (file.is_open()) {
        std::time_t now = std::time(0);
        char buffer[80];
        std::strftime(buffer, sizeof(buffer), "%c", std::localtime(&now)); // Форматирование времени
        description_string = " - " + what + "\n";
        file << buffer << description_string; // Запись в файл
        file.close();
    } else {
        throw ErrorLogin("Error opening log file");
    }
    return description_string;
}
