#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "../server_lib/server.hpp"

int main(int argc, char* argv[])
{
  try
  {
    // Check command line arguments.
    if (argc != 3)
    {
      std::cerr << "Usage: server <address> <port>\n";
      std::cerr << "  For IPv4, try:\n";
      std::cerr << "    server 0.0.0.0 80\n";
      std::cerr << "  For IPv6, try:\n";
      std::cerr << "    server 0::0 80\n";
      return 1;
    }

    // Initialise the server.
    kcp_svr::server s(argv[1], argv[2]);

    // Run the server until stopped.
    s.run();
  }
  catch (std::exception& e)
  {
    std::cerr << "exception: " << e.what() << "\n";
  }

  return 0;
}
