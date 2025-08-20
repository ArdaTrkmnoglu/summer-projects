#include <iostream>
#include <memory>
#include <asio.hpp>

#define PORT_NUMBER 3131

using namespace std;
using asio::ip::tcp;

class Session : public enable_shared_from_this<Session> {
public:
    Session(tcp::socket socket) : socket_(std::move(socket)) {}

    void start() {
        doRead();
    }

private:
    void doRead() {
        auto self(shared_from_this());
        socket_.async_read_some(asio::buffer(data_), [this, self](error_code ec, size_t length) {
            if (!ec) {
                doWrite(length);
            }
        });
    }

    void doWrite(size_t length) {
        auto self(shared_from_this());
        asio::async_write(socket_, asio::buffer(data_, length), [this, self](error_code ec, size_t) {
            if (!ec) {
                doRead();
            }
        });
    }

    tcp::socket socket_;
    char data_[1024];
};

class Server {
public:
    Server(asio::io_context& io, unsigned int port) : acceptor_(io, tcp::endpoint(tcp::v4(), port)) {
        doAccept();
    }

private:
    void doAccept() {
        acceptor_.async_accept([this](error_code ec, tcp::socket socket) {
            if (!ec) {
                make_shared<Session>(std::move(socket))->start();
            }
            doAccept();
        });
    }

    tcp::acceptor acceptor_;
};

int main() {
    
    try {
        asio::io_context context;
        Server server(context, PORT_NUMBER);
        cout << "Server running on port " << PORT_NUMBER << "..." << endl;
        context.run();
    }
    catch(exception& e) {
        cerr << "Exception occured: " << e.what() << endl;
    }

}