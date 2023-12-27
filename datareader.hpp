/** @file datareader.hpp
 * @author Шатов В.С.
 * @version 1.08
 * @brief Считывание данных о клиентах
 * @date 26.12.2023
 * @copyright ИБСТ ПГУ
 */
#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include "ProgramError.hpp"

using namespace std;

/**
 * @brief Класс для чтения данных из файла и формирования хранилища пользователей
 */
class datareader
{
public:
    /**
     * @brief Конструктор класса DataReader
     * @param local_path Путь к локальному файлу, который будет использоваться для чтения данных
     */
    datareader(const string& local_path);

    /**
     * @brief Получает данные из указанного файла и формирует хранилище пользователей
     * @param file_path Путь к файлу с данными пользователей
     * @return Хранилище данных пользователей в виде std::map, где ключ - идентификатор, значение - пароль
     * @throw ErrorRead Если возникают проблемы при открытии или чтении файла
     */
    map<string, string> get(const string& file_path);
};
