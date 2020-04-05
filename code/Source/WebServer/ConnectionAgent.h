#ifndef CHESS_WEBSERVER_CONNECTIONAGENT_H_
#define CHESS_WEBSERVER_CONNECTIONAGENT_H_

#include "Chess.h"

#include <iostream>  
#include <boost/asio.hpp>  
#include <boost/bind.hpp>  
#include <boost/enable_shared_from_this.hpp>  

using namespace boost::asio;  
using ip::tcp;  
using std::string;  
using std::cout;  
using std::endl;

namespace Chess
{
  namespace WebServer
  {

    class ConnectionAgent
      : public boost::enable_shared_from_this<ConnectionAgent>  
    {  
    public:
      //-- types
      typedef boost::shared_ptr<ConnectionAgent> ConnectionAgentPtr;

      ConnectionAgent(boost::asio::io_service& io_service)
        : socket_(io_service)
      { }  
      
      // creating the pointer  
      static ConnectionAgentPtr create( boost::asio::io_service & io_service );
      
      //socket creation  
      ip::tcp::socket & socket( );
      void start( );
      void handleRead( const boost::system::error_code& err, size_t bytes_transferred );
      void handleWrite( const boost::system::error_code& err, size_t bytes_transferred );

    protected:  
      //-- protected members
      ip::tcp::socket socket_;  
      std::string message="Hello From Server!";  
      enum {length = 1024};  
      char data[length];  
    };

  }
}

#endif /* CHESS_WEBSERVER_CONNECTIONAGENT_H_ */
