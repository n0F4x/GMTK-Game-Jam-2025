export module player.create_player;

import extensions.scheduler;

import events.SpawnDialogEvent;

import states.GlobalState;

using namespace extensions::scheduler::accessors;

export auto create_player(Registry registry, State<GlobalState> globalState, Recorder<SpawnDialogEvent>) -> void;
