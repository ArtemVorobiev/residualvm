/* Residual - A 3D game interpreter
 *
 * Residual is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the AUTHORS
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef MYST3_ENGINE_H
#define MYST3_ENGINE_H

#include "engines/engine.h"

#include "common/system.h"
#include "common/random.h"

#include "engines/myst3/archive.h"
#include "engines/myst3/console.h"
#include "engines/myst3/database.h"
#include "engines/myst3/movie.h"
#include "engines/myst3/node.h"
#include "engines/myst3/scene.h"
#include "engines/myst3/script.h"
#include "engines/myst3/cursor.h"

namespace Myst3 {

// Engine Debug Flags
enum {
	kDebugVariable = (1 << 0),
	kDebugSaveLoad = (1 << 1),
	kDebugNode     = (1 << 2),
	kDebugScript   = (1 << 3)
};

// View type
enum ViewType {
	kCube = 1,
	kFrame = 2,
	kMenu = 3
};

class Console;
class Variables;
class HotSpot;

class Myst3Engine : public Engine {

protected:
	// Engine APIs
	virtual Common::Error run();
	virtual GUI::Debugger *getDebugger() { return (GUI::Debugger *)_console; }
public:
	Variables *_vars;
	Common::RandomSource *_rnd;

	Myst3Engine(OSystem *syst, int gameFlags);
	virtual ~Myst3Engine();

	void goToNode(uint16 nodeID, uint8 roomID = 0);
	void loadNode(uint16 nodeID, uint8 roomID = 0, uint32 ageID = 0);
	void loadNodeCubeFaces(uint16 nodeID);
	void loadNodeFrame(uint16 nodeID);
	void runNodeInitScripts();
	void runNodeBackgroundScripts();
	void runScriptsFromNode(uint16 nodeID, uint8 roomID = 0, uint32 ageID = 0);

	void loadMovie(uint16 id, uint16 condition, bool resetCond, bool loop);
	void playSimpleMovie(uint16 id);

	void addSpotItem(uint16 id, uint16 condition, bool fade);

	void processInput(bool lookOnly);
	void drawFrame();
	uint getFrameCount() { return _frameCount; }
private:
	OSystem *_system;
	Console *_console;
	
	Node *_node;
	Scene *_scene;
	Archive *_archive;
	Script *_scriptEngine;
	Database *_db;
	Cursor *_cursor;

	Common::Array<ScriptedMovie *> _movies;
	Common::Array<Drawable *> _drawables;

	ViewType _viewType;

	uint _frameCount;
	bool _shouldQuit;

	Common::Array<HotSpot *> listHoveredHotspots();
	void updateCursor();

	friend class Console;
};

} // end of namespace Myst3

#endif
