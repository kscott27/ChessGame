#include "State/PathScanState.h"


namespace Chess
{
  namespace State
  {

    BaseState::StatePtr PathScanState::execute( )
    {
      std::cout << "Path scan state" << std::endl;
      
      PiecePtr currentPiece = board_->getPiece(interface_->sourceRow, interface_->sourceCol);
      if( currentPiece->pathScan(interface_->destRow, interface_->destCol) )
      {
        return nextState_;
      }
      else
      {
        std::cout << "Path not clear" << std::endl;
        return returnState_;
      }
    }

  }
}
