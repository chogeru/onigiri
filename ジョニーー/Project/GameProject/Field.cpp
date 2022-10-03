#include "Field.h"
#include"Base/Base.h"

Field::Field() :Base(eType_Field)
{
	m_Map = COPY_RESOURCE("Map", CImage);
	m_foreground = COPY_RESOURCE("ForeGround", CImage);
	m_ground_y = 540;
}
void Field::Draw()
{
	
	m_Map.Draw();
	m_foreground.Draw();
}
