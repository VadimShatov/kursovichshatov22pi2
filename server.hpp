/** @file server.hpp
 * @author Шатов В.С.
 * @version 1.08
 * @brief Операции выполняемые сервером
 * @date 26.12.2023
 * @copyright ИБСТ ПГУ
 */
#pragma once
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include <iostream>
#include <map>
#include <stdlib.h>
#include <bitset>
#include <cstdint>
#include <limits>
/**
 * @brief Класс управления работой сервера
 */
class server
{
private:
    ///Путь к файлу с логом
    std::string local_path;
    ///Сокет
    int sckt;
    ///Действующее соединение с клиентом
    int wrkr;
    ///Ответ от клиента
    int rc;
    ///Буфер
    char *buffer = new char[4096];
    ///Данные клиента ID:PASS
    std::map <std::string, std::string> vault;
public:
    /**
     * @brief Конструктор класса
     * @param file_path Путь к файлу с ID:PASS клиентов
     * @param port Порт для приема соединения
     * @param local_path Путь к файлу журнала
     */
    server(std::string file_path, int port, std::string local_path);
    /**
     * @brief Запуск сервера и привязка порта
     * @param port Порт для приема соединения
     * @param address Сетевой адрес для приема соединения
     * @return sckt Сокет
     */
    int start(int port, const char* address);
    /**
     * @brief Функция ожидания и принятия соединения с клиентом
     * @return wrkr Действующее соединение с клиентом
     */
    int connect();
    /**
     * @brief Функция аутентификации пользователя
     * @return True, если аутентификация удалась, False - если нет
     */
    bool authentication();
    /**
     * @brief Функция обработки векторов
     * @return True, если обработка удалась, False - если нет
     */
    bool operations();
};
