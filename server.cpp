/** @file server.сpp
 * @author Шатов В.С.
 * @version 1.08
 * @brief Операции выполняемые сервером
 * @date 26.12.2023
 * @copyright ИБСТ ПГУ
 */
#include "server.hpp"
#include "ProgramError.hpp"
#include "datareader.hpp"
#include "md5h.hpp"
using namespace std;

/**
 * @brief Конструктор класса server
 * @param file_path - путь к файлу с данными
 * @param port - порт сервера
 * @param local_path - путь к локальному файлу
 */
 
server::server(string file_path, int port, string local_path)
{
    local_path = local_path;
    const char* ip = "127.0.0.1";
    vault = datareader(local_path).get(file_path);
    sckt = start(port, ip);
}

/**
 * @brief Метод для запуска сервера
 * @param port - порт сервера
 * @param address - IP-адрес сервера
 * @return sckt - сокет сервера
 */
 
int server::start(int port, const char* address)
{
    sockaddr_in* selfAddr = new (sockaddr_in);
    selfAddr->sin_family = AF_INET;
    selfAddr->sin_port = htons(port);
    selfAddr->sin_addr.s_addr = inet_addr(address);

    int sckt = socket(AF_INET, SOCK_STREAM, 0);
    int rc = bind(sckt, reinterpret_cast<const sockaddr*>(selfAddr), sizeof(sockaddr_in));
    if (rc == -1) {
        throw std::system_error(errno, std::generic_category(), "Failed to bind socket");
    }

    listen(sckt, 3);
    std::cout << "The server has started" << std::endl;

    return sckt;
}

/**
 * @brief Метод для соединения с клиентом
 * @return wrkr - рабочий сокет
 */
 
int server::connect()
{
    sockaddr_in* remoteAddr = new (sockaddr_in);
    remoteAddr->sin_family = AF_INET;
    remoteAddr->sin_port = 0;
    remoteAddr->sin_addr.s_addr = 0;

    sockaddr_in* client_addr = new sockaddr_in;
    socklen_t len = sizeof(sockaddr_in);
    wrkr = accept(sckt, reinterpret_cast<sockaddr*>(client_addr), &len);

    std::cout << "The server has accepted the connection" << std::endl;

    return wrkr;
}


/**
 * @brief Метод аутентификации клиента
 * @return bool - результат аутентификации (true - успешно, false - ошибка)
 */
 
bool server::authentication()
{
    md5h crypt;
    const std::string err = "ERR";
    const std::string ok = "OK";

    rc = recv(wrkr, buffer, sizeof(buffer), 0);
    buffer[rc] = '\0';
    std::string ID(buffer);

    if (vault.count(ID) == 1) {
        strcpy(buffer, crypt.salt.c_str());
        send(wrkr, buffer, crypt.salt.length(), 0);
    } else {
        strcpy(buffer, err.c_str());
        send(wrkr, buffer, sizeof(buffer), 0);
        close(wrkr);
        throw ErrorAuth("Invalid client ID");
        return false;
    }

    std::cout << "Client has been identified" << std::endl;

    rc = recv(wrkr, buffer, 4096, 0);
    buffer[rc] = '\0';
    std::string what(buffer);

    if (what != crypt.hash(vault[ID])) {
        strcpy(buffer, err.c_str());
        send(wrkr, buffer, err.length(), 0);
        close(wrkr);
        throw ErrorAuth("Invalid password");
        return false;
    }

    strcpy(buffer, ok.c_str());
    rc = send(wrkr, buffer, ok.length(), 0);
    buffer[rc] = '\0';

    std::cout << "Client has been authenticated" << std::endl;
    return true;
}

/**
 * @brief Метод для выполнения операций
 * @return bool - результат выполнения операций (true - успешно, false - ошибка)
 */
 
bool server::operations()
{
    uint32_t vectors_quantity;
    uint32_t vector_size;
    double vector;
    const uint64_t maxVal = std::numeric_limits<uint64_t>::max();

    recv(wrkr, &vectors_quantity, sizeof(vectors_quantity), 0);

    for (uint32_t i = 0; i < vectors_quantity; i++) {
        double sum = 0;

        recv(wrkr, &vector_size, sizeof(vector_size), 0);

        for (uint32_t j = 0; j < vector_size; j++) {
            recv(wrkr, &vector, sizeof(vector), 0);

            if ((sum + vector) - vector == sum) {
                sum = sum + vector;
            } else {
                sum = maxVal / 2;
                break;
            }
        }

        double answer = (sum == maxVal / 2) ? static_cast<double>(INT64_MIN) : sum;
        send(wrkr, &answer, sizeof(answer), 0);
    }

    return true;
}
