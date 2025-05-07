#include "OccupationManager.h"
#include <cassert>

OccupationManager::OccupationManager()
{
    m_OccupationRegistry = std::vector<OccupationData>();
}
