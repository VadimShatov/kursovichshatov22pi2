/** @file md5h.hpp
 * @author Шатов В.С.
 * @version 1.08
 * @brief Класс обработки MD5 Hash
 * @date 26.12.2023
 * @copyright ИБСТ ПГУ
 */
#pragma once
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <cryptopp/hex.h>
#include <cryptopp/md5.h>

using namespace std;
/**
 * @brief Класс обрабатки MD5 Hash
 */
class md5h
{
private:
    /**
     * @brief Генератор SALT
     * @return tmp_s SALT
     */
    string generation_SALT();
    
public:
 /**
     * @brief Конструктор класса md5h
     *
     * Инициализирует соль для использования при генерации хеша.
     */
    md5h();
    /// SALT для хеширования
    string salt;
    /**
     * @brief Получение хэша пароля
     * @param PASS - пароль
     * @return digest - хэш от пароля
     */
    string hash(const string& PASS);
};
