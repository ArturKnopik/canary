/**
 * Canary - A free and open-source MMORPG server emulator
 * Copyright (C) 2021 OpenTibiaBR <opentibiabr@outlook.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef SRC_GAME_GAME_DEFINITIONS_HPP_
#define SRC_GAME_GAME_DEFINITIONS_HPP_

#include "movement/position.h"

// Enums
enum Offer_t {
	DISABLED=0,
	ITEM=1,
	STACKABLE_ITEM=2,
	OUTFIT=3,
	OUTFIT_ADDON=4,
	MOUNT=5,
	NAMECHANGE=6,
	SEXCHANGE=7,
	PROMOTION=8,
	PREMIUM_TIME,
	TELEPORT,
	BLESSING,
	BOOST_XP, //not using yet
	BOOST_STAMINA, //not using yet
	WRAP_ITEM
};

enum ClientOffer_t{
	SIMPLE=0,
	ADDITIONALINFO=1
};

enum StackPosType_t {
	STACKPOS_MOVE,
	STACKPOS_LOOK,
	STACKPOS_TOPDOWN_ITEM,
	STACKPOS_USEITEM,
	STACKPOS_USETARGET,
	STACKPOS_FIND_THING,
};

enum WorldType_t {
	WORLD_TYPE_NO_PVP = 1,
	WORLD_TYPE_PVP = 2,
	WORLD_TYPE_PVP_ENFORCED = 3,
};

enum GameState_t {
	GAME_STATE_STARTUP,
	GAME_STATE_INIT,
	GAME_STATE_NORMAL,
	GAME_STATE_CLOSED,
	GAME_STATE_SHUTDOWN,
	GAME_STATE_CLOSING,
	GAME_STATE_MAINTAIN,
};

enum QuickLootFilter_t {
	QUICKLOOTFILTER_SKIPPEDLOOT = 0,
	QUICKLOOTFILTER_ACCEPTEDLOOT = 1,
};

enum LightState_t {
	LIGHT_STATE_DAY,
	LIGHT_STATE_NIGHT,
	LIGHT_STATE_SUNSET,
	LIGHT_STATE_SUNRISE,
};

enum BlessType_t : uint8_t
{
	ADVENTURE_BLESS = 0,
	TWIST_OF_FATE = 1, // PVP Bless
	WISDOM_OF_SOLITUDE = 2,
	SPARK_OF_THE_PHOENIX = 3,
	FIRE_OF_THE_SUNS = 4,
	SPIRITUAL_SHIELDING = 5,
	EMBRACE_OF_TIBIA = 6,
	HEART_OF_THE_MOUNTAIN = 7,
	BLOOD_OF_THE_MOUNTAIN = 8,

	BLESS_ADV_FIRST = ADVENTURE_BLESS,
	BLESS_FIRST = TWIST_OF_FATE,
	BLESS_PVE_FIRST = WISDOM_OF_SOLITUDE,
	BLESS_LAST = BLOOD_OF_THE_MOUNTAIN
};

enum CyclopediaCharacterInfoType_t : uint8_t {
	CYCLOPEDIA_CHARACTERINFO_BASEINFORMATION = 0,
	CYCLOPEDIA_CHARACTERINFO_GENERALSTATS = 1,
	CYCLOPEDIA_CHARACTERINFO_COMBATSTATS = 2,
	CYCLOPEDIA_CHARACTERINFO_RECENTDEATHS = 3,
	CYCLOPEDIA_CHARACTERINFO_RECENTPVPKILLS = 4,
	CYCLOPEDIA_CHARACTERINFO_ACHIEVEMENTS = 5,
	CYCLOPEDIA_CHARACTERINFO_ITEMSUMMARY = 6,
	CYCLOPEDIA_CHARACTERINFO_OUTFITSMOUNTS = 7,
	CYCLOPEDIA_CHARACTERINFO_STORESUMMARY = 8,
	CYCLOPEDIA_CHARACTERINFO_INSPECTION = 9,
	CYCLOPEDIA_CHARACTERINFO_BADGES = 10,
	CYCLOPEDIA_CHARACTERINFO_TITLES = 11
};

enum CyclopediaCharacterInfo_RecentKillStatus_t : uint8_t {
	CYCLOPEDIA_CHARACTERINFO_RECENTKILLSTATUS_JUSTIFIED = 0,
	CYCLOPEDIA_CHARACTERINFO_RECENTKILLSTATUS_UNJUSTIFIED = 1,
	CYCLOPEDIA_CHARACTERINFO_RECENTKILLSTATUS_GUILDWAR = 2,
	CYCLOPEDIA_CHARACTERINFO_RECENTKILLSTATUS_ASSISTED = 3,
	CYCLOPEDIA_CHARACTERINFO_RECENTKILLSTATUS_ARENA = 4
};

enum HighscoreCategories_t : uint8_t {
	HIGHSCORE_CATEGORY_EXPERIENCE = 0,
	HIGHSCORE_CATEGORY_FIST_FIGHTING,
	HIGHSCORE_CATEGORY_CLUB_FIGHTING,
	HIGHSCORE_CATEGORY_SWORD_FIGHTING,
	HIGHSCORE_CATEGORY_AXE_FIGHTING,
	HIGHSCORE_CATEGORY_DISTANCE_FIGHTING,
	HIGHSCORE_CATEGORY_SHIELDING,
	HIGHSCORE_CATEGORY_FISHING,
	HIGHSCORE_CATEGORY_MAGIC_LEVEL
};

enum HighscoreType_t : uint8_t {
	HIGHSCORE_GETENTRIES = 0,
	HIGHSCORE_OURRANK = 1
};

enum Webhook_Colors_t : uint32_t {
	WEBHOOK_COLOR_ONLINE = 0x00FF00,
	WEBHOOK_COLOR_OFFLINE = 0xFF0000,
	WEBHOOK_COLOR_WARNING = 0xFFFF00,
	WEBHOOK_COLOR_RAID = 0x0000FF
};

enum CoinType_t : uint8_t {
	COIN_TYPE_DEFAULT = 0,
	COIN_TYPE_TRANSFERABLE = 1,
	COIN_TYPE_TOURNAMENT = 2,
};

// Structs
struct ModalWindow {
	std::list<std::pair<std::string, uint8_t>> buttons, choices;
	std::string title, message;
	uint32_t id;
	uint8_t defaultEnterButton, defaultEscapeButton;
	bool priority;

	ModalWindow(uint32_t newId, std::string newTitle, std::string newMessage) :
                    title(std::move(newTitle)),
                    message(std::move(newMessage)),
                    id(newId),
                    defaultEnterButton(0xFF),
                    defaultEscapeButton(0xFF),
					priority(false) {}
};

struct BaseOffer{
	uint32_t id;
	std::string name;
	std::string description;
	uint32_t price;
	Offer_t type;
	std::vector<std::string> icons;
};

struct ItemOffer : BaseOffer{
	uint16_t productId;
	uint16_t count;
};

struct MountOffer: BaseOffer{
	uint8_t mountId;
};

struct OutfitOffer : BaseOffer {
	uint16_t maleLookType;
	uint16_t femaleLookType;
	uint8_t addonNumber;
};

struct TeleportOffer : BaseOffer{
	Position position;
};

struct PremiumTimeOffer : BaseOffer{
	uint16_t days;
};

struct BlessingOffer : BaseOffer{
	std::vector<uint8_t> blessings;
};

#endif  // SRC_GAME_GAME_DEFINITIONS_HPP_