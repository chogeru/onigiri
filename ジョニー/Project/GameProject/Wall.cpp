#include "Wall.h"

Wall::Wall() :Base(eType_Wall)
{
	m_Wall = COPY_RESOURCE("Wall", CImage);
	

	
}
void Wall::Draw()
{
	m_Wall.Draw();

	m_Wall.SetSize(1920, 1080);

	
}
