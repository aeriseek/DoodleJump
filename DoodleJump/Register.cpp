#include "Register.h"


Register::Register()
{
	levelY = static_cast<float>(windowSizeY);
	positions.resize(maxEntities);
	velocities.resize(maxEntities);
	inputComponent.resize(maxEntities);
	sprites.resize(maxEntities);
	soundComponent.resize(maxEntities);
}

Entity Register::create()
{
	Entity id;
	if (!freeIDs.empty())
	{
		id = freeIDs.back();
		freeIDs.pop_back();
	}
	else {
		id = nextId++;
	}
	return id;
}

void Register::remove(Entity entity)
{
	if (hasSound[entity]) {
		soundComponent[entity].playingSound.stop();
		hasSound.reset(entity);
	}

	hasPosition.reset(entity);
	hasVelocity.reset(entity);
	hasInput.reset(entity);
	gravityAffected.reset(entity);
	hasSprite.reset(entity);
	hasCollision.reset(entity);
	freeIDs.push_back(entity);
}

void Register::createPlayer()
{
	Entity player = create();
	addPosition(player, windowSizeX / 2.f, windowSizeY / 2.f);
	addVelocity(player, 0.f, 0.f);
	addInput(player);
	addSound(player, "resources/sounds/jumpSound.ogg");
	sf::Texture& tex = AssetManager::GetTexture("resources/textures/player.png");
	sf::Sprite sprite(tex);
	sprite.setOrigin(tex.getSize().x / 2.f, tex.getSize().y / 2.f);
	sprite.setPosition(windowSizeX / 2.f, windowSizeY / 2.f);
	addSprite(player, sprite);
	gravityAffected[player] = true;

};

void Register::setBackground()
{
	Entity background = create();
	sf::Sprite sprite(AssetManager::GetTexture("resources/textures/Background.png"));
	addSprite(background, sprite);
}

const uint32_t Register::totalEntities() const
{
	return nextId;
}

void Register::restart()
{
	nextId = 0;
	levelY = static_cast<float>(windowSizeY);

	hasPosition.reset();
	hasVelocity.reset();
	hasInput.reset();
	gravityAffected.reset();
	hasSprite.reset();
	hasCollision.reset();
	hasSound.reset();

	freeIDs.clear();
	entitiesToDelete.clear();

	setBackground();
	createPlayer();

}

void Register::addPosition(Entity e, float x, float y)
{
	positions[e] = Position(x, y);
	hasPosition[e] = true;
}

void Register::addVelocity(Entity e, float x, float y)
{
	velocities[e] = Velocity(x, y);
	hasVelocity[e] = true;
}

void Register::addInput(Entity e)
{
	inputComponent[e] = Input();
	hasInput[e] = true;
}

void Register::addSprite(Entity e, sf::Sprite sprite)
{
	sprites[e] = sprite;
	hasSprite[e] = true;
}

void Register::addCollision(Entity e)
{
	hasCollision[e] = true;
}

void Register::addSound(Entity e, std::string_view filename)
{
	soundComponent[e] = SoundComponent();
	soundComponent[e].playingSound.setBuffer(AssetManager::GetSound(filename));
	hasSound[e] = true;
}
