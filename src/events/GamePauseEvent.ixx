export module events.GamePauseEvent;

export enum struct GamePause {
    ePause,
    eResume,
};

export struct GamePauseEvent {
    GamePause type;
};
