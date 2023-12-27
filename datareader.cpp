/** @file datareader.сpp
 * @author Шатов В.С.
 * @version 1.08
 * @brief Считывание данных о клиентах
 * @date 26.12.2023
 * @copyright ИБСТ ПГУ
 */
#include "datareader.hpp"
using namespace std;

datareader::datareader(const string& local_path) {}

map<string, string> datareader::get(const string& file_path)
{
    map<string, string> vault;
    ifstream in(file_path);

    if (!in.is_open()) {
        throw ErrorRead("Failed to open data");
    }

    // Проверка на пустоту файла
    if (in.peek() == ifstream::traits_type::eof()) {
        in.close();
        throw ErrorRead("Empty file");
    }

    string row;
    while (getline(in, row)) {
        size_t position = row.find(':');
        if (position != string::npos) {
            string ID = row.substr(0, position);
            string PASS = row.substr(position + 1);
            vault[ID] = PASS;
        }
    }
    in.close();
    return vault;
}
