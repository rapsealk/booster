#include <boost/asio.hpp>
#include <iostream>
using namespace boost;

int main()
{
	asio::io_service ios;

	asio::ip::tcp protocol = asio::ip::tcp::v6();

	asio::ip::tcp::acceptor acceptor(ios);

	boost::system::error_code ec;

	// allocate os socket
	acceptor.open(protocol, ec);

	if (ec.value() != 0) {
		std::cout << "Failed to open the acceptor socket!" << std::endl;
		std::cout << "Error code = " << ec.value() << std::endl;
		std::cout << "Message: " << ec.message() << std::endl;

		return ec.value();
	}

	return 0;
}