#pragma once

#include <memory>

#include "Math.h"
#include "Canvas.h"

class LongBone;
class PelvisBone;

class Bone
{
	friend class LongBone;
	friend class PelvisBone;

private:

	Bone* parent = nullptr;

public:
	Bone();
	~Bone();
};
