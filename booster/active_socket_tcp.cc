#include <boost/asio.hpp>
#include <iostream>
using namespace boost;

int main()
{
	asio::io_service ios;

	asio::ip::tcp protocol = asio::ip::tcp::v4();

	asio::ip::tcp::socket sock(ios);

	boost::system::error_code ec;

	// allocate os socket
	sock.open(protocol, ec);

	if (ec.value() != 0) {
		std::cout << "Failed to open the socket! Error code = " << ec.value();
		std::cout << "Message: " << ec.message() << std::endl;
		return ec.value();
	}

	/*
	try {
		asio::ip::tcp::socket sock(ios, protocol);
	}
	catch (boost::system::system_error &e) {
		std::cout << "Error occured! Error code = " << e.code();
		std::cout << "Message: " << e.what();
	}
	*/

	return 0;
}