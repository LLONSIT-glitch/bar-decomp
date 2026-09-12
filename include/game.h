// SPDX-License-Identifier: AGPL-3.0-or-later
enum gameState {
        INIT = -1,    // used during game init
        NONE = 0,
        UNUSED_PARADIGM_LOGO = 1,
        INTRO,
        DEMO,         // Attract demo while idling at main menu
        CREDITS,      // Demo with staff roll
        RACE,         // Single and Multiplayer
        BATTLE,       // Beetle Battle
        VICTORY,      // Championship win screen
        UFO_CAMERA,   // Free look camera
        SCENE_EDITOR, // General model viewer 
        TASK_EDITOR,  // Track editor
        AI_EDIT,      // AI Path editor
        TEXTURE_VIEWER, // Broken in final build
        COLOR_BARS,   // color bars test screen
        SELECTION,    // Save file select and main menu (game starts here)
        PROFILE_CAR   // Additional car model viewer
};