#include "InputEvent.h"
#include "ICallback.h"
using namespace Platform;
using namespace PhoneDirect3DXamlAppComponent::OpenXLiveHelper;

namespace PhoneDirect3DXamlAppComponent
{
	class OpenXLiveEvent : public InputEvent
	{
	public:
		OpenXLiveEvent(Object^ sender, CompletedEventArgs^ args, Windows::Foundation::EventHandler<CompletedEventArgs^>^ handler);
		virtual void execute(Cocos2dRenderer ^ renderer);

	private:
		Object^ m_sender;
		CompletedEventArgs^ m_args;
		Windows::Foundation::EventHandler<CompletedEventArgs^>^ m_handler;
	};
}