#include "WebServer/WebServer.h"

#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h>

using namespace boost::asio;  
using ip::tcp;  
using std::string;  
using std::cout;  
using std::endl;

namespace Chess
{
  namespace WebServer
  {

    WebServer::WebServer( boost::asio::io_service & io_service )
      : acceptor_(io_service, ip::tcp::endpoint(ip::tcp::v4(), 1234))
    {  
      startAccept();  
    }

    void WebServer::handleAccept( ConnectionAgent::ConnectionAgentPtr connection, const boost::system::error_code& err )
    {  
      if(!err)
        connection->start();

      startAccept();  
    }

    void WebServer::startAccept( )
    {
      // socket  
      ConnectionAgent::ConnectionAgentPtr connection = ConnectionAgent::create(acceptor_.get_io_service());  
      // asynchronous accept operation and wait for a new connection.  
      acceptor_.async_accept(
        connection->socket(),  
        boost::bind(&WebServer::handleAccept, this, connection,  
        boost::asio::placeholders::error) );
    }

  }
}
