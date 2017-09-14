#ifndef __CELL_H__
#define __CELL_H__

#include "State.h"

class Cell {
public:
    Cell(){}
    Cell(uint32_t row, uint32_t column, STATES state)
        : _row(row)
        , _column(column)
        , _state(STATES::DEAD)
        , _nextState(STATES::UNKNOWN)
    {}

    inline uint32_t getRow() { return _row; }
    inline uint32_t getColumn() { return _column; }

    inline STATES getState() { return _state; }
    inline void setState(STATES state) { _state = state; }

    inline STATES getNextState() { return _nextState; }
    inline void setNextState(STATES nextState) { _nextState = nextState; }

private:
    uint32_t _row;
    uint32_t _column;
    STATES _state;
    STATES _nextState;
};

#endif
