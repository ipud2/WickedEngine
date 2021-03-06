#pragma once
#include "CommonInclude.h"

class wiGUI;
class wiWindow;
class wiLabel;
class wiCheckBox;
class wiSlider;
class wiComboBox;
class wiColorPicker;
class wiButton;

class PaintToolWindow
{
	float rot = 0;
	XMFLOAT2 posPrev = XMFLOAT2(0, 0);
public:
	PaintToolWindow(wiGUI* gui);
	~PaintToolWindow();

	wiGUI* GUI;
	wiECS::Entity entity = wiECS::INVALID_ENTITY;
	int subset = -1;

	wiWindow* window;
	wiComboBox* modeComboBox;
	wiLabel* infoLabel;
	wiSlider* radiusSlider;
	wiSlider* amountSlider;
	wiSlider* falloffSlider;
	wiCheckBox* backfaceCheckBox;
	wiCheckBox* wireCheckBox;
	wiColorPicker* colorPicker;

	void Update(float dt);
	void DrawBrush() const;

	XMFLOAT2 pos = XMFLOAT2(0, 0);

	enum MODE
	{
		MODE_DISABLED,
		MODE_VERTEXCOLOR,
		MODE_SCULPTING_ADD,
		MODE_SCULPTING_SUBTRACT,
		MODE_SOFTBODY_PINNING,
		MODE_SOFTBODY_PHYSICS,
		MODE_HAIRPARTICLE_ADD_TRIANGLE,
		MODE_HAIRPARTICLE_REMOVE_TRIANGLE,
		MODE_HAIRPARTICLE_LENGTH,
	};
	MODE GetMode() const;
	void SetEntity(wiECS::Entity value, int subsetindex = -1);
};
