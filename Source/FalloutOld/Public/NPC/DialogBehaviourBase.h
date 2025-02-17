#pragma once

class DialogBehaviourBase
{
public:
	virtual ~DialogBehaviourBase();
	virtual void RequestDialog() = 0;
};
