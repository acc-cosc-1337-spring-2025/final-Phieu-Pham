#ifndef POINT_PHASE_H
#define POINT_PHASE_H

#include "phase.h"

class PointPhase : public Phase {
private:
    int point;

public:
    PointPhase(int p);
    RollOutcome get_outcome(Roll* roll) override;
};

#endif