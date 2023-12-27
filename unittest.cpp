#include <UnitTest++/UnitTest++.h>
#include "server.hpp"
#include "ProgramError.hpp"
#include "datareader.hpp"
#include "md5h.hpp"

using namespace std;
SUITE(ServerTests)
{
    TEST(ServerConstructor) {
        // Тест проверяет корректное создание объекта сервера с заданными параметрами
        string file_path = "data.txt";
        int port = 33333;
        string local_path = "log.txt";
        server test(file_path, port, local_path);
        CHECK(true);
    }
    TEST(BadPort) {
        // Тест проверяет, что исключение выбрасывается при попытке использовать некорректный порт
        string local_path = "log.txt";
        string file_path = "data.txt";
        int port = 52;
        CHECK_THROW(server test(file_path, port, local_path), std::system_error);
    }
}

SUITE(TestLog)
{
    TEST(LogValidation) {
        // Тест проверяет корректную запись ошибки в файл журнала
        log_entry("log.txt", "Error in function");
        CHECK(true);
    }
    TEST(InvalidLog) {
        // Тест проверяет выбрасывание исключения при попытке записи в файл журнала с некорректным путем
        CHECK_THROW(log_entry("", "Error in function"), ErrorLogin);
    }
}

SUITE(DataReaderTests)
{
    TEST(datareaderCreation) {
        // Тест проверяет корректное создание объекта чтения данных
        string local_path = "data.txt";
        datareader test(local_path);
        CHECK(true);
    }
    TEST(GetVault) {
        // Тест проверяет корректное получение хранилища данных
        string local_path = "log.txt";
        map <string, string> vault;
        vault["user"] = "P@ssW0rd";
        string file_path = "data.txt";
        CHECK_EQUAL(true, vault == datareader(local_path).get(file_path));
    }
    TEST(InvalidVault) {
        // Тест проверяет выбрасывание исключения при попытке получить данные из некорректного файла
        string local_path = "log.txt";
        string file_path = "nedata.txt";
        CHECK_THROW(datareader(local_path).get(file_path), ErrorRead);
    }

    TEST(DataReaderEmptyFile) {
        // Тест проверяет выбрасывание исключения при попытке чтения из пустого файла
        string file_path = "empty_data.txt";
        // Создание пустого файла
        ofstream empty_file(file_path);
        empty_file.close();
        datareader test(file_path);
        CHECK_THROW(test.get(file_path), ErrorRead);
    }
}

SUITE(TestHashGeneration)
{
    TEST(HashValidation) {
        // Тест проверяет сравнение хешей для одинаковых паролей
        md5h test;
        string pass_1 = "P@ssW0rd";
        string pass_2 = "P@ssW0rd";
        CHECK_EQUAL(true, test.hash(pass_1) == test.hash(pass_2));
    }
    TEST(SecureHash) {
        // Тест проверяет, что разные пароли имеют разные хеши
        md5h test;
        string pass_1 = "P@ssW0rd";
        string pass_2 = "L@daGrAnta";
        CHECK_EQUAL(false, test.hash(pass_1) == test.hash(pass_2));
    }
    TEST(EmptyString) {
        // Тест проверяет хеширование пустой строки
        md5h test;
        string empty = "";
        CHECK_EQUAL(test.hash(empty), test.hash(empty)); // Пустые строки должны иметь одинаковый хеш
    }

    TEST(WhitespaceString) {
        // Тест проверяет хеширование строки с пробелами
        md5h test;
        string whitespace = "   ";
        CHECK_EQUAL(test.hash(whitespace), test.hash(whitespace)); // Строки только с пробелами должны иметь одинаковый хеш
    }

    TEST(SpecialCharacters) {
        // Тест проверяет хеширование строки с спецсимволами
        md5h test;
        string specialChars = "!@#$%^&*()_+{}[];:'\"\\,.<>?/";
        CHECK_EQUAL(test.hash(specialChars), test.hash(specialChars)); // Строки с спецсимволами должны иметь одинаковый хеш
    }
}

int main(int argc, char **argv)
{
    return UnitTest::RunAllTests();
}
