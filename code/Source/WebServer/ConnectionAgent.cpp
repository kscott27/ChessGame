#include "WebServer/ConnectionAgent.h"

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

    ConnectionAgent::ConnectionAgentPtr ConnectionAgent::create( boost::asio::io_service & io_service, bool & pendingUserInput, string & userInput )
    {
      return ConnectionAgentPtr( new ConnectionAgent(io_service, pendingUserInput, userInput) );
    }

    tcp::socket & ConnectionAgent::socket()
    {
      return socket_;
    }

    void ConnectionAgent::start()
    {
      socket_.async_read_some(
        boost::asio::buffer(data, length),  
        boost::bind(&ConnectionAgent::handleRead,  
        shared_from_this(),  
        boost::asio::placeholders::error,  
        boost::asio::placeholders::bytes_transferred) );  
  
      socket_.async_write_some(
        boost::asio::buffer(message, length),  
        boost::bind(&ConnectionAgent::handleWrite,  
        shared_from_this(),  
        boost::asio::placeholders::error,  
        boost::asio::placeholders::bytes_transferred) );  
    }

    void ConnectionAgent::handleRead( const boost::system::error_code & err, size_t bytes_transferred )
    {
      if(!err)
      {  
        cout << endl << "ConnectionAgent::handleRead; bytes_transferred: " << bytes_transferred << endl;
        string temp(data);
        userInput_ = temp;
        memset(data, 0, sizeof data);
        pendingUserInput_ = false;
      }   
      else
      {  
        std::cerr << "error: " << err.message() << std::endl;  
        socket_.close();  
      }  
    }

    void ConnectionAgent::handleWrite( const boost::system::error_code & err, size_t bytes_transferred )
    {
      if(!err) 
      {  
        cout << "Server sent Hello message!"<< endl;  
      }   
      else
      {  
        std::cerr << "error: " << err.message() << endl;  
        socket_.close();  
      }  
    }

  }
}
