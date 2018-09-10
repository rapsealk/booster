#include <boost/asio.hpp>
#include <iostream>
using namespace boost;

int main()
{
	std::string raw_ip_address = "127.0.0.1";
	unsigned short port_num = 3333;

	// IP �ּҸ� �м��ϴ� ���� �߻��� �� �ִ� ���� ������ �����ϴ� �� ���δ�.
	boost::system::error_code ec;

	// IP �������� ������ ���� ���� �ּ� ������ ����Ѵ�.
	asio::ip::address ip_address = asio::ip::address::from_string(raw_ip_address, ec);

	if (ec.value() != 0) {
		// IP �ּҰ� ��ȿ���� ���� ���
		std::cout << "Failed to parse the IP address. Error code = " << ec.value() << std::endl;
		std::cout << "Message: " << ec.message();
		return ec.value();
	}

	asio::ip::tcp::endpoint ep(ip_address, port_num);
	// asio::ip::udp::endpoint ep(ip_address, port_num);

	return 0;
}