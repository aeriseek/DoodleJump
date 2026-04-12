#include "CleanupSystem.h"
#include "Config.h"

void CleanupSystem(Register& reg)
{
	for (Entity entity : reg.entitiesToDelete)
		reg.remove(entity);
	reg.entitiesToDelete.clear();
}