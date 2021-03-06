// This header file houses all of the data
// that composes the Pieces 
// class. This class serves to characterize
// each piece with specific data, which is 
// analyzed by the Mastermind files.
#ifndef CHESS_PIECES_H_
#define CHESS_PIECES_H_

#include "Chess.h"


namespace Chess
{

  class Pieces
  {
  public:
    //-- types
    typedef shared_ptr<Pieces> PiecePtr;
    
    //-- construction
    Pieces( const string name, string type );
    Pieces( const string name, string type, int initRow, int initCol );

    //-- interface methods
    virtual bool pathScan( int destRow, int destCol )       { return false; }
    virtual bool validDirection( int destRow, int destCol ) { return false; }

    //-- accessors
    void     setKing( Pieces * king ) { king_ = king; }
    Pieces * getKing( )               { return king_; }
    string   getType( );
    char     getColor( );
    string   getName( );
    void     setLocation( int row, int col );
    int      getCol( )    { return col; }
    int      getRow( )    { return row; }
    void     setPinned( ) { pinned = true; }
    void     clrPinned( ) { pinned = false; }
    bool     getPinnedStatus( ) { return pinned; }
    void     setActiveListIndex( int index ) { activeListIndex_ = index; }
    int      getActiveListIndex( ) const { return activeListIndex_; }
    void     clrActiveListIndex( ) { activeListIndex_ = 0; }

    //-- miscellaneous public methods
    bool pieceMoved( int destRow, int destCol );
    bool destinationOnBoard( int destRow, int destCol );

  protected:
    //-- protected methods
    void clrLocation( );

    //-- protected members
    bool      in_check;
    bool      prev_in_check;
    bool      pinned;
    bool      captured;
    char      color;
    char      opponent;
    int       col;
    int       row;
    string    name;
    string    type;
    Pieces *  king_;
    int       activeListIndex_;
  };

}

#endif /* CHESS_PIECES_H_ */
