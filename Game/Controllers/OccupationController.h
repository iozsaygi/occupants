#ifndef OCCUPATION_CONTROLLER_H
#define OCCUPATION_CONTROLLER_H

#include <vector>

class OccupationController final
{
public:
    OccupationController();

private:
    std::vector<int> m_OccupiedNodeIDs;
};

#endif // OCCUPATION_CONTROLLER_H
