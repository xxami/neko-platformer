
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

        this->player_sprites = SpriteBatchNode::create("sprites/dev-player.png");
        cc::SpriteFrameCache *cache = cc::SpriteFrameCache::getInstance();
        cache->addSpriteFramesWithFile("sprites/dev-player.plist");
        cc_log("test");
        this->player = nullptr;
        this->init_map("maps/test.tmx");

        return true;
    }

    /**
     * load map, objects, init level
     */
    void GameScene::init_map(const std::string& map_file) {
        cc_log("loading map :: %s", map_file.c_str());
        this->map = TMXTiledMap::create(map_file);
        this->map->setScale(neko_remap(1.0f));
        this->layer_base = map->getLayer("base");
        this->init_map_entities(map->getObjectGroup("entities"));
        this->init_map_collide(map->getLayer("collisions"));
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

                this->player = Sprite::create("sprites/dev-player.png");
                this->player->getTexture()->setAliasTexParameters();
                this->player->setPosition(neko_remap2(x, y));
                this->player->setScale(neko_remap(1.0f));

                this->addChild(this->player, 1);
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

}
