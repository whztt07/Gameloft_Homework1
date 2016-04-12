#include "Global.h"
#include "Enemy.h"
#include "TextureManager.h"

#define ENEMY_COUNT				20
#define ENEMY_LINE_COUNT		5
#define ENEMY_VERTICAL_MARGIN	50
#define ENEMY_HOTIZONTAL_MARGIN	100

class EnemyHolder
{

private:

	list<Enemy>				enemyList;

public:

	list<Enemy>				getEnemyList() const;

	void					setEnemyList(list<Enemy> newList);

	vector3df				getRandomEnemyPosition() const;

	bool					createEnemies(ISceneManager *manager, TextureManager *&texManager, rectf limits);
	IMetaTriangleSelector	*createSelectors(ISceneManager *manager);
	bool					checkNode(ISceneNode *check, ISceneManager *manager, u32 *score, ISoundEngine *sound, bool soundPlay, vector3df *position);
	void					fly(f32 delta);
	bool					step();
	void					drop();
	void					dropSelectors();

};