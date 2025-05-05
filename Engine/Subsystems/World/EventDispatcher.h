#ifndef EVENT_DISPATCHER_H
#define EVENT_DISPATCHER_H

namespace Engine
{
    enum DispatchableEvent
    {
        None,

        // Events related to core engine loop.
        EngineShutdown,

        // Key down events.
        WKeyDown,
        AKeyDown,
        SKeyDown,
        DKeyDown,
    };

    class EventDispatcher final
    {
    public:
        DispatchableEvent TryDispatchingEvent();
    };
} // namespace Engine

#endif // EVENT_DISPATCHER_H
