//
//  Entity.hpp
//  SDLProject
//
//  Created by Shucong Zhou on 2020/6/18.
//  Copyright © 2020 ctg. All rights reserved.
//
#pragma once
#define GL_SILENCE_DEPRECATION

#ifdef _WINDOWS
#include <GL/glew.h>
#endif

#define GL_GLEXT_PROTOTYPES 1
#include <SDL.h>
#include <SDL_opengl.h>
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "ShaderProgram.h"
#include "Map.h"

enum EntityType {PLAYER, PLATFORM, ENEMY, DOOR};

enum AIType {WALKER, WAITANDGO, WAITANDEAT, FLYANDATTACK};
enum AIState {IDLE, WALKING, ATTACKING, FLY};

class Entity {
public:
    
    EntityType entityType;
    AIType aiType;
    AIState aiState;
    
    glm::vec3 position;
    glm::vec3 movement;
    glm::vec3 acceleration;
    glm::vec3 velocity;
    glm::vec3 speed;
    
    std::string entityName;
    float number;
    float width = 1;
    float height = 1;
    
    bool jump = false;
    float jumpPower = 0;
    
    
    
    GLuint textureID;
    GLint textureID_Alter;
    
    glm::mat4 modelMatrix;
    
    int *animRight = NULL;
    int *animLeft = NULL;
    int *animUp = NULL;
    int *animDown = NULL;
    int *animUpANDDown = NULL;

    int *animIndices = NULL;
    int animFrames = 0;
    int animIndex = 0;
    float animTime = 0;
    int animCols = 0;
    int animRows = 0;
    
    bool loseLife = false;
    
    bool isActive = true;
    bool startAttack = false;
    bool touchSuccess = false;
    
    bool collidedTop = false;
    bool collidedBottom = false;
    bool collidedLeft = false;
    bool collidedRight = false;        
    
    bool collideSomething = false;
    bool collideRock = false;
    
    bool collideEnemy = false;
    bool killEnemySuccess = false;
    
    bool gameOver = false;
    

    
    Entity();
    
    
    Entity* checkCollision(Entity *other);
    
    //void checkCollisionsX_Rock(Entity *objects, int objectCount);
    //Entity* checkCollisionsY_Rock(Entity *objects, int objectCount);
    
    void checkCollisionsX_Enemy(Entity *objects, int objectCount);
    Entity* checkCollisionsY_Enemy(Entity *objects, int objectCount);
    void CheckCollisionsX(Map *map);
    void CheckCollisionsY(Map *map);

    void UpdateAI(Entity *player, Entity *AI, float deltaTime, Entity *enemies, int enemyCount);
    void Update(float deltaTime, Entity *player, Map *map, Entity *enemies, int enemyCount, Entity *door);
    
    void Render(ShaderProgram *program);
    void RenderDwarf(ShaderProgram *program);
    void RenderFlower_Sleep(ShaderProgram *program);
    void RenderFlower_Activated(ShaderProgram *program);
    void RenderAccelerator(ShaderProgram *program);
    void RenderClouds(ShaderProgram *program);
    void RenderStart(ShaderProgram *program);
    void RenderHeart(ShaderProgram *program);
    void RenderDoor(ShaderProgram *program);
    
    void DrawSpriteFromTextureAtlas(ShaderProgram *program, GLuint textureID, int index);
    
    void AI(Entity *player);
    void AIWalker();
    void AIWAITANDGO(Entity *player);
    void AIWAITANDEAT(Entity *player);
    void AIFLYANDATTACK(Entity *player);
};
