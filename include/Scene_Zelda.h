#include "SFML/Graphics/Text.hpp"
#include "Scene.h"
#include "Components.h"
#include "Physics.h"

class Scene_Zelda : public Scene
{
    struct PlayerConfig
    {
        float X, Y, CX, CY, SPEED, HEALTH;
    };

    protected:

    std::string m_levelPath;
    PlayerConfig m_playerConfig;
    bool m_drawGrid = false;
    bool m_drawTextures = true;
    bool m_drawCollision = false;
    bool m_follow = false;
    const Vec2 m_gridSize = { 64, 64 };
    sf::Text m_gridText;
    Vec2 m_mousePos;
    Entity* m_eOnDragging;
    Physics m_physics;

    void init(const std::string& levelPath);
    void loadLevel(const std::string& levelPath);
    void onEnd();
    void setPaused(bool pause);
    void spawnPlayer();
    void spawnSword(Entity& entity);
    Vec2 getPosition(int rx, int ry, int tx, int ty) const;
    Entity player();
    void sDoAction(const Action& action);
    void sMovement();
    void sAI();
    void sStatus();
    void sAnimation();
    void sCollision();
    void sCamera();
    void sGUI();
    void sRender();
    void sDrag();

    void changePlayerStateTo(PlayerState s);
    void changePlayerStateTo(const std::string& state, const Vec2& facing); 

    Vec2 posWinToWorld(const Vec2& pos);
    Vec2 getRoomXY(const Vec2& pos);
    public:

    Scene_Zelda(GameEngine*, std::string& levelPath);
    void update();
};
