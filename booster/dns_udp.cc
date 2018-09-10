#include <boost/asio.hpp>
#include <iostream>
using namespace boost;

int main()
{
	std::string hostname = "hostname.com";
	std::string port_num = "3333";

	asio::io_service ios;

	asio::ip::udp::resolver::query resolver_query(hostname, port_num, asio::ip::udp::resolver::query::numeric_service);

	asio::ip::udp::resolver resolver(ios);

	boost::system::error_code ec;

	asio::ip::udp::resolver::iterator it = resolver.resolve(resolver_query, ec);

	if (ec.value() != 0) {
		std::cout << "Failed to resolve a DNS name." << std::endl;
		std::cout << "Error code = " << ec.value() << std::endl;
		std::cout << "Message: " << ec.message() << std::endl;

		return ec.value();
	}

	asio::ip::udp::resolver::iterator it_end;

	for (; it != it_end; ++it) {
		asio::ip::udp::endpoint ep = it->endpoint();
	}

	return 0;
}