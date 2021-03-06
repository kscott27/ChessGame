#include "BaseTurn.h"


namespace Chess
{

  void BaseTurn::deactivatePiece( ) 
  {
    // Do not attempt to deactivate a Null Piece
    if(pendingRemovedPiece_ && pendingRemovedPiece_->getType() != "") 
    {
      int index = pendingRemovedPiece_->getActiveListIndex();
      pendingRemovedPiece_->clrActiveListIndex();
      activeList_.erase(activeList_.begin() + index);
      pendingRemovedPiece_ = PiecePtr();
      updatePieceIndices();
    }
  }

  void BaseTurn::setActivePiece( PiecePtr activePiece )
  {
    activePiece->setActiveListIndex(activeList_.size());
    activeList_.push_back(activePiece);
  }

  void BaseTurn::updatePieceIndices( )
  {
    for( int i = 0; i < activeList_.size(); i++ )
    {
      PiecePtr piece = getActivePiece(i);
      piece->setActiveListIndex(i);
    }
  }

}
