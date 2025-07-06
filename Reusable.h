#pragma once
class Reusable
{
public:
	Reusable() {
		m_reuse = false;
	}
	virtual void Reset() = 0;
	bool m_reuse;
};

