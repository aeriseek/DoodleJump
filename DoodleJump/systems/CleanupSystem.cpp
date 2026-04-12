#include "CleanupSystem.h"
#include "Config.h"

void CleanupSystem(Register& reg)
{
	for (Entity entity = playerID; entity < reg.totalEntities(); ++entity)
		reg.remove(entity);
}