#include "OpenXLiveEvent.h"

namespace PhoneDirect3DXamlAppComponent
{

	OpenXLiveEvent::OpenXLiveEvent(Object^ sender, CompletedEventArgs^ args, Windows::Foundation::EventHandler<CompletedEventArgs^>^ handler):
		m_sender(sender),
		m_args(args),
		m_handler(handler)
	{

	}

	void OpenXLiveEvent::execute( Cocos2dRenderer ^ renderer )
	{
		m_handler->Invoke(m_sender, m_args);
	}

}