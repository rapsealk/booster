#include <boost/asio.hpp>
#include <iostream>
using namespace boost;

int main()
{
	std::string raw_ip_address = "127.0.0.1";
	unsigned short port_num = 3333;

	// IP 주소를 분석하는 동안 발생할 수 있는 오류 정보를 저장하는 데 쓰인다.
	boost::system::error_code ec;

	// IP 프로토콜 버전과 관계 없는 주소 형식을 사용한다.
	asio::ip::address ip_address = asio::ip::address::from_string(raw_ip_address, ec);

	if (ec.value() != 0) {
		// IP 주소가 유효하지 않을 경우
		std::cout << "Failed to parse the IP address. Error code = " << ec.value() << std::endl;
		std::cout << "Message: " << ec.message();
		return ec.value();
	}

	asio::ip::tcp::endpoint ep(ip_address, port_num);
	// asio::ip::udp::endpoint ep(ip_address, port_num);

	return 0;
}