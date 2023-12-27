/** @file md5h.cpp
 * @author Шатов В.С.
 * @version 1.08
 * @brief Класс обработки MD5 Hash
 * @date 26.12.2023
 * @copyright ИБСТ ПГУ
 * Содержит главную функцию для запуска сервера, включая разбор аргументов командной строки и обработку ошибок.
 */
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <iostream>
#include <unistd.h>
#include <ctime>
#include <cstdlib>
#include <cryptopp/md5.h>
#include <cryptopp/hex.h>
#include <cryptopp/filters.h>
#include <cryptopp/randpool.h>
#include "md5h.hpp"

/**
 * @brief Конструктор класса md5h
 *
 * Инициализирует соль для использования при генерации хеша.
 */
 
md5h::md5h()
{
    salt = generation_SALT();
}

/**
 * @brief Генерация хеша MD5
 * @param PASS Пароль для хеширования
 * @return Строка с хешем
 */
 
std::string md5h::hash(const std::string& PASS)
{
    CryptoPP::Weak::MD5 hash;
    std::string dispatch = salt + PASS;
    std::string digest;

    CryptoPP::StringSource(dispatch, true,
                           new CryptoPP::HashFilter(hash,
                                   new CryptoPP::HexEncoder(
                                       new CryptoPP::StringSink(digest)
                                   )
                                                   )
                          );

    return digest;
}

/**
 * @brief Генерация случайной соли
 * @return Сгенерированная строка с солью
 */
 
std::string md5h::generation_SALT()
{
    static const char alpha_num[] =
        "0123456789"
        "ABCDEF";

    CryptoPP::RandomPool randomondo;
    std::string tmp_s;
    tmp_s.reserve(16);

    for (int i = 0; i < 16; ++i) {
        tmp_s += alpha_num[randomondo.GenerateByte() % (sizeof(alpha_num) - 1)];
    }

    return tmp_s;
}
