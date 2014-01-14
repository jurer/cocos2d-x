#include "XLiveDelegate.h"

namespace PhoneDirect3DXamlAppComponent
{
	namespace OpenXLiveHelper
	{
		XLiveDelegate::XLiveDelegate(void)
		{
		}

		void XLiveDelegate::SetCallback(ICallback^ callback)
		{
			GlobalCallback = callback;
		}
	}
}
