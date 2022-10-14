#include "Wall.h"

Wall::Wall() :Base(eType_Wall)
{
	m_Wall = COPY_RESOURCE("Wall", CImage);
	

	
}
void Wall::Draw()
{
	m_Wall.Draw();
<<<<<<< HEAD
	//m_Wall.SetSize(1920, 1080);
=======
	
>>>>>>> f67beb96d84ab438190f42d244f47bd70101c9f4
	
}
