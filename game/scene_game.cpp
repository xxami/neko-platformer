
#include "neko.h"
#include "scene_game.h"

namespace neko {

    namespace cc = cocos2d;

    using cc::Vec2;
    using cc::Sprite;
    using cc::SpriteBatchNode;
    using cc::experimental::TMXTiledMap;
    using cc::experimental::TMXLayer;

    /**
     * GameIntroScene
     */

    cc::Scene* GameScene::create_scene() {
        auto scene = cc::Scene::create();
        auto layer = self::create();
        scene->addChild(layer);

        return scene;
    }

    bool GameScene::init() {
        if (!super::init()) return false;

        this->phys = Physics::create();

        this->player_sprites = SpriteBatchNode::create("sprites/dev-player.png");
        cc::SpriteFrameCache *cache = cc::SpriteFrameCache::getInstance();

        /**
         * remember cache is not autoreleased
         */
        cache->addSpriteFramesWithFile("sprites/dev-player.plist",
            "sprites/dev-player.png");

        this->player = nullptr;
        this->init_map("maps/test.tmx");
        this->init_map_collide(this->map->getLayer("collisions"));

        auto keybd_listener = cc::EventListenerKeyboard::create();
        keybd_listener->onKeyPressed = cc_callback2(GameScene::cb_key_down, this);
        keybd_listener->onKeyReleased = cc_callback2(GameScene::cb_key_up, this);

        cc_event_dispatch_graphed(keybd_listener, this);
        this->scheduleUpdate();

        return true;
    }

    /**
     * update: game loop
     */
    void GameScene::update(float delta) {
        
    }

    /**
     * load map, objects, init level
     */
    void GameScene::init_map(const std::string& map_file) {
        cc_log("loading map :: %s", map_file.c_str());
        this->map = TMXTiledMap::create(map_file);
        this->map->setScale(neko_remap(1.0f));
        this->layer_base = this->map->getLayer("base");
        this->init_map_entities(this->map->getObjectGroup("entities"));
        this->addChild(this->map, 0, id_tilemap);
    }

    /**
     * add map entity data from a given object group
     */
    void GameScene::init_map_entities(cc::TMXObjectGroup *group) {
        cc_assert(group != nullptr, "no entity data found in map");
        /**
         * add/process valid entity object group data
         */
         cc_log("loading map entity data");
         auto& objects = group->getObjects();

         for (auto &obj : objects) {
            auto &properties = obj.asValueMap();

            if (properties["type"].asString() == "player_start") {
                if (this->player != nullptr) {
                    /**
                     * multiplayer unsupported
                     */
                     continue;
                }

                /**
                 * spawn player at this point
                 */
                float x = properties["x"].asFloat();
                float y = properties["y"].asFloat();
                cc_log("spawning player :: Vec2(%.0f, %.0f)", x, y);

                this->player = Sprite::createWithSpriteFrameName("dev-player-1");
                this->player_sprites->addChild(this->player);
                this->player->getTexture()->setAliasTexParameters();
                this->player->setPosition(neko_remap2(x, y));
                this->player->setScale(neko_remap(1.0f));

                this->addChild(this->player_sprites, 1);
            }

            /**
             * other entities?
             */
         }

         cc_assert(this->player != nullptr,
            "no player spawn data found in map");
    }

    /**
     * add collision data from a given layer
     */
    void GameScene::init_map_collide(TMXLayer *layer) {
        cc_assert(layer != nullptr, "no collision data found in map");
        /**
         * add/process valid collision layer
         */
        cc_log("loading map collision data");
        this->layer_collide = layer;
        this->layer_collide->setVisible(false);

    }

    /**
     * on key down event - todo: keyboard manager class
     */
    void GameScene::cb_key_down(cc::EventKeyboard::KeyCode code, cc::Event *e) {
        cc_log("%d", (int)code);
        if (code == cc_key_a) cc_log("meow");
    }

    /**
     * on key release event - todo: keyboard manager class
     */
    void GameScene::cb_key_up(cc::EventKeyboard::KeyCode code, cc::Event *e) {
        if (code == cc_key_space) {
            //
        }
    }

}
