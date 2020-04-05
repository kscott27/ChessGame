#ifndef CHESS_WEBSERVER_WEBSERVER_H_
#define CHESS_WEBSERVER_WEBSERVER_H_

#include "Chess.h"

#include <iostream>  
#include <boost/asio.hpp>  
#include <boost/bind.hpp>  
#include <boost/enable_shared_from_this.hpp>

#include "WebServer/ConnectionAgent.h"

using namespace boost::asio;  
using ip::tcp;  
using std::string;  
using std::cout;  
using std::endl;

namespace Chess
{
  namespace WebServer
  {

    class WebServer
    {
    public:  
      // constructor for accepting connection from client  
      WebServer( boost::asio::io_service & io_service );
      
      //-- public methods
      void handleAccept( ConnectionAgent::ConnectionAgentPtr connection, const boost::system::error_code& err );

    protected:  
      //-- protected methods
      void startAccept( );

      //-- protected members
      ip::tcp::acceptor acceptor_;  
    };  

  }
}

#endif /* CHESS_WEBSERVER_WEBSERVER_H_ */
