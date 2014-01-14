namespace PhoneDirect3DXamlAppComponent
{
	namespace OpenXLiveHelper
	{
		// An asynchronous completed event argument, similar with OpenXLive.Feature.AsyncProcessResult.
		public ref class CompletedEventArgs sealed
		{
		public:
			CompletedEventArgs(bool ReturnValue, int ErrorCode, Platform::String^ ErrorMessage)
			{
				this->ReturnValue = ReturnValue;
				this->ErrorCode = ErrorCode;
				this->ErrorMessage = ErrorMessage;
			}

			property bool ReturnValue;
			property int ErrorCode;
			property Platform::String^ ErrorMessage;
		};

		// SNSProvider delegate class for native code to call, similar with OpenXLive.Feature.SNSProvider.
		public ref class SNSProviderDelegate sealed
		{
		public:
			SNSProviderDelegate()
			{
			}

			property Platform::String^ ID;
			property Platform::String^ LoginUrl;
			property Platform::String^ Logo;
			property Platform::String^ Name;
			property Platform::String^ Url;

		};

		// A callback interface for C# code to implement.
		public interface class ICallback
		{
#pragma region OpenXLive UI Method

			//// Invokes XLiveUIManager.ShowAchievement() and show achievement page.
			//void ShowAchievement();
			//// Invokes XLiveUIManager.ShowAnnouncement() and show announcement page.
			//void ShowAnnouncement();
			//// Invokes XLiveUIManager.ShowFriend() and show friend page.
			//void ShowFriend(bool isRefresh);
			//// Invokes XLiveUIManager.ShowGameCenter() and show game center page.
			//void ShowGameCenter();
			//// Invokes XLiveUIManager.ShowLeaderboard() and show leaderboard page.
			//void ShowLeaderboard();
			//// Invokes XLiveUIManager.ShowLogon() and show logon page.
			//void ShowLogon();
			//// Invokes XLiveUIManager.ShowMessageThread() and show message thread page.
			//void ShowMessageThread();
			//// Invokes XLiveUIManager.ShowMoreGames() and show more games page.
			//void ShowMoreGames();
			//// Invokes XLiveUIManager.ShowOnlinePlayer() and show online player page.
			//void ShowOnlinePlayer();
			//// Invokes XLiveUIManager.ShowSearch() and show search page.
			//void ShowSearch();
			//// Invokes XLiveUIManager.ShowUpdateStatus() and show share page.
			//void ShowUpdateStatus(Windows::Storage::Streams::IBuffer^ picture, Platform::String^ content);

#pragma endregion

#pragma region OpenXLive Feature

#pragma region Leaderboard Submit
			// Submit a score completed event.
			event Windows::Foundation::EventHandler<CompletedEventArgs^>^ OnSubmitCompleted;
			void Leaderboard_Submit(Platform::String^ leaderboardKey, int score);
			//void Leaderboard_Submit(Platform::String^ leaderboardKey, float score);
			//void Leaderboard_Submit(Platform::String^ leaderboardKey, Windows::Foundation::TimeSpan score);
#pragma endregion

#pragma region Achievement Award
			// Award an achievement completed event.
			event Windows::Foundation::EventHandler<CompletedEventArgs^>^ OnAwardComplted;
			void Achievement_Award(Platform::String^ achievementKey);
//			void Achievement_Award(Platform::String^ achievementKey, Platform::String^ leaderboardKey, Platform::String^ score, Platform::String^ comment);
//#pragma endregion
//
//#pragma region MyStatus Update
//			// Update status completed event.
//			event Windows::Foundation::EventHandler<CompletedEventArgs^>^ OnUpdateStatusComplted;
//			void MyStatus_UpdateStatus(Platform::String^ content, SNSProviderDelegate^ provider);
//			void MyStatus_UpdateStatus(Platform::String^ content, Windows::Storage::Streams::IBuffer^ picture, SNSProviderDelegate^ provider);
//
//			// Gets SNS providers list.
//			Windows::Foundation::Collections::IVector<SNSProviderDelegate^>^ GetSNSProviders();
#pragma endregion

#pragma endregion
		};
	}
}

