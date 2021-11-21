#pragma once

#include "EventHandler.h"

namespace GLFW_WRAPPER_NAMESPACE
{
    class EventHandlerManager
    {
    public:
        void RegisterHandler(const EventHandlerPtr& handler)
        {
            ClearRemovedHandlers();
            m_handlers.insert({ handler->Type, handler });
        }

        void RemoveHandlers(EventType type)
        {
            m_handlers.erase(type);
        }

        void Handle(const Event* event) const
        {
            if (event)
            {
                const auto range = m_handlers.equal_range(event->Type);
                for (auto it = range.first; it != range.second; ++it)
                {
                    if (auto func = it->second.lock())
                        func->Process(event);
                    else
                        m_removedHandlers.emplace_back(it);
                }
            }
        }

    private:
        void ClearRemovedHandlers()
        {
            for (auto& it : m_removedHandlers)
                m_handlers.erase(it);
            m_removedHandlers.clear();
        }

        std::unordered_multimap<EventType, EventHandlerWPtr> m_handlers;
        mutable std::list<decltype(m_handlers)::const_iterator> m_removedHandlers;
    };
}