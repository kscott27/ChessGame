#ifndef CHESS_WEBSERVER_H_
#define CHESS_WEBSERVER_H_

#include "Chess.h"


namespace Chess
{
  namespace WebServer
  {

    class WebServer
    {
    public:
      //-- construction
      WebServer( );

      void getInput( char * );

    };

  }
}

#endif /* CHESS_WEBSERVER_H_ */
