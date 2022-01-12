#pragma once

class Enable
{
public:
	Enable(bool enabled);

	void enable(void);
	void disable(void);

protected:
	bool isEnabled(void);

private:
	bool enabled;
};
