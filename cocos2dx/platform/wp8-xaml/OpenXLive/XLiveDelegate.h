#pragma once

#include "ICallback.h"

namespace PhoneDirect3DXamlAppComponent
{
	namespace OpenXLiveHelper
	{
		public ref class XLiveDelegate sealed
		{
		public:
			XLiveDelegate(void);

			void SetCallback(ICallback^ callback);

			property static ICallback^ GlobalCallback;
		};
	}	
}
